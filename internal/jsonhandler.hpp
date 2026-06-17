#ifndef JSONHANDLER_HPP
#define JSONHANDLER_HPP
#include "datamodel.hpp"
#include <jsoncpp/json/json.h>
#include <iostream>
#include <string>
#include <fstream>

vector<DataModel> from_json (char* filepath);

string to_json (DataModel model);

#endif