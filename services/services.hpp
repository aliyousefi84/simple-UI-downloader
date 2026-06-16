#ifndef SERVICES_HPP
#define SERVICES_HPP 

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <string>
#include "../downloadwidget/downloadwidget.hpp"
#include "../utils/utils.hpp"

class DownloadServices : public downloadwidget{
    Q_OBJECT
    public:
        DownloadServices (downloadwidget* parent);

    private slots:
        void read_data_from_request ();
            
    private:

        QNetworkAccessManager* manager;

        QNetworkReply* reply;

        QUrl* url;

};




#endif
