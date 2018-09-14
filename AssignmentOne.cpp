#include <iostream>
#include <fstream>
#include "AssignmentOne.h"
#include <cmath>
#include <cstdlib>

using namespace std;

double percA = 0;
double percC = 0;
double percG = 0;
double percT = 0;

double percAA = 0;
double percAC = 0;
double percAG = 0;
double percAT = 0;

double percCA = 0;
double percCC = 0;
double percCG = 0;
double percCT = 0;

double percGA = 0;
double percGC = 0;
double percGG = 0;
double percGT = 0;

double percTA = 0;
double percTC = 0;
double percTG = 0;
double percTT = 0;



AssignmentOne::AssignmentOne()
{

}

AssignmentOne::~AssignmentOne()
{

}

//this method takes the sum of the letters
int AssignmentOne::sumOfLetters(int lineLength, int sum)
{
  sum += lineLength;
  return sum;
}


//file reader
//code found at http://www.cplusplus.com/doc/tutorial/files/
//this method outputs the mean of how many character per line
double AssignmentOne::meanOfLetters(string nameOfFile)
{
  int numberOfLines = 0;
  double sum = 0;

  ifstream fileReader(nameOfFile);

  if (fileReader.is_open())
    {
      string fileLine;

      while (getline(fileReader, fileLine))
      {
          sum = AssignmentOne::sumOfLetters(fileLine.length(), sum);
          numberOfLines++;
      }
      double mean = (sum/numberOfLines);
      return mean;
    }
    fileReader.close();

  }

//this method takes the variance
//code for power: http://www.cplusplus.com/reference/cmath/pow/
double AssignmentOne::variance(string nameOfFile)
{
  double getMean = AssignmentOne::meanOfLetters(nameOfFile);
  double variance = 0;

  ifstream fileReader(nameOfFile);

  if (fileReader.is_open())
    {
      string fileLine;

      while (getline(fileReader, fileLine))
      {

        double changeNum = (getMean - fileLine.length());
        variance += pow(changeNum, 2);

      }
      fileReader.close();
    }
    return variance;

}

//this gets the std deviation
double AssignmentOne::stdDev(string nameOfFile)
{
    double variance = AssignmentOne::variance(nameOfFile);
    double deviation = sqrt(variance);
    return deviation;
}

//this method figures out the probability of a's c's g's and t's
//I collaborated ryan kasaab on how to do this
double AssignmentOne::probabilityNuc(string nameOfFile)
{
  double a = 0;
  double c = 0;
  double g = 0;
  double t = 0;

  double probA = 0;
  double probC = 0;
  double probG = 0;
  double probT = 0;

  double counter = 0;
  string fileLine;

  ifstream fileReader(nameOfFile);

  if (fileReader.is_open())
    {

      while (getline(fileReader, fileLine))
      {
        for (int i = 0; i < fileLine.length(); ++i)
        {
          fileLine[i] = tolower(fileLine[i]);
        }
        for (int i = 0; i < fileLine.length(); i++)
          {
          if (fileLine[i] == 'a')
          {
            a++;
            counter++;
          }
          if (fileLine[i] == 'c')
          {
            c++;
            counter++;
          }
          if (fileLine[i] == 'g')
          {
            g++;
            counter++;

          }
          if (fileLine[i] == 't')
          {
            t++;
            counter++;

          }
        }
      }
    }
    fileReader.close();

    probA = (a/counter) * 100;
    probC = (c/counter) * 100;
    probG = (g/counter) * 100;
    probT = (t/counter) * 100;

    percA += probA;
    percC += probC;
    percG += probG;
    percT += probT;

    return probA;
    return probC;
    return probG;
    return probT;
}

