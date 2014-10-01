/****************************************************************************
** Meta object code from reading C++ file 'classtabone.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "E:/Code/project/testTabUI/classtabone.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classtabone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClassTabOne_t {
    QByteArrayData data[19];
    char stringdata[347];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ClassTabOne_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ClassTabOne_t qt_meta_stringdata_ClassTabOne = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 22),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 23),
QT_MOC_LITERAL(4, 60, 30),
QT_MOC_LITERAL(5, 91, 23),
QT_MOC_LITERAL(6, 115, 21),
QT_MOC_LITERAL(7, 137, 5),
QT_MOC_LITERAL(8, 143, 14),
QT_MOC_LITERAL(9, 158, 3),
QT_MOC_LITERAL(10, 162, 21),
QT_MOC_LITERAL(11, 184, 4),
QT_MOC_LITERAL(12, 189, 23),
QT_MOC_LITERAL(13, 213, 27),
QT_MOC_LITERAL(14, 241, 23),
QT_MOC_LITERAL(15, 265, 4),
QT_MOC_LITERAL(16, 270, 23),
QT_MOC_LITERAL(17, 294, 23),
QT_MOC_LITERAL(18, 318, 27)
    },
    "ClassTabOne\0DownloadLongHuFinished\0\0"
    "DownloadYinYeBuFinished\0"
    "DownloadLongHuDateListFinished\0"
    "DownloadNewDateFinished\0on_tableView1_clicked\0"
    "index\0openYinYeBuURL\0url\0on_comboBox_activated\0"
    "arg1\0on_pushButton_2_clicked\0"
    "on_tableView1_doubleClicked\0"
    "on_dateEdit_dateChanged\0date\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked\0"
    "on_dateEdit_userDateChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClassTabOne[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08,
       3,    0,   80,    2, 0x08,
       4,    0,   81,    2, 0x08,
       5,    0,   82,    2, 0x08,
       6,    1,   83,    2, 0x08,
       8,    1,   86,    2, 0x08,
      10,    1,   89,    2, 0x08,
      12,    0,   92,    2, 0x08,
      13,    1,   93,    2, 0x08,
      14,    1,   96,    2, 0x08,
      16,    0,   99,    2, 0x08,
      17,    0,  100,    2, 0x08,
      18,    1,  101,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void, QMetaType::QDate,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,   15,

       0        // eod
};

void ClassTabOne::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClassTabOne *_t = static_cast<ClassTabOne *>(_o);
        switch (_id) {
        case 0: _t->DownloadLongHuFinished(); break;
        case 1: _t->DownloadYinYeBuFinished(); break;
        case 2: _t->DownloadLongHuDateListFinished(); break;
        case 3: _t->DownloadNewDateFinished(); break;
        case 4: _t->on_tableView1_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->openYinYeBuURL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_tableView1_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_dateEdit_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_3_clicked(); break;
        case 11: _t->on_pushButton_4_clicked(); break;
        case 12: _t->on_dateEdit_userDateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ClassTabOne::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClassTabOne.data,
      qt_meta_data_ClassTabOne,  qt_static_metacall, 0, 0}
};


const QMetaObject *ClassTabOne::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClassTabOne::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClassTabOne.stringdata))
        return static_cast<void*>(const_cast< ClassTabOne*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClassTabOne::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
