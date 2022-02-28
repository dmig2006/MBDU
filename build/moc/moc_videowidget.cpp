/****************************************************************************
** Meta object code from reading C++ file 'videowidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/videowidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videowidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoWidget_t {
    QByteArrayData data[11];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoWidget_t qt_meta_stringdata_VideoWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VideoWidget"
QT_MOC_LITERAL(1, 12, 9), // "newLogMsg"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "string"
QT_MOC_LITERAL(4, 30, 11), // "resetCamera"
QT_MOC_LITERAL(5, 42, 8), // "setImage"
QT_MOC_LITERAL(6, 51, 5), // "image"
QT_MOC_LITERAL(7, 57, 16), // "setOperationMode"
QT_MOC_LITERAL(8, 74, 5), // "state"
QT_MOC_LITERAL(9, 80, 15), // "isNotConnetcted"
QT_MOC_LITERAL(10, 96, 15) // "closeConnection"

    },
    "VideoWidget\0newLogMsg\0\0string\0resetCamera\0"
    "setImage\0image\0setOperationMode\0state\0"
    "isNotConnetcted\0closeConnection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoWidget[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   43,    2, 0x0a /* Public */,
       7,    2,   46,    2, 0x0a /* Public */,
      10,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    8,    9,
    QMetaType::Void,

       0        // eod
};

void VideoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoWidget *_t = static_cast<VideoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newLogMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->resetCamera(); break;
        case 2: _t->setImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->setOperationMode((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->closeConnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VideoWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoWidget::newLogMsg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (VideoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoWidget::resetCamera)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject VideoWidget::staticMetaObject = {
    { &QVideoWidget::staticMetaObject, qt_meta_stringdata_VideoWidget.data,
      qt_meta_data_VideoWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoWidget.stringdata0))
        return static_cast<void*>(const_cast< VideoWidget*>(this));
    return QVideoWidget::qt_metacast(_clname);
}

int VideoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVideoWidget::qt_metacall(_c, _id, _a);
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
void VideoWidget::newLogMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoWidget::resetCamera()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
