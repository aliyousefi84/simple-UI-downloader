#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>
#include <QStandardItemModel>
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
        
        void edit_table ();
    
    private slots:
        
        void init_download_widget ();

    private:
        void create_table (); 
        
        void create_toolbar ();

        void create_menu ();

        void handle_download_menu_clicked ();

        void handle_download_toolbar_clicked ();
        
        void handle_download();

        QString parse_url ();

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

        QAction* tool_delete_action;

        QAction* tool_delete_all_action;

        QTableView* table_view;        
        
        QStandardItemModel* model;

        QPushButton* button;
       
        QVBoxLayout* Vlayout;
        
        QLineEdit* line;

        downloadwidget* download_widget;
        
};
