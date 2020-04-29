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
#include "Task/Image/TaskModifyImageLinks.h"
#include "TaskDownloadPage.h"
#include "Task/Style/TaskDownloadStyles.h"
#include "Task/TaskModifyPageLinks.h"
#include "Task/404/TaskSaveNotFoundPage.h"

TaskDownloadWeb::TaskDownloadWeb(HttpPath url, unsigned int currentDepth)
    : _url(move(url))
    , _page(nullptr)
    , _currentDepth(currentDepth)
{
}

auto TaskDownloadWeb::process() -> void
{
    const string content = Application::getHttpClient().getContent(_url);
    _page = HtmlParser::parse(content, _url);

    Application::getHttpMap().addPath(_url);

    setNext<TaskDownloadImages>(_page);
    setNext<TaskDownloadStyles>(_page);

    if(canGoDeeper())
        setNext<TaskDownloadLinks>(_page, _currentDepth);

    if(Application::isLocalImagesEnabled())
        setNext<TaskModifyImageLinks>(_page, ELocationType::LOCAL);
    else
        setNext<TaskModifyImageLinks>(_page, ELocationType::REMOTE);

    if(!canGoDeeper() && Application::isNotFoundForExcessiveDepthEnabled())
    {
        setNext<TaskSaveNotFoundPage>();
        setNext<TaskModifyPageLinks>(_page, ELocationType::NOT_FOUND);
    }
    else
    {
        setNext<TaskModifyPageLinks>(_page, canGoDeeper() ? ELocationType::LOCAL : ELocationType::REMOTE);
    }

    setNext<TaskDownloadPage>(_page);

    TaskBase::process();
}

auto TaskDownloadWeb::canGoDeeper() -> bool
{
    return _currentDepth < Application::getMaxDepth();
}
