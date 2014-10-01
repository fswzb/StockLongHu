/****************************************************************************
** Meta object code from reading C++ file 'classtabtwo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "E:/Code/project/testTabUI/classtabtwo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classtabtwo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClassTabTwo_t {
    QByteArrayData data[13];
    char stringdata[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ClassTabTwo_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ClassTabTwo_t qt_meta_stringdata_ClassTabTwo = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 14),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 3),
QT_MOC_LITERAL(4, 32, 30),
QT_MOC_LITERAL(5, 63, 26),
QT_MOC_LITERAL(6, 90, 28),
QT_MOC_LITERAL(7, 119, 27),
QT_MOC_LITERAL(8, 147, 23),
QT_MOC_LITERAL(9, 171, 23),
QT_MOC_LITERAL(10, 195, 23),
QT_MOC_LITERAL(11, 219, 21),
QT_MOC_LITERAL(12, 241, 4)
    },
    "ClassTabTwo\0openYinYeBuURL\0\0url\0"
    "downloadYinYeBuHistoryFinished\0"
    "downloadYinYeBuDayFinished\0"
    "downloadYinYeBuMonthFinished\0"
    "downloadYinYeBuPageFinished\0"
    "on_pushButton_1_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_2_clicked\0on_comboBox_activated\0"
    "arg1\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClassTabTwo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08,
       4,    0,   62,    2, 0x08,
       5,    0,   63,    2, 0x08,
       6,    0,   64,    2, 0x08,
       7,    0,   65,    2, 0x08,
       8,    0,   66,    2, 0x08,
       9,    0,   67,    2, 0x08,
      10,    0,   68,    2, 0x08,
      11,    1,   69,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void ClassTabTwo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClassTabTwo *_t = static_cast<ClassTabTwo *>(_o);
        switch (_id) {
        case 0: _t->openYinYeBuURL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->downloadYinYeBuHistoryFinished(); break;
        case 2: _t->downloadYinYeBuDayFinished(); break;
        case 3: _t->downloadYinYeBuMonthFinished(); break;
        case 4: _t->downloadYinYeBuPageFinished(); break;
        case 5: _t->on_pushButton_1_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ClassTabTwo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClassTabTwo.data,
      qt_meta_data_ClassTabTwo,  qt_static_metacall, 0, 0}
};


const QMetaObject *ClassTabTwo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClassTabTwo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClassTabTwo.stringdata))
        return static_cast<void*>(const_cast< ClassTabTwo*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClassTabTwo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
