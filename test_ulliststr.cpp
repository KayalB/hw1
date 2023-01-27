#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"


using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  int doNothing = 0;

  // dat.push_back("2");
  // dat.push_front("1");
  // dat.push_front("2");
  // dat.push_front("3");
  // dat.push_front("4");
  // dat.push_front("5");
  // dat.push_front("6");
  // dat.push_front("7");
  // dat.push_front("8");
  // dat.push_front("9");
  // dat.push_front("10");
  // dat.push_front("11");
  // dat.push_front("5");
  // dat.push_front("5");
  // dat.push_front("5");
  // dat.push_front("5");
  // dat.push_front("5");
  dat.push_back("0");
  dat.push_back("1");
  dat.push_back("2");
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("10");

  if(doNothing == 0){
    doNothing = 1;
  }

  // dat.push_back("6");
  // dat.push_front("7");
  // dat.push_back("8");
  // dat.push_front("9");
  // dat.push_back("10");
  // dat.push_front("11");
  // dat.push_back("12");
  // dat.push_front("13");
  // string printVal;
  // printVal = dat.get(0);
  // cout << printVal << endl;
  
  return 0;
}

