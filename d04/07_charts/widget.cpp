/***************************************************************************
*                                                                          *
*                widget.cpp for 07_charts                                  *
*                Created on  : Mon Apr 03 2017 22:58                       *
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
#include <QLineSeries>
#include <QSplineSeries>
#include <QScatterSeries>

const double KELVIN_ZERO = -273.15;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),
    m_manager(new QNetworkAccessManager(this)),
    m_chartView(new QChartView(new QChart))
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(m_chartView);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_returnPressed()
{
    QUrl url("http://api.openweathermap.org/data/2.5/forecast");
    QUrlQuery query;

    query.addQueryItem("q", ui->lineEdit->text());
    query.addQueryItem("mode", "json");
    query.addQueryItem("cnt", "15");
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

        QChart *chart = m_chartView->chart();
        QLineSeries *tempSeries = new QLineSeries();
        tempSeries->setName(ui->lineEdit->text());

        if (obj.contains(QStringLiteral("list"))) {
            val = obj.value(QStringLiteral("list"));
            QJsonArray weatherArray = val.toArray();
            for (int i = 0; i < weatherArray.size(); ++i) {
                val = weatherArray.at(i);
                obj = val.toObject();

                if (i == 0) {
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
                }
                if (obj.contains(QStringLiteral("main"))) {
                    val = obj.value(QStringLiteral("main"));
                    tempObject = val.toObject();
                    val = tempObject.value(QStringLiteral("temp"));
                    ui->temperatureLabel->setText(QString::number(qRound(val.toDouble() + KELVIN_ZERO)) + QChar(0x02DA) + " Celcius");
                    *tempSeries << QPointF(i, val.toDouble() + KELVIN_ZERO);
                }
            }
            chart->addSeries(tempSeries);
            chart->createDefaultAxes();
            chart->axisX()->setRange(0, 5);
            chart->axisX()->setVisible(false);
            chart->axisY()->setRange(-30, 30);

        }
    }
    m_reply->deleteLater();
}

