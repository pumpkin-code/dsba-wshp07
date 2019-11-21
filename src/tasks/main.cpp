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

// Solution by K. Rudakov

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>

// type aliases definition
typedef std::vector<std::string> VecNames;

// function prototypes definition
VecNames toCountSurvived(std::istream& inputFile);
void printVec(const VecNames& aliveNames);
std::string genThreeDigitNumber(int randomState);


int main ()
{
    const std::string INP_FILE_NAME = "/Users/kirill/Documents/Кирилл Рудаков/Учеба/Преподавание/C++/untitled1/tasks/input.csv";
    std::ifstream inputFile;
    inputFile.open(INP_FILE_NAME);

    VecNames aliveNames = toCountSurvived(inputFile);
    printVec(aliveNames);


    VecNames newVec;

    int size = aliveNames.size();

    while (size > 0)
    {
        newVec.push_back(genThreeDigitNumber(size));
        --size;
    }

    printVec(newVec);
}

//std::vector<std::string> toCountSurvived(std::istream& input_file) // also ok
VecNames toCountSurvived(std::istream& inputFile)
{
    std::string line;
    VecNames aliveNames;

    while (!inputFile.eof() && inputFile.good())
    {
        std::getline(inputFile, line);
        std::stringstream ss(line);
        std::string token;

        int tokenI = 0;
        bool isSurvived = false;
        while (!ss.eof () && ss.good())
        {
            std::getline (ss, token, ',');

            if (tokenI == 1)                            // process survived attribute
            {
                short survived;
                std::stringstream t(token);
                t >> survived;
                if (survived == 1)
                    isSurvived = true;
            }

            if (tokenI == 3 && isSurvived)              // process full name
            {
                std::string surname;
                std::stringstream surStream(token);
                std::getline(surStream, surname, ';');  // need only surname
                aliveNames.push_back(surname);
            }
            ++tokenI;
        }
    }

    return aliveNames;
}


void printVec(const VecNames& aliveNames)
{
    int i = 1;
    for (std::string name : aliveNames)
        std::cout << i++ << ") " << name<<'\n';
}


std::string genThreeDigitNumber(int randomState)
{
    std::mt19937 gen;
    gen.seed(randomState);
    std::uniform_int_distribution<int> distr_0_9(0, 9);
    std::uniform_int_distribution<int> distr_1_9(1, 9);

    std::stringstream numberStream;
    for (int i = 0; i < 3; i++)
        numberStream <<  (i > 0 ? distr_0_9(gen) : distr_1_9 (gen));

    std::string number;
    std::getline(numberStream, number);

    return number;
}
