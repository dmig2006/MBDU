#ifndef QUDPSERVER_H
#define QUDPSERVER_H

#include <QThread>
#include <QUdpSocket>
#include <QDataStream>

struct UDP_Parcel
{
    qint8   flag;
    double x;
    double y;
};

class qudpserver : public QThread
{
    Q_OBJECT
public:
    explicit qudpserver(QThread *parent = 0);
    ~qudpserver();

    void sendUdpTest();
    void run();

signals:
    void newLogMsg(QString);
    void sendUdpParcel (UDP_Parcel udpParcel);
public slots:
    void readyReadd();

private:
    QUdpSocket *udpsocket;
    UDP_Parcel udp_p_send;
    UDP_Parcel udp_p_recive;
};

#endif // QUDPSERVER_H
