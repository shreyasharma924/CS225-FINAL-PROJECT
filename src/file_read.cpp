#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include "Graph.h"
#include "file_read.h"
using std::list;
using std::vector;
using std::string;

std::string file_to_string(const std::string& filename){
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}
