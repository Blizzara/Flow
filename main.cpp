#include <QtGui/QApplication>
#include "Flow.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Flow foo;
    foo.show();
    return app.exec();
}
