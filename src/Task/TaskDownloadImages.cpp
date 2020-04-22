//
// Created by Richard Baláž on 22/04/2020.
//

#include <precomp.h>
#include "TaskDownloadImages.h"
#include "TaskDownloadFile.h"
#include <Html/Html.h>

TaskDownloadImages::TaskDownloadImages(shared_ptr<Html> web)
    : _web(std::move(web))
{}

auto TaskDownloadImages::process() -> void
{
    cout << "download images" << endl;

    for(const auto & img : _web->search("img"))
    {
        string url = img.property("src");
        setNext(make_unique<TaskDownloadFile>(url));
    }

    TaskBase::process();
}
