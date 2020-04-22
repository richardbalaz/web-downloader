//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADWEB_H
#define WEB_DOWNLOADER_TASKDOWNLOADWEB_H


#include "TaskBase.h"

class TaskDownloadWeb : public TaskBase
{
public:
    explicit TaskDownloadWeb(string url);
    ~TaskDownloadWeb() override {};

public:
    auto process() -> void override;

private:
    string _url;
    shared_ptr<Html> _web;
};


#endif //WEB_DOWNLOADER_TASKDOWNLOADWEB_H
