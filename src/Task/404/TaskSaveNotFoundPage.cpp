//
// Created by Richard Baláž on 28/04/2020.
//

#include <precomp.h>
#include <Html/Html.h>
#include <Html/Custom/HtmlNotFound.h>
#include "TaskSaveNotFoundPage.h"
#include "Task/Web/TaskDownloadPage.h"

TaskSaveNotFoundPage::TaskSaveNotFoundPage()
{}

auto TaskSaveNotFoundPage::process() -> void
{
    shared_ptr<Html> pageNotFound = HtmlNotFound::getPage();

    if(Application::getHttpMap().hasPath(pageNotFound->getUrl()))
        return;

    Application::getHttpMap().addPath(pageNotFound->getUrl());

    setNext<TaskDownloadPage>(pageNotFound);
    TaskBase::process();
}