//this gets the probability of bigrams
//I collaborated ryan kasaab on how to do this
double AssignmentOne::probabilityBigram(string nameOfFile)
{
  double aa = 0;
  double ac = 0;
  double ag = 0;
  double at = 0;

  double cc = 0;
  double cg = 0;
  double ct = 0;
  double ca = 0;

  double gg = 0;
  double gt = 0;
  double gc = 0;
  double ga = 0;

  double tt = 0;
  double ta = 0;
  double tc = 0;
  double tg = 0;

  double probAA = 0;
  double probAC = 0;
  double probAG = 0;
  double probAT = 0;

  double probCC = 0;
  double probCG = 0;
  double probCT = 0;
  double probCA = 0;

  double probGG = 0;
  double probGT = 0;
  double probGC = 0;
  double probGA = 0;

  double probTT = 0;
  double probTA = 0;
  double probTC = 0;
  double probTG = 0;


  double bigramCounter = 0;

  ifstream fileReader(nameOfFile);

  if (fileReader.is_open())
    {
      string fileLine;
      while (getline(fileReader, fileLine))
      {
        for (int i = 0; i < fileLine.length(); ++i)
        {
          fileLine[i] = tolower(fileLine[i]);
        }

        double counter = 0;
        while (counter < fileLine.length())
        {
          if (fileLine[counter] == 'a' && fileLine[counter+1] == 'a')
          {
            aa++;
            bigramCounter++;
          }
          if (fileLine[counter] == 'a' && fileLine[counter+1] == 'c')
          {
            ac++;
            bigramCounter++;
          }
          if (fileLine[counter] == 'a' && fileLine[counter+1] == 'g')
          {
            ag++;
            bigramCounter++;
          }
          if (fileLine[counter] == 'a' && fileLine[counter+1] == 't')
          {
            at++;
            bigramCounter++;
          }


          if (fileLine[counter] == 'c' && fileLine[counter+1] == 'c')
          {
            cc++;
            bigramCounter++;
          }
          if (fileLine[counter] == 'c' && fileLine[counter+1] == 'g')
          {
            cg++;
            bigramCounter++;
          }
          if (fileLine[counter] == 'c' && fileLine[counter+1] == 't')
          {
            ct++;
            bigramCounter++;
          }
          if (fileLine[counter] == 'c' && fileLine[counter+1] == 'a')
          {
            ca++;
            bigramCounter++;
          }



          if (fileLine[counter] == 'g' && fileLine[counter+1] == 'g')
          {
            gg++;
            bigramCounter++;
          }
          if (fileLine[counter] == 'g' && fileLine[counter+1] == 't')
          {
            gt++;
            bigramCounter++;
          }
          if (fileLine[counter] == 'g' && fileLine[counter+1] == 'c')
          {
            gc++;
            bigramCounter++;
          }
          if (fileLine[counter] == 'g' && fileLine[counter+1] == 'a')
          {
            ga++;
            bigramCounter++;
          }




          if (fileLine[counter] == 't' && fileLine[counter+1] == 't')
          {
            tt++;
            bigramCounter++;
          }
          if (fileLine[counter] == 't' && fileLine[counter+1] == 'c')
          {
            tc++;
            bigramCounter++;
          }
          if (fileLine[counter] == 't' && fileLine[counter+1] == 'g')
          {
            tg++;
            bigramCounter++;
          }
          if (fileLine[counter] == 't' && fileLine[counter+1] == 'a')
          {
            tt++;
            bigramCounter++;
          }
          counter += 2;
        }
      }
    }

    fileReader.close();

    probAA = aa/bigramCounter * 100;
    probAC = ac/bigramCounter * 100;
    probAG = ag/bigramCounter * 100;
    probAT = at/bigramCounter * 100;

    probCC = cc/bigramCounter * 100;
    probCG = cg/bigramCounter * 100;
    probCT = ct/bigramCounter * 100;
    probCA = ca/bigramCounter * 100;

    probGG = gg/bigramCounter * 100;
    probGT = gt/bigramCounter * 100;
    probGC = gc/bigramCounter * 100;
    probGA = ga/bigramCounter * 100;

    probTT = tt/bigramCounter * 100;
    probTA = ta/bigramCounter * 100;
    probTC = tc/bigramCounter * 100;
    probTG = tg/bigramCounter * 100;

    percAA += probAA;
    percAC += probAC;
    percAG += probAG;
    percAT += probAT;

    percCA += probCA;
    percCC += probCC;
    percCG += probCG;
    percCT += probCT;

    percGA += probGA;
    percGC += probGC;
    percGG += probGG;
    percGT += probGT;

    percTA += probTA;
    percTC += probTC;
    percTG += probTG;
    percTT += probTT;

    return probAA;
    return probAC;
    return probAG;
    return probAT;

    return probCC;
    return probCG;
    return probCT;
    return probCA;

    return probGG;
    return probGT;
    return probGA;
    return probGC;

    return probTT;
    return probTA;
    return probTC;
    return probTG;

}


