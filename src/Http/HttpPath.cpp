//
// Created by Richard Baláž on 23/04/2020.
//
#include <precomp.h>
#include "HttpPath.h"

HttpPath::HttpPath(string path, const HttpPath * prevPath)
    : _path(move(path))
    , _prevPath(prevPath)
{
    extractHostname();
    extractUri();
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

auto HttpPath::extractHostname() -> bool
{
    if(!isAbsolute())
    {
        _hostname = _prevPath->getHostname();
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

auto HttpPath::extractUri() -> bool
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

        if(_prevPath->getUri().back() == '/')
        {
            _uri = _prevPath->getUri() + path;
            return true;
        }

        auto lastSlashPos = _uri.find_last_of('/') ;
        _uri = string(_prevPath->getUri().begin(), _prevPath->getUri().begin() + lastSlashPos) + path;
    }

    /*if(_uri.back() == '/' && _uri.length() > 1)
        _uri.pop_back();*/

    return !_uri.empty();
}

