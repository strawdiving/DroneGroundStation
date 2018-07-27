// MESSAGE PID_SET_Confirm PACKING

#define MAVLINK_MSG_ID_PID_SET_Confirm 157

typedef struct __mavlink_pid_set_confirm_t
{
 float param_1; /*< param_1*/
 float param_2; /*< param_2*/
 float param_3; /*< param_3*/
 float param_4; /*< param_4*/
 char PID_NAME; /*< enum{Att_pitch,Att_roll,Att_yaw,Pos_x,Pos_y,Pos_z}*/
} mavlink_pid_set_confirm_t;

#define MAVLINK_MSG_ID_PID_SET_Confirm_LEN 17
#define MAVLINK_MSG_ID_157_LEN 17

#define MAVLINK_MSG_ID_PID_SET_Confirm_CRC 53
#define MAVLINK_MSG_ID_157_CRC 53



#define MAVLINK_MESSAGE_INFO_PID_SET_Confirm { \
	"PID_SET_Confirm", \
	5, \
	{  { "param_1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pid_set_confirm_t, param_1) }, \
         { "param_2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pid_set_confirm_t, param_2) }, \
         { "param_3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_set_confirm_t, param_3) }, \
         { "param_4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pid_set_confirm_t, param_4) }, \
         { "PID_NAME", NULL, MAVLINK_TYPE_CHAR, 0, 16, offsetof(mavlink_pid_set_confirm_t, PID_NAME) }, \
         } \
}


/**
 * @brief Pack a pid_set_confirm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param PID_NAME enum{Att_pitch,Att_roll,Att_yaw,Pos_x,Pos_y,Pos_z}
 * @param param_1 param_1
 * @param param_2 param_2
 * @param param_3 param_3
 * @param param_4 param_4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_set_confirm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       char PID_NAME, float param_1, float param_2, float param_3, float param_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PID_SET_Confirm_LEN];
	_mav_put_float(buf, 0, param_1);
	_mav_put_float(buf, 4, param_2);
	_mav_put_float(buf, 8, param_3);
	_mav_put_float(buf, 12, param_4);
	_mav_put_char(buf, 16, PID_NAME);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#else
	mavlink_pid_set_confirm_t packet;
	packet.param_1 = param_1;
	packet.param_2 = param_2;
	packet.param_3 = param_3;
	packet.param_4 = param_4;
	packet.PID_NAME = PID_NAME;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PID_SET_Confirm;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif
}

/**
 * @brief Pack a pid_set_confirm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param PID_NAME enum{Att_pitch,Att_roll,Att_yaw,Pos_x,Pos_y,Pos_z}
 * @param param_1 param_1
 * @param param_2 param_2
 * @param param_3 param_3
 * @param param_4 param_4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_set_confirm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           char PID_NAME,float param_1,float param_2,float param_3,float param_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PID_SET_Confirm_LEN];
	_mav_put_float(buf, 0, param_1);
	_mav_put_float(buf, 4, param_2);
	_mav_put_float(buf, 8, param_3);
	_mav_put_float(buf, 12, param_4);
	_mav_put_char(buf, 16, PID_NAME);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#else
	mavlink_pid_set_confirm_t packet;
	packet.param_1 = param_1;
	packet.param_2 = param_2;
	packet.param_3 = param_3;
	packet.param_4 = param_4;
	packet.PID_NAME = PID_NAME;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_PID_SET_Confirm;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif
}

/**
 * @brief Encode a pid_set_confirm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pid_set_confirm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_set_confirm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pid_set_confirm_t* pid_set_confirm)
{
	return mavlink_msg_pid_set_confirm_pack(system_id, component_id, msg, pid_set_confirm->PID_NAME, pid_set_confirm->param_1, pid_set_confirm->param_2, pid_set_confirm->param_3, pid_set_confirm->param_4);
}

/**
 * @brief Encode a pid_set_confirm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pid_set_confirm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_set_confirm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pid_set_confirm_t* pid_set_confirm)
{
	return mavlink_msg_pid_set_confirm_pack_chan(system_id, component_id, chan, msg, pid_set_confirm->PID_NAME, pid_set_confirm->param_1, pid_set_confirm->param_2, pid_set_confirm->param_3, pid_set_confirm->param_4);
}

/**
 * @brief Send a pid_set_confirm message
 * @param chan MAVLink channel to send the message
 *
 * @param PID_NAME enum{Att_pitch,Att_roll,Att_yaw,Pos_x,Pos_y,Pos_z}
 * @param param_1 param_1
 * @param param_2 param_2
 * @param param_3 param_3
 * @param param_4 param_4
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pid_set_confirm_send(mavlink_channel_t chan, char PID_NAME, float param_1, float param_2, float param_3, float param_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PID_SET_Confirm_LEN];
	_mav_put_float(buf, 0, param_1);
	_mav_put_float(buf, 4, param_2);
	_mav_put_float(buf, 8, param_3);
	_mav_put_float(buf, 12, param_4);
	_mav_put_char(buf, 16, PID_NAME);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, buf, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, buf, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif
#else
	mavlink_pid_set_confirm_t packet;
	packet.param_1 = param_1;
	packet.param_2 = param_2;
	packet.param_3 = param_3;
	packet.param_4 = param_4;
	packet.PID_NAME = PID_NAME;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, (const char *)&packet, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, (const char *)&packet, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_PID_SET_Confirm_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pid_set_confirm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  char PID_NAME, float param_1, float param_2, float param_3, float param_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, param_1);
	_mav_put_float(buf, 4, param_2);
	_mav_put_float(buf, 8, param_3);
	_mav_put_float(buf, 12, param_4);
	_mav_put_char(buf, 16, PID_NAME);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, buf, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, buf, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif
#else
	mavlink_pid_set_confirm_t *packet = (mavlink_pid_set_confirm_t *)msgbuf;
	packet->param_1 = param_1;
	packet->param_2 = param_2;
	packet->param_3 = param_3;
	packet->param_4 = param_4;
	packet->PID_NAME = PID_NAME;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, (const char *)packet, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, (const char *)packet, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE PID_SET_Confirm UNPACKING


/**
 * @brief Get field PID_NAME from pid_set_confirm message
 *
 * @return enum{Att_pitch,Att_roll,Att_yaw,Pos_x,Pos_y,Pos_z}
 */
