#include "plathormdir.h"
#include "ui_plathormdir.h"

PlathormDir::PlathormDir(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlathormDir)
{
    ui->setupUi(this);
    mAngle = 0;
    mPixmapDir.load("://res/images/compass_mbdu.png");
//    mPixmapBackground.load(":/compass.png");
}

PlathormDir::~PlathormDir()
{
    delete ui;
}

void PlathormDir::setAngle(int pAngle)
{
    mAngle = pAngle;
    update();
}

void PlathormDir::inversia(bool pFlag)
{
    if (pFlag)      mPixmapDir.load("://res/images/compass_mbdu.png");
    else            mPixmapDir.load("://res/images/compass_mbdu_inversia.jpg");
}

void PlathormDir::paintEvent(QPaintEvent *)
{
    QPainter pb(this);
    pb.drawImage(width() / 2 - mPixmapBackground.width() / 2,
                 height() / 2 - mPixmapBackground.height() / 2 - 10,
                 mPixmapBackground);
    pb.translate(width() / 2 - mPixmapDir.width() / 2,
                 height() / 2 - mPixmapDir.height() / 2 - 5);
    pb.translate(mPixmapDir.width() / 2, mPixmapDir.height() / 2 - 5);
    pb.rotate(mAngle);
    pb.translate(-mPixmapDir.width() / 2, -mPixmapDir.height() / 2 - 5);
    pb.drawImage(0, 0, mPixmapDir);
    pb.end();
}