//this method writes to a new file
//corey McCrea helped me with appending to a text
//I collaborated ryan kasaab on how to get the values from each method in order
          //to write them to the txt file
void AssignmentOne::writeToNewFile(string nameOfFile)
{
  int sum = 0;

  ifstream readerFile(nameOfFile);
  ofstream fileWriter;
  fileWriter.open("ademirvila.txt", ios_base::app);

  fileWriter << "Ademir Vila" << endl;
  fileWriter << "Student ID: 2299217" << endl;
  fileWriter << "Section 1" << endl;
  fileWriter << " " << endl;


  if (readerFile.is_open())
    {
      string fileLine;

      while (getline(readerFile, fileLine))
      {
          sum = AssignmentOne::sumOfLetters(fileLine.length(), sum);

      }
    }
    readerFile.close();

  fileWriter << "Total letters: " << sum << endl;

  double printMean = AssignmentOne::meanOfLetters(nameOfFile);
  fileWriter << "Mean of letters per line: " << printMean << endl;

  double printVariance = AssignmentOne::variance(nameOfFile);
  fileWriter << "Variance: " << printVariance << endl;

  double printStdDev = AssignmentOne::variance(nameOfFile);
  fileWriter << "Standard Deviation: " << sqrt(printStdDev) << endl;

  fileWriter << "Probability of A: " << percA << " percent" << endl;
  fileWriter << "Probability of C: " << percC << " percent" << endl;
  fileWriter << "Probability of G: " << percG << " percent" << endl;
  fileWriter << "Probability of T: " << percT << " percent" << endl;

  fileWriter << "Probability of AA: " << percAA << " percent" << endl;
  fileWriter << "Probability of AC: " << percAC << " percent" << endl;
  fileWriter << "Probability of AG: " << percAG << " percent" << endl;
  fileWriter << "Probability of AT: " << percAT << " percent" << endl;

  fileWriter << "Probability of CA: " << percCA << " percent" << endl;
  fileWriter << "Probability of CC: " << percCC << " percent" << endl;
  fileWriter << "Probability of CG: " << percCG << " percent" << endl;
  fileWriter << "Probability of CT: " << percCT << " percent" << endl;

  fileWriter << "Probability of GA: " << percGA << " percent" << endl;
  fileWriter << "Probability of GA: " << percGC << " percent" << endl;
  fileWriter << "Probability of GA: " << percGG << " percent" << endl;
  fileWriter << "Probability of GA: " << percGT << " percent" << endl;

  fileWriter << "Probability of TA: " << percTA << " percent" << endl;
  fileWriter << "Probability of TC: " << percTC << " percent" << endl;
  fileWriter << "Probability of TG: " << percTG << " percent" << endl;
  fileWriter << "Probability of TT: " << percTT << " percent" << endl;

  fileWriter.close();

}

//reference: https://www.daniweb.com/programming/software-development/threads/1769/c-random-numbers
void AssignmentOne::randomDNA(string nameOfFile)
{
  ofstream writeFile;
  writeFile.open("ademirvila.txt", ios_base::app);

  double mean = AssignmentOne::meanOfLetters(nameOfFile);
  double dev = AssignmentOne::stdDev(nameOfFile);

  int x = 0;

  while(x < 1000)
  {
    double a = ((double) rand() / RAND_MAX);
    double b = ((double) rand() / RAND_MAX);
    int c = ((rand() % 4) + 1);

    double natLog = sqrt(-2 * log(a));
    double cosine = cos(2 * M_PI * b);

    double cEquation = (natLog * cosine);

    int D = ((dev * cEquation) + mean);

    string lineCreation;

    if (D != 0)
    for(int x = 0; x < D; x++)
    {
      if(c == 1)
      {
        lineCreation += 'A';
      }
      if(c == 2)
      {
        lineCreation += 'C';
      }
      if(c == 3)
      {
        lineCreation += 'G';
      }
      if(c == 4)
      {
        lineCreation += 'T';
      }
    }
    if (lineCreation != "")
    {
      writeFile << lineCreation << endl;
      x++;
    }
  }
}

// if(str[i] = 'A')
