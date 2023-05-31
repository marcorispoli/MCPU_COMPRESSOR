/****************************************************************************
** Meta object code from reading C++ file 'can_bootloader_protocol.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MCPU_SHARED_MODULES/MODULES/CAN_DEVICE_PROTOCOL/can_bootloader_protocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'can_bootloader_protocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_canBootloaderProtocol_t {
    const uint offsetsAndSize[16];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_canBootloaderProtocol_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_canBootloaderProtocol_t qt_meta_stringdata_canBootloaderProtocol = {
    {
QT_MOC_LITERAL(0, 21), // "canBootloaderProtocol"
QT_MOC_LITERAL(22, 14), // "txToBootloader"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 5), // "canId"
QT_MOC_LITERAL(44, 4), // "data"
QT_MOC_LITERAL(49, 29), // "dataReceivedFromBootloaderCan"
QT_MOC_LITERAL(79, 16), // "rxFromBootloader"
QT_MOC_LITERAL(96, 18) // "bootloaderTmoEvent"

    },
    "canBootloaderProtocol\0txToBootloader\0"
    "\0canId\0data\0dataReceivedFromBootloaderCan\0"
    "rxFromBootloader\0bootloaderTmoEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canBootloaderProtocol[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,
       5,    2,   43,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,   48,    2, 0x08,    7 /* Private */,
       7,    0,   53,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    4,
    QMetaType::Void,

       0        // eod
};

void canBootloaderProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<canBootloaderProtocol *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->txToBootloader((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->dataReceivedFromBootloaderCan((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->rxFromBootloader((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 3: _t->bootloaderTmoEvent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (canBootloaderProtocol::*)(ushort , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canBootloaderProtocol::txToBootloader)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (canBootloaderProtocol::*)(ushort , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canBootloaderProtocol::dataReceivedFromBootloaderCan)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject canBootloaderProtocol::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_canBootloaderProtocol.offsetsAndSize,
    qt_meta_data_canBootloaderProtocol,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_canBootloaderProtocol_t
, QtPrivate::TypeAndForceComplete<canBootloaderProtocol, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *canBootloaderProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canBootloaderProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_canBootloaderProtocol.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int canBootloaderProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void canBootloaderProtocol::txToBootloader(ushort _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canBootloaderProtocol::dataReceivedFromBootloaderCan(ushort _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
