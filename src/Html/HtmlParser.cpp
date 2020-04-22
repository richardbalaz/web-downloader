//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include "HtmlParser.h"

auto HtmlParser::parse(const string &document) -> shared_ptr<Html>
{
    auto doc = htmlReadMemory(document.c_str(), document.length(),
                              getLibXmlParsingBaseUrl(),
                              getLibXmlParsingEncoding(),
                              getLibXmlParsingOptions());

    return make_shared<Html>(doc);
}

auto HtmlParser::getLibXmlParsingOptions() -> int
{
    return HTML_PARSE_NONET | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING;
}

auto HtmlParser::getLibXmlParsingBaseUrl() -> const char *
{
    return "/";
}

auto HtmlParser::getLibXmlParsingEncoding() -> const char *
{
    return nullptr;
}


