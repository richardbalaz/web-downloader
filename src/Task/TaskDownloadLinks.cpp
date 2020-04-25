//
// Created by Richard Baláž on 25/04/2020.
//

#include <precomp.h>
#include "TaskDownloadLinks.h"
#include "TaskDownloadWeb.h"
#include <Html/Html.h>
#include <Html/HtmlDumper.h>

TaskDownloadLinks::TaskDownloadLinks(shared_ptr<Html> page)
        : _page(move(page))
{}

void TaskDownloadLinks::process()
{
    for(const auto & link : _page->search("a"))
    {
        string urlRaw = link.property("href");

        if(urlRaw.empty() || urlRaw == "#")
            continue;

        HttpPath url(urlRaw, _page->url());

        if(url.hostnameDiffersFromPrev() || Application::getHttpMap().hasPath(url))
            continue;

        Application::getHttpMap().addPath(url);
        setNext<TaskDownloadWeb>(url);

        cout << "download link '" << url.getHostname() << "' uri: '" << url.getUri() << "'" << endl;
    }

    TaskBase::process();
}
