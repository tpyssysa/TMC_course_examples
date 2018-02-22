/***************************************************************************
*                                                                          *
*                fileloader.cpp for 04_ipc                                 *
*                Created on  : Mon Apr 04 2017 12:11                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "fileloader.h"
#include <QLabel>
#include <QFile>
#include <QImage>
#include <QDir>

FileLoader::FileLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent) :
    QObject(parent),
    m_imageLabel(imageLabel),
    m_textLabel(textLabel)
{
}

