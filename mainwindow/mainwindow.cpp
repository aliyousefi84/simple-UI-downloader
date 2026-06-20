#include "mainwindow.hpp"

MainWindow::MainWindow (QMainWindow* parent) : QMainWindow () {
    setWindowTitle ("Fast Download Manager");
    resize (800,600);
    create_menu ();
    create_toolbar ();
    handle_download_menu_clicked ();
    handle_download_toolbar_clicked ();
};



void MainWindow::create_menu () {
    menubar = this->menuBar();
    filemenu = menubar->addMenu("&File");
    helpmenu = menubar->addMenu("&Help");

    filemenu_download_action = new QAction ("&Download",filemenu);
    filemenu_save_action = new QAction ("&Save" , filemenu);
    filemenu_save_action->setShortcut (QKeySequence::Save);
    filemenu_quit_action = new QAction ("&Quit" , filemenu);
    filemenu_quit_action->setShortcut (QKeySequence::Quit);

    helpmenu_doc_action = new QAction ("&Document" , helpmenu);
    helpmenu_doc_action->setShortcut (QKeySequence::HelpContents);

    filemenu->addAction (filemenu_download_action);
    filemenu->addAction (filemenu_save_action);
    filemenu->addSeparator ();

    helpmenu->addAction (helpmenu_doc_action);
    
    QString style = read_file("../css/menubar.css");
    menubar->setStyleSheet (style);
    
}

void MainWindow::create_toolbar () {
    toolbar = this->addToolBar ("Tools");
    tool_download_action = new QAction ("&Download" , this);
    

    toolbar->addAction (tool_download_action);
    toolbar->addSeparator ();
    
}

void MainWindow::init_download_widget () {
    download_widget = new downloadwidget;
    download_widget->show();
}

void MainWindow::handle_download_menu_clicked () {
    connect (filemenu_download_action , SIGNAL(triggered()),this,SLOT (init_download_widget()));
}

void MainWindow::handle_download_toolbar_clicked () {
    connect (tool_download_action , SIGNAL(triggered()),this,SLOT (init_download_widget()));
}


MainWindow::~MainWindow (){};
