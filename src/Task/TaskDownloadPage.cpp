//
// Created by Richard Baláž on 25/04/2020.
//

#include <precomp.h>
#include "TaskDownloadPage.h"
#include <Html/Html.h>
#include <Html/HtmlDumper.h>

TaskDownloadPage::TaskDownloadPage(shared_ptr<Html> page)
    : _page(move(page))
{}

void TaskDownloadPage::process()
{
    cout << "download page '" << _page->url().getHostname() << "' uri: '" << _page->url().getUri() << "'" << endl;

    string outputFile = Application::getOutputFolder() + _page->url().getUri() + "_index.html";

    filesystem::path outputPath(outputFile);
    filesystem::create_directories(outputPath.parent_path());

    HtmlDumper::save(_page->doc(), outputFile);

    TaskBase::process();
}

