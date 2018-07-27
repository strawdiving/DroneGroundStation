#ifndef MESSAGES_H
#define MESSAGES_H
#include "basic_types.h"

typedef struct accProcessed_s{
	uint32_t timestamp;
	vec3f_t mean;
	vec3f_t std;
}accProcessed_t;
typedef enum missionVehicle_e{
	Normal = 0,
	Takeoff,
	Land,
	Returnhome
}mission_t;
typedef struct margData_s {
	uint32_t timestamp;
	vec3f_t acc;
	vec3f_t gyr;
	vec3f_t mag;
	bool mag_updated;
} marg_t;
typedef struct calib_s {
	vec3f_acc_cali_t acc_bias;//hyl- change vec3i16_t to vec3f_acc_cali_t
	vec3f_imu_cali_t gyr_bias;//hyl- change vec3i16_t to vec3f_imu_cali_t	
	vec3f_mag_cali_t mag_bias;
	vec3f_imu_cali_t mag_d_bias;
	vec3f_imu_cali_t acc_d_bias;
	vec3f_imu_cali_t acc_d_prop;
	vec3f_imu_cali_t gyr_tmp_bias;
	vec3f_imu_cali_t acc_tmp_bias;
} calib_t;
typedef struct calib_st {
	union{
		struct{
			bool acc_done;						//hyl- add
			bool gyr_done;	
			bool mag_done;
//		bool rc_done;
		};
	uint8_t v[3];
	};
} calib_status;
typedef struct baro_s {
	uint32_t timestamp;
	float pressure;
	float temp;
	float alt;
	float offset;
} baro_t;
typedef struct gpsRaw_s {
	uint32_t timestamp;
	int64_t lat;
	int64_t lon;
	float azm;
	float vel;
	bool vel_valid;
	float alt;
	uint8_t sat;
	uint32_t date;
	uint32_t time;
	float eph;
	enum statusGPS_e {
		noGPS = 0,
		realtimeGPS = 1,
		difGPS = 2
	}status;
} gpsRaw_t;
typedef struct gpsProcessed_s {
	uint32_t timestamp;
	vec3f_t pos;
	vec3f_t vel;
	vec3f_t acc;
} gpsProcessed_t;
typedef struct rc_s {
	uint32_t timestamp;
	float channels[16];
} rc_t;
typedef struct battery_s {
	uint32_t timestamp;
	uint16_t voltage;
	int8_t battery_remaining;	//SK	2017-3-28 11:09:39
} battery_t;//used in queue
typedef struct att_s {
	uint32_t timestamp;
	vec3f_t Euler;
	quaternion_t Q;
	rotation_t R;
	vec3f_t rate;
} att_t;//used in queue
typedef struct pos_s {
	uint32_t timestamp;
	vec3f_t pos;
	vec3f_t vel;
	vec3f_t acc;
	bool xy_valid;
	float yaw_bias;
} pos_t;//used in queue
typedef struct attsp_s {
	uint32_t timestamp;
	rotation_t R;
	float thrust;
	float yaw_ff;
} attsp_t;//used in queue
typedef struct possp_s {
	uint32_t timestamp;
	vec3f_t pos_sp;
	vec3f_t vel_ff;
	vec3f_t acc_ff;
	float yaw_sp;
}posCtrlsp_t;//used in queue
typedef struct altCtrlsp_s {
	uint32_t timestamp;
	float pos_sp_z;
	float vel_ff_z;
	vec3f_t euler;
} altCtrlsp_t;//used in queue
typedef struct manuelCtrlsp_s {
	uint32_t timestamp;
	float throttle;
	vec3f_t euler;
} manCtrlsp_t;//used in queue
typedef struct output_s {
	uint32_t timestamp;
	vec3f_t moment;
	float thrust;
} output_t;//used in queue
typedef struct motors_s {
	float thrust[8];
} motors_t;//used in queue
typedef struct msg_magcalib{	//SK 2017-3-28 11:09:21
	union{
		struct{
			char data_1[5];
			int num;
			};
			char textt[7];		//SK 	2017-3-30 14:35:53
		};
} msg_magcalib_t;


typedef enum modeVehicle_e {
	modeCal = 0,
	modeRate,
	modeMan,
	modeAlt,
	modePos,
	modeTrj
} mode_t;
typedef enum statusLock_e {
	motorLocked = 0,
	motorUnlocking,
	motorUnlocked,
} statusLock_t;
typedef enum statusFlight_e {
	statusLanded = 0,
	statusInitiating,
	statusTakingoff,
	statusLanding,
	statusFlying,
	statusHovering,
	stautsFreefall,
	stautsUpsidedown,
	stautsTumble
} statusFlight_t;
typedef enum statusGS_e {
	gs_normal = 0,

} statusGS_t;
typedef enum statusRC_e {
	rc_normal = 0,
} statusRC_t;
//typedef enum msg_log_type {
//	LOG_MODE=0,
//	LOG_STATUS,
//	
//	LOG_IMU,
//	LOG_BARO,
//	LOG_GPS,
//	LOG_RC,
//	
//	LOG_ATTSP,
//	LOG_ATT,
//	LOG_FORCE,
//	LOG_MAN_POSSP,
//	LOG_ALT_POSSP,
//	LOG_POS_POSSP,
//	LOG_POS,
//	LOG_POWER
//} msg_log_type_t;
extern mode_t g_mode;
extern statusLock_t g_statusLock;
extern statusFlight_t g_statusFlight;
extern statusRC_t g_statusRC;
extern statusGS_t g_statusGS;
//extern msg_log_type_t msg_log_type;
#endif
