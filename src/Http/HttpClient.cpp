//
// Created by Richard Baláž on 31/03/2020.
//

#include <precomp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#include "HttpClient.h"
#include "HttpPath.h"

HttpClient::~HttpClient()
{
    closeSocket();
}

auto HttpClient::sendHttp() -> HttpClient &
{
    if(!openSocket())
    {
        _ok = false;
        return *this;
    }

    string get_http = "GET ";

    get_http += _uri + " HTTP/1.1\r\n"
        "Host: " + _hostname + "\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3\r\n"
        "Accept-Encoding: deflate\r\n"
        "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36\r\n"
        "Connection: close\r\n";

    get_http += "\r\n";

    auto SendIt = [this](const string & data) -> bool
    {
        const char * d = data.c_str();
        int size = (int) data.size();
        while(size != 0)
        {
            const int r = send(_socket, d, size, 0);
            if(r == -1)
                return false;

            size -= r;
            d += r;
        }
        return true;
    };

    if(!SendIt(get_http))
    {
        closeSocket();
        _ok = false;
    }

    return *this;
}


auto HttpClient::readResponse() -> HttpClient &
{
    if (!isAlive(_socket))
        return *this;

    vector<char> buffer;
    buffer.resize(10 * 1024);

    _response.clear();
    _response.reserve(8 * 1024);

    int nDataLength;
    while ((nDataLength = recv(_socket, &buffer[0], static_cast<int>(buffer.size()), 0)) > 0)
    {
        _response += string(&buffer[0], nDataLength);
    }

    if (!isAlive(nDataLength))
    {
        _readTillError = move(_response);
        _response.clear();
    }

    closeSocket();

    string::size_type end_header = _response.find("\r\n\r\n");
    if(end_header != string::npos)
    {
        end_header += 4;
        _data = string(_response.begin() + end_header, _response.end());
    }

    return *this;
}


auto HttpClient::closeSocket() -> void
{
    if(!isAlive(_socket))
        return;

    close(_socket);
    _socket = -1;
}

auto HttpClient::setUri(const string & uri) -> void
{
    _uri = uri;
}

auto HttpClient::setHostname(const string & hostname) -> void
{
    _hostname = hostname;
}

auto HttpClient::openSocket() -> bool
{
    addrinfo hints {}, *lookup;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;

    if(getaddrinfo(_hostname.c_str(), "http", &hints, &lookup) != 0)
        return false;

    _socket = socket(lookup->ai_family, lookup->ai_socktype, lookup->ai_protocol);

    if(!isAlive(_socket))
        return false;

    if(!isAlive(connect(_socket, lookup->ai_addr, lookup->ai_addrlen)))
        return false;

    freeaddrinfo(lookup);

    timeval timeout {};
    timeout.tv_sec = _timeout;
    timeout.tv_usec = 0;

    setsockopt(_socket, SOL_SOCKET, SO_SNDTIMEO, (char *) &timeout, sizeof(timeout));
    setsockopt(_socket, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

    return true;
}

auto HttpClient::getContent(const HttpPath & url) -> string
{
    string tillError;

    setHostname(url.getHostname());
    setUri(url.getUri());
    setTimeout(10);
    sendHttp();
    readResponse();
    dataTillError(tillError);

    return data();
}

auto HttpClient::setTimeout(int seconds) -> HttpClient &
{
    _timeout = seconds;
    return *this;
}

auto HttpClient::ok() const -> bool
{
    return _ok;
}

auto HttpClient::response() const -> const string &
{
    return _response;
}

auto HttpClient::data() const -> const string &
{
    return _data;
}

auto HttpClient::tillError() const -> const string &
{
    return _readTillError;
}

auto HttpClient::dataTillError(string & tillError) -> HttpClient &
{
    tillError = _readTillError;
    return *this;
}

auto HttpClient::isAlive(int ret) const -> bool
{
    return ret >= 0;
}
