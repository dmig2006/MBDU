/*
#ifndef TRACKING_CLIENT_H
#define TRACKING_CLIENT_H

#include <QRect>
#include <QThread>
#include <QMutex>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "client.h"
#include "tracking_error.h"
#include "camera_error.h"
#include "tracking_msg.h"

/*param connectig*/
/*
#define TRACKING_SERVER_ADDRESS     "127.0.0.1"
#define TRACKING_SERVER_PORT        7777

/*param TrackingClient*/
/*
#define FILE_DETECTOR_CONFIG        "detector.d/detector.conf"
#define PRFILE_MATH                 "detector.d/match.vcc"
#define PRFILE_DETECT               "detector.d/detect.vcc"

class TrackingClient : public QThread, protected Client
{
    Q_OBJECT

    std::vector<QRect> rects;
    QMutex mMutex;
    QRect mRectTarget;
    bool tracking_client;
    bool is_new_rect;
    bool is_filter;
    bool is_new_camera;
    bool is_new_filter;
    bool is_new_param;
    bool need_exit;
    int camera;
    int tracking_client_type;
    /*[temp] for debug*/
/*
bool is_new_math;
    int frame_num;

    void onTrackingClientChanged(int state);
    /*
    void saveDetectorConfig(std::string profile, int pTrackingClient);
    */
/*
int  readDetectorConfig();
    int  readParamsFile(const char* pFileName);
    bool sendParam();
    bool recvFrame();
    bool queryFrame();
    void setError(int idError);
/*
protected:
    void run();

public:
    TrackingClient();
    ~TrackingClient();
    /*setting metods*/
/*
void setTypeTrackingClient(int pTypeTrackingClient);
    void setCamera(int pCamera);
    void setTrackingClient(bool pTrackingClient);
    void setRectTarget(QRect pRectTarget);
    void setFilter(bool pStateFilter );
    /*get metods*/
/*
int  getTypeTrackingClient() { return tracking_client_type; }
    bool isTrackingClient();

public slots:
    void stopExecution();

signals:
    void newCenterMassTracking(int x, int y);
    void newRects(QRect, QRect);
};

#endif // TRACKING_CLIENT_H
*/
