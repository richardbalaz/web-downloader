//
// Created by Richard Baláž on 23/04/2020.
//

#ifndef WEB_DOWNLOADER_HTTPPATH_H
#define WEB_DOWNLOADER_HTTPPATH_H

class HttpPath
{
public:
    HttpPath(string path, const optional<HttpPath> & prevPath = nullopt);

public:
    auto getHostname() const -> const string &;
    auto getUri() const -> const string &;

    auto hostnameDiffersFromPrev() const -> bool;

public:
    auto operator==(const HttpPath & other) const -> bool;

private:
    auto extractHostname(const optional<HttpPath> & = nullopt) -> bool;
    auto extractUri(const optional<HttpPath> & = nullopt) -> bool;

    auto isAbsolute() const -> bool;
private:
    string _path;
    string _hostname;
    string _uri;

    optional<bool> _hostnameDiffersFromPrev;
};

#endif //WEB_DOWNLOADER_HTTPPATH_H
