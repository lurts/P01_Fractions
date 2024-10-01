#include <iostream>

/* --Bruchrechnen mit C++. */
#include "fraction.h"

/* --Testfunction. */
bool eval(const std::string& title, const Fraction& f, const Fraction& expect)
{
    bool retvalue=true;
    std::cout << "Running " << title << "... " << std::flush;
    /* --Erwartetes Ergebnis? */
    if (f.equals(expect))
        std::cout << "ok... " << f.toString() + " == " + expect.toString()<< std::endl;
    else
    {
        std::cout << "failed! expected value is "
                  << expect.toString() << " got " << f.toString() << "." << std::endl;
        retvalue=false;
    }
    return retvalue;
}

bool str_eval(const std::string& title, const std::string& f, const std::string& expect){
    bool retvalue = true;
    std::cout << "Running " << title << "... " << std::flush;
    /* --Erwartetes Ergebnis? */
    if (f == expect)
        std::cout << "ok... " << f + " == " + expect<< std::endl;
    else
    {
        std::cout << "failed! expected value is "
                  << expect << " got " << f << "." << std::endl;
        retvalue=false;
    }
    return retvalue;
}

/* --Testfaelle. */

bool test_add(){
    bool test = true;
    //Test 1
    const Fraction a(1,2);
    if (!eval("Test 0-1, Addition", a.add(Fraction(1,4)), Fraction(3,4))) {test = false;}
    //Test 2
    if (!eval("Test 0-2, Addition", Fraction(5,6).add(Fraction(1,1)), Fraction(11,6))) {test = false;}
    return test;
}

bool test_sub(){
    bool test=true;
    //Test 1
    if (!eval("Test 1-1, Subtraction", Fraction(1,2).sub(Fraction(1,4)), Fraction(1,4))) {test=false;}
    //Test 2
    if (!eval("Test 1-2, Subtraction", Fraction(5,6).sub(Fraction(1,1)), Fraction(-1,6))){test=false;}
    return test;
}

bool test_equal(){
    bool test=true;
    //Test 1
    if (!eval("Test 2-1, Equal", Fraction(1,2).equals(Fraction(2,4)), true)){test=false;}
    //Test 2
    if (!eval("Test 2-2, Equal", Fraction(5,6).equals(Fraction(15,18)), true)){test=false;}
    return test;
}

bool test_reciprocal(){
    bool test=true;
    //Test 1
    if (!eval("Test 3-1, Reciprocal", Fraction(1,2).reciprocal(), Fraction(2,1))){test=false;}
    //Test 2
    if (!eval("Test 3-2 - Reciprocal", Fraction(5,6).reciprocal(), Fraction(6,5))){test=false;}
    return test;
}

bool test_mult(){
    bool test=true;
    //Test 1
    if (!eval("Test 4-1, Multiplication", Fraction(1,2).mult(Fraction(1,2)), Fraction(1,4))){test=false;}
    //Test 2
    if (!eval("Test 4-2, Multiplication", Fraction(5,6).mult(Fraction(1,2)), Fraction(5,12))){test=false;}
    //Test SONDER - Große Zahl
    if (!eval("Test 4-3, Mult with big numbers", Fraction(0x4000'0000,1).mult(Fraction(5,8)), Fraction(0x2800'0000,1))){test=false;}
    return test;
}

bool test_div(){
    bool test=true;
    //Test 1
    if (!eval("Test 5-1, Division", Fraction(1,2).div(Fraction(1,2)), Fraction(1,1))){test=false;}
    //Test 2
    if (!eval("Test 5-2, Division", Fraction(5,6).div(Fraction(1,2)), Fraction(5,3))){test=false;}
    return test;
}

bool test_pow(){
    bool test=true;
    //Test 1
    if (!eval("Test 6-1, Power", Fraction(1,2).pow(2), Fraction(1,4))){test=false;}
    //Test 2
    if (!eval("Test 6-2, Power", Fraction(1,2).pow(5), Fraction(1,32))){test=false;}
    //Test 3
    if (!eval("Test 6-3, Power 0", Fraction(1,2).pow(0),Fraction(1,1))){test=false;}
    return test;
}

bool test_str(){
    bool test=true;
    //Test 1
    if(!str_eval("Test 7-1, String", Fraction(6,2).toString(), "3")){test=false;}
    //Test 2
    if(!str_eval("Test 7-2, String", Fraction(-3,2).toString(), "-1 1/2")){test=false;}
    return test;
}

int main()
{
    std::cout << "Calculation with Fractions...\n\n";

    Fraction third(1,3);
    Fraction quarter= {1,4};

    Fraction sum=third.add(quarter);

    std::cout << third.toString() << '+' << quarter.toString() << '=' << sum.toString() << std::endl;

    std::cout << "\n===============\nRunning Tests:\n\n";

    /* --Tests. */
    unsigned errors=0, oks=0;
    if (test_add()) {oks++;}
    else {errors++;}
    if (test_sub()) {oks++;}
    else {errors++;}
    if (test_equal()) {oks++;}
    else {errors++;}
    if (test_reciprocal()) {oks++;}
    else {errors++;}
    if (test_mult()) {oks++;}
    else {errors++;}
    if (test_div()) {oks++;}
    else {errors++;}
    if (test_pow()) {oks++;}
    else {errors++;}
    if (test_str()) {oks++;}
    else {errors++;}

    std::cout << "Number of test cases "
              << errors+oks << " with "
              << errors << " failures." << std::endl;

    return 0;
}
