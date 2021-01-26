#include "newfile.h"
#include "sizecombobox.h"
#include "colorcombobox.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QFile>
#include <QString>
#include <QIODevice>
#include <QTextStream>
#include <QComboBox>
#include <QTextCursor>
#include <QFont>
#include <QMessageBox>
#include <QFileDialog>
#include <QGridLayout>
#include <QFontDatabase>

newFile::newFile(QWidget *parent) : QMainWindow(parent)
{
    // create instances of combobox classes
    colorBox box;
    colorComboBox = box.color;
    colorComboBox->show();

    sizecombobox sizeBox;
    sizeComboBox = sizeBox.size;
    sizeComboBox->show();

    // create list of font families that exist in windows
    fontComboBox = new QComboBox;
    QFontDatabase database;
    const QStringList fontFamilies = database.families();
    for (const QString &family : fontFamilies) {
        fontComboBox->addItem(family);
    }

    // set default value for comboboxes
    sizeComboBox->setCurrentText("12");
    fontComboBox->setCurrentText("Times New Roman");
    colorComboBox->setCurrentText("black");

    //create text edit field and set default font type and size
    edit = new QTextEdit(this);
    edit->setFontFamily("Times New Roman");
    edit->setFontPointSize(12);
    setCentralWidget(edit); // set text edit in center of window

    // declare menu bar and tool bar icons
    QPixmap newPix("new.png");
    QPixmap openPix("open.png");
    QPixmap quitpix("quit.png");
    QPixmap savePix("save.png");
    QPixmap saveasPix("saveas.png");
    QPixmap clearPix("clear.png");
    QPixmap rightPix("right.png");
    QPixmap leftPix("left.png");
    QPixmap justifyPix("justify.png");
    QPixmap boldPix("Bold.png");
    QPixmap italicPix("Italic.png");
    QPixmap normalPix("Normal.png");

    // create actions that we put in menu bar
    auto *quit = new QAction(QIcon(quitpix), "Quit", this);
    auto *newWindow = new QAction(QIcon(newPix), "New window", this);
    auto *open = new QAction(QIcon(openPix), "Open", this);
    auto *save = new QAction(QIcon(savePix), "Save", this);
    auto *saveAs = new QAction(QIcon(saveasPix), "Save as", this);
    newWindow->setShortcut(tr("CTRL+SHIFT+N"));
    open->setShortcut(tr("CTRL+O"));
    save->setShortcut(tr("CTRL+S"));
    quit->setShortcut(tr("CTRL+Q"));
    saveAs->setShortcut(tr("CTRL+SHIFT+S"));

    // create a menu bar
    QMenu *file = menuBar()->addMenu("File");
    file->addAction(newWindow);
    file->addAction(open);
    file->addAction(save);
    file->addAction(saveAs);
    file->addSeparator();
    file->addAction(quit);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    // give funtionality to menu item signals come from selecting them
    connect(quit, &QAction::triggered, this, &QApplication::quit);
    connect(newWindow, &QAction::triggered, this, &newFile::openNewWindow);
    connect(open, &QAction::triggered, this, &newFile::openFile);
    connect(save, &QAction::triggered, this, &newFile::saveFile);
    connect(saveAs, &QAction::triggered, this, &newFile::saveAsFile);

    // give functionality to combo boxes when we select one of its value
    connect(colorComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(updateColor(QString)));
    connect(sizeComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(updateSize(QString)));
    connect(fontComboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(updateFont(QString)));
    connect(colorComboBox, SIGNAL(cursorPositionChanged()), this, SLOT(updateComboBox(QString)));
    connect(edit, SIGNAL(currentCharFormatChanged(QTextCharFormat)), this, SLOT(updateCombobox(QTextCharFormat)));

    // add combo boxes to toolbar
    QToolBar *toolbar = addToolBar("main toolbar");
    toolbar->addWidget(colorComboBox);
    toolbar->addSeparator();
    toolbar->addWidget(sizeComboBox);
    toolbar->addSeparator();
    toolbar->addWidget(fontComboBox);

    // create action values in toolbar
    QAction *clear = toolbar->addAction(clearPix, "clear");
    QAction *leftAlignment = toolbar->addAction(leftPix ,"left alignment");
    QAction *rightAlignment = toolbar->addAction(rightPix, "right alignment");
    QAction *justifyAlignment = toolbar->addAction(justifyPix, "justify alignment");
    QAction *bold = toolbar->addAction(boldPix ,"Bold");
    QAction *italic = toolbar->addAction(italicPix ,"Italic");
    QAction *normal = toolbar->addAction(normalPix ,"Normal");

    // give actions to signals come from objects that we have
    connect(clear, &QAction::triggered, this, &newFile::clear);
    connect(leftAlignment, &QAction::triggered, this, [=]() { this->setAlignment("left alignment"); });
    connect(rightAlignment, &QAction::triggered, this, [=]() { this->setAlignment("right alignment"); });
    connect(justifyAlignment, &QAction::triggered, this, [=]() { this->setAlignment("justify alignment"); });
    connect(bold, &QAction::triggered, this, [=]() { this->setType("Bold"); });
    connect(italic, &QAction::triggered, this, [=]() { this->setType("Italic"); });
    connect(normal, &QAction::triggered, this, [=]() { this->setType("Normal"); });


    statusBar()->showMessage("Ready     Utf-8");
}

