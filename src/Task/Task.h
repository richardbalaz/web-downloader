//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASK_H
#define WEB_DOWNLOADER_TASK_H

// Task Interface
class Task
{
public:
    virtual ~Task() = 0;

public:
    virtual auto process() -> void = 0;
private:
    virtual auto setNext_impl(unique_ptr<Task> task) -> Task & = 0;
};

#endif //WEB_DOWNLOADER_TASK_H
