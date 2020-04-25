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
    cout << "download images" << endl;

    for(const auto & img : _web->search("img"))
    {
        HttpPath url(img.property("src"), _web->url());

        if(url.hostnameDiffersFromPrev() || Application::getHttpMap().hasPath(url))
            continue;

        Application::getHttpMap().addPath(url);
        setNext(make_unique<TaskDownloadFile>(url));

        cout << "image" << endl;
    }

    TaskBase::process();
}
