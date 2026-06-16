#include "services.hpp"

DownloadServices::DownloadServices (downloadwidget* parent) : downloadwidget (parent) {
    manager = new QNetworkAccessManager ();
    QObject::connect (manager , SIGNAL (finished (reply)) , this , SLOT (read_data_from_request()));
    *url = this->get_url();
    manager->get(QNetworkRequest(*url));
    read_data_from_request ();
};


void DownloadServices::read_data_from_request () {
    QByteArray byte = reply->readAll ();
    QString file_name = url->fileName ();
    std::string file_name_str = file_name.toStdString();
    write_file (file_name_str.data() ,byte.data() , byte.size());
}