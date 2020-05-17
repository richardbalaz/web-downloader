//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include "TaskBase.h"

TaskBase::TaskBase()
{}

TaskBase::~TaskBase() = default;

auto TaskBase::setNext_impl(unique_ptr<Task> task) -> Task &
{
    _nextTasks.emplace_back(move(task));
    return *_nextTasks.back();
}

auto TaskBase::process() -> void
{
    for(auto & task : _nextTasks)
        task->process();

    _nextTasks.clear();
}

auto TaskBase::processAsync() -> void
{
    for(auto & task : _nextTasks)
        _nextTasksFutures.emplace_back(async(launch::async, [&task]() { task->process(); }));

    for(auto & future : _nextTasksFutures)
        future.wait();

    _nextTasks.clear();
}


