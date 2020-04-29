//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_HTMLDUMPER_H
#define WEB_DOWNLOADER_HTMLDUMPER_H

#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>

// Html building interface for libxml2
class HtmlDumper
{
public:
    // Save Html tree's content into target file
    static auto save(htmlDocPtr document, const string & targetPath) -> void;
};


#endif //WEB_DOWNLOADER_HTMLDUMPER_H
