// MESSAGE Qgcmission PACKING

#define MAVLINK_MSG_ID_Qgcmission 224

typedef struct __mavlink_qgcmission_t
{
 float length; /*< X-axis angular offset (in radians) of the target from the center of the image*/
 float width; /*< Y-axis angular offset (in radians) of the target from the center of the image*/
 float height; /*< Distance to the target from the vehicle in meters*/
 uint8_t times; /*< MAV_FRAME enum specifying the whether the following feilds are earth-frame, body-frame, etc.*/
} mavlink_qgcmission_t;

#define MAVLINK_MSG_ID_Qgcmission_LEN 13
#define MAVLINK_MSG_ID_224_LEN 13

#define MAVLINK_MSG_ID_Qgcmission_CRC 164
#define MAVLINK_MSG_ID_224_CRC 164



#define MAVLINK_MESSAGE_INFO_Qgcmission { \
	"Qgcmission", \
	4, \
	{  { "length", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_qgcmission_t, length) }, \
         { "width", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_qgcmission_t, width) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_qgcmission_t, height) }, \
         { "times", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_qgcmission_t, times) }, \
         } \
}


/**
 * @brief Pack a qgcmission message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param length X-axis angular offset (in radians) of the target from the center of the image
 * @param width Y-axis angular offset (in radians) of the target from the center of the image
 * @param height Distance to the target from the vehicle in meters
 * @param times MAV_FRAME enum specifying the whether the following feilds are earth-frame, body-frame, etc.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_qgcmission_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float length, float width, float height, uint8_t times)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Qgcmission_LEN];
	_mav_put_float(buf, 0, length);
	_mav_put_float(buf, 4, width);
	_mav_put_float(buf, 8, height);
	_mav_put_uint8_t(buf, 12, times);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Qgcmission_LEN);
#else
	mavlink_qgcmission_t packet;
	packet.length = length;
	packet.width = width;
	packet.height = height;
	packet.times = times;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Qgcmission_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Qgcmission;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Qgcmission_LEN, MAVLINK_MSG_ID_Qgcmission_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_Qgcmission_LEN);
#endif
}

/**
 * @brief Pack a qgcmission message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param length X-axis angular offset (in radians) of the target from the center of the image
 * @param width Y-axis angular offset (in radians) of the target from the center of the image
 * @param height Distance to the target from the vehicle in meters
 * @param times MAV_FRAME enum specifying the whether the following feilds are earth-frame, body-frame, etc.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_qgcmission_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float length,float width,float height,uint8_t times)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Qgcmission_LEN];
	_mav_put_float(buf, 0, length);
	_mav_put_float(buf, 4, width);
	_mav_put_float(buf, 8, height);
	_mav_put_uint8_t(buf, 12, times);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_Qgcmission_LEN);
#else
	mavlink_qgcmission_t packet;
	packet.length = length;
	packet.width = width;
	packet.height = height;
	packet.times = times;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_Qgcmission_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_Qgcmission;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Qgcmission_LEN, MAVLINK_MSG_ID_Qgcmission_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_Qgcmission_LEN);
#endif
}

/**
 * @brief Encode a qgcmission struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param qgcmission C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_qgcmission_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_qgcmission_t* qgcmission)
{
	return mavlink_msg_qgcmission_pack(system_id, component_id, msg, qgcmission->length, qgcmission->width, qgcmission->height, qgcmission->times);
}

/**
 * @brief Encode a qgcmission struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param qgcmission C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_qgcmission_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_qgcmission_t* qgcmission)
{
	return mavlink_msg_qgcmission_pack_chan(system_id, component_id, chan, msg, qgcmission->length, qgcmission->width, qgcmission->height, qgcmission->times);
}

/**
 * @brief Send a qgcmission message
 * @param chan MAVLink channel to send the message
 *
 * @param length X-axis angular offset (in radians) of the target from the center of the image
 * @param width Y-axis angular offset (in radians) of the target from the center of the image
 * @param height Distance to the target from the vehicle in meters
 * @param times MAV_FRAME enum specifying the whether the following feilds are earth-frame, body-frame, etc.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_qgcmission_send(mavlink_channel_t chan, float length, float width, float height, uint8_t times)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_Qgcmission_LEN];
	_mav_put_float(buf, 0, length);
	_mav_put_float(buf, 4, width);
	_mav_put_float(buf, 8, height);
	_mav_put_uint8_t(buf, 12, times);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Qgcmission, buf, MAVLINK_MSG_ID_Qgcmission_LEN, MAVLINK_MSG_ID_Qgcmission_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Qgcmission, buf, MAVLINK_MSG_ID_Qgcmission_LEN);
#endif
#else
	mavlink_qgcmission_t packet;
	packet.length = length;
	packet.width = width;
	packet.height = height;
	packet.times = times;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Qgcmission, (const char *)&packet, MAVLINK_MSG_ID_Qgcmission_LEN, MAVLINK_MSG_ID_Qgcmission_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Qgcmission, (const char *)&packet, MAVLINK_MSG_ID_Qgcmission_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_Qgcmission_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_qgcmission_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float length, float width, float height, uint8_t times)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, length);
	_mav_put_float(buf, 4, width);
	_mav_put_float(buf, 8, height);
	_mav_put_uint8_t(buf, 12, times);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Qgcmission, buf, MAVLINK_MSG_ID_Qgcmission_LEN, MAVLINK_MSG_ID_Qgcmission_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Qgcmission, buf, MAVLINK_MSG_ID_Qgcmission_LEN);
#endif
#else
	mavlink_qgcmission_t *packet = (mavlink_qgcmission_t *)msgbuf;
	packet->length = length;
	packet->width = width;
	packet->height = height;
	packet->times = times;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Qgcmission, (const char *)packet, MAVLINK_MSG_ID_Qgcmission_LEN, MAVLINK_MSG_ID_Qgcmission_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_Qgcmission, (const char *)packet, MAVLINK_MSG_ID_Qgcmission_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE Qgcmission UNPACKING


/**
 * @brief Get field length from qgcmission message
 *
 * @return X-axis angular offset (in radians) of the target from the center of the image
 */
static inline float mavlink_msg_qgcmission_get_length(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field width from qgcmission message
 *
 * @return Y-axis angular offset (in radians) of the target from the center of the image
 */
static inline float mavlink_msg_qgcmission_get_width(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field height from qgcmission message
 *
 * @return Distance to the target from the vehicle in meters
 */
static inline float mavlink_msg_qgcmission_get_height(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field times from qgcmission message
 *
 * @return MAV_FRAME enum specifying the whether the following feilds are earth-frame, body-frame, etc.
 */
static inline uint8_t mavlink_msg_qgcmission_get_times(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Decode a qgcmission message into a struct
 *
 * @param msg The message to decode
 * @param qgcmission C-struct to decode the message contents into
 */
static inline void mavlink_msg_qgcmission_decode(const mavlink_message_t* msg, mavlink_qgcmission_t* qgcmission)
{
#if MAVLINK_NEED_BYTE_SWAP
	qgcmission->length = mavlink_msg_qgcmission_get_length(msg);
	qgcmission->width = mavlink_msg_qgcmission_get_width(msg);
	qgcmission->height = mavlink_msg_qgcmission_get_height(msg);
	qgcmission->times = mavlink_msg_qgcmission_get_times(msg);
#else
	memcpy(qgcmission, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_Qgcmission_LEN);
#endif
}
