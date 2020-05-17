//
// Created by Richard Baláž on 28/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKMODIFYPAGELINKS_H
#define WEB_DOWNLOADER_TASKMODIFYPAGELINKS_H

#include "TaskModifyLinks.h"

class Html;

class TaskModifyPageLinks : public TaskModifyLinks
{
public:
    explicit TaskModifyPageLinks(shared_ptr<Html> page, ELocationType placement);
    ~TaskModifyPageLinks() override {};

protected:
    string getNodeName() override;
    string getAttrName() override;

public:
    auto process() -> void override;
};


#endif //WEB_DOWNLOADER_TASKMODIFYPAGELINKS_H