static inline char mavlink_msg_pid_set_confirm_get_PID_NAME(const mavlink_message_t* msg)
{
	return _MAV_RETURN_char(msg,  16);
}

/**
 * @brief Get field param_1 from pid_set_confirm message
 *
 * @return param_1
 */
static inline float mavlink_msg_pid_set_confirm_get_param_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param_2 from pid_set_confirm message
 *
 * @return param_2
 */
static inline float mavlink_msg_pid_set_confirm_get_param_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param_3 from pid_set_confirm message
 *
 * @return param_3
 */
static inline float mavlink_msg_pid_set_confirm_get_param_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param_4 from pid_set_confirm message
 *
 * @return param_4
 */
static inline float mavlink_msg_pid_set_confirm_get_param_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a pid_set_confirm message into a struct
 *
 * @param msg The message to decode
 * @param pid_set_confirm C-struct to decode the message contents into
 */
static inline void mavlink_msg_pid_set_confirm_decode(const mavlink_message_t* msg, mavlink_pid_set_confirm_t* pid_set_confirm)
{
#if MAVLINK_NEED_BYTE_SWAP
	pid_set_confirm->param_1 = mavlink_msg_pid_set_confirm_get_param_1(msg);
	pid_set_confirm->param_2 = mavlink_msg_pid_set_confirm_get_param_2(msg);
	pid_set_confirm->param_3 = mavlink_msg_pid_set_confirm_get_param_3(msg);
	pid_set_confirm->param_4 = mavlink_msg_pid_set_confirm_get_param_4(msg);
	pid_set_confirm->PID_NAME = mavlink_msg_pid_set_confirm_get_PID_NAME(msg);
#else
	memcpy(pid_set_confirm, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif
}
