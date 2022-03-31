#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "stamp.h"

class EditDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editCount;
    QLineEdit* editName;
    QComboBox* editCountry;
    QSpinBox* editYear;

public:
    EditDialog(QWidget* pwgt = nullptr);

    QString count() const;
    QString name() const;
    QString country() const;
    int year() const;

    void SetUpDialog(QString count, QString name,QString country, int year);
};

#endif // INPUTDIALOG_H
