//============================================================================
// Name        : SubwaySimulationInputTests.cpp
// Author      : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Version     :
// Copyright   : Cesare De Cal, Marco Natali, Veronica Orsanigo
// Description : Subway simulation in C++
//============================================================================

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

#include "Subway.h"
#include "SubwaySimulationUtils.h"
#include "SubwaySimulationImporter.h"

class SubwaySimulationInputTests: public ::testing::Test {
 protected:
  friend class Subway;

  virtual void SetUp() {
  }

  virtual void TearDown() {
  }

  Subway subway_;
};

TEST_F(SubwaySimulationInputTests, InputIllegalSimulations) {
  ASSERT_TRUE(DirectoryExists("testInput"));

  ofstream myfile;
  SuccessEnum importResult;
  int fileCounter = 1;
  string fileName = "testInput/illegalSubway" + ToString(fileCounter) + ".xml";
  string errorfileName;

  while (FileExists (fileName)) {
    myfile.open("testInput/zzzError.txt");
    importResult = SubwaySimulationImporter::importSubway(fileName.c_str(), myfile, subway_);
    myfile.close();
    EXPECT_TRUE(importResult == ImportAborted);
    errorfileName = "testInput/illegalSubway" + ToString(fileCounter) + ".txt";
    EXPECT_TRUE(FileCompare("testInput/zzzError.txt", errorfileName));

    fileCounter = fileCounter + 1;
    fileName = "testInput/illegalSubway" + ToString(fileCounter) + ".xml";
  };
  EXPECT_TRUE(fileCounter == 7);
}

TEST_F(SubwaySimulationInputTests, InputXMLSyntaxErrors) {
  ASSERT_TRUE(DirectoryExists("testInput"));

  ofstream myfile;
  SuccessEnum importResult;
  int fileCounter = 1;
  string fileName = "testInput/xmlsyntaxerror" + ToString(fileCounter) + ".xml";
  string errorfileName;

  while (FileExists(fileName)) {
    myfile.open( "testInput/zzzError.txt");

    importResult = SubwaySimulationImporter::importSubway(fileName.c_str(), myfile, subway_);
    myfile.close();
    EXPECT_TRUE(importResult == ImportAborted);
    errorfileName = "testInput/xmlsyntaxerror" + ToString(fileCounter) + ".txt";
    EXPECT_TRUE(FileCompare("testInput/zzzError.txt", errorfileName));

    fileCounter = fileCounter + 1;
    fileName = "testInput/xmlsyntaxerror" + ToString(fileCounter) + ".xml";
  };
  EXPECT_TRUE(fileCounter == 6);
}

TEST_F(SubwaySimulationInputTests, InputLegalSubways) {
  ASSERT_TRUE(DirectoryExists("testInput"));

  ofstream myfile;
  SuccessEnum importResult;
  int fileCounter = 1;
  string fileName = "testInput/legalSubway" + ToString(fileCounter) + ".xml";

  while (FileExists (fileName)) {
    myfile.open("testInput/zzzError.txt");
    importResult = SubwaySimulationImporter::importSubway(fileName.c_str(), myfile, subway_);
    myfile.close();
    EXPECT_TRUE((importResult == Success));
    EXPECT_TRUE(FileIsEmpty("testInput/zzzError.txt"));

    fileCounter = fileCounter + 1;
    fileName = "testInput/legalSubway" + ToString(fileCounter) + ".xml";
  };
  EXPECT_TRUE(fileCounter == 4);
}
