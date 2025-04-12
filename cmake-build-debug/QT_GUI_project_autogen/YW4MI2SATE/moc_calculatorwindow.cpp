/****************************************************************************
** Meta object code from reading C++ file 'calculatorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../new/calculatorwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculatorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_CalculatorWindow_t {
    uint offsetsAndSizes[16];
    char stringdata0[17];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[14];
    char stringdata5[13];
    char stringdata6[20];
    char stringdata7[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CalculatorWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CalculatorWindow_t qt_meta_stringdata_CalculatorWindow = {
    {
        QT_MOC_LITERAL(0, 16),  // "CalculatorWindow"
        QT_MOC_LITERAL(17, 12),  // "digitClicked"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 15),  // "operatorClicked"
        QT_MOC_LITERAL(47, 13),  // "equalsClicked"
        QT_MOC_LITERAL(61, 12),  // "clearClicked"
        QT_MOC_LITERAL(74, 19),  // "secondButtonClicked"
        QT_MOC_LITERAL(94, 16)   // "oneButtonClicked"
    },
    "CalculatorWindow",
    "digitClicked",
    "",
    "operatorClicked",
    "equalsClicked",
    "clearClicked",
    "secondButtonClicked",
    "oneButtonClicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CalculatorWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CalculatorWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CalculatorWindow.offsetsAndSizes,
    qt_meta_data_CalculatorWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CalculatorWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CalculatorWindow, std::true_type>,
        // method 'digitClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'operatorClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'equalsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'secondButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'oneButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CalculatorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalculatorWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->digitClicked(); break;
        case 1: _t->operatorClicked(); break;
        case 2: _t->equalsClicked(); break;
        case 3: _t->clearClicked(); break;
        case 4: _t->secondButtonClicked(); break;
        case 5: _t->oneButtonClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *CalculatorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculatorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatorWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CalculatorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
