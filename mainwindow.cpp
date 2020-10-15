#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Trace.h"
#include "ALGCompression.h"
#include "ALGKey.h"
#include "definitions.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , algorithm(nullptr)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/Images/Title_icon.png"));
    setWindowTitle("Перевірка цілісності зображення.");

    connect(ui->AlgCompression, SIGNAL(clicked()), this, SLOT(onALGCompressionClicked()));
    connect(ui->AlgKey, SIGNAL(clicked()), this, SLOT(onALGKeyClicked()));
    connect(ui->StartInject, SIGNAL(clicked()), this, SLOT(onStartClicked()));

    ui->progressBar->setValue(0); // 0% loading
    ui->StartInject->setIcon(QIcon(":/Images/input.png"));
    ui->StartDetach->setIcon(QIcon(":/Images/output.png"));

    QString boldText = " { font-weight: bold; }";
    ui->StartInject->setStyleSheet("QPushButton" + boldText);
    ui->StartDetach->setStyleSheet("QPushButton" + boldText);

    ui->AlgCompression->setStyleSheet("QRadioButton" + boldText);
    ui->AlgKey->setStyleSheet("QRadioButton" + boldText);

    ui->AlgCompression->setIcon(QIcon(":/Images/compressed-file.png"));
    ui->AlgKey->setIcon(QIcon(":/Images/key.png"));

    ui->TitleKey->setStyleSheet("QLineEdit"+ boldText);
    ui->ChoosingTitle->setStyleSheet("QLineEdit"+ boldText);
    ui->PathText->setStyleSheet("QLineEdit"+ boldText);
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

void MainWindow::onStartClicked()
{
    LOG_INF("<-");

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
        cv::Mat img = cv::imread(pathToFile.toStdString(), cv::IMREAD_COLOR);
        if (img.empty())
        {
            callMessage("Не можна відкрити зображення!");
        }
        else
        {
            //cv::imshow("Display window", img);
            algorithm->inject(key);
        }
    }
}
