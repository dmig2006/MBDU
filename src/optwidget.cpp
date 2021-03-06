#include "optwidget.h"
#include "ui_optwidget.h"
#include "mainwindow.h"

OptWidget::OptWidget(QWidget *parent) :
    QVideoWidget(parent), ui(new Ui::OptWidget)
{
    ui->setupUi(this);
    QPixmap curPix;
    curPix.load(":/cross.png");
    QCursor cur(curPix);
    setCursor(cur);

    isPressRect = false;
    is_cocking = false;

//    mTrackingClient = new TrackingClient();

//    mTrackingClient->setCamera(2);
//    mTrackingClient->setTypeTrackingClient(0);
//    mTrackingClient->setTrackingClient(false);

    isInvertColor = false;

    mRectTracking = QRect(0, 0, 100, 100);

    mGraphicsWhite.pixmapCrossWide.load(":/white/cross_shz.png");
    mGraphicsWhite.pixmapCrossNarrow.load(":/white/cross_uz.png");
    mGraphicsWhite.pixmapCrossThermo.load(":/white/cross_teplo.png");
    mGraphicsWhite.pixmapCrossZoomThermo.load(":/white/cross_teplo_zoom.png");
    mGraphicsWhite.pixmapOptNarrow.load(":/white/opt_uz.png");
    mGraphicsWhite.pixmapOptThermo.load(":/white/opt_teplo.png");
    mGraphicsWhite.pixmapOptZoomThermo.load(":/white/opt_teplo_zoom.png");
    mGraphicsWhite.pixmapOptWide.load(":/white/opt_shz.png");
    mGraphicsWhite.pixmapRectNarrow.load(":/white/ramka_uz.png");
    mGraphicsWhite.pixmapAim.load(":/white/target.png");
    mGraphicsWhite.pixmapCrossTg.load(":/white/cross.png");
    mGraphicsWhite.pixmapTriangleHor.load(":/white/triangle_hor.png");
    mGraphicsWhite.pixmapTriangleVert.load(":/white/triangle_vert.png");
    mGraphicsWhite.pixmapCenter.load(":/white/center.png");
    mGraphicsWhite.pixmapOptRange.load(":/white/opt_range.png");
    mGraphicsWhite.pixmapLogo.load(":/logo.png");

    mGraphicsBlack.pixmapCrossWide.load(":/black/cross_shz.png");
    mGraphicsBlack.pixmapCrossNarrow.load(":/black/cross_uz.png");
    mGraphicsBlack.pixmapCrossThermo.load(":/black/cross_teplo.png");
    mGraphicsBlack.pixmapCrossZoomThermo.load(":/black/cross_teplo_zoom.png");
    mGraphicsBlack.pixmapOptNarrow.load(":/black/opt_uz.png");
    mGraphicsBlack.pixmapOptThermo.load(":/black/opt_teplo.png");
    mGraphicsBlack.pixmapOptZoomThermo.load(":/black/opt_teplo_zoom.png");
    mGraphicsBlack.pixmapOptWide.load(":/black/opt_shz.png");
    mGraphicsBlack.pixmapRectNarrow.load(":/black/ramka_uz.png");
    mGraphicsBlack.pixmapAim.load(":/black/target.png");
    mGraphicsBlack.pixmapCrossTg.load(":/black/cross.png");
    mGraphicsBlack.pixmapTriangleHor.load(":/black/triangle_hor.png");
    mGraphicsBlack.pixmapTriangleVert.load(":/black/triangle_vert.png");
    mGraphicsBlack.pixmapCenter.load(":/black/center.png");
    mGraphicsBlack.pixmapOptRange.load(":/black/opt_range.png");
    mGraphicsBlack.pixmapLogo.load(":/logo.png");
    
    mGraphics = mGraphicsBlack;
    color = Qt::black;
    idColor = 0;
    pixmapL = mGraphics.pixmapLogo;

    mCorrectionX = 0;
    mCorrectionY = 0;

    mPositionEncoderX = 0;
    mPositionEncoderY = 0;

    mJustX = 0;
    mJustY = 0;

    mRectWidth = 100;
    mRectHeight = 100;

    mRange = 100;

    mHeightOptRange = 100;
    mVisibleOptRange = false;

    mTracking = false;
    mStabilization = false;
    mConnect = false;
    isVisibleTracking = false;

    mCameraMode = WIDE_FORMAT;
    setCameraMode(mCameraMode);

    isFilter = false;
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(update()));
//    connect(mTrackingClient, SIGNAL(newCenterMassTracking(int,int)),
//            SLOT(setCenterMassTracking(int,int)));
//    connect(mTrackingClient, SIGNAL(newRects(QRect, QRect)),
//            SLOT(setRects(QRect, QRect)));
    timer->start(50);
