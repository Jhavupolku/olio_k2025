#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numberClicked();
    void operationClicked();
    void clearClicked();
    void enterClicked();

private:
    Ui::MainWindow *ui;
    double num1, num2, result;
    QString currentOperation;
};

#endif // MAINWINDOW_H
