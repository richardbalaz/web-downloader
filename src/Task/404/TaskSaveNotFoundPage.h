//
// Created by Richard Baláž on 28/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKSAVENOTFOUNDPAGE_H
#define WEB_DOWNLOADER_TASKSAVENOTFOUNDPAGE_H


#include "Task/TaskBase.h"

class Html;

// Save hard-coded 'Page not found' into local /404.html file
class TaskSaveNotFoundPage : public TaskBase
{
public:
    explicit TaskSaveNotFoundPage();
    ~TaskSaveNotFoundPage() override {};

public:
    auto process() -> void override;
};

#endif //WEB_DOWNLOADER_TASKSAVENOTFOUNDPAGE_H
