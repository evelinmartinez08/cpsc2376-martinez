#pragma once

class Purchase {
public:
    virtual double getCost() const = 0;
    virtual ~Purchase() = default;
};
