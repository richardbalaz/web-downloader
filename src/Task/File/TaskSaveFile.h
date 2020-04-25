//
// Created by Richard Baláž on 25/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKSAVEFILE_H
#define WEB_DOWNLOADER_TASKSAVEFILE_H


#include <Http/HttpPath.h>
#include "Task/TaskBase.h"

class TaskSaveFile : public TaskBase
{
public:
    TaskSaveFile(const HttpPath & path, const string & content);

    void process() override;

private:
    HttpPath _url;
    string _content;
};


#endif //WEB_DOWNLOADER_TASKSAVEFILE_H
