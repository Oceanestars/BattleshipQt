/****************************************************************************
** Meta object code from reading C++ file 'cell.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../finalproject/cell.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cell.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cell_t {
    QByteArrayData data[11];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cell_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cell_t qt_meta_stringdata_Cell = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Cell"
QT_MOC_LITERAL(1, 5, 8), // "increase"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 8), // "decrease"
QT_MOC_LITERAL(4, 24, 9), // "neighbors"
QT_MOC_LITERAL(5, 34, 1), // "x"
QT_MOC_LITERAL(6, 36, 1), // "y"
QT_MOC_LITERAL(7, 38, 3), // "bom"
QT_MOC_LITERAL(8, 42, 5), // "Cell*"
QT_MOC_LITERAL(9, 48, 12), // "scorechanger"
QT_MOC_LITERAL(10, 61, 1) // "p"

    },
    "Cell\0increase\0\0decrease\0neighbors\0x\0"
    "y\0bom\0Cell*\0scorechanger\0p"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cell[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    2,   41,    2, 0x06 /* Public */,
       7,    1,   46,    2, 0x06 /* Public */,
       9,    1,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,   10,

       0        // eod
};

void Cell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cell *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->increase(); break;
        case 1: _t->decrease(); break;
        case 2: _t->neighbors((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->bom((*reinterpret_cast< Cell*(*)>(_a[1]))); break;
        case 4: _t->scorechanger((*reinterpret_cast< Cell*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Cell* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Cell* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cell::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::increase)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cell::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::decrease)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Cell::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::neighbors)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Cell::*)(Cell * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::bom)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Cell::*)(Cell * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::scorechanger)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cell::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Cell.data,
    qt_meta_data_Cell,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cell::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cell.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Cell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Cell::increase()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cell::decrease()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Cell::neighbors(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Cell::bom(Cell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Cell::scorechanger(Cell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
