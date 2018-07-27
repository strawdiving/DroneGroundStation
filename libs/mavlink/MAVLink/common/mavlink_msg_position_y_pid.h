// MESSAGE Position_Y_PID PACKING

#define MAVLINK_MSG_ID_Position_Y_PID 155

typedef struct __mavlink_position_y_pid_t
{
 float MPC_Y_P; /*< MPC_Y_P*/
 float MPC_YRATE_P; /*< MPC_YRATE_P*/
 float MPC_YRATE_I; /*< MPC_YRATE_I*/
 float MPC_YRATE_D; /*< MPC_YRATE_D*/
} mavlink_position_y_pid_t;

#define MAVLINK_MSG_ID_Position_Y_PID_LEN 16
#define MAVLINK_MSG_ID_155_LEN 16

#define MAVLINK_MSG_ID_Position_Y_PID_CRC 89
#define MAVLINK_MSG_ID_155_CRC 89



#define MAVLINK_MESSAGE_INFO_Position_Y_PID { \
	"Position_Y_PID", \
	4, \
	{  { "MPC_Y_P", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_position_y_pid_t, MPC_Y_P) }, \
         { "MPC_YRATE_P", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_position_y_pid_t, MPC_YRATE_P) }, \
         { "MPC_YRATE_I", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_position_y_pid_t, MPC_YRATE_I) }, \
         { "MPC_YRATE_D", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_position_y_pid_t, MPC_YRATE_D) }, \
         } \
}


/**
 * @brief Pack a position_y_pid message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param MPC_Y_P MPC_Y_P
 * @param MPC_YRATE_P MPC_YRATE_P
 * @param MPC_YRATE_I MPC_YRATE_I
 * @param MPC_YRATE_D MPC_YRATE_D
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_y_pid_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float MPC_Y_P, float MPC_YRATE_P, float MPC_YRATE_I, float MPC_YRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Position_Y_PID_LEN];
	_mav_put_float(buf, 0, MPC_Y_P);
	_mav_put_float(buf, 4, MPC_YRATE_P);
	_mav_put_float(buf, 8, MPC_YRATE_I);
	_mav_put_float(buf, 12, MPC_YRATE_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#else
	mavlink_position_y_pid_t packet;
	packet.MPC_Y_P = MPC_Y_P;
	packet.MPC_YRATE_P = MPC_YRATE_P;
	packet.MPC_YRATE_I = MPC_YRATE_I;
	packet.MPC_YRATE_D = MPC_YRATE_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Position_Y_PID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Position_Y_PID_LEN, MAVLINK_MSG_ID_Position_Y_PID_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#endif
}

/**
 * @brief Pack a position_y_pid message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param MPC_Y_P MPC_Y_P
 * @param MPC_YRATE_P MPC_YRATE_P
 * @param MPC_YRATE_I MPC_YRATE_I
 * @param MPC_YRATE_D MPC_YRATE_D
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_y_pid_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float MPC_Y_P,float MPC_YRATE_P,float MPC_YRATE_I,float MPC_YRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Position_Y_PID_LEN];
	_mav_put_float(buf, 0, MPC_Y_P);
	_mav_put_float(buf, 4, MPC_YRATE_P);
	_mav_put_float(buf, 8, MPC_YRATE_I);
	_mav_put_float(buf, 12, MPC_YRATE_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#else
	mavlink_position_y_pid_t packet;
	packet.MPC_Y_P = MPC_Y_P;
	packet.MPC_YRATE_P = MPC_YRATE_P;
	packet.MPC_YRATE_I = MPC_YRATE_I;
	packet.MPC_YRATE_D = MPC_YRATE_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Position_Y_PID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Position_Y_PID_LEN, MAVLINK_MSG_ID_Position_Y_PID_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#endif
}

/**
 * @brief Encode a position_y_pid struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param position_y_pid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_y_pid_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_position_y_pid_t* position_y_pid)
{
	return mavlink_msg_position_y_pid_pack(system_id, component_id, msg, position_y_pid->MPC_Y_P, position_y_pid->MPC_YRATE_P, position_y_pid->MPC_YRATE_I, position_y_pid->MPC_YRATE_D);
}

/**
 * @brief Encode a position_y_pid struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param position_y_pid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_y_pid_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_position_y_pid_t* position_y_pid)
{
	return mavlink_msg_position_y_pid_pack_chan(system_id, component_id, chan, msg, position_y_pid->MPC_Y_P, position_y_pid->MPC_YRATE_P, position_y_pid->MPC_YRATE_I, position_y_pid->MPC_YRATE_D);
}

/**
 * @brief Send a position_y_pid message
 * @param chan MAVLink channel to send the message
 *
 * @param MPC_Y_P MPC_Y_P
 * @param MPC_YRATE_P MPC_YRATE_P
 * @param MPC_YRATE_I MPC_YRATE_I
 * @param MPC_YRATE_D MPC_YRATE_D
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_position_y_pid_send(mavlink_channel_t chan, float MPC_Y_P, float MPC_YRATE_P, float MPC_YRATE_I, float MPC_YRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Position_Y_PID_LEN];
	_mav_put_float(buf, 0, MPC_Y_P);
	_mav_put_float(buf, 4, MPC_YRATE_P);
	_mav_put_float(buf, 8, MPC_YRATE_I);
	_mav_put_float(buf, 12, MPC_YRATE_D);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Y_PID, buf, MAVLINK_MSG_ID_Position_Y_PID_LEN, MAVLINK_MSG_ID_Position_Y_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Y_PID, buf, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#endif
#else
	mavlink_position_y_pid_t packet;
	packet.MPC_Y_P = MPC_Y_P;
	packet.MPC_YRATE_P = MPC_YRATE_P;
	packet.MPC_YRATE_I = MPC_YRATE_I;
	packet.MPC_YRATE_D = MPC_YRATE_D;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Y_PID, (const char *)&packet, MAVLINK_MSG_ID_Position_Y_PID_LEN, MAVLINK_MSG_ID_Position_Y_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Y_PID, (const char *)&packet, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_Position_Y_PID_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_position_y_pid_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float MPC_Y_P, float MPC_YRATE_P, float MPC_YRATE_I, float MPC_YRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, MPC_Y_P);
	_mav_put_float(buf, 4, MPC_YRATE_P);
	_mav_put_float(buf, 8, MPC_YRATE_I);
	_mav_put_float(buf, 12, MPC_YRATE_D);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Y_PID, buf, MAVLINK_MSG_ID_Position_Y_PID_LEN, MAVLINK_MSG_ID_Position_Y_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Y_PID, buf, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#endif
#else
	mavlink_position_y_pid_t *packet = (mavlink_position_y_pid_t *)msgbuf;
	packet->MPC_Y_P = MPC_Y_P;
	packet->MPC_YRATE_P = MPC_YRATE_P;
	packet->MPC_YRATE_I = MPC_YRATE_I;
	packet->MPC_YRATE_D = MPC_YRATE_D;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Y_PID, (const char *)packet, MAVLINK_MSG_ID_Position_Y_PID_LEN, MAVLINK_MSG_ID_Position_Y_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Position_Y_PID, (const char *)packet, MAVLINK_MSG_ID_Position_Y_PID_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE Position_Y_PID UNPACKING


/**
 * @brief Get field MPC_Y_P from position_y_pid message
 *
 * @return MPC_Y_P
 */
