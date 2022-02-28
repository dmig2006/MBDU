/****************************************************************************
** Meta object code from reading C++ file 'canad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/canad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_canad_t {
    QByteArrayData data[13];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_canad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_canad_t qt_meta_stringdata_canad = {
    {
QT_MOC_LITERAL(0, 0, 5), // "canad"
QT_MOC_LITERAL(1, 6, 9), // "SendToLog"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 9), // "SendFrame"
QT_MOC_LITERAL(4, 27, 10), // "can_frame*"
QT_MOC_LITERAL(5, 38, 9), // "SendBytes"
QT_MOC_LITERAL(6, 48, 5), // "char*"
QT_MOC_LITERAL(7, 54, 4), // "data"
QT_MOC_LITERAL(8, 59, 3), // "len"
QT_MOC_LITERAL(9, 63, 13), // "BytesToFrames"
QT_MOC_LITERAL(10, 77, 4), // "size"
QT_MOC_LITERAL(11, 82, 13), // "FramesToBytes"
QT_MOC_LITERAL(12, 96, 5) // "frame"

    },
    "canad\0SendToLog\0\0SendFrame\0can_frame*\0"
    "SendBytes\0char*\0data\0len\0BytesToFrames\0"
    "size\0FramesToBytes\0frame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canad[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,
       5,    2,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   50,    2, 0x0a /* Public */,
      11,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,   10,
    QMetaType::Void, 0x80000000 | 4,   12,

       0        // eod
};

void canad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        canad *_t = static_cast<canad *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendToLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SendFrame((*reinterpret_cast< can_frame*(*)>(_a[1]))); break;
        case 2: _t->SendBytes((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->BytesToFrames((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->FramesToBytes((*reinterpret_cast< can_frame*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (canad::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&canad::SendToLog)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (canad::*_t)(can_frame * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&canad::SendFrame)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (canad::*_t)(char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&canad::SendBytes)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject canad::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_canad.data,
      qt_meta_data_canad,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *canad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canad::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_canad.stringdata0))
        return static_cast<void*>(const_cast< canad*>(this));
    return QObject::qt_metacast(_clname);
}

int canad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void canad::SendToLog(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canad::SendFrame(can_frame * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void canad::SendBytes(char * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
