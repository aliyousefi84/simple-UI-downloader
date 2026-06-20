#ifndef DATAMODEL_HPP
#define DATAMODEL_HPP
#include <string>
using namespace std;

struct DataModel
{
    public:
        string FileName;

        float Size;

        string State;

        string Date;

        string Description;

        
};

vector<DataModel*> model_list;

DataModel* init_model () {
    DataModel *model = new DataModel;
    return model;
};

#endif