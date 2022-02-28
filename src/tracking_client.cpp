/*
#include "tracking_client.h"

TrackingClient::TrackingClient()
    : tracking_client(false), is_new_rect(false), is_filter(false),
      is_new_camera(false), is_new_filter(false), is_new_param(false),
      need_exit(false), camera(2), is_new_math(false), frame_num(0) {}

TrackingClient::~TrackingClient()
{
//    stopExecution();
    msleep(200);
    wait(1000);
}

void TrackingClient::onTrackingClientChanged(int state)
{
    std::string profile;
    profile = (state) ? PRFILE_MATH : PRFILE_DETECT;

    saveDetectorConfig(profile, state);

//}

void TrackingClient::saveDetectorConfig(std::string pProfile, int pTrackingClient)
{
    std::string file_name(FILE_DETECTOR_CONFIG);
    std::ifstream i(file_name.c_str());
    int lState = 1;
    std::string lProfile;
    int lTrackingClient;
    if (i.is_open()) {
        i >> lState;
        i >> lProfile;
        i >> lTrackingClient;
        i.close();
    }
    std::offstream o(file_name.c_str());
    o << lState << std::endl;
    o << (pProfile == "" ? lProfile : pProfile) << std::endl;
    o << (pTrackingClient == -1 ? lTrackingClient : pTrackingClient) << std::endl;
    o.close();
}
*/
/*
int  TrackingClient::readDetectorConfig()
{
    bool lState;
    std::string lFileName;
    std::string lTrackingClient;
    std::ifstream i(FILE_DETECTOR_CONFIG);
    if (i.is_open()) {
        i >> lState;
        i >> lFileName;
        i >> lTrackingClient;
        i.close();
    }
    int isError = readParamsFile(lFileName.c_str());
    if (isError != NO_ERROR) {
        setError(isError);
        return isError;
    }
    return NO_ERROR;
}
*/
/*
int TrackingClient::readParamsFile(const char* pFileName)
{
    std::ifstream paramsFile;
    paramsFile.open(pFileName, std::ios::binary);
    //  Whether the file stream is good
    if (!paramsFile.good())
        return ERROR_OPENING_FILE_DETECTOR;
    //  get the size of file
    paramsFile.seekg(0, std::ios::end);
    size_t PayloadLength = paramsFile.tellg();
    paramsFile.seekg(0, std::ios::beg);
    //  Command structure
    MSG_FILTER_PARAM m;
    //  Alloc the buffer
    m.Data.m_pPayload = reinterpret_cast<char*>(::malloc(PayloadLength));
    //  read the whole config file
    paramsFile.read(m.Data.m_pPayload, PayloadLength);
    //  The lenght of Command Message = length of header + length of config file
    m.m_Len = sizeof(MsgHdr) + PayloadLength;
    //  write the message header first
    if (!writeBytes((unsigned char*)&m, sizeof(MsgHdr)))
        return ERROR_WRITE_PARAM_DETECTOR;
    //  write the raw config data
    if (!writeBytes((unsigned char*)m.Data.m_pPayload, PayloadLength))
        return ERROR_WRITE_PARAM_DETECTOR;
        ::free(m.Data.m_pPayload);
    return NO_ERROR;
}

void TrackingClient::setTypeTrackingClient(int pTypeTrackingClient)
{
    mMutex.lock();
    is_new_param = true;
    tracking_client_type = pTypeTrackingClient;
    mMutex.unlock();
//    onTrackingClientChanged(pTypeTrackingClient);
}
*/
/*
void TrackingClient::setCamera(int pCamera)
{
    mMutex.lock();
    camera = pCamera;
    is_new_camera = true;
    mMutex.unlock();
}
*/
/*
void TrackingClient::setTrackingClient(bool pTrackingClient)
{
    mMutex.lock();
    tracking_client = pTrackingClient;
    mMutex.unlock();
}
*/
/*
void TrackingClient::setRectTarget(QRect pRectTarget)
{
    mMutex.lock();
    mRectTarget = pRectTarget;
    is_new_rect = true;
    is_new_math = true;
    //frame_nums = 0;
    mMutex.unlock();
}
*/
/*
void TrackingClient::setFilter(bool pStateFilter)
{
    mMutex.lock();
    is_filter = pStateFilter;
    is_new_filter = true;
    mMutex.unlock();
}
*/
/*
bool TrackingClient::sendParam()
{
    MSG_SET_FOG fog;
    MSG_SET_CAMERA camera_to_set;
    MSG_SELECTED_RECT rect;

    mMutex.lock();
    if (is_new_param) {
        is_new_param = false;
        int isError = readDetectorConfig();
        if (isError != NO_ERROR) {
            mMutex.unlock();
            return false;
        }
    }

    if (is_new_filter) {
        is_new_filter = false;
        fog.Data.m_FogState = is_filter;
        if (!writeBytes((const unsigned char*)&fog, fog.m_Len)) {
            mMutex.unlock();
            setError(ERROR_WRITE_PARAM_DETECTOR);
            return false;
        }
    }

    if (is_new_camera) {
        is_new_camera = false;
        camera_to_set.Data.m_CameraId = camera;
        if (!writeBytes((const unsigned char*)&camera_to_set,
                        camera_to_set.m_Len)) {
            mMutex.unlock();
            setError(ERROR_WRITE_PARAM_DETECTOR);
            return false;
        }
    }

    if(is_new_rect){
        is_new_rect = false;
        frame_num = 0;
        int x1, y1, x2, y2;
        mRectTarget.getCoords(&x1, &y1, &x2, &y2);
        rect.Data.m_Begin.m_X = x1;
        rect.Data.m_Begin.m_Y = y1;
        rect.Data.m_End.m_X = x2;
        rect.Data.m_End.m_Y = y2;
        if (!writeBytes((const unsigned char*)&rect, rect.m_Len)) {
            mMutex.unlock();
            setError(ERROR_WRITE_PARAM_DETECTOR);
            return false;
        }
    }
    mMutex.unlock();
    return true;
}
*/
/*
bool TrackingClient::recvFrame()
{
    if (!sendParam())
        return false;
    MSG_META_FRAME *spFrame = new MSG_META_FRAME();
    unsigned int uiTargetCount = 0;
    if (!readBytes((unsigned char*)&uiTargetCount, sizeof(unsigned int))) {
        setError(ERROR_READ_PARAM_DETECTOR);
        delete spFrame;
        return false;
    }
    if (uiTargetCount) {
        unsigned int uiRawDataLength = uiTargetCount
                                       * sizeof(FRAME_META_DATA::targets_container::value_type);
        spFrame->Data.m_MetaData.m_Targets.resize(uiTargetCount);
        if (!readBytes((unsigned char*)&spFrame->Data.m_MetaData.m_Targets[0], uiRawDataLength)) {
            setError(ERROR_READ_PARAM_DETECTOR);
            delete spFrame;
            return false;
        }
        unsigned short x;
        unsigned short y;
        mMutex.lock();
        rects.clear();
        if (tracking_client) {
            x = spFrame->Data.m_MetaData.m_Targets[0].m_CenterOfMass[0];
            y = spFrame->Data.m_MetaData.m_Targets[0].m_CenterOfMass[1];
            if (x > 0 && x < 768 && y > 0 && y < 576) {
                if (frame_num > 3) {
                    frame_num = 10;
                    emit newCenterMassTracking(x, y);
                } else {
                    ++frame_num;
                }
            }
            QRect rect_t1, rect_t2;
            if (uiTargetCount > 0) {
                QRect rect = QRect(QPoint(spFrame->Data.m_MetaData.m_Targets[0].m_Rect[0],
                                          (int)spFrame->Data.m_MetaData.m_Targets[0].m_Rect[1]),
                                   QPoint(spFrame->Data.m_MetaData.m_Targets[0].m_Rect[2],
                                          (int)spFrame->Data.m_MetaData.m_Targets[0].m_Rect[3]));
                if (rect.width() > 0 && rect.width() < 767
                        && rect.height() > 0 && rect.height() < 575) {
                    rect_t1 = rect;
                }
            }
            if (uiTargetCount > 1) {
                QRect rect_2 = QRect(QPoint(spFrame->Data.m_MetaData.m_Targets[1].m_Rect[0],
                                            (int)spFrame->Data.m_MetaData.m_Targets[1].m_Rect[1]),
                                     QPoint(spFrame->Data.m_MetaData.m_Targets[1].m_Rect[2],
                                            (int)spFrame->Data.m_MetaData.m_Targets[1].m_Rect[3]));
                if (rect_2.width() > 0 && rect_2.width() < 767
                        && rect_2.height() > 0 && rect_2.height() < 575) {
                    rect_t2 = rect_2;
                }
            }
            emit newRects(rect_t1, rect_t2);
        } else {
            rects.clear();
            for (unsigned int i = 0; i < uiTargetCount; ++i) {
                QRect rect = QRect(QPoint(spFrame->Data.m_MetaData.m_Targets[i].m_Rect[0],
                                          (int)spFrame->Data.m_MetaData.m_Targets[i].m_Rect[1]),
                                   QPoint(spFrame->Data.m_MetaData.m_Targets[i].m_Rect[2],
                                          (int)spFrame->Data.m_MetaData.m_Targets[i].m_Rect[3]));
                rects.push_back(rect);
            }
        }
        mMutex.unlock();
    } else {
        //onTargetDetected(false);
    }
    if (!readBytes((unsigned char*)&spFrame->Data.m_Frame, sizeof(FRAME))) {
        setError(ERROR_READ_PARAM_DETECTOR);
        delete spFrame;
        return false;
    }
    usleep(50000);
    delete spFrame;
    return true;
}
*/
/*
bool TrackingClient::queryFrame()
{
    MSG_GET_FRAME m;
    if (!writeBytes((const unsigned char*)&m, m.m_Len)) {
        setError(ERROR_WRITE_PARAM_DETECTOR);
        return false;
    }
    unsigned int lFrameLength = 0;
    if (!readBytes((unsigned char*)&lFrameLength, sizeof(unsigned int))) {
        setError(ERROR_READ_PARAM_DETECTOR);
        return false;
    }
    return true;
}

void TrackingClient::run()
{
    bool is_connect = false;
    while (!need_exit) {
        if (is_connect) {
            if (!queryFrame()) {
                close();
                is_connect = false;
            }
            //msleep(10);
            if (!recvFrame()) {
                close();
                is_connect = false;
            }
        } else {
            if (connectToServer(std::string(TRACKING_SERVER_ADDRESS),
                                TRACKING_SERVER_PORT) == NO_ERROR) {
                if (readDetectorConfig() == NO_ERROR) {
                    is_connect = true;
                } else {
                    is_connect = false;
                    close();
                }
            } else {
                is_connect = false;
                sleep(1);
            }
        }
    }
}
*/
/*
bool TrackingClient::isTrackingClient()
{
    bool isTrackingClient = false;
    mMutex.lock();
    isTrackingClient = tracking_client;
    mMutex.unlock();
    return isTrackingClient;
}
*/
/*
void TrackingClient::stopExecution()
{
    need_exit = true;
}
*/
/*
void TrackingClient::setError(int error_id)
{
    switch (error_id) {
    case ERROR_READ_PARAMS_TRACKING:
        std::cerr << "TrackingClient: ERROR_READ_PARAMS\n";
        break;
    case ERROR_OPENING_FILE_DETECTOR:
        std::cerr << "TrackingClient: ERROR_OPENING_FILE_DETECTOR\n";
        break;
    case ERROR_WRITE_PARAM_DETECTOR:
        std::cerr << "TrackingClient: ERROR_WRITE_PARAM_DETECTOR\n";
        break;
    case ERROR_READ_PARAM_DETECTOR:
        std::cerr << "TrackingClient: ERROR_READ_PARAM_DETECTOR\n";
        break;
    }
}
*/
