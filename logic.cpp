#include "logic.h"
#include "ui_logic.h"
#include <QDir>
#include <QPixmap>
#include <QLabel>

logic::logic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::logic)
{
    ui->setupUi(this);
    QWidget* contentWidget = new QWidget();
    QVBoxLayout* contentLayout = new QVBoxLayout(contentWidget);

    // Load images from the folders
    loadImagesFromFolder("gates", contentLayout);

    // Add stretch to push content to the top if there's extra space
    contentLayout->addStretch();

    // Set the content widget in the scroll area
    ui->scrollArea->setWidget(contentWidget);
    ui->scrollArea->setWidgetResizable(true);
}

logic::~logic()
{
    delete ui;
}

void logic::loadImagesFromFolder(const QString& folderName, QVBoxLayout* layout) {
    QString basePath = QCoreApplication::applicationDirPath(); // Get application directory

    //Find the Media directory relative to application directory.  Adjust if needed.
    QDir mediaDir(basePath + "/Media"); //Assumes Media is in application directory
    if (!mediaDir.exists()) {
        qDebug() << "Error: Media directory not found at:" << mediaDir.absolutePath();
        return; // or handle the error appropriately
    }

    QDir dir(mediaDir.absolutePath() + "/" + folderName); //Construct the full path
    if (!dir.exists()) {
        qDebug() << "Error: Folder not found: " << dir.absolutePath();
        return; // or handle the error appropriately
    }

    QStringList imageFiles = dir.entryList(QStringList() << "*.jpg" << "*.png" << "*.jpeg", QDir::Files); //Explicitly list image types

    for (const QString& file : imageFiles) {
        QString fullPath = dir.absolutePath() + "/" + file;

        qDebug() << "Trying to load image: " << fullPath;

        QPixmap pixmap(fullPath);
        if (pixmap.isNull()) {
            qDebug() << "Failed to load image: " << fullPath;
            continue;
        }

        QLabel* imageLabel = new QLabel();
        imageLabel->setPixmap(pixmap.scaled(1000, 1200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        layout->addWidget(imageLabel);
    }
}
