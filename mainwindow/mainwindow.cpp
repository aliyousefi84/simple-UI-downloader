#include "mainwindow.hpp"

MyWidget::MyWidget (QWidget* parent) : QWidget (parent) {
    button = new QPushButton("Download" , this);
    layout = new QVBoxLayout (this);
    line = new QLineEdit (this);
    
    button->setSizePolicy(QSizePolicy::Fixed , QSizePolicy::Fixed);
    
    layout->addWidget(line);
    
    layout->setAlignment(Qt::AlignCenter);
    
    layout->setContentsMargins(200,200,200,200);
    
    layout->addWidget(button);

    layout->setAlignment(Qt::AlignCenter);

    connect (button,&QPushButton::clicked,this,&MyWidget::handle_click);
};

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
