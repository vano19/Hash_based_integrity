#include "Mainwindow.h"
#include "ui_mainwindow.h"
#include "Trace.h"
#include "ALGCompression.h"
#include "ALGKey.h"
#include "Definitions.h"

#include <QDir>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , algorithm(nullptr)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/Title_icon.png"));
    setWindowTitle("Перевірка цілісності зображення.");

    connect(ui->AlgCompression, SIGNAL(clicked()), this, SLOT(onALGCompressionClicked()));
    connect(ui->AlgKey, SIGNAL(clicked()), this, SLOT(onALGKeyClicked()));
    connect(ui->StartInject, SIGNAL(clicked()), this, SLOT(onStartInjectClicked()));
    connect(ui->StartDetach, SIGNAL(clicked()), this, SLOT(onStartDetachClicked()));
    connect(ui->ShowImage, SIGNAL(clicked()), this, SLOT(onShowImageClicked()));

    ui->progressBar->setValue(0); // 0% loading
    ui->StartInject->setIcon(QIcon(":/input.png"));
    ui->StartDetach->setIcon(QIcon(":/output.png"));

    QString boldText = " { font-weight: bold; }";
    ui->StartInject->setStyleSheet("QPushButton" + boldText);
    ui->StartDetach->setStyleSheet("QPushButton" + boldText);

    ui->AlgCompression->setStyleSheet("QRadioButton" + boldText);
    ui->AlgKey->setStyleSheet("QRadioButton" + boldText);

    ui->AlgCompression->setIcon(QIcon(":/compressed-file.png"));
    ui->AlgKey->setIcon(QIcon(":/key.png"));

    ui->TitleKey->setStyleSheet("QLineEdit"+ boldText);
    ui->ChoosingTitle->setStyleSheet("QLineEdit"+ boldText);
    ui->PathText->setStyleSheet("QLineEdit"+ boldText);

    ui->ShowImage->setIcon(QIcon(":/image-file.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onALGCompressionClicked()
{
    LOG_INF("<-");

    QLineEdit& textKey = *ui->TextKey;
    textKey.clear();
    textKey.setEnabled(false);

    algorithm.reset(new ALGCompression());
}

void MainWindow::onALGKeyClicked()
{
    LOG_INF("<-");

    ui->TextKey->setEnabled(true);
    algorithm.reset(new ALGKey());
}

void MainWindow::onStartDetachClicked()
{
    LOG_INF("<-");

    ui->progressBar->setValue(5);

    QString key = ui->TextKey->text();
    QString pathToFile = ui->PathToFile->text();
    if (!algorithm)
    {
        callMessage("Алгоритм не був вибраний!");
    }
    else if (pathToFile.isEmpty())
    {
        callMessage("Шлях до зображення порожній!");
    }
    else
    {
        ui->progressBar->setValue(30);

        if (algorithm->detach(key, pathToFile))
        {
            ui->progressBar->setValue(100);

            callDone("Готово");
        }
        else
        {
            callError("Помилка");
        }
    }
}

void MainWindow::onShowImageClicked()
{
    LOG_INF("<-");

    QString pathToFile = ui->PathToFile->text();
    if (pathToFile.isEmpty())
    {
        callMessage("Шлях до зображення порожній!");
    }
    else if (!showImage(pathToFile) && !showImage(QDir::currentPath() + "\"" + pathToFile))
    {
       callMessage("Не можна відкрити зображення!");
    }
}

bool MainWindow::showImage(const QString& path)
{
    cv::Mat img = cv::imread(path.toStdString(), cv::IMREAD_COLOR);
    if (!img.empty())
    {
        cv::imshow("Display window", img);
    }
    img.deallocate();
    return !img.empty();
}

void MainWindow::onStartInjectClicked()
{
    LOG_INF("<-");

    ui->progressBar->setValue(5);

    QString key = ui->TextKey->text();
    QString pathToFile = ui->PathToFile->text();
    if (!algorithm)
    {
        callMessage("Алгоритм не був вибраний!");
    }
    else if (pathToFile.isEmpty())
    {
        callMessage("Шлях до зображення порожній!");
    }
    else
    {
        ui->progressBar->setValue(30);

        if (algorithm->inject(key, pathToFile))
        {
            ui->progressBar->setValue(100);
            callDone("Готово");
        }
        else
        {
            callError("Помилка");
        }
    }
}
