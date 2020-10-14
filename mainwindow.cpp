#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Trace.h"
#include "ALGCompression.h"
#include "ALGKey.h"
#include "definitions.h"

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
    connect(ui->Start, SIGNAL(clicked()), this, SLOT(onStartClicked()));

    ui->progressBar->setValue(0); // 0% loading
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

    if (!algorithm)
    {
        callMessage("Алгоритм не був вибраний!");
    }
    else
    {
        algorithm->inject(key);
    }
}
