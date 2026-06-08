#ifndef DOWNLOADWIDGET_HPP
#define DOWNLOADWIDGET_HPP
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

class downloadwidget : public QWidget {
    Q_OBJECT
    public:
        downloadwidget (QWidget* parent = nullptr);
        ~downloadwidget ();
        
    private:
        void create_downloadbox (QWidget* parent);

        void create_savebox (QWidget* parent);

        void create_description (QWidget* parent);

        void set_layout ();
        
        QGridLayout* Glayout;

        QLineEdit* download_url_line;
        
        QLabel* save_label;
        
        QLineEdit* save_line;

        QLineEdit* description_line;
        
        QPushButton* cancel_button;

        QPushButton* download_button;
        
        QLabel* download_url_label;
        
        QLabel* description_label;
};



#endif