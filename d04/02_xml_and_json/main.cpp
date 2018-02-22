/***************************************************************************
*                                                                          *
*                main.cpp for 02_xml_and_json                              *
*                Created on  : Mon Mar 30 2017 08:15                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDataStream>
#include <QXmlStreamWriter>
#include <QCoreApplication>
#include <QtDebug>

void parseObject(const QJsonObject &object, QXmlStreamWriter &writer);
void parseValue(const QJsonValue &value, QXmlStreamWriter &writer);
void parseArray(const QJsonArray &array, QXmlStreamWriter &writer);

void parseArray(const QJsonArray &array, QXmlStreamWriter &writer)
{
    QJsonArray::const_iterator iterator;
    iterator = array.begin();
    while (iterator != array.end()) {
        QJsonValue jsonValue = *iterator;
        if (jsonValue.isArray())
            parseArray(jsonValue.toArray(), writer);
        if (jsonValue.isObject())
            parseObject(jsonValue.toObject(), writer);
        *iterator++;
    }
}

void parseObject(const QJsonObject &object, QXmlStreamWriter &writer)
{
    QStringList keys = object.keys();
    for (const QString &key : keys) {
        writer.writeStartElement(key);
        parseValue(object.value(key), writer);
        writer.writeEndElement();
    }
}

void parseValue(const QJsonValue &value, QXmlStreamWriter &writer)
{
    if (value.isArray())
        parseArray(value.toArray(), writer);
    else if (value.isObject())
        parseObject(value.toObject(), writer);
    else if (value.isBool()) {
        if (value.toBool())
            writer.writeCharacters("true");
        else
            writer.writeCharacters("false");
    }
    else if (value.isDouble())
        writer.writeCharacters(QString::number(value.toDouble()));
    else if (value.isString())
        writer.writeCharacters(value.toString());
    else {
        qDebug() << "Something else";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);

    QFile file(QStringLiteral(":/jsonExample.json"));
    file.open(QFile::ReadOnly);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &error);

    if (error.error != QJsonParseError::NoError) {
        qDebug() << error.errorString();
        return EXIT_FAILURE;
    }

    QFile xmlFile(QStringLiteral("jsonExample.xml"));
    qDebug() << "XML output written to" << QCoreApplication::applicationDirPath() + "/" + xmlFile.fileName();
    xmlFile.open(QFile::WriteOnly);
    QXmlStreamWriter writer(&xmlFile);
    writer.writeStartDocument();
    writer.setAutoFormatting(true);
    writer.setAutoFormattingIndent(4);

    if (jsonDoc.isArray())
        parseArray(jsonDoc.array(), writer);
    else if (jsonDoc.isObject())
        parseObject(jsonDoc.object(), writer);
    else if (jsonDoc.isEmpty() | jsonDoc.isNull())
        qDebug() << "Empty JSON document";

    writer.writeEndDocument();
    xmlFile.close();

    return EXIT_SUCCESS;
}
