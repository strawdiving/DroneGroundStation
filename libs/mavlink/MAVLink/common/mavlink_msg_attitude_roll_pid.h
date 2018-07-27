// MESSAGE Attitude_ROLL_PID PACKING

#define MAVLINK_MSG_ID_Attitude_ROLL_PID 152

typedef struct __mavlink_attitude_roll_pid_t
{
 float MC_ROLL_P; /*< Roll P gain*/
 float MC_ROLLRATE_P; /*< Roll rate P gain*/
 float MC_ROLLRATE_I; /*< Roll rate I gain*/
 float MC_ROLLRATE_D; /*< Roll rate D gain*/
} mavlink_attitude_roll_pid_t;

#define MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN 16
#define MAVLINK_MSG_ID_152_LEN 16

#define MAVLINK_MSG_ID_Attitude_ROLL_PID_CRC 139
#define MAVLINK_MSG_ID_152_CRC 139



#define MAVLINK_MESSAGE_INFO_Attitude_ROLL_PID { \
	"Attitude_ROLL_PID", \
	4, \
	{  { "MC_ROLL_P", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_attitude_roll_pid_t, MC_ROLL_P) }, \
         { "MC_ROLLRATE_P", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_attitude_roll_pid_t, MC_ROLLRATE_P) }, \
         { "MC_ROLLRATE_I", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_attitude_roll_pid_t, MC_ROLLRATE_I) }, \
         { "MC_ROLLRATE_D", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_attitude_roll_pid_t, MC_ROLLRATE_D) }, \
         } \
}


/**
 * @brief Pack a attitude_roll_pid message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param MC_ROLL_P Roll P gain
 * @param MC_ROLLRATE_P Roll rate P gain
 * @param MC_ROLLRATE_I Roll rate I gain
 * @param MC_ROLLRATE_D Roll rate D gain
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_roll_pid_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float MC_ROLL_P, float MC_ROLLRATE_P, float MC_ROLLRATE_I, float MC_ROLLRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN];
	_mav_put_float(buf, 0, MC_ROLL_P);
	_mav_put_float(buf, 4, MC_ROLLRATE_P);
	_mav_put_float(buf, 8, MC_ROLLRATE_I);
	_mav_put_float(buf, 12, MC_ROLLRATE_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#else
	mavlink_attitude_roll_pid_t packet;
	packet.MC_ROLL_P = MC_ROLL_P;
	packet.MC_ROLLRATE_P = MC_ROLLRATE_P;
	packet.MC_ROLLRATE_I = MC_ROLLRATE_I;
	packet.MC_ROLLRATE_D = MC_ROLLRATE_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Attitude_ROLL_PID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN, MAVLINK_MSG_ID_Attitude_ROLL_PID_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#endif
}

/**
 * @brief Pack a attitude_roll_pid message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param MC_ROLL_P Roll P gain
 * @param MC_ROLLRATE_P Roll rate P gain
 * @param MC_ROLLRATE_I Roll rate I gain
 * @param MC_ROLLRATE_D Roll rate D gain
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_attitude_roll_pid_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float MC_ROLL_P,float MC_ROLLRATE_P,float MC_ROLLRATE_I,float MC_ROLLRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN];
	_mav_put_float(buf, 0, MC_ROLL_P);
	_mav_put_float(buf, 4, MC_ROLLRATE_P);
	_mav_put_float(buf, 8, MC_ROLLRATE_I);
	_mav_put_float(buf, 12, MC_ROLLRATE_D);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#else
	mavlink_attitude_roll_pid_t packet;
	packet.MC_ROLL_P = MC_ROLL_P;
	packet.MC_ROLLRATE_P = MC_ROLLRATE_P;
	packet.MC_ROLLRATE_I = MC_ROLLRATE_I;
	packet.MC_ROLLRATE_D = MC_ROLLRATE_D;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Attitude_ROLL_PID;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN, MAVLINK_MSG_ID_Attitude_ROLL_PID_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#endif
}

/**
 * @brief Encode a attitude_roll_pid struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param attitude_roll_pid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_roll_pid_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_attitude_roll_pid_t* attitude_roll_pid)
{
	return mavlink_msg_attitude_roll_pid_pack(system_id, component_id, msg, attitude_roll_pid->MC_ROLL_P, attitude_roll_pid->MC_ROLLRATE_P, attitude_roll_pid->MC_ROLLRATE_I, attitude_roll_pid->MC_ROLLRATE_D);
}

/**
 * @brief Encode a attitude_roll_pid struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param attitude_roll_pid C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_attitude_roll_pid_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_attitude_roll_pid_t* attitude_roll_pid)
{
	return mavlink_msg_attitude_roll_pid_pack_chan(system_id, component_id, chan, msg, attitude_roll_pid->MC_ROLL_P, attitude_roll_pid->MC_ROLLRATE_P, attitude_roll_pid->MC_ROLLRATE_I, attitude_roll_pid->MC_ROLLRATE_D);
}

/**
 * @brief Send a attitude_roll_pid message
 * @param chan MAVLink channel to send the message
 *
 * @param MC_ROLL_P Roll P gain
 * @param MC_ROLLRATE_P Roll rate P gain
 * @param MC_ROLLRATE_I Roll rate I gain
 * @param MC_ROLLRATE_D Roll rate D gain
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_attitude_roll_pid_send(mavlink_channel_t chan, float MC_ROLL_P, float MC_ROLLRATE_P, float MC_ROLLRATE_I, float MC_ROLLRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN];
	_mav_put_float(buf, 0, MC_ROLL_P);
	_mav_put_float(buf, 4, MC_ROLLRATE_P);
	_mav_put_float(buf, 8, MC_ROLLRATE_I);
	_mav_put_float(buf, 12, MC_ROLLRATE_D);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_ROLL_PID, buf, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN, MAVLINK_MSG_ID_Attitude_ROLL_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_ROLL_PID, buf, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#endif
#else
	mavlink_attitude_roll_pid_t packet;
	packet.MC_ROLL_P = MC_ROLL_P;
	packet.MC_ROLLRATE_P = MC_ROLLRATE_P;
	packet.MC_ROLLRATE_I = MC_ROLLRATE_I;
	packet.MC_ROLLRATE_D = MC_ROLLRATE_D;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_ROLL_PID, (const char *)&packet, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN, MAVLINK_MSG_ID_Attitude_ROLL_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_ROLL_PID, (const char *)&packet, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_attitude_roll_pid_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float MC_ROLL_P, float MC_ROLLRATE_P, float MC_ROLLRATE_I, float MC_ROLLRATE_D)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, MC_ROLL_P);
	_mav_put_float(buf, 4, MC_ROLLRATE_P);
	_mav_put_float(buf, 8, MC_ROLLRATE_I);
	_mav_put_float(buf, 12, MC_ROLLRATE_D);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_ROLL_PID, buf, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN, MAVLINK_MSG_ID_Attitude_ROLL_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_ROLL_PID, buf, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#endif
#else
	mavlink_attitude_roll_pid_t *packet = (mavlink_attitude_roll_pid_t *)msgbuf;
	packet->MC_ROLL_P = MC_ROLL_P;
	packet->MC_ROLLRATE_P = MC_ROLLRATE_P;
	packet->MC_ROLLRATE_I = MC_ROLLRATE_I;
	packet->MC_ROLLRATE_D = MC_ROLLRATE_D;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_ROLL_PID, (const char *)packet, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN, MAVLINK_MSG_ID_Attitude_ROLL_PID_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Attitude_ROLL_PID, (const char *)packet, MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE Attitude_ROLL_PID UNPACKING


/**
 * @brief Get field MC_ROLL_P from attitude_roll_pid message
 *
 * @return Roll P gain
 */
