#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cassert>
#include <fstream>
#include <sstream>
#include <fenv.h>
#include <signal.h>
using std::list;
using std::vector;
using std::string;

/* Reads the txt file and converts it into string
*
*
*/
std::string file_to_string(const std::string& filename);
