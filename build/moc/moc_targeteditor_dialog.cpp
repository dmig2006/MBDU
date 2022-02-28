/****************************************************************************
** Meta object code from reading C++ file 'targeteditor_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/targeteditor_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'targeteditor_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TargetEditorDialog_t {
    QByteArrayData data[13];
    char stringdata0[359];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TargetEditorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TargetEditorDialog_t qt_meta_stringdata_TargetEditorDialog = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TargetEditorDialog"
QT_MOC_LITERAL(1, 19, 23), // "on_apply_Button_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 23), // "on_close_Button_clicked"
QT_MOC_LITERAL(4, 68, 33), // "on_choose_activate_Button_cli..."
QT_MOC_LITERAL(5, 102, 36), // "on_choose_no_activate_Button_..."
QT_MOC_LITERAL(6, 139, 35), // "on_activate_selected_Button_c..."
QT_MOC_LITERAL(7, 175, 30), // "on_activate_all_Button_clicked"
QT_MOC_LITERAL(8, 206, 30), // "on_deactive_all_Button_clicked"
QT_MOC_LITERAL(9, 237, 33), // "on_remove_selected_Button_cli..."
QT_MOC_LITERAL(10, 271, 28), // "on_remove_all_Button_clicked"
QT_MOC_LITERAL(11, 300, 36), // "on_deactivate_selecte_Button_..."
QT_MOC_LITERAL(12, 337, 21) // "on_listWidget_clicked"

    },
    "TargetEditorDialog\0on_apply_Button_clicked\0"
    "\0on_close_Button_clicked\0"
    "on_choose_activate_Button_clicked\0"
    "on_choose_no_activate_Button_clicked\0"
    "on_activate_selected_Button_clicked\0"
    "on_activate_all_Button_clicked\0"
    "on_deactive_all_Button_clicked\0"
    "on_remove_selected_Button_clicked\0"
    "on_remove_all_Button_clicked\0"
    "on_deactivate_selecte_Button_clicked\0"
    "on_listWidget_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TargetEditorDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x09 /* Protected */,
       3,    0,   70,    2, 0x09 /* Protected */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void TargetEditorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TargetEditorDialog *_t = static_cast<TargetEditorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_apply_Button_clicked(); break;
        case 1: _t->on_close_Button_clicked(); break;
        case 2: _t->on_choose_activate_Button_clicked(); break;
        case 3: _t->on_choose_no_activate_Button_clicked(); break;
        case 4: _t->on_activate_selected_Button_clicked(); break;
        case 5: _t->on_activate_all_Button_clicked(); break;
        case 6: _t->on_deactive_all_Button_clicked(); break;
        case 7: _t->on_remove_selected_Button_clicked(); break;
        case 8: _t->on_remove_all_Button_clicked(); break;
        case 9: _t->on_deactivate_selecte_Button_clicked(); break;
        case 10: _t->on_listWidget_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TargetEditorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TargetEditorDialog.data,
      qt_meta_data_TargetEditorDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TargetEditorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TargetEditorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TargetEditorDialog.stringdata0))
        return static_cast<void*>(const_cast< TargetEditorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TargetEditorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
