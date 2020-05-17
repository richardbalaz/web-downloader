//
// Created by Richard Baláž on 20/04/2020.
//

#include <precomp.h>
#include "TaskModifyLinks.h"
#include <Html/Html.h>
#include <Html/Custom/HtmlNotFound.h>

TaskModifyLinks::TaskModifyLinks(shared_ptr<Html> page, ELocationType placement)
    : _page(std::move(page))
    , _placement(placement)
{}

auto TaskModifyLinks::process() -> void
{
    for(auto & node : _page->search(getNodeName()))
    {
        string urlRaw = node.getProperty(getAttrName());
        if(urlRaw.empty() || urlRaw == "#")
            continue;

        HttpPath url(urlRaw, _page->getUrl());

        if(url.hostnameDiffersFromPrev())
            continue;

        string location;
        switch(_placement)
        {
            case ELocationType::LOCAL :
                location = Application::getOutputFolder() + url.getUri();
                break;
            case ELocationType::REMOTE :
                location = url.getHttpUrl();
                break;
            case ELocationType::NOT_FOUND :
                location = Application::getOutputFolder() + HtmlNotFound::getPage()->getUrl().getUri();
                break;
            default:
                static_assert("Unhandled placement.");
        }

        node.setProperty(getAttrName(), location);
    }

    TaskBase::process();
}

