#include "logicalform.h"
#include "ui_logicalform.h"

LogicalForm::LogicalForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogicalForm)
{
    ui->setupUi(this);
    setWindowTitle("Logical Solver");

    // Try loading images from original paths
    backgroundPixmap = QPixmap("/Media/background/bgl.jpg");
    logoPixmap = QPixmap("/Media/background/logo.ico");

    // If original paths fail, try relative paths
    if (backgroundPixmap.isNull()) {
        QString appDir = QCoreApplication::applicationDirPath();
        backgroundPixmap = QPixmap(appDir + "/Media/background/bgl.jpg");
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
}

LogicalForm::~LogicalForm()
{
    delete ui;
}

void LogicalForm::paintEvent(QPaintEvent*)
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

void LogicalForm::on_conjunction_clicked()
{
    ui->label_log->setText("∧");
    if(ui->comboBox_p1->currentText()=="True"&&ui->comboBox_q1->currentText()=="True")
    {
        ui->label_r1->setText("True");
    }else
    {
        ui->label_r1->setText("False");
    }
    if(ui->comboBox_p2->currentText()=="True"&&ui->comboBox_q2->currentText()=="True")
    {
        ui->label_r2->setText("True");
    }else
    {
        ui->label_r2->setText("False");
    }
    if(ui->comboBox_p3->currentText()=="True"&&ui->comboBox_q3->currentText()=="True")
    {
        ui->label_r3->setText("True");
    }else
    {
        ui->label_r3->setText("False");
    }
    if(ui->comboBox_p4->currentText()=="True"&&ui->comboBox_q4->currentText()=="True")
    {
        ui->label_r4->setText("True");
    }else
    {
        ui->label_r4->setText("False");
    }
}

void LogicalForm::on_disjunction_clicked()
{
    ui->label_log->setText("∨");
    if(ui->comboBox_p1->currentText()=="True"||ui->comboBox_q1->currentText()=="True")
    {
        ui->label_r1->setText("True");
    }else
    {
        ui->label_r1->setText("False");
    }
    if(ui->comboBox_p2->currentText()=="True"||ui->comboBox_q2->currentText()=="True")
    {
        ui->label_r2->setText("True");
    }else
    {
        ui->label_r2->setText("False");
    }
    if(ui->comboBox_p3->currentText()=="True"||ui->comboBox_q3->currentText()=="True")
    {
        ui->label_r3->setText("True");
    }else
    {
        ui->label_r3->setText("False");
    }
    if(ui->comboBox_p4->currentText()=="True"||ui->comboBox_q4->currentText()=="True")
    {
        ui->label_r4->setText("True");
    }else
    {
        ui->label_r4->setText("False");
    }
}

void LogicalForm::on_impliaction_clicked()
{
    ui->label_log->setText("->");
    if(ui->comboBox_p1->currentText()=="True"&&ui->comboBox_q1->currentText()=="False")
    {
        ui->label_r1->setText("False");
    }else
    {
        ui->label_r1->setText("True");
    }
    if(ui->comboBox_p2->currentText()=="True"&&ui->comboBox_q2->currentText()=="False")
    {
        ui->label_r2->setText("False");
    }else
    {
        ui->label_r2->setText("True");
    }
    if(ui->comboBox_p3->currentText()=="True"&&ui->comboBox_q3->currentText()=="False")
    {
        ui->label_r3->setText("False");
    }else
    {
        ui->label_r3->setText("True");
    }
    if(ui->comboBox_p4->currentText()=="True"&&ui->comboBox_q4->currentText()=="False")
    {
        ui->label_r4->setText("False");
    }else
    {
        ui->label_r4->setText("True");
    }
}

void LogicalForm::on_doubleimplication_clicked()
{
    ui->label_log->setText("<->");
    if(ui->comboBox_p1->currentText()=="True"&&ui->comboBox_q1->currentText()=="True"||ui->comboBox_p1->currentText()=="False"&&ui->comboBox_q1->currentText()=="False")
    {
        ui->label_r1->setText("True");
    }else
    {
        ui->label_r1->setText("False");
    }
    if(ui->comboBox_p2->currentText()=="True"&&ui->comboBox_q2->currentText()=="True"||ui->comboBox_p2->currentText()=="False"&&ui->comboBox_q2->currentText()=="False")
    {
        ui->label_r2->setText("True");
    }else
    {
        ui->label_r2->setText("False");
    }
    if(ui->comboBox_p3->currentText()=="True"&&ui->comboBox_q3->currentText()=="True"||ui->comboBox_p3->currentText()=="False"&&ui->comboBox_q3->currentText()=="False")
    {
        ui->label_r3->setText("True");
    }else
    {
        ui->label_r3->setText("False");
    }
    if(ui->comboBox_p4->currentText()=="True"&&ui->comboBox_q4->currentText()=="True"||ui->comboBox_p4->currentText()=="False"&&ui->comboBox_q4->currentText()=="False")
    {
        ui->label_r4->setText("True");
    }else
    {
        ui->label_r4->setText("False");
    }
}
