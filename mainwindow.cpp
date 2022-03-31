#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "mymodel.h"
#include "QGridLayout"
#include "countrydelegate.h"
#include "linedelegate.h"
#include "editdialog.h"
#include "dialogdelegate.h"
#include "spinedirdelegate.h"
#include "runline.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);



    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel( myModel );

    DialogDelegate* ddel = new DialogDelegate(nullptr,this);
    CountryDelegate* cdel = new CountryDelegate();
    lineDelegate* ldel = new lineDelegate();
    spinedirDelegate* ldel1 = new spinedirDelegate();
    tableView->setItemDelegateForColumn(0,ddel);
    tableView->setItemDelegateForColumn(1,ldel);
    tableView->setItemDelegateForColumn(2,cdel);
    tableView->setItemDelegateForColumn(3,ldel1);
    tableView->viewport()->setAttribute(Qt::WA_Hover);


    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,2);

    QPushButton* pb1 = new QPushButton("Добавить");
    QPushButton* pb2 = new QPushButton("Удалить");

    glay->addWidget(pb1,2,1);
    glay->addWidget(pb2,2,2);

    QObject::connect(pb1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(pb2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));

    QSpinBox *speedSpinbox(new QSpinBox(this));
    QLineEdit *textLine(new QLineEdit(this));
    RunLine *runline(new RunLine(this));

    glay->addWidget(textLine, 3, 1, 1, 1);
    glay->addWidget(speedSpinbox, 3, 2, 1, 1);
    glay->addWidget(runline, 4, 1, 1, 2);

    connect(speedSpinbox, SIGNAL(valueChanged(int)), runline, SLOT(setSpeed(int)));
    connect(textLine, SIGNAL(textChanged(QString)), runline, SLOT(setString(QString)));


    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);
    this->setGeometry(100, 100, 500, 300);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditDialog* addDialog = new EditDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Stamp* std = new Stamp(addDialog->count(),addDialog->name(),addDialog->country(), addDialog->year(), this);
        myModel->AddStamp(std);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    myModel->DeleteStamp(selList.row());
}
