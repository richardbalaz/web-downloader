//
// Created by Richard Baláž on 25/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADSTYLE_H
#define WEB_DOWNLOADER_TASKDOWNLOADSTYLE_H


#include <Http/HttpPath.h>
#include "Task/TaskBase.h"

// Download all url's in stylesheet and save it into local file
class TaskDownloadStyle : public TaskBase
{
public:
    explicit TaskDownloadStyle(const HttpPath & url);
    ~TaskDownloadStyle() override {};

public:
    auto process() -> void override;

private:
    HttpPath _url;
};


#endif //WEB_DOWNLOADER_TASKDOWNLOADSTYLE_H
