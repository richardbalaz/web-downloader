//
// Created by Richard Baláž on 25/04/2020.
//

#include <precomp.h>
#include "TaskDownloadLinks.h"
#include "TaskDownloadWeb.h"
#include <Html/Html.h>
#include <Html/HtmlDumper.h>

TaskDownloadLinks::TaskDownloadLinks(shared_ptr<Html> page, unsigned int currentDepth)
        : _page(move(page))
        , _currentDepth(currentDepth)
{}

void TaskDownloadLinks::process()
{
    for(const auto & link : _page->search("a"))
    {
        string urlRaw = link.getProperty("href");

        if(urlRaw.empty() || urlRaw == "#")
            continue;

        HttpPath url(urlRaw, _page->getUrl());

        if(url.hostnameDiffersFromPrev() || Application::getHttpMap().hasPath(url))
            continue;

        cout << "download link '" << url.getHostname() << "' uri: '" << url.getUri() << "'" << endl;

        setNext<TaskDownloadWeb>(url, _currentDepth + 1);
        TaskBase::process();
    }

    TaskBase::process();
}
