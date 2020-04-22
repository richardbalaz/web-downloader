//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include "TaskBase.h"

TaskBase::TaskBase()
{}

TaskBase::~TaskBase() = default;

auto TaskBase::setNext(unique_ptr<Task> task) -> Task &
{
    _nextTasks.emplace_back(move(task));
    return *_nextTasks.back();
}

auto TaskBase::process() -> void
{
    if(_nextTasks.empty())
        return;

    for(auto & task : _nextTasks)
        task->process();
}
