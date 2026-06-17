#include "jsonhandler.hpp"

string to_json (DataModel model) {
    Json::Value root;
    root["filename"] = model.FileName;
    root["size"] = model.Size;
    root["state"] = model.State;
    root["date"] = model.Date;
    root["description"] = model.Description;

    Json::StreamWriterBuilder writer;
    string json_string = Json::writeString (writer , root);

    return json_string;
};

vector<DataModel> from_json (char* filepath) {
    Json::Value parsed_data;
    Json::CharReaderBuilder reader;
    string err;

    std::ifstream input(filepath);
    vector<DataModel> model;
    
    if (Json::parseFromStream (reader , input ,&parsed_data , &err))
    {   
        

    }

    return model;
};
