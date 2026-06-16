#include "progressbar.hpp"

ProgressBar::ProgressBar (QWidget* parent , QString url) : QWidget (parent) {
    download_url = url;
    this->resize (800,150);
    progressbar = new QProgressBar (this);
    progressbar->setAlignment (Qt::AlignCenter);

    progressbar_reusme_button = new QPushButton ("Reusme",this);
    progressbar_stop_button = new QPushButton ("Stop",this);
    progressbar_cancel_button = new QPushButton ("Cancel",this);

    GPlayout = new QGridLayout (this);

    GPlayout->addWidget (progressbar , 0 ,0);
    GPlayout->addWidget (progressbar_reusme_button, 1 ,0);
    GPlayout->addWidget (progressbar_stop_button , 1 , 1);
    GPlayout->addWidget (progressbar_cancel_button , 1 , 2);

    progressbar->setValue (0);
    send_request (url);
    
};
// handeling http request and progressbar update 
void ProgressBar::send_request (QString url) {
    manager = new QNetworkAccessManager();
    reply = manager->get(QNetworkRequest(QUrl(url)));
    connect (reply , &QNetworkReply::finished ,  this , &ProgressBar::read_data_from_request);
    connect (reply , &QNetworkReply::downloadProgress, this , &ProgressBar::update_progress);
};

// we should adding a share memory for non copy from data receieved to file 
void ProgressBar::read_data_from_request () {
    if (reply->error() == QNetworkReply::NoError) {
    QUrl url = QUrl (download_url);
    byte = reply->readAll ();
    QString file_name = url.fileName ();
    std::string file_name_str = file_name.toStdString();
    write_file (file_name_str.data() ,byte.data() , byte.size());
    } else {
        std::cout << "can not download this shit !!!" << std::endl;
        exit(1);
    }
}

// progressbar update logic
void ProgressBar::update_progress (qint64 received , qint64 total) {
    if (total > 0)
    {
        int percent = (int) ((received * 100) / total);
        progressbar->setValue (percent);
    }
}