// MESSAGE Attitude_YAW_PID PACKING

#define MAVLINK_MSG_ID_Attitude_YAW_PID 153

typedef struct __mavlink_attitude_yaw_pid_t
{
 float MC_YAW_P; /*< YAW P gain*/
 float MC_YAWRATE_P; /*< YAW rate P gain*/
 float MC_YAWRATE_I; /*< YAW rate I gain*/
 float MC_YAWRATE_D; /*< YAW rate D gain*/
} mavlink_attitude_yaw_pid_t;

#define MAVLINK_MSG_ID_Attitude_YAW_PID_LEN 16
#define MAVLINK_MSG_ID_153_LEN 16

#define MAVLINK_MSG_ID_Attitude_YAW_PID_CRC 25
#define MAVLINK_MSG_ID_153_CRC 25



#define MAVLINK_MESSAGE_INFO_Attitude_YAW_PID { \
	"Attitude_YAW_PID", \
	4, \
	{  { "MC_YAW_P", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_attitude_yaw_pid_t, MC_YAW_P) }, \
         { "MC_YAWRATE_P", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_attitude_yaw_pid_t, MC_YAWRATE_P) }, \
         { "MC_YAWRATE_I", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_attitude_yaw_pid_t, MC_YAWRATE_I) }, \
         { "MC_YAWRATE_D", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_attitude_yaw_pid_t, MC_YAWRATE_D) }, \
         } \
}


/**
 * @brief Pack a attitude_yaw_pid message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param MC_YAW_P YAW P gain
 * @param MC_YAWRATE_P YAW rate P gain
 * @param MC_YAWRATE_I YAW rate I gain
 * @param MC_YAWRATE_D YAW rate D gain
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_yaw_pid_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float MC_YAW_P, float MC_YAWRATE_P, float MC_YAWRATE_I, float MC_YAWRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Attitude_YAW_PID_LEN];
	_mav_put_float(buf, 0, MC_YAW_P);
	_mav_put_float(buf, 4, MC_YAWRATE_P);
	_mav_put_float(buf, 8, MC_YAWRATE_I);
	_mav_put_float(buf, 12, MC_YAWRATE_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#else
	mavlink_attitude_yaw_pid_t packet;
	packet.MC_YAW_P = MC_YAW_P;
	packet.MC_YAWRATE_P = MC_YAWRATE_P;
	packet.MC_YAWRATE_I = MC_YAWRATE_I;
	packet.MC_YAWRATE_D = MC_YAWRATE_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Attitude_YAW_PID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN, MAVLINK_MSG_ID_Attitude_YAW_PID_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#endif
}

/**
 * @brief Pack a attitude_yaw_pid message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param MC_YAW_P YAW P gain
 * @param MC_YAWRATE_P YAW rate P gain
 * @param MC_YAWRATE_I YAW rate I gain
 * @param MC_YAWRATE_D YAW rate D gain
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_yaw_pid_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float MC_YAW_P,float MC_YAWRATE_P,float MC_YAWRATE_I,float MC_YAWRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Attitude_YAW_PID_LEN];
	_mav_put_float(buf, 0, MC_YAW_P);
	_mav_put_float(buf, 4, MC_YAWRATE_P);
	_mav_put_float(buf, 8, MC_YAWRATE_I);
	_mav_put_float(buf, 12, MC_YAWRATE_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#else
	mavlink_attitude_yaw_pid_t packet;
	packet.MC_YAW_P = MC_YAW_P;
	packet.MC_YAWRATE_P = MC_YAWRATE_P;
	packet.MC_YAWRATE_I = MC_YAWRATE_I;
	packet.MC_YAWRATE_D = MC_YAWRATE_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Attitude_YAW_PID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN, MAVLINK_MSG_ID_Attitude_YAW_PID_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#endif
}

/**
 * @brief Encode a attitude_yaw_pid struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param attitude_yaw_pid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_yaw_pid_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_attitude_yaw_pid_t* attitude_yaw_pid)
{
	return mavlink_msg_attitude_yaw_pid_pack(system_id, component_id, msg, attitude_yaw_pid->MC_YAW_P, attitude_yaw_pid->MC_YAWRATE_P, attitude_yaw_pid->MC_YAWRATE_I, attitude_yaw_pid->MC_YAWRATE_D);
}

/**
 * @brief Encode a attitude_yaw_pid struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param attitude_yaw_pid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_yaw_pid_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_attitude_yaw_pid_t* attitude_yaw_pid)
{
	return mavlink_msg_attitude_yaw_pid_pack_chan(system_id, component_id, chan, msg, attitude_yaw_pid->MC_YAW_P, attitude_yaw_pid->MC_YAWRATE_P, attitude_yaw_pid->MC_YAWRATE_I, attitude_yaw_pid->MC_YAWRATE_D);
}

/**
 * @brief Send a attitude_yaw_pid message
 * @param chan MAVLink channel to send the message
 *
 * @param MC_YAW_P YAW P gain
 * @param MC_YAWRATE_P YAW rate P gain
 * @param MC_YAWRATE_I YAW rate I gain
 * @param MC_YAWRATE_D YAW rate D gain
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_attitude_yaw_pid_send(mavlink_channel_t chan, float MC_YAW_P, float MC_YAWRATE_P, float MC_YAWRATE_I, float MC_YAWRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Attitude_YAW_PID_LEN];
	_mav_put_float(buf, 0, MC_YAW_P);
	_mav_put_float(buf, 4, MC_YAWRATE_P);
	_mav_put_float(buf, 8, MC_YAWRATE_I);
	_mav_put_float(buf, 12, MC_YAWRATE_D);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_YAW_PID, buf, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN, MAVLINK_MSG_ID_Attitude_YAW_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_YAW_PID, buf, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#endif
#else
	mavlink_attitude_yaw_pid_t packet;
	packet.MC_YAW_P = MC_YAW_P;
	packet.MC_YAWRATE_P = MC_YAWRATE_P;
	packet.MC_YAWRATE_I = MC_YAWRATE_I;
	packet.MC_YAWRATE_D = MC_YAWRATE_D;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_YAW_PID, (const char *)&packet, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN, MAVLINK_MSG_ID_Attitude_YAW_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_YAW_PID, (const char *)&packet, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_Attitude_YAW_PID_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_attitude_yaw_pid_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float MC_YAW_P, float MC_YAWRATE_P, float MC_YAWRATE_I, float MC_YAWRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, MC_YAW_P);
	_mav_put_float(buf, 4, MC_YAWRATE_P);
	_mav_put_float(buf, 8, MC_YAWRATE_I);
	_mav_put_float(buf, 12, MC_YAWRATE_D);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_YAW_PID, buf, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN, MAVLINK_MSG_ID_Attitude_YAW_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_YAW_PID, buf, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#endif
#else
	mavlink_attitude_yaw_pid_t *packet = (mavlink_attitude_yaw_pid_t *)msgbuf;
	packet->MC_YAW_P = MC_YAW_P;
	packet->MC_YAWRATE_P = MC_YAWRATE_P;
	packet->MC_YAWRATE_I = MC_YAWRATE_I;
	packet->MC_YAWRATE_D = MC_YAWRATE_D;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_YAW_PID, (const char *)packet, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN, MAVLINK_MSG_ID_Attitude_YAW_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_YAW_PID, (const char *)packet, MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE Attitude_YAW_PID UNPACKING


/**
 * @brief Get field MC_YAW_P from attitude_yaw_pid message
 *
 * @return YAW P gain
 */
