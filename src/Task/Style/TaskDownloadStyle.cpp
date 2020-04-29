//
// Created by Richard Baláž on 25/04/2020.
//

#include <precomp.h>
#include <Http/HttpClient.h>
#include "TaskDownloadStyle.h"
#include "Task/File/TaskDownloadFile.h"
#include "Task/File/TaskSaveFile.h"


TaskDownloadStyle::TaskDownloadStyle(const HttpPath & url)
        : _url(url)
{}

auto TaskDownloadStyle::process() -> void
{
    string stylesheet = Application::getHttpClient().getContent(_url);

    regex isFileInUrl("getUrl\\((.*?)\\)");

    for(auto it = sregex_iterator(stylesheet.begin(), stylesheet.end(), isFileInUrl); it != sregex_iterator(); ++it)
    {
        string fileInUrl = it->str();
        // erase getUrl(
        fileInUrl.erase(0, 4);
        // erase )
        fileInUrl.pop_back();

        // erase first quote if there
        if(fileInUrl.front() == '\'' || fileInUrl.front() == '"')
            fileInUrl.erase(0, 1);

        // erase last quote if there
        if(fileInUrl.back() == '\'' || fileInUrl.back() == '"')
            fileInUrl.pop_back();

        HttpPath dependencyPath(fileInUrl, _url);

        if(dependencyPath.hostnameDiffersFromPrev() || Application::getHttpMap().hasPath(dependencyPath))
            continue;

        Application::getHttpMap().addPath(dependencyPath);

        setNext<TaskDownloadFile>(dependencyPath);
    }

    setNext<TaskSaveFile>(_url, stylesheet);
    TaskBase::process();
}