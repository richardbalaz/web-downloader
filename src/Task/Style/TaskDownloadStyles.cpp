//
// Created by Richard Baláž on 25/04/2020.
//

#include <precomp.h>
#include "TaskDownloadStyles.h"
#include "TaskDownloadStyle.h"
#include "Task/File/TaskDownloadFile.h"
#include <Html/Html.h>

TaskDownloadStyles::TaskDownloadStyles(shared_ptr<Html> web)
        : _web(std::move(web))
{}

auto TaskDownloadStyles::process() -> void
{
    for(const auto & img : _web->search("link"))
    {
        HttpPath url(img.getProperty("href"), _web->getUrl());

        if(url.hostnameDiffersFromPrev() || Application::getHttpMap().hasPath(url))
            continue;

        Application::getHttpMap().addPath(url);
        setNext<TaskDownloadStyle>(url);
    }

    TaskBase::process();
}

