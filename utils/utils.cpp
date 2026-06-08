#include "utils.hpp"

QString read_file (const char* path) {
    struct stat st;
    stat (path , &st);

    size_t size = st.st_size;

    char buffer[size];

    int fd = open (path , O_RDONLY);
    if (fd < 0)
    {
        std::cout << "unable to read this file check permission or path" << std::endl;
    }

    read (fd , buffer , st.st_size);
    QString str = QString (buffer);
    return str;
}
