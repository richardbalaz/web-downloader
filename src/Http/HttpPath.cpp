//
// Created by Richard Baláž on 23/04/2020.
//
#include <precomp.h>
#include "HttpPath.h"

HttpPath::HttpPath(string path, const optional<HttpPath> & prevPath)
    : _path(move(path))
    , _hostnameDiffersFromPrev(nullopt)
{
    extractHostname(prevPath);
    extractUri(prevPath);

    if(prevPath)
        _hostnameDiffersFromPrev = getHostname() != prevPath->getHostname();
}

auto HttpPath::isAbsolute() const -> bool
{
    regex isAbsoluteRegex("^(?:[a-z]+:)?//");
    smatch isAbsoluteMatch;

    return regex_search(_path, isAbsoluteMatch, isAbsoluteRegex);
}

auto HttpPath::getHostname() const -> const string &
{
    return _hostname;
}

auto HttpPath::getUri() const -> const string &
{
    return _uri;
}

auto HttpPath::extractHostname(const optional<HttpPath> & prevPath) -> bool
{
    if(!isAbsolute())
    {
        if(prevPath.has_value())
            _hostname = prevPath->getHostname();

        return false;
    }

    _hostname = _path;

    if(_hostname.rfind("//", 0) != string::npos)
        _hostname.erase(0, 2);

    if(_hostname.rfind("http://", 0) != string::npos)
        _hostname.erase(0, 7);

    if(auto pos = _hostname.find('/'); pos != string::npos)
        _hostname.erase(_hostname.begin() + pos, _hostname.end());

    return !_hostname.empty();
}

auto HttpPath::extractUri(const optional<HttpPath> & prevPath) -> bool
{
    string path = _path;

    if(isAbsolute())
    {
        if(path.rfind("//", 0) != string::npos)
            path.erase(0, 2);

        if(path.rfind("http://", 0) != string::npos)
            path.erase(0, 7);

        if(auto pos = path.find_first_of('/'); pos != string::npos)
            _uri = string(path.begin() + pos, path.end());
        else
            return false;
    }
    else
    {
        if(path.front() == '/')
        {
            _uri = path;
            return true;
        }

        if(prevPath->getUri().back() == '/')
        {
            _uri = prevPath->getUri() + path;
            return true;
        }

        auto lastSlashPos = prevPath->getUri().find_last_of('/');
        _uri = string(prevPath->getUri().begin(), prevPath->getUri().begin() + lastSlashPos + 1) + path;
    }

    return !_uri.empty();
}

auto HttpPath::hostnameDiffersFromPrev() const -> bool
{
    return *_hostnameDiffersFromPrev;
}

auto HttpPath::operator==(const HttpPath &other) const -> bool
{
    return getHostname() == other.getHostname() && getUri() == other.getUri();
}

auto HttpPath::getHttpUrl() const -> string
{
    return "http://" + getHostname() + getUri();
}
