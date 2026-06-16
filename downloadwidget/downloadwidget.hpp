#ifndef DOWNLOADWIDGET_HPP
#define DOWNLOADWIDGET_HPP
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QString>
#include "../services/services.hpp"

class downloadwidget : public QWidget {
    Q_OBJECT
    public:
        downloadwidget (QWidget* parent = nullptr);
        ~downloadwidget ();
        QString get_url ();
    private slots:

        void init_prog_widget ();
    
    private:
        void create_downloadbox (QWidget* parent);

        void create_savebox (QWidget* parent);

        void create_description (QWidget* parent);

        void set_layout ();
        
        void handle_download_button_click ();

        void handle_http_request ();
    
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

        DownloadServices* services;

        QProgressBar* progressbar;

        QPushButton* progressbar_reusme_button;

        QPushButton* progressbar_stop_button;

        QPushButton* progressbar_cancel_button;

        QWidget* progressbar_widget;
};



#endif