/****************************************************************************
** Meta object code from reading C++ file 'adjustment_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/adjustment_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adjustment_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdjustmentDialog_t {
    QByteArrayData data[10];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdjustmentDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdjustmentDialog_t qt_meta_stringdata_AdjustmentDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AdjustmentDialog"
QT_MOC_LITERAL(1, 17, 19), // "on_upButton_pressed"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 21), // "on_leftButton_pressed"
QT_MOC_LITERAL(4, 60, 21), // "on_downButton_pressed"
QT_MOC_LITERAL(5, 82, 22), // "on_rightButton_pressed"
QT_MOC_LITERAL(6, 105, 23), // "on_centerButton_clicked"
QT_MOC_LITERAL(7, 129, 22), // "on_applyButton_clicked"
QT_MOC_LITERAL(8, 152, 23), // "on_applyButton_released"
QT_MOC_LITERAL(9, 176, 23) // "on_cancelButton_clicked"

    },
    "AdjustmentDialog\0on_upButton_pressed\0"
    "\0on_leftButton_pressed\0on_downButton_pressed\0"
    "on_rightButton_pressed\0on_centerButton_clicked\0"
    "on_applyButton_clicked\0on_applyButton_released\0"
    "on_cancelButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdjustmentDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

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

void AdjustmentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdjustmentDialog *_t = static_cast<AdjustmentDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_upButton_pressed(); break;
        case 1: _t->on_leftButton_pressed(); break;
        case 2: _t->on_downButton_pressed(); break;
        case 3: _t->on_rightButton_pressed(); break;
        case 4: _t->on_centerButton_clicked(); break;
        case 5: _t->on_applyButton_clicked(); break;
        case 6: _t->on_applyButton_released(); break;
        case 7: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AdjustmentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AdjustmentDialog.data,
      qt_meta_data_AdjustmentDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdjustmentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdjustmentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdjustmentDialog.stringdata0))
        return static_cast<void*>(const_cast< AdjustmentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AdjustmentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
