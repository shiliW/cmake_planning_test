#include <iostream>
#include "process.h"
using std::cout, std::endl;

void Process::planProcess()
{
  cout << "This is planing process" << endl;
  my_map.mapInfo();
  cout << "planning success!" << endl;
}