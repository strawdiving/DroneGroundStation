#ifndef __SDFILES_H__
#define __SDFILES_H__


//#include "stm32f4xx.h"
//#include "ff.h"
//#include "fatfs.h"
#include "messages.h"

//typedef struct _sensor_combined_s
//{
//	union{
//		struct {
//			char message_id;
//			marg_t marg_log_s;
//		};
//		char  marg_sens_log[40];
//	};
//}sensor_combined_t;

typedef struct _mode_log_s
{
	char message_id;
	uint32_t timestamp;
	mode_t mode_log_s;
}mode_log_t;

typedef struct _status_log_s
{
	char message_id;
	uint32_t timestamp;
	statusFlight_t status_log_s;
}status_log_t;

typedef struct _imu_log_s
{
	char message_id;
	marg_t marg_log_s;
}imu_log_t;

typedef struct _baro_log_s
{
	char message_id;
	baro_t baro_log_s;
}baro_log_t;

typedef struct _gps_log_s
{
	char message_id;
	gpsRaw_t gpsRaw_log_s;
}gps_log_t;

typedef struct _rc_log_s
{
	char message_id;
	rc_t rc_log_s;
}rc_log_t;

//typedef struct _attsp_log_s
//{
//	char message_id;
//	attsp_t attsp_log_s;
//}attsp_log_t;

typedef struct _att_log_s
{
	char message_id;
	att_t att_log_s;
}att_log_t;

typedef struct _output_log_s
{
	char message_id;
	output_t output_log_s;
}output_log_t;

typedef struct _mansp_log_s
{
	char message_id;
	manCtrlsp_t mansp_log_s;
}mansp_log_t;

typedef struct _altsp_log_s
{
	char message_id;
	altCtrlsp_t altsp_log_s;
}altsp_log_t;

typedef struct _possp_log_s
{
	char message_id;
	posCtrlsp_t possp_log_s;
}possp_log_t;

typedef struct _pos_log_s
{
	char message_id;
	pos_t pos_log_s;
}pos_log_t;

typedef struct _bat_log_s
{
	char message_id;
	battery_t bat_log_s;
}bat_log_t;


//extern FIL sd_file;
//extern char file_newline[2];
//extern uint32_t byte_writtened;
//extern FRESULT f_res;

void sd_file_init(void);
void vLogTask(void *pvParameters);


#endif


