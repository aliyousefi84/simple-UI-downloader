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

void write_file (char* filename,char* data , size_t size) {
    char current_dir[1024];
    getcwd (current_dir, 1024);
    chdir ("/home/$USER/Downloads");
    
    int fd = open (filename , O_CREAT | O_WRONLY);

    if (fd == -1)
    {
        std::cout << "can not open this file" << std::endl;
        exit(1);
    }

    write (fd,data,size);
    
};