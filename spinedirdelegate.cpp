#include "spinedirdelegate.h"
#include "QtWidgets"
#include "editdialog.h"
#include "QStyledItemDelegate"

spinedirDelegate::spinedirDelegate(): QStyledItemDelegate()
{

}


QWidget *spinedirDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &,
    const QModelIndex &) const
{
    QSpinBox* edt = new QSpinBox(parent);
    edt->setMinimum(1700);
    edt->setMaximum(2022);
    return edt;
}

void spinedirDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    QSpinBox *myeditor = static_cast<QSpinBox*>(editor);
    myeditor->setMaximum(2022);
    myeditor->setMinimum(1700);
    QString value = myeditor->text();
    model->setData(index, value, Qt::EditRole);
}

void spinedirDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QSpinBox *myeditor = qobject_cast<QSpinBox *>(editor);
    myeditor->setMaximum(2022);
    myeditor->setMinimum(1700);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    myeditor->setValue(currentText.toInt());
}


void spinedirDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  if (option.state & QStyle :: State_MouseOver)
  {
      QRect rect = option.rect;
      QBrush brush(Qt::blue);

      painter->setBrush(brush);
      painter->drawRect(rect);
  }
  QStyledItemDelegate::paint(painter, option, index);
}
