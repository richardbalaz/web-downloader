//
// Created by Richard Baláž on 22/04/2020.
//

#include <precomp.h>
#include "Html.h"

Html::Html(htmlDocPtr document, const HttpPath & url)
    : _document(document)
    , _url(url)
{

}

Html::~Html()
{
    xmlFreeDoc(_document);
    xmlCleanupParser();
}

htmlDocPtr Html::getDoc() const
{
    return _document;
}

auto Html::search(const string &searchName) const -> vector<HtmlNode>
{
    vector<HtmlNode> nodes;

    search_impl(xmlDocGetRootElement(_document), [&](xmlNode * node) -> bool
    {
        return xmlStrcmp(node->name, (xmlChar *) searchName.c_str()) == 0;
    }, nodes);

    return nodes;
}

auto Html::search_impl(xmlNode *node, const std::function<bool(xmlNode *)> & isMatch, std::vector<HtmlNode> & result) -> void
{
    for(auto currentNode = node; currentNode; currentNode = currentNode->next)
    {
        if(currentNode->type == XML_ELEMENT_NODE && isMatch(currentNode))
            result.emplace_back(currentNode);

        search_impl(currentNode->children, isMatch, result);
    }
}

auto Html::getUrl() const -> const HttpPath &
{
    return _url;
}

HtmlNode::HtmlNode(xmlNode *node)
    : _node(node)
{}

auto HtmlNode::getProperty(const string &name) const -> string
{
    if(xmlHasProp(_node, (xmlChar *) name.c_str()) == nullptr)
        return {};

    xmlChar * prop = xmlGetProp(_node, (xmlChar *) name.c_str());
    string propStr((char *) prop);
    xmlFree(prop);
    return propStr;
}

auto HtmlNode::setProperty(const string &name, const string & content) -> void
{
    if(xmlHasProp(_node, (xmlChar *) name.c_str()) == nullptr)
        return;

    xmlSetProp(_node, (xmlChar *) name.c_str(), (xmlChar *) content.c_str());
}
