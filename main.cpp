#include <QtGui/QApplication>
#include <QtGui/QMainWindow>

#include "FlowUI.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QMainWindow ui;
    Ui_FlowWin flowmain;
    flowmain.setupUi(&ui);
    
    ui.show();
    return app.exec();
}
