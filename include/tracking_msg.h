/*
#ifndef TRACKING_MSG_H_
#define TRACKING_MSG_H_
#include <cstring>
#include <vector>

#pragma pack(push, messpack, 1)

const unsigned short MI_DEVICE_ANSWER               =  1;
const unsigned short MI_OPEN_DEVICE                 =  2;
const unsigned short MI_SET_MOTOR_PARAMETER         =  3;
const unsigned short MI_SET_ENCODER_PARAMETER       =  4;
const unsigned short MI_DIGITAL_INPUT_CONFIGURATION =  5;
const unsigned short MI_SET_OBJECT                  =  6;
const unsigned short MI_SET_OPERATION_MODE          =  7;
const unsigned short MI_SET_HOMING_PARAMETER        =  8;
const unsigned short MI_FIND_HOME                   =  9;
const unsigned short MI_SET_ENABLE_STATE            = 10;
const unsigned short MI_SET_DISABLE_STATE           = 11;
const unsigned short MI_GET_FAULT_STATE             = 12;
const unsigned short MI_CLEAR_FAULT                 = 13;
const unsigned short MI_GET_ERROR_INFO              = 14;
const unsigned short MI_GET_POSITION_IS             = 15;
const unsigned short MI_HALT_VELOCITY_MOVEMENT      = 16;
const unsigned short MI_MOVE_WITH_VELOCITY          = 17;
const unsigned short MI_SET_VELOCITY_PROFILE        = 18;
const unsigned short MI_GET_OPERATION_MODE          = 19;
const unsigned short MI_MOVE_TO_POSITION            = 20;
const unsigned short MI_SET_POSITION_PROFILE        = 21;
const unsigned short MI_GET_MOVEMENT_STATE          = 22;
const unsigned short MI_GET_OBJECT                  = 23;
const unsigned short MI_CLOSE_DEVICE                = 24;
const unsigned short MI_SET_PROTOCOL_STACK_SETTINGS = 25;
const unsigned short MI_HALT_POSITION_MOVEMENT      = 25;
const unsigned short MI_FRAME                       = 26;
const unsigned short MI_META_FRAME                  = 27;
const unsigned short MI_GET_FRAME                   = 28;
const unsigned short MI_FILTER_PARAM                = 29;
const unsigned short MI_SELECTED_RECT               = 30;
const unsigned short MI_SET_CAMERA                  = 31;
const unsigned short MI_SET_FOG                     = 32;

struct MsgHdr	// Message header
{
    MsgHdr() {}
    MsgHdr(unsigned short _Type, unsigned int _Len)
        : m_Len(_Len), m_Type(_Type) {}
    // message length
    unsigned int m_Len;
    // The identifier of a communication center sent the message
    unsigned short m_From;
    // The identifier of a communication center accepted the message
    unsigned short m_To;
    // Type of the message
    unsigned short m_Type;
};

// Message container
template<class _Data, unsigned short _Type>
struct LanMessage : public MsgHdr
{
    LanMessage() : MsgHdr(_Type, sizeof(LanMessage<_Data, _Type>)) {}
    LanMessage(const _Data& d)
        : MsgHdr(_Type, sizeof(LanMessage<_Data, _Type>)), Data(d) {}
    _Data Data;
};

struct DEVICE_ANSWER
{	
    int m_HasError;
    unsigned long m_ErrorCode;
    unsigned short m_Type;
    long m_Data;
    unsigned long m_NbOfBytesWritten;
    unsigned long m_NbOfBytesread;
    int m_IsInFault;
    char m_ErrorInfo[100];
    long m_PositionIs;
    unsigned char m_Mode;
    int m_TargetReached;
};

struct OPEN_DEVICE
{
    OPEN_DEVICE() {}
    OPEN_DEVICE(const char* _DeviceName, const char* _ProtocolStackName,
                const char* _InterfaceName, const char* _URL)
    {
        memset(m_DeviceName, 0, sizeof(m_DeviceName));
        memcpy(m_DeviceName, _DeviceName, strlen(_DeviceName));

        memset(m_ProtocolStackName, 0, sizeof(m_ProtocolStackName));
        memcpy(m_ProtocolStackName, _ProtocolStackName, strlen(_ProtocolStackName));

        memset(m_InterfaceName, 0, sizeof(m_InterfaceName));
        memcpy(m_InterfaceName, _InterfaceName, strlen(_InterfaceName));

        memset(m_URL, 0, sizeof(m_URL));
        memcpy(m_URL, _URL, strlen(_URL));
    }

    char m_DeviceName[255];
    char m_ProtocolStackName[255];
    char m_InterfaceName[255];
    char m_URL[255];
};

struct SET_PROTOCOL_STACK_SETTINGS
{
    SET_PROTOCOL_STACK_SETTINGS() {}
    SET_PROTOCOL_STACK_SETTINGS(unsigned long _Baudrate, unsigned long _Timeout)
        : m_Baudrate(_Baudrate), m_Timeout(_Timeout) {}
    unsigned long m_Baudrate;
    unsigned long m_Timeout;
};

struct SET_MOTOR_PARAMETER
{
    SET_MOTOR_PARAMETER(){}
    SET_MOTOR_PARAMETER(unsigned short _NodeId, unsigned short _MotorType,
                        unsigned short _ContinuousCurrent,
                        unsigned short _PeakCurrent, unsigned char _PolePair,
                        unsigned short _ThermalTimeConstant)
        : m_NodeId(_NodeId), m_MotorType(_MotorType),
          m_ContinuousCurrent(_ContinuousCurrent), m_PeakCurrent(_PeakCurrent),
          m_PolePair(_PolePair), m_ThermalTimeConstant(_ThermalTimeConstant) {}
    unsigned short m_NodeId;
    unsigned short m_MotorType;
    unsigned short m_ContinuousCurrent;
    unsigned short m_PeakCurrent;
    unsigned char m_PolePair;
    unsigned short m_ThermalTimeConstant;
};

struct SET_ENCODER_PARAMETER
{
    SET_ENCODER_PARAMETER(){}
    SET_ENCODER_PARAMETER(unsigned short _NodeId, unsigned short _Counts,
                          unsigned short _SensorType)
        : m_NodeId(_NodeId), m_Counts(_Counts), m_SensorType(_SensorType) {}
    unsigned short m_NodeId;
    unsigned short m_Counts;
    unsigned short m_SensorType;
};

struct DIGITAL_INPUT_CONFIGURATION
{
    DIGITAL_INPUT_CONFIGURATION() {}
    DIGITAL_INPUT_CONFIGURATION(unsigned short _NodeId,
                                unsigned short _DigInputNb,
                                unsigned short _Configuration, int _Mask,
                                int _Polarity, int _ExecutionMask)
        : m_NodeId(_NodeId), m_DigInputNb(_DigInputNb),
          m_Configuration(_Configuration), m_Mask(_Mask),
          m_Polarity(_Polarity), m_ExecutionMask(_ExecutionMask) {}
    unsigned short m_NodeId;
    unsigned short m_DigInputNb;
    unsigned short m_Configuration;
    int m_Mask;
    int m_Polarity;
    int m_ExecutionMask;
};

struct SET_OBJECT
{
    SET_OBJECT() {}
    SET_OBJECT(unsigned short _NodeId, unsigned short _ObjectIndex,
               unsigned char _ObjectSubIndex, long _setData,
               unsigned long _NbOfBytesTowrite)
        : m_NodeId(_NodeId), m_ObjectIndex(_ObjectIndex),
          m_ObjectSubIndex(_ObjectSubIndex), m_setData(_setData),
          m_NbOfBytesTowrite(_NbOfBytesTowrite) {}
    unsigned short m_NodeId;
    unsigned short m_ObjectIndex;
    unsigned char m_ObjectSubIndex;
    long m_setData;
    unsigned long m_NbOfBytesTowrite;
};

struct SET_OPERATION_MODE
{
    SET_OPERATION_MODE() {}
    SET_OPERATION_MODE(unsigned short _NodeId, unsigned char _Mode)
        : m_NodeId(_NodeId), m_Mode(_Mode) {}
    unsigned short m_NodeId;
    unsigned char m_Mode;
};

struct SET_HOMING_PARAMETER
{
    SET_HOMING_PARAMETER() {}
    SET_HOMING_PARAMETER(unsigned short _NodeId,
                         unsigned long _HomingAcceleration,
                         unsigned long _SpeedSwitch, unsigned long _SpeedIndex,
                         long _HomeOffset, unsigned short _CurrentThreshold,
                         long _HomePosition)
        : m_NodeId(_NodeId), m_HomingAcceleration(_HomingAcceleration),
          m_SpeedSwitch(_SpeedSwitch), m_SpeedIndex(_SpeedIndex),
          m_HomeOffset(_HomeOffset), m_CurrentThreshold(_CurrentThreshold),
          m_HomePosition(_HomePosition) {}
    unsigned short m_NodeId;
    unsigned long m_HomingAcceleration;
    unsigned long m_SpeedSwitch;
    unsigned long m_SpeedIndex;
    long m_HomeOffset;
    unsigned short m_CurrentThreshold;
    long m_HomePosition;
};

struct FIND_HOME
{
    FIND_HOME() {}
    FIND_HOME(unsigned short _NodeId, unsigned char _HomingMethod)
        : m_NodeId(_NodeId), m_HomingMethod(_HomingMethod) {}
    unsigned short m_NodeId;
    unsigned char m_HomingMethod;
};

struct SET_ENABLE_STATE
{
    SET_ENABLE_STATE() {}
    SET_ENABLE_STATE(unsigned short _NodeId) : m_NodeId(_NodeId) {}
    unsigned short m_NodeId;
};

struct SET_DISABLE_STATE
{
    SET_DISABLE_STATE() {}
    SET_DISABLE_STATE(unsigned short _NodeId) : m_NodeId(_NodeId) {}
    unsigned short m_NodeId;
};

struct GET_FAULT_STATE
{
    GET_FAULT_STATE() {}
    GET_FAULT_STATE(unsigned short _NodeId) : m_NodeId(_NodeId) {}
    unsigned short m_NodeId;
};

struct CLEAR_FAULT
{
    CLEAR_FAULT() {}
    CLEAR_FAULT(unsigned short _NodeId) : m_NodeId(_NodeId) {}
    unsigned short m_NodeId;
};

struct GET_ERROR_INFO
{
    GET_ERROR_INFO() {}
    GET_ERROR_INFO(unsigned long _ErrorCodeValue)
        : m_ErrorCodeValue(_ErrorCodeValue) {}
    unsigned long m_ErrorCodeValue;
};

struct GET_POSITION_IS
{
    GET_POSITION_IS() {}
    GET_POSITION_IS(unsigned short _NodeId) : m_NodeId(_NodeId) {}
    unsigned short m_NodeId;
};

struct HALT_VELOCITY_MOVEMENT
{
    HALT_VELOCITY_MOVEMENT() {}
    HALT_VELOCITY_MOVEMENT(unsigned short _NodeId) : m_NodeId(_NodeId) {}
    unsigned short m_NodeId;
};

struct MOVE_WITH_VELOCITY
{
    MOVE_WITH_VELOCITY() {}
    MOVE_WITH_VELOCITY(unsigned short _NodeId, long _TargetVelocity)
        : m_NodeId(_NodeId), m_TargetVelocity(_TargetVelocity) {}
    unsigned short m_NodeId;
    long m_TargetVelocity;
};

struct SET_VELOCITY_PROFILE
{
    SET_VELOCITY_PROFILE() {}
    SET_VELOCITY_PROFILE(unsigned short _NodeId,
                         unsigned long _ProfileAcceleration,
                         unsigned long _ProfileDeceleration)
        : m_NodeId(_NodeId), m_ProfileAcceleration(_ProfileAcceleration),
          m_ProfileDeceleration(_ProfileDeceleration) {}
    unsigned short m_NodeId;
    unsigned long m_ProfileAcceleration;
    unsigned long m_ProfileDeceleration;
};

struct GET_OPERATION_MODE
{
    GET_OPERATION_MODE() {}
    GET_OPERATION_MODE(unsigned short _NodeId) : m_NodeId(_NodeId) {}
    unsigned short m_NodeId;
};

struct MOVE_TO_POSITION
{
    MOVE_TO_POSITION() {}
    MOVE_TO_POSITION(unsigned short _NodeId, long _TargetPosition,
                     int _Absolute, int _Immediately)
        : m_NodeId(_NodeId), m_TargetPosition(_TargetPosition),
          m_Absolute(_Absolute), m_Immediately(_Immediately) {}
    unsigned short m_NodeId;
    long m_TargetPosition;
    int m_Absolute;
    int m_Immediately;
};

struct SET_POSITION_PROFILE
{
    SET_POSITION_PROFILE() {}
    SET_POSITION_PROFILE(unsigned short _NodeId, unsigned long _ProfileVelocity,
                         unsigned long _ProfileAcceleration,
                         unsigned long _ProfileDeceleration)
        : m_NodeId(_NodeId), m_ProfileVelocity(_ProfileVelocity),
          m_ProfileAcceleration(_ProfileAcceleration),
          m_ProfileDeceleration(_ProfileDeceleration) {}
    unsigned short m_NodeId;
    unsigned long m_ProfileVelocity;
    unsigned long m_ProfileAcceleration;
    unsigned long m_ProfileDeceleration;
};

struct GET_MOVEMENT_STATE
{
    GET_MOVEMENT_STATE() {}
    GET_MOVEMENT_STATE(unsigned short _NodeId, int _TargetReached)
        : m_NodeId(_NodeId), m_TargetReached(_TargetReached) {}
    unsigned short m_NodeId;
    int m_TargetReached;
};

struct GET_OBJECT
{
    GET_OBJECT() {}
    GET_OBJECT(unsigned short _NodeId, unsigned short _ObjectIndex,
               unsigned char _ObjectSubIndex, long _getData,
               unsigned long _NbOfBytesToread)
        : m_NodeId(_NodeId), m_ObjectIndex(_ObjectIndex),
          m_ObjectSubIndex(_ObjectSubIndex), m_getData(_getData),
          m_NbOfBytesToread(_NbOfBytesToread) {}
    unsigned short m_NodeId;
    unsigned short m_ObjectIndex;
    unsigned char m_ObjectSubIndex;
    long m_getData;
    unsigned long m_NbOfBytesToread;
};

struct CLOSE_DEVICE {};

struct HALT_POSITION_MOVEMENT
{
    HALT_POSITION_MOVEMENT() {}
    HALT_POSITION_MOVEMENT(unsigned short _NodeId) : m_NodeId(_NodeId) {}
    unsigned short m_NodeId;
};

struct FRAME
{
    int  m_Channels;
    int  m_Width;
    int  m_Height;
    int  m_Depth;
    int  m_ImageSize;
        //char m_Data[1216512];
};

struct FRAME_META_DATA
{
    struct TARGET
    {
        unsigned char  m_TargetNumber;
        unsigned short m_CenterOfMass[2];
        unsigned short m_Rect[4];
        float m_xVelocity;
        float m_yVelocity;
    };

    typedef std::vector<TARGET> targets_container;
    targets_container m_Targets;
};

struct FRAME_WITH_META_DATA
{
    FRAME_META_DATA	m_MetaData;
    FRAME m_Frame;
};

struct GET_FRAME {};

struct FILTER_PARAM
{
    char* m_pPayload;
};
struct Point
{
    int m_X;
    int m_Y;
};
struct SELECTED_RECT
{
    Point m_Begin;
    Point m_End;
};
struct SET_CAMERA
{
    int m_CameraId;
};
struct SET_FOG
{
    int m_FogState;
};

typedef LanMessage<DEVICE_ANSWER, MI_DEVICE_ANSWER>                             MSG_DEVICE_ANSWER;
typedef LanMessage<OPEN_DEVICE, MI_OPEN_DEVICE>                                 MSG_OPEN_DEVICE;
typedef LanMessage<SET_MOTOR_PARAMETER, MI_SET_MOTOR_PARAMETER>                 MSG_SET_MOTOR_PARAMETER;
typedef LanMessage<SET_ENCODER_PARAMETER, MI_SET_ENCODER_PARAMETER>             MSG_SET_ENCODER_PARAMETER;
typedef LanMessage<DIGITAL_INPUT_CONFIGURATION, MI_DIGITAL_INPUT_CONFIGURATION> MSG_DIGITAL_INPUT_CONFIGURATION;
typedef LanMessage<SET_OBJECT, MI_SET_OBJECT>                                   MSG_SET_OBJECT;
typedef LanMessage<SET_OPERATION_MODE, MI_SET_OPERATION_MODE>                   MSG_SET_OPERATION_MODE;
typedef LanMessage<SET_HOMING_PARAMETER, MI_SET_HOMING_PARAMETER>               MSG_SET_HOMING_PARAMETER;
typedef LanMessage<FIND_HOME, MI_FIND_HOME>                                     MSG_FIND_HOME;
typedef LanMessage<SET_ENABLE_STATE, MI_SET_ENABLE_STATE>                       MSG_SET_ENABLE_STATE;
typedef LanMessage<SET_DISABLE_STATE, MI_SET_DISABLE_STATE>                     MSG_SET_DISABLE_STATE;
typedef LanMessage<GET_FAULT_STATE, MI_GET_FAULT_STATE>                         MSG_GET_FAULT_STATE;
typedef LanMessage<CLEAR_FAULT, MI_CLEAR_FAULT>                                 MSG_CLEAR_FAULT;
typedef LanMessage<GET_ERROR_INFO, MI_GET_ERROR_INFO>                           MSG_GET_ERROR_INFO;
typedef LanMessage<GET_POSITION_IS, MI_GET_POSITION_IS>                         MSG_GET_POSITION_IS;
typedef LanMessage<HALT_VELOCITY_MOVEMENT, MI_HALT_VELOCITY_MOVEMENT>           MSG_HALT_VELOCITY_MOVEMENT;
typedef LanMessage<MOVE_WITH_VELOCITY, MI_MOVE_WITH_VELOCITY>                   MSG_MOVE_WITH_VELOCITY;
typedef LanMessage<SET_VELOCITY_PROFILE, MI_SET_VELOCITY_PROFILE>               MSG_SET_VELOCITY_PROFILE;
typedef LanMessage<GET_OPERATION_MODE, MI_GET_OPERATION_MODE>                   MSG_GET_OPERATION_MODE;
typedef LanMessage<MOVE_TO_POSITION, MI_MOVE_TO_POSITION>                       MSG_MOVE_TO_POSITION;
typedef LanMessage<SET_POSITION_PROFILE, MI_SET_POSITION_PROFILE>               MSG_SET_POSITION_PROFILE;
typedef LanMessage<GET_MOVEMENT_STATE, MI_GET_MOVEMENT_STATE>                   MSG_GET_MOVEMENT_STATE;
typedef LanMessage<GET_OBJECT, MI_GET_OBJECT>                                   MSG_GET_OBJECT;
typedef LanMessage<CLOSE_DEVICE, MI_CLOSE_DEVICE>                               MSG_CLOSE_DEVICE;
typedef LanMessage<SET_PROTOCOL_STACK_SETTINGS, MI_SET_PROTOCOL_STACK_SETTINGS>	MSG_SET_PROTOCOL_STACK_SETTINGS;
typedef LanMessage<HALT_POSITION_MOVEMENT, MI_HALT_POSITION_MOVEMENT>           MSG_HALT_POSITION_MOVEMENT;
typedef LanMessage<FRAME, MI_FRAME>                                             MSG_FRAME;
typedef LanMessage<FRAME_WITH_META_DATA, MI_META_FRAME>                         MSG_META_FRAME;
typedef LanMessage<GET_FRAME, MI_GET_FRAME>                                     MSG_GET_FRAME;
typedef LanMessage<FILTER_PARAM, MI_FILTER_PARAM>                             	MSG_FILTER_PARAM;
typedef LanMessage<SELECTED_RECT, MI_SELECTED_RECT>                             MSG_SELECTED_RECT;
typedef LanMessage<SET_CAMERA, MI_SET_CAMERA>                                   MSG_SET_CAMERA;
typedef LanMessage<SET_FOG, MI_SET_FOG>                                         MSG_SET_FOG;

#pragma pack(pop, messpack)

#endif /*AD_TRACKING_MSG_H_*/
