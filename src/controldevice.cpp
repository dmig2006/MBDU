#include "controldevice.h"

ControlDevice* ControlDevice::mControlDevice = 0;

ControlDevice::~ControlDevice()
{
    close();
    wait(2000);
}

ControlDevice* ControlDevice::getSingletonPtr()
{
    if (!mControlDevice)
        mControlDevice = new ControlDevice();
    return mControlDevice;
}

void ControlDevice::close()
{
    isClose = true;
    com.close();
    isInit = false;
}

bool ControlDevice::init()
{
    char port[] = "/dev/ttyS1";
    return com.open(port);
}

bool ControlDevice::reset()
{
    unsigned char writeBuffer[5] = {0};
    unsigned char readBuffer[4] = {0};
    writeBuffer[0] = 0x55;
    writeBuffer[1] = 0x00;
    writeBuffer[2] = 0x00;
    writeBuffer[3] = 0x00;
    writeBuffer[4] = 0x55;
    if (!com.write(writeBuffer, 5))
        return false;
    if (!com.read(readBuffer, 4))
        return false;
    if (readBuffer[0] == 0xAA && readBuffer[1] == 'R'
            && readBuffer[2] == 'S' && readBuffer[3] == 0xFF)
        return true;
    return false;
}

bool ControlDevice::getADC(unsigned char Number, int &Voltage)
{
    unsigned char writeBuffer[5] = {0};
    unsigned char readBuffer[5] = {0};
    writeBuffer[0] = 0x55;
    writeBuffer[1] = 0x02;
    writeBuffer[2] = 0x00;
    writeBuffer[3] = Number;
    writeBuffer[4] = crc8(writeBuffer, 4);
    if (!com.write(writeBuffer, 5))
        return false;
    if (!com.read(readBuffer, 5))
        return false;
    if (readBuffer[0] == 0xAA && readBuffer[1] == 0x02
            && readBuffer[4] == crc8(readBuffer, 4))
    {
        Voltage = (int)(readBuffer[2]) << 8;
        Voltage |= (int)(readBuffer[3]);
        return true;
    }
    return false;
}

bool ControlDevice::getVoltage(int &Voltage)
{
    unsigned char writeBuffer[5] = {0};
    unsigned char readBuffer[5] = {0};
    writeBuffer[0] = 0x55;
    writeBuffer[1] = 0x07;
    writeBuffer[2] = 0x00;
    writeBuffer[3] = 0x00;
    writeBuffer[4] = crc8(writeBuffer, 4);
    if (!com.write(writeBuffer, 5))
        return false;
    if (!com.read(readBuffer, 5))
        return false;
    if (readBuffer[0] == 0xAA && readBuffer[1] == 0x07
            && readBuffer[4] == crc8(readBuffer, 4))
    {
        Voltage = (int)(readBuffer[2]) << 8;
        Voltage |= (int)(readBuffer[3]);
        return true;
    }
    return false;
}

bool ControlDevice::getTemperature(int &Termo1, int& Termo0)
{
    unsigned char writeBuffer[5] = {0};
    unsigned char readBuffer[5] = {0};
    writeBuffer[0] = 0x55;
    writeBuffer[1] = 0x03;
    writeBuffer[2] = 0x00;
    writeBuffer[3] = 0x00;
    writeBuffer[4] = crc8(writeBuffer, 4);
    if (!com.write(writeBuffer, 5))
        return false;
    if (!com.read(readBuffer, 5))
        return false;
    if (readBuffer[0] == 0xAA && readBuffer[1] == 0x03
            && readBuffer[4] == crc8(readBuffer, 4))
    {
        Termo1 = readBuffer[2];
        Termo0 = readBuffer[3];
        return true;
    }
    return false;
}

bool ControlDevice::getKeyPressed(Key &pKey)
{
    bool isKey = false;
    mMutex.lock();
    if (keys.size() > 0)
    {
        pKey = keys.back();
        keys.pop_back();
        isKey = true;
    }
    mMutex.unlock();
    return isKey;
}

