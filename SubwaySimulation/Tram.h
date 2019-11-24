//============================================================================
// Name        : Tram.h
// Author      : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Version     :
// Copyright   : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Description : This file holds the header for the Tram class.
//============================================================================

#ifndef UNTITLED_TRAM_H
#define UNTITLED_TRAM_H
#include <string>
#include "Station.h"

using namespace std;

enum TramType {Albatross, PCC};

class Tram {
 public:

/**
 Constructs a Tram class with line, capacity, speed, and start Station name.
 @note ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
 @note ENSURE(line == getLine(), "Line wasn't set correctly in constructor");
 @note ENSURE(capacity == getCapacity(), "Capacity wasn't set correctly in constructor");
 @note ENSURE(speed = getSpeed(), "Speed wasn't set correctly in constructor");
 @note ENSURE(startStation = getStartStationName(), "Start station wasn't set correctly in constructor");
 @param line Line of the Tram.
 @param next Capacity of the Tram.
 @param speed Speed of the Tram.
 @param startStation Start Station of the Tram.
 @returns An instance of Tram.
*/
  Tram(int line, TramType type, string startStation);

  bool properlyInitialized();
/**
  Getter for the line of the Tram.
  @note REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling getLine");
  @returns Line of the Tram.
*/
  int getLine();

/**
  Getter for the capacity of the Tram.
  @note REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling getCapacity");
  @returns Capacity of the Tram.
*/
  int getCapacity();

/**
  Getter for the speed of the Tram.
  @note REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling getSpeed");
  @returns Speed of the Tram.
*/
  int getSpeed();

/**
  Getter for the start Station of the Tram.
  @note REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling getStartStation");
  @returns Start Station of the Tram.
*/
  Station* getStartStation();

/**
  Getter for the current Station name of the Tram.
  @note REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling getCurrentStation");
  @returns Current Station the tram is at.
*/
  Station* getCurrentStation();

  string getStartStationName();

  TramType getType();

/**
  Setter for the line of the Tram.
  @note REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling setLine");
  @note ENSURE(ValidIntegerAttribute(getLine()), "Tram line can't be negative");
  @note ENSURE(line == getLine(), "Tram line was not set correctly");
  @param line Line of the Tram.
*/
  void setLine(int line);

/**
  Setter for the start Station name.
  @note REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling setStartStation");
  @note ENSURE(ValidStringAttribute(getStartStation()), "Tram start station must be valid");
  @note ENSURE(startStation == getStartStation(), "Tram start station was not set correctly");
  @param startStaton Start Station of the Tram.
*/
  void setStartStation(Station *station);

/**
  Setter for the current start Station name.
  @note REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling setCurrentStation");
  @note ENSURE(ValidStringAttribute(getCurrentStation()), "Tram current station must be valid");
  @note ENSURE(station == getCurrentStation(), "Tram current station was not set correctly");
  @param station Start Station.
*/
  void setCurrentStation(Station *station);

/**
  Setter for the start Station name.
  REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling getStartStation");
  _startStationName = startStation;
  ENSURE(startStation == getStartStationName(), "Tram start station name was not set correctly");
*/
  void setStartStationName(string startStation);

/**
  Setter for tram type.
  REQUIRE(this->properlyInitialized(), "Tram wasn't initialized when calling setType");
  ENSURE(type == getType(), "Tram type was not set correctly");
*/
  void setType(TramType type);

  void move();

 private:
  Tram * _initCheck;
  int _line;
  Station* _startStation;
  Station* _currentStation;
  string _startStationName;
  string _currentStationName;
  TramType _type;
};

#endif //UNTITLED_TRAM_H
