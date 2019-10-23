//============================================================================
// Name        : Subway.cpp
// Author      : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Version     :
// Copyright   : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Description : Subway simulation in C++
//============================================================================

#include <iostream>
#include "tinyxml.h"
#include "Station.h"
#include "Tram.h"

using std::string;

void parseXMLFile() {
  TiXmlDocument doc;
  if (!doc.LoadFile ("testInput/example.xml")) {
    std :: cerr << doc.ErrorDesc () << std::endl;
  } else {
    std::cout << "Ok, file found!" << std::endl;
  }

  TiXmlElement * root = doc.FirstChildElement (); if (root == NULL) {
    std::cerr << "Failed to load file: No root element." << std::endl;
    doc.Clear();
  }

  for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
    string elemName = elem->Value();
    std::cout << elemName << std::endl;
  }

  // This is just to test initializing trams and stations
  Station *firstStation = new Station;
  firstStation->name = "A";

}

int main() {
    parseXMLFile();
    return 0;
}