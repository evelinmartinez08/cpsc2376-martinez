#pragma once
#include "Purchase.h"
#include <memory>

class DiscountDecorator : public Purchase {
private:
    std::shared_ptr<Purchase> purchase;

public:
    DiscountDecorator(std::shared_ptr<Purchase> p) : purchase(p) {}
    double getCost() const override {
        return purchase->getCost() * 0.90;
    }
};
