//
// Created by Richard Baláž on 22/04/2020.
//

#include <precomp.h>
#include "TaskDownloadImages.h"
#include "Task/File/TaskDownloadFile.h"
#include <Html/Html.h>

TaskDownloadImages::TaskDownloadImages(shared_ptr<Html> web)
    : _web(std::move(web))
{}

auto TaskDownloadImages::process() -> void
{
    if(!Application::isLocalImagesEnabled())
        return;

    for(const auto & img : _web->search("img"))
    {
        HttpPath url(img.getProperty("src"), _web->getUrl());

        if(url.hostnameDiffersFromPrev() || Application::getHttpMap().hasPath(url))
            continue;

        Application::getHttpMap().addPath(url);
        setNext<TaskDownloadFile>(url);
    }

    TaskBase::process();
}
