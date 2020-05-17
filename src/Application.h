//
// Created by Richard Baláž on 22/04/2020.
//

#ifndef WEB_DOWNLOADER_APPLICATION_H
#define WEB_DOWNLOADER_APPLICATION_H

#include <Http/HttpClient.h>
#include <Http/HttpMap.h>

// Application settings and singleton instances
class Application
{
public:
    // Return webiste url about to be downloaded
    static auto getWebsiteToDownload() -> const string &;
    // Return client for Http communication
    static auto getHttpClient() -> HttpClient;
    // Return output folder where the website is downloaded (ends without '/')
    static auto getOutputFolder() -> const string &;
    // Return map of website
    static auto getHttpMap() -> HttpMap &;
    // Maximum depth of website downloading (0 = don't download deeper than firstly given page)
    static auto getMaxDepth() -> unsigned int;
    // Check if image downloading is enabled
    static auto isLocalImagesEnabled() -> bool;
    // Check if use 'Page not found' for too deep pages is enabled
    static auto isNotFoundForExcessiveDepthEnabled() -> bool;

public:
    static auto init(int argc, char * argv[]) -> void;
    static auto init(const vector<string> & args) -> void;

    static auto run() -> void;

public:
    // Set website url about to be downloaded
    static auto setWebsiteToDownload(string url) -> void;
    // Set output folder root where the website is downloaded (e.g. ~/localhost-website/)
    static auto setOutputFolder(string folder) -> void;
    // Set maximum depth of website which can be downloaded
    static auto setMaxDepth(unsigned int depth) -> void;
    // Enable image downloading
    static auto setLocalImagesEnabled(bool enabled) -> void;
    // Enable 'Page not found' for too deep pages
    static auto setNotFoundForExcessiveDepthEnabled(bool enabled) -> void;

public:
    static string _websiteToDownload;
    static HttpMap _httpMap;
    static string _outputFolder;
    static unsigned int _maxDepth;
    static bool _localImagesEnabled;
    static bool _notFoundForExcessiveDepth;
};


#endif //WEB_DOWNLOADER_APPLICATION_H
