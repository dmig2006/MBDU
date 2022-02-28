#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QMutex>
#include <QBuffer>
#include <QTimer>
#include <QPainter>
#include <QPicture>
#include <QBitmap>
#include <QMouseEvent>
#include <QList>

#include <QVideoWidget>

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "aimlist.h"
#include "view.enum.h"
#include "camera.h"
//#include "tracking_client.h"
#include "controllermanager.h"
/*
enum TrackingType {
    MATCH    = 1,
    DETECTOR = 0,
    NONE     = 2
};
*/
namespace Ui {
    class VideoWidget;
}

class VideoWidget : public QVideoWidget
{
    Q_OBJECT

    Ui::VideoWidget *ui;
    QMutex           mMutex;
    QPixmap          mPixmap;
    QImage           mImage;
    QImage           mZeroImage;
    Camera          *mCamera;
    bool             isOperationMode;
    bool             isConnected;
    bool             mConnect;
    bool             flagInversia;

protected:
    void paintEvent(QPaintEvent *);

public:
    VideoWidget(QWidget *parent = 0);
    ~VideoWidget();
    void setCameraMode(CameraMode pCameraMode);
    void setOperationState(bool state, bool is_not_connected);
    void getFlagInversia(bool pFlag);
    void pictureCompression(int i);

public slots:
    void setImage(QImage image);
    void setOperationMode(bool state, bool isNotConnetcted);
    void closeConnection();

signals:
    void newLogMsg(QString string);
    void resetCamera();
};

#endif // VIDEOWIDGET_H
