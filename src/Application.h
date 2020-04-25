//
// Created by Richard Baláž on 22/04/2020.
//

#ifndef WEB_DOWNLOADER_APPLICATION_H
#define WEB_DOWNLOADER_APPLICATION_H

#include <Http/HttpClient.h>
#include <Http/HttpMap.h>

class Application
{
public:
    static auto getHttpClient() -> HttpClient &;
    static auto getOutputFolder() -> const string &;
    static auto getHttpMap() -> HttpMap &;

public:
    static auto setOutputFolder(string folder) -> void;

public:
    static HttpMap _httpMap;
    static HttpClient _httpClient;
    static string _outputFolder;
};


#endif //WEB_DOWNLOADER_APPLICATION_H
