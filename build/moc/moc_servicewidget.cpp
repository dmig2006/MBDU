/****************************************************************************
** Meta object code from reading C++ file 'servicewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../servicewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servicewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serviceWidget_t {
    QByteArrayData data[16];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serviceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serviceWidget_t qt_meta_stringdata_serviceWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "serviceWidget"
QT_MOC_LITERAL(1, 14, 13), // "newAdjustment"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "newSound"
QT_MOC_LITERAL(4, 38, 14), // "newStandByMode"
QT_MOC_LITERAL(5, 53, 16), // "newOperationMode"
QT_MOC_LITERAL(6, 70, 8), // "newMJPEG"
QT_MOC_LITERAL(7, 79, 7), // "newH264"
QT_MOC_LITERAL(8, 87, 27), // "on_adjustmentButton_clicked"
QT_MOC_LITERAL(9, 115, 21), // "on_exitButton_clicked"
QT_MOC_LITERAL(10, 137, 21), // "on_modeButton_clicked"
QT_MOC_LITERAL(11, 159, 22), // "on_soundButton_clicked"
QT_MOC_LITERAL(12, 182, 27), // "on_applyBurstLength_clicked"
QT_MOC_LITERAL(13, 210, 26), // "on_applyAmmunition_clicked"
QT_MOC_LITERAL(14, 237, 22), // "on_mjpegButton_clicked"
QT_MOC_LITERAL(15, 260, 21) // "on_h264Button_clicked"

    },
    "serviceWidget\0newAdjustment\0\0newSound\0"
    "newStandByMode\0newOperationMode\0"
    "newMJPEG\0newH264\0on_adjustmentButton_clicked\0"
    "on_exitButton_clicked\0on_modeButton_clicked\0"
    "on_soundButton_clicked\0"
    "on_applyBurstLength_clicked\0"
    "on_applyAmmunition_clicked\0"
    "on_mjpegButton_clicked\0on_h264Button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serviceWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    0,   88,    2, 0x06 /* Public */,
       7,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void serviceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        serviceWidget *_t = static_cast<serviceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newAdjustment(); break;
        case 1: _t->newSound(); break;
        case 2: _t->newStandByMode(); break;
        case 3: _t->newOperationMode(); break;
        case 4: _t->newMJPEG(); break;
        case 5: _t->newH264(); break;
        case 6: _t->on_adjustmentButton_clicked(); break;
        case 7: _t->on_exitButton_clicked(); break;
        case 8: _t->on_modeButton_clicked(); break;
        case 9: _t->on_soundButton_clicked(); break;
        case 10: _t->on_applyBurstLength_clicked(); break;
        case 11: _t->on_applyAmmunition_clicked(); break;
        case 12: _t->on_mjpegButton_clicked(); break;
        case 13: _t->on_h264Button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (serviceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serviceWidget::newAdjustment)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (serviceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serviceWidget::newSound)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (serviceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serviceWidget::newStandByMode)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (serviceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serviceWidget::newOperationMode)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (serviceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serviceWidget::newMJPEG)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (serviceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serviceWidget::newH264)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject serviceWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_serviceWidget.data,
      qt_meta_data_serviceWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *serviceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serviceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_serviceWidget.stringdata0))
        return static_cast<void*>(const_cast< serviceWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int serviceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void serviceWidget::newAdjustment()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void serviceWidget::newSound()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void serviceWidget::newStandByMode()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void serviceWidget::newOperationMode()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void serviceWidget::newMJPEG()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void serviceWidget::newH264()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
