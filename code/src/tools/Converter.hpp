#pragma once
#include <vector>
#include <string>
#include <cassert>

#include "Event.hpp"

namespace Converter
{

std::vector<Event> convert(std::vector<std::string> &params)
{
    if (params.size() == 0)
    {
        assert(false);
    }

    std::vector<Event> convertedParams{};
    convertedParams.reserve(10);
    Event event{};

    auto begin = params.begin();
    const auto end = params.end();

    while (begin != end)
    {
        event.setId(std::stoi(*begin++));
        event.setNameOfAction((*begin++));
        event.setDescription((*begin++));
        convertedParams.push_back(event);
    }
    convertedParams.shrink_to_fit();
    params = std::vector<std::string>{};
    return convertedParams;
}

} // namespace Converter