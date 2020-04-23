//
// Created by Richard Baláž on 22/04/2020.
//

#ifndef WEB_DOWNLOADER_APPLICATION_H
#define WEB_DOWNLOADER_APPLICATION_H

#include <Http/HttpClient.h>

class Application
{
public:
    static auto httpClient() -> HttpClient &;

public:
    static HttpClient _httpClient;
};


#endif //WEB_DOWNLOADER_APPLICATION_H