//    mTrackingClient->start();
    mAimType = HOME;
    updateRect();
    need_to_show_pixmap_opt = true;
    is_operation_mode = true;
}

void OptWidget::setOperationMode(bool enabled)
{
    is_operation_mode = enabled;
}

void OptWidget::setCocking(bool enabled)
{
    is_cocking = enabled;
}

OptWidget::~OptWidget()
{
//    delete mTrackingClient;
    delete ui;
}

void OptWidget::setCenterMassTracking(int x, int y)
{
    mControllerManager->setCenterMassTracking(x, y);
}

void OptWidget::setControllerManager(ControllerManager *pControllerManager)
{
    mControllerManager = pControllerManager;
}

void OptWidget::setRects(QRect pRect_t1, QRect pRect_t2)
{
    mMutex.lock();
    mRect_t1 = pRect_t1;
    mRect_t2 = pRect_t2;
    mMutex.unlock();
}

void OptWidget::setCross(CameraMode pCameraMode)
{
    mMutex.lock();
    mCameraMode = pCameraMode;
    mMutex.unlock();
}

bool OptWidget::setFilter(bool state)
{
    isFilter = state;
//    mTrackingClient->setFilter(state);
    return true;
}

void OptWidget::invertCrossColor()
{
    mMutex.lock();
    if (idColor == 0)
    {
        idColor = 1;
        color = Qt::white;
        mGraphics = mGraphicsWhite;
    }
    else
    {
        idColor = 0;
        color = Qt::black;
        mGraphics = mGraphicsBlack;
    }
    switch (mCameraMode)
    {
        case NARROW_FORMAT:
            pixmapCross = mGraphics.pixmapCrossNarrow;
            pixmapOpt = mGraphics.pixmapOptNarrow;
            break;
        case WIDE_FORMAT:
            pixmapCross = mGraphics.pixmapCrossWide;
            pixmapOpt = mGraphics.pixmapOptWide;
            pixmapNarrow = mGraphics.pixmapRectNarrow;
            break;
        case THERMAL:
            pixmapCross = mGraphics.pixmapCrossThermo;
            pixmapOpt = mGraphics.pixmapOptThermo;
            break;
        case ZOOM_THERMAL:
            pixmapCross = mGraphics.pixmapCrossZoomThermo;
            pixmapOpt = mGraphics.pixmapOptZoomThermo;
            break;
    }
    mMutex.unlock();
    updateRect();
}

void OptWidget::setBlockPP(bool enabled)
{
    is_cocking = enabled;
}

void OptWidget::updateRect()
{
    float w = 0.0;
    float h = 0.0;
    QString strColor;
    if (idColor == 1)
        strColor = "WHITE";
    else
        strColor = "BLACK";
    switch (mAimType)
    {
        case HOME:
            ui->label->setText(TEXT_COLOR(strColor, tr("Target type: HUMAN")));
            w = HOME_SIZE_W;
            h = HOME_SIZE_H;
            break;
        case CAR:
            ui->label->setText(TEXT_COLOR(strColor, tr("Target type: CAR")));
            w = CAR_SIZE_W;
            h = CAR_SIZE_H;
            break;
/*
        case HELICOPTER:
            ui->label->setText(TEXT_COLOR(strColor, tr("Target type: HELICOPTER")));
            w = HELICOPTER_SIZE_W;
            h = HELICOPTER_SIZE_H;
            break;
*/
    }
    mMutex.lock();
    if (mCameraMode == WIDE_FORMAT)
    {
        mRectWidth = (atan((double)(w / 2.0) / (double)mRange) * 180 / M_PI)
                * ((double)DEFAULT_WIDTH / ANGLE_WIDE_X) * 2.0;
        mRectHeight = (atan((double)(h / 2.0) / (double)mRange) * 180 / M_PI)
                * ((double)DEFAULT_HEIGHT / ANGLE_WIDE_Y) * 2.0;
    }
    if (mCameraMode == NARROW_FORMAT)
    {
        mRectWidth = (atan((double)(w / 2.0) / (double)mRange) * 180 / M_PI)
                * ((double)DEFAULT_WIDTH / ANGLE_NARROW_X) * 2.0;
        mRectHeight = (atan((double)(h / 2.0) / (double)mRange) * 180 / M_PI)
                * ((double)DEFAULT_HEIGHT / ANGLE_NARROW_Y) * 2.0;
    }
    if (mCameraMode == THERMAL)
    {
        mRectWidth = (atan((double)(w / 2.0) / (double)mRange) * 180 / M_PI)
                * ((double)DEFAULT_WIDTH / ANGLE_THERMAL_X) * 2.0;
        mRectHeight = (atan((double)(h / 2.0) / (double)mRange) * 180 / M_PI)
                * ((double)DEFAULT_HEIGHT / ANGLE_THERMAL_Y) * 2.0;
    }
    if (mCameraMode == ZOOM_THERMAL)
    {
        mRectWidth = (atan((double)(w / 2.0) / (double)mRange) * 180 / M_PI)
                * ((double)DEFAULT_WIDTH / ANGLE_ZOOM_THERMAL_X) * 2.0;
        mRectHeight = (atan((double)(h / 2.0) / (double)mRange) * 180 / M_PI)
                * ((double)DEFAULT_HEIGHT / ANGLE_ZOOM_THERMAL_Y) * 2.0;
    }
    if (mRectWidth > DEFAULT_WIDTH / 3)
        mRectWidth = DEFAULT_WIDTH / 3;
    if (mRectHeight > DEFAULT_HEIGHT / 3)
        mRectHeight = DEFAULT_HEIGHT / 3;
    if (mRectWidth < MIN_RECT_WIDTH)
        mRectWidth = MIN_RECT_WIDTH;
    if (mRectHeight < MIN_RECT_HEIGHT)
        mRectHeight = MIN_RECT_HEIGHT;
    mMutex.unlock();
}

