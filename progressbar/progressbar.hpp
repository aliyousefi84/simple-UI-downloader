#ifndef SERVICES_HPP
#define SERVICES_HPP 

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QGridLayout>
#include <string>
#include "../utils/utils.hpp"

class ProgressBar : public QWidget {
    Q_OBJECT
    public:
        ProgressBar (QWidget* parent, QString url);

    private slots:
        void read_data_from_request ();

        void update_progress (qint64 received , qint64 total);
            
    private:

        void send_request (QString url);

        QNetworkAccessManager* manager;

        QNetworkReply* reply;

        QProgressBar* progressbar;

        QPushButton* progressbar_reusme_button;

        QPushButton* progressbar_stop_button;

        QPushButton* progressbar_cancel_button;

        QGridLayout* GPlayout;

        QByteArray byte;

        QString download_url;
};




#endif
