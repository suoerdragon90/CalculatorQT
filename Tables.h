#ifndef TABLES_H
#define TABLES_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
namespace Ui {
class TabLes;
}

class TabLes : public QWidget
{
    Q_OBJECT

public:
    explicit TabLes(QWidget *parent = nullptr);
    ~TabLes();
protected:
    void paintEvent(QPaintEvent*) override;

private slots:
    void on_p1_clicked();

private:
    Ui::TabLes *ui;
    QPixmap backgroundPixmap;
    QPixmap iconPixmap;
    QPixmap logoPixmap;
};

#endif // TABLES_H
