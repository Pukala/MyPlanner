#pragma once
#include <vector>
#include <string>
#include "Event.hpp"
#include <iostream>
#include <cassert>

namespace Converter
{

std::vector<Event> convert(const std::vector<std::string> &params)
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
    return convertedParams;
}

} // namespace Converter