/****************************************************************************
** Meta object code from reading C++ file 'optwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/optwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OptWidget_t {
    QByteArrayData data[14];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptWidget_t qt_meta_stringdata_OptWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "OptWidget"
QT_MOC_LITERAL(1, 10, 14), // "move_Ac_Target"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 1), // "x"
QT_MOC_LITERAL(4, 28, 1), // "y"
QT_MOC_LITERAL(5, 30, 21), // "setCenterMassTracking"
QT_MOC_LITERAL(6, 52, 8), // "setRects"
QT_MOC_LITERAL(7, 61, 8), // "pRect_t1"
QT_MOC_LITERAL(8, 70, 8), // "pRect_t2"
QT_MOC_LITERAL(9, 79, 16), // "invertCrossColor"
QT_MOC_LITERAL(10, 96, 10), // "setBlockPP"
QT_MOC_LITERAL(11, 107, 7), // "enabled"
QT_MOC_LITERAL(12, 115, 8), // "inversia"
QT_MOC_LITERAL(13, 124, 7) // "pButton"

    },
    "OptWidget\0move_Ac_Target\0\0x\0y\0"
    "setCenterMassTracking\0setRects\0pRect_t1\0"
    "pRect_t2\0invertCrossColor\0setBlockPP\0"
    "enabled\0inversia\0pButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   49,    2, 0x0a /* Public */,
       6,    2,   54,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,
      10,    1,   60,    2, 0x0a /* Public */,
      12,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Long, QMetaType::Long,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QRect, QMetaType::QRect,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   13,

       0        // eod
};

void OptWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptWidget *_t = static_cast<OptWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->move_Ac_Target((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 1: _t->setCenterMassTracking((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setRects((*reinterpret_cast< QRect(*)>(_a[1])),(*reinterpret_cast< QRect(*)>(_a[2]))); break;
        case 3: _t->invertCrossColor(); break;
        case 4: _t->setBlockPP((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->inversia((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OptWidget::*_t)(long , long );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OptWidget::move_Ac_Target)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject OptWidget::staticMetaObject = {
    { &QVideoWidget::staticMetaObject, qt_meta_stringdata_OptWidget.data,
      qt_meta_data_OptWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OptWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OptWidget.stringdata0))
        return static_cast<void*>(const_cast< OptWidget*>(this));
    return QVideoWidget::qt_metacast(_clname);
}

int OptWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVideoWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void OptWidget::move_Ac_Target(long _t1, long _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
