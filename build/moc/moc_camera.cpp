/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/camera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Camera_t {
    QByteArrayData data[9];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Camera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Camera_t qt_meta_stringdata_Camera = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Camera"
QT_MOC_LITERAL(1, 7, 8), // "newFrame"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "image"
QT_MOC_LITERAL(4, 23, 11), // "closeCamera"
QT_MOC_LITERAL(5, 35, 9), // "newLogMsg"
QT_MOC_LITERAL(6, 45, 6), // "string"
QT_MOC_LITERAL(7, 52, 13), // "gotConnection"
QT_MOC_LITERAL(8, 66, 13) // "stopExecution"

    },
    "Camera\0newFrame\0\0image\0closeCamera\0"
    "newLogMsg\0string\0gotConnection\0"
    "stopExecution"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Camera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    1,   43,    2, 0x06 /* Public */,
       7,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Camera *_t = static_cast<Camera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newFrame((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->closeCamera(); break;
        case 2: _t->newLogMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->gotConnection(); break;
        case 4: _t->stopExecution(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Camera::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::newFrame)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Camera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::closeCamera)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Camera::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::newLogMsg)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Camera::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Camera::gotConnection)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Camera::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Camera.data,
      qt_meta_data_Camera,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Camera.stringdata0))
        return static_cast<void*>(const_cast< Camera*>(this));
    if (!strcmp(_clname, "VideoClient"))
        return static_cast< VideoClient*>(const_cast< Camera*>(this));
    return QThread::qt_metacast(_clname);
}

int Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Camera::newFrame(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Camera::closeCamera()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Camera::newLogMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Camera::gotConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
