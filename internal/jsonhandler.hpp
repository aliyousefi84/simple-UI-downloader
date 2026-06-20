#ifndef JSONHANDLER_HPP
#define JSONHANDLER_HPP
#include "datamodel.hpp"
#include <jsoncpp/json/json.h>
#include <iostream>
#include <string>
#include <fstream>

static DataModel* from_json (const Json::Value& parsed_data);

string to_json (DataModel model);

vector<DataModel*> json_array (char* filepath);

void clean_up (DataModel* model);

#endif