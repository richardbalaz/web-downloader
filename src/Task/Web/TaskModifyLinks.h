//
// Created by Richard Baláž on 20/04/2020.
//

#ifndef WEB_DOWNLOADER_TASKMODIFYLINKS_H
#define WEB_DOWNLOADER_TASKMODIFYLINKS_H


#include "Task/TaskBase.h"

class Html;

// Find all nodes matching their name and replace their attribute (links)
// so that they point either to local or remote file
// Usage:
// Derive TaskModifyLinks, implement getNodeName and getAttrName
class TaskModifyLinks : public TaskBase
{
public:
    explicit TaskModifyLinks(shared_ptr<Html> page, ELocationType placement);
    ~TaskModifyLinks() override {};

public:
    auto process() -> void override;

protected:
    // Name of nodes to be searched
    virtual auto getNodeName() -> string = 0;

    // In which attribute the link should be replaced
    virtual auto getAttrName() -> string = 0;

private:
    shared_ptr<Html> _page;

    ELocationType _placement;
};


#endif //WEB_DOWNLOADER_TASKMODIFYLINKS_H
