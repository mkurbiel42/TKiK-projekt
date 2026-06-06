//
// Created by komp on 21.05.2026.
//

#include <iostream>
#include "MainWindow.h"
#include <QtWidgets/QFileDialog>
#include <QMessageBox>
#include "Translator.h"

using namespace std;
using namespace Ui;

MainWindow::MainWindow() : Ui_MainWindow() {
    std::cout << "should initialize" << std::endl;
    this->setupUi(this);
    this->setupActions();
    this->showMaximized();
}

void MainWindow::setupActions() {
    this->actionFileOpen->connect(actionFileOpen, QAction::triggered, this, [this] {handleFileOpen();});
    this->actionFileSave->connect(actionFileSave, QAction::triggered, this, [this] {handleFileSave();});
    this->actionTranslate->connect(actionTranslate, QAction::triggered, this, [this] {handleTranslate();});
}

void MainWindow::handleFileOpen() {
    auto dialog = QFileDialog(this);
    auto filters = QStringList{"Python code file (*.py)", "Text file (*.txt)"};

    dialog.setNameFilters(filters);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    if (dialog.exec()) {
        auto inputFile = QFile(dialog.selectedFiles()[0]);

        if (!inputFile.open(QIODevice::ReadOnly|QIODevice::Text))
            return;

        QTextStream input(&inputFile);
        QString inputText = input.readAll();

        this->textEdit->setPlainText(inputText);
    }
}

void MainWindow::handleFileSave() {
    auto dialog = QFileDialog(this);
    auto filters = QStringList{"JavaScript code file (*.js)", "Text file (*.txt)"};

    dialog.setNameFilters(filters);
    dialog.setAcceptMode(QFileDialog::AcceptSave);

    if (dialog.exec()) {
        auto outputFile = QFile(dialog.selectedFiles()[0]);

        if (!outputFile.open(QIODevice::ReadWrite | QIODevice::Text))
            return;

        QTextStream output(&outputFile);
        output << textEdit_2->toPlainText();
    }
}

void MainWindow::handleTranslate() {
    string translation = Translator::translate(this->textEdit->toPlainText().toStdString());
    if (Translator::errors.size()>0) {
        QMessageBox msgBox = QMessageBox(this);
        string text;
        if (Translator::areErrorsFatal) {
            text = "The code could not be translated, translator found errors:\n\n";
            msgBox.setWindowTitle("Fatal translation error");
        }
        else {
            text = "Translator found errors. The code was partially translated, however the output will most likely differ from the desired translation. Errors in the output have been replaced with comments.\n\n";
            msgBox.setWindowTitle("Translation error");
        }
        for (auto m: Translator::errors) text += m + "\n";
        msgBox.setText(QString::fromStdString(text));
        msgBox.exec();
    }
    textEdit_2->setPlainText(QString::fromStdString(translation));
}