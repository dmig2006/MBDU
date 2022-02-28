/****************************************************************************
** Meta object code from reading C++ file 'qsocketthred.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/qsocketthred.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsocketthred.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSocketThred_t {
    QByteArrayData data[11];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSocketThred_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSocketThred_t qt_meta_stringdata_QSocketThred = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QSocketThred"
QT_MOC_LITERAL(1, 13, 9), // "DataReady"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "char*"
QT_MOC_LITERAL(4, 30, 4), // "data"
QT_MOC_LITERAL(5, 35, 3), // "len"
QT_MOC_LITERAL(6, 39, 9), // "newLogMsg"
QT_MOC_LITERAL(7, 49, 3), // "str"
QT_MOC_LITERAL(8, 53, 9), // "WriteData"
QT_MOC_LITERAL(9, 63, 11), // "onReadyRead"
QT_MOC_LITERAL(10, 75, 14) // "onDisconnected"

    },
    "QSocketThred\0DataReady\0\0char*\0data\0"
    "len\0newLogMsg\0str\0WriteData\0onReadyRead\0"
    "onDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSocketThred[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       6,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   47,    2, 0x0a /* Public */,
       9,    0,   52,    2, 0x0a /* Public */,
      10,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSocketThred::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QSocketThred *_t = static_cast<QSocketThred *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataReady((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->newLogMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->WriteData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->onReadyRead(); break;
        case 4: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QSocketThred::*_t)(char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSocketThred::DataReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QSocketThred::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QSocketThred::newLogMsg)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject QSocketThred::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QSocketThred.data,
      qt_meta_data_QSocketThred,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSocketThred::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSocketThred::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSocketThred.stringdata0))
        return static_cast<void*>(const_cast< QSocketThred*>(this));
    return QThread::qt_metacast(_clname);
}

int QSocketThred::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QSocketThred::DataReady(char * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSocketThred::newLogMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
