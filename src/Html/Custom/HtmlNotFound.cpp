//
// Created by Richard Baláž on 28/04/2020.
//

#include <precomp.h>
#include "HtmlNotFound.h"
#include <Html/HtmlParser.h>

shared_ptr<Html> HtmlNotFound::_page = HtmlNotFound::createPage();

auto HtmlNotFound::createPage() -> shared_ptr<Html>
{
    string pageContent =
            "<html>"
            "<body>"
            "<h1>Error 404</h1>"
            "</body>"
            "</html>";


    return HtmlParser::parse(pageContent, HttpPath("/404.html"));
}

auto HtmlNotFound::getPage() -> shared_ptr<Html>
{
    return HtmlNotFound::_page;
}
