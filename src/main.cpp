#include <precomp.h>
#include <Html/HtmlParser.h>
#include <Html/HtmlDebug.h>
#include <Http/HttpPath.h>
#include <Task/TaskDownloadWeb.h>
#include "Application.h"

int main(int argc, char * argv[])
{
    if(argc == 2)
    {
        string url(argv[1]);

        TaskDownloadWeb dw("http://192.168.2.249/MSMain/");
        dw.process();
    }
    else
        cerr << "Missing url" << endl;

    return 0;
}