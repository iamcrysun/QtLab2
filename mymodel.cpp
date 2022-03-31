#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{

    Stamp* std1 = new Stamp("100000","Марка 1","Испания", 2002, this);
    Stamp* std2 = new Stamp("1023456789","Марка 2","Франция", 2007, this);
    Stamp* std3 = new Stamp("6785","Марка 3","СССР", 2012, this);
    AddStamp(std1);
    AddStamp(std2);
    AddStamp(std3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return stamps.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 4;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Stamp* std = stamps.at(index.row());
        if (index.column() == 0){Value = std->Count();}
        else if (index.column() == 1){Value = std->Name();}
        else if (index.column() == 2){Value = std->Country();}
        else if (index.column() == 3){
            int a = std->Year();
            QString b=QString::number(a);
            Value = b;}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Тираж");
            case 1:
                return QString("Название");
            case 2:
                return QString("Страна");
            case 3:
                return QString("Год");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Stamp* std = stamps.at(index.row());
        if (index.column() == 0){std->SetCount(value.toString());}
        else if (index.column() == 1){std->SetName(value.toString());}
        else if (index.column() == 2){std->SetСountry(value.toString());}
        else if (index.column() == 3){std->SetYear(value.toInt());}
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & ) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void MyModel::AddStamp(Stamp* stamp)
{
    beginInsertRows(QModelIndex(),stamps.size(),stamps.size());
    stamps.append(stamp);
    endInsertRows();

}

void MyModel::DeleteStamp(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    stamps.removeAt(row);
    endRemoveRows();

}

