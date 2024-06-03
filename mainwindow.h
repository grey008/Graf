#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPushButton *BuildButton;
    QPushButton *CleanButton;
    QPushButton *ResetFButton;
    QPushButton *ResetMButton;
    QPushButton *BuildSinButton;
    QPushButton *BuildTgButton;
    QPushButton *BuildX2Button;
    QPushButton *Build1DXButton;
    QPushButton *BuildSQRTButton;
    QPushButton *BuildABSButton;

    QLineEdit *FunctionLine;
    QLineEdit *xminLine;
    QLineEdit *xmaxLine;
    QLineEdit *yminLine;
    QLineEdit *ymaxLine;
    QLineEdit *ResultLine;
    QLabel *Function;
    QLabel *xmin;
    QLabel *xmax;
    QLabel *ymin;
    QLabel *ymax;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void Build();
    void Clean();
    void ResetF();
    void ResetM();
    void BuildSin();
    void BuildTg();
    void BuildX2();
    void Build1DX();
    void BuildSQRT();
    void BuildABS();
};

#endif // MAINWINDOW_H
