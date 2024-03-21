#include "NotepadMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NotepadMain w;
    w.show();
    return a.exec();
}
