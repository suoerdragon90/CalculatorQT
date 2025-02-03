#include "mainwindow.h"
#include <QApplication>
#ifdef Q_OS_WINDOWS
#include <Windows.h>
#endif

#ifdef Q_OS_WINDOWS
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char *argv[])
#endif
{
#ifdef Q_OS_WINDOWS
    int argc = 0;
    char **argv = nullptr;
#endif
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
