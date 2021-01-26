#ifndef COLORCOMBOBOX_H
#define COLORCOMBOBOX_H

#include <QComboBox>
#include <QTextEdit>

class colorBox : public QWidget
{
public:
    colorBox(QWidget *parent = nullptr);
    QComboBox* color;
    void updateColor(QTextEdit *edit,const QString &text);
};

#endif // COLORCOMBOBOX_H
