#ifndef LONGDIVATION_H
#define LONGDIVATION_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>

namespace Ui {
class LongDivation;
}

class LongDivation : public QWidget
{
    Q_OBJECT

public:
    explicit LongDivation(QWidget *parent = nullptr);
    ~LongDivation();

protected:
    void paintEvent(QPaintEvent*) override;

private slots:
    void on_calculate_clicked();

private:
    Ui::LongDivation *ui;
    QPixmap backgroundPixmap;
    QPixmap iconPixmap;
    QPixmap logoPixmap;
};

#endif // LONGDIVATION_H