void OptWidget::inversia(bool pButton)
{
    if (pButton)
    {
        mGraphics = mGraphicsBlack;
    }
    else
    {
        mGraphics = mGraphicsWhite;
    }
}

void OptWidget::setAimType(AimType pAimType)
{
    mAimType = pAimType;
    updateRect();
}

void OptWidget::optRangeUp()
{
    ++mHeightOptRange;
    updateOptRange(mHeightOptRange, mCameraMode);
}

void OptWidget::optRangeDown()
{
    if (mHeightOptRange > 0)
    {
        --mHeightOptRange;
        updateOptRange(mHeightOptRange, mCameraMode);
    }
}

void OptWidget::setVisibleOptRange(bool state)
{
    mMutex.lock();
    mVisibleOptRange = state;
    mMutex.unlock();
}

void OptWidget::setRange(int pRange)
{
    mRange = pRange;
    updateRect();
}

void OptWidget::setCameraMode(CameraMode pCameraMode)
{
    mMutex.lock();
    isVisibleTracking = false;
    mCameraMode = pCameraMode;
    switch (mCameraMode)
    {
        case NARROW_FORMAT:
            pixmapCross = mGraphics.pixmapCrossNarrow;
            pixmapOpt = mGraphics.pixmapOptNarrow;
            break;
        case WIDE_FORMAT:
            pixmapCross = mGraphics.pixmapCrossWide;
            pixmapOpt = mGraphics.pixmapOptWide;
            pixmapNarrow = mGraphics.pixmapRectNarrow;
            break;
        case THERMAL:
            pixmapCross = mGraphics.pixmapCrossThermo;
            pixmapOpt = mGraphics.pixmapOptThermo;
            break;
        case ZOOM_THERMAL:
            pixmapCross = mGraphics.pixmapCrossZoomThermo;
            pixmapOpt = mGraphics.pixmapOptZoomThermo;
            break;
    }
    mMutex.unlock();
//    mTrackingClient->setTrackingClient(false);
/*    if (pCameraMode != ZOOM_THERMAL)
        mTrackingClient->setCamera(pCameraMode);
    else
        mTrackingClient->setCamera(THERMAL);
*/    updateRect();
}

void OptWidget::setNullRect()
{
    mRect_t1.setWidth(0);
    mRect_t2.setHeight(0);
    mRect_t1.setHeight(0);
    mRect_t2.setWidth(0);
}

void OptWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    mMutex.lock();
    /*draw tracking rects*/
    if (mTracking && isVisibleTracking)
    {
        painter.setPen(QColor(0, 255, 0));
        painter.drawRect(mRect_t1);
        painter.setPen(QColor(0, 0, 255));
        painter.drawRect(mRect_t2);
    }
    else
    {
        setNullRect();
    }

    if (mTracking)
        ui->label->show();
    else
        ui->label->hide();
    /*draw main cross*/
    painter.drawImage(1210, 14, pixmapL); //?????????? ???????????????? ???? (????10 , yy14)
    painter.drawImage(mJustX, mJustY, pixmapCross);
    painter.drawImage(width() / 2 - mGraphics.pixmapCenter.width() / 2,
                      height() / 2 - mGraphics.pixmapCenter.height() / 2,
                      mGraphics.pixmapCenter);
    if (need_to_show_pixmap_opt)
        painter.drawImage(15, 300, pixmapOpt);
    if (mVisibleOptRange)
        painter.drawImage(width() / 2 - mGraphics.pixmapOptRange.width() / 2 + mJustX,
                          height() / 2 - mGraphics.pixmapOptRange.height() / 2 + mJustY - mHeightOptRange,
                          mGraphics.pixmapOptRange);
    if (mCameraMode == WIDE_FORMAT)
           painter.drawImage(width() / 2 - pixmapNarrow.width() / 2,
                             height() / 2 - pixmapNarrow.height() / 2,
                             pixmapNarrow);
    painter.drawImage(int(mCorrectionX) - mGraphics.pixmapCrossTg.width() / 2 + mJustX,
                      int(mCorrectionY) - mGraphics.pixmapCrossTg.height() / 2 + mJustY,
                      mGraphics.pixmapCrossTg);
    /*draw aim*/
    if (!mTracking && is_operation_mode)
    {
        QImage lPixmapAim;
        lPixmapAim = mGraphics.pixmapAim;
        for (int i = 0; i < AimList::getSingletonPtr()->size(); ++i)
        {
            Aim *lAim = AimList::getSingletonPtr()->get(i);
            if (lAim) {
                long PosX = 0;
                long PosY = 0;
                long DeltaPositionX = 0;
                long UnitPositionX = 0;
                UnitPositionX = mControllerManager->getUnitPositionX(mPositionEncoderX);
                DeltaPositionX = mControllerManager->getDeltaX(lAim->mPositionX, UnitPositionX);
                switch (mCameraMode)
                {
                    case WIDE_FORMAT:
                        PosX = static_cast<long>(static_cast<double>(-INVERT_SPEED_X)
                                                 * static_cast<double>(-DeltaPositionX)
                                                 * static_cast<double>(-DEFAULT_WIDTH)
                                                 / ANGLE_WIDE_X / 100.0
                                                 + static_cast<double>(DEFAULT_WIDTH) / 2.0);
                        PosY = static_cast<long>(static_cast<double>(-INVERT_SPEED_Y)
                                                 * static_cast<double>(-mPositionEncoderY
                                                                       - lAim->mPositionY)
                                                 * static_cast<double>(DEFAULT_HEIGHT)
                                                 / ANGLE_WIDE_Y / 100.0
                                                 + static_cast<double>(DEFAULT_HEIGHT) / 2.0);
                        break;
                    case NARROW_FORMAT:
                        PosX = static_cast<long>(static_cast<double>(-INVERT_SPEED_X)
                                                 * static_cast<double>(-DeltaPositionX)
                                                 * static_cast<double>(-DEFAULT_WIDTH)
                                                 / ANGLE_NARROW_X / 100.0
                                                 + static_cast<double>(DEFAULT_WIDTH) / 2.0);
                        PosY = static_cast<long>(static_cast<double>(-INVERT_SPEED_Y)
                                                 * static_cast<double>(-mPositionEncoderY
                                                                       - lAim->mPositionY)
                                                 * static_cast<double>(DEFAULT_HEIGHT)
                                                 / ANGLE_NARROW_Y / 100.0
                                                 + static_cast<double>(DEFAULT_HEIGHT) / 2.0);
                        break;
                    case THERMAL:
                        PosX = static_cast<long>(static_cast<double>(-INVERT_SPEED_X)
                                                 * static_cast<double>(-DeltaPositionX)
                                                 * static_cast<double>(-DEFAULT_WIDTH)
                                                 / ANGLE_THERMAL_X / 100.0
                                                 + static_cast<double>(DEFAULT_WIDTH) / 2.0);
                        PosY = static_cast<long>(static_cast<double>(-INVERT_SPEED_Y)
                                                 * static_cast<double>(-mPositionEncoderY
                                                                       - lAim->mPositionY)
                                                 * static_cast<double>(DEFAULT_HEIGHT)
                                                 / ANGLE_THERMAL_Y / 100.0
                                                 + static_cast<double>(DEFAULT_HEIGHT) / 2.0);
                        break;
                    case ZOOM_THERMAL:
                        PosX = static_cast<long>(static_cast<double>(-INVERT_SPEED_X)
                                                 * static_cast<double>(-DeltaPositionX)
                                                 * static_cast<double>(-DEFAULT_WIDTH)
                                                 / ANGLE_ZOOM_THERMAL_X / 100.0
                                                 + static_cast<double>(DEFAULT_WIDTH) / 2.0);
                        PosY = static_cast<long>(static_cast<double>(-INVERT_SPEED_Y)
                                                 * static_cast<double>(-mPositionEncoderY
                                                                       - lAim->mPositionY)
                                                 * static_cast<double>(DEFAULT_HEIGHT)
                                                 / ANGLE_ZOOM_THERMAL_Y / 100.0
                                                 + static_cast<double>(DEFAULT_HEIGHT) / 2.0);
                        break;
                }
                painter.drawImage(int(PosX) - lPixmapAim.width() / 2 + mJustX,
                                  int(PosY) - lPixmapAim.height() / 2 + mJustY,
                                  lPixmapAim);
                painter.setPen(color);
                painter.drawText(QRect(int(PosX) - lPixmapAim.width() / 2 + 2 + mJustX,
                                       int(PosY) - lPixmapAim.height() / 2 + mJustY,
                                       15, 15),
                                 QString::number(lAim->mTarget));
            }
        }
    }
    if (mTracking)
    {
        painter.setPen(QColor(0, 0, 255));
        int m_x = cursor().pos().x() - geometry().x();
        int m_y = cursor().pos().y() - geometry().y();
        int x = m_x - mRectWidth / 2;
        int y = m_y - mRectHeight / 2;
        if (m_x + mRectWidth / 2 >= DEFAULT_WIDTH)
            x = DEFAULT_WIDTH - mRectWidth - 1;
        if (m_x <= mRectWidth / 2)
            x = 0;
        if (m_y + mRectHeight / 2 >= DEFAULT_HEIGHT)
            y = DEFAULT_HEIGHT - mRectHeight - 1;
        if (m_y <= mRectHeight / 2)
            y = 0;
        if (is_cursor_in_area)
        {
            mRectTracking = QRect(x, y, mRectWidth, mRectHeight);
            painter.setPen(color);
            painter.drawRect(mRectTracking);
        }
    }
    painter.end();
    mMutex.unlock();
}

