//
// Created by komp on 21.05.2026.
//

#include <iostream>
#include <fstream>
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
    this->actionRun->connect(actionRun, QAction::triggered, this, [this] {handleRun();});
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

void MainWindow::handleRun() {
#ifndef _WIN32
    QMessageBox msgBox = QMessageBox(this);
    msgBox.setWindowTitle("Error");
    msgBox.setText("Running translated code is only supported on Windows");
    msgBox.exec();
    return;
#endif
    try {
        auto fp = filesystem::current_path();
        while (!fp.generic_string().ends_with("TKiK-projekt") && fp.has_parent_path())
            fp = fp.parent_path();
        if (!fp.has_parent_path()) throw runtime_error("Could not find directory");
        fp += "/qt_app";
        string filename = "tmpfile.js";
        string filepath = fp.generic_string() + "/" + filename;
        ofstream tmpfile(filepath);
        tmpfile << textEdit_2->toPlainText().toStdString();
        tmpfile.close();
        string cmd = "start /d \"" + fp.generic_string()+ "\" " + fp.generic_string() + "/runnode.bat";
        system(cmd.c_str());
        // filesystem::remove(filepath);
    }catch (exception& e) {
        QMessageBox msgBox = QMessageBox(this);
        msgBox.setWindowTitle("Error");
        msgBox.setText("There was an error running the code:\n"+QString::fromStdString(e.what()));
        msgBox.exec();
    }
}