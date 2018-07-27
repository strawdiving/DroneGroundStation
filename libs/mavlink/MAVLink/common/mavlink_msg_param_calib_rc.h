// MESSAGE param_calib_rc PACKING

#define MAVLINK_MSG_ID_param_calib_rc 150

typedef struct __mavlink_param_calib_rc_t
{
 uint16_t RC1_MAX; /*< Maximum value for RC channel 1*/
 uint16_t RC1_MIN; /*< Minimum value for RC channel 1*/
 uint16_t RC2_MAX; /*< Maximum value for RC channel 2*/
 uint16_t RC2_MIN; /*< Minimum value for RC channel 2*/
 uint16_t RC3_MAX; /*< Maximum value for RC channel 3*/
 uint16_t RC3_MIN; /*< Minimum value for RC channel 3*/
 uint16_t RC4_MAX; /*< Maximum value for RC channel 4*/
 uint16_t RC4_MIN; /*< Minimum value for RC channel 4*/
 uint16_t RC5_MAX; /*< Maximum value for RC channel 5*/
 uint16_t RC5_MIN; /*< Minimum value for RC channel 5*/
 uint16_t RC6_MAX; /*< Maximum value for RC channel 6*/
 uint16_t RC6_MIN; /*< Minimum value for RC channel 6*/
 uint16_t RC7_MAX; /*< Maximum value for RC channel 7*/
 uint16_t RC7_MIN; /*< Minimum value for RC channel 7*/
 uint16_t RC8_MAX; /*< Maximum value for RC channel 8*/
 uint16_t RC8_MIN; /*< Minimum value for RC channel 8*/
 uint16_t RC9_MAX; /*< Maximum value for RC channel 9*/
 uint16_t RC9_MIN; /*< Minimum value for RC channel 9*/
 uint16_t RC10_MAX; /*< Maximum value for RC channel 10*/
 uint16_t RC10_MIN; /*< Minimum value for RC channel 10*/
 uint16_t RC11_MAX; /*< Maximum value for RC channel 11*/
 uint16_t RC11_MIN; /*< Minimum value for RC channel 11*/
 uint16_t RC12_MAX; /*< Maximum value for RC channel 12*/
 uint16_t RC12_MIN; /*< Minimum value for RC channel 12*/
} mavlink_param_calib_rc_t;

#define MAVLINK_MSG_ID_param_calib_rc_LEN 48
#define MAVLINK_MSG_ID_150_LEN 48

#define MAVLINK_MSG_ID_param_calib_rc_CRC 4
#define MAVLINK_MSG_ID_150_CRC 4



#define MAVLINK_MESSAGE_INFO_param_calib_rc { \
	"param_calib_rc", \
	24, \
	{  { "RC1_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_param_calib_rc_t, RC1_MAX) }, \
         { "RC1_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_param_calib_rc_t, RC1_MIN) }, \
         { "RC2_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_param_calib_rc_t, RC2_MAX) }, \
         { "RC2_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_param_calib_rc_t, RC2_MIN) }, \
         { "RC3_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_param_calib_rc_t, RC3_MAX) }, \
         { "RC3_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_param_calib_rc_t, RC3_MIN) }, \
         { "RC4_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_param_calib_rc_t, RC4_MAX) }, \
         { "RC4_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_param_calib_rc_t, RC4_MIN) }, \
         { "RC5_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_param_calib_rc_t, RC5_MAX) }, \
         { "RC5_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_param_calib_rc_t, RC5_MIN) }, \
         { "RC6_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_param_calib_rc_t, RC6_MAX) }, \
         { "RC6_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_param_calib_rc_t, RC6_MIN) }, \
         { "RC7_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_param_calib_rc_t, RC7_MAX) }, \
         { "RC7_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_param_calib_rc_t, RC7_MIN) }, \
         { "RC8_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_param_calib_rc_t, RC8_MAX) }, \
         { "RC8_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_param_calib_rc_t, RC8_MIN) }, \
         { "RC9_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_param_calib_rc_t, RC9_MAX) }, \
         { "RC9_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_param_calib_rc_t, RC9_MIN) }, \
         { "RC10_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_param_calib_rc_t, RC10_MAX) }, \
         { "RC10_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_param_calib_rc_t, RC10_MIN) }, \
         { "RC11_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_param_calib_rc_t, RC11_MAX) }, \
         { "RC11_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_param_calib_rc_t, RC11_MIN) }, \
         { "RC12_MAX", NULL, MAVLINK_TYPE_UINT16_T, 0, 44, offsetof(mavlink_param_calib_rc_t, RC12_MAX) }, \
         { "RC12_MIN", NULL, MAVLINK_TYPE_UINT16_T, 0, 46, offsetof(mavlink_param_calib_rc_t, RC12_MIN) }, \
         } \
}