void OptWidget::mousePressEvent(QMouseEvent *event)
{
    int lJustX = 0;
    int lJustY = 0;
    float kofX = 0.0f;
    float kofx = 0.0f;
    float kofy = 0.0f;
    mMutex.lock();
    lJustX = mJustX;
    lJustY = mJustY;
    bool isTracking = mTracking;
    CameraMode lCameraMode = mCameraMode;
    mMutex.unlock();
    if (!isTracking)
    {
        if (event->button() == Qt::LeftButton
                || event->button() == Qt::RightButton)
        {
            int lX = event->x();
            int lY = event->y();
            long lConvertX = 0;
            long lConvertY = 0;
            long aC_ConvertX = 0;
            long aC_ConvertY = 0;

            lX = DEFAULT_WIDTH / 2 - lX + lJustX;
            lY = DEFAULT_HEIGHT / 2 - lY + lJustY;
            switch (lCameraMode)
            {
                case NARROW_FORMAT:
                    lConvertX = static_cast<long>(static_cast<double>(lX) * ANGLE_NARROW_X * 100.0  / static_cast<double>(DEFAULT_WIDTH));
                    lConvertY = static_cast<long>(static_cast<double>(lY) * ANGLE_NARROW_Y * 100.0  / static_cast<double>(DEFAULT_HEIGHT));

                    kofX = 8.449f;
                    kofx = 7.928f;
                    kofy = 6.863f;
                    if (lConvertX >= 0)
                    {
                        aC_ConvertX = static_cast<long>((((-127.0f/710.0f)*static_cast<double>(lConvertX)*kofX)));
                        if (aC_ConvertX <= -127)
                            aC_ConvertX = -127;
                    }
                    else
                    {
                        aC_ConvertX = static_cast<long>(((((127.0f/710.0f)*static_cast<double>(-1*lConvertX)*kofx))));
                        if (aC_ConvertX >= 127)
                            aC_ConvertX = 127;
                    }


                    if (lConvertY >= 0)
                    {
                         aC_ConvertY = static_cast<long>((((127.0f/530.0f)*static_cast<double>(lConvertY)*kofy)));
                        if (aC_ConvertY >= 127)
                            aC_ConvertY = 127;
                    }
                    else
                    {
                        aC_ConvertY = static_cast<long>(((((127.0f/530.0f)*static_cast<double>(lConvertY)*kofy))));
                        if (aC_ConvertY <= -127)
                            aC_ConvertY = -110;
                    }

                    emit move_Ac_Target(aC_ConvertX,aC_ConvertY); // ???????????? ?????????????? ???? ???????????????????? ?????????????????????? ??????????
                    break;

                case WIDE_FORMAT:
                    lConvertX = static_cast<long>(static_cast<double>(lX) * ANGLE_WIDE_X * 100.0    / static_cast<double>(DEFAULT_WIDTH));
                    lConvertY = static_cast<long>(static_cast<double>(lY) * ANGLE_WIDE_Y * 100.0    / static_cast<double>(DEFAULT_HEIGHT));

                    /*???????? ???????????????? ?????????????????? ?????????????????? ?????????? ?????? ???????????????? ???????? ???????????? ????????????*/
                    kofX = 1.428f;
                    kofx = 1.34f;
                    kofy = 1.16f;
                    if (lConvertX >= 0)
                    {
                        aC_ConvertX = static_cast<long>((((-127.0f/710.0f)*static_cast<double>(lConvertX)*kofX)));
                        if (aC_ConvertX <= -127)
                            aC_ConvertX = -127;
                    }
                    else
                    {
                        aC_ConvertX = static_cast<long>(((((127.0f/710.0f)*static_cast<double>(-1*lConvertX)*kofx))));
                        if (aC_ConvertX >= 127)
                            aC_ConvertX = 127;
                    }


                    if (lConvertY >= 0)
                    {
                        aC_ConvertY = static_cast<long>((((127.0f/530.0f)*static_cast<double>(lConvertY)*kofy)));
                        if (aC_ConvertY >= 127)
                            aC_ConvertY = 127;
                    }
                    else
                    {
                        aC_ConvertY = static_cast<long>(((((127.0f/530.0f)*static_cast<double>(lConvertY)*kofy))));
                        if (aC_ConvertY <= -127)
                            aC_ConvertY = -110;
                    }

                    emit move_Ac_Target(aC_ConvertX,aC_ConvertY); // ???????????? ?????????????? ???? ???????????????????? ?????????????????????? ??????????

                    break;

                case THERMAL:
                    lConvertX = static_cast<long>(static_cast<double>(lX) * ANGLE_THERMAL_X * 100.0/ static_cast<double>(DEFAULT_WIDTH));
                    lConvertY = static_cast<long>(static_cast<double>(lY) * ANGLE_THERMAL_Y * 100.0/ static_cast<double>(DEFAULT_HEIGHT));

                    kofX = 3.000f;
                    kofx = 2.825f;
                    kofy = 2.385f;
                    if (lConvertX >= 0)
                    {
                        aC_ConvertX = static_cast<long>((((-127.0f/640.0f)*static_cast<double>(lConvertX)*kofX)));
                        if (aC_ConvertX <= -127)
                            aC_ConvertX = -127;
                    }
                    else
                    {
                        aC_ConvertX = static_cast<long>(((((127.0f/640.0f)*static_cast<double>(-1*lConvertX)*kofx))));
                        if (aC_ConvertX >= 127)
                            aC_ConvertX = 127;
                    }


                    if (lConvertY >= 0)
                    {
                        aC_ConvertY = static_cast<long>((((127.0f/480.0f)*static_cast<double>(lConvertY)*kofy)));
                        if (aC_ConvertY >= 127)
                            aC_ConvertY = 127;
                    }
                    else
                    {
                    aC_ConvertY = static_cast<long>(((((127.0f/480.0f)*static_cast<double>(lConvertY)*kofy))));
                    if (aC_ConvertY <= -127)
                        aC_ConvertY = -110;
                    }

                    emit move_Ac_Target(aC_ConvertX,aC_ConvertY); // ???????????? ?????????????? ???? ???????????????????? ?????????????????????? ??????????
                    break;

                case ZOOM_THERMAL:
                    lConvertX = static_cast<long>(static_cast<double>(lX) * ANGLE_ZOOM_THERMAL_X * 100.0 / static_cast<double>(DEFAULT_WIDTH));
                    lConvertY = static_cast<long>(static_cast<double>(lY) * ANGLE_ZOOM_THERMAL_Y * 100.0 / static_cast<double>(DEFAULT_HEIGHT));

                    kofX = 6.000f;
                    kofx = 5.750f;
                    kofy = 4.770f;
                    if (lConvertX >= 0)
                    {
                        aC_ConvertX = static_cast<long>((((-127.0f/640.0f)*static_cast<double>(lConvertX)*kofX)));
                        if (aC_ConvertX <= -127)
                            aC_ConvertX = -127;
                    }
                    else
                    {
                        aC_ConvertX = static_cast<long>(((((127.0f/640.0f)*static_cast<double>(-1*lConvertX)*kofx))));
                        if (aC_ConvertX >= 127)
                            aC_ConvertX = 127;
                    }


                    if (lConvertY >= 0)
                    {
                        aC_ConvertY = static_cast<long>((((127.0f/480.0f)*static_cast<double>(lConvertY)*kofy)));
                        if (aC_ConvertY >= 127)
                            aC_ConvertY = 127;
                    }
                        else
                    {
                        aC_ConvertY = static_cast<long>(((((127.0f/480.0f)*static_cast<double>(lConvertY)*kofy))));
                        if (aC_ConvertY <= -127)
                            aC_ConvertY = -110;
                    }

                    emit move_Ac_Target(aC_ConvertX,aC_ConvertY); // ???????????? ?????????????? ???? ???????????????????? ?????????????????????? ??????????
                    break;
                }

            if ((!is_cocking) && (!mControllerManager->enabled_as))

                mControllerManager->setPositionDeviceDrive(-lConvertX,lConvertY,false);
        }
    }
}

