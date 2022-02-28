#include "devicethread.h"

DeviceThread::DeviceThread() : is_closed(false)
{
    tcp_cfg = CfgManager::getSingletonPtr()->getTcpCfg();
    connect(this, SIGNAL(newPermission(bool)),
            ActionList::getSingletonPtr(), SLOT(setPermission(bool)));

}

DeviceThread::~DeviceThread()
{
    close();
    wait(2000);
}

void DeviceThread::close()
{
    mutex.lock();
    is_closed = true;
    mutex.unlock();

}

void DeviceThread::run()
{

    emit newPermission(false);
    while (!is_closed)
    {

        try
        {
            TCPClient tcp_client(tcp_cfg->maddr, tcp_cfg->mPort);


            /**/

            emit newPermission(true);
            emit newLogMsg(tr("Device drive connected"));
            emit newConnectedDevice(true);


            while (!is_closed)
                update(tcp_client);

        }
        catch (TCPConnectionError)
        {
            usleep(500000);
            continue;
        }
        catch (TCPError)
        {
            /* SOME OTHER TCP EXCEPTION */
        } catch (...)
        {
            /* SOME OTHER UNEXPECTED EXCEPTION */
        }

        emit newPermission(false);
        emit newLogMsg(tr("Device drive not connected"));
        emit newConnectedDevice(false);
    }
}

void DeviceThread::update(TCPClient &tcp_client)
{
    Action *action = ActionList::getSingletonPtr()->getAction();
    if (action)
    {
        tcp_client.writeAction(action);
        parsingResponse(tcp_client.readAction());
    }
    else
    {
        msleep(20);
    }
}

void DeviceThread::parsingResponse(Action *action)
{
    switch (action->getActionType())
    {
        case ACTION_TYPE_ENCODER_SPEED_X:
            emit newSpeedEncoderX(action->getValue());
            break;
        case ACTION_TYPE_ENCODER_SPEED_Y:
            emit newSpeedEncoderY(action->getValue());
            break;
        case ACTION_TYPE_ENCODER_POSITION_X:
            emit newPositionEncoderX(action->getValue());
            break;
        case ACTION_TYPE_ENCODER_POSITION_Y:
            emit newPositionEncoderY(action->getValue());
            break;
        case ACTION_TYPE_TRMO_0:
            emit newThermo(action->getValue());
            break;
        case ACTION_TYPE_PRESSURE:
            emit newPressure(action->getValue(), true);
            break;
        case ACTION_TYPE_AMMUNITION_COUNTER:
            emit newAmmunitionCounter(action->getValue(), false);
            break;
        case ACTION_TYPE_RANGE:
            emit newRange(action->getValue() / 100);
            break;
        case ACTION_TYPE_ACHIEVEMENT_POSITION:
            emit newAchievementPosition(action->getValue());
            break;
        case ACTION_TYPE_VOLTAGE_EXTERNAL:
            emit newVoltageExternal(action->getValue());
            break;
        case ACTION_TYPE_VOLTAGE_BATTERY:
            emit newVoltageBattery(action->getValue());
            break;
        case ACTION_TYPE_CLOSE:
            emit newClose();
            break;
        case ACTION_TYPE_STAND_BY_MODE:
        case ACTION_TYPE_OPERATION_MODE :
            break;
        case ACTION_TYPE_BOLT_NOTCH :
            emit newResBoltNotch(action->getValue());
            break;
    }
    delete action;
}
