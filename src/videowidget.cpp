#include "videowidget.h"
#include "ui_videowidget.h"

VideoWidget::VideoWidget(QWidget *parent) :
    QVideoWidget(parent), ui(new Ui::VideoWidget)
{
    ui->setupUi(this);
    isOperationMode = true;
    flagInversia = true;
    mImage = mZeroImage;
    mCamera = new Camera();
    connect(mCamera, SIGNAL(newFrame(QImage)),   SLOT(setImage(QImage)));
    connect(mCamera, SIGNAL(closeCamera()),      SLOT(closeConnection()));
    connect(mCamera, SIGNAL(newLogMsg(QString)), SIGNAL(newLogMsg(QString)));
    connect(mCamera, SIGNAL(gotConnection()),    SIGNAL(resetCamera()));
    mConnect = true;
    mCamera->start();
}

VideoWidget::~VideoWidget()
{
    delete mCamera;
    delete ui;
}

void VideoWidget::setCameraMode(CameraMode pCameraMode)
{
    mCamera->setCamera(pCameraMode);
}

void VideoWidget::closeConnection()
{
    mConnect = false;
}

void VideoWidget::setImage(QImage image)
{
    mConnect = true;
    mImage = image.scaled(1920,1040, Qt::KeepAspectRatio);
//    mImage = image;
    update();
}

void VideoWidget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    if (isOperationMode)
    {
        if (mConnect)
        {
            painter.drawImage(0, 0, mImage);
        }
        else
        {
            mImage = mZeroImage;
            painter.drawImage(0, 0, mImage);

            if (flagInversia)   painter.setPen(QColor::fromRgb(0x610404));
            else                painter.setPen(QColor::fromRgb(0xF68068));

            painter.drawText(width() / 2 - 50, height() / 2, 150, 600, true,
                             tr("LOADING"));
        }
    }
    else
    {
        mImage = mZeroImage;
        painter.drawImage(0, 0, mImage);

        if (flagInversia)   painter.setPen(QColor::fromRgb(0x610404));
        else                painter.setPen(QColor::fromRgb(0xF68068));

        if (isConnected)

            painter.drawText(width() / 2 - 50, height() / 2, 150, 600, true,
                             tr("STANDBY MODE"));
        else
            painter.drawText(width() / 2 - 50, height() / 2, 150, 600, true,
                             tr("NOT CONNECTED"));
    }
    painter.end();
}

void VideoWidget::setOperationState(bool state, bool is_not_connected)
{
    mMutex.lock();
    isOperationMode = state;
    isConnected = !is_not_connected;
    mMutex.unlock();
}

void VideoWidget::getFlagInversia(bool pFlag)
{
    if (pFlag)  flagInversia = pFlag;
    else        flagInversia = pFlag;

}

void VideoWidget::pictureCompression(int i)
{
    mCamera -> compresPicture(i);
}

void VideoWidget::setOperationMode(bool state, bool isNotConnetcted)
{
    mMutex.lock();
    isOperationMode = state;
    isConnected = !isNotConnetcted;
    mCamera->setOperationMode(state);
    mMutex.unlock();
}
