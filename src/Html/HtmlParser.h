//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_HTMLPARSER_H
#define WEB_DOWNLOADER_HTMLPARSER_H

#include "Html.h"

class HtmlParser
{
public:
    static auto parse(const string & document) -> shared_ptr<Html>;

private:
    static auto getLibXmlParsingOptions() -> int;
    static auto getLibXmlParsingEncoding() -> const char *;
    static auto getLibXmlParsingBaseUrl() -> const char *;
};


#endif //WEB_DOWNLOADER_HTMLPARSER_H
