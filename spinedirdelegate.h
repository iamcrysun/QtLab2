#ifndef SPINEDIRDELEGATE_H
#define SPINEDIRDELEGATE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "QtWidgets"

class spinedirDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    spinedirDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void paint(QPainter* painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
};

#endif // SPINEDIRDELEGATE_H
