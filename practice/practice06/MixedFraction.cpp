#include "MixedFraction.h"
#include <iostream>

MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(n, d), wholePart(whole) {}

MixedFraction::MixedFraction(const Fraction& fraction) {
    wholePart = fraction.getNumerator() / fraction.getDenominator();
    int remainder = fraction.getNumerator() % fraction.getDenominator();
    *this = Fraction(remainder, fraction.getDenominator());
}

std::ostream& operator<<(std::ostream& os, const MixedFraction& mixedFraction) {
    os << mixedFraction.wholePart << " ";
    os << static_cast<const Fraction&>(mixedFraction);
    return os;
}