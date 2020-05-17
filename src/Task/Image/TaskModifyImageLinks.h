//
// Created by Richard Baláž on 28/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKMODIFYIMAGELINKS_H
#define WEB_DOWNLOADER_TASKMODIFYIMAGELINKS_H

#include "Task/Web/TaskModifyLinks.h"

class Html;

// Find all images and replace their links so they either point to local file or remote http url
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
