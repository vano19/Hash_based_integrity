#include "Definitions.h"
#include <QMessageBox>
#include <QIcon>

void callMessage(const QString& text)
{
    QMessageBox message(QMessageBox::Information , QString("До Уваги"), text);
    message.setWindowIcon( QIcon(":/resources/Title_icon.png") );
    message.exec();
}
