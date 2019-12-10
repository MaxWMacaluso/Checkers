/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HW5/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "SLeftClickSlot"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "Square*"
QT_MOC_LITERAL(4, 35, 5), // "click"
QT_MOC_LITERAL(5, 41, 15), // "SRightClickSlot"
QT_MOC_LITERAL(6, 57, 8), // "TakeTurn"
QT_MOC_LITERAL(7, 66, 7), // "move_to"
QT_MOC_LITERAL(8, 74, 9), // "MovePiece"
QT_MOC_LITERAL(9, 84, 6), // "Piece*"
QT_MOC_LITERAL(10, 91, 11), // "TeamXPieces"
QT_MOC_LITERAL(11, 103, 14), // "vector<Piece*>"
QT_MOC_LITERAL(12, 118, 4), // "team"
QT_MOC_LITERAL(13, 123, 9), // "MakeBoard"
QT_MOC_LITERAL(14, 133, 7), // "Recolor"
QT_MOC_LITERAL(15, 141, 12), // "makeBarChart"
QT_MOC_LITERAL(16, 154, 14), // "PLeftClickSlot"
QT_MOC_LITERAL(17, 169, 15), // "PRightClickSlot"
QT_MOC_LITERAL(18, 185, 18), // "on_newGame_clicked"
QT_MOC_LITERAL(19, 204, 18), // "on_P1Human_clicked"
QT_MOC_LITERAL(20, 223, 17), // "on_P1Comp_clicked"
QT_MOC_LITERAL(21, 241, 18), // "on_P2Human_clicked"
QT_MOC_LITERAL(22, 260, 17) // "on_P2Comp_clicked"

    },
    "MainWindow\0SLeftClickSlot\0\0Square*\0"
    "click\0SRightClickSlot\0TakeTurn\0move_to\0"
    "MovePiece\0Piece*\0TeamXPieces\0"
    "vector<Piece*>\0team\0MakeBoard\0Recolor\0"
    "makeBarChart\0PLeftClickSlot\0PRightClickSlot\0"
    "on_newGame_clicked\0on_P1Human_clicked\0"
    "on_P1Comp_clicked\0on_P2Human_clicked\0"
    "on_P2Comp_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x0a /* Public */,
       5,    1,   92,    2, 0x0a /* Public */,
       6,    1,   95,    2, 0x0a /* Public */,
       8,    2,   98,    2, 0x0a /* Public */,
      10,    1,  103,    2, 0x0a /* Public */,
      13,    0,  106,    2, 0x0a /* Public */,
      14,    0,  107,    2, 0x0a /* Public */,
      15,    0,  108,    2, 0x0a /* Public */,
      16,    1,  109,    2, 0x0a /* Public */,
      17,    1,  112,    2, 0x0a /* Public */,
      18,    0,  115,    2, 0x08 /* Private */,
      19,    0,  116,    2, 0x08 /* Private */,
      20,    0,  117,    2, 0x08 /* Private */,
      21,    0,  118,    2, 0x08 /* Private */,
      22,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    7,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 3,    4,    7,
    0x80000000 | 11, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    4,
    QMetaType::Void, 0x80000000 | 9,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SLeftClickSlot((*reinterpret_cast< Square*(*)>(_a[1]))); break;
        case 1: _t->SRightClickSlot((*reinterpret_cast< Square*(*)>(_a[1]))); break;
        case 2: _t->TakeTurn((*reinterpret_cast< Square*(*)>(_a[1]))); break;
        case 3: _t->MovePiece((*reinterpret_cast< Piece*(*)>(_a[1])),(*reinterpret_cast< Square*(*)>(_a[2]))); break;
        case 4: { vector<Piece*> _r = _t->TeamXPieces((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<Piece*>*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->MakeBoard(); break;
        case 6: _t->Recolor(); break;
        case 7: _t->makeBarChart(); break;
        case 8: _t->PLeftClickSlot((*reinterpret_cast< Piece*(*)>(_a[1]))); break;
        case 9: _t->PRightClickSlot((*reinterpret_cast< Piece*(*)>(_a[1]))); break;
        case 10: _t->on_newGame_clicked(); break;
        case 11: _t->on_P1Human_clicked(); break;
        case 12: _t->on_P1Comp_clicked(); break;
        case 13: _t->on_P2Human_clicked(); break;
        case 14: _t->on_P2Comp_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Square* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Square* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Square* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Piece* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Square* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Piece* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Piece* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
