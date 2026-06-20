#include "storage.hpp"


void store_data (vector<DataModel*> model_list) {
    int fd = open (DB_PATH , O_WRONLY | O_APPEND | O_CREAT);

    if (fd == -1)
    {
        std::cout << "unable to create file in the db path !!" << std::endl;
        exit(1);
    }
    std::string json_data;
    for (DataModel *d : model_list) {
        json_data = to_json (*d);
        write (fd , json_data.data() , json_data.size());
    }
    
};


vector<DataModel*> load_data () {
    
    vector<DataModel*> list = json_array (DB_PATH);

    return list;
};