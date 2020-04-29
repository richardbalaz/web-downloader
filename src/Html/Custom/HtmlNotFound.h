//
// Created by Richard Baláž on 28/04/2020.
//

#ifndef WEB_DOWNLOADER_HTMLNOTFOUND_H
#define WEB_DOWNLOADER_HTMLNOTFOUND_H

#include <Html/Html.h>

// Special Html page with "Page not found" content
// Used as page to display to all links when web downloading reaches max depth
// Note: This feature must be enabled in Application.h
class HtmlNotFound
{
public:
    // Return Html tree pointing to /404.html
    static auto getPage() -> shared_ptr<Html>;

private:
    // Create the Html tree from hard-coded content
    // Called only once, at _page initializaton
    static auto createPage() -> shared_ptr<Html>;

private:
    static shared_ptr<Html> _page;
};


#endif //WEB_DOWNLOADER_HTMLNOTFOUND_H
