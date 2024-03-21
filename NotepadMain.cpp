#include "NotepadMain.h"

NotepadMain::NotepadMain(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setCentralWidget(ui.textEdit);
}

NotepadMain::~NotepadMain()
{}

void NotepadMain::on_actionNew_triggered()
{
    currentFile.clear();
    ui.textEdit->setText(QString());
}


void NotepadMain::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui.textEdit->setText(text);
    file.close();
}

void NotepadMain::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui.textEdit->toPlainText();
    out << text;
    file.close();
}

void NotepadMain::on_actionSaveAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui.textEdit->toPlainText();
    out << text;
    file.close();
}

void NotepadMain::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if (pDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }
    ui.textEdit->print(&printer);
}

void NotepadMain::on_actionExit_triggered()
{
    QApplication::quit();
}


void NotepadMain::on_actionCopy_triggered()
{
    ui.textEdit->copy();
}

void NotepadMain::on_actionCut_triggered()
{
    ui.textEdit->cut();
}

void NotepadMain::on_actionPaste_triggered()
{
    ui.textEdit->paste();
}

void NotepadMain::on_actionUndo_triggered()
{
    ui.textEdit->undo();
}

void NotepadMain::on_actionRedo_triggered()
{
    ui.textEdit->redo();
}