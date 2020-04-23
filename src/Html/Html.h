//
// Created by Richard Baláž on 22/04/2020.
//

#ifndef WEB_DOWNLOADER_HTML_H
#define WEB_DOWNLOADER_HTML_H


#include <libxml/HTMLparser.h>
#include <Http/HttpPath.h>

class HtmlNode
{
public:
    explicit HtmlNode(xmlNode * node);

    auto property(const string & name) const -> string;
private:
    xmlNode * _node;
};

class Html
{
public:
    explicit Html(htmlDocPtr document, const HttpPath & url);
    virtual ~Html();

    auto doc() const -> htmlDocPtr;
    auto url() const -> const HttpPath &;

    auto search(const string & searchName) const -> vector<HtmlNode>;

private:
    static auto search_impl(xmlNode * node, const function<bool(xmlNode *)> & isMatch, std::vector<HtmlNode> & result) -> void;

private:
    htmlDocPtr _document;
    HttpPath _url;
};


#endif //WEB_DOWNLOADER_HTML_H
