/*
 *  Copyright (c) 2020 Saurabh Kumar <saurabhk660@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __STORYBOARD_DELEGATE_H
#define __STORYBOARD_DELEGATE_H

#include <QStyledItemDelegate>

class QListView;
class StoryboardModel;

class StoryboardDelegate : public QStyledItemDelegate
{
public:
    StoryboardDelegate(QObject *parent);
    ~StoryboardDelegate() override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setView(QListView *view);
    void drawSpinBox(QPainter *p, const QStyleOptionViewItem &option, QString data) const;
    void drawComment(QPainter *p, const QStyleOptionViewItem &option, QString data, const QModelIndex &index) const;

    QRect spinBoxUpButton(const QStyleOptionViewItem &option);
    QRect spinBoxDownButton(const QStyleOptionViewItem &option);
    QRect spinBoxEditField(const QStyleOptionViewItem &option);
private:
    QListView *m_view;
};

#endif