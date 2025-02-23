#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , num1(0), num2(0), result(0), currentOperation("")
{
    ui->setupUi(this);

    connect(ui->no0, &QPushButton::clicked, this, &MainWindow::numberClicked);
    connect(ui->no1, &QPushButton::clicked, this, &MainWindow::numberClicked);
    connect(ui->no2, &QPushButton::clicked, this, &MainWindow::numberClicked);
    connect(ui->no3, &QPushButton::clicked, this, &MainWindow::numberClicked);
    connect(ui->no4, &QPushButton::clicked, this, &MainWindow::numberClicked);
    connect(ui->no5, &QPushButton::clicked, this, &MainWindow::numberClicked);
    connect(ui->no6, &QPushButton::clicked, this, &MainWindow::numberClicked);
    connect(ui->no7, &QPushButton::clicked, this, &MainWindow::numberClicked);
    connect(ui->no8, &QPushButton::clicked, this, &MainWindow::numberClicked);
    connect(ui->no9, &QPushButton::clicked, this, &MainWindow::numberClicked);

    connect(ui->noPlus, &QPushButton::clicked, this, &MainWindow::operationClicked);
    connect(ui->noMiinus, &QPushButton::clicked, this, &MainWindow::operationClicked);
    connect(ui->noKerto, &QPushButton::clicked, this, &MainWindow::operationClicked);
    connect(ui->noJako, &QPushButton::clicked, this, &MainWindow::operationClicked);

    connect(ui->nClear, &QPushButton::clicked, this, &MainWindow::clearClicked);
    connect(ui->nEnter, &QPushButton::clicked, this, &MainWindow::enterClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
    {
        QString buttonText = button->text();
        if (currentOperation.isEmpty())
        {
            // luku yksi
            num1 = num1 * 10 + buttonText.toInt();
            ui->num1->setText(QString::number(num1));
        }
        else
        {
            // luku kaksi
            num2 = num2 * 10 + buttonText.toInt();
            ui->num2->setText(QString::number(num2));
        }
    }
}

void MainWindow::operationClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
    {
        currentOperation = button->text();
    }
}

void MainWindow::clearClicked()
{
    num1 = 0;
    num2 = 0;
    result = 0;
    currentOperation.clear();
    ui->num1->setText("");
    ui->num2->setText("");
    ui->result->setText("");
}

void MainWindow::enterClicked()
{
    switch (currentOperation.toStdString()[0])
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            ui->result->setText("Error: Div by 0");
            return;
        }
        break;
    default:
        return;
    }

    ui->result->setText(QString::number(result));
}
