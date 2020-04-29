//
// Created by Richard Baláž on 25/04/2020.
//

#ifndef WEB_DOWNLOADER_HTTPMAP_H
#define WEB_DOWNLOADER_HTTPMAP_H


#include "HttpPath.h"

// Single node in Map of Http website
// Node may know his parent (for ../ traversing) and contains all it's children
// Node is identified by it's name, so name among all children is unique in scope of one node
class HttpMapNode
{
public:
    HttpMapNode(const string & name, HttpMapNode * parent);

public:
    // Return node's name (e.g. index.html)
    auto getName() -> const string &;
    // Return all node's children
    auto getChildren() -> vector<shared_ptr<HttpMapNode>> &;

    // Create a child in current node (child cannot exists)
    auto createChild(const string & name) -> HttpMapNode &;
    // Return a child with name
    auto getChild(const string & name) -> HttpMapNode &;
    // Check if child with name exists
    auto hasChild(const string & name) -> bool;

private:
    string _name;
    HttpMapNode * _parent;
    vector<shared_ptr<HttpMapNode>> _children;
};

// Root of Map of Http website
class HttpMapRoot : public HttpMapNode
{
public:
    HttpMapRoot();
};

// Map of Http website (tree of uri)
// Allows remembering which paths have been already visited
class HttpMap
{
public:
    HttpMap();

public:
    // Create given path in tree
    auto addPath(const HttpPath & path) -> void;
    // Check whether given path already exists in tree
    auto hasPath(const HttpPath & path) -> bool;

private:
    // Explode path by '/' delimiter (for tree traversing)
    auto decompose(const string & path) -> vector<string>;

private:
    shared_ptr<HttpMapRoot> _root;
};


#endif //WEB_DOWNLOADER_HTTPMAP_H
