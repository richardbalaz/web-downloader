//
// Created by Richard Baláž on 28/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKMODIFYIMAGELINKS_H
#define WEB_DOWNLOADER_TASKMODIFYIMAGELINKS_H

#include "Task/TaskModifyLinks.h"

class Html;

class TaskModifyImageLinks : public TaskModifyLinks
{
public:
    explicit TaskModifyImageLinks(shared_ptr<Html> page, ELocationType placement);
    ~TaskModifyImageLinks() override {};

protected:
    string getNodeName() override;
    string getAttrName() override;

public:
    auto process() -> void override;
};


#endif //WEB_DOWNLOADER_TASKMODIFYIMAGELINKS_H
