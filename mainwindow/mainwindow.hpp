#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QToolBar>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include "../utils/utils.hpp"
#include "../downloadwidget/downloadwidget.hpp"


class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        MainWindow (QMainWindow* parent = nullptr);
        ~MainWindow ();
    
    private slots:
        
        void init_download_widget ();

    private:
        
        void create_toolbar ();

        void create_menu ();

        void handle_download_menu_clicked ();

        void handle_download_toolbar_clicked ();


        QStringList List;

        QMenuBar* menubar;

        QMenu* filemenu;

        QMenu* helpmenu;

        QAction* helpmenu_doc_action;

        QAction* filemenu_save_action;

        QAction* filemenu_quit_action;

        QAction* filemenu_download_action;

        QToolBar* toolbar;

        QAction* tool_download_action;

        QPushButton* button;
       
        QVBoxLayout* Vlayout;
        
        QLineEdit* line;

        downloadwidget* download_widget;
        
};
