//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKMODIFYLINKS_H
#define WEB_DOWNLOADER_TASKMODIFYLINKS_H


#include "TaskBase.h"

class TaskModifyLinks : public TaskBase
{
public:
    TaskModifyLinks();
    ~TaskModifyLinks() override;

public:
    auto process() -> void override;
};


#endif //WEB_DOWNLOADER_TASKMODIFYLINKS_H