/**
 * @brief Pack a param_calib_rc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param RC1_MAX Maximum value for RC channel 1
 * @param RC1_MIN Minimum value for RC channel 1
 * @param RC2_MAX Maximum value for RC channel 2
 * @param RC2_MIN Minimum value for RC channel 2
 * @param RC3_MAX Maximum value for RC channel 3
 * @param RC3_MIN Minimum value for RC channel 3
 * @param RC4_MAX Maximum value for RC channel 4
 * @param RC4_MIN Minimum value for RC channel 4
 * @param RC5_MAX Maximum value for RC channel 5
 * @param RC5_MIN Minimum value for RC channel 5
 * @param RC6_MAX Maximum value for RC channel 6
 * @param RC6_MIN Minimum value for RC channel 6
 * @param RC7_MAX Maximum value for RC channel 7
 * @param RC7_MIN Minimum value for RC channel 7
 * @param RC8_MAX Maximum value for RC channel 8
 * @param RC8_MIN Minimum value for RC channel 8
 * @param RC9_MAX Maximum value for RC channel 9
 * @param RC9_MIN Minimum value for RC channel 9
 * @param RC10_MAX Maximum value for RC channel 10
 * @param RC10_MIN Minimum value for RC channel 10
 * @param RC11_MAX Maximum value for RC channel 11
 * @param RC11_MIN Minimum value for RC channel 11
 * @param RC12_MAX Maximum value for RC channel 12
 * @param RC12_MIN Minimum value for RC channel 12
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_calib_rc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t RC1_MAX, uint16_t RC1_MIN, uint16_t RC2_MAX, uint16_t RC2_MIN, uint16_t RC3_MAX, uint16_t RC3_MIN, uint16_t RC4_MAX, uint16_t RC4_MIN, uint16_t RC5_MAX, uint16_t RC5_MIN, uint16_t RC6_MAX, uint16_t RC6_MIN, uint16_t RC7_MAX, uint16_t RC7_MIN, uint16_t RC8_MAX, uint16_t RC8_MIN, uint16_t RC9_MAX, uint16_t RC9_MIN, uint16_t RC10_MAX, uint16_t RC10_MIN, uint16_t RC11_MAX, uint16_t RC11_MIN, uint16_t RC12_MAX, uint16_t RC12_MIN)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_param_calib_rc_LEN];
	_mav_put_uint16_t(buf, 0, RC1_MAX);
	_mav_put_uint16_t(buf, 2, RC1_MIN);
	_mav_put_uint16_t(buf, 4, RC2_MAX);
	_mav_put_uint16_t(buf, 6, RC2_MIN);
	_mav_put_uint16_t(buf, 8, RC3_MAX);
	_mav_put_uint16_t(buf, 10, RC3_MIN);
	_mav_put_uint16_t(buf, 12, RC4_MAX);
	_mav_put_uint16_t(buf, 14, RC4_MIN);
	_mav_put_uint16_t(buf, 16, RC5_MAX);
	_mav_put_uint16_t(buf, 18, RC5_MIN);
	_mav_put_uint16_t(buf, 20, RC6_MAX);
	_mav_put_uint16_t(buf, 22, RC6_MIN);
	_mav_put_uint16_t(buf, 24, RC7_MAX);
	_mav_put_uint16_t(buf, 26, RC7_MIN);
	_mav_put_uint16_t(buf, 28, RC8_MAX);
	_mav_put_uint16_t(buf, 30, RC8_MIN);
	_mav_put_uint16_t(buf, 32, RC9_MAX);
	_mav_put_uint16_t(buf, 34, RC9_MIN);
	_mav_put_uint16_t(buf, 36, RC10_MAX);
	_mav_put_uint16_t(buf, 38, RC10_MIN);
	_mav_put_uint16_t(buf, 40, RC11_MAX);
	_mav_put_uint16_t(buf, 42, RC11_MIN);
	_mav_put_uint16_t(buf, 44, RC12_MAX);
	_mav_put_uint16_t(buf, 46, RC12_MIN);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_param_calib_rc_LEN);
#else
	mavlink_param_calib_rc_t packet;
	packet.RC1_MAX = RC1_MAX;
	packet.RC1_MIN = RC1_MIN;
	packet.RC2_MAX = RC2_MAX;
	packet.RC2_MIN = RC2_MIN;
	packet.RC3_MAX = RC3_MAX;
	packet.RC3_MIN = RC3_MIN;
	packet.RC4_MAX = RC4_MAX;
	packet.RC4_MIN = RC4_MIN;
	packet.RC5_MAX = RC5_MAX;
	packet.RC5_MIN = RC5_MIN;
	packet.RC6_MAX = RC6_MAX;
	packet.RC6_MIN = RC6_MIN;
	packet.RC7_MAX = RC7_MAX;
	packet.RC7_MIN = RC7_MIN;
	packet.RC8_MAX = RC8_MAX;
	packet.RC8_MIN = RC8_MIN;
	packet.RC9_MAX = RC9_MAX;
	packet.RC9_MIN = RC9_MIN;
	packet.RC10_MAX = RC10_MAX;
	packet.RC10_MIN = RC10_MIN;
	packet.RC11_MAX = RC11_MAX;
	packet.RC11_MIN = RC11_MIN;
	packet.RC12_MAX = RC12_MAX;
	packet.RC12_MIN = RC12_MIN;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_param_calib_rc_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_param_calib_rc;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_param_calib_rc_LEN, MAVLINK_MSG_ID_param_calib_rc_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_param_calib_rc_LEN);
#endif
}

/**
 * @brief Pack a param_calib_rc message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param RC1_MAX Maximum value for RC channel 1
 * @param RC1_MIN Minimum value for RC channel 1
 * @param RC2_MAX Maximum value for RC channel 2
 * @param RC2_MIN Minimum value for RC channel 2
 * @param RC3_MAX Maximum value for RC channel 3
 * @param RC3_MIN Minimum value for RC channel 3
 * @param RC4_MAX Maximum value for RC channel 4
 * @param RC4_MIN Minimum value for RC channel 4
 * @param RC5_MAX Maximum value for RC channel 5
 * @param RC5_MIN Minimum value for RC channel 5
 * @param RC6_MAX Maximum value for RC channel 6
 * @param RC6_MIN Minimum value for RC channel 6
 * @param RC7_MAX Maximum value for RC channel 7
 * @param RC7_MIN Minimum value for RC channel 7
 * @param RC8_MAX Maximum value for RC channel 8
 * @param RC8_MIN Minimum value for RC channel 8
 * @param RC9_MAX Maximum value for RC channel 9
 * @param RC9_MIN Minimum value for RC channel 9
 * @param RC10_MAX Maximum value for RC channel 10
 * @param RC10_MIN Minimum value for RC channel 10
 * @param RC11_MAX Maximum value for RC channel 11
 * @param RC11_MIN Minimum value for RC channel 11
 * @param RC12_MAX Maximum value for RC channel 12
 * @param RC12_MIN Minimum value for RC channel 12
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_calib_rc_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t RC1_MAX,uint16_t RC1_MIN,uint16_t RC2_MAX,uint16_t RC2_MIN,uint16_t RC3_MAX,uint16_t RC3_MIN,uint16_t RC4_MAX,uint16_t RC4_MIN,uint16_t RC5_MAX,uint16_t RC5_MIN,uint16_t RC6_MAX,uint16_t RC6_MIN,uint16_t RC7_MAX,uint16_t RC7_MIN,uint16_t RC8_MAX,uint16_t RC8_MIN,uint16_t RC9_MAX,uint16_t RC9_MIN,uint16_t RC10_MAX,uint16_t RC10_MIN,uint16_t RC11_MAX,uint16_t RC11_MIN,uint16_t RC12_MAX,uint16_t RC12_MIN)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_param_calib_rc_LEN];
	_mav_put_uint16_t(buf, 0, RC1_MAX);
	_mav_put_uint16_t(buf, 2, RC1_MIN);
	_mav_put_uint16_t(buf, 4, RC2_MAX);
	_mav_put_uint16_t(buf, 6, RC2_MIN);
	_mav_put_uint16_t(buf, 8, RC3_MAX);
	_mav_put_uint16_t(buf, 10, RC3_MIN);
	_mav_put_uint16_t(buf, 12, RC4_MAX);
	_mav_put_uint16_t(buf, 14, RC4_MIN);
	_mav_put_uint16_t(buf, 16, RC5_MAX);
	_mav_put_uint16_t(buf, 18, RC5_MIN);
	_mav_put_uint16_t(buf, 20, RC6_MAX);
	_mav_put_uint16_t(buf, 22, RC6_MIN);
	_mav_put_uint16_t(buf, 24, RC7_MAX);
	_mav_put_uint16_t(buf, 26, RC7_MIN);
	_mav_put_uint16_t(buf, 28, RC8_MAX);
	_mav_put_uint16_t(buf, 30, RC8_MIN);
	_mav_put_uint16_t(buf, 32, RC9_MAX);
	_mav_put_uint16_t(buf, 34, RC9_MIN);
	_mav_put_uint16_t(buf, 36, RC10_MAX);
	_mav_put_uint16_t(buf, 38, RC10_MIN);
	_mav_put_uint16_t(buf, 40, RC11_MAX);
	_mav_put_uint16_t(buf, 42, RC11_MIN);
	_mav_put_uint16_t(buf, 44, RC12_MAX);
	_mav_put_uint16_t(buf, 46, RC12_MIN);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_param_calib_rc_LEN);
#else
	mavlink_param_calib_rc_t packet;
	packet.RC1_MAX = RC1_MAX;
	packet.RC1_MIN = RC1_MIN;
	packet.RC2_MAX = RC2_MAX;
	packet.RC2_MIN = RC2_MIN;
	packet.RC3_MAX = RC3_MAX;
	packet.RC3_MIN = RC3_MIN;
	packet.RC4_MAX = RC4_MAX;
	packet.RC4_MIN = RC4_MIN;
	packet.RC5_MAX = RC5_MAX;
	packet.RC5_MIN = RC5_MIN;
	packet.RC6_MAX = RC6_MAX;
	packet.RC6_MIN = RC6_MIN;
	packet.RC7_MAX = RC7_MAX;
	packet.RC7_MIN = RC7_MIN;
	packet.RC8_MAX = RC8_MAX;
	packet.RC8_MIN = RC8_MIN;
	packet.RC9_MAX = RC9_MAX;
	packet.RC9_MIN = RC9_MIN;
	packet.RC10_MAX = RC10_MAX;
	packet.RC10_MIN = RC10_MIN;
	packet.RC11_MAX = RC11_MAX;
	packet.RC11_MIN = RC11_MIN;
	packet.RC12_MAX = RC12_MAX;
	packet.RC12_MIN = RC12_MIN;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_param_calib_rc_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_param_calib_rc;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_param_calib_rc_LEN, MAVLINK_MSG_ID_param_calib_rc_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_param_calib_rc_LEN);
#endif
}

/**
 * @brief Encode a param_calib_rc struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_calib_rc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_calib_rc_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_calib_rc_t* param_calib_rc)
{
	return mavlink_msg_param_calib_rc_pack(system_id, component_id, msg, param_calib_rc->RC1_MAX, param_calib_rc->RC1_MIN, param_calib_rc->RC2_MAX, param_calib_rc->RC2_MIN, param_calib_rc->RC3_MAX, param_calib_rc->RC3_MIN, param_calib_rc->RC4_MAX, param_calib_rc->RC4_MIN, param_calib_rc->RC5_MAX, param_calib_rc->RC5_MIN, param_calib_rc->RC6_MAX, param_calib_rc->RC6_MIN, param_calib_rc->RC7_MAX, param_calib_rc->RC7_MIN, param_calib_rc->RC8_MAX, param_calib_rc->RC8_MIN, param_calib_rc->RC9_MAX, param_calib_rc->RC9_MIN, param_calib_rc->RC10_MAX, param_calib_rc->RC10_MIN, param_calib_rc->RC11_MAX, param_calib_rc->RC11_MIN, param_calib_rc->RC12_MAX, param_calib_rc->RC12_MIN);
}

/**
 * @brief Encode a param_calib_rc struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_calib_rc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_calib_rc_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_calib_rc_t* param_calib_rc)
{
	return mavlink_msg_param_calib_rc_pack_chan(system_id, component_id, chan, msg, param_calib_rc->RC1_MAX, param_calib_rc->RC1_MIN, param_calib_rc->RC2_MAX, param_calib_rc->RC2_MIN, param_calib_rc->RC3_MAX, param_calib_rc->RC3_MIN, param_calib_rc->RC4_MAX, param_calib_rc->RC4_MIN, param_calib_rc->RC5_MAX, param_calib_rc->RC5_MIN, param_calib_rc->RC6_MAX, param_calib_rc->RC6_MIN, param_calib_rc->RC7_MAX, param_calib_rc->RC7_MIN, param_calib_rc->RC8_MAX, param_calib_rc->RC8_MIN, param_calib_rc->RC9_MAX, param_calib_rc->RC9_MIN, param_calib_rc->RC10_MAX, param_calib_rc->RC10_MIN, param_calib_rc->RC11_MAX, param_calib_rc->RC11_MIN, param_calib_rc->RC12_MAX, param_calib_rc->RC12_MIN);
}

/**
 * @brief Send a param_calib_rc message
 * @param chan MAVLink channel to send the message
 *
 * @param RC1_MAX Maximum value for RC channel 1
 * @param RC1_MIN Minimum value for RC channel 1
 * @param RC2_MAX Maximum value for RC channel 2
 * @param RC2_MIN Minimum value for RC channel 2
 * @param RC3_MAX Maximum value for RC channel 3
 * @param RC3_MIN Minimum value for RC channel 3
 * @param RC4_MAX Maximum value for RC channel 4
 * @param RC4_MIN Minimum value for RC channel 4
 * @param RC5_MAX Maximum value for RC channel 5
 * @param RC5_MIN Minimum value for RC channel 5
 * @param RC6_MAX Maximum value for RC channel 6
 * @param RC6_MIN Minimum value for RC channel 6
 * @param RC7_MAX Maximum value for RC channel 7
 * @param RC7_MIN Minimum value for RC channel 7
 * @param RC8_MAX Maximum value for RC channel 8
 * @param RC8_MIN Minimum value for RC channel 8
 * @param RC9_MAX Maximum value for RC channel 9
 * @param RC9_MIN Minimum value for RC channel 9
 * @param RC10_MAX Maximum value for RC channel 10
 * @param RC10_MIN Minimum value for RC channel 10
 * @param RC11_MAX Maximum value for RC channel 11
 * @param RC11_MIN Minimum value for RC channel 11
 * @param RC12_MAX Maximum value for RC channel 12
 * @param RC12_MIN Minimum value for RC channel 12
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_param_calib_rc_send(mavlink_channel_t chan, uint16_t RC1_MAX, uint16_t RC1_MIN, uint16_t RC2_MAX, uint16_t RC2_MIN, uint16_t RC3_MAX, uint16_t RC3_MIN, uint16_t RC4_MAX, uint16_t RC4_MIN, uint16_t RC5_MAX, uint16_t RC5_MIN, uint16_t RC6_MAX, uint16_t RC6_MIN, uint16_t RC7_MAX, uint16_t RC7_MIN, uint16_t RC8_MAX, uint16_t RC8_MIN, uint16_t RC9_MAX, uint16_t RC9_MIN, uint16_t RC10_MAX, uint16_t RC10_MIN, uint16_t RC11_MAX, uint16_t RC11_MIN, uint16_t RC12_MAX, uint16_t RC12_MIN)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_param_calib_rc_LEN];
	_mav_put_uint16_t(buf, 0, RC1_MAX);
	_mav_put_uint16_t(buf, 2, RC1_MIN);
	_mav_put_uint16_t(buf, 4, RC2_MAX);
	_mav_put_uint16_t(buf, 6, RC2_MIN);
	_mav_put_uint16_t(buf, 8, RC3_MAX);
	_mav_put_uint16_t(buf, 10, RC3_MIN);
	_mav_put_uint16_t(buf, 12, RC4_MAX);
	_mav_put_uint16_t(buf, 14, RC4_MIN);
	_mav_put_uint16_t(buf, 16, RC5_MAX);
	_mav_put_uint16_t(buf, 18, RC5_MIN);
	_mav_put_uint16_t(buf, 20, RC6_MAX);
	_mav_put_uint16_t(buf, 22, RC6_MIN);
	_mav_put_uint16_t(buf, 24, RC7_MAX);
	_mav_put_uint16_t(buf, 26, RC7_MIN);
	_mav_put_uint16_t(buf, 28, RC8_MAX);
	_mav_put_uint16_t(buf, 30, RC8_MIN);
	_mav_put_uint16_t(buf, 32, RC9_MAX);
	_mav_put_uint16_t(buf, 34, RC9_MIN);
	_mav_put_uint16_t(buf, 36, RC10_MAX);
	_mav_put_uint16_t(buf, 38, RC10_MIN);
	_mav_put_uint16_t(buf, 40, RC11_MAX);
	_mav_put_uint16_t(buf, 42, RC11_MIN);
	_mav_put_uint16_t(buf, 44, RC12_MAX);
	_mav_put_uint16_t(buf, 46, RC12_MIN);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_param_calib_rc, buf, MAVLINK_MSG_ID_param_calib_rc_LEN, MAVLINK_MSG_ID_param_calib_rc_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_param_calib_rc, buf, MAVLINK_MSG_ID_param_calib_rc_LEN);
#endif
#else
	mavlink_param_calib_rc_t packet;
	packet.RC1_MAX = RC1_MAX;
	packet.RC1_MIN = RC1_MIN;
	packet.RC2_MAX = RC2_MAX;
	packet.RC2_MIN = RC2_MIN;
	packet.RC3_MAX = RC3_MAX;
	packet.RC3_MIN = RC3_MIN;
	packet.RC4_MAX = RC4_MAX;
	packet.RC4_MIN = RC4_MIN;
	packet.RC5_MAX = RC5_MAX;
	packet.RC5_MIN = RC5_MIN;
	packet.RC6_MAX = RC6_MAX;
	packet.RC6_MIN = RC6_MIN;
	packet.RC7_MAX = RC7_MAX;
	packet.RC7_MIN = RC7_MIN;
	packet.RC8_MAX = RC8_MAX;
	packet.RC8_MIN = RC8_MIN;
	packet.RC9_MAX = RC9_MAX;
	packet.RC9_MIN = RC9_MIN;
	packet.RC10_MAX = RC10_MAX;
	packet.RC10_MIN = RC10_MIN;
	packet.RC11_MAX = RC11_MAX;
	packet.RC11_MIN = RC11_MIN;
	packet.RC12_MAX = RC12_MAX;
	packet.RC12_MIN = RC12_MIN;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_param_calib_rc, (const char *)&packet, MAVLINK_MSG_ID_param_calib_rc_LEN, MAVLINK_MSG_ID_param_calib_rc_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_param_calib_rc, (const char *)&packet, MAVLINK_MSG_ID_param_calib_rc_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_param_calib_rc_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_param_calib_rc_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t RC1_MAX, uint16_t RC1_MIN, uint16_t RC2_MAX, uint16_t RC2_MIN, uint16_t RC3_MAX, uint16_t RC3_MIN, uint16_t RC4_MAX, uint16_t RC4_MIN, uint16_t RC5_MAX, uint16_t RC5_MIN, uint16_t RC6_MAX, uint16_t RC6_MIN, uint16_t RC7_MAX, uint16_t RC7_MIN, uint16_t RC8_MAX, uint16_t RC8_MIN, uint16_t RC9_MAX, uint16_t RC9_MIN, uint16_t RC10_MAX, uint16_t RC10_MIN, uint16_t RC11_MAX, uint16_t RC11_MIN, uint16_t RC12_MAX, uint16_t RC12_MIN)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, RC1_MAX);
	_mav_put_uint16_t(buf, 2, RC1_MIN);
	_mav_put_uint16_t(buf, 4, RC2_MAX);
	_mav_put_uint16_t(buf, 6, RC2_MIN);
	_mav_put_uint16_t(buf, 8, RC3_MAX);
	_mav_put_uint16_t(buf, 10, RC3_MIN);
	_mav_put_uint16_t(buf, 12, RC4_MAX);
	_mav_put_uint16_t(buf, 14, RC4_MIN);
	_mav_put_uint16_t(buf, 16, RC5_MAX);
	_mav_put_uint16_t(buf, 18, RC5_MIN);
	_mav_put_uint16_t(buf, 20, RC6_MAX);
	_mav_put_uint16_t(buf, 22, RC6_MIN);
	_mav_put_uint16_t(buf, 24, RC7_MAX);
	_mav_put_uint16_t(buf, 26, RC7_MIN);
	_mav_put_uint16_t(buf, 28, RC8_MAX);
	_mav_put_uint16_t(buf, 30, RC8_MIN);
	_mav_put_uint16_t(buf, 32, RC9_MAX);
	_mav_put_uint16_t(buf, 34, RC9_MIN);
	_mav_put_uint16_t(buf, 36, RC10_MAX);
	_mav_put_uint16_t(buf, 38, RC10_MIN);
	_mav_put_uint16_t(buf, 40, RC11_MAX);
	_mav_put_uint16_t(buf, 42, RC11_MIN);
	_mav_put_uint16_t(buf, 44, RC12_MAX);
	_mav_put_uint16_t(buf, 46, RC12_MIN);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_param_calib_rc, buf, MAVLINK_MSG_ID_param_calib_rc_LEN, MAVLINK_MSG_ID_param_calib_rc_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_param_calib_rc, buf, MAVLINK_MSG_ID_param_calib_rc_LEN);
#endif
#else
	mavlink_param_calib_rc_t *packet = (mavlink_param_calib_rc_t *)msgbuf;
	packet->RC1_MAX = RC1_MAX;
	packet->RC1_MIN = RC1_MIN;
	packet->RC2_MAX = RC2_MAX;
	packet->RC2_MIN = RC2_MIN;
	packet->RC3_MAX = RC3_MAX;
	packet->RC3_MIN = RC3_MIN;
	packet->RC4_MAX = RC4_MAX;
	packet->RC4_MIN = RC4_MIN;
	packet->RC5_MAX = RC5_MAX;
	packet->RC5_MIN = RC5_MIN;
	packet->RC6_MAX = RC6_MAX;
	packet->RC6_MIN = RC6_MIN;
	packet->RC7_MAX = RC7_MAX;
	packet->RC7_MIN = RC7_MIN;
	packet->RC8_MAX = RC8_MAX;
	packet->RC8_MIN = RC8_MIN;
	packet->RC9_MAX = RC9_MAX;
	packet->RC9_MIN = RC9_MIN;
	packet->RC10_MAX = RC10_MAX;
	packet->RC10_MIN = RC10_MIN;
	packet->RC11_MAX = RC11_MAX;
	packet->RC11_MIN = RC11_MIN;
	packet->RC12_MAX = RC12_MAX;
	packet->RC12_MIN = RC12_MIN;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_param_calib_rc, (const char *)packet, MAVLINK_MSG_ID_param_calib_rc_LEN, MAVLINK_MSG_ID_param_calib_rc_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_param_calib_rc, (const char *)packet, MAVLINK_MSG_ID_param_calib_rc_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE param_calib_rc UNPACKING


/**
 * @brief Get field RC1_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 1
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC1_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field RC1_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 1
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC1_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field RC2_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 2
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC2_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field RC2_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 2
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC2_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field RC3_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 3
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC3_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field RC3_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 3
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC3_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field RC4_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 4
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC4_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field RC4_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 4
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC4_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field RC5_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 5
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC5_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field RC5_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 5
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC5_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field RC6_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 6
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC6_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field RC6_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 6
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC6_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field RC7_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 7
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC7_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field RC7_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 7
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC7_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field RC8_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 8
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC8_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field RC8_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 8
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC8_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field RC9_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 9
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC9_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field RC9_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 9
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC9_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field RC10_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 10
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC10_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field RC10_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 10
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC10_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field RC11_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 11
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC11_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field RC11_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 11
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC11_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Get field RC12_MAX from param_calib_rc message
 *
 * @return Maximum value for RC channel 12
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC12_MAX(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  44);
}

/**
 * @brief Get field RC12_MIN from param_calib_rc message
 *
 * @return Minimum value for RC channel 12
 */
