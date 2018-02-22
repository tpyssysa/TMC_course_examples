/***************************************************************************
*                                                                          *
*                fileloader.cpp for 04_ipc                                 *
*                Created on  : Mon Apr 04 2017 12:11                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "fileloader.h"
#include <QLabel>
#include <QFileSystemWatcher>
#include <QFile>
#include <QImage>
#include <QDir>
#include <QMessageBox>

FileLoader::FileLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent) :
    QObject(parent),
    m_watcher(new QFileSystemWatcher(this)),
    m_imageLabel(imageLabel),
    m_textLabel(textLabel)
{
    m_watcher->addPath(QDir::tempPath());
    connect(m_watcher, &QFileSystemWatcher::directoryChanged, this, &FileLoader::loadFile);
}

FileLoader::~FileLoader()
{
    QFile::remove(QString(QDir::tempPath() + "/imageFile"));
}

void FileLoader::loadFile()
{
    QFile inFile(QString(QDir::tempPath() + "/imageFile"));
    QImage image;
    if (!inFile.open(QFile::ReadOnly))
        return; // tmp directory was not changed by the client app
    QDataStream in(&inFile);
    in >> image;

    if (image.isNull()) {
            QMessageBox::warning(m_imageLabel, tr("IO Error"), tr("Image reading error"));
            return;
    }
    m_imageLabel->setPixmap(QPixmap::fromImage(image));
    m_textLabel->setText(tr("New image loaded from a file."));
}

