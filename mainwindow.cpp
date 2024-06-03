#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QPainterPath>
#include <QPainter>
#include <QPen>
#include <QColor>
#include "poland.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BuildButton = new QPushButton(this);
    BuildButton->setGeometry(width() - 5 - 100 - 50, 5, 150, 30);
    BuildButton->setText("Build");
    connect(BuildButton,SIGNAL(clicked(bool)), this, SLOT(Build()));

    BuildSinButton = new QPushButton(this);
    BuildSinButton->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 6), 150, 30);
    BuildSinButton->setText("sin(x)");
    connect(BuildSinButton,SIGNAL(clicked(bool)), this, SLOT(BuildSin()));

    BuildTgButton = new QPushButton(this);
    BuildTgButton->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 7), 150, 30);
    BuildTgButton->setText("tg(x)");
    connect(BuildTgButton,SIGNAL(clicked(bool)), this, SLOT(BuildTg()));

    BuildX2Button = new QPushButton(this);
    BuildX2Button->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 8), 150, 30);
    BuildX2Button->setText("x^2");
    connect(BuildX2Button,SIGNAL(clicked(bool)), this, SLOT(BuildX2()));

    Build1DXButton = new QPushButton(this);
    Build1DXButton->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 9), 150, 30);
    Build1DXButton->setText("1/x");
    connect(Build1DXButton,SIGNAL(clicked(bool)), this, SLOT(Build1DX()));

    BuildSQRTButton = new QPushButton(this);
    BuildSQRTButton->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 10), 150, 30);
    BuildSQRTButton->setText("sqrt(x)");
    connect(BuildSQRTButton,SIGNAL(clicked(bool)), this, SLOT(BuildSQRT()));

    BuildABSButton = new QPushButton(this);
    BuildABSButton->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 11), 150, 30);
    BuildABSButton->setText("abs(x)");
    connect(BuildABSButton,SIGNAL(clicked(bool)), this, SLOT(BuildABS()));

    CleanButton = new QPushButton(this);
    CleanButton->setGeometry(width() - 5 - 100 - 50, height() - 35, 150, 30);
    CleanButton->setText("Clear");
    connect(CleanButton,SIGNAL(clicked(bool)), this, SLOT(Clean()));

    ResetFButton = new QPushButton(this);
    ResetFButton->setGeometry(width() - 5 - 100 - 50, height() - 35 - 35, 150, 30);
    ResetFButton->setText("Reset f(x)");
    connect(ResetFButton,SIGNAL(clicked(bool)), this, SLOT(ResetF()));

    ResetMButton = new QPushButton(this);
    ResetMButton->setGeometry(width() - 5 - 100 - 50, height() - 35 - 35 - 35, 150, 30);
    ResetMButton->setText("Reset min/max");
    connect(ResetMButton,SIGNAL(clicked(bool)), this, SLOT(ResetM()));


    FunctionLine = new QLineEdit(this);
    FunctionLine->setGeometry(5 + 40, 5, width() - 5 - 5 - 150 - 5 - 40, 30);
    xminLine = new QLineEdit(this);
    xminLine->setGeometry(width() - 5 - 100, 5 + (35 * 1), 100, 30);
    xmaxLine = new QLineEdit(this);
    xmaxLine->setGeometry(width() - 5 - 100, 5 + (35 * 2), 100, 30);
    yminLine = new QLineEdit(this);
    yminLine->setGeometry(width() - 5 - 100, 5 + (35 * 3), 100, 30);
    ymaxLine = new QLineEdit(this);
    ymaxLine->setGeometry(width() - 5 - 100, 5 + (35 * 4), 100, 30);
    ResultLine = new QLineEdit(this);
    ResultLine->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 5), 150, 30);
    Function = new QLabel(this);
    Function->setGeometry(5, 5, 40, 30);
    Function->setText("f(x) = ");
    xmin = new QLabel(this);
    xmin->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 1), 40 + 20, 30);
    xmin->setText("xmin = ");
    xmax = new QLabel(this);
    xmax->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 2), 40 + 20, 30);
    xmax->setText("xmax = ");
    ymin = new QLabel(this);
    ymin->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 3), 40 + 20, 30);
    ymin->setText("ymin = ");
    ymax = new QLabel(this);
    ymax->setGeometry(width() - 5 - 100 - 50, 5 + (35 * 4), 40 + 20, 30);
    ymax->setText("ymax = ");

    ResetM();
    Clean();
}

void MainWindow::Clean() {
    QColor lineColor(100, 100, 100);
    QColor axesColor(255, 0, 0);
    QColor filer(40, 40, 40);

    QPen pen;
    pen.setColor(lineColor);

    ui->label->setGeometry(5, 5 + 30 + 5, width() - 15 - CleanButton->width(), height() - 5 - 5 - 30 - 5);
    QPixmap pm(width()-5-5-CleanButton->width(), height() - 5);
    pm.fill(filer);
    ui->label->setPixmap(pm);
    ResultLine->setText("");
}

void MainWindow::ResetF() {
    FunctionLine->setText("");
}

