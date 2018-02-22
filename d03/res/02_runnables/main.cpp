/***************************************************************************
*                                                                          *
*                main.cpp for 02_runnables                                 *
*                Created on  : Thu Mar 23 2017 16:28                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QHeaderView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget container;
    QVBoxLayout layout;
    QPushButton button("Add images to invert pixels");
    layout.addWidget(&button);
    QTableView tableView;
    layout.addWidget(&tableView);
    tableView.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    container.setLayout(&layout);

    QStringList imageFiles;
    QStandardItemModel imageModel;
    tableView.setModel(&imageModel);

    button.connect(&button, &QPushButton::clicked, [&imageFiles, &container, &imageModel, &tableView] () {
        imageFiles = QFileDialog::getOpenFileNames(&container, "Open image files", QDir::homePath(), "Images (*.png *.xpm *.jpg *.jpeg)");
        imageModel.clear();
        imageModel.insertRows(0, imageFiles.count());
        imageModel.insertColumns(0, 2);
        imageModel.setHeaderData(0, Qt::Horizontal, "Images");
        imageModel.setHeaderData(1, Qt::Horizontal, "Inverted images");

        auto currentRow(0);
        for (const QString &imageFile : imageFiles) {
            QImage image(imageFile);
            tableView.setRowHeight(currentRow, image.height());
            imageModel.setData(imageModel.index(currentRow, 0), image, Qt::DecorationRole);
        }
    });

    container.show();

    return a.exec();
}
