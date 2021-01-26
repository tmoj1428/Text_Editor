#ifndef NEWFILE_H
#define NEWFILE_H

#include <QMainWindow>
#include <QApplication>
#include <QTextEdit>
#include <QComboBox>

class newFile : public QMainWindow
{
    Q_OBJECT
    public:
        newFile(QWidget *parent = nullptr);
        bool newWindowSignal = false;
        QTextEdit *edit;
        QString fileName, pFileName, fileDirectory;
        QComboBox* colorComboBox;
        QComboBox* sizeComboBox;
        QComboBox* fontComboBox;
    private slots:
        void openNewWindow();
        void saveFile();
        void saveAsFile();
        void clear();
        void openFile();
        void setAlignment(QString tex);
        void setType(QString tex);
        void updateColor(const QString &text);
        void updateSize(const QString &text1);
        void updateFont(const QString &text2);
        void updateCombobox(const QTextCharFormat &text3);
};

#endif // NEWFILE_H
