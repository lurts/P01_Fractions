#ifndef FRACTION_H
#define FRACTION_H

#include <string>

class Fraction
{
public:
    /* --Standardkonstruktor. */
    Fraction();
    /* --Konstruktor mit Werten. */
    Fraction(int n, int d = 1);
    /* --Addition. */
    Fraction add(const Fraction& f) const;
    /* --Subtraktion. */
    Fraction sub(const Fraction& f) const;
    /* --Identisch? */
    bool equals(const Fraction& f) const;
    /* --Kehrwert eines Bruches */
    Fraction reciprocal() const;
    /* --Multiplikation-- */
    Fraction mult(const Fraction& f) const;
    /* --Division-- */
    Fraction div(const Fraction& f) const;
    /* --Potenzieren-- */
    Fraction pow(const int n) const;
    /* --In Zeichenkette umwandeln. */
    std::string toString() const;
private:
    int numerator;      /* --Zaehler. */
    int denominator;    /* --Nenner. */
    /* --Hilfsmethode: GGT. */
    static int gcd(int a, int b);
    /* --Vereinfachen. */
    void simplify();
};

#endif // FRACTION_H
