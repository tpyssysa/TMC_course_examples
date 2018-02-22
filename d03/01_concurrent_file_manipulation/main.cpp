/***************************************************************************
*                                                                          *
*                main.cpp for 00_concurrent_file_manipulation              *
*                Created on  : Thu Mar 23 2017 13:40                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QtConcurrent>
#include <QtDebug>

QByteArray toLowered(const QByteArray &array)
{
    return array.toLower();
}

static void toLower(const QString &fileName)
{
    QFileInfo fileInfo(fileName);
    QFile inputFile(fileName);
    QFile outputFile(fileInfo.absolutePath() + "/" +  fileInfo.baseName()+ "_toLower." + fileInfo.completeSuffix());

    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open " << fileName << " for input";
        return;
    }

    QByteArray array = inputFile.readAll();
    QList<QByteArray> container = array.split(' ');
    container = QtConcurrent::blockingMapped(container, toLowered);
    QByteArray convertedArray = container.join(' ');

    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Cannot open " << outputFile.fileName() << " for output";
        return;
    }

    outputFile.write(convertedArray);
    inputFile.close();
    outputFile.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString fileName;
    QPushButton button("Open a file to be converted");
    button.resize(200, 100);
    button.connect(&button, &QPushButton::clicked, [&fileName, &button] () {
        fileName = QFileDialog::getOpenFileName(&button, "Open a source code file",
                                                "/home",
                                                "Source code files (*.h *.cpp *.js *.qml)");
        if (!fileName.isEmpty())
            QtConcurrent::run(toLower, fileName);
    });
    button.show();

    return a.exec();
}
