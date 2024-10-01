#include "fraction.h"

#include <utility>

Fraction::Fraction():numerator(0),denominator(1)
{
    simplify();
}

Fraction::Fraction(int n, int d):numerator(n),denominator(d)
{
    simplify();
}

Fraction Fraction::add(const Fraction& f) const
{
    int num = numerator * f.denominator + f.numerator * denominator;
    int denom = denominator * f.denominator;
    return Fraction(num,denom);
}

Fraction Fraction::sub(const Fraction& f) const
{
    int num = numerator * f.denominator - f.numerator * denominator;
    int denom = denominator * f.denominator;
    return Fraction(num,denom);
}

bool Fraction::equals(const Fraction& f) const
{
    return numerator==f.numerator && denominator==f.denominator;
}

Fraction Fraction::pow(unsigned int n) const
{
    Fraction frac = Fraction(1,1);

    for (int i = 0; i < n; i++) {
        frac = this->mult(frac);
    }
    return frac;
}

std::string Fraction::toString() const
{
    int whole_num;
    int remainder;

    if (numerator%denominator == 0)
    {
        whole_num = numerator/denominator;
        return std::to_string(whole_num);
    }
    else
    {
        whole_num = numerator/denominator;
        remainder = abs(numerator%denominator);

        if (whole_num != 0)
            return std::to_string(whole_num) + " " + std::to_string(remainder) + "/" + std::to_string(denominator);

        return std::to_string(remainder) + "/" + std::to_string(denominator);
    }

    //return std::to_string(numerator)+"/"+std::to_string(denominator);
}

/* --siehe 1. Vorlesungsstunde Programmierung 1 */
int Fraction::gcd(int a, int b)
{
    /* --Sonderfaelle. */
    if (a==0)
        return abs(b);
    if (b==0)
        return abs(a);
    while (b!=0)
    {
        int h = a%b;
        a=b;
        b=h;
    }
    return abs(a);
}


void Fraction::simplify()
{
    /* --Negativer Nenner. */
    if (denominator<0)
    {
        numerator=-numerator;
        denominator=-denominator;
    }
    /* --Kuerzen. */
    if (denominator!=0)
    {
        int g=gcd(numerator,denominator);
        numerator/=g;
        denominator/=g;
    }
}

Fraction Fraction::reciprocal() const {
    //Bruch mit Zaehler und Nenner getauscht zurueckgeben
    return Fraction(denominator, numerator);
}

Fraction Fraction::mult(const Fraction& f) const {

    //a/b*c/d = a/d*c/b
    Fraction a = Fraction(numerator, f.denominator);
    Fraction b = Fraction(f.numerator, denominator);
    return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
}

Fraction Fraction::div(const Fraction& f) const {
    //Division zweier Brüche kann durch den Kehrwert realisiert werden
    return this->mult(f.reciprocal());
}
