#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <qt6/QtCore/QUrl>
#include <qt6/QtCore/QFile>
#include <qt6/QtCore/QDir>
#include <QProgressBar>

class MyWidget : public QWidget {
    Q_OBJECT
    public:
        MyWidget (QWidget* parent = nullptr);
    private slots:
        
        void handle_click ();
        
        
        void handle_download();

        QString parse_url ();
    
    private:
        QPushButton* button;
       
        QVBoxLayout* layout;
        
        QLineEdit* line;
        
        QNetworkAccessManager* manager;
        
        QNetworkReply* reply;
        
        QProgressBar* progressbar;
};
