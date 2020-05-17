//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKBASE_H
#define WEB_DOWNLOADER_TASKBASE_H

#include "Task.h"

// Base class for Task
// Tasks use Chain-of-resposibility pattern, that means
// that every task tells which task is going to be processed next.
// This pattern is very comfortable to use when
// trying to download a website, because there is a series of commands
// that need to be processed in exact order.
// Usage:
// Derive TaskBase, implement 'process' function in which
// the next tasks are set and processed with TaskBase::process()
class TaskBase : public Task
{
public:
    TaskBase();
    ~TaskBase() override = 0;

    // Add task into queue about to be processed
    // Example: setNext<TaskExample>(exampleArg)
    template<typename TTask, typename... Args>
    auto setNext(Args && ... args) -> Task &;

    // Process all pending tasks in order (FIFO)
    auto process() -> void override;
    auto processAsync() -> void override;

private:
    // Add task into queue about to be processed
    auto setNext_impl(unique_ptr<Task> task) -> Task & override;

private:
    vector<unique_ptr<Task>> _nextTasks;
    vector<future<void>> _nextTasksFutures;
};

template<typename TTask, typename... Args>
auto TaskBase::setNext(Args && ... args) -> Task &
{
    return setNext_impl(make_unique<TTask>(std::forward<Args>(args)...));
}

#endif //WEB_DOWNLOADER_TASKBASE_H
