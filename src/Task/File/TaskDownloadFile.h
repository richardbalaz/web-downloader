//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADFILE_H
#define WEB_DOWNLOADER_TASKDOWNLOADFILE_H

#include "Task/TaskBase.h"
#include <Http/HttpPath.h>

class TaskDownloadFile : public TaskBase
{
public:
    TaskDownloadFile(const HttpPath & url);
    ~TaskDownloadFile() override {};

public:
    auto process() -> void override;

private:
    HttpPath _url;
};

#endif //WEB_DOWNLOADER_TASKDOWNLOADFILE_H
