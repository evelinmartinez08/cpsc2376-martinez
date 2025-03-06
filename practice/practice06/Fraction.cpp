#include "Fraction.h"

void Fraction::simplify() {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");

    int a = num, b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    num /= gcd;
    den /= gcd;

    if (den < 0) {
        num = -num;
        den = -den;
    }
}

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) : num(n), den(d) {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");
    simplify();
}

int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    den = d;
    simplify();
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int numerator = lhs.num * rhs.den + rhs.num * lhs.den;
    int denominator = lhs.den * rhs.den;
    Fraction result(numerator, denominator);
    return result;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int numerator = lhs.num * rhs.den - rhs.num * lhs.den;
    int denominator = lhs.den * rhs.den;
    Fraction result(numerator, denominator);
    return result;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    int numerator = lhs.num * rhs.num;
    int denominator = lhs.den * rhs.den;
    Fraction result(numerator, denominator);
    return result;
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) throw std::invalid_argument("Cannot divide by zero");
    int numerator = lhs.num * rhs.den;
    int denominator = lhs.den * rhs.num;
    Fraction result(numerator, denominator);
    return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.getNumerator() << "/" << fraction.getDenominator();
    return os;
}