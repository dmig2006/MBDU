#include "qudpserver.h"

qudpserver::qudpserver(QThread *parent) : QThread(parent)
{
    udpsocket = new QUdpSocket(this);
    udpsocket->bind(QHostAddress::Any,8192); //связывание порта с адресом при получении посылки отправляется сигнал readyread();


}

qudpserver::~qudpserver()
{
    udpsocket->disconnectFromHost();
    delete udpsocket;
}

void qudpserver::run()
{

    connect (udpsocket, SIGNAL(readyRead()),this,SLOT(readyReadd()),Qt::DirectConnection);
}


void qudpserver::readyReadd()
{
    QByteArray buffer,flag, xx, yy;
    buffer.resize(udpsocket->pendingDatagramSize()); //функция pendingDatagramSize() возвращает размер принятой посылки
    /*qint8  f = 0;
    double x = 0.0;
    double y = 0.0;*/
    QHostAddress sender;
    quint16 senderPort;
    udpsocket->readDatagram(buffer.data(),buffer.size(),&sender, &senderPort);
    for (int i=0; i<=3  ;i++)
    {
        flag.append(buffer[i]);
    }
    for (int i=24; i>=8 ;i--)
    {
       if ((i>=8)  & (i<=15))    xx.append(buffer[i]);
       if ((i>=16) & (i<=23))    yy.append(buffer[i]);
    }
    QDataStream in_f(&flag, QIODevice::ReadOnly);   //объявление потока данных считывающего из байтового массива
    QDataStream in_x(&xx, QIODevice::ReadOnly);
    QDataStream in_y(&yy, QIODevice::ReadOnly);
    in_f.setVersion(QDataStream::Qt_5_0);           //установка версии потока данных требуется для синхронизации с клиентом
    in_x.setVersion(QDataStream::Qt_5_0);
    in_y.setVersion(QDataStream::Qt_5_0);

    in_f >> udp_p_recive.flag;                                      //забираем из потока в переменную значение
    in_x >> udp_p_recive.x;
    in_y >> udp_p_recive.y;

    emit sendUdpParcel(udp_p_recive);
    //emit newLogMsg("1111111");
    //qDebug() << "Message : " << udp_p_recive.flag << " " << udp_p_recive.x << ","<< udp_p_recive.y;


}
void qudpserver::sendUdpTest()
{
    /*QByteArray data;
    QString    str;

    //udp_p_send.flag = 1;
    //udp_p_send.x    = 112.1;
    //udp_p_send.y    = -98.4;

    //str =  QString("$%1,%2,%3#").arg(udp_p_send.flag).arg(udp_p_send.x).arg(udp_p_send.y);
    //data.append(str);
    data.resize(sizeof (udp_p_send));


    udpsocket->writeDatagram(data,QHostAddress("10.0.0.36"),8192);*/


}
