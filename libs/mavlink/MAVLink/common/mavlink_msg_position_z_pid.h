// MESSAGE Position_Z_PID PACKING

#define MAVLINK_MSG_ID_Position_Z_PID 156

typedef struct __mavlink_position_z_pid_t
{
 float MPC_Z_P; /*< MPC_Z_P*/
 float MPC_ZRATE_P; /*< MPC_ZRATE_P*/
 float MPC_ZRATE_I; /*< MPC_ZRATE_I*/
 float MPC_ZRATE_D; /*< MPC_ZRATE_D*/
} mavlink_position_z_pid_t;

#define MAVLINK_MSG_ID_Position_Z_PID_LEN 16
#define MAVLINK_MSG_ID_156_LEN 16

#define MAVLINK_MSG_ID_Position_Z_PID_CRC 132
#define MAVLINK_MSG_ID_156_CRC 132



#define MAVLINK_MESSAGE_INFO_Position_Z_PID { \
	"Position_Z_PID", \
	4, \
	{  { "MPC_Z_P", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_position_z_pid_t, MPC_Z_P) }, \
         { "MPC_ZRATE_P", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_position_z_pid_t, MPC_ZRATE_P) }, \
         { "MPC_ZRATE_I", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_position_z_pid_t, MPC_ZRATE_I) }, \
         { "MPC_ZRATE_D", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_position_z_pid_t, MPC_ZRATE_D) }, \
         } \
}


/**
 * @brief Pack a position_z_pid message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param MPC_Z_P MPC_Z_P
 * @param MPC_ZRATE_P MPC_ZRATE_P
 * @param MPC_ZRATE_I MPC_ZRATE_I
 * @param MPC_ZRATE_D MPC_ZRATE_D
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_z_pid_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float MPC_Z_P, float MPC_ZRATE_P, float MPC_ZRATE_I, float MPC_ZRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Position_Z_PID_LEN];
	_mav_put_float(buf, 0, MPC_Z_P);
	_mav_put_float(buf, 4, MPC_ZRATE_P);
	_mav_put_float(buf, 8, MPC_ZRATE_I);
	_mav_put_float(buf, 12, MPC_ZRATE_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#else
	mavlink_position_z_pid_t packet;
	packet.MPC_Z_P = MPC_Z_P;
	packet.MPC_ZRATE_P = MPC_ZRATE_P;
	packet.MPC_ZRATE_I = MPC_ZRATE_I;
	packet.MPC_ZRATE_D = MPC_ZRATE_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Position_Z_PID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Position_Z_PID_LEN, MAVLINK_MSG_ID_Position_Z_PID_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#endif
}

/**
 * @brief Pack a position_z_pid message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param MPC_Z_P MPC_Z_P
 * @param MPC_ZRATE_P MPC_ZRATE_P
 * @param MPC_ZRATE_I MPC_ZRATE_I
 * @param MPC_ZRATE_D MPC_ZRATE_D
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_z_pid_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float MPC_Z_P,float MPC_ZRATE_P,float MPC_ZRATE_I,float MPC_ZRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Position_Z_PID_LEN];
	_mav_put_float(buf, 0, MPC_Z_P);
	_mav_put_float(buf, 4, MPC_ZRATE_P);
	_mav_put_float(buf, 8, MPC_ZRATE_I);
	_mav_put_float(buf, 12, MPC_ZRATE_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#else
	mavlink_position_z_pid_t packet;
	packet.MPC_Z_P = MPC_Z_P;
	packet.MPC_ZRATE_P = MPC_ZRATE_P;
	packet.MPC_ZRATE_I = MPC_ZRATE_I;
	packet.MPC_ZRATE_D = MPC_ZRATE_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Position_Z_PID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Position_Z_PID_LEN, MAVLINK_MSG_ID_Position_Z_PID_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#endif
}

/**
 * @brief Encode a position_z_pid struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param position_z_pid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_z_pid_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_position_z_pid_t* position_z_pid)
{
	return mavlink_msg_position_z_pid_pack(system_id, component_id, msg, position_z_pid->MPC_Z_P, position_z_pid->MPC_ZRATE_P, position_z_pid->MPC_ZRATE_I, position_z_pid->MPC_ZRATE_D);
}

/**
 * @brief Encode a position_z_pid struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param position_z_pid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_z_pid_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_position_z_pid_t* position_z_pid)
{
	return mavlink_msg_position_z_pid_pack_chan(system_id, component_id, chan, msg, position_z_pid->MPC_Z_P, position_z_pid->MPC_ZRATE_P, position_z_pid->MPC_ZRATE_I, position_z_pid->MPC_ZRATE_D);
}

/**
 * @brief Send a position_z_pid message
 * @param chan MAVLink channel to send the message
 *
 * @param MPC_Z_P MPC_Z_P
 * @param MPC_ZRATE_P MPC_ZRATE_P
 * @param MPC_ZRATE_I MPC_ZRATE_I
 * @param MPC_ZRATE_D MPC_ZRATE_D
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_position_z_pid_send(mavlink_channel_t chan, float MPC_Z_P, float MPC_ZRATE_P, float MPC_ZRATE_I, float MPC_ZRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Position_Z_PID_LEN];
	_mav_put_float(buf, 0, MPC_Z_P);
	_mav_put_float(buf, 4, MPC_ZRATE_P);
	_mav_put_float(buf, 8, MPC_ZRATE_I);
	_mav_put_float(buf, 12, MPC_ZRATE_D);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Z_PID, buf, MAVLINK_MSG_ID_Position_Z_PID_LEN, MAVLINK_MSG_ID_Position_Z_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Z_PID, buf, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#endif
#else
	mavlink_position_z_pid_t packet;
	packet.MPC_Z_P = MPC_Z_P;
	packet.MPC_ZRATE_P = MPC_ZRATE_P;
	packet.MPC_ZRATE_I = MPC_ZRATE_I;
	packet.MPC_ZRATE_D = MPC_ZRATE_D;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Z_PID, (const char *)&packet, MAVLINK_MSG_ID_Position_Z_PID_LEN, MAVLINK_MSG_ID_Position_Z_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Z_PID, (const char *)&packet, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_Position_Z_PID_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_position_z_pid_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float MPC_Z_P, float MPC_ZRATE_P, float MPC_ZRATE_I, float MPC_ZRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, MPC_Z_P);
	_mav_put_float(buf, 4, MPC_ZRATE_P);
	_mav_put_float(buf, 8, MPC_ZRATE_I);
	_mav_put_float(buf, 12, MPC_ZRATE_D);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Z_PID, buf, MAVLINK_MSG_ID_Position_Z_PID_LEN, MAVLINK_MSG_ID_Position_Z_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Z_PID, buf, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#endif
#else
	mavlink_position_z_pid_t *packet = (mavlink_position_z_pid_t *)msgbuf;
	packet->MPC_Z_P = MPC_Z_P;
	packet->MPC_ZRATE_P = MPC_ZRATE_P;
	packet->MPC_ZRATE_I = MPC_ZRATE_I;
	packet->MPC_ZRATE_D = MPC_ZRATE_D;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Z_PID, (const char *)packet, MAVLINK_MSG_ID_Position_Z_PID_LEN, MAVLINK_MSG_ID_Position_Z_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Z_PID, (const char *)packet, MAVLINK_MSG_ID_Position_Z_PID_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE Position_Z_PID UNPACKING


/**
 * @brief Get field MPC_Z_P from position_z_pid message
 *
 * @return MPC_Z_P
 */
