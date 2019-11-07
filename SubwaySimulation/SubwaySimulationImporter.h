//============================================================================
// Name        : SubwaySimulationImporter.h
// Author      : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Version     :
// Copyright   : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Description : Subway simulation in C++
//============================================================================

#ifndef UNTITLED_SUBWAYSIMULATIONIMPORTER_H
#define UNTITLED_SUBWAYSIMULATIONIMPORTER_H

#include <vector>
#include <map>

#include "tinyxml.h"
#include "Tram.h"
#include "Station.h"

using namespace std;

// Goals: parsing the schedule of the subway network: the different stations, how they are connected to each other,
// and the different trams.

class SubwaySimulationImporter {
 public:
  static string fetch_text(TiXmlNode *elem);
  static bool check_digit(string s, int i, bool is_ok);
  static bool check_letter(string s, int i, bool is_ok);
  static void set_values_station(string elemName, Station* station, string attributeValue);
  static bool check_digits_letters_station(string elemName, string attributeValue, Station* station);
  static void set_values_tram(string elemName, Tram* tram, string attributeValue);
  static bool check_digits_letters_tram(string elemName, string attributeValue, Tram* tram);
  int parsing();

 private:
  // These maps will contain objects parsed with the Parsing class
  map<string, Station*> stations;
  map<string, Tram*> trams;
};

#endif