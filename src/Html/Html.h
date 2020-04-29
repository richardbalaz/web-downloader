//
// Created by Richard Baláž on 22/04/2020.
//

#ifndef WEB_DOWNLOADER_HTML_H
#define WEB_DOWNLOADER_HTML_H

#include <libxml/HTMLparser.h>
#include <Http/HttpPath.h>

// Single Html node in document
class HtmlNode
{
public:
    explicit HtmlNode(xmlNode * node);

    // Return content of node's attribute
    // Example:
    // <img src="./image.png">
    // getProperty("src") -> "./image.png"
    auto getProperty(const string & name) const -> string;

    // Set content of node's attribute
    auto setProperty(const string & name, const string & content) -> void;
private:
    xmlNode * _node;
};

// Whole Html tree document tied to some path
// Use HtmlParser to construct
class Html
{
public:
    explicit Html(htmlDocPtr document, const HttpPath & url);
    virtual ~Html();

    // Return raw pointer to libxml2 document (DO NOT FREE)
    auto getDoc() const -> htmlDocPtr;
    // Return path from which was the document obtained
    auto getUrl() const -> const HttpPath &;

    // Return all nodes with name
    auto search(const string & searchName) const -> vector<HtmlNode>;

private:
    // Recursive searching for node with isMatch() = true
    // If node was found, it's placed into result vector
    static auto search_impl(xmlNode * node, const function<bool(xmlNode *)> & isMatch, std::vector<HtmlNode> & result) -> void;

private:
    const htmlDocPtr _document;
    const HttpPath _url;
};


#endif //WEB_DOWNLOADER_HTML_H
