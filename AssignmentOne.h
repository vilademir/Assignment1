#include <iostream>

using namespace std;

class AssignmentOne
{
  public:
    AssignmentOne();
    ~AssignmentOne();
    int sumOfLetters(int lineLength, int sum);
    double meanOfLetters(string nameOfFile);
    double variance(string nameOfFile);
    double stdDev(string nameOfFile);
    double probabilityNuc(string nameOfFile);
    double probabilityBigram(string nameOfFile);
    void writeToNewFile(string nameOfFile);
    void randomDNA(string newFile);

};
