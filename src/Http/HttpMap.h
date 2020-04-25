//
// Created by Richard Baláž on 25/04/2020.
//

#ifndef WEB_DOWNLOADER_HTTPMAP_H
#define WEB_DOWNLOADER_HTTPMAP_H


#include "HttpPath.h"

class HttpMap
{
public:
    HttpMap() = default;

public:
    auto addPath(const HttpPath & path) -> void;
    auto hasPath(const HttpPath & path) -> bool;

private:
    vector<HttpPath> _paths;
};


#endif //WEB_DOWNLOADER_HTTPMAP_H
