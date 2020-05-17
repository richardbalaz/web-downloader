//
// Created by Richard Baláž on 28/04/2020.
//

#include <precomp.h>
#include "TaskModifyPageLinks.h"
#include <Html/Html.h>

TaskModifyPageLinks::TaskModifyPageLinks(shared_ptr<Html> page, ELocationType placement)
        : TaskModifyLinks(move(page), placement)
{}

auto TaskModifyPageLinks::process() -> void
{
    TaskModifyLinks::process();
}

string TaskModifyPageLinks::getNodeName()
{
    return "a";
}

string TaskModifyPageLinks::getAttrName()
{
    return "href";
}
