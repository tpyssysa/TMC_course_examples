/***************************************************************************
*                                                                          *
*                customview.cpp for 04_custom_view                         *
*                Created on  : Wed Mar 22 2017 15:43                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "customview.h"
#include <QKeyEvent>

CustomView::CustomView(QWidget *parent) :
    QTableView(parent)
{
    setAlternatingRowColors(true);
    setStyleSheet("QTableView { selection-background-color: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5, stop: 0 blue, stop: 1 white); gridline-color: blue; background-color: lightblue; alternate-background-color: lightgray; }"
                  );
}

void CustomView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_D) {
        QModelIndexList indexList = selectedIndexes();
        if (!indexList.isEmpty()) {
            int previousRowDeleted(-1);
            for (QModelIndexList::const_reverse_iterator iterator = indexList.rbegin(); iterator != indexList.rend(); ++iterator) {
                int row(iterator->row());
                if (row != previousRowDeleted) {
                    model()->removeRows(row, 1);
                    previousRowDeleted = row;
                }
            }
        }
    }
}
