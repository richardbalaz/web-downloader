//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include <Http/HttpClient.h>
#include "TaskDownloadFile.h"

TaskDownloadFile::TaskDownloadFile(const HttpPath & url)
        : _url(url)
{}

auto TaskDownloadFile::process() -> void
{
    cout << "download file '" << _url.getHostname() << "' uri: '" << _url.getUri() << "'" << endl;

    const string content = Application::httpClient().getContent(_url);


    ofstream file("./test.png", ios::out | ios::binary);

    if(!file.is_open())
        throw runtime_error("Cannot open file for writing.");

    file << content;

    file.close();
    TaskBase::process();
}

