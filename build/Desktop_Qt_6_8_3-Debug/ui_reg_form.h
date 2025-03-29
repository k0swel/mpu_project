/********************************************************************************
** Form generated from reading UI file 'reg_form.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_FORM_H
#define UI_REG_FORM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *pushButton_reg;
    QToolButton *toolButton_auth;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_login;
    QLineEdit *lineEdit_login;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_email_2;
    QDateEdit *dateEdit_birthday;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(510, 336);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 35, 40);"));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 231, 28));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        pushButton_reg = new QPushButton(Widget);
        pushButton_reg->setObjectName("pushButton_reg");
        pushButton_reg->setGeometry(QRect(180, 250, 141, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(13, 178, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pushButton_reg->setPalette(palette);
        pushButton_reg->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(13, 178, 255);\n"
"border: 2px solid rgb(0,0,0);"));
        toolButton_auth = new QToolButton(Widget);
        toolButton_auth->setObjectName("toolButton_auth");
        toolButton_auth->setGeometry(QRect(170, 300, 171, 22));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_auth->sizePolicy().hasHeightForWidth());
        toolButton_auth->setSizePolicy(sizePolicy);
        toolButton_auth->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(68, 135, 0);\n"
"color: white;\n"
"selection-color: rgb(85, 255, 0);\n"
"border: 2px solid rgb(0, 0, 0);"));
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 80, 441, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_login = new QLabel(horizontalLayoutWidget);
        label_login->setObjectName("label_login");
        label_login->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_login->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        label_login->setFrameShape(QFrame::Shape::Box);
        label_login->setFrameShadow(QFrame::Shadow::Plain);
        label_login->setLineWidth(0);
        label_login->setMidLineWidth(0);
        label_login->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(label_login);

        lineEdit_login = new QLineEdit(horizontalLayoutWidget);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setMinimumSize(QSize(0, 0));
        lineEdit_login->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));

        horizontalLayout_2->addWidget(lineEdit_login);

        horizontalLayoutWidget_2 = new QWidget(Widget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(30, 120, 441, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_password = new QLabel(horizontalLayoutWidget_2);
        label_password->setObjectName("label_password");
        label_password->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        label_password->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(label_password);

        lineEdit_password = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_3->addWidget(lineEdit_password);

        horizontalLayoutWidget_3 = new QWidget(Widget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(30, 160, 441, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_email = new QLabel(horizontalLayoutWidget_3);
        label_email->setObjectName("label_email");
        label_email->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        label_email->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(label_email);

        lineEdit_email = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));

        horizontalLayout_4->addWidget(lineEdit_email);

        horizontalLayoutWidget_4 = new QWidget(Widget);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(30, 210, 441, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_email_2 = new QLabel(horizontalLayoutWidget_4);
        label_email_2->setObjectName("label_email_2");
        label_email_2->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        label_email_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_5->addWidget(label_email_2);

        dateEdit_birthday = new QDateEdit(horizontalLayoutWidget_4);
        dateEdit_birthday->setObjectName("dateEdit_birthday");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateEdit_birthday->sizePolicy().hasHeightForWidth());
        dateEdit_birthday->setSizePolicy(sizePolicy1);
        dateEdit_birthday->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        dateEdit_birthday->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));
        dateEdit_birthday->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dateEdit_birthday->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::UpDownArrows);
        dateEdit_birthday->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(9, 0, 0)));
        dateEdit_birthday->setCalendarPopup(true);
        dateEdit_birthday->setCurrentSectionIndex(0);
        dateEdit_birthday->setDate(QDate(2000, 1, 1));

        horizontalLayout_5->addWidget(dateEdit_birthday);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\320\241\320\236\320\227\320\224\320\220\320\235\320\230\320\225 \320\220\320\232\320\232\320\220\320\243\320\235\320\242\320\220", nullptr));
        pushButton_reg->setText(QCoreApplication::translate("Widget", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        toolButton_auth->setText(QCoreApplication::translate("Widget", "\320\243 \320\274\320\265\320\275\321\217 \321\203\320\266\320\265 \320\265\321\201\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        label_login->setText(QCoreApplication::translate("Widget", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_password->setText(QCoreApplication::translate("Widget", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_email->setText(QCoreApplication::translate("Widget", "email", nullptr));
        label_email_2->setText(QCoreApplication::translate("Widget", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_FORM_H
