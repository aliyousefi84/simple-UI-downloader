#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string>
#include <QString>

QString read_file (const char* path);

void write_file (char* filename,char* data , size_t size);

#endif