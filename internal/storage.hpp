#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "datamodel.hpp"
#include "jsonhandler.hpp"
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <vector>

#define DB_PATH "/var/lib/Downloader/db.json"

void store_data (vector<DataModel*> model_list);

vector<DataModel*> load_data ();

#endif