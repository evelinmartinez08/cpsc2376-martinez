#pragma once
#include "Purchase.h"
#include <memory>

class TaxDecorator : public Purchase {
private:
    std::shared_ptr<Purchase> purchase;

public:
    TaxDecorator(std::shared_ptr<Purchase> p) : purchase(p) {}
    double getCost() const override {
        return purchase->getCost() * 1.10;
    }
};

