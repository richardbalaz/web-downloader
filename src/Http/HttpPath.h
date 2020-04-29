//
// Created by Richard Baláž on 23/04/2020.
//

#ifndef WEB_DOWNLOADER_HTTPPATH_H
#define WEB_DOWNLOADER_HTTPPATH_H

// Single path of Http link with context of previous path
// Class can normalize all paths which can be found in Http links
// Previous path is important, because relative paths cannot be constructed without it
// Previous path may be nullopt, but hostname can be empty if not given in path
// Example:
// Absolute -> http://localhost/some/path | //localhost/another/path
// Relative -> ./some/path | ../another/path | /some/path/ | somefile.png
class HttpPath
{
public:
    HttpPath(string path, const optional<HttpPath> & prevPath = nullopt);

public:
    // Return the domain of path (e.g. localhost)
    auto getHostname() const -> const string &;
    // Return only the path (always starts with / ) after domain (e.g. /some/path/index.html)
    auto getUri() const -> const string &;

    // Return path in full Http url (e.g. http://localhost/some/path/index.html)
    auto getHttpUrl() const -> string;

    // Return if current hostname is different than in previous path
    // Used to tell if path points to another website
    auto hostnameDiffersFromPrev() const -> bool;

public:
    // Check if hostname and uri are the same
    auto operator==(const HttpPath & other) const -> bool;

private:
    // Parse the hostname part from given path at construction
    auto extractHostname(const optional<HttpPath> & = nullopt) -> bool;
    // Parse the uri part from given path at construction
    auto extractUri(const optional<HttpPath> & = nullopt) -> bool;

    // Check if given path at construction is absolute or not
    auto isAbsolute() const -> bool;
private:
    string _path;
    string _hostname;
    string _uri;

    optional<bool> _hostnameDiffersFromPrev;
};

#endif //WEB_DOWNLOADER_HTTPPATH_H
