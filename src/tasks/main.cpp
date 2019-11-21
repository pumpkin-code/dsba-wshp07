/*******************************************************************************
 *
 *  Workshop 7
 *
 * 1) Define an alias VecNames for the std::vector<std::string> datatype using
 * the typedef keyword.
 *
 * 2) Create a function called toCountSurvived that obtains an input stream
 * object (given by reference) istream& (input.csv), reads the whole file line
 * by line and get a surname ("Braund; Mr. Owen Harris" will be just "Braund")
 * of survived person from /data/input.csv (Survived column). Function returns
 * VecNames data type -- vector of survived surnames.
 *
 * 3) Create a method printVec(const VecNames& aliveNames).
 * The method prints the content of the given vector out to the standard output
 * with elements and its enumeration
 *      1) Name_1
 *      2) Name_2
 *      ...
 *      N) Name_n
 *
 * 4) Create a method named genThreeDigitNumber(const int& random_state).
 * The method return random three digit number as std::string.
 * Use:
 *      std::mt19937 gen(time(nullptr));
 *      std::uniform_int_distribution<int> distr(0,9);
 *      int rNum = distr(gen); // random number
 *
 * 5) Create new vector newVec as VecNames and fill it by random numbers.
 * newVec size should be the same as obtained from toCountSurvived
 ******************************************************************************/

#include <iostream>
// TODO: include all necessary headers


// TODO: implement all necessary methods

int main ()
{
    // TODO: put all the stuff together
    return 0;
}
