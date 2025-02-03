#ifndef LOGICALFORM_H
#define LOGICALFORM_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>

namespace Ui {
class LogicalForm;
}

class LogicalForm : public QWidget
{
    Q_OBJECT

public:
    explicit LogicalForm(QWidget *parent = nullptr);
    ~LogicalForm();

protected:
    void paintEvent(QPaintEvent*) override;

private slots:
    void on_conjunction_clicked();
    void on_disjunction_clicked();
    void on_impliaction_clicked();
    void on_doubleimplication_clicked();


private:
    Ui::LogicalForm *ui;
    QPixmap backgroundPixmap;
    QPixmap iconPixmap;
    QPixmap logoPixmap;
};

#endif // LOGICALFORM_H
