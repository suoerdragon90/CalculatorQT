#include "Tables.h"
#include "ui_TabLes.h"

TabLes::TabLes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TabLes)
{
    ui->setupUi(this);
    setWindowTitle("TabLes");

    // Try loading images from original paths
    backgroundPixmap = QPixmap("G:/Data Structure Project/Discreete_Finale_forreal/Discreete/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/Media/background/bgt.jpg");
    logoPixmap = QPixmap("G:/Data Structure Project/Discreete_Finale_forreal/Discreete/build/Desktop_Qt_6_8_1_MinGW_64_bit-Debug/Media/background/logo.ico");

    // If original paths fail, try relative paths
    if (backgroundPixmap.isNull()) {
        QString appDir = QCoreApplication::applicationDirPath();
        backgroundPixmap = QPixmap(appDir + "/Media/background/bgt.jpg");
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

TabLes::~TabLes()
{
    delete ui;
}

void TabLes::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    // Draw background with opacity if loaded
    if (!backgroundPixmap.isNull()) {
        qreal opacity = 0.05;  // Maintaining the very light opacity
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

void TabLes::on_p1_clicked()
{
    this->hide();
}
