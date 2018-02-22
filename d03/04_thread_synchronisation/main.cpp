/***************************************************************************
*                                                                          *
*                main.cpp for 04_thread_synchronisation                    *
*                Created on  : Mon Mar 27 2017 11:50                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

#include <QApplication>
#include "globalbuffer.h"
#include "consumer.h"
#include "producer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Consumer consumer;
    Producer producer;

    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();
    return 0;
}


