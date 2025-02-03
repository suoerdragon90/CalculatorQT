#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Logicalform(nullptr),
    Longdivation(nullptr),
    Equations(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Discreete Project");

    // Try loading images from original paths
    backgroundPixmap = QPixmap("/Media/background/bg.png");
    logoPixmap = QPixmap("/Media/background/logo.ico");

    // If original paths fail, try relative paths
    if (backgroundPixmap.isNull()) {
        QString appDir = QCoreApplication::applicationDirPath();
        backgroundPixmap = QPixmap(appDir + "/Media/background/bg.png");
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

MainWindow::~MainWindow()
{
    if (Logicalform) {
        Logicalform->close();
        delete Logicalform;
    }
    if (Longdivation) {
        Longdivation->close();
        delete Longdivation;
    }
    if (Equations) {
        Equations->close();
        delete Equations;
    }
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (Logicalform) {
        Logicalform->close();
    }
    if (Longdivation) {
        Longdivation->close();
    }
    if (Equations) {
        Equations->close();
    }
    event->accept();
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    // Draw background with opacity if loaded
    if (!backgroundPixmap.isNull()) {
        qreal opacity = 0.5;
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

void MainWindow::on_b1_clicked()
{
    if(!Logicalform) {
        Logicalform = new LogicalForm();
    }
    Logicalform->show();
}

void MainWindow::on_b2_clicked()
{
    if(!Longdivation) {
        Longdivation = new LongDivation();
    }
    Longdivation->show();
}

void MainWindow::on_b3_clicked()
{
    if(!Equations) {
        Equations = new EquaTions();
    }
    Equations->show();
}
