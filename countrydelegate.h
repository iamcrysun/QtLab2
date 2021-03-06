#pragma once
#define MYMODEL_H

#include "QtWidgets"

class CountryDelegate: public QItemDelegate
{
    Q_OBJECT
public:
    CountryDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

};
