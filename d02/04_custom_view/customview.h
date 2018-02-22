/***************************************************************************
*                                                                          *
*                customview.h for 04_custom_view                           *
*                Created on  : Wed Mar 22 2017 15:43                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QTableView>

class CustomView : public QTableView
{
public:
    CustomView(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
};

#endif // CUSTOMVIEW_H
