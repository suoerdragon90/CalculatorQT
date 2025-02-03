#include "longdivation.h"
#include "ui_longdivation.h"

LongDivation::LongDivation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LongDivation)
{
    ui->setupUi(this);
    setWindowTitle("Long Div");

    // Try loading images from original paths
    backgroundPixmap = QPixmap("/Media/background/calc.jpg");
    logoPixmap = QPixmap("/Media/background/logo.ico");

    // If original paths fail, try relative paths
    if (backgroundPixmap.isNull()) {
        QString appDir = QCoreApplication::applicationDirPath();
        backgroundPixmap = QPixmap(appDir + "/Media/background/calc.jpg");
        if (backgroundPixmap.isNull()) {
            qDebug() << "Failed to load background image from both paths";
        }
    }

    if (logoPixmap.isNull()) {
        QString appDir = QCoreApplication::applicationDirPath();
        logoPixmap = QPixmap(appDir + "/Media/background/logo.ico");
        if (logoPixmap.isNull()) {
            qDebug() << "Failed to load logo from both paths";
        }
    }

    setWindowIcon(QIcon(logoPixmap));

    // Set text fields to read-only
    ui->text_a->setReadOnly(true);
    ui->text_n->setReadOnly(true);
    ui->text_q->setReadOnly(true);
    ui->text_r->setReadOnly(true);
}

LongDivation::~LongDivation()
{
    delete ui;
}

void LongDivation::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    // Draw background with opacity if loaded
    if (!backgroundPixmap.isNull()) {
        qreal opacity = 0.1;
        painter.setOpacity(opacity);
        painter.drawPixmap(0, 0, width(), height(), backgroundPixmap);
    }

    // Draw logo if loaded
    if (!logoPixmap.isNull()) {
        int logoSize = 32;  // Set a reasonable size for the logo
        painter.setOpacity(1.0);  // Reset opacity for logo
        painter.drawPixmap(10, 10, logoSize, logoSize, logoPixmap);
    }
}

void LongDivation::on_calculate_clicked()
{
    QString number = ui->text_num->toPlainText();
    QString number2 = ui->text_div->toPlainText();
    bool ok1, ok2;
    double num = number.toDouble(&ok1);
    double div = number2.toDouble(&ok2);

    if (ok1 && ok2 && div != 0) {
        // Valid input case
        ui->text_a->setPlainText(number);
        ui->text_n->setPlainText(number2);

        int quotient = num / div;
        double reminder = num - (quotient * div);

        ui->text_q->setPlainText(QString::number(quotient, 'f', 2));
        ui->text_r->setPlainText(QString::number(reminder, 'f', 2));
    } else {
        // Invalid input case
        QString errorMsg = "Invalid Input";
        ui->text_a->setPlainText(errorMsg);
        ui->text_n->setPlainText(errorMsg);
        ui->text_q->setPlainText(errorMsg);
        ui->text_r->setPlainText(errorMsg);
    }
}
