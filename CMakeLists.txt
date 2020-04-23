cmake_minimum_required(VERSION 3.15)

project(web_downloader)

set(CMAKE_CXX_STANDARD 17)

find_package(LibXml2 REQUIRED)

include_directories(src ${LIBXML2_INCLUDE_DIR})

add_executable(web_downloader src/main.cpp src/Http/HttpClient.cpp src/Http/HttpClient.h src/precomp.h src/Html/HtmlParser.cpp src/Html/HtmlParser.h src/Html/HtmlDumper.cpp src/Html/HtmlDumper.h src/Html/HtmlDebug.cpp src/Html/HtmlDebug.h src/Task/TaskModifyLinks.cpp src/Task/TaskModifyLinks.h src/Task/TaskBase.h src/Task/TaskBase.cpp src/Task/Task.h src/Task/TaskDownloadWeb.cpp src/Task/TaskDownloadWeb.h src/Task/Task.cpp src/Task/TaskDownloadFile.cpp src/Task/TaskDownloadFile.h src/Html/Html.cpp src/Html/Html.h src/Task/TaskDownloadImages.cpp src/Task/TaskDownloadImages.h src/Application.cpp src/Application.h src/Http/HttpPath.cpp src/Http/HttpPath.h)

target_link_libraries(web_downloader ${LIBXML2_LIBRARIES})