void MainWindow::ResetM() {
    xminLine->setText("-10");
    xmaxLine->setText("10");
    yminLine->setText("-5");
    ymaxLine->setText("5");
}

void MainWindow::BuildSin() {
    FunctionLine->setText("sin(x)");
    xminLine->setText("-10");
    xmaxLine->setText("10");
    yminLine->setText("-3");
    ymaxLine->setText("3");
}

void MainWindow::BuildTg() {
    FunctionLine->setText("tg(x)");
    xminLine->setText("-10");
    xmaxLine->setText("10");
    yminLine->setText("-2");
    ymaxLine->setText("2");
}

void MainWindow::BuildX2() {
    FunctionLine->setText("x^2");
    xminLine->setText("-5");
    xmaxLine->setText("5");
    yminLine->setText("-1");
    ymaxLine->setText("5");
}

void MainWindow::Build1DX() {
    FunctionLine->setText("1/x");
    xminLine->setText("-3");
    xmaxLine->setText("3");
    yminLine->setText("-6");
    ymaxLine->setText("6");
}

void MainWindow::BuildSQRT() {
    FunctionLine->setText("sqrt(x)");
    xminLine->setText("-5");
    xmaxLine->setText("15");
    yminLine->setText("-4");
    ymaxLine->setText("7");
}

void MainWindow::BuildABS() {
    FunctionLine->setText("abs(x)");
    xminLine->setText("-6");
    xmaxLine->setText("6");
    yminLine->setText("-2");
    ymaxLine->setText("5");
}

void MainWindow::Build() {

    QColor lineColor(40, 255, 150);
    QColor axesColor(200, 200, 200);
    QColor filer(40, 40, 40);

    QPen pen;
    pen.setColor(lineColor);

    ui->label->setGeometry(5, 5 + 30 + 5, width() - 15 - BuildButton->width(), height() - 5 - 5 - 30 - 5);
    QPixmap pm(width()-5-5-BuildButton->width(), height() - 5);
    pm.fill(filer);

    QPainterPath path;
    QPainter painter;
    painter.begin(&pm);

    double pi = 3.14159265;

    QString xmin1 = xminLine->text();
    QString xmax1 = xmaxLine->text();
    if (xmin1 == "" || xmax1 == "") {
        ResultLine->setText("Error: null ymin/ymax");
        return;
    }
    double xmin = xmin1.toDouble();
    double xmax = xmax1.toDouble();
    if (xmin >= xmax) {
        ResultLine->setText("Error: xmin >= xmax");
        return;
    }
    else {
        ResultLine->setText("");
    }

    QString ymin1 = yminLine->text();
    QString ymax1 = ymaxLine->text();
    if (ymin1 == "" || ymax1 == "") {
        ResultLine->setText("Error: null ymin/ymax");
        return;
    }
    double ymin = ymin1.toDouble();
    double ymax = ymax1.toDouble();
    if (ymin >= ymax) {
        ResultLine->setText("Error: ymin >= ymax");
        return;
    }
    else {
        ResultLine->setText("");
    }

    double step = (xmax - xmin) / pm.height();


    int xgmin = 0;
    int xgmax = pm.width();
    int ygmin = 0;
    int ygmax = pm.height();


    double kx = (xgmax - xgmin) / (xmax - xmin);
    double ky = (ygmax - ygmin) / (ymax - ymin);

    int x0 = xgmin - kx * xmin;
    int y0 = ygmin - ky * ymin;

    double x, y;
    int xg, yg;

    //path.moveTo(0, pm.height() / 2);
    painter.setPen(axesColor);
    painter.drawLine(x0, 0, x0, pm.height());
    painter.drawLine(0, ygmax - y0, pm.width(), ygmax - y0);

    painter.setPen(lineColor);
    x = xmin;
    int flag = 1;
    QString s1 = FunctionLine->text();
    if (s1 == "") {
        ResultLine->setText("Error: null function");
        return;
    }

    for (int i = xgmin; i < xgmax; i++) {
        QString s1 = FunctionLine->text();
        QString s2 = s1.replace("x", "(" + QString::number(x) + ")");

        double my_ans = 0.0;
        bool p2 = calculate(s2.toStdString(), my_ans);
        if (p2 == 0) {
            //path.clear();
            flag = 1;
        }
        else {
            y = my_ans;

            if (y > ymax && flag == 0) {
                flag = 1;
            }
            else if (y < ymin && flag == 0) {
                flag = 1;
            }
            else {
                if (flag == 1) {
                    xg = xgmin + kx * (x - xmin);
                    yg = ygmin + ky * (ymax - y);
                    path.moveTo(xg, yg);
                    flag = 0;
                }
                else {
                    xg = xgmin + kx * (x - xmin);
                    yg = ygmin + ky * (ymax - y);
                    path.lineTo(xg, yg);
                }

            }
        }
        x += step;
    }

    painter.drawPath(path);

    ResultLine->setText("successfully");
    //painter.drawPath(path);
    ui->label->setPixmap(pm);
}

MainWindow::~MainWindow()
{
    delete ui;
}
