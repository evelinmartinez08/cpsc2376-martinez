#pragma once
#include "TextFilter.h"
#include <memory>

class TextProcessor {
private:
    std::unique_ptr<TextFilter> strategy;

public:
    void setStrategy(std::unique_ptr<TextFilter> s) {
        strategy = std::move(s);
    }

    std::string process(const std::string& input) {
        return strategy->apply(input);
    }
};
