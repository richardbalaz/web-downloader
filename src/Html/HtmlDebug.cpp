//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include "HtmlDebug.h"

auto HtmlDebug::isLeaf(xmlNode *node) -> bool
{
    xmlNode * child = node->children;

    while(child)
    {
        if(child->type == XML_ELEMENT_NODE) return false;

        child = child->next;
    }

    return true;
}

auto HtmlDebug::printNode(xmlNode *node, size_t indent) -> void
{
    while(node)
    {
        if(node->type == XML_ELEMENT_NODE)
        {
            printf("%s%s%s\n", string(indent * 2, '-').c_str(), node->name, xmlNodeGetContent(node));
        }
        printNode(node->children, indent + 1);
        node = node->next;
    }
}

auto HtmlDebug::printDocument(xmlDocPtr document) -> void
{
    printNode(xmlDocGetRootElement(document), 1);
}
