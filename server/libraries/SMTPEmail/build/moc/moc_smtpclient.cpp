/****************************************************************************
** Meta object code from reading C++ file 'smtpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/smtpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'smtpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SmtpClient_t {
    QByteArrayData data[64];
    char stringdata0[926];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SmtpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SmtpClient_t qt_meta_stringdata_SmtpClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SmtpClient"
QT_MOC_LITERAL(1, 11, 5), // "error"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 21), // "SmtpClient::SmtpError"
QT_MOC_LITERAL(4, 40, 1), // "e"
QT_MOC_LITERAL(5, 42, 12), // "stateChanged"
QT_MOC_LITERAL(6, 55, 23), // "SmtpClient::ClientState"
QT_MOC_LITERAL(7, 79, 1), // "s"
QT_MOC_LITERAL(8, 81, 9), // "connected"
QT_MOC_LITERAL(9, 91, 14), // "readyConnected"
QT_MOC_LITERAL(10, 106, 13), // "authenticated"
QT_MOC_LITERAL(11, 120, 8), // "mailSent"
QT_MOC_LITERAL(12, 129, 9), // "mailReset"
QT_MOC_LITERAL(13, 139, 12), // "disconnected"
QT_MOC_LITERAL(14, 152, 18), // "socketStateChanged"
QT_MOC_LITERAL(15, 171, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(16, 200, 5), // "state"
QT_MOC_LITERAL(17, 206, 11), // "socketError"
QT_MOC_LITERAL(18, 218, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(19, 247, 15), // "socketReadyRead"
QT_MOC_LITERAL(20, 263, 15), // "socketEncrypted"
QT_MOC_LITERAL(21, 279, 10), // "AuthMethod"
QT_MOC_LITERAL(22, 290, 9), // "AuthPlain"
QT_MOC_LITERAL(23, 300, 9), // "AuthLogin"
QT_MOC_LITERAL(24, 310, 9), // "SmtpError"
QT_MOC_LITERAL(25, 320, 22), // "ConnectionTimeoutError"
QT_MOC_LITERAL(26, 343, 20), // "ResponseTimeoutError"
QT_MOC_LITERAL(27, 364, 19), // "AuthenticationError"
QT_MOC_LITERAL(28, 384, 16), // "MailSendingError"
QT_MOC_LITERAL(29, 401, 11), // "ServerError"
QT_MOC_LITERAL(30, 413, 11), // "ClientError"
QT_MOC_LITERAL(31, 425, 11), // "SocketError"
QT_MOC_LITERAL(32, 437, 14), // "ConnectionType"
QT_MOC_LITERAL(33, 452, 13), // "TcpConnection"
QT_MOC_LITERAL(34, 466, 13), // "SslConnection"
QT_MOC_LITERAL(35, 480, 13), // "TlsConnection"
QT_MOC_LITERAL(36, 494, 11), // "ClientState"
QT_MOC_LITERAL(37, 506, 16), // "UnconnectedState"
QT_MOC_LITERAL(38, 523, 15), // "ConnectingState"
QT_MOC_LITERAL(39, 539, 14), // "ConnectedState"
QT_MOC_LITERAL(40, 554, 10), // "ReadyState"
QT_MOC_LITERAL(41, 565, 19), // "AuthenticatingState"
QT_MOC_LITERAL(42, 585, 16), // "MailSendingState"
QT_MOC_LITERAL(43, 602, 18), // "DisconnectingState"
QT_MOC_LITERAL(44, 621, 10), // "ResetState"
QT_MOC_LITERAL(45, 632, 11), // "_EHLO_State"
QT_MOC_LITERAL(46, 644, 10), // "_TLS_State"
QT_MOC_LITERAL(47, 655, 16), // "_READY_Connected"
QT_MOC_LITERAL(48, 672, 20), // "_READY_Authenticated"
QT_MOC_LITERAL(49, 693, 15), // "_READY_MailSent"
QT_MOC_LITERAL(50, 709, 16), // "_READY_Encrypted"
QT_MOC_LITERAL(51, 726, 15), // "_QUITTING_State"
QT_MOC_LITERAL(52, 742, 15), // "_TLS_0_STARTTLS"
QT_MOC_LITERAL(53, 758, 14), // "_TLS_1_ENCRYPT"
QT_MOC_LITERAL(54, 773, 11), // "_TLS_2_EHLO"
QT_MOC_LITERAL(55, 785, 13), // "_AUTH_PLAIN_0"
QT_MOC_LITERAL(56, 799, 13), // "_AUTH_LOGIN_0"
QT_MOC_LITERAL(57, 813, 18), // "_AUTH_LOGIN_1_USER"
QT_MOC_LITERAL(58, 832, 18), // "_AUTH_LOGIN_2_PASS"
QT_MOC_LITERAL(59, 851, 12), // "_MAIL_0_FROM"
QT_MOC_LITERAL(60, 864, 17), // "_MAIL_1_RCPT_INIT"
QT_MOC_LITERAL(61, 882, 12), // "_MAIL_2_RCPT"
QT_MOC_LITERAL(62, 895, 12), // "_MAIL_3_DATA"
QT_MOC_LITERAL(63, 908, 17) // "_MAIL_4_SEND_DATA"

    },
    "SmtpClient\0error\0\0SmtpClient::SmtpError\0"
    "e\0stateChanged\0SmtpClient::ClientState\0"
    "s\0connected\0readyConnected\0authenticated\0"
    "mailSent\0mailReset\0disconnected\0"
    "socketStateChanged\0QAbstractSocket::SocketState\0"
    "state\0socketError\0QAbstractSocket::SocketError\0"
    "socketReadyRead\0socketEncrypted\0"
    "AuthMethod\0AuthPlain\0AuthLogin\0SmtpError\0"
    "ConnectionTimeoutError\0ResponseTimeoutError\0"
    "AuthenticationError\0MailSendingError\0"
    "ServerError\0ClientError\0SocketError\0"
    "ConnectionType\0TcpConnection\0SslConnection\0"
    "TlsConnection\0ClientState\0UnconnectedState\0"
    "ConnectingState\0ConnectedState\0"
    "ReadyState\0AuthenticatingState\0"
    "MailSendingState\0DisconnectingState\0"
    "ResetState\0_EHLO_State\0_TLS_State\0"
    "_READY_Connected\0_READY_Authenticated\0"
    "_READY_MailSent\0_READY_Encrypted\0"
    "_QUITTING_State\0_TLS_0_STARTTLS\0"
    "_TLS_1_ENCRYPT\0_TLS_2_EHLO\0_AUTH_PLAIN_0\0"
    "_AUTH_LOGIN_0\0_AUTH_LOGIN_1_USER\0"
    "_AUTH_LOGIN_2_PASS\0_MAIL_0_FROM\0"
    "_MAIL_1_RCPT_INIT\0_MAIL_2_RCPT\0"
    "_MAIL_3_DATA\0_MAIL_4_SEND_DATA"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SmtpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       4,   94, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       8,    0,   80,    2, 0x06 /* Public */,
       9,    0,   81,    2, 0x06 /* Public */,
      10,    0,   82,    2, 0x06 /* Public */,
      11,    0,   83,    2, 0x06 /* Public */,
      12,    0,   84,    2, 0x06 /* Public */,
      13,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   86,    2, 0x09 /* Protected */,
      17,    1,   89,    2, 0x09 /* Protected */,
      19,    0,   92,    2, 0x09 /* Protected */,
      20,    0,   93,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,    1,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      21,   21, 0x0,    2,  114,
      24,   24, 0x0,    7,  118,
      32,   32, 0x0,    3,  132,
      36,   36, 0x0,   27,  138,

 // enum data: key, value
      22, uint(SmtpClient::AuthPlain),
      23, uint(SmtpClient::AuthLogin),
      25, uint(SmtpClient::ConnectionTimeoutError),
      26, uint(SmtpClient::ResponseTimeoutError),
      27, uint(SmtpClient::AuthenticationError),
      28, uint(SmtpClient::MailSendingError),
      29, uint(SmtpClient::ServerError),
      30, uint(SmtpClient::ClientError),
      31, uint(SmtpClient::SocketError),
      33, uint(SmtpClient::TcpConnection),
      34, uint(SmtpClient::SslConnection),
      35, uint(SmtpClient::TlsConnection),
      37, uint(SmtpClient::UnconnectedState),
      38, uint(SmtpClient::ConnectingState),
      39, uint(SmtpClient::ConnectedState),
      40, uint(SmtpClient::ReadyState),
      41, uint(SmtpClient::AuthenticatingState),
      42, uint(SmtpClient::MailSendingState),
      43, uint(SmtpClient::DisconnectingState),
      44, uint(SmtpClient::ResetState),
      45, uint(SmtpClient::_EHLO_State),
      46, uint(SmtpClient::_TLS_State),
      47, uint(SmtpClient::_READY_Connected),
      48, uint(SmtpClient::_READY_Authenticated),
      49, uint(SmtpClient::_READY_MailSent),
      50, uint(SmtpClient::_READY_Encrypted),
      51, uint(SmtpClient::_QUITTING_State),
      52, uint(SmtpClient::_TLS_0_STARTTLS),
      53, uint(SmtpClient::_TLS_1_ENCRYPT),
      54, uint(SmtpClient::_TLS_2_EHLO),
      55, uint(SmtpClient::_AUTH_PLAIN_0),
      56, uint(SmtpClient::_AUTH_LOGIN_0),
      57, uint(SmtpClient::_AUTH_LOGIN_1_USER),
      58, uint(SmtpClient::_AUTH_LOGIN_2_PASS),
      59, uint(SmtpClient::_MAIL_0_FROM),
      60, uint(SmtpClient::_MAIL_1_RCPT_INIT),
      61, uint(SmtpClient::_MAIL_2_RCPT),
      62, uint(SmtpClient::_MAIL_3_DATA),
      63, uint(SmtpClient::_MAIL_4_SEND_DATA),

       0        // eod
};

void SmtpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SmtpClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< SmtpClient::SmtpError(*)>(_a[1]))); break;
        case 1: _t->stateChanged((*reinterpret_cast< SmtpClient::ClientState(*)>(_a[1]))); break;
        case 2: _t->connected(); break;
        case 3: _t->readyConnected(); break;
        case 4: _t->authenticated(); break;
        case 5: _t->mailSent(); break;
        case 6: _t->mailReset(); break;
        case 7: _t->disconnected(); break;
        case 8: _t->socketStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 9: _t->socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 10: _t->socketReadyRead(); break;
        case 11: _t->socketEncrypted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SmtpClient::*)(SmtpClient::SmtpError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SmtpClient::error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)(SmtpClient::ClientState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SmtpClient::stateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SmtpClient::connected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SmtpClient::readyConnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SmtpClient::authenticated)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SmtpClient::mailSent)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SmtpClient::mailReset)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SmtpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SmtpClient::disconnected)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SmtpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SmtpClient.data,
    qt_meta_data_SmtpClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SmtpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmtpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SmtpClient.stringdata0))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void SmtpClient::error(SmtpClient::SmtpError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SmtpClient::stateChanged(SmtpClient::ClientState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
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
QT_END_MOC_NAMESPACE