static inline float mavlink_msg_position_y_pid_get_MPC_Y_P(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field MPC_YRATE_P from position_y_pid message
 *
 * @return MPC_YRATE_P
 */
static inline float mavlink_msg_position_y_pid_get_MPC_YRATE_P(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field MPC_YRATE_I from position_y_pid message
 *
 * @return MPC_YRATE_I
 */
static inline float mavlink_msg_position_y_pid_get_MPC_YRATE_I(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field MPC_YRATE_D from position_y_pid message
 *
 * @return MPC_YRATE_D
 */
static inline float mavlink_msg_position_y_pid_get_MPC_YRATE_D(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a position_y_pid message into a struct
 *
 * @param msg The message to decode
 * @param position_y_pid C-struct to decode the message contents into
 */
static inline void mavlink_msg_position_y_pid_decode(const mavlink_message_t* msg, mavlink_position_y_pid_t* position_y_pid)
{
#if MAVLINK_NEED_BYTE_SWAP
	position_y_pid->MPC_Y_P = mavlink_msg_position_y_pid_get_MPC_Y_P(msg);
	position_y_pid->MPC_YRATE_P = mavlink_msg_position_y_pid_get_MPC_YRATE_P(msg);
	position_y_pid->MPC_YRATE_I = mavlink_msg_position_y_pid_get_MPC_YRATE_I(msg);
	position_y_pid->MPC_YRATE_D = mavlink_msg_position_y_pid_get_MPC_YRATE_D(msg);
#else
	memcpy(position_y_pid, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_Position_Y_PID_LEN);
#endif
}
