#ifndef DOWNLOADWIDGET_HPP
#define DOWNLOADWIDGET_HPP
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QString>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <chrono>
#include <ctime>
#include "../utils/utils.hpp"
#include "../progressbar/progressbar.hpp"
#include "../internal/datamodel.hpp"
#include "../internal/storage.hpp"

class downloadwidget : public QWidget {
    Q_OBJECT
    public:
        downloadwidget (QWidget* parent = nullptr);
        ~downloadwidget ();

        QString get_url ();

        void initialize_datamodel_name ();

    private slots:

        void init_prog_widget ();

        void exit_from_app ();
    
    private:
        void create_downloadbox (QWidget* parent);

        void create_savebox (QWidget* parent);

        void create_description (QWidget* parent);

        void set_layout ();
        
        void handle_download_button_click ();

        void handle_cancel_button ();

        QGridLayout* Glayout;

        QGridLayout* GPlayout;

        QLineEdit* download_url_line;
        
        QLabel* save_label;
        
        QLineEdit* save_line;

        QLineEdit* description_line;
        
        QPushButton* cancel_button;

        QPushButton* download_button;
        
        QLabel* download_url_label;
        
        QLabel* description_label;

        ProgressBar* progress_bar;


        //QUrl* url;

};



#endif