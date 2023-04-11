#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QOpenGLWidget>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setViewport(new QOpenGLWidget());
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    ui->graphicsView->setScene(_alphanumericDisplay.scene());
    ui->graphicsView->update();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_hoverEdit_textChanged(const QString &arg1)
{
    _alphanumericDisplay.writeHover(arg1);
}


void MainWindow::on_staticEdit_textChanged(const QString &arg1)
{
    _alphanumericDisplay.write(arg1);
}

