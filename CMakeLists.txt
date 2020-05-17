cmake_minimum_required(VERSION 3.15)

project(web_downloader)

set(CMAKE_CXX_STANDARD 17)

find_package(LibXml2 REQUIRED)

include_directories(src ${LIBXML2_INCLUDE_DIR})

add_executable(web_downloader src/main.cpp src/Http/HttpClient.cpp src/Http/HttpClient.h src/precomp.h src/Html/HtmlParser.cpp src/Html/HtmlParser.h src/Html/HtmlDumper.cpp src/Html/HtmlDumper.h src/Html/HtmlDebug.cpp src/Html/HtmlDebug.h src/Task/Web/TaskModifyLinks.cpp src/Task/Web/TaskModifyLinks.h src/Task/TaskBase.h src/Task/TaskBase.cpp src/Task/Task.h src/Task/Web/TaskDownloadWeb.cpp src/Task/Web/TaskDownloadWeb.h src/Task/Task.cpp src/Task/File/TaskDownloadFile.cpp src/Task/File/TaskDownloadFile.h src/Html/Html.cpp src/Html/Html.h src/Task/Image/TaskDownloadImages.cpp src/Task/Image/TaskDownloadImages.h src/Application.cpp src/Application.h src/Http/HttpPath.cpp src/Http/HttpPath.h src/Task/Web/TaskDownloadPage.cpp src/Task/Web/TaskDownloadPage.h src/Task/Style/TaskDownloadStyles.cpp src/Task/Style/TaskDownloadStyles.h src/Task/Style/TaskDownloadStyle.cpp src/Task/Style/TaskDownloadStyle.h src/Task/File/TaskSaveFile.cpp src/Task/File/TaskSaveFile.h src/Task/Web/TaskDownloadLinks.cpp src/Task/Web/TaskDownloadLinks.h src/Http/HttpMap.cpp src/Http/HttpMap.h src/Task/Image/TaskModifyImageLinks.cpp src/Task/Image/TaskModifyImageLinks.h src/Enum.h src/Task/Web/TaskModifyPageLinks.cpp src/Task/Web/TaskModifyPageLinks.h src/Html/Custom/HtmlNotFound.cpp src/Html/Custom/HtmlNotFound.h src/Task/404/TaskSaveNotFoundPage.cpp src/Task/404/TaskSaveNotFoundPage.h)

target_link_libraries(web_downloader ${LIBXML2_LIBRARIES})