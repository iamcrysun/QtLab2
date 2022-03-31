#include "dialogdelegate.h"
#include "QtWidgets"
#include "editdialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;

}


bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditDialog* editDialog = new EditDialog(dparentWidget);

        QString Count = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Country = model->data(model->index(index.row(),2,index)).toString();
        int Year = model->data(model->index(index.row(),3,index)).toInt();



        editDialog->SetUpDialog(Count, Name, Country, Year);
        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->count());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->country());
            model->setData(model->index(index.row(),3,index),editDialog->year());
        }

         editDialog->deleteLater();
    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget*,const QStyleOptionViewItem &,const QModelIndex &) const
{
    return nullptr;
}
