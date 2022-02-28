#include "qsimpleserver.h"

QSimpleServer::QSimpleServer(QObject *parent):QTcpServer(parent)

{
    listen(QHostAddress::Any, 4210);
    can_adapter = new canad;

}

void QSimpleServer::incomingConnection(qintptr handle)
{
    QSocketThred *thread = new QSocketThred(handle);
    connect (thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

//    отправка данных по Ethernet
    connect(can_adapter, SIGNAL(SendBytes(char*,int)), thread, SLOT(WriteData(char*,int)));
//    прием данных по Ethernet
    connect(thread, SIGNAL(DataReady(char*,int)), can_adapter, SLOT(BytesToFrames(char*,int)));
//    реакция на готовность кан-фрейма
    connect(can_adapter, SIGNAL(SendFrame(can_frame*)), this, SLOT(OnFrameReady(can_frame*)));
    
    thread->start();
    
}

QSimpleServer::~QSimpleServer()
{
    delete can_adapter;
}


void QSimpleServer::FramesToBytes(can_frame* frame)
{
//    добавить проверку наличия потока
    can_adapter->FramesToBytes(frame);
}
void QSimpleServer::OnFrameReady(can_frame *frame)
{
    emit FrameReady(frame);
}
