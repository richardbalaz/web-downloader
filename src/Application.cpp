//
// Created by Richard Baláž on 22/04/2020.
//

#include <precomp.h>
#include "Application.h"

HttpClient Application::_httpClient;
string Application::_outputFolder;
HttpMap Application::_httpMap;

auto Application::getHttpClient() -> HttpClient &
{
    return _httpClient;
}

auto Application::getOutputFolder() -> const string &
{
    return _outputFolder;
}

auto Application::setOutputFolder(string path) -> void
{
    if(filesystem::is_directory(path))
    {
        if(path.back() == '/')
            path.pop_back();

        _outputFolder = move(path);
    }
    else
        throw runtime_error("Path is not folder.");
}

auto Application::getHttpMap() -> HttpMap &
{
    return _httpMap;
}
