//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include "HtmlDumper.h"

auto HtmlDumper::save(htmlDocPtr document, const string & targetPath) -> void
{
    if(document == nullptr)
        return;

    auto bytesWritten = htmlSaveFile(targetPath.c_str(), document);

    if(bytesWritten == -1)
        throw std::runtime_error("Could't write document into file.");
}