void OptWidget::mouseReleaseEvent(QMouseEvent *event)
{
    mMutex.lock();
    bool isTracking = mTracking;
    mMutex.unlock();
    if (isTracking) {
        if (event->button() == Qt::RightButton)
        {
            int lX = event->x();
            int lY = event->y();
            lX = lX - DEFAULT_WIDTH / 2;
            lY = lY - DEFAULT_HEIGHT / 2;
            mControllerManager->setCorrectionTracking(lX, lY);
        }
        else
        {
            mMutex.lock();
            isPressRect = false;
            isVisibleTracking = true;
            mRectTracking = norm(mRectTracking);
//            mTrackingClient->setTypeTrackingClient(mTypeTracking);
//            mTrackingClient->setRectTarget(mRectTracking);
            if (mTypeTracking == 1)
            {
//                mTrackingClient->setTrackingClient(true);
//                mControllerManager->setMode(MODE_TRACKING); 7.10.15
            }
            else
            {
                mControllerManager->setMode(MODE_SEMI_AUTO);
//                mTrackingClient->setTrackingClient(false);
            }
            mMutex.unlock();
            mControllerManager->resetCorrectionTracking();
        }
    }
}

void OptWidget::enterEvent(QEvent *)
{
    is_cursor_in_area = true;
}

