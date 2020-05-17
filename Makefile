LIBXML2_INCLUDE_DIR=/usr/include/libxml2
LIBXML2_LIBRARY=/usr/lib/x86_64-linux-gnu/libxml2.so
PROJECT_INCLUDE_DIR=./src
CXX=g++ -g -std=c++17 -Wall -pedantic -Wno-long-long -I$(PROJECT_INCLUDE_DIR) -I$(LIBXML2_INCLUDE_DIR)

SRC_FILES = src/main.cpp src/Http/HttpClient.cpp src/Html/HtmlParser.cpp src/Html/HtmlDumper.cpp src/Html/HtmlDebug.cpp src/Task/Web/TaskModifyLinks.cpp src/Task/TaskBase.cpp src/Task/Web/TaskDownloadWeb.cpp src/Task/Task.cpp src/Task/File/TaskDownloadFile.cpp src/Html/Html.cpp src/Task/Image/TaskDownloadImages.cpp src/Application.cpp src/Http/HttpPath.cpp src/Task/Web/TaskDownloadPage.cpp src/Task/Style/TaskDownloadStyles.cpp src/Task/Style/TaskDownloadStyle.cpp src/Task/File/TaskSaveFile.cpp src/Task/Web/TaskDownloadLinks.cpp src/Http/HttpMap.cpp src/Task/Image/TaskModifyImageLinks.cpp src/Task/Web/TaskModifyPageLinks.cpp src/Html/Custom/HtmlNotFound.cpp src/Task/404/TaskSaveNotFoundPage.cpp

all: clean compile

compile:
	@echo "Compiling project..."
	@$(CXX) -o balazric $(SRC_FILES) $(LIBXML2_LIBRARY) -lstdc++fs -lpthread
	@echo "Compiling done"

run: clean compile
	@echo "Running project..."
	@mkdir web
	@./balazric --output-dir ./web http://localhost/index.html

clean:
	@echo "Cleaning project build files..."
	@rm -rf web
	@rm -f balazric
	@echo "Cleaning done"

doc:
	@echo "No dynamic doc generation, use static files in ./doc"