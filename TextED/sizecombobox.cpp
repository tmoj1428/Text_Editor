#include "sizecombobox.h"
#include <QComboBox>
sizecombobox::sizecombobox(QWidget *parent) : QWidget(parent)
{
    size = new QComboBox;
    size->addItem("8");
    size->addItem("10");
    size->addItem("12");
    size->addItem("14");
    size->addItem("16");
    size->addItem("18");
    size->addItem("24");
    size->addItem("36");
    size->addItem("72");
}

void sizecombobox::updateSize(QTextEdit *edit, const QString &text)
{
    QTextCursor cursor = edit->textCursor();
    if(cursor.hasSelection())
    {
        edit->setFontPointSize(text.toInt());
    }else{
        edit->setFontPointSize(text.toInt());
    }
}
