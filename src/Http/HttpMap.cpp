//
// Created by Richard Baláž on 25/04/2020.
//

#include <precomp.h>
#include "HttpMap.h"

auto HttpMap::addPath(const HttpPath & path) -> void
{
//  assert(!hasPath(path) && "Path already exists in map");
    if(hasPath(path))
        return;

    const auto pathNodeNames = decompose(path.getUri());

    HttpMapNode * node = _root.get();
    for(const auto & pathNodeName : pathNodeNames)
    {
        if(!node->hasChild(pathNodeName))
            node = &node->createChild(pathNodeName);
        else
            node = &node->getChild(pathNodeName);
    }
}

auto HttpMap::hasPath(const HttpPath &path) -> bool
{
    const auto pathNodeNames = decompose(path.getUri());

    HttpMapNode * node = _root.get();
    for(const auto & pathNodeName : pathNodeNames)
    {
        if(node->hasChild(pathNodeName))
            node = &node->getChild(pathNodeName);
        else
            return false;
    }

    return true;
}

auto HttpMap::decompose(const string & path) -> vector<string>
{
    vector<string> result;
    std::istringstream iss(path);

    for (std::string token; std::getline(iss, token, '/'); )
        result.push_back(std::move(token));

    return result;
}

HttpMap::HttpMap()
    : _root(make_unique<HttpMapRoot>())
{}

HttpMapNode::HttpMapNode(const string & name, HttpMapNode * parent)
    : _name(name)
    , _parent(parent)
{}

auto HttpMapNode::createChild(const string &name) -> HttpMapNode &
{
//  assert(!hasChild(name) && "Child already exists");
    if(hasChild(name))
        return getChild(name);

    return *_children.emplace_back(make_unique<HttpMapNode>(name, this));
}

auto HttpMapNode::getChild(const string &name) -> HttpMapNode &
{
    if(name == ".")
        return *this;

    if(name == "..")
    {
        assert(_parent != nullptr && "Trying to access null parent");
        return *_parent;
    }

    return **find_if(_children.begin(), _children.end(), [&](const unique_ptr<HttpMapNode> & child)
    {
        return child->getName() == name;
    });
}

auto HttpMapNode::hasChild(const string &name) -> bool
{
    if(name == "." || (name == ".." && _parent != nullptr))
        return true;

    return any_of(_children.begin(), _children.end(), [&](const unique_ptr<HttpMapNode> & child)
    {
        return child->getName() == name;
    });
}

auto HttpMapNode::getName() -> const string &
{
    return _name;
}

auto HttpMapNode::getChildren() -> vector<unique_ptr<HttpMapNode>> &
{
    return _children;
}

HttpMapRoot::HttpMapRoot()
    : HttpMapNode("root", nullptr)
{}
