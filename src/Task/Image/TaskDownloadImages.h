//
// Created by Richard Baláž on 22/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADIMAGES_H
#define WEB_DOWNLOADER_TASKDOWNLOADIMAGES_H


#include "Task/TaskBase.h"

class Html;

class TaskDownloadImages : public TaskBase
{
public:
    explicit TaskDownloadImages(shared_ptr<Html> web);
    ~TaskDownloadImages() override {};

public:
    auto process() -> void override;

private:
    shared_ptr<Html> _web;
};

#endif //WEB_DOWNLOADER_TASKDOWNLOADIMAGES_H
