//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASK_H
#define WEB_DOWNLOADER_TASK_H

class Task
{
public:
    virtual ~Task() = 0;

public:
    virtual auto setNext(unique_ptr<Task> task) -> Task & = 0;
    virtual auto process() -> void = 0;
};

#endif //WEB_DOWNLOADER_TASK_H