static inline float mavlink_msg_position_z_pid_get_MPC_Z_P(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field MPC_ZRATE_P from position_z_pid message
 *
 * @return MPC_ZRATE_P
 */
static inline float mavlink_msg_position_z_pid_get_MPC_ZRATE_P(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field MPC_ZRATE_I from position_z_pid message
 *
 * @return MPC_ZRATE_I
 */
static inline float mavlink_msg_position_z_pid_get_MPC_ZRATE_I(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field MPC_ZRATE_D from position_z_pid message
 *
 * @return MPC_ZRATE_D
 */
static inline float mavlink_msg_position_z_pid_get_MPC_ZRATE_D(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a position_z_pid message into a struct
 *
 * @param msg The message to decode
 * @param position_z_pid C-struct to decode the message contents into
 */
static inline void mavlink_msg_position_z_pid_decode(const mavlink_message_t* msg, mavlink_position_z_pid_t* position_z_pid)
{
#if MAVLINK_NEED_BYTE_SWAP
	position_z_pid->MPC_Z_P = mavlink_msg_position_z_pid_get_MPC_Z_P(msg);
	position_z_pid->MPC_ZRATE_P = mavlink_msg_position_z_pid_get_MPC_ZRATE_P(msg);
	position_z_pid->MPC_ZRATE_I = mavlink_msg_position_z_pid_get_MPC_ZRATE_I(msg);
	position_z_pid->MPC_ZRATE_D = mavlink_msg_position_z_pid_get_MPC_ZRATE_D(msg);
#else
	memcpy(position_z_pid, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_Position_Z_PID_LEN);
#endif
}
