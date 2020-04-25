//
// Created by Richard Baláž on 25/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADLINKS_H
#define WEB_DOWNLOADER_TASKDOWNLOADLINKS_H


#include "TaskBase.h"

class Html;

class TaskDownloadLinks : public TaskBase
{
public:
    explicit TaskDownloadLinks(shared_ptr<Html> page);
    ~TaskDownloadLinks() override {};

    void process() override;

private:
    shared_ptr<Html> _page;
};


#endif //WEB_DOWNLOADER_TASKDOWNLOADLINKS_H
