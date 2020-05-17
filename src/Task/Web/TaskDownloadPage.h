//
// Created by Richard Baláž on 25/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKDOWNLOADPAGE_H
#define WEB_DOWNLOADER_TASKDOWNLOADPAGE_H


#include "Task/TaskBase.h"

class Html;

// Save Html tree into local file
class TaskDownloadPage : public TaskBase
{
public:
    explicit TaskDownloadPage(shared_ptr<Html> page);
    ~TaskDownloadPage() override {};

    void process() override;

private:
    shared_ptr<Html> _page;
};


#endif //WEB_DOWNLOADER_TASKDOWNLOADPAGE_H
