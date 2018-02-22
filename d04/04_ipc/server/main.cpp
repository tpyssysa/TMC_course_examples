/***************************************************************************
*                                                                          *
*                widget.h for 04_ipc                                       *
*                Created on  : Mon Apr 04 2017 08:17                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "fileloader.h"
#include "sharedmemoryloader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget container;
    container.setGeometry(100, 100, 400, 300);
    QVBoxLayout *layout = new QVBoxLayout(&container);

    QPushButton *loadButton = new QPushButton(QObject::tr("Load from shared memory"));
    layout->addWidget(loadButton);

    QLabel *textLabel = new QLabel;
    textLabel->setText(QObject::tr("No image received"));
    QLabel *imageLabel = new QLabel;
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(textLabel);
    layout->addWidget(imageLabel);
    container.show();

    SharedMemoryLoader sharedMemoryLoader(imageLabel, textLabel);
    QObject::connect(loadButton, &QPushButton::clicked, &sharedMemoryLoader, &SharedMemoryLoader::loadFromSharedMemory);

    FileLoader fileLoader(imageLabel, textLabel);

    return a.exec();
}
