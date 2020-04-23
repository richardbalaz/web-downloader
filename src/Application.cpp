//
// Created by Richard Baláž on 22/04/2020.
//

#include <precomp.h>

HttpClient Application::_httpClient;

auto Application::httpClient() -> HttpClient &
{
    return _httpClient;
}
