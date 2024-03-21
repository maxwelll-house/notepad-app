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
    // Opens a dialog for saving a file
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");

    // An object for reading and writing files
    QFile file(fileName);

    // Try to open a file with write only options
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }

    // Store the currentFile name
    currentFile = fileName;

    // Set the title for the window to the file name
    setWindowTitle(fileName);

    // Interface for writing text
    QTextStream out(&file);

    // Copy text in the textEdit widget and convert to plain text
    QString text = ui.textEdit->toPlainText();

    // Output to file
    out << text;

    // Close the file
    file.close();
}

void NotepadMain::on_actionPrint_triggered()
{
    // Allows for interacting with printer
    QPrinter printer;

    // You'll put your printer name here
    printer.setPrinterName("Printer Name");

    // Create the print dialog and pass the name and parent
    QPrintDialog pDialog(&printer, this);

    if (pDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }

    // Send the text to the printer
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