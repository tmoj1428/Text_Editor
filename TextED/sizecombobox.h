#ifndef SIZECOMBOBOX_H
#define SIZECOMBOBOX_H

#include <QComboBox>
#include <QTextEdit>

class sizecombobox : public QWidget
{
public:
    sizecombobox(QWidget *parent = nullptr);
    QComboBox* size;
    void updateSize(QTextEdit *edit,const QString &text);
};

#endif // SIZECOMBOBOX_H
