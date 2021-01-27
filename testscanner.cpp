#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "token.h"
#include "scanner.h"
#include "testscanner.h"

/*
Author: Scott Tabaka
CMPSCI 4280 Project1
*/

void printtoken(token t)            //function to print token
{
    cout
            << setw(12) << left << tokenNames[t.tokenId]
            << setw(10) << t.tokenInstance
            << setw(3) << t.lineNum
            << endl;
}

void testscanner(ifstream& input)       //function to test scanner
{
    token t;
    t.lineNum = 1;

    while(t.tokenId != EOF_tk)
    {
        t = scanner(input,t.lineNum);
        printtoken(t);
    }
}