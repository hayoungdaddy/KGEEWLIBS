/****************************************************************************
** Meta object code from reading C++ file 'kgeewlibs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "kgeewlibs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kgeewlibs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RecvQSCD20Message_t {
    QByteArrayData data[4];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecvQSCD20Message_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecvQSCD20Message_t qt_meta_stringdata_RecvQSCD20Message = {
    {
QT_MOC_LITERAL(0, 0, 17), // "RecvQSCD20Message"
QT_MOC_LITERAL(1, 18, 14), // "sendQSCDtoMain"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 33) // "QMultiMap<int,_QSCD_FOR_MULTI..."

    },
    "RecvQSCD20Message\0sendQSCDtoMain\0\0"
    "QMultiMap<int,_QSCD_FOR_MULTIMAP>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecvQSCD20Message[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void RecvQSCD20Message::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RecvQSCD20Message *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendQSCDtoMain((*reinterpret_cast< QMultiMap<int,_QSCD_FOR_MULTIMAP>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RecvQSCD20Message::*)(QMultiMap<int,_QSCD_FOR_MULTIMAP> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecvQSCD20Message::sendQSCDtoMain)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RecvQSCD20Message::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_RecvQSCD20Message.data,
    qt_meta_data_RecvQSCD20Message,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RecvQSCD20Message::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecvQSCD20Message::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RecvQSCD20Message.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int RecvQSCD20Message::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void RecvQSCD20Message::sendQSCDtoMain(QMultiMap<int,_QSCD_FOR_MULTIMAP> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_RecvQSCD100Message_t {
    QByteArrayData data[4];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecvQSCD100Message_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecvQSCD100Message_t qt_meta_stringdata_RecvQSCD100Message = {
    {
QT_MOC_LITERAL(0, 0, 18), // "RecvQSCD100Message"
QT_MOC_LITERAL(1, 19, 14), // "sendQSCDtoMain"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 33) // "QMultiMap<int,_QSCD_FOR_MULTI..."

    },
    "RecvQSCD100Message\0sendQSCDtoMain\0\0"
    "QMultiMap<int,_QSCD_FOR_MULTIMAP>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecvQSCD100Message[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void RecvQSCD100Message::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RecvQSCD100Message *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendQSCDtoMain((*reinterpret_cast< QMultiMap<int,_QSCD_FOR_MULTIMAP>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RecvQSCD100Message::*)(QMultiMap<int,_QSCD_FOR_MULTIMAP> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecvQSCD100Message::sendQSCDtoMain)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RecvQSCD100Message::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_RecvQSCD100Message.data,
    qt_meta_data_RecvQSCD100Message,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RecvQSCD100Message::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecvQSCD100Message::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RecvQSCD100Message.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int RecvQSCD100Message::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void RecvQSCD100Message::sendQSCDtoMain(QMultiMap<int,_QSCD_FOR_MULTIMAP> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_RecvEEWMessage_t {
    QByteArrayData data[4];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecvEEWMessage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecvEEWMessage_t qt_meta_stringdata_RecvEEWMessage = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RecvEEWMessage"
QT_MOC_LITERAL(1, 15, 10), // "_rvEEWInfo"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8) // "_EEWINFO"

    },
    "RecvEEWMessage\0_rvEEWInfo\0\0_EEWINFO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecvEEWMessage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void RecvEEWMessage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RecvEEWMessage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->_rvEEWInfo((*reinterpret_cast< _EEWINFO(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RecvEEWMessage::*)(_EEWINFO );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecvEEWMessage::_rvEEWInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RecvEEWMessage::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_RecvEEWMessage.data,
    qt_meta_data_RecvEEWMessage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RecvEEWMessage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecvEEWMessage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RecvEEWMessage.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int RecvEEWMessage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void RecvEEWMessage::_rvEEWInfo(_EEWINFO _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
