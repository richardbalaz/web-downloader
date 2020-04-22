//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADFILE_H
#define WEB_DOWNLOADER_TASKDOWNLOADFILE_H


#include "TaskBase.h"

class TaskDownloadFile : public TaskBase
{
public:
    TaskDownloadFile(string url);
    ~TaskDownloadFile() override {};

public:
    auto process() -> void override;

private:
    string _url;
};

#endif //WEB_DOWNLOADER_TASKDOWNLOADFILE_H
