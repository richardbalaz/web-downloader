#include <precomp.h>
#include <Html/HtmlParser.h>
#include <Html/HtmlDebug.h>
#include <Http/HttpPath.h>
#include <Task/TaskDownloadWeb.h>
#include "Application.h"

int main(int argc, char * argv[])
{
    if(argc == 3)
    {
        string url(argv[1]);
        string output(argv[2]);

        Application::setOutputFolder("/Users/richardbalaz/Documents/web");

        TaskDownloadWeb dw({ "http://localhost/" });
        dw.process();
    }
    else
        cerr << "Missing url or output path" << endl;

    return 0;
}