/********************************************************************************
** Form generated from reading UI file 'reset_password.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESET_PASSWORD_H
#define UI_RESET_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reset_password
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_login;
    QLineEdit *lineEdit_login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_code;
    QLineEdit *lineEdit_code;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_code;
    QPushButton *pushButton_reset_password;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_to_reg;
    QPushButton *pushButton_to_auth;
    QLabel *label_message_send_code;
    QPushButton *pushButton;

    void setupUi(QWidget *reset_password)
    {
        if (reset_password->objectName().isEmpty())
            reset_password->setObjectName("reset_password");
        reset_password->resize(601, 272);
        reset_password->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 35, 40);\n"
""));
        label = new QLabel(reset_password);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 291, 28));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget = new QWidget(reset_password);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 60, 505, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName("horizontalLayout");
        label_login = new QLabel(verticalLayoutWidget);
        label_login->setObjectName("label_login");
        label_login->setEnabled(true);
        label_login->setFont(font);
        label_login->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_login->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        label_login->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_login);

        lineEdit_login = new QLineEdit(verticalLayoutWidget);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));

        horizontalLayout->addWidget(lineEdit_login);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_code = new QLabel(verticalLayoutWidget);
        label_code->setObjectName("label_code");
        label_code->setFont(font);
        label_code->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        label_code->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        horizontalLayout_2->addWidget(label_code);

        lineEdit_code = new QLineEdit(verticalLayoutWidget);
        lineEdit_code->setObjectName("lineEdit_code");
        lineEdit_code->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));

        horizontalLayout_2->addWidget(lineEdit_code);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_code = new QPushButton(verticalLayoutWidget);
        pushButton_code->setObjectName("pushButton_code");
        pushButton_code->setEnabled(true);
        pushButton_code->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(0, 170, 255);\n"
"color: white;\n"
"border: 2px solid rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(pushButton_code);

        pushButton_reset_password = new QPushButton(verticalLayoutWidget);
        pushButton_reset_password->setObjectName("pushButton_reset_password");
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(0, 0, 0, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        QBrush brush3(QColor(255, 255, 255, 135));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        pushButton_reset_password->setPalette(palette);
        pushButton_reset_password->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: white;\n"
"color: black;\n"
"border: 2px solid rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(pushButton_reset_password);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_to_reg = new QPushButton(verticalLayoutWidget);
        pushButton_to_reg->setObjectName("pushButton_to_reg");
        pushButton_to_reg->setStyleSheet(QString::fromUtf8("border-radius: 10px;  /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"background-color: rgb(158, 48, 25);\n"
"color: white;\n"
"border: 2px solid rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(pushButton_to_reg);

        pushButton_to_auth = new QPushButton(verticalLayoutWidget);
        pushButton_to_auth->setObjectName("pushButton_to_auth");
        pushButton_to_auth->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(68, 135, 0);\n"
"color: white;\n"
"selection-color: rgb(85, 255, 0);\n"
"border: 2px solid rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(pushButton_to_auth);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_message_send_code = new QLabel(verticalLayoutWidget);
        label_message_send_code->setObjectName("label_message_send_code");
        label_message_send_code->setEnabled(true);
        QFont font1;
        font1.setPointSize(10);
        label_message_send_code->setFont(font1);
        label_message_send_code->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));

        verticalLayout_2->addWidget(label_message_send_code);

        pushButton = new QPushButton(reset_password);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(550, 10, 50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-image: url(:/icons/icons/icon-reload.png);\n"
"	background-color: rgb(173, 173, 173);\n"
"	border: 1px solid black;\n"
"	border-radius: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #e74c3c;\n"
"    \n"
"}"));

        retranslateUi(reset_password);

        QMetaObject::connectSlotsByName(reset_password);
    } // setupUi

    void retranslateUi(QWidget *reset_password)
    {
        reset_password->setWindowTitle(QCoreApplication::translate("reset_password", "Form", nullptr));
        label->setText(QCoreApplication::translate("reset_password", "\320\222\320\236\320\241\320\241\320\242\320\220\320\235\320\236\320\222\320\233\320\225\320\235\320\230\320\225 \320\237\320\220\320\240\320\236\320\233\320\257", nullptr));
        label_login->setText(QCoreApplication::translate("reset_password", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_code->setText(QCoreApplication::translate("reset_password", "\320\232\320\276\320\264 \320\277\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        pushButton_code->setText(QCoreApplication::translate("reset_password", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\264", nullptr));
        pushButton_reset_password->setText(QCoreApplication::translate("reset_password", "\320\227\320\260\320\261\321\213\320\273 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton_to_reg->setText(QCoreApplication::translate("reset_password", "\320\235\320\265\321\202 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        pushButton_to_auth->setText(QCoreApplication::translate("reset_password", "\320\243 \320\274\320\265\320\275\321\217 \321\203\320\266\320\265 \320\265\321\201\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        label_message_send_code->setText(QCoreApplication::translate("reset_password", "\320\235\320\260 \320\277\320\276\321\207\321\202\321\203, \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\321\203\321\216\321\211\321\203\321\216 \320\262\320\260\321\210\320\265\320\274\321\203 \320\273\320\276\320\263\320\270\320\275\321\203, \320\261\321\213\320\273 \320\262\321\213\321\201\320\273\320\260\320\275 \320\272\320\276\320\264 \320\277\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\321\217.", nullptr));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("reset_password", "<html><head/><body><p>\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \320\276\320\272\320\275\320\276</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class reset_password: public Ui_reset_password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESET_PASSWORD_H