static inline float mavlink_msg_attitude_roll_pid_get_MC_ROLL_P(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field MC_ROLLRATE_P from attitude_roll_pid message
 *
 * @return Roll rate P gain
 */
static inline float mavlink_msg_attitude_roll_pid_get_MC_ROLLRATE_P(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field MC_ROLLRATE_I from attitude_roll_pid message
 *
 * @return Roll rate I gain
 */
static inline float mavlink_msg_attitude_roll_pid_get_MC_ROLLRATE_I(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field MC_ROLLRATE_D from attitude_roll_pid message
 *
 * @return Roll rate D gain
 */
static inline float mavlink_msg_attitude_roll_pid_get_MC_ROLLRATE_D(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a attitude_roll_pid message into a struct
 *
 * @param msg The message to decode
 * @param attitude_roll_pid C-struct to decode the message contents into
 */
static inline void mavlink_msg_attitude_roll_pid_decode(const mavlink_message_t* msg, mavlink_attitude_roll_pid_t* attitude_roll_pid)
{
#if MAVLINK_NEED_BYTE_SWAP
	attitude_roll_pid->MC_ROLL_P = mavlink_msg_attitude_roll_pid_get_MC_ROLL_P(msg);
	attitude_roll_pid->MC_ROLLRATE_P = mavlink_msg_attitude_roll_pid_get_MC_ROLLRATE_P(msg);
	attitude_roll_pid->MC_ROLLRATE_I = mavlink_msg_attitude_roll_pid_get_MC_ROLLRATE_I(msg);
	attitude_roll_pid->MC_ROLLRATE_D = mavlink_msg_attitude_roll_pid_get_MC_ROLLRATE_D(msg);
#else
	memcpy(attitude_roll_pid, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_Attitude_ROLL_PID_LEN);
#endif
}
