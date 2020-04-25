//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include <Http/HttpClient.h>
#include <Html/HtmlParser.h>
#include "TaskDownloadWeb.h"
#include "TaskModifyLinks.h"
#include "TaskDownloadLinks.h"
#include "Task/Image/TaskDownloadImages.h"
#include "TaskDownloadPage.h"
#include "Task/Style/TaskDownloadStyles.h"

TaskDownloadWeb::TaskDownloadWeb(HttpPath url)
    : _url(move(url))
    , _web(nullptr)
{
}

auto TaskDownloadWeb::process() -> void
{
    const string content = Application::getHttpClient().getContent(_url);
    _web = HtmlParser::parse(content, _url);

    cout << "download web" << endl;
    Application::getHttpMap().addPath(_url);

    setNext<TaskDownloadImages>(_web);
    setNext<TaskDownloadStyles>(_web);
    setNext<TaskDownloadLinks>(_web);
    setNext<TaskDownloadPage>(_web);

    TaskBase::process();
}
