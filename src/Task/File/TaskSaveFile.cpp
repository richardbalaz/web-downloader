//
// Created by Richard Baláž on 25/04/2020.
//

#include <precomp.h>
#include "TaskSaveFile.h"

TaskSaveFile::TaskSaveFile(const HttpPath & url, const string & content)
    : _url(url)
    , _content(content)
{}

void TaskSaveFile::process()
{
    string outputFile = Application::getOutputFolder() + _url.getUri();

    filesystem::path outputPath(outputFile);
    filesystem::create_directories(outputPath.parent_path());

    assert(!filesystem::exists(outputPath) && "Trying to save file which already exists, use HttpMap to avoid.");

    ofstream file(outputFile, ios::out | ios::binary);

    if(!file.is_open())
        throw runtime_error("Cannot open file for writing.");

    file << _content;

    file.close();
    TaskBase::process();
}
