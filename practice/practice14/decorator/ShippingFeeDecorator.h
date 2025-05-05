#pragma once
#include "Purchase.h"
#include <memory>

class ShippingFeeDecorator : public Purchase {
private:
    std::shared_ptr<Purchase> purchase;

public:
    ShippingFeeDecorator(std::shared_ptr<Purchase> p) : purchase(p) {}
    double getCost() const override {
        return purchase->getCost() + 5.0;
    }
};
