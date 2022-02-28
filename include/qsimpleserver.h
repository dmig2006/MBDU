#ifndef TCPSERV_H
#define TCPSERV_H

#include <QTcpServer>
#include <QTcpSocket>
#include "qsocketthred.h"
#include  "canad.h"

class QSimpleServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit QSimpleServer(QObject *parent =0);

    canad	 *can_adapter;
    void incomingConnection(qintptr handle);
    ~QSimpleServer(); // освобождение памяти canad
private slots:
    void OnFrameReady(can_frame* frame);
signals:
    void FrameReady(can_frame* frame);  //сигнал готовности принятого фрейма
    void newLogMsg(QString str);
public slots:
    void FramesToBytes(can_frame* frame);    //слот отправки фрейма
   
};

#endif // TCPSERV_H
