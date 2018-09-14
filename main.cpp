#include <iostream>
#include "AssignmentOne.cpp"

using namespace std;

string input;
string newFileName;

int main(int argc, char ** argv)
{
    if(argc > 1)
    {
      string fileName = argv[1];

      ifstream doesFileExist(fileName);

      if(doesFileExist.good()){
        AssignmentOne a;
        a.meanOfLetters(fileName);
        a.variance(fileName);
        a.stdDev(fileName);
        a.probabilityNuc(fileName);
        a.probabilityBigram(fileName);
        a.writeToNewFile(fileName);
        a.randomDNA(fileName);

        cout << "Would you like to test another file? Enter 'yes' or 'no' in all lowercase." << '\n';
        cin >> input;

        if (input == "yes")
        {
          AssignmentOne b;

          string newFileName;
          std::cout << "Enter a file name." << '\n';
          cin >> newFileName;

          ifstream checkFile(newFileName);

          if(checkFile.good())
          {
            b.meanOfLetters(newFileName);
            b.variance(newFileName);
            b.stdDev(newFileName);
            b.probabilityNuc(newFileName);
            b.probabilityBigram(newFileName);
            b.writeToNewFile(newFileName);
            b.randomDNA(newFileName);
          }else{
            std::cout << "file doesnt exist try again" << '\n';
          }

        }
        if (input == "no")
        {
          std::cout << "Thank you. The program will now exit. Have a nice day!" << endl;
        }

        if (input != "yes" || input != "no")
        {
          std::cout << "Input not recognized. Please enter 'yes' or 'no' in all lowercase" << '\n';
          cin >> newFileName;
        }

      }else{
        std::cout << "file does not exist" << '\n';
      }
    }

  return 0;
}
