#include "mainwindow.hpp"

MainWindow::MainWindow (QMainWindow* parent) : QMainWindow () {
    setWindowTitle ("Fast Download Manager");
    resize (800,600);
    create_table ();
    create_menu ();
    create_toolbar ();
    create_table ();
    handle_download_menu_clicked ();
    handle_download_toolbar_clicked ();
};

void MainWindow::create_table () {
    model = new QStandardItemModel (20,5);
    List = {"FileName" , "Size" , "State" , "Date" , "Description"};
    model->setHorizontalHeaderLabels (List);

    table_view = new QTableView ();
    table_view->setModel (model);

    this->setCentralWidget (table_view);
}

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
    tool_delete_action = new QAction ("&Delete" , this);
    tool_delete_all_action = new QAction ("&DeleteAll" , this);

    toolbar->addAction (tool_download_action);
    toolbar->addSeparator ();
    toolbar->addAction (tool_delete_action);
    toolbar->addSeparator ();
    toolbar->addAction (tool_delete_all_action);
    
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

/*
void MyWidget::handle_click () {
    manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl(line->text()));
    reply = manager->get(request);

    connect (reply,&QNetworkReply::readyRead,this,&MyWidget::handle_download);
};

void MyWidget::handle_download () {
    QFile* file = new QFile (parse_url());
    
    file->open(QIODevice::WriteOnly);
    
    file->write(reply->readAll());
};

QString MyWidget::parse_url() {
    QString text = line->text();
    
    int lastindex = text.lastIndexOf('/');
    QString lastword = text.mid(lastindex + 1);
    QString dir = "/home/ali/Downloads";
    QString path = QDir(dir).filePath(lastword);
    
    return path;
};
*/