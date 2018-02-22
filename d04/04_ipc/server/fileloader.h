/***************************************************************************
*                                                                          *
*                fileloader.h for 04_ipc                                   *
*                Created on  : Mon Apr 04 2017 12:11                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef FILELOADER_H
#define FILELOADER_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(QFileSystemWatcher)
QT_FORWARD_DECLARE_CLASS(QLabel)

class FileLoader : public QObject
{
    Q_OBJECT
public:
    explicit FileLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent = 0);
    ~FileLoader();

protected Q_SLOTS:
    void loadFile();

private:
    QFileSystemWatcher *m_watcher;
    QLabel *m_imageLabel;
    QLabel *m_textLabel;
};

#endif // FILELOADER_H
