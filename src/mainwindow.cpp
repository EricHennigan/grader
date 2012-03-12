#include <QFileDialog>
#include <QTableView>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qxtcsvmodel.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menuOpenRoster_triggered()
{
    ui->statusBar->showMessage("Opening Roster...");
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Roster"),
                                                    "",
                                                    tr("CSV and text (*.csv *.txt)"));

    if (fileName.isEmpty())
        return;
    ui->statusBar->showMessage("Opening Roster " + fileName, 2000);

    QxtCsvModel *model = new QxtCsvModel(fileName, this, true);
    QTableView *table = new QTableView(this);
    table->setModel(model);
    this->setCentralWidget(table);

    // todo: verify that the following headers are present
    //       FirstName, LastName, StandardName, UniqueId, EmailAddress
    // todo: put this widget into a dock
    // todo: subclass the QxtCsvModel?
    //       provide student selection (row selection)
    //       provide editing
    //       provide sorting on columns
}

