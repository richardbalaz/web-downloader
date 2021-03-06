//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include <Http/HttpClient.h>
#include "TaskDownloadFile.h"
#include "TaskSaveFile.h"

TaskDownloadFile::TaskDownloadFile(const HttpPath & url)
        : _url(url)
{}

auto TaskDownloadFile::process() -> void
{
    string content = Application::getHttpClient().getContent(_url);

    setNext<TaskSaveFile>(_url, content);
    TaskBase::process();
}

