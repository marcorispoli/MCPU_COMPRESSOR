/****************************************************************************
** Meta object code from reading C++ file 'canclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MCPU_SHARED_MODULES/MODULES/CAN_CLIENT/canclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_canClient_t {
    const uint offsetsAndSize[32];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_canClient_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_canClient_t qt_meta_stringdata_canClient = {
    {
QT_MOC_LITERAL(0, 9), // "canClient"
QT_MOC_LITERAL(10, 9), // "rxFromCan"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 5), // "canId"
QT_MOC_LITERAL(27, 4), // "data"
QT_MOC_LITERAL(32, 14), // "rxAsyncFromCan"
QT_MOC_LITERAL(47, 25), // "canDriverConnectionStatus"
QT_MOC_LITERAL(73, 6), // "status"
QT_MOC_LITERAL(80, 11), // "txToCanData"
QT_MOC_LITERAL(92, 12), // "socketRxData"
QT_MOC_LITERAL(105, 11), // "socketError"
QT_MOC_LITERAL(117, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(146, 5), // "error"
QT_MOC_LITERAL(152, 15), // "socketConnected"
QT_MOC_LITERAL(168, 18), // "socketDisconnected"
QT_MOC_LITERAL(187, 19) // "setAcceptanceFilter"

    },
    "canClient\0rxFromCan\0\0canId\0data\0"
    "rxAsyncFromCan\0canDriverConnectionStatus\0"
    "status\0txToCanData\0socketRxData\0"
    "socketError\0QAbstractSocket::SocketError\0"
    "error\0socketConnected\0socketDisconnected\0"
    "setAcceptanceFilter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_canClient[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    1 /* Public */,
       5,    2,   73,    2, 0x06,    4 /* Public */,
       6,    1,   78,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   81,    2, 0x0a,    9 /* Public */,
       9,    0,   86,    2, 0x08,   12 /* Private */,
      10,    1,   87,    2, 0x08,   13 /* Private */,
      13,    0,   90,    2, 0x08,   15 /* Private */,
      14,    0,   91,    2, 0x08,   16 /* Private */,
      15,    0,   92,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::QByteArray,    3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void canClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<canClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rxFromCan((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->rxAsyncFromCan((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->canDriverConnectionStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->txToCanData((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 4: _t->socketRxData(); break;
        case 5: _t->socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->socketConnected(); break;
        case 7: _t->socketDisconnected(); break;
        case 8: _t->setAcceptanceFilter(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (canClient::*)(ushort , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canClient::rxFromCan)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (canClient::*)(ushort , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canClient::rxAsyncFromCan)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (canClient::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&canClient::canDriverConnectionStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject canClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_canClient.offsetsAndSize,
    qt_meta_data_canClient,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_canClient_t
, QtPrivate::TypeAndForceComplete<canClient, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ushort, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *canClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *canClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_canClient.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int canClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void canClient::rxFromCan(ushort _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void canClient::rxAsyncFromCan(ushort _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void canClient::canDriverConnectionStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
