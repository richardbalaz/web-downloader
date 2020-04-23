//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include <Http/HttpClient.h>
#include <Html/HtmlParser.h>
#include "TaskDownloadWeb.h"
#include "TaskModifyLinks.h"
#include "TaskDownloadImages.h"

TaskDownloadWeb::TaskDownloadWeb(string url)
    : _url(move(url))
    , _web(nullptr)
{
}

auto TaskDownloadWeb::process() -> void
{
    const string content = Application::httpClient().getContent(_url);
    _web = HtmlParser::parse(content, _url);

    cout << "download web" << endl;

    setNext(make_unique<TaskDownloadImages>(_web));

    TaskBase::process();
}
