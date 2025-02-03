#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <QWidget>
#include "TabLes.h"
#include "simple.h"
#include "logic.h"
#include <QCloseEvent>
#include <QPixmap>
#include <QPainter>


namespace Ui {
class EquaTions;
}

class EquaTions : public QWidget
{
    Q_OBJECT

public:
     EquaTions(QWidget *parent = nullptr);
    ~EquaTions();
     bool evaluateExpression(bool P, bool Q, bool R);
protected:
    void closeEvent(QCloseEvent *event) override;
    void paintEvent(QPaintEvent*) override;
private slots:
  void on_p1_clicked();
  void on_p2_clicked();
  void on_p3_clicked();
  void on_EQ_Solve_clicked();



private:
    Ui::EquaTions *ui;
    TabLes *Tables;
    simple *simple;
    logic *logic;
     void calculateAndDisplayResult();
    QPixmap backgroundPixmap;
    QPixmap iconPixmap;
    QPixmap logoPixmap;

};

#endif // EQUATIONS_H
