#include "jsonhandler.hpp"



string to_json (DataModel* model) {
    Json::Value root;
    root["filename"] = model->FileName;
    root["size"] = model->Size;
    root["state"] = model->State;
    root["date"] = model->Date;
    root["description"] = model->Description;

    Json::StreamWriterBuilder writer;
    string json_string = Json::writeString (writer , root);

    return json_string;
};

static DataModel* from_json (const Json::Value& parsed_data) {

    DataModel *model = init_model();    
      
    model->FileName = parsed_data["filename"].asString ();
    model->Size = parsed_data["size"].asFloat();
    model->State = parsed_data["state"].asString();
    model->Date = parsed_data["date"].asString();
    model->Description = parsed_data["description"].asString();

    return model;
};


vector<DataModel*> json_array (char* filepath) {
    std::ifstream file(filepath);
    Json::Value root;
    Json::CharReaderBuilder reader;
    string error;

    if (!Json::parseFromStream (reader , file , &root , &error))
    {
        std::cout << "error !" << error << std::endl;
        return ;
    }
    
    

    if (root.isArray())
    {
        for (const auto& item : root)
        {
            model_list.push_back (from_json(item));
        }
        
    }

    return model_list;
};

void clean_up (DataModel* model) {
    delete model;
};