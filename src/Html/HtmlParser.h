//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_HTMLPARSER_H
#define WEB_DOWNLOADER_HTMLPARSER_H

#include "Html.h"

class HttpPath;

// Html parsing interface for libxml2
class HtmlParser
{
public:
    // Parse Html document using libxml2 (with setings below) into Html tree with given path
    static auto parse(const string & document, const HttpPath & url) -> shared_ptr<Html>;

private:
    // Settings for libxml2
    static auto getLibXmlParsingOptions() -> int;
    static auto getLibXmlParsingEncoding() -> const char *;
    static auto getLibXmlParsingBaseUrl() -> const char *;
};


#endif //WEB_DOWNLOADER_HTMLPARSER_H
