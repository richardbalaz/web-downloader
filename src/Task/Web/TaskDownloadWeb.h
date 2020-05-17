//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADWEB_H
#define WEB_DOWNLOADER_TASKDOWNLOADWEB_H

#include "Task/TaskBase.h"
#include <Http/HttpPath.h>
#include <Html/Html.h>

// Top-level task for downloading a website
// Downloads pages, images, styles, replaces links,...
// This task processes TaskDownloadLinks which processes TaskDownloadWeb,
// so this task is called recursively
// All settings are taken from Application.h
// Usage:
// TaskDownloadWeb({ "http://locahost/index.html" }).process()
// Note: Url must be absolute and must include hostname and uri.
class TaskDownloadWeb : public TaskBase
{
public:
    TaskDownloadWeb(HttpPath url, unsigned int currentDepth = 0);
    ~TaskDownloadWeb() override {};

public:
    auto process() -> void override;

private:
    // Check if any further links located in _page can be further downloaded
    auto canGoDeeper() -> bool;

private:
    HttpPath _url;
    shared_ptr<Html> _page;

    unsigned int _currentDepth;
};


#endif //WEB_DOWNLOADER_TASKDOWNLOADWEB_H
