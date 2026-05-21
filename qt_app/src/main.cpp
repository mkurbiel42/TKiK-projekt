#include <QApplication>
#include <QPushButton>

#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Ui::MainWindow m = Ui::MainWindow();
    return QApplication::exec();
}
