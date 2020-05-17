//
// Created by Richard Baláž on 25/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADLINKS_H
#define WEB_DOWNLOADER_TASKDOWNLOADLINKS_H


#include "Task/TaskBase.h"

class Html;

// Find all links to another pages (<a> nodes) and download their link
// as they were just like another website
class TaskDownloadLinks : public TaskBase
{
public:
    explicit TaskDownloadLinks(shared_ptr<Html> page, unsigned int currentDepth);
    ~TaskDownloadLinks() override {};

    void process() override;

private:
    shared_ptr<Html> _page;
    unsigned int _currentDepth;
};


#endif //WEB_DOWNLOADER_TASKDOWNLOADLINKS_H
