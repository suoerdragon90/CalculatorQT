#ifndef LOGIC_H
#define LOGIC_H

#include <QWidget>
#include <qboxlayout.h>

namespace Ui {
class logic;
}

class logic : public QWidget
{
    Q_OBJECT

public:
    explicit logic(QWidget *parent = nullptr);
    ~logic();
    void loadImagesFromFolder(const QString& folderName, QVBoxLayout* layout);
private:
    Ui::logic *ui;
};

#endif // LOGIC_H
