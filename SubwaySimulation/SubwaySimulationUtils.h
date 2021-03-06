//============================================================================
// Name        : SubwaySimulationUtils.h
// Author      : Serge Demeyer
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Serge Demeyer - University of Antwerp
// Description : TicTactToe in C++, Ansi-style
//============================================================================


#ifndef SUBWAYSIMULATION__SUBWAYSIMULATIONUTILS_H_
#define SUBWAYSIMULATION__SUBWAYSIMULATIONUTILS_H_

#include <iostream>

typedef std::pair<int, int> pairInt;

bool DirectoryExists(const std::string dirname);

bool FileExists(const std::string dirname);

bool FileIsEmpty(const std::string filename);

bool FileCompare(const std::string leftFileName, const std::string rightFileName);

int GenerateRandomNumber(int a, int b);

/**
Checks if the attribute string is valid.
@returns True if the string isn't empty.
*/
bool ValidStringAttribute(std::string string);

/**
  Checks if the attribute integer is valid.
  @returns True if the value is positive.
*/
bool ValidIntegerAttribute(int value);

bool IsStringNumber(std::string string);

std::string ToString(int i);

std::string ConvertSecondsToTimeString(int input_seconds);

// Closing of the ``header guard''.
#endif