//
// Created by Richard Baláž on 31/03/2020.
//

#ifndef WEB_DOWNLOADER_HTTPCLIENT_H
#define WEB_DOWNLOADER_HTTPCLIENT_H

class HttpPath;

// Network client for connecting to Http server and getting a response of request
// Example: getContent({ "http://localhost/index.html" }) -> plain Html
// Example: getContent({ "http://localhost/image.png" }) -> png binary
class HttpClient
{
public:
    HttpClient() = default;
    virtual ~HttpClient();

    // Connects to url and return it's content
    auto getContent(const HttpPath & url) -> string;

private:
    // Set hostname
    auto setHostname(const string & hostname) -> void;
    // Set uri
    auto setUri(const string & uri) -> void;

    // Set timeout (time to response)
    auto setTimeout(int seconds) -> HttpClient &;

    // Send Http request
    auto sendHttp() -> HttpClient &;
    // Read Http response
    auto readResponse() -> HttpClient &;

    // Is client ok
    auto ok() const -> bool;

    // Return response
    auto response() const -> const string &;
    // Return data received by server
    auto data() const -> const string &;
    // Return data till error
    auto tillError() const -> const string &;

    // Copy data till error
    auto dataTillError(string & tillError) -> HttpClient &;

private:
    // Open socket to hostname
    auto openSocket() -> bool;
    // Close currently opened socket
    auto closeSocket() -> void;

    // Some socket functions return less-than-zero if invalid
    // so this checks whether the return value is valid
    auto isAlive(int ret) const -> bool;

private:
    string _hostname;
    string _uri;

    string _response;
    string _readTillError;
    string _data;
    bool _ok;
    int _timeout {10};

    int _socket {-1};
};

#endif //WEB_DOWNLOADER_HTTPCLIENT_H
