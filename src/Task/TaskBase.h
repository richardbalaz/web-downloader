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

    template<typename TTask, typename... Args>
    auto setNext(Args && ... args) -> Task &;

    auto process() -> void override;

private:
    vector<unique_ptr<Task>> _nextTasks;
};

template<typename TTask, typename... Args>
auto TaskBase::setNext(Args && ... args) -> Task &
{
    return setNext(make_unique<TTask>(std::forward<Args>(args)...));
}

#endif //WEB_DOWNLOADER_TASKBASE_H
