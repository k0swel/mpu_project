/********************************************************************************
** Form generated from reading UI file 'auth_form.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_FORM_H
#define UI_AUTH_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_auth_form
{
public:
    QPushButton *pushButton_login;
    QPushButton *pushButton_reset_password;
    QPushButton *pushButton_to_reg;
    QLabel *label_login;
    QLineEdit *lineEdit_login;
    QLabel *label_password;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_draw_password;

    void setupUi(QWidget *auth_form)
    {
        if (auth_form->objectName().isEmpty())
            auth_form->setObjectName("auth_form");
        auth_form->resize(448, 323);
        QPalette palette;
        QBrush brush(QColor(33, 35, 40, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(138, 136, 135, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush1);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush1);
        auth_form->setPalette(palette);
        auth_form->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 35, 40);\n"
""));
        pushButton_login = new QPushButton(auth_form);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(120, 190, 191, 61));
        pushButton_login->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_login {\n"
"\n"
"border-radius: 30px; \n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(13, 178, 255);\n"
"border: 2px solid rgb(0,0,0);\n"
"}\n"
"\n"
"QPushButton#pushButton_login::hover {\n"
"	border: 2px solid rgb(170, 0, 0);\n"
"	font-size: 20px;\n"
"}\n"
""));
        pushButton_reset_password = new QPushButton(auth_form);
        pushButton_reset_password->setObjectName("pushButton_reset_password");
        pushButton_reset_password->setGeometry(QRect(50, 260, 101, 24));
        pushButton_reset_password->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_reset_password {\n"
"border-radius: 10px;  /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"background-color: rgb(68, 135, 0);\n"
"color: white;\n"
"selection-color: rgb(85, 255, 0);\n"
"border: 2px solid rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton#pushButton_reset_password::hover {\n"
"	border: 2px solid rgb(170, 0, 0);\n"
"	font-size: 12px;\n"
"}"));
        pushButton_to_reg = new QPushButton(auth_form);
        pushButton_to_reg->setObjectName("pushButton_to_reg");
        pushButton_to_reg->setGeometry(QRect(250, 260, 121, 24));
        pushButton_to_reg->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_to_reg { border-radius: 10px;  /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"background-color: rgb(158, 48, 25);\n"
"color: white;\n"
"border: 2px solid rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton#pushButton_to_reg::hover {\n"
"	border: 2px solid rgb(85, 255, 127);\n"
"	font-size: 12px;\n"
"}\n"
""));
        label_login = new QLabel(auth_form);
        label_login->setObjectName("label_login");
        label_login->setGeometry(QRect(90, 50, 241, 16));
        label_login->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        lineEdit_login = new QLineEdit(auth_form);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(90, 70, 241, 22));
        lineEdit_login->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));
        label_password = new QLabel(auth_form);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(90, 120, 142, 21));
        label_password->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        label = new QLabel(auth_form);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 121, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(241, 241, 241);"));
        horizontalLayoutWidget = new QWidget(auth_form);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(90, 140, 271, 42));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_password = new QLineEdit(horizontalLayoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);
        lineEdit_password->setClearButtonEnabled(false);

        horizontalLayout->addWidget(lineEdit_password);

        pushButton_draw_password = new QPushButton(horizontalLayoutWidget);
        pushButton_draw_password->setObjectName("pushButton_draw_password");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_draw_password->sizePolicy().hasHeightForWidth());
        pushButton_draw_password->setSizePolicy(sizePolicy);
        pushButton_draw_password->setMinimumSize(QSize(30, 30));
        pushButton_draw_password->setMaximumSize(QSize(30, 30));
        pushButton_draw_password->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 10px;\n"
"	background-color: rgb(79, 79, 79)\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border: 2px solid rgb(170, 0, 0);\n"
"}\n"
""));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("edit-find")));
        pushButton_draw_password->setIcon(icon);

        horizontalLayout->addWidget(pushButton_draw_password);


        retranslateUi(auth_form);

        QMetaObject::connectSlotsByName(auth_form);
    } // setupUi

    void retranslateUi(QWidget *auth_form)
    {
        auth_form->setWindowTitle(QCoreApplication::translate("auth_form", "Form", nullptr));
        pushButton_login->setText(QCoreApplication::translate("auth_form", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        pushButton_reset_password->setText(QCoreApplication::translate("auth_form", "\320\227\320\260\320\261\321\213\320\273 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton_to_reg->setText(QCoreApplication::translate("auth_form", "\320\235\320\265\321\202 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        label_login->setText(QCoreApplication::translate("auth_form", "\320\222\320\276\320\271\321\202\320\270, \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\321\217 \320\273\320\276\320\263\320\270\320\275:", nullptr));
        label_password->setText(QCoreApplication::translate("auth_form", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("auth_form", "\320\220\320\222\320\242\320\236\320\240\320\230\320\227\320\220\320\246\320\230\320\257", nullptr));
        pushButton_draw_password->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class auth_form: public Ui_auth_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_FORM_H
