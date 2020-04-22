//
// Created by Richard Baláž on 31/03/2020.
//

#ifndef WEB_DOWNLOADER_HTTPCLIENT_H
#define WEB_DOWNLOADER_HTTPCLIENT_H


class HttpClient
{
public:
    explicit HttpClient(string url);
    virtual ~HttpClient();

    static string getContent(const string & url);
public:

    void setPutData(const string & data, const char * type)
    {
        _sendData = &data;
        _sendDataType = type;
    }

    HttpClient & setTimeout(int seconds) { _timeout = seconds; return *this; }

    HttpClient & sendHttp();
    HttpClient & readResponse();

    bool ok() const { return _ok; }

    const string & response() const { return _response; }

    const string & data() const { return _data; }

    const string & tillError() const { return _readTillError; }
    HttpClient & dataTillError(string & tillError) & { tillError = _readTillError; return *this; }
    HttpClient & dataTillError(string & tillError) && { tillError = std::move(_readTillError); return *this; }


private:
    void parseUrl(string && url);

    bool openSocket();
    void closeSocket();

    // some socket functions return less-than-zero if invalid
    // so this checks whether the return value is valid
    bool isAlive(int ret) const { return ret >= 0; }

private:

    string _hostname;
    string _uri;

    string _response;
    string _readTillError;
    const string * _sendData = nullptr;
    string _sendDataType;
    string _data;
    bool _ok;
    int _socket = -1;

    int _timeout = 10;
};

#endif //WEB_DOWNLOADER_HTTPCLIENT_H
