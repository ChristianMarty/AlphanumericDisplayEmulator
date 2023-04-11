#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AlphanumericDisplay.h"

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

    void on_hoverEdit_textChanged(const QString &arg1);
    void on_staticEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    AlphanumericDisplay _alphanumericDisplay = AlphanumericDisplay(4, 20, this);

};



#endif // MAINWINDOW_H
