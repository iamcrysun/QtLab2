#include "countrydelegate.h"
#include "QtWidgets"
#include "stamp.h"
CountryDelegate::CountryDelegate(QObject *parent): QItemDelegate(parent)
{

}


QWidget *CountryDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &,
    const QModelIndex &) const
{
    QComboBox* cmb = new QComboBox(parent);
    QStringList countries = Stamp::GetCountries();
    foreach  (QString fc, countries)
    {
        cmb->addItem(fc);
    }
    return cmb;
}

void CountryDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    QComboBox *myeditor = static_cast<QComboBox*>(editor);

    QString value = myeditor->currentText();

    model->setData(index, value, Qt::EditRole);
}

void CountryDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QComboBox *myeditor = qobject_cast<QComboBox *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    const int cbIndex = myeditor->findText(currentText);
    if (cbIndex >= 0)
       myeditor->setCurrentIndex(cbIndex);
}



