//
// Created by Richard Baláž on 22/04/2020.
//

#include <precomp.h>
#include "Application.h"

HttpClient Application::_httpClient;
string Application::_outputFolder;
HttpMap Application::_httpMap;
unsigned int Application::_maxDepth;
bool Application::_localImagesEnabled;
bool Application::_notFoundForExcessiveDepth;

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

auto Application::getMaxDepth() -> unsigned int
{
    return _maxDepth;
}

auto Application::setMaxDepth(unsigned int depth) -> void
{
    _maxDepth = depth;
}

auto Application::isLocalImagesEnabled() -> bool
{
    return _localImagesEnabled;
}

auto Application::setLocalImagesEnabled(bool enabled) -> void
{
    _localImagesEnabled = enabled;
}

auto Application::setNotFoundForExcessiveDepthEnabled(bool enabled) -> void
{
    _notFoundForExcessiveDepth = enabled;
}

auto Application::isNotFoundForExcessiveDepthEnabled() -> bool
{
    return _notFoundForExcessiveDepth;
}
