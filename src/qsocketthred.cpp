#include "qsocketthred.h"


QSocketThred::QSocketThred(int descriptor, QObject *parent):QThread(parent),socketDescriptor(descriptor)
{
//    need_exit = false;
    socket = new QTcpSocket();
    socket -> setSocketDescriptor(socketDescriptor);
}

QSocketThred::~QSocketThred()
{
    socket -> disconnectFromHost();
    delete socket;
//    need_exit = true;
//    wait(1000); //Ждем 1000 мС на завершение потока, если он не бы заверешен, то он убивается
}

void QSocketThred::run()
{
//    while (!need_exit)
//{
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),this, SLOT(onDisconnected()),Qt::DirectConnection);
//    msleep(50);
//}
//    connect(mOptWidget, SIGNAL(move_Ac_Target(long,long)), SIGNAL(move_Ac_Target1(long,long)));

    exec();

}
void QSocketThred::WriteData(char *data, int len)
{

    if(socket->isValid())
    {
        socket->write(data, len);
    }
}
void QSocketThred::onReadyRead()
{
    QByteArray rdata;
//    Get number of received bytes
    int size = socket -> bytesAvailable();

//    Read bytes
    rdata = socket->read(size);

//    emit newLogMsg("Чтение данных");

//    emit SendToLog(QString("read: 0x%1...").arg(QString::fromAscii((rdata.toHex()).data(), (rdata.toHex()).size())));

//    Сигнал готовности данных
    emit DataReady(rdata.data(), rdata.size()); //char* data int len
}


void QSocketThred::onDisconnected()
{
    socket -> close();
    quit();
}

