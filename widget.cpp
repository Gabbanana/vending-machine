#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // ui->pdCoffee->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    checkMoney();
}

void Widget::checkMoney(){
    if(money < 100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    } else if (money < 150) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    } else if (money < 200) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(false);
    } else {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbMilk->setEnabled(true);
    }
}



void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    int coins500 = money / 500;
    money %= 500;

    int coins100 = money / 100;
    money %= 100;

    int coins50 = money / 50;
    money %= 50;

    int coins10 = money / 10;
    money %= 10;

    QString message = QString("Change Returned:\n500 coins: %1\n100 coins: %2\n50 coins: %3\n10 coins: %4")
                          .arg(coins500).arg(coins100).arg(coins50).arg(coins10);

    QMessageBox mb;
    mb.information(this, "Reset", message);

    ui->lcdNumber->display(0);
    checkMoney();
}


