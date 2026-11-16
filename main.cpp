#include "tcpfilesever.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpFileSever w;
    w.show();
    return QApplication::exec();
}
