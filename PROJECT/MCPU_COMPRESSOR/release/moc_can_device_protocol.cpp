/****************************************************************************
** Meta object code from reading C++ file 'can_device_protocol.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MCPU_SHARED_MODULES/MODULES/CAN_DEVICE_PROTOCOL/can_device_protocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'can_device_protocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_canDeviceProtocol_t {
    const uint offsetsAndSize[20];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_canDeviceProtocol_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_canDeviceProtocol_t qt_meta_stringdata_canDeviceProtocol = {
    {
QT_MOC_LITERAL(0, 17), // "canDeviceProtocol"
QT_MOC_LITERAL(18, 13), // "txToDeviceCan"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 5), // "canId"
QT_MOC_LITERAL(39, 4), // "data"
QT_MOC_LITERAL(44, 25), // "dataReceivedFromDeviceCan"
QT_MOC_LITERAL(70, 15), // "rxFromDeviceCan"
QT_MOC_LITERAL(86, 14), // "deviceTmoEvent"
QT_MOC_LITERAL(101, 25), // "canDriverConnectionStatus"
QT_MOC_LITERAL(127, 6) // "status"

    },
    "canDeviceProtocol\0txToDeviceCan\0\0canId\0"
    "data\0dataReceivedFromDeviceCan\0"
    "rxFromDeviceCan\0deviceTmoEvent\0"
    "canDriverConnectionStatus\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canDeviceProtocol[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x06,    1 /* Public */,
       5,    2,   49,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   54,    2, 0x08,    7 /* Private */,
       7,    0,   59,    2, 0x08,   10 /* Private */,
       8,    1,   60,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void canDeviceProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<canDeviceProtocol *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->txToDeviceCan((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->dataReceivedFromDeviceCan((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->rxFromDeviceCan((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 3: _t->deviceTmoEvent(); break;
        case 4: _t->canDriverConnectionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (canDeviceProtocol::*)(ushort , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canDeviceProtocol::txToDeviceCan)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (canDeviceProtocol::*)(ushort , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canDeviceProtocol::dataReceivedFromDeviceCan)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject canDeviceProtocol::staticMetaObject = { {
    QMetaObject::SuperData::link<canBootloaderProtocol::staticMetaObject>(),
    qt_meta_stringdata_canDeviceProtocol.offsetsAndSize,
    qt_meta_data_canDeviceProtocol,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_canDeviceProtocol_t
, QtPrivate::TypeAndForceComplete<canDeviceProtocol, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *canDeviceProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canDeviceProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_canDeviceProtocol.stringdata0))
        return static_cast<void*>(this);
    return canBootloaderProtocol::qt_metacast(_clname);
}

int canDeviceProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = canBootloaderProtocol::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void canDeviceProtocol::txToDeviceCan(ushort _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canDeviceProtocol::dataReceivedFromDeviceCan(ushort _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
