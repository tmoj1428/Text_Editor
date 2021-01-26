#ifndef OPENNEWWINDOW_H
#define OPENNEWWINDOW_H
#include <QMainWindow>
#include <QWidget>

class opennewwindow : public QMainWindow
{
public:
    ~opennewwindow();
public slots:
    void openWindow();
};

#endif // OPENNEWWINDOW_H
