#pragma once
#include <string>

class TextFilter {
public:
    virtual std::string apply(const std::string& input) = 0;
    virtual ~TextFilter() = default;
};
