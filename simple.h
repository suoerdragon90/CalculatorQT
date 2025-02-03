#ifndef SIMPLE_H
#define SIMPLE_H

#include <QWidget>
#include <qboxlayout.h>

namespace Ui {
class simple;
}

class simple : public QWidget
{
    Q_OBJECT

public:
    explicit simple(QWidget *parent = nullptr);
    ~simple();
    void loadImagesFromFolder(const QString& folderName, QVBoxLayout* layout);
private:
    Ui::simple *ui;
};

#endif // SIMPLE_H