static inline uint16_t mavlink_msg_param_calib_rc_get_RC12_MIN(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  46);
}

/**
 * @brief Decode a param_calib_rc message into a struct
 *
 * @param msg The message to decode
 * @param param_calib_rc C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_calib_rc_decode(const mavlink_message_t* msg, mavlink_param_calib_rc_t* param_calib_rc)
{
#if MAVLINK_NEED_BYTE_SWAP
	param_calib_rc->RC1_MAX = mavlink_msg_param_calib_rc_get_RC1_MAX(msg);
	param_calib_rc->RC1_MIN = mavlink_msg_param_calib_rc_get_RC1_MIN(msg);
	param_calib_rc->RC2_MAX = mavlink_msg_param_calib_rc_get_RC2_MAX(msg);
	param_calib_rc->RC2_MIN = mavlink_msg_param_calib_rc_get_RC2_MIN(msg);
	param_calib_rc->RC3_MAX = mavlink_msg_param_calib_rc_get_RC3_MAX(msg);
	param_calib_rc->RC3_MIN = mavlink_msg_param_calib_rc_get_RC3_MIN(msg);
	param_calib_rc->RC4_MAX = mavlink_msg_param_calib_rc_get_RC4_MAX(msg);
	param_calib_rc->RC4_MIN = mavlink_msg_param_calib_rc_get_RC4_MIN(msg);
	param_calib_rc->RC5_MAX = mavlink_msg_param_calib_rc_get_RC5_MAX(msg);
	param_calib_rc->RC5_MIN = mavlink_msg_param_calib_rc_get_RC5_MIN(msg);
	param_calib_rc->RC6_MAX = mavlink_msg_param_calib_rc_get_RC6_MAX(msg);
	param_calib_rc->RC6_MIN = mavlink_msg_param_calib_rc_get_RC6_MIN(msg);
	param_calib_rc->RC7_MAX = mavlink_msg_param_calib_rc_get_RC7_MAX(msg);
	param_calib_rc->RC7_MIN = mavlink_msg_param_calib_rc_get_RC7_MIN(msg);
	param_calib_rc->RC8_MAX = mavlink_msg_param_calib_rc_get_RC8_MAX(msg);
	param_calib_rc->RC8_MIN = mavlink_msg_param_calib_rc_get_RC8_MIN(msg);
	param_calib_rc->RC9_MAX = mavlink_msg_param_calib_rc_get_RC9_MAX(msg);
	param_calib_rc->RC9_MIN = mavlink_msg_param_calib_rc_get_RC9_MIN(msg);
	param_calib_rc->RC10_MAX = mavlink_msg_param_calib_rc_get_RC10_MAX(msg);
	param_calib_rc->RC10_MIN = mavlink_msg_param_calib_rc_get_RC10_MIN(msg);
	param_calib_rc->RC11_MAX = mavlink_msg_param_calib_rc_get_RC11_MAX(msg);
	param_calib_rc->RC11_MIN = mavlink_msg_param_calib_rc_get_RC11_MIN(msg);
	param_calib_rc->RC12_MAX = mavlink_msg_param_calib_rc_get_RC12_MAX(msg);
	param_calib_rc->RC12_MIN = mavlink_msg_param_calib_rc_get_RC12_MIN(msg);
#else
	memcpy(param_calib_rc, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_param_calib_rc_LEN);
#endif
}
