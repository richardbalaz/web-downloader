//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_HTMLDEBUG_H
#define WEB_DOWNLOADER_HTMLDEBUG_H


#include <libxml/tree.h>

// Debugging interface for lixml2's Html tree
class HtmlDebug
{
public:
    // Return true if node doesn't contain any further nodes
    static auto isLeaf(xmlNode * node) -> bool;
    // Recursive debug-print: node's name and content
    static auto printNode(xmlNode * node, size_t indent) -> void;
    // Debug-print whole document starting from root
    static auto printDocument(xmlDocPtr document) -> void;
};


#endif //WEB_DOWNLOADER_HTMLDEBUG_H
