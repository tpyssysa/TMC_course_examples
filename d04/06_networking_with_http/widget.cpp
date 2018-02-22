/***************************************************************************
*                                                                          *
*                widget.cpp for 06_networking_with_http                    *
*                Created on  : Mon Apr 03 2017 15:17                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include "widget.h"
#include "ui_form.h"
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),
    m_manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_returnPressed()
{
    QUrl url("http://api.openweathermap.org/data/2.5/weather");
    QUrlQuery query;

    query.addQueryItem("q", ui->lineEdit->text());
    query.addQueryItem("mode", "json");
    query.addQueryItem("APPID", QStringLiteral("36496bad1955bf3365448965a42b9eac"));
    url.setQuery(query);

    m_reply = m_manager->get(QNetworkRequest(url));
    connect(m_reply, &QNetworkReply::finished, this, &Widget::handleNetworkReply);
}

void Widget::handleNetworkReply()
{
    QJsonDocument document = QJsonDocument::fromJson(m_reply->readAll());

    if (document.isObject()) {
        QJsonObject obj = document.object();
        QJsonObject tempObject;
        QJsonValue val;

        if (obj.contains(QStringLiteral("weather"))) {
            val = obj.value(QStringLiteral("weather"));
            QJsonArray weatherArray = val.toArray();
            val = weatherArray.at(0);
            tempObject = val.toObject();
            ui->descriptionLabel->setText(tempObject.value(QStringLiteral("description")).toString());
            QUrl iconUrl("http://openweathermap.org/img/w/" + tempObject.value("icon").toString() + ".png");
            QNetworkReply *reply = m_manager->get(QNetworkRequest(iconUrl));
            connect(reply, &QNetworkReply::finished, [this, reply] () {
                QImage image;
                if (image.load(reply, "PNG")) {
                    ui->iconLabel->setPixmap(QPixmap::fromImage(image));
                }
                reply->deleteLater();
            });
        }
        if (obj.contains(QStringLiteral("main"))) {
            val = obj.value(QStringLiteral("main"));
            tempObject = val.toObject();
            val = tempObject.value(QStringLiteral("temp"));
            ui->temperatureLabel->setText(QString::number(qRound(val.toDouble() - 273.15)) + QChar(0x02DA) + " Celcius");
        }
    }
    m_reply->deleteLater();
}
