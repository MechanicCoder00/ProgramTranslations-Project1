#include <iostream>
#include <fstream>

using namespace std;

#include "token.h"
#include "scanner.h"
#include "testscanner.h"

/*
Author: Scott Tabaka
CMPSCI 4280 Project1

Purpose: This program takes 0 or 1 command line arguments and then tests the scanner function with a testscanner function.
    With 0 arguments the program will prompt the user to input strings manually followed by <ctrl+d> and insert them into
    an output file named temp.fs19.  With 1 command line argument the program will use the given file for the scanner.
    The program then uses either the temp.fs19 or the user file *.fs19 and passes it into the testscanner function.  The
    testscanner function will then send the file input into the scanner function and will print the tokens as they are
    returned.
*/


string appendFileExtension(string s)             //adds .fs19 file extension if it does not exist
{
    if(s.length() > 5)
    {
        if (s.substr(s.length() - 5, 5).compare(".fs19") != 0)
        {
            s.append(".fs19");
        }
    }else{
        s.append(".fs19");
    }
    return s;
}

int main(int argc, char *argv[])
{
    if(argc > 2)                                //checks for correct amount of arguments
    {
        cout << "Usage Error: P1 <filename>" << endl;
        exit(1);
    }

    string inputFilename;

    if(argc == 1)       //if there is no command line argument given
    {
        inputFilename = "temp.fs19";
        ofstream output(inputFilename);

        cout << "Please enter valid inputs and press <ctrl+d> when finished\n";
        output << string(istreambuf_iterator<char>(cin), {});           //inputs user input into the output file
        cout << endl;

        output.close();
    }
    else if (argc == 2)             //if command line argument is given
    {
        inputFilename = argv[1];        //use the file name provided by user
        inputFilename = appendFileExtension(inputFilename); //append .fs19 if not present
    }
    else
    {
        cout << "Usage Error: P1 <filename>" << endl;		//display for proper usage
        exit(1);
    }


    ifstream input(inputFilename);                  //opens input file stream
    if(input)
    {
        testscanner(input);
    }else{
        cout << "Error: Cannot open file -- " << inputFilename << endl;
    }

    input.close();
    return 0;
}