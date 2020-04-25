//
// Created by Richard Baláž on 25/04/2020.
//

#include <precomp.h>
#include "HttpMap.h"

auto HttpMap::addPath(const HttpPath &path) -> void
{
    if(!hasPath(path))
        _paths.emplace_back(path);
}

auto HttpMap::hasPath(const HttpPath &path) -> bool
{
    return any_of(_paths.begin(), _paths.end(), [&](const HttpPath & existingPath)
    {
        return existingPath == path;
    });
}