static inline float mavlink_msg_attitude_yaw_pid_get_MC_YAW_P(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field MC_YAWRATE_P from attitude_yaw_pid message
 *
 * @return YAW rate P gain
 */
static inline float mavlink_msg_attitude_yaw_pid_get_MC_YAWRATE_P(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field MC_YAWRATE_I from attitude_yaw_pid message
 *
 * @return YAW rate I gain
 */
static inline float mavlink_msg_attitude_yaw_pid_get_MC_YAWRATE_I(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field MC_YAWRATE_D from attitude_yaw_pid message
 *
 * @return YAW rate D gain
 */
static inline float mavlink_msg_attitude_yaw_pid_get_MC_YAWRATE_D(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a attitude_yaw_pid message into a struct
 *
 * @param msg The message to decode
 * @param attitude_yaw_pid C-struct to decode the message contents into
 */
static inline void mavlink_msg_attitude_yaw_pid_decode(const mavlink_message_t* msg, mavlink_attitude_yaw_pid_t* attitude_yaw_pid)
{
#if MAVLINK_NEED_BYTE_SWAP
	attitude_yaw_pid->MC_YAW_P = mavlink_msg_attitude_yaw_pid_get_MC_YAW_P(msg);
	attitude_yaw_pid->MC_YAWRATE_P = mavlink_msg_attitude_yaw_pid_get_MC_YAWRATE_P(msg);
	attitude_yaw_pid->MC_YAWRATE_I = mavlink_msg_attitude_yaw_pid_get_MC_YAWRATE_I(msg);
	attitude_yaw_pid->MC_YAWRATE_D = mavlink_msg_attitude_yaw_pid_get_MC_YAWRATE_D(msg);
#else
	memcpy(attitude_yaw_pid, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_Attitude_YAW_PID_LEN);
#endif
}
