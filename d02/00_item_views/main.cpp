/***************************************************************************
*                                                                          *
*                main.cpp for 00_item_views                                *
*                Created on  : Tue Mar 21 2017 08:21                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFileSystemModel model;
    model.setRootPath(QDir::homePath());

    QTreeView treeView;
    treeView.setModel(&model);
    treeView.show();

    return a.exec();
}
