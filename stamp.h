#ifndef STAMP_H
#define STAMP_H
#include "QString"
#include <QObject>

class Stamp: public QObject
{
    Q_OBJECT

public:
    Stamp(QString Count, QString Name, QString Value, int Year, QObject *parent = nullptr );
    virtual ~Stamp();
    void SetCount(QString Count);
    void SetName(QString Name);
    void SetСountry(QString Value);
    void SetYear(int Year);

    QString Count();
    QString Name();
    QString Country();
    static QStringList GetCountries();
    int Year();
private:
    QString count;
    QString name;
    QString country;
    int year;
};



#endif // STAMP_H
