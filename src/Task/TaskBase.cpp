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
    _nextTasks.emplace(move(task));
    return *_nextTasks.back();
}

auto TaskBase::process() -> void
{
    while(!_nextTasks.empty())
    {
        _nextTasks.front()->process();
        _nextTasks.pop();
    }
}