// open file
void newFile::openFile()
{
    // open window to select file
    QString files = QFileDialog::getOpenFileName(this, tr("Open File"), "./", tr("*.txt"));
    QFile file(files);
    // give warning if the file does not exist
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","File does not exists!");
        messageBox.setFixedSize(500,200);
    }
    // open file in new window
    openNewWindow();
    QFileInfo fname(files);
    fileName = fname.fileName();
    fileDirectory = fname.path();
    pFileName = fileDirectory + '/' + fileName;
    QTextStream in(&file);
    // code it in utf-8 to represent persian
    in.setCodec("utf-8");
    QString allText = in.readAll();
    edit->setText(allText);

    file.close();
}

//open a new window
void newFile::openNewWindow()
{
    QWidget *newWin = new newFile();
    newWin->resize(1200, 1000);
    newWin->setWindowTitle("new window");
    newWin->show();
}

// save changes to the file
void newFile::saveFile()
{
    QMessageBox messageBox;
    messageBox.critical(0,"Error",pFileName);
    messageBox.setFixedSize(500,200);
    if (fileDirectory == ""){
        newFile::saveAsFile();
    }else{
        QFile f(pFileName);
        if (f.open(QIODevice::WriteOnly)) {
            QTextStream out{&f};
            out.setCodec("utf-8");
            out << edit->toHtml();
            f.close();
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error",pFileName);
            messageBox.setFixedSize(500,200);
        }
    }
}

// save the new file or save as the file that we have
void newFile::saveAsFile()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "./", tr("*.txt"));
    pFileName = fileName;
    QFile f(fileName);
    QFileInfo ff(fileName);
    fileDirectory = ff.path();
    if (f.open(QIODevice::WriteOnly)) {
        QTextStream out{&f};
        out.setCodec("utf-8");
        out << edit->toHtml();
    }
    f.close();
}

// call update color function when the combo box value has been changed
void newFile::updateColor(const QString &text)
{
    colorBox box;
    box.updateColor(edit, text);
}

// call update size function when the combo box value has been changed
void newFile::updateSize(const QString &text)
{
    sizecombobox sizeBox;
    sizeBox.updateSize(edit, text);
}

// change the font of the text when the font combo box value has been changed
void newFile::updateFont(const QString &text)
{
    QTextCursor cursor = edit->textCursor();
    if(cursor.hasSelection())
    {
        edit->setFontFamily(text);
    }else{
        edit->setFontFamily(text);
    }
}

// update combo boxes value when the cursor moves through the text
void newFile::updateCombobox(const QTextCharFormat &text3)
{
    QString size = QString::number(text3.fontPointSize());
    QString font = text3.fontFamily();
    QColor color = text3.foreground().color();
    QString currentColor = color.name();
    if (color == "#ff0000"){
        currentColor = "red";
    }else if(color == "#000000"){
        currentColor = "black";
    }else if(color == "#008000"){
        currentColor = "green";
    }else if(color == "#0000ff"){
        currentColor = "blue";
    }else if(color == "#ffff00"){
        currentColor = "yellow";
    }else if(color == "#ffa500"){
        currentColor = "orange";
    }
    sizeComboBox->setCurrentText(size);
    fontComboBox->setCurrentText(font);
    colorComboBox->setCurrentText(currentColor);
}

// set alignment to the text
void newFile::setAlignment(QString tex)
{
    QTextCursor cursor = edit->textCursor();
    if (tex == "left alignment")
    {
        edit->setAlignment(Qt::AlignLeft);
    }else if (tex == "right alignment"){
        edit->setAlignment(Qt::AlignRight);
    }else{
        edit->setAlignment(Qt::AlignJustify);
    }
}

// set font type to the text
void newFile::setType(QString text)
{
    QTextCursor cursor = edit->textCursor();
    if (text == "Bold")
    {
        QFont f(edit->fontFamily(), edit->fontPointSize() ,QFont::Bold);
        edit->setFont(f);
    }else if (text == "Italic"){
        QFont f( edit->fontFamily(), edit->fontPointSize(), QFont::StyleItalic);
        f.setItalic(true);
        edit->setFont(f);
    }else{
        QFont f( edit->fontFamily(), edit->fontPointSize(), QFont::StyleNormal);
        edit->setFont(f);
    }
}

// clear all values in the app
void newFile::clear()
{
    edit->clear();
}
