#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Plus_clicked()
{

    calculate('+');
}

void MainWindow::on_Minus_clicked()
{
    calculate('-');
}

void MainWindow::on_Multiply_clicked()
{
    calculate('*');
}

void MainWindow::on_Divition_clicked()
{
   calculate('/');
}

void MainWindow::calculate(char op)
{

double num1,num2, answer;
num1= ui->NumInput1->text().toDouble();
num2=ui->NumInput2->text().toDouble();
answer=0;
switch(op)
{
case '+':
    answer=num1+num2;
    break;
case '-':
    answer=num1-num2;
    break;
case '*':
    answer=num1*num2;
    break;
case '/':
    answer=num1/num2;
    break;
}
QString str;
str.setNum(answer);
ui->DisplayInput->setText(str);

}

void MainWindow::on_actionExit_triggered()
{
    exit(EXIT_SUCCESS);
}

void MainWindow::on_actionHelp_Content_triggered()
{
    QMessageBox help;
    help.setWindowTitle("Help");
    help.setText("1.Enter 2 number in 2 number text boxes. \n 2. Press on any operator.\n 3. See result in the answer box.");
    help.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox about;
    about.setWindowTitle("About Simple Calculator");
    about.setText("Simple Calculator. \n Developer: Shekhar & Tithi.\n Email: chandrapub@gmalil.com.");
    about.exec();
}