void OptWidget::leaveEvent(QEvent *)
{
    is_cursor_in_area = false;
}

void OptWidget::updateOptRange(int pHeinghtOptRange, CameraMode pCameraMode)
{
    long distance = 0;
    if (pCameraMode == WIDE_FORMAT)
        distance = long(5121.0 / double(pHeinghtOptRange) + 0.5);
    if (pCameraMode == NARROW_FORMAT)
        distance = long(32775.0 / double(pHeinghtOptRange) + 0.5);
    if (pCameraMode == THERMAL)
        distance = long((12783.3) / double(pHeinghtOptRange) + 0.5);
    if (pCameraMode == ZOOM_THERMAL)
        distance = long((25544.0) / double(pHeinghtOptRange) + 0.5);
    if (distance > 0 && distance < 2600)
        mControllerManager->setRange(distance);
}

void OptWidget::setTypeTracking(int pType)
{
    mMutex.lock();
    mTypeTracking = pType;
//    mTrackingClient->setTypeTrackingClient(pType);
    mMutex.unlock();
}


void OptWidget::setTargets(std::vector<QRect> pTargets)
{
    mMutex.lock();
    mTargets = pTargets;
    mMutex.unlock();
}

void OptWidget::setTracking(bool state)
{
    mMutex.lock();
    mTracking = state;
    mMutex.unlock();
}

void OptWidget::setStabilization(bool state)
{
    mMutex.lock();
    mStabilization = state;
    mMutex.unlock();
}

void OptWidget::setJustCross(long pJustX, long pJustY)
{
    mMutex.lock();
    mJustX = pJustX;
    mJustY = pJustY;
    mMutex.unlock();
}

