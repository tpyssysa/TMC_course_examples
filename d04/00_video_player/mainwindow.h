/***************************************************************************
*                                                                          *
*                mainwindow.h for 00_video_player                          *
*                Created on  : Mon Apr 03 2017 08:22                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_FORWARD_DECLARE_CLASS(QMediaPlayer)
QT_FORWARD_DECLARE_CLASS(QMediaPlaylist)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openButton_clicked();

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player;
    QMediaPlaylist *m_playlist;
};

#endif // MAINWINDOW_H
