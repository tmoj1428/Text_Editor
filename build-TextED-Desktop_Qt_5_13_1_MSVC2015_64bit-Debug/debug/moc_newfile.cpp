/****************************************************************************
** Meta object code from reading C++ file 'newfile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TextED/newfile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_newFile_t {
    QByteArrayData data[19];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_newFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_newFile_t qt_meta_stringdata_newFile = {
    {
QT_MOC_LITERAL(0, 0, 7), // "newFile"
QT_MOC_LITERAL(1, 8, 13), // "openNewWindow"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "saveFile"
QT_MOC_LITERAL(4, 32, 10), // "saveAsFile"
QT_MOC_LITERAL(5, 43, 5), // "clear"
QT_MOC_LITERAL(6, 49, 8), // "openFile"
QT_MOC_LITERAL(7, 58, 12), // "setAlignment"
QT_MOC_LITERAL(8, 71, 3), // "tex"
QT_MOC_LITERAL(9, 75, 7), // "setType"
QT_MOC_LITERAL(10, 83, 11), // "updateColor"
QT_MOC_LITERAL(11, 95, 4), // "text"
QT_MOC_LITERAL(12, 100, 10), // "updateSize"
QT_MOC_LITERAL(13, 111, 5), // "text1"
QT_MOC_LITERAL(14, 117, 10), // "updateFont"
QT_MOC_LITERAL(15, 128, 5), // "text2"
QT_MOC_LITERAL(16, 134, 14), // "updateCombobox"
QT_MOC_LITERAL(17, 149, 15), // "QTextCharFormat"
QT_MOC_LITERAL(18, 165, 5) // "text3"

    },
    "newFile\0openNewWindow\0\0saveFile\0"
    "saveAsFile\0clear\0openFile\0setAlignment\0"
    "tex\0setType\0updateColor\0text\0updateSize\0"
    "text1\0updateFont\0text2\0updateCombobox\0"
    "QTextCharFormat\0text3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_newFile[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      16,    1,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void newFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<newFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openNewWindow(); break;
        case 1: _t->saveFile(); break;
        case 2: _t->saveAsFile(); break;
        case 3: _t->clear(); break;
        case 4: _t->openFile(); break;
        case 5: _t->setAlignment((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->updateColor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->updateSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->updateFont((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->updateCombobox((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject newFile::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_newFile.data,
    qt_meta_data_newFile,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *newFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *newFile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_newFile.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int newFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