void OptWidget::setCorrectionCross(long pCorrectionX, long pCorrectionY)
{
    mMutex.lock();
    mCorrectionX = pCorrectionX;
    mCorrectionY = pCorrectionY;
    switch (mCameraMode)
    {
        case WIDE_FORMAT:
            mCorrectionX = static_cast<long>(static_cast<double>(mCorrectionX)
                                             * static_cast<double>(-DEFAULT_WIDTH)
                                             / ANGLE_WIDE_X / 100.0
                                             + static_cast<double>(DEFAULT_WIDTH) / 2.0);
            mCorrectionY = static_cast<long>(static_cast<double>(mCorrectionY)
                                             * static_cast<double>(DEFAULT_HEIGHT)
                                             / ANGLE_WIDE_Y / 100.0
                                             + static_cast<double>(DEFAULT_HEIGHT) / 2.0);
            break;
        case NARROW_FORMAT:
            mCorrectionX = static_cast<long>(static_cast<double>(mCorrectionX)
                                             * static_cast<double>(-DEFAULT_WIDTH)
                                             / ANGLE_NARROW_X / 100.0
                                             + static_cast<double>(DEFAULT_WIDTH) / 2.0);
            mCorrectionY = static_cast<long>(static_cast<double>(mCorrectionY)
                                             * static_cast<double>(DEFAULT_HEIGHT)
                                             / ANGLE_NARROW_Y / 100.0
                                             + static_cast<double>(DEFAULT_HEIGHT) / 2.0);
            break;
        case THERMAL:
            mCorrectionX = static_cast<long>(static_cast<double>(mCorrectionX)
                                             * static_cast<double>(-DEFAULT_WIDTH)
                                             / ANGLE_THERMAL_X / 100.0
                                             + static_cast<double>(DEFAULT_WIDTH) / 2.0);
            mCorrectionY = static_cast<long>(static_cast<double>(mCorrectionY)
                                             * static_cast<double>(DEFAULT_HEIGHT)
                                             / ANGLE_THERMAL_Y / 100.0
                                             + static_cast<double>(DEFAULT_HEIGHT) / 2.0);
            break;
        case ZOOM_THERMAL:
            mCorrectionX = static_cast<long>(static_cast<double>(mCorrectionX)
                                             * static_cast<double>(-DEFAULT_WIDTH)
                                             / ANGLE_ZOOM_THERMAL_X / 100.0
                                             + static_cast<double>(DEFAULT_WIDTH) / 2.0);
            mCorrectionY = static_cast<long>(static_cast<double>(mCorrectionY)
                                             * static_cast<double>(DEFAULT_HEIGHT)
                                             / ANGLE_ZOOM_THERMAL_Y / 100.0
                                             + static_cast<double>(DEFAULT_HEIGHT) / 2.0);
            break;
    }
    mMutex.unlock();
}

void OptWidget::setPositionEncoderX(long value)
{
    mMutex.lock();
    mPositionEncoderX = value;
    mMutex.unlock();
}

void OptWidget::setPositionEncoderY(long value)
{
    mMutex.lock();
    mPositionEncoderY = value;
    mMutex.unlock();
}

void OptWidget::setVisibleTracking(bool state)
{
    mMutex.lock();
    isVisibleTracking = state;
    mMutex.unlock();
}
/*
int OptWidget::getDistanceToRect(QRect _rect, QPoint _point)
{
    int dist = getDistanceToLine(QLine(_rect.topLeft(), _rect.topRight()),    _point);
    int tmp = getDistanceToLine(QLine(_rect.topLeft(),  _rect.bottomLeft()),  _point);
    dist = (dist > tmp) ? dist : tmp;
    tmp = getDistanceToLine(QLine(_rect.bottomLeft(),   _rect.bottomRight()), _point);
    dist = (dist > tmp) ? dist : tmp;
    tmp = getDistanceToLine(QLine(_rect.bottomRight(),  _rect.topRight()),    _point);
    dist = (dist > tmp) ? dist : tmp;
    tmp = getDistanceToLine(QLine(_rect.topLeft(),      _rect.bottomRight()), _point);
    dist = (dist > tmp) ? dist : tmp;
    tmp = getDistanceToLine(QLine(_rect.topRight(),     _rect.bottomLeft()),  _point);
    dist = (dist > tmp) ? dist : tmp;
    return dist;
}

int OptWidget::getDistanceToLine(QLine line, QPoint point)
{
//    explode the stuff into coordinates
    int x1 = line.x1();
    int y1 = line.y1();
    int x2 = line.x2();
    int y2 = line.y2();
    int x3 = point.x();
    int y3 = point.y();
    double area = 0.5 * static_cast<double>((x1 * y2 + x2 * y3 + x3 * y1
                                             - x2 * y1 - x3 * y2 - x1 * y3));
    double base = sqrt((double)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
    return static_cast<int>(2.0 * area) / base;
}
*/
QRect OptWidget::norm(QRect rect)
{
    QRect norm_rect = rect;
    int x1, x2, y1, y2;
    int norm_x1, norm_x2, norm_y1, norm_y2;
    norm_rect.getCoords(&x1, &y1, &x2, &y2);
    /* X */
    if (x2 < x1)
    {
        norm_x2 = x1;
        norm_x1 = x2;
    }
    else
    {
        norm_x2 = x2;
        norm_x1 = x1;
    }

    /* Y */
    if (y2 < y1)
    {
        norm_y2 = y1;
        norm_y1 = y2;
    }
    else
    {
        norm_y2 = y2;
        norm_y1 = y1;
    }
    norm_rect.setCoords(norm_x1, norm_y1, norm_x2, norm_y2);
    return norm_rect;
}

void OptWidget::setPixmapOptEnabled()
{
    if (need_to_show_pixmap_opt)
        need_to_show_pixmap_opt = false;
    else
        need_to_show_pixmap_opt = true;
}
