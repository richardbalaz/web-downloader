//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKBASE_H
#define WEB_DOWNLOADER_TASKBASE_H

#include "Task.h"

class TaskBase : public Task
{
public:
    TaskBase();
    ~TaskBase() override = 0;

    auto setNext(unique_ptr<Task> task) -> Task & override;
    auto process() -> void override;

private:
    vector<unique_ptr<Task>> _nextTasks;
};



#endif //WEB_DOWNLOADER_TASKBASE_H
