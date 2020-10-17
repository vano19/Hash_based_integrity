#include "Definitions.h"
#include <QMessageBox>
#include <QIcon>

void callMessage(const QString& text)
{
    QMessageBox message(QMessageBox::Information , QString("До Уваги"), text);
    message.setWindowIcon( QIcon(":/Title_icon.png") );
    message.exec();
}

void callError(const QString& text)
{
    QMessageBox message(QMessageBox::Critical , QString("Помилка"), text);
    message.setWindowIcon( QIcon(":/Title_icon.png") );
    message.exec();
}

void callDone(const QString& text)
{
    QMessageBox message(QMessageBox::NoIcon , QString("Готово"), text);
    message.setWindowIcon( QIcon(":/Title_icon.png") );
    message.exec();
}
