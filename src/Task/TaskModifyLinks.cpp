//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include "TaskModifyLinks.h"

TaskModifyLinks::TaskModifyLinks()
{}

TaskModifyLinks::~TaskModifyLinks()
{}

auto TaskModifyLinks::process() -> void
{
    cout << "modify links" << endl;

    TaskBase::process();
}

