#include "editdialog.h"
#include "stamp.h"
EditDialog::EditDialog(QWidget* pwgt): QDialog(pwgt)
{
    editCount = new QLineEdit();
    editName = new QLineEdit();
    editCountry = new QComboBox();
    editYear = new QSpinBox ();
    editYear->setMinimum(1700);
    editYear->setMaximum(2022);
    QStringList countries = Stamp::GetCountries();
    foreach  (QString ct, countries)
    {
        editCountry->addItem(ct);
    }

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("Тираж"),1,1);
    mainLayout->addWidget(editCount,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Страна"),3,1);
    mainLayout->addWidget(editCountry,3,2);
    mainLayout->addWidget(new QLabel("Год"),4,1);
    mainLayout->addWidget(editYear,4,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,5,1,1,2);


    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Внесение новой марки");


    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditDialog::count() const
{
    return editCount->text();
}
QString EditDialog::name() const
{
    return editName->text();
}
QString EditDialog::country() const
{
    return editCountry->currentText();
}

int EditDialog::year() const
{
    return editYear->value();
}


void EditDialog::SetUpDialog(QString count, QString name,QString country, int year)
{
    editCount->setText(count);
    editName->setText(name);

    int ind = editCountry->findText(country);
    if (ind>=0)
    {
        editCountry->setCurrentIndex(ind);
    }
    editYear->setValue(year);
}
