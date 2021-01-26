#include "colorcombobox.h"
#include <QWidget>
#include <QComboBox>
#include <QTextEdit>

colorBox::colorBox(QWidget *parent) : QWidget(parent)
{
    color = new QComboBox;
    color->setCurrentText("choose color");
    color->addItem("black");
    color->addItem("red");
    color->addItem("orange");
    color->addItem("green");
    color->addItem("red");
    color->addItem("yellow");
    color->addItem("blue");
}

void colorBox::updateColor(QTextEdit *edit,const QString &text)
{
    QTextCursor cursor = edit->textCursor();
    if(cursor.hasSelection())
    {
        edit->setTextColor(QColor(text));
    }else{
        edit->setTextColor(QColor(text));
    }
}
