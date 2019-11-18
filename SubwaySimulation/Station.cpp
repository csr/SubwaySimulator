//============================================================================
// Name        : Station.cpp
// Author      : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Version     :
// Copyright   : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Description : This class is the blueprint for the Station object.
//============================================================================

#include <iostream>
#include "Station.h"
#include "DesignByContract.h"

using namespace std;

Station::Station(string name, string next, string previous, int track) {
  _initCheck = this;
  setName(name);
  setNext(next);
  setPrevious(previous);
  setTrack(track);
  ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
}

bool Station::properlyInitialized() {
  return _initCheck == this;
}

string Station::getName() {
  REQUIRE(this->properlyInitialized(), "Station wasn't initialized when calling getName");
  ENSURE(validStringAttribute(_name), "Name of station not valid");
  return _name;
}

string Station::getNext() {
  REQUIRE(this->properlyInitialized(), "Station wasn't initialized when calling getNext");
  ENSURE(validStringAttribute(_next), "Next of station not valid");
  return _next;
}

string Station::getPrevious() {
  REQUIRE(this->properlyInitialized(), "Station wasn't initialized when calling getPrevious");
  ENSURE(validStringAttribute(_previous), "Previous of station not valid");
  return _previous;
}

int Station::getTrack() {
  REQUIRE(this->properlyInitialized(), "Station wasn't initialized when calling getTrack");
  ENSURE(validIntegerAttribute(_track), "Track of station not valid");
  return _track;
}

void Station::setName(string name) {
  REQUIRE(this->properlyInitialized(), "Station wasn't initialized when calling setName");
  _name = name;
  ENSURE(validStringAttribute(_name), "Station name can't be empty");
}

void Station::setNext(string next) {
  REQUIRE(this->properlyInitialized(), "Station wasn't initialized when calling setNext");
  _next = next;
  ENSURE(validStringAttribute(_next), "Next station name can't be empty");
}

void Station::setPrevious(string previous) {
  REQUIRE(this->properlyInitialized(), "Station wasn't initialized when calling setPrevious");
  _previous = previous;
  ENSURE(validStringAttribute(_previous), "Previous station name can't be empty");
}

void Station::setTrack(int track) {
  REQUIRE(this->properlyInitialized(), "Station wasn't initialized when calling setTrack");
  _track = track;
  ENSURE(validIntegerAttribute(track), "Station track number can't be negative");
}