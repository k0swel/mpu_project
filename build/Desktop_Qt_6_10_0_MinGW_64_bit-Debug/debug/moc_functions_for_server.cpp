/****************************************************************************
** Meta object code from reading C++ file 'functions_for_server.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../functions_for_server.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'functions_for_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN20functions_for_serverE_t {};
} // unnamed namespace

template <> constexpr inline auto functions_for_server::qt_create_metaobjectdata<qt_meta_tag_ZN20functions_for_serverE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "functions_for_server",
        "register_ok",
        "",
        "register_error",
        "auth_ok",
        "auth_error",
        "signal_equation_solution",
        "slot_register_new_account",
        "login",
        "password",
        "email",
        "date_of_birthday",
        "last_name",
        "first_name",
        "middle_name",
        "slot_auth",
        "slot_send_code",
        "code",
        "slot_new_password",
        "slot_linear_equation",
        "a",
        "b",
        "slot_quadratic_equation",
        "c"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'register_ok'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'register_error'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'auth_ok'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'auth_error'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signal_equation_solution'
        QtMocHelpers::SignalData<void(QString)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'slot_register_new_account'
        QtMocHelpers::SlotData<void(QString, QString, QString, QString, QString, QString, QString)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 }, { QMetaType::QString, 9 }, { QMetaType::QString, 10 }, { QMetaType::QString, 11 },
            { QMetaType::QString, 12 }, { QMetaType::QString, 13 }, { QMetaType::QString, 14 },
        }}),
        // Slot 'slot_auth'
        QtMocHelpers::SlotData<void(QString, QString)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 }, { QMetaType::QString, 9 },
        }}),
        // Slot 'slot_send_code'
        QtMocHelpers::SlotData<void(QString, QString)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { QMetaType::QString, 17 },
        }}),
        // Slot 'slot_new_password'
        QtMocHelpers::SlotData<void(QString, QString)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { QMetaType::QString, 9 },
        }}),
        // Slot 'slot_linear_equation'
        QtMocHelpers::SlotData<void(QString, QString)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 20 }, { QMetaType::QString, 21 },
        }}),
        // Slot 'slot_quadratic_equation'
        QtMocHelpers::SlotData<void(QString, QString, QString)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 20 }, { QMetaType::QString, 21 }, { QMetaType::QString, 23 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<functions_for_server, qt_meta_tag_ZN20functions_for_serverE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject functions_for_server::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20functions_for_serverE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20functions_for_serverE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20functions_for_serverE_t>.metaTypes,
    nullptr
} };

void functions_for_server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<functions_for_server *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->register_ok(); break;
        case 1: _t->register_error(); break;
        case 2: _t->auth_ok(); break;
        case 3: _t->auth_error(); break;
        case 4: _t->signal_equation_solution((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->slot_register_new_account((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7]))); break;
        case 6: _t->slot_auth((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->slot_send_code((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->slot_new_password((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->slot_linear_equation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 10: _t->slot_quadratic_equation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (functions_for_server::*)()>(_a, &functions_for_server::register_ok, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (functions_for_server::*)()>(_a, &functions_for_server::register_error, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (functions_for_server::*)()>(_a, &functions_for_server::auth_ok, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (functions_for_server::*)()>(_a, &functions_for_server::auth_error, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (functions_for_server::*)(QString )>(_a, &functions_for_server::signal_equation_solution, 4))
            return;
    }
}

const QMetaObject *functions_for_server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *functions_for_server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20functions_for_serverE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int functions_for_server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void functions_for_server::register_ok()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void functions_for_server::register_error()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void functions_for_server::auth_ok()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void functions_for_server::auth_error()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void functions_for_server::signal_equation_solution(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
