#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "LogicalForm.h"
#include "LongDivation.h"
#include "Equations.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QPixmap>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();

private:
    Ui::MainWindow *ui;
    LogicalForm *Logicalform;
    LongDivation *Longdivation;
    EquaTions *Equations;
    QPixmap backgroundPixmap;
    QPixmap iconPixmap;
    QPixmap logoPixmap;
};

#endif // MAINWINDOW_H
