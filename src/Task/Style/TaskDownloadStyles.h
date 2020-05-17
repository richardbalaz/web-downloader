//
// Created by Richard Baláž on 25/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADSTYLES_H
#define WEB_DOWNLOADER_TASKDOWNLOADSTYLES_H



#include "Task/TaskBase.h"

class Html;

// Find all stylesheets and download them
class TaskDownloadStyles : public TaskBase
{
public:
    explicit TaskDownloadStyles(shared_ptr<Html> web);
    ~TaskDownloadStyles() override {};

public:
    auto process() -> void override;

private:
    shared_ptr<Html> _web;
};


#endif //WEB_DOWNLOADER_TASKDOWNLOADSTYLES_H
