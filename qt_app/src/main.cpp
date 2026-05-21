#include <iostream>

#include "antlr4-runtime.h"

#pragma execution_character_set("utf-8")
#include "MainWindow.h"

using namespace antlr4;
using namespace std;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Ui::MainWindow m = Ui::MainWindow();
    return QApplication::exec();
}