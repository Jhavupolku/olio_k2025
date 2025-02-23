#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , counter(0)
{
    ui->setupUi(this);
    connect(ui->nappi, &QPushButton::clicked, this, &MainWindow::handleCountClick);
    connect(ui->nReset, &QPushButton::clicked, this, &MainWindow::handleResetClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleCountClick()
{
    counter++;
    ui->tulos->setText(QString::number(counter));
    qDebug() << "vastaanotettu +1" << counter;
}

void MainWindow::handleResetClick()
{
    counter = 0;
    ui->tulos->setText(QString::number(counter));
    qDebug() << "nollattu";
}