std::vector<Key> ControlDevice::getKeysState()
{
    std::vector<Key> keys;

    Key lKeyPermission;
    lKeyPermission.id = KEY_PERMISSION;
    lKeyPermission.state = 0;

    Key lKeyAuto;
    lKeyAuto.id = KEY_AUTO;
    lKeyAuto.state = 0;

    Key lKeySaveAim;
    lKeySaveAim.id = KEY_SAVE_AIM;
    lKeySaveAim.state = 0;

    Key lKeyBoltNotch;
    lKeyBoltNotch.id = KEY_BOLT_NOTCH;
    lKeyBoltNotch.state = 0;

    Key lKeySensors;
    lKeySensors.id = KEY_SENSORS;
    lKeySensors.state = 0;

    Key lKeyFireType;
    lKeyFireType.id = KEY_FIRE_TYPE;
    lKeyFireType.state = 0;

    Key lKeyTypeBrush;
    lKeyTypeBrush.id = KEY_TYPE_BURST;
    lKeyTypeBrush.state = 0;

    Key lKeyTracking;
    lKeyTracking.id = KEY_TRACKING;
    lKeyTracking.state = 0;

    Key lKeyAimMode;
    lKeyAimMode.id = KEY_AIM_MODE;
    lKeyAimMode.state = 0;

    Key lKeyStabilization;
    lKeyStabilization.id = KEY_STABILIZATION;
    lKeyStabilization.state = 0;

    Key lKeyInvert;
    lKeyInvert.id = KEY_INVERT;
    lKeyInvert.state = 0;

    keys.push_back(lKeyPermission);
    keys.push_back(lKeyAuto);
    keys.push_back(lKeySaveAim);
    keys.push_back(lKeyBoltNotch);
    keys.push_back(lKeySensors);
    keys.push_back(lKeyFireType);
    keys.push_back(lKeyTypeBrush);
    keys.push_back(lKeyTracking);
    keys.push_back(lKeyAimMode);
    keys.push_back(lKeyStabilization);
    keys.push_back(lKeyInvert);

    for (unsigned int i = 0; i < keys.size(); ++i)
    {
        unsigned char writeBuffer[5] = {0};
        unsigned char readBuffer[5] = {0};
        writeBuffer[0] = 0x55;
        writeBuffer[1] = 0x01;
        writeBuffer[2] = 0x00;
        writeBuffer[3] = keys[i].id;
        writeBuffer[4] = crc8(writeBuffer, 4);
        if (com.write(writeBuffer, 5) && com.read(readBuffer, 5)
                && readBuffer[0] == 0xaa && readBuffer[1] == 0x01
                && readBuffer[4] == crc8(readBuffer, 4))
        {
            keys[i].id = readBuffer[3];
            keys[i].state = readBuffer[2];
        }
    }
    return keys;
}

bool ControlDevice::switchLight(bool enable)
{
    unsigned char writeBuffer[5] = {0};
    unsigned char readBuffer[5] = {0};
    writeBuffer[0] = 0x55;
    writeBuffer[1] = 0x0A;
    writeBuffer[2] = 0x00;
    if (enable)
        writeBuffer[3] = 0x01;
    else
        writeBuffer[3] = 0x00;
    writeBuffer[4] = crc8(writeBuffer, 4);
    if (!com.write(writeBuffer, 5))
        return false;
    if (!com.read(readBuffer, 5))
        return false;
    if (readBuffer[0] == 0xAA && readBuffer[1] == 0xA && readBuffer[2] == 0x00)
    {
        if (enable && readBuffer[3] == 0x01 && readBuffer[4] == crc8(readBuffer, 4))
            return true;
        else if (readBuffer[3] == 0x00 && readBuffer[4] == crc8(readBuffer, 4))
            return true;
    }
    return true;
}

void ControlDevice::run()
{
    if (isInit)
    {
        while (!isClose)
        {
            usleep(150000);
            updateKeyPressed();
            clock_gettime(CLOCK_MONOTONIC, &time_n);
            double time = static_cast<double>(time_n.tv_sec - time_s.tv_sec)
                          + static_cast<double>(time_n.tv_nsec - time_s.tv_nsec)
                            / 1000000000.0;
            if (time > 5.0)
            {
                clock_gettime(CLOCK_MONOTONIC, &time_s);
                updateState();
            }
        }
    }
}

ControlDevice::ControlDevice()
{
    isClose = false;
    isInit = init();
    clock_gettime(CLOCK_MONOTONIC, &time_s);
}

void ControlDevice::updateKeyPressed()
{
    Key lKey;
    bool state = readKey(lKey);
    if (state)
    {
        mMutex.lock();
        if (keys.size() < 20)
            keys.push_front(lKey);
        mMutex.unlock();
    }
}

void ControlDevice::updateState()
{
    int lVoltageExternal = 0;
    getVoltage(lVoltageExternal);
    emit newVoltageBu(lVoltageExternal);
    //query voltag
    emit newQueryVoltage();
}

bool ControlDevice::readKey(Key &pKey)
{
    unsigned char readBuffer[5] = {0};
    if (!com.read(readBuffer, 5))
        return false;
    if (readBuffer[0] == 0xAA && readBuffer[1] == 0x01)
    {
        pKey.id = readBuffer[3];
        pKey.state = readBuffer[2];
        return true;
    }
    return false;
}
