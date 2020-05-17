//
// Created by Richard Baláž on 22/04/2020.
//

#include <precomp.h>
#include "Application.h"
#include "Task/Web/TaskDownloadWeb.h"

string Application::_websiteToDownload;
string Application::_outputFolder;
HttpMap Application::_httpMap;
unsigned int Application::_maxDepth = 3;
bool Application::_localImagesEnabled = true;
bool Application::_notFoundForExcessiveDepth = false;

auto Application::getHttpClient() -> HttpClient
{
    return HttpClient();
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

auto Application::setWebsiteToDownload(string url) -> void
{
    _websiteToDownload = move(url);
}

auto Application::getWebsiteToDownload() -> const string &
{
    return _websiteToDownload;
}

auto Application::init(int argc, char * argv[]) -> void
{
    vector<string> args;
    for(int i = 1; i < argc; i++)
        args.push_back({ argv[i] });

    Application::init(args);
}

auto Application::init(const vector<string> & args) -> void
{
    for(auto it = args.begin(); it != args.end(); it++)
    {
        if(*it == "--output-dir")
        {
            Application::setOutputFolder(*(++it));
        }
        else if(*it == "--max-depth")
        {
            Application::setMaxDepth(stoi(*(++it)));
        }
        else if(*it == "--remote-images")
        {
            Application::setLocalImagesEnabled(false);
        }
        else if(*it == "--404-for-excessive-depth")
        {
            Application::setNotFoundForExcessiveDepthEnabled(true);
        }
        else
        {
            Application::setWebsiteToDownload(*it);
        }
    }

    if(Application::getOutputFolder().empty())
        throw runtime_error("Output folder not found, use --output-dir to specify where to download the web.");
}

auto Application::run() -> void
{
    HttpPath websitePath = { Application::getWebsiteToDownload() };
    TaskDownloadWeb(websitePath).process();
}
