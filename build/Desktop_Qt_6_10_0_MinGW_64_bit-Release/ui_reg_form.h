/********************************************************************************
** Form generated from reading UI file 'reg_form.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_FORM_H
#define UI_REG_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QPushButton *pushButton_draw_password;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label__lastname;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_lastname;
    QSpacerItem *horizontalSpacer_4;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_name;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_name;
    QSpacerItem *horizontalSpacer_2;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_middlename;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(513, 462);
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
        pushButton_reg->setGeometry(QRect(180, 380, 141, 41));
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
        QBrush brush4(QColor(255, 255, 255, 135));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        pushButton_reg->setPalette(palette);
        pushButton_reg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 20px;\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(13, 178, 255);\n"
"	border: 2px solid rgb(0,0,0);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border: 2px solid rgb(170, 0, 0);\n"
"}\n"
""));
        toolButton_auth = new QToolButton(Widget);
        toolButton_auth->setObjectName("toolButton_auth");
        toolButton_auth->setGeometry(QRect(170, 430, 171, 22));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_auth->sizePolicy().hasHeightForWidth());
        toolButton_auth->setSizePolicy(sizePolicy);
        toolButton_auth->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	border-radius: 10px;\n"
"	background-color: rgb(68, 135, 0);\n"
"	color: white;\n"
"	border: 2px solid rgb(0, 0, 0);\n"
"}\n"
"\n"
"\n"
"QToolButton::hover {\n"
"	border: 2px solid rgb(170, 0, 0);\n"
"}\n"
""));
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
        horizontalLayoutWidget_2->setGeometry(QRect(30, 120, 441, 32));
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

        pushButton_draw_password = new QPushButton(horizontalLayoutWidget_2);
        pushButton_draw_password->setObjectName("pushButton_draw_password");
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

        horizontalLayout_3->addWidget(pushButton_draw_password);

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

        horizontalLayoutWidget_5 = new QWidget(Widget);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(30, 290, 441, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label__lastname = new QLabel(horizontalLayoutWidget_5);
        label__lastname->setObjectName("label__lastname");
        label__lastname->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));

        horizontalLayout->addWidget(label__lastname);

        horizontalSpacer_3 = new QSpacerItem(82, 19, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        lineEdit_lastname = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit_lastname->setObjectName("lineEdit_lastname");
        lineEdit_lastname->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));

        horizontalLayout->addWidget(lineEdit_lastname);

        horizontalSpacer_4 = new QSpacerItem(127, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayoutWidget_6 = new QWidget(Widget);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(30, 250, 441, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(horizontalLayoutWidget_6);
        label_name->setObjectName("label_name");
        label_name->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));

        horizontalLayout_6->addWidget(label_name);

        horizontalSpacer = new QSpacerItem(113, 19, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        lineEdit_name = new QLineEdit(horizontalLayoutWidget_6);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));

        horizontalLayout_6->addWidget(lineEdit_name);

        horizontalSpacer_2 = new QSpacerItem(127, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        horizontalLayoutWidget_7 = new QWidget(Widget);
        horizontalLayoutWidget_7->setObjectName("horizontalLayoutWidget_7");
        horizontalLayoutWidget_7->setGeometry(QRect(30, 330, 441, 41));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_7);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));

        horizontalLayout_7->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(84, 19, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        lineEdit_middlename = new QLineEdit(horizontalLayoutWidget_7);
        lineEdit_middlename->setObjectName("lineEdit_middlename");
        lineEdit_middlename->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));

        horizontalLayout_7->addWidget(lineEdit_middlename);

        horizontalSpacer_6 = new QSpacerItem(133, 19, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);


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
        pushButton_draw_password->setText(QString());
        label_email->setText(QCoreApplication::translate("Widget", "email", nullptr));
        label__lastname->setText(QCoreApplication::translate("Widget", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_name->setText(QCoreApplication::translate("Widget", "\320\230\320\274\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_FORM_H
