#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qdir.h"
#include "qdebug.h"
#include <windows.h>

QStringList fileNames = {
    "Incident and Illness Report",
    "Diaper Sheet",
    "Meal Bundle",
    "Breakfast Sheet",
    "Lunch Sheet",
    "Dinner Sheet",
    "Infant Care Report",
    "Tour Sheet"
};

QDir dir = QDir("C:/Users/Wannaplay/Desktop/Wanna Play Documents");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->insertItems(0, fileNames);
    //ui->comboBox->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int copyNum = 1;

    if (ui->lineEdit->hasAcceptableInput()) {
        copyNum = ui->lineEdit->text().toInt();
    }

    int comboIndex = ui->comboBox->currentIndex();

    const char* filePath = qUtf8Printable(dir.filePath(fileNames[comboIndex] + ".pdf"));
    qDebug() << filePath;

    for (int i = 0; i < copyNum; i++) {
        ShellExecuteA(NULL, "print", filePath, NULL, NULL, SW_SHOWNORMAL);
    }
}

