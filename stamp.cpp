#include "stamp.h"

Stamp::Stamp(QString Count, QString Name, QString Country, int Year, QObject *parent): QObject(parent)
{
    count = Count;
    name = Name;
    country = Country;
    year =Year;
}

void Stamp::SetYear(int Year)
{
    year = Year;
}

void Stamp::SetCount(QString Count)
{
    count = Count;
}
void Stamp::SetName(QString Name)
{
    name = Name;
}
void Stamp::SetСountry(QString Country)
{
    country = Country;
}
QString Stamp::Count()
{
    return count;
}
QString Stamp::Name()
{
    return name;
}
QString Stamp::Country()
{
    return country;
}

int Stamp::Year()
{
    return year;
}

QStringList Stamp::GetCountries()
{
    QStringList value;
    value.append("Австралия");
    value.append("Австрия");
    value.append("Азербайджан");
    value.append("Албания");
    value.append("Алжир");
    value.append("Ангола");
    value.append("Армения");
    value.append("Белоруссия");
    value.append("Бельгия");
    value.append("Болгария");
    value.append("Бразилия");
    value.append("Ватикан");
    value.append("Великобритания");
    value.append("Венгрия");
    value.append("Вьетнам");
    value.append("Греция");
    value.append("Грузия");
    value.append("Дания");
    value.append("Египет");
    value.append("Израиль");
    value.append("Индия");
    value.append("Индонезия");
    value.append("Иордания");
    value.append("Иран");
    value.append("Ирак");
    value.append("Ирландия");
    value.append("Исландия");
    value.append("Испания");
    value.append("Италия");
    value.append("Казахстан");
    value.append("Канада");
    value.append("Кипр");
    value.append("Китай");
    value.append("Корея");
    value.append("Латвия");
    value.append("Ливия");
    value.append("Литва");
    value.append("Мальта");
    value.append("Марокко");
    value.append("Мексика");
    value.append("Молдавия");
    value.append("Монако");
    value.append("Монголия");
    value.append("Нидерланды");
    value.append("Норвегия");
    value.append("ОАЭ");
    value.append("Пакистан");
    value.append("Польша");
    value.append("Португалия");
    value.append("Россия");
    value.append("Румыния");
    value.append("Сербия");
    value.append("Словакия");
    value.append("СССР");
    value.append("США");
    value.append("Турция");
    value.append("Украина");
    value.append("Хорватия");
    value.append("Франция");
    value.append("Швеция");
    value.append("Швейцария");
    value.append("Япония");
    return value;
}

 Stamp::~Stamp()
{
}
