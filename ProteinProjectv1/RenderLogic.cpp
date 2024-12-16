#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "AllHeader.h"
using namespace std;

void SelectLines() {
    ifstream inputFile("Coordinates.txt");
    string line;
    int lineNum = 0;
    string prevLine;

    while (getline(inputFile, line)) {
        lineNum++;

        if (!prevLine.empty()) {
            stringstream ssPrev(prevLine), ssCurr(line);
            double num1Prev, num2Prev, num3Prev;
            double num1Curr, num2Curr, num3Curr;

            ssPrev >> num1Prev >> num2Prev >> num3Prev;
            ssCurr >> num1Curr >> num2Curr >> num3Curr;

			renderLine(num1Prev, num2Prev, num3Prev, num1Curr, num2Curr, num3Curr);

        }
        prevLine = line;
    }
    inputFile.close();
}