//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_HTMLDEBUG_H
#define WEB_DOWNLOADER_HTMLDEBUG_H


#include <libxml/tree.h>

class HtmlDebug
{
public:
    static auto isLeaf(xmlNode * node) -> bool;
    static auto printNode(xmlNode * node, size_t indent) -> void;
    static auto printDocument(xmlDocPtr document) -> void;
};


#endif //WEB_DOWNLOADER_HTMLDEBUG_H
