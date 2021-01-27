# ProgramTranslations-Project1

Author: Scott Tabaka
CMPSCI 4280 Project1
Purpose: This program takes 0 or 1 command line arguments and then tests the scanner function with a testscanner function.
    With 0 arguments the program will prompt the user to input strings manually followed by <ctrl+d> and insert them into
    an output file named temp.fs19.  With 1 command line argument the program will use the given file for the scanner.
    The program then uses either the temp.fs19 or the user file *.fs19 and passes it into the testscanner function.  The
    testscanner function will then send the file input into the scanner function and will print the tokens as they are
    returned.
