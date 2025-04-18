/****************************************************************************
** Meta object code from reading C++ file 'smtpclient.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/smtpclient.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'smtpclient.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10SmtpClientE_t {};
} // unnamed namespace

template <> constexpr inline auto SmtpClient::qt_create_metaobjectdata<qt_meta_tag_ZN10SmtpClientE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SmtpClient",
        "error",
        "",
        "SmtpClient::SmtpError",
        "e",
        "stateChanged",
        "SmtpClient::ClientState",
        "s",
        "connected",
        "readyConnected",
        "authenticated",
        "mailSent",
        "mailReset",
        "disconnected",
        "socketStateChanged",
        "QAbstractSocket::SocketState",
        "state",
        "socketError",
        "QAbstractSocket::SocketError",
        "socketReadyRead",
        "socketEncrypted",
        "AuthMethod",
        "AuthPlain",
        "AuthLogin",
        "SmtpError",
        "ConnectionTimeoutError",
        "ResponseTimeoutError",
        "AuthenticationError",
        "MailSendingError",
        "ServerError",
        "ClientError",
        "SocketError",
        "ConnectionType",
        "TcpConnection",
        "SslConnection",
        "TlsConnection",
        "ClientState",
        "UnconnectedState",
        "ConnectingState",
        "ConnectedState",
        "ReadyState",
        "AuthenticatingState",
        "MailSendingState",
        "DisconnectingState",
        "ResetState",
        "_EHLO_State",
        "_TLS_State",
        "_READY_Connected",
        "_READY_Authenticated",
        "_READY_MailSent",
        "_READY_Encrypted",
        "_QUITTING_State",
        "_TLS_0_STARTTLS",
        "_TLS_1_ENCRYPT",
        "_TLS_2_EHLO",
        "_AUTH_PLAIN_0",
        "_AUTH_LOGIN_0",
        "_AUTH_LOGIN_1_USER",
        "_AUTH_LOGIN_2_PASS",
        "_MAIL_0_FROM",
        "_MAIL_1_RCPT_INIT",
        "_MAIL_2_RCPT",
        "_MAIL_3_DATA",
        "_MAIL_4_SEND_DATA"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'error'
        QtMocHelpers::SignalData<void(SmtpClient::SmtpError)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(SmtpClient::ClientState)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'connected'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'readyConnected'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'authenticated'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'mailSent'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'mailReset'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'disconnected'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'socketStateChanged'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketState)>(14, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Slot 'socketError'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(17, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 18, 1 },
        }}),
        // Slot 'socketReadyRead'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'socketEncrypted'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessProtected, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'AuthMethod'
        QtMocHelpers::EnumData<AuthMethod>(21, 21, QMC::EnumFlags{}).add({
            {   22, AuthMethod::AuthPlain },
            {   23, AuthMethod::AuthLogin },
        }),
        // enum 'SmtpError'
        QtMocHelpers::EnumData<SmtpError>(24, 24, QMC::EnumFlags{}).add({
            {   25, SmtpError::ConnectionTimeoutError },
            {   26, SmtpError::ResponseTimeoutError },
            {   27, SmtpError::AuthenticationError },
            {   28, SmtpError::MailSendingError },
            {   29, SmtpError::ServerError },
            {   30, SmtpError::ClientError },
            {   31, SmtpError::SocketError },
        }),
        // enum 'ConnectionType'
        QtMocHelpers::EnumData<ConnectionType>(32, 32, QMC::EnumFlags{}).add({
            {   33, ConnectionType::TcpConnection },
            {   34, ConnectionType::SslConnection },
            {   35, ConnectionType::TlsConnection },
        }),
        // enum 'ClientState'
        QtMocHelpers::EnumData<ClientState>(36, 36, QMC::EnumFlags{}).add({
            {   37, ClientState::UnconnectedState },
            {   38, ClientState::ConnectingState },
            {   39, ClientState::ConnectedState },
            {   40, ClientState::ReadyState },
            {   41, ClientState::AuthenticatingState },
            {   42, ClientState::MailSendingState },
            {   43, ClientState::DisconnectingState },
            {   44, ClientState::ResetState },
            {   45, ClientState::_EHLO_State },
            {   46, ClientState::_TLS_State },
            {   47, ClientState::_READY_Connected },
            {   48, ClientState::_READY_Authenticated },
            {   49, ClientState::_READY_MailSent },
            {   50, ClientState::_READY_Encrypted },
            {   51, ClientState::_QUITTING_State },
            {   52, ClientState::_TLS_0_STARTTLS },
            {   53, ClientState::_TLS_1_ENCRYPT },
            {   54, ClientState::_TLS_2_EHLO },
            {   55, ClientState::_AUTH_PLAIN_0 },
            {   56, ClientState::_AUTH_LOGIN_0 },
            {   57, ClientState::_AUTH_LOGIN_1_USER },
            {   58, ClientState::_AUTH_LOGIN_2_PASS },
            {   59, ClientState::_MAIL_0_FROM },
            {   60, ClientState::_MAIL_1_RCPT_INIT },
            {   61, ClientState::_MAIL_2_RCPT },
            {   62, ClientState::_MAIL_3_DATA },
            {   63, ClientState::_MAIL_4_SEND_DATA },
        }),
    };
    return QtMocHelpers::metaObjectData<SmtpClient, qt_meta_tag_ZN10SmtpClientE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SmtpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10SmtpClientE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10SmtpClientE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10SmtpClientE_t>.metaTypes,
    nullptr
} };

void SmtpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SmtpClient *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< std::add_pointer_t<SmtpClient::SmtpError>>(_a[1]))); break;
        case 1: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<SmtpClient::ClientState>>(_a[1]))); break;
        case 2: _t->connected(); break;
        case 3: _t->readyConnected(); break;
        case 4: _t->authenticated(); break;
        case 5: _t->mailSent(); break;
        case 6: _t->mailReset(); break;
        case 7: _t->disconnected(); break;
        case 8: _t->socketStateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 9: _t->socketError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 10: _t->socketReadyRead(); break;
        case 11: _t->socketEncrypted(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SmtpClient::*)(SmtpClient::SmtpError )>(_a, &SmtpClient::error, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmtpClient::*)(SmtpClient::ClientState )>(_a, &SmtpClient::stateChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmtpClient::*)()>(_a, &SmtpClient::connected, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmtpClient::*)()>(_a, &SmtpClient::readyConnected, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmtpClient::*)()>(_a, &SmtpClient::authenticated, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmtpClient::*)()>(_a, &SmtpClient::mailSent, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmtpClient::*)()>(_a, &SmtpClient::mailReset, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmtpClient::*)()>(_a, &SmtpClient::disconnected, 7))
            return;
    }
}

const QMetaObject *SmtpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmtpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10SmtpClientE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SmtpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SmtpClient::error(SmtpClient::SmtpError _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SmtpClient::stateChanged(SmtpClient::ClientState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void SmtpClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SmtpClient::readyConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SmtpClient::authenticated()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SmtpClient::mailSent()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SmtpClient::mailReset()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SmtpClient::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
