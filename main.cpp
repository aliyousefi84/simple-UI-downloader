#include <QApplication>
#include "mainwindow/mainwindow.hpp"

int main (int argc , char **argv) {
    QApplication app(argc,argv);
    MyWidget window;
    window.resize(400,300);
    window.show();
    return app.exec();   
}
