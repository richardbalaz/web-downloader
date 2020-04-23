//
// Created by Richard Baláž on 23/04/2020.
//

#ifndef WEB_DOWNLOADER_HTTPPATH_H
#define WEB_DOWNLOADER_HTTPPATH_H

class HttpPath
{
public:
    HttpPath(string path, const HttpPath * prevPath = nullptr);

public:
    auto getHostname() const -> const string &;
    auto getUri() const -> const string &;

private:
    auto isAbsolute() const -> bool;

    auto extractHostname() -> bool;
    auto extractUri() -> bool;

private:
    string _path;
    string _hostname;
    string _uri;

    const HttpPath * _prevPath;
};

#endif //WEB_DOWNLOADER_HTTPPATH_H
