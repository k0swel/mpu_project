/********************************************************************************
** Form generated from reading UI file 'notification.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATION_H
#define UI_NOTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_notification
{
public:
    QProgressBar *progressBar;
    QLabel *label;

    void setupUi(QWidget *notification)
    {
        if (notification->objectName().isEmpty())
            notification->setObjectName("notification");
        notification->resize(408, 91);
        notification->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 35, 40);"));
        progressBar = new QProgressBar(notification);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(50, 50, 301, 16));
        progressBar->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        progressBar->setValue(24);
        label = new QLabel(notification);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 381, 41));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(224, 225, 230);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(notification);

        QMetaObject::connectSlotsByName(notification);
    } // setupUi

    void retranslateUi(QWidget *notification)
    {
        notification->setWindowTitle(QCoreApplication::translate("notification", "Form", nullptr));
        label->setText(QCoreApplication::translate("notification", "\320\236\321\210\320\270\320\261\320\272\320\260 \320\277\321\200\320\270 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270. \320\224\320\260\320\275\320\275\320\260\321\217 \321\203\321\207\321\221\321\202\320\275\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214 \321\203\320\266\320\265 \320\267\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class notification: public Ui_notification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATION_H
