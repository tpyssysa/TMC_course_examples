/***************************************************************************
*                                                                          *
*                mainwindow.cpp for 01_subtitles                           *
*                Created on  : Mon Apr 03 2017 08:30                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videowidget.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_player(new QMediaPlayer(this)),
    m_playlist(new QMediaPlaylist(this))
{
    m_player->setPlaylist(m_playlist);
    ui->setupUi(this);
    VideoWidget *widget = new VideoWidget();
    m_player->setVideoOutput(widget->videoSurface());
    ui->centralwidget->layout()->addWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    QList<QUrl> fileList = QFileDialog::getOpenFileUrls(Q_NULLPTR, "Open Media Files", QUrl("."));
    for (const QUrl &file : fileList)
        m_playlist->addMedia(file);
}

void MainWindow::on_playButton_clicked()
{
    if (m_player->state() == QMediaPlayer::StoppedState)
        m_playlist->setCurrentIndex(1);
    m_player->play();
}

void MainWindow::on_pauseButton_clicked()
{
    m_player->pause();
}

void MainWindow::on_stopButton_clicked()
{
    m_player->stop();

}
