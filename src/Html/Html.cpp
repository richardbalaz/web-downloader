//
// Created by Richard Baláž on 22/04/2020.
//

#include <precomp.h>
#include "Html.h"

Html::Html(htmlDocPtr document)
    : _document(document)
{

}

Html::~Html()
{
    xmlFreeDoc(_document);
    xmlCleanupParser();
}

htmlDocPtr Html::doc() const
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

HtmlNode::HtmlNode(xmlNode *node)
    : _node(node)
{}

auto HtmlNode::property(const string &name) const -> string
{
    return string((char *) xmlGetProp(_node, (xmlChar *) name.c_str()));
}