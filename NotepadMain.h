#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NotepadMain.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

class NotepadMain : public QMainWindow
{
    Q_OBJECT

public:
    NotepadMain(QWidget* parent = nullptr);
    ~NotepadMain();
private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionPrint_triggered();
    void on_actionExit_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
private:
    Ui::NotepadMainClass ui;
    QString currentFile = "";
};
