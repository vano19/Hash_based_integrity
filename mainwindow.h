#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "IAlgorithm.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onALGCompressionClicked();
    void onALGKeyClicked();
    void onStartClicked();

private:

    Ui::MainWindow*             ui;
    std::unique_ptr<IAlgorithm> algorithm;
};
#endif // MAINWINDOW_H
