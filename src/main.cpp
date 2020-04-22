#include <precomp.h>
#include <Html/HtmlParser.h>
#include <Html/HtmlDebug.h>
#include <Task/TaskDownloadWeb.h>

int main(int argc, char * argv[])
{
    if(argc == 2)
    {
        string url(argv[1]);

        TaskDownloadWeb dw(url);
        dw.process();
    }
    else
        cerr << "Missing url" << endl;

    return 0;
}