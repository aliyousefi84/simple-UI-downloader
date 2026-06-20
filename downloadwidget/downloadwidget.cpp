#include "downloadwidget.hpp"

downloadwidget::downloadwidget (QWidget* parent) : QWidget (parent) {
    this->resize (800,200);
    this->setWindowTitle ("Download Box");
    create_downloadbox (this);
    create_savebox (this);
    create_description (this);
    set_layout();
    handle_download_button_click ();
    handle_cancel_button ();
    
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
    if (download_url_line->text().isEmpty())
    {
        QMessageBox::warning (this ,"warning","url field should not be empty !");
        download_url_line->setFocus ();
        return;
    }
    
    progress_bar = new ProgressBar (NULL,get_url());
    progress_bar->show();
};


void downloadwidget::handle_download_button_click () {

    connect (download_button , SIGNAL (clicked()) , this , SLOT (init_prog_widget()));
};

void downloadwidget::exit_from_app () {
    this->setAttribute (Qt::WA_DeleteOnClose);
    this->close();
};

void downloadwidget::handle_cancel_button () {
    
    connect (cancel_button,SIGNAL (clicked()),this, SLOT (exit_from_app()));
};

QString downloadwidget::get_url () {
    return download_url_line->text();
};



downloadwidget::~downloadwidget () {};