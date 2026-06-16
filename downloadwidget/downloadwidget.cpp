#include "downloadwidget.hpp"

downloadwidget::downloadwidget (QWidget* parent) : QWidget (parent) {
    this->resize (800,200);
    this->setWindowTitle ("Download Box");
    create_downloadbox (this);
    create_savebox (this);
    create_description (this);
    set_layout();
    handle_download_button_click ();
}

void downloadwidget::create_downloadbox (QWidget* parent) {
    download_url_label = new QLabel ("Url" , parent);

    download_url_line = new QLineEdit (parent);

    download_button = new QPushButton ("Download",parent);

    cancel_button = new QPushButton ("Cancel" , parent);
}

void downloadwidget::create_savebox (QWidget* parent) {
    save_label = new QLabel ("Save as" , parent);

    save_line = new QLineEdit (parent);
}

void downloadwidget::create_description (QWidget* parent) {
    description_label = new QLabel ("Description" , parent);

    description_line = new QLineEdit (parent);
}

void downloadwidget::set_layout () {
    Glayout = new QGridLayout;

    Glayout->addWidget (download_url_label , 0 , 0);
    Glayout->addWidget (download_url_line , 0 , 1);
    Glayout->addWidget (save_label , 1 , 0);
    Glayout->addWidget (save_line,1,1);
    Glayout->addWidget (description_label,2,0);
    Glayout->addWidget (description_line,2,1);
    
    Glayout->addWidget (download_button, 3 , 0);
    Glayout->addWidget (cancel_button , 3,1);
    

    this->setLayout(Glayout);
}

void downloadwidget::init_prog_widget () {
    progressbar_widget = new QWidget;
    progressbar_widget->resize (800,150);
    progressbar = new QProgressBar (progressbar_widget);
    progressbar->setAlignment (Qt::AlignCenter);

    progressbar_reusme_button = new QPushButton ("Reusme",progressbar_widget);
    progressbar_stop_button = new QPushButton ("Stop",progressbar_widget);
    progressbar_cancel_button = new QPushButton ("Cancel",progressbar_widget);

    GPlayout = new QGridLayout (progressbar_widget);

    GPlayout->addWidget (progressbar , 0 ,0);
    GPlayout->addWidget (progressbar_reusme_button, 1 ,0);
    GPlayout->addWidget (progressbar_stop_button , 1 , 1);
    GPlayout->addWidget (progressbar_cancel_button , 1 , 2);

    services = new DownloadServices (this);
    progressbar_widget->show();

};


void downloadwidget::handle_download_button_click () {
    // check download line 
    // check save as line
    connect (download_button , SIGNAL (clicked()) , this , SLOT (init_prog_widget()));
};

QString downloadwidget::get_url () {
    return download_url_line->text();
};

downloadwidget::~downloadwidget () {};