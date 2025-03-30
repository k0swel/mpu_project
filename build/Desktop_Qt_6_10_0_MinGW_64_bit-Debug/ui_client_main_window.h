/********************************************************************************
** Form generated from reading UI file 'client_main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_MAIN_WINDOW_H
#define UI_CLIENT_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client_main_window
{
public:
    QAction *action_2;
    QAction *action_3;
    QLabel *label;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *Layout_quadratic;
    QComboBox *comboBox_sign2_quardratic;
    QLineEdit *lineEdit_a_quadratic;
    QLabel *label_2;
    QComboBox *comboBox_sign2_quadratic_2;
    QLineEdit *lineEdit_b_quadratic;
    QLabel *label_3;
    QComboBox *comboBox_sign2_quadratic_3;
    QLineEdit *lineEdit_c_quadratic;
    QLabel *label_6;
    QLabel *label_answer;
    QHBoxLayout *layout_linear;
    QComboBox *comboBox_sign_linear;
    QLineEdit *lineEdit_a_linear;
    QLabel *label_5;
    QComboBox *comboBox_sign2_linear;
    QLineEdit *lineEdit_b_linear;
    QLabel *label_4;
    QPushButton *pushButton_solve_equation;

    void setupUi(QWidget *client_main_window)
    {
        if (client_main_window->objectName().isEmpty())
            client_main_window->setObjectName("client_main_window");
        client_main_window->resize(354, 196);
        client_main_window->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 35, 40);\n"
""));
        action_2 = new QAction(client_main_window);
        action_2->setObjectName("action_2");
        action_3 = new QAction(client_main_window);
        action_3->setObjectName("action_3");
        label = new QLabel(client_main_window);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 211, 21));
        label->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        pushButton = new QPushButton(client_main_window);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 10, 30, 30));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        pushButton->setToolTipDuration(-1);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 3px;\n"
"background-color: rgb(84, 84, 84);\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemLogOut));
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(30, 30));
        comboBox = new QComboBox(client_main_window);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(190, 160, 151, 22));
        comboBox->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"background-color: rgb(84, 84, 84);\n"
"color: rgb(237, 237, 237);\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"color: rgb(237, 237, 237);\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"      border: 2px solid rgb(255, 0, 0);\n"
"  }\n"
"\n"
"  QListView::item:selected:!active {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
"  }\n"
"\n"
"  QListView::item:selected:active {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
"  }\n"
"\n"
"  QListView::item:hover {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
"  }"));
        comboBox->setFrame(true);
        horizontalLayoutWidget_3 = new QWidget(client_main_window);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(40, 70, 291, 26));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Layout_quadratic = new QHBoxLayout();
        Layout_quadratic->setObjectName("Layout_quadratic");
        comboBox_sign2_quardratic = new QComboBox(horizontalLayoutWidget_3);
        comboBox_sign2_quardratic->addItem(QString());
        comboBox_sign2_quardratic->addItem(QString());
        comboBox_sign2_quardratic->setObjectName("comboBox_sign2_quardratic");

        Layout_quadratic->addWidget(comboBox_sign2_quardratic);

        lineEdit_a_quadratic = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_a_quadratic->setObjectName("lineEdit_a_quadratic");
        lineEdit_a_quadratic->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lineEdit_a_quadratic->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));
        lineEdit_a_quadratic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        Layout_quadratic->addWidget(lineEdit_a_quadratic);

        label_2 = new QLabel(horizontalLayoutWidget_3);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));

        Layout_quadratic->addWidget(label_2);

        comboBox_sign2_quadratic_2 = new QComboBox(horizontalLayoutWidget_3);
        comboBox_sign2_quadratic_2->addItem(QString());
        comboBox_sign2_quadratic_2->addItem(QString());
        comboBox_sign2_quadratic_2->setObjectName("comboBox_sign2_quadratic_2");

        Layout_quadratic->addWidget(comboBox_sign2_quadratic_2);

        lineEdit_b_quadratic = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_b_quadratic->setObjectName("lineEdit_b_quadratic");
        lineEdit_b_quadratic->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));
        lineEdit_b_quadratic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        Layout_quadratic->addWidget(lineEdit_b_quadratic);

        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));

        Layout_quadratic->addWidget(label_3);

        comboBox_sign2_quadratic_3 = new QComboBox(horizontalLayoutWidget_3);
        comboBox_sign2_quadratic_3->addItem(QString());
        comboBox_sign2_quadratic_3->addItem(QString());
        comboBox_sign2_quadratic_3->setObjectName("comboBox_sign2_quadratic_3");

        Layout_quadratic->addWidget(comboBox_sign2_quadratic_3);

        lineEdit_c_quadratic = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_c_quadratic->setObjectName("lineEdit_c_quadratic");
        lineEdit_c_quadratic->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));
        lineEdit_c_quadratic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        Layout_quadratic->addWidget(lineEdit_c_quadratic);

        label_6 = new QLabel(horizontalLayoutWidget_3);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));

        Layout_quadratic->addWidget(label_6);

        label_answer = new QLabel(horizontalLayoutWidget_3);
        label_answer->setObjectName("label_answer");
        label_answer->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));

        Layout_quadratic->addWidget(label_answer);


        horizontalLayout_4->addLayout(Layout_quadratic);

        layout_linear = new QHBoxLayout();
        layout_linear->setObjectName("layout_linear");
        comboBox_sign_linear = new QComboBox(horizontalLayoutWidget_3);
        comboBox_sign_linear->addItem(QString());
        comboBox_sign_linear->addItem(QString());
        comboBox_sign_linear->setObjectName("comboBox_sign_linear");

        layout_linear->addWidget(comboBox_sign_linear);

        lineEdit_a_linear = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_a_linear->setObjectName("lineEdit_a_linear");
        lineEdit_a_linear->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));
        lineEdit_a_linear->setAlignment(Qt::AlignmentFlag::AlignCenter);

        layout_linear->addWidget(lineEdit_a_linear);

        label_5 = new QLabel(horizontalLayoutWidget_3);
        label_5->setObjectName("label_5");

        layout_linear->addWidget(label_5);

        comboBox_sign2_linear = new QComboBox(horizontalLayoutWidget_3);
        comboBox_sign2_linear->addItem(QString());
        comboBox_sign2_linear->addItem(QString());
        comboBox_sign2_linear->setObjectName("comboBox_sign2_linear");

        layout_linear->addWidget(comboBox_sign2_linear);

        lineEdit_b_linear = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_b_linear->setObjectName("lineEdit_b_linear");
        lineEdit_b_linear->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 53, 60);"));
        lineEdit_b_linear->setAlignment(Qt::AlignmentFlag::AlignCenter);

        layout_linear->addWidget(lineEdit_b_linear);

        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));

        layout_linear->addWidget(label_4);


        horizontalLayout_4->addLayout(layout_linear);

        pushButton_solve_equation = new QPushButton(client_main_window);
        pushButton_solve_equation->setObjectName("pushButton_solve_equation");
        pushButton_solve_equation->setGeometry(QRect(110, 110, 141, 41));
        pushButton_solve_equation->setStyleSheet(QString::fromUtf8("border-radius: 15px;  /* \320\241\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(13, 178, 255);\n"
"border: 2px solid rgb(0,0,0);\n"
""));

        retranslateUi(client_main_window);

        QMetaObject::connectSlotsByName(client_main_window);
    } // setupUi

    void retranslateUi(QWidget *client_main_window)
    {
        client_main_window->setWindowTitle(QCoreApplication::translate("client_main_window", "MainWindow", nullptr));
        action_2->setText(QCoreApplication::translate("client_main_window", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        action_3->setText(QCoreApplication::translate("client_main_window", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
        label->setText(QCoreApplication::translate("client_main_window", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("client_main_window", "\320\233\320\270\320\275\320\265\320\271\320\275\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("client_main_window", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202\320\275\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));

#if QT_CONFIG(tooltip)
        comboBox->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        comboBox_sign2_quardratic->setItemText(0, QCoreApplication::translate("client_main_window", "+", nullptr));
        comboBox_sign2_quardratic->setItemText(1, QCoreApplication::translate("client_main_window", "-", nullptr));

        label_2->setText(QCoreApplication::translate("client_main_window", "x^2", nullptr));
        comboBox_sign2_quadratic_2->setItemText(0, QCoreApplication::translate("client_main_window", "+", nullptr));
        comboBox_sign2_quadratic_2->setItemText(1, QCoreApplication::translate("client_main_window", "-", nullptr));

        label_3->setText(QCoreApplication::translate("client_main_window", "x", nullptr));
        comboBox_sign2_quadratic_3->setItemText(0, QCoreApplication::translate("client_main_window", "+", nullptr));
        comboBox_sign2_quadratic_3->setItemText(1, QCoreApplication::translate("client_main_window", "-", nullptr));

        label_6->setText(QCoreApplication::translate("client_main_window", "= 0", nullptr));
        label_answer->setText(QString());
        comboBox_sign_linear->setItemText(0, QCoreApplication::translate("client_main_window", "+", nullptr));
        comboBox_sign_linear->setItemText(1, QCoreApplication::translate("client_main_window", "-", nullptr));

        label_5->setText(QCoreApplication::translate("client_main_window", "x", nullptr));
        comboBox_sign2_linear->setItemText(0, QCoreApplication::translate("client_main_window", "+", nullptr));
        comboBox_sign2_linear->setItemText(1, QCoreApplication::translate("client_main_window", "-", nullptr));

        label_4->setText(QCoreApplication::translate("client_main_window", "= 0", nullptr));
        pushButton_solve_equation->setText(QCoreApplication::translate("client_main_window", "\320\240\320\265\321\210\320\270\321\202\321\214 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client_main_window: public Ui_client_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_MAIN_WINDOW_H
