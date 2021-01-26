#include <QWidget>
#include "newfile.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    newFile window;
    window.resize(1200, 1000);
    window.setWindowTitle("new window");
    window.show();
    return app.exec();
}
