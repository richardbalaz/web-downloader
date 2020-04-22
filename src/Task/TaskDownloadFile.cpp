//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include "TaskDownloadFile.h"

TaskDownloadFile::TaskDownloadFile(string url)
        : _url(move(url))
{}

auto TaskDownloadFile::process() -> void
{
    cout << "download file" << endl;

    TaskBase::process();
}

