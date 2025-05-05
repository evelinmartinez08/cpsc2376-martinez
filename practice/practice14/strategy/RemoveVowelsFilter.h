#pragma once
#include "TextFilter.h"
#include <string>
#include <algorithm>

class RemoveVowelsFilter : public TextFilter {
public:
    std::string apply(const std::string& input) override {
        std::string result = input;
        result.erase(std::remove_if(result.begin(), result.end(), [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        }), result.end());
        return result;
    }
};
