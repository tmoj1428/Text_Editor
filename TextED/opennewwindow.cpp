#include "opennewwindow.h"
#include "newfile.h"
#include <QWidget>

void openWindow()
{
    QWidget *newWin = new newFile();
    newWin->resize(1200, 1000);
    newWin->setWindowTitle("new window");
    newWin->show();
}
