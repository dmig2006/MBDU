/****************************************************************************
** Meta object code from reading C++ file 'tracking_zala.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/tracking_zala.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tracking_zala.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrackingZala_t {
    QByteArrayData data[25];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrackingZala_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrackingZala_t qt_meta_stringdata_TrackingZala = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TrackingZala"
QT_MOC_LITERAL(1, 13, 9), // "newLogMsg"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "pString"
QT_MOC_LITERAL(4, 32, 14), // "move_Ac_Target"
QT_MOC_LITERAL(5, 47, 1), // "x"
QT_MOC_LITERAL(6, 49, 1), // "y"
QT_MOC_LITERAL(7, 51, 15), // "setCameraModeAC"
QT_MOC_LITERAL(8, 67, 10), // "CameraMode"
QT_MOC_LITERAL(9, 78, 11), // "pCameraMode"
QT_MOC_LITERAL(10, 90, 11), // "ac_Joystick"
QT_MOC_LITERAL(11, 102, 11), // "AC_Joystick"
QT_MOC_LITERAL(12, 114, 7), // "readVPx"
QT_MOC_LITERAL(13, 122, 2), // "pv"
QT_MOC_LITERAL(14, 125, 7), // "readVPy"
QT_MOC_LITERAL(15, 133, 12), // "acRamkaFreez"
QT_MOC_LITERAL(16, 146, 4), // "move"
QT_MOC_LITERAL(17, 151, 14), // "getKoordinatAc"
QT_MOC_LITERAL(18, 166, 10), // "can_frame*"
QT_MOC_LITERAL(19, 177, 5), // "frame"
QT_MOC_LITERAL(20, 183, 15), // "filterIndikator"
QT_MOC_LITERAL(21, 199, 12), // "time_indi_ac"
QT_MOC_LITERAL(22, 212, 10), // "setAimType"
QT_MOC_LITERAL(23, 223, 7), // "AimType"
QT_MOC_LITERAL(24, 231, 8) // "pAimtype"

    },
    "TrackingZala\0newLogMsg\0\0pString\0"
    "move_Ac_Target\0x\0y\0setCameraModeAC\0"
    "CameraMode\0pCameraMode\0ac_Joystick\0"
    "AC_Joystick\0readVPx\0pv\0readVPy\0"
    "acRamkaFreez\0move\0getKoordinatAc\0"
    "can_frame*\0frame\0filterIndikator\0"
    "time_indi_ac\0setAimType\0AimType\0"
    "pAimtype"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrackingZala[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   77,    2, 0x0a /* Public */,
       7,    1,   82,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,
      17,    1,   96,    2, 0x08 /* Private */,
      20,    0,   99,    2, 0x08 /* Private */,
      21,    0,  100,    2, 0x08 /* Private */,
      22,    1,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Long, QMetaType::Long,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   13,
    QMetaType::Void, QMetaType::Float,   13,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,

       0        // eod
};

void TrackingZala::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrackingZala *_t = static_cast<TrackingZala *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newLogMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->move_Ac_Target((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 2: _t->setCameraModeAC((*reinterpret_cast< CameraMode(*)>(_a[1]))); break;
        case 3: _t->ac_Joystick(); break;
        case 4: _t->AC_Joystick(); break;
        case 5: _t->readVPx((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->readVPy((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: _t->acRamkaFreez((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->getKoordinatAc((*reinterpret_cast< can_frame*(*)>(_a[1]))); break;
        case 9: _t->filterIndikator(); break;
        case 10: _t->time_indi_ac(); break;
        case 11: _t->setAimType((*reinterpret_cast< AimType(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TrackingZala::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TrackingZala::newLogMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TrackingZala::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TrackingZala.data,
      qt_meta_data_TrackingZala,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TrackingZala::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrackingZala::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TrackingZala.stringdata0))
        return static_cast<void*>(const_cast< TrackingZala*>(this));
    return QThread::qt_metacast(_clname);
}

int TrackingZala::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TrackingZala::newLogMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
