//
// Created by Richard Baláž on 28/04/2020.
//

#include <precomp.h>
#include "TaskModifyImageLinks.h"
#include <Html/Html.h>

TaskModifyImageLinks::TaskModifyImageLinks(shared_ptr<Html> page, ELocationType placement)
    : TaskModifyLinks(move(page), placement)
{}

auto TaskModifyImageLinks::process() -> void
{
    TaskModifyLinks::process();
}

string TaskModifyImageLinks::getNodeName()
{
    return "img";
}

string TaskModifyImageLinks::getAttrName()
{
    return "src";
}
