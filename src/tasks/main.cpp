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
#include <fstream>
#include <sstream>
#include <vector>
#include <random>



typedef std::vector<std::string> VecNames;

VecNames toCountSurvived(std::istream& input_file);
void printVec(const VecNames& aliveNames);
std::string genThreeDigitNumber(const int& random_state);

int main ()
{
    const std::string INP_FILE_NAME = "/Users/kirill/Documents/Кирилл Рудаков/Учеба/Преподавание/C++/untitled1/tasks/input.csv";
    std::ifstream input_file;
    input_file.open(INP_FILE_NAME);

    VecNames aliveNames = toCountSurvived(input_file);
    printVec(aliveNames);


    VecNames newVec;

    int size = aliveNames.size();

    while (size > 0)
    {
        newVec.push_back(genThreeDigitNumber(size));
        size--;
    }

    printVec(newVec);
}

std::vector<std::string> toCountSurvived(std::istream& input_file)
{
    std::string line;
    VecNames aliveNames;

    while (!input_file.eof() && input_file.good ())
    {
        std::getline (input_file, line);
        std::stringstream ss(line);
        std::string token;

        int token_i = 0;
        bool isSurvived = false;
        while (!ss.eof () && ss.good ())
        {
            std::getline (ss, token,',');

            if (token_i == 1)
            {
                short survived;
                std::stringstream t(token);
                t >> survived;
                if (survived == 1)
                    isSurvived = true;
            }

            if (token_i == 3 && isSurvived)
            {
                std::string surname;
                std::stringstream surStream(token);
                std::getline(surStream, surname,';');
                aliveNames.push_back(surname);
            }

            ++token_i;
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

std::string genThreeDigitNumber(const int& random_state){
    std::mt19937 gen;
    gen.seed(random_state);
    std::uniform_int_distribution<int> distr_0_9(0,9);
    std::uniform_int_distribution<int> distr_1_9(1,9);

    std::stringstream numberStream;
    for (int i = 0; i < 3; i++)
        numberStream <<  (i > 0 ? distr_0_9(gen) : distr_1_9 (gen));

    std::string number;
    std::getline(numberStream,number);
    return number;


}
