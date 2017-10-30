#ifndef __UITD_H__
#define __UITD_H__

#include "stdint.h"
#include "board.h"
#include "sys_def.h"
#include <rtdevice.h>
//#include "ringbuffer.h"


//#include "sensor_sample.h"


//#include "fire_alarm.h"



#define FW_FILE_PATH    "/fw/firmware.bin"
#define FW_UPGRADE_FLAG "/fw/upgrade.flg"
#define FW_FILE_DIR     "/fw"
#define DOWN_FILE_DIR   "/download"


//#if defined ( __CC_ARM )
//    #define PACK_STRUCT_BEGIN		
//    #define PACK_STRUCT_STRUCT		 __attribute__((packed))
//    #define PACK_STRUCT_END
//    #define PACK_STRUCT_FIELD(x) 	 x

//#elif defined ( __GNUC__ )
//    #define PACK_STRUCT_BEGIN		
//    #define PACK_STRUCT_STRUCT		 __attribute__((packed))
//    #define PACK_STRUCT_END
//    #define PACK_STRUCT_FIELD(x) 	 x
//#endif


#define GB_SW_VER_MAIN			1
#define GB_SW_VER_USER			20

#define GB_PKT_HEAD_CHAR		'@'
#define GB_PKT_TAIL_CHAR		'#'
#define GB_PKT_HEAD				"@@"
#define GB_PKT_TAIL			    "##"

#define GB_CTRL_LEN				sizeof(t_GB_ctrl_unit)
#define GB_DATA_LEN_MIN			0
#define GB_DATA_LEN_MAX			1024
#define GB_CHECKSUM_LEN			1
#define GB_PACKET_LEN_MIN		(GB_CTRL_LEN + GB_DATA_LEN_MIN + GB_CHECKSUM_LEN)
#define GB_PACKET_LEN_MAX		(GB_CTRL_LEN + GB_DATA_LEN_MAX + GB_CHECKSUM_LEN)
#define GB_ROUGH_LEN_MIN		(GB_PACKET_LEN_MIN + sizeof(GB_PKT_HEAD) + sizeof(GB_PKT_TAIL))
#define GB_ROUGH_LEN_MAX		(GB_PACKET_LEN_MAX + sizeof(GB_PKT_HEAD) + sizeof(GB_PKT_TAIL))
#define GB_ROUGH_BUF_MAX		(GB_ROUGH_LEN_MAX * 2)
#define GB_PACKET_NO_DATA_LEN   GB_PACKET_LEN_MIN


#define TP_DATA_PKT_SIZE_MAX    800

#define FW_NAME_LEN_MAX         64
#define FW_PKT_LEN_MAX          (GB_DATA_LEN_MAX - sizeof(s_FW_DATA) - 2)
#define FW_PKT_LEN_DEFAULT      FW_PKT_LEN_MAX
////#define FW_PKT_LEN_DEFAULT      512

////#define FILE_DATA_BUF_NUM       4
#define FILE_DATA_BUF_NUM       1

#define GB_SERVER_NODE_MAX		20

#define SERVER_TIMEOUT_MAX	    (100 * 10)  // 10S
#define SERVER_RETRY_MAX		3

////#define SERVER_ALIVE_PERIOD     (100 * 30)  // 30S
#define SERVER_ALIVE_PERIOD     (100 * 60)  // 60S


#define UITD_VER_MAIN		    1
#define UITD_VER_SUB		    1

#define GB_CMD_RESERVE		    0
#define GB_CMD_CTRL				1
#define GB_CMD_SEND_DATA	    2
#define GB_CMD_AFFIRM			3
#define GB_CMD_REQUIRE		    4
#define GB_CMD_ACK				5
#define GB_CMD_DENY				6
#define JS_CMD_ALIVE			128
#define JS_CMD_FILE_SERVICE 	129
#define JS_CMD_SENSOR_SAMPLE    130
#define JS_CMD_OUTPUT_CTRL      131
#define JS_CMD_INPUT_REPORT     132
#define JS_CMD_IOT_GW_INFO      133
#define JS_CMD_IOT_GW_SCRIPT    134
#define JS_CMD_DIR_FILE_UPLOAD  135
#define JS_CMD_ROUGH_DATA_TRANS 136


#define GB_TYPE_0_RESERVE						    0
#define GB_TYPE_1_U_FIRE_SYS_STATUS				    1
#define GB_TYPE_2_U_FIRE_DEV_STATUS				    2
#define GB_TYPE_3_U_FIRE_DEV_ANALOG				    3
#define GB_TYPE_4_U_FIRE_DEV_OPERATE			    4
#define GB_TYPE_5_U_FIRE_SYS_SW						5
#define GB_TYPE_6_U_FIRE_SYS_CONFIG				    6
#define GB_TYPE_7_U_FIRE_DEV_CONFIG				    7
#define GB_TYPE_8_U_FIRE_SYS_TIME					8
#define GB_TYPE_21_U_UITD_STATUS					21
#define GB_TYPE_24_U_UITD_OPERATE					24
#define GB_TYPE_25_U_UITD_SW						25
#define GB_TYPE_26_U_UITD_CONFIG					26
#define GB_TYPE_28_U_UITD_TIME  					28
#define GB_TYPE_61_R_FIRE_SYS_STATUS			    61
#define GB_TYPE_62_R_FIRE_DEV_STATUS			    62
#define GB_TYPE_63_R_FIRE_DEV_ANALOG			    63
#define GB_TYPE_64_R_FIRE_DEV_OPERATE			    64
#define GB_TYPE_65_R_FIRE_SYS_SW					65
#define GB_TYPE_66_R_FIRE_SYS_CONFIG			    66
#define GB_TYPE_67_R_FIRE_DEV_CONFIG			    67
#define GB_TYPE_68_R_FIRE_SYS_TIME				    68
#define GB_TYPE_81_R_UITD_STATUS					81
#define GB_TYPE_84_R_UITD_OPERATE_LOG			    84
#define GB_TYPE_85_R_UITD_SW						85
#define GB_TYPE_86_R_UITD_CONFIG					86
#define GB_TYPE_88_R_UITD_TIME						88
#define GB_TYPE_89_C_UITD_INIT						89
#define GB_TYPE_90_C_UITD_SYNC						90
#define GB_TYPE_91_C_UITD_CHECK						91

#define JS_TYPE_128_ALIVE			        128
#define JS_TYPE_129_D_PUSH_FW_INFO 	        129
#define JS_TYPE_130_U_REQ_FW_DATA           130
#define JS_TYPE_131_D_ACK_FW_DATA           131
#define JS_TYPE_132_U_REQ_FW_INFO           132
#define JS_TYPE_133_D_ACK_FW_INFO           133
#define JS_TYPE_134_U_REQ_FILE_INFO         134
#define JS_TYPE_135_D_ACK_FILE_INFO         135
#define JS_TYPE_136_D_PUSH_FORCE_FW_INFO    136
#define JS_TYPE_137_D_PUSH_FORCE_FILE_INFO  137
#define JS_TYPE_138_D_REQ_FILE_INFO         138
#define JS_TYPE_139_U_ACK_FILE_INFO         139


#define JS_TYPE_140_U_SENSOR_DATA           140
#define JS_TYPE_141_D_SENSOR_DATA_CHECK     141
#define JS_TYPE_142_U_SENSOR_DATA_ACK       142
#define JS_TYPE_143_D_SENSOR_CFG_CHECK      143
#define JS_TYPE_144_U_SENSOR_CFG_ACK        144
#define JS_TYPE_145_D_SENSOR_CFG_SET        145
#define JS_TYPE_146_D_SENSOR_ID_CHECK       146
#define JS_TYPE_147_U_SENSOR_ID_ACK         147

#define JS_TYPE_150_D_OUTPUT_CTRL           150
#define JS_TYPE_151_D_OUTPUT_SEQ_ACTION     151
#define JS_TYPE_152_D_OUTPUT_CHECK          152
#define JS_TYPE_153_U_OUTPUT_CHECK_ACK      153

#define JS_TYPE_160_U_INPUT_REPORT          160
#define JS_TYPE_161_R_INPUT_STATE_CHECK     161
#define JS_TYPE_162_U_INPUT_STATE_ACK       162
#define JS_TYPE_163_D_INPUT_CFG_SET         163
#define JS_TYPE_164_R_INPUT_CFG_CHECK       164
#define JS_TYPE_165_U_INPUT_CFG_ACK         165

#define JS_TYPE_170_U_IOT_GW_INFO_REPORT    170
#define JS_TYPE_171_R_IOT_GW_INFO_CHECK     171
#define JS_TYPE_172_U_IOT_GW_INFO_ACK       172
#define JS_TYPE_173_D_IOT_GW_RESTART        173

#define JS_TYPE_180_D_IOT_GW_SCRIPT_EXECUTE 180
#define JS_TYPE_181_D_IOT_GW_SCRIPT_CHECK   181
#define JS_TYPE_182_D_IOT_GW_SCRIPT_REPORT  182

#define JS_TYPE_190_U_FILE_INFO_UPLOAD      190
#define JS_TYPE_191_R_FILE_DATA_REQUEST     191
#define JS_TYPE_192_U_FILE_DATA_ACK         192
#define JS_TYPE_193_R_DIR_REQUEST           193
#define JS_TYPE_194_U_DIR_ACK               194

#define JS_TYPE_200_U_ROUGH_DATA            200


#define GB_DEV_STATUS_DATA_MAX		        22


#define GB_SYS_TYPE_NORMAL						0
#define GB_SYS_TYPE_FIRE_ALARMER				1
#define GB_SYS_TYPE_LINKAGE_CTRL				10
#define GB_SYS_TYPE_FIRE_HYDRANT				11
#define GB_SYS_TYPE_SPRINKLER_OUTFIRE		    12
#define GB_SYS_TYPE_GAS_OUTFIRE					13
#define GB_SYS_TYPE_WATER_SPRAY_PUMP		    14
#define GB_SYS_TYPE_WATER_SPRAY_STRESS	        15
#define GB_SYS_TYPE_FOAM_OUTFIRE				16
#define GB_SYS_TYPE_DRY_POWDER_OUTFIRE	        17
#define GB_SYS_TYPE_SMOKE_EXTRACTION		    18
#define GB_SYS_TYPE_FIRE_DOOR					19
#define GB_SYS_TYPE_FIRE_ELEVATOR				20
#define GB_SYS_TYPE_FIRE_BROADCAST			    21
#define GB_SYS_TYPE_FIRE_LIGHT					22
#define GB_SYS_TYPE_FIRE_POWER					23
#define GB_SYS_TYPE_FIRE_TELEPHONE			    24

// Song: TODO: complete the whole device type defines.
#define GB_DEV_TYPE_NORMAL						0
#define GB_DEV_TYPE_FIRE_ALARMER				1
#define GB_DEV_TYPE_MANUL_ALARM_BUTTON          23
#define GB_DEV_TYPE_SOMKE_ALARMER				40
//#define GB_DEV_TYPE_
//#define GB_DEV_TYPE_
//#define GB_DEV_TYPE_

typedef int	(* fun_send_retry)(void *data, int node, int time);
typedef int	(* fun_send_fail)(void *data, int node);
typedef int	(* fun_send_success)(void *data, int node);
typedef int (* fun_send_data)(void *handler, int socket,char *data,int len);
typedef int (* fun_send_acked)(char *data,int len);

typedef int (* fun_ack_deal)(char *data,int len, uint8_t if_affirm);
typedef int (* fun_rec_file_data)(uint8_t *data, uint32_t len);







typedef enum
{
	GB_E_OK = 0,
	GB_E_LEN_LESS,
	GB_E_LEN_OVER,
	GB_E_ARG_ERR,
	GB_E_LEN_ERR,
	GB_E_CHECKSUM,
	GB_E_NULL,
	GB_E_BUF_WR,
	GB_E_OTHERS
	
} e_GB_err;

/*
typedef enum
{
	GB_trans_idle = 0,
	GB_trans_sended,
	GB_trans_ack,
	GB_trans_deny,
	GB_trans_need_return,
	
	GB_trans_completed
} e_GB_trans_status;
*/


typedef struct
{
    uint8_t     controller  :5;
    uint8_t     port        :3;
} PACK_STRUCT_STRUCT s_FS_sys_addr_SZJS;

typedef union
{
    s_FS_sys_addr_SZJS  SZJS_addr;
    uint8_t             sys_addr;
} PACK_STRUCT_STRUCT u_GB_fire_sys_addr;


typedef struct
{
	uint8_t	ver_main;
	uint8_t	ver_user;
	
} PACK_STRUCT_STRUCT	t_GB_ctrl_version;




typedef struct
{
	uint8_t addr[6];
	
} PACK_STRUCT_STRUCT	t_GB_ctrl_srcaddr;

typedef struct
{
	uint8_t addr[6];
	
} PACK_STRUCT_STRUCT	t_GB_ctrl_desaddr;



typedef struct
{
	uint16_t						SN;
	t_GB_ctrl_version		ver;
	t_GB_ctrl_timestamp	TS;
	t_GB_ctrl_srcaddr		src;
	t_GB_ctrl_desaddr		des;
	uint16_t						data_len;
	uint8_t							cmd;
	
} PACK_STRUCT_STRUCT t_GB_ctrl_unit;

typedef struct
{
	uint8_t 	type;
	uint8_t		num;
	uint32_t	data_len;
	void 			*data;
} t_GB_data_unit;


typedef struct
{
	t_GB_ctrl_unit	        ctrl;
	uint8_t					buf[GB_DATA_LEN_MAX];
	uint8_t 				checksum;
	
	uint8_t					data_type;
	uint8_t					data_num;
	
	t_GB_data_unit	        data_unit;
	
	int 				    socket;
	uint8_t					ack_cmd;
	fun_send_retry 			send_retry;
	fun_send_fail 			send_fail;
	fun_send_success 		send_success;
	fun_send_acked			send_acked;
//    fun_rec_file_data       rec_file_data;
	
	fun_ack_deal			ack_deal;
	
} t_GB_pkt;


typedef enum
{
	data_unit_start = 0,
	data_unit_normal,
	data_unit_single,
	data_unit_final
	
} e_GB_data_unit_status;

typedef enum
{
	UITD_status_working = 0,
	UITD_status_fire_alarm,
	UITD_status_fault,
	UITD_status_main_power,
	UITD_status_backup_power,
	UITD_status_server_discon,
	UITD_status_bus_discon
	
} e_GB_UITD_status;

typedef enum
{
	UITD_parse_idle = 0,
	UITD_parse_head,
	UITD_parse_data,
	UITD_parse_tail,
} e_parse_status;



typedef struct
{
	uint8_t					valid;
	e_parse_status	status;
	uint8_t 				buf[GB_ROUGH_BUF_MAX];
	uint32_t 				len;
	
} t_GB_parse;


typedef struct
{
	int 						socket;
	
	t_GB_ctrl_unit	ctrl;
	uint8_t					*buf;
	uint8_t					len;
	uint8_t 				checksum;

} t_GB_send;


typedef enum
{
	GB_NODE_unused = 0,
	GB_NODE_sending,
	GB_NODE_send_success,
	GB_NODE_send_fail,
	GB_NODE_send_acked
} e_node_status;


typedef enum
{
	cmd_acked_none = 0,
	cmd_acked_waiting,
	cmd_acked_affirm,
	cmd_acked_deny
} e_cmd_acked_status;

typedef int (* pFun_srv_report_IP)(void *handler, uint8_t *local_IP, uint16_t local_port, uint8_t *remote_IP, uint16_t remote_port);
typedef int (* pFun_srv_connected)(void *data);
typedef int (* pFun_srv_accepted)(void *data);

typedef int (* pFun_srv_disconnect)(void *handler, int socket);
typedef int (* pFun_srv_disconnected)(void *handler, void *data, int socket);

typedef int (* pFun_srv_connect_fail)(void *data);

typedef int (* pFun_srv_received)(void *handler, void *data, uint32_t len);
typedef int (* pFun_srv_rejected)(void *data);
typedef int (* pFun_srv_closed)(void *data);

typedef int (* pFun_srv_connect)(void *handler, uint8_t if_UDP, uint8_t if_use_name, uint8_t *IP, uint16_t port,
                                pFun_srv_connect_fail connect_fail,
                                pFun_srv_connected connected,
                                pFun_srv_disconnected disconnected,
                                pFun_srv_received received,
                                pFun_srv_rejected rejected,
                                pFun_srv_closed closed,
                                pFun_srv_report_IP
                                );

typedef int (* pFun_srv_listen)(uint8_t if_UDP, uint16_t listen_port, 
                                pFun_srv_accepted accepted,
                                pFun_srv_disconnected disconnected,
                                pFun_srv_received received,
                                pFun_srv_closed closed,
                                pFun_srv_report_IP
                                );

typedef struct
{
	e_node_status	node_status;
	
	uint32_t 			retry;
	uint32_t 			time;
	int 				socket;
    
//	e_GB_trans_status	status;
	t_GB_ctrl_unit		ctrl;
	uint8_t				*data;
	uint8_t 			checksum;
	
	uint8_t				if_active_send;
	e_cmd_acked_status	ack_status;
	
	fun_send_retry		send_retry;
	fun_send_fail			send_fail;
	fun_send_success	send_success;
	fun_send_acked		send_acked;
	
	fun_ack_deal		ack_deal;
		
} t_server_node;

typedef enum
{
    UITD_svc_status_idle = 0,
    UITD_svc_status_connect,
    UITD_svc_status_alive,
    UITD_svc_status_testing,
    UITD_svc_status_disconnected,
    UITD_svc_status_stoped
} e_UITD_svc_status;

typedef struct
{
    uint8_t     ID;
    uint8_t     out_type;
    uint16_t    data;
    t_GB_ctrl_timestamp timestamp;
} PACK_STRUCT_STRUCT s_sensor_rough_data;

typedef struct
{
    t_GB_ctrl_timestamp timestamp;
    uint16_t            total;
    uint16_t            index;
    uint16_t            len;
    uint8_t             data[TP_DATA_PKT_SIZE_MAX];
} PACK_STRUCT_STRUCT s_transparent_data;

typedef struct
{
    uint8_t dev_sample_ctrl :1;
    uint8_t dev_simple_UITD :1;
    uint8_t dev_controller  :1;
    uint8_t dev_full_func   :1;
    uint8_t dev_IOT_PRO_UITD:1;
    uint8_t dev_IOT_PRO_CTRL:1;
    uint8_t dev_res_17      :1;
    uint8_t dev_res_18      :1;

    uint8_t dev_res_21      :1;
    uint8_t dev_res_22      :1;
    uint8_t dev_res_23      :1;
    uint8_t dev_res_24      :1;
    uint8_t dev_res_25      :1;
    uint8_t dev_res_26      :1;
    uint8_t dev_res_27      :1;
    uint8_t dev_res_28      :1;
    
    uint8_t res_3           :8;    
    uint8_t res_4           :8;    
    //uint32_t    res         :28;  // CAUTION: must be 32-N  !!!
} PACK_STRUCT_STRUCT s_FW_support_dev;


typedef struct
{
    uint8_t             fw_ver_main;
    uint8_t             fw_ver_user;
    s_FW_support_dev    support_dev;
    uint8_t             name[FW_NAME_LEN_MAX];
    int32_t             len;
    uint16_t            CRC16;
} PACK_STRUCT_STRUCT s_FW_info;

typedef struct
{
    uint8_t             fw_ver_main;
    uint8_t             fw_ver_user;
    s_FW_support_dev    support_dev;
} PACK_STRUCT_STRUCT s_FW_info_req;

typedef struct
{
    uint8_t             name[FW_NAME_LEN_MAX];
} PACK_STRUCT_STRUCT s_file_info_req;

//typedef struct
//{
//    uint8_t             name[FW_NAME_LEN_MAX];
//    uint32_t            length;
//    uint16_t            CRC16;
//} PACK_STRUCT_STRUCT s_file_upload_info;

typedef struct
{
    uint8_t             name[FW_NAME_LEN_MAX];
    int32_t             length;
    uint16_t            CRC16;
} PACK_STRUCT_STRUCT s_file_info_ack;

typedef struct
{
    uint8_t     name[FW_NAME_LEN_MAX];
    uint32_t    index;
    int16_t     len;
    uint16_t    CRC16;
} PACK_STRUCT_STRUCT s_FW_DATA;

typedef struct
{
    uint8_t     name[FW_NAME_LEN_MAX];
    uint32_t    index;
    int16_t     len;
} PACK_STRUCT_STRUCT s_file_DATA;

typedef struct
{
    uint8_t     name[FW_NAME_LEN_MAX];
    uint32_t    index;
    int16_t     len;
    uint16_t    CRC16;
} PACK_STRUCT_STRUCT s_file_DATA_ack;

typedef struct
{
    uint8_t     name[FW_NAME_LEN_MAX];
    uint32_t    index;
    int16_t     len;
} PACK_STRUCT_STRUCT s_FW_DATA_req;

typedef struct
{
    uint8_t             ID;
    uint8_t             trig;
    uint16_t            period; // unit: S
} PACK_STRUCT_STRUCT s_IO_input_cfg;


typedef enum
{
    FW_idle = 0,
    FW_init,
    FW_fetch,
    FW_failed,
    FW_done,
    FW_error,
    FW_stop,
    FW_stoped
} e_FW_status;


typedef int (* pFun_file_open)(uint8_t *filename);
typedef int (* pFun_file_write)(int fd, uint8_t *data, uint32_t len);
typedef int (* pFun_file_close)(int fd);
typedef int (* pFun_file_down_success)(void *data);
typedef int (* pFun_file_down_fail)(void *data);


//typedef struct // totally 31 bytes.
//{
//    int32_t    reserved;   
//    int16_t    port;
//    int16_t    controller;
//    int32_t    loop;
//    int64_t    device_ID;
//    uint8_t     res[11];
//} PACK_STRUCT_STRUCT s_fire_dev_status_info; 

typedef struct // totally 31 bytes.
{
    int32_t     reserved;   								//保留字段
    int16_t     port;												//网关端口号
    int16_t     controller;									//控制器号
    int32_t     loop;												//回路号
    int64_t     device_ID;									//设备编号
    int32_t     device_port;								//设备端口号
    uint8_t     res[7];											//保留字段 7个字节
} PACK_STRUCT_STRUCT s_fire_dev_status_info; 


typedef struct
{
    e_FW_status     status;
    s_FW_info       FW;
    uint32_t        req_index;
    uint32_t        req_pkt_len;
    uint32_t        req_pkt_num;
    uint32_t        rec_index;
    uint32_t        rec_pkt_len;
    uint32_t        rec_pkt_num;
    uint16_t        pkt_CRC16;
    
    uint8_t         push_FW_flag;
    uint8_t         force_FW_flag;
    uint8_t         return_FW_flag;
    uint8_t         force_file_flag;
    
    uint8_t         FW_upgrade_success;
    uint8_t         FW_upgrade_failed;
    
    s_FW_DATA_req   data_req;
    s_FW_DATA       data_rec;
//    uint8_t         *data;
    
    uint8_t         fw_path[48];
    int             fw_fd;
    pFun_file_open  file_open;
    pFun_file_write file_write;
    pFun_file_close file_close;
    
    pFun_file_down_success  file_down_success;
    pFun_file_down_fail     file_down_fail;
    
} s_FW_update;

typedef enum
{
    sensor_out_type_general = 0,
    sensor_out_type_4_20mA  = 1,
    sensor_out_type_5V      = 2,
    sensor_out_type_Hz      = 3,
} e_sensor_out_type;

typedef enum
{
    output_action_disconn = 0,
    output_action_connect = 1,
    output_action_toggle = 2,
    output_action_disconn_delay = 3,
    output_action_connect_delay = 4,
    output_action_just_delay = 5,

} e_output_action;

typedef struct
{
    uint8_t             ID;
    e_output_action     action;
    uint32_t            delay;

} PACK_STRUCT_STRUCT s_output_data;

typedef struct
{
    uint8_t     ID;
    uint8_t     action;
    uint32_t    delay;
} PACK_STRUCT_STRUCT s_output_state;

 

typedef struct
{
    uint8_t         valid;
    uint8_t         num;
    uint8_t         ID[OUTPUT_CHANNEL_MAX];
    s_output_data   data[OUTPUT_CHANNEL_MAX];
} s_output_cb;

typedef struct
{
    uint8_t                 valid;
    uint8_t                 num;
    uint8_t                 ID[INPUT_CHANNEL_MAX];
    s_IO_input_cfg_report   cfg[INPUT_CHANNEL_MAX];   
} s_input_cb;



typedef struct
{
    uint8_t     restart;
    uint32_t    restart_cnt;
    uint8_t     shutdown;
    uint32_t    shutdown_cnt;
} s_AP_ctrl;


typedef struct
{
    uint8_t     if_valid;
    uint32_t    index;
    uint32_t    len;
    uint8_t     data[FW_PKT_LEN_DEFAULT];
} s_file_data_pkt;

typedef struct
{
//    s_file_data_pkt     data_pkt[FILE_DATA_BUF_NUM];
    s_file_data_pkt     *data_buf;
    int                 buf_index;
    int                 store_index;
    int                 waiting_num;
    uint8_t             data_buf_num;
} s_file_trans_cb;


typedef struct
{
    uint8_t     name[FW_NAME_LEN_MAX];
    int32_t     len;
    
} s_JS_info;


typedef struct
{
//	uint8_t  full;
//	uint32_t used;
    e_UITD_svc_status   status;
    uint32_t            alive_cnt;
    
	t_server_node 		node[GB_SERVER_NODE_MAX];
	fun_send_data			send_data;
	uint8_t 					send_buf[GB_ROUGH_LEN_MAX];
	uint32_t 					data_len;

    uint8_t             if_connected;  // 0: not connected, 1: connected, 2: alive,
    uint8_t             if_disconnected;
    int                 socket;
    
    pFun_srv_connect        connect;
    pFun_srv_connected      connected;
    pFun_srv_disconnect     disconnect;
    pFun_srv_disconnected   disconnected;
    pFun_srv_connect_fail   connect_fail;
    pFun_srv_received       received;
    pFun_srv_rejected       rejected;
    pFun_srv_closed         closed;
    pFun_srv_listen         listen;
    pFun_srv_accepted       accepted;
    pFun_srv_report_IP      report_IP;
    
    
    uint8_t             if_UDP;
    uint8_t             if_use_name;
    uint8_t             svr_name[SVR_IF_NAME_LEN];
    uint8_t             IP[4];
    uint16_t            port;
    uint16_t            listen_port;
    uint8_t             local_IP[4];
    uint16_t            local_port;
	
    uint8_t                     if_testing_mode;
	uint8_t						sys_addr[6];
	uint8_t						server_addr[6];
	uint16_t					send_SN;
	
	uint8_t						ver_main;
	uint8_t						ver_user;
    
    struct rt_ringbuffer        ring_buf;
    uint8_t                     ring_buf_buf[GB_ROUGH_BUF_MAX];
	
    t_GB_parse      GB_parse;
    t_GB_pkt        GB_pkt_rec;
    t_GB_pkt        GB_pkt_send;
    uint8_t         GB_pkt_buff[GB_PACKET_LEN_MAX];
    
    s_file_trans_cb     *file_trans;
    
    s_FW_update         FW;
    s_FW_support_dev    dev_type;
    
    s_JS_info           JS;
    
    s_input_cb          input;
    s_output_cb         output;
    s_AP_ctrl           AP_ctrl;
    uint8_t             if_UITD;
    
} t_server_handler;


typedef struct
{
	uint8_t		if_working 	  :1;
	uint8_t		if_fire 	  :1;
	uint8_t		if_fault 	  :1;
	uint8_t		if_disable	  :1;
	uint8_t		if_supervise  :1;
	uint8_t		if_run		  :1;
	uint8_t		if_feedback	  :1;
	uint8_t		if_delaying	  :1;
	uint8_t		if_main_pwr   :1;
	uint8_t		if_backup_pwr :1;
	uint8_t		if_bus_fault  :1;
	uint8_t		if_manul_state:1;
	uint8_t		if_cfg_change :1;
	uint8_t		if_reset      :1;
	uint8_t		reserve_6     :1;
	uint8_t		reserve_7     :1;

} PACK_STRUCT_STRUCT	t_GB_fire_sys_status;

typedef struct
{
	uint8_t		reset 	        :1;
	uint8_t		silent 	        :1;
	uint8_t		manual_alarm 	:1;
	uint8_t		disalarm        :1;
	uint8_t		selftest        :1;
	uint8_t		affirm		    :1;
	uint8_t		testing	        :1;
	uint8_t		reserved	    :1;

} PACK_STRUCT_STRUCT	t_GB_fire_sys_operate;

typedef struct
{
	uint8_t		if_working 	  :1;
	uint8_t		if_fire 	  :1;
	uint8_t		if_fault 	  :1;
	uint8_t		if_disable	  :1;
	uint8_t		if_supervise  :1;
	uint8_t		if_run		  :1;
	uint8_t		if_feedback	  :1;
	uint8_t		if_delaying	  :1;
	uint8_t		if_power_fault:1;
	uint8_t		reserve_1     :1;
	uint8_t		reserve_2     :1;
	uint8_t		reserve_3     :1;
	uint8_t		reserve_4     :1;
	uint8_t		reserve_5     :1;
	uint8_t		reserve_6     :1;
	uint8_t		reserve_7     :1;

} PACK_STRUCT_STRUCT	t_GB_dev_status;



typedef union
{
	uint16_t			status_16;
	t_GB_dev_status		status_struct;

}	u_dev_status;


typedef enum
{
    fire_dev_status_working = 0,
    fire_dev_status_smoke_alarm,
    fire_dev_status_smoke_fault,
    fire_dev_status_smoke_disable,
    fire_dev_status_smoke_resume,
} e_fire_dev_status;

typedef struct
{
	uint8_t 						sys_type;
	//uint8_t							sys_addr;
	u_GB_fire_sys_addr              sys_addr;
    uint8_t							type;
	uint8_t							addr[4];
	t_GB_dev_status			        status;
    s_fire_dev_status_info          dev_info;
	//uint8_t							remark[31];
	t_GB_ctrl_timestamp	timestamp;
} PACK_STRUCT_STRUCT t_GB_dev_status_data;


typedef struct
{
	uint8_t		if_working 			:1;
	uint8_t		if_fire 				:1;
	uint8_t		if_fault 				:1;
	uint8_t		if_main_power		:1;
	uint8_t		if_backup_power :1;
	uint8_t		if_server_discon:1;
	uint8_t		if_bus_discon		:1;
	uint8_t		reserve	  			:1;

} PACK_STRUCT_STRUCT	t_GB_UITD_status;

typedef struct
{
	uint8_t		reset 	        :1;
	uint8_t		silent 	        :1;
	uint8_t		manual_alarm 	:1;
	uint8_t		disalarm        :1;
	uint8_t		selftest        :1;
	uint8_t		inspect_affirm  :1;
	uint8_t		testing	        :1;
	uint8_t		reserved	    :1;
    
} PACK_STRUCT_STRUCT	t_GB_UITD_operate;


typedef struct
{
	t_GB_UITD_status 		status;
	t_GB_ctrl_timestamp	timestamp;
} PACK_STRUCT_STRUCT t_GB_UITD_status_data;





typedef struct
{
    uint8_t                     sys_type;
    //uint8_t                     sys_addr;
    u_GB_fire_sys_addr          sys_addr;
	t_GB_fire_sys_status 		status;
	t_GB_ctrl_timestamp	        timestamp;
} PACK_STRUCT_STRUCT t_GB_fire_sys_status_data;


typedef struct
{
	t_GB_UITD_operate    		operate;
    uint8_t                     operator_ID;
	t_GB_ctrl_timestamp	        timestamp;
} PACK_STRUCT_STRUCT t_GB_UITD_operate_data;


typedef struct
{
    uint8_t                     sys_type;
    u_GB_fire_sys_addr          sys_addr;
	t_GB_fire_sys_operate 		operate;
    uint8_t                     operator_ID;
	t_GB_ctrl_timestamp	        timestamp;
} PACK_STRUCT_STRUCT t_GB_fire_sys_operate_data;
//typedef struct
//{
//    uint8_t             ID;
//    e_sensor_out_type   out_type;
//    uint16_t            data_rough;
//} s_sensor_data_report;

typedef struct
{
    uint8_t     ID;
    uint32_t    period;
} PACK_STRUCT_STRUCT s_sensor_cfg_report;

typedef struct
{
    uint8_t             ID;
    e_sensor_out_type   out_type;
} PACK_STRUCT_STRUCT s_sensor_ID_report;


typedef struct
{
    uint8_t             SN[6];
    uint8_t             IP[4];
    uint16_t            port;
    uint8_t             ver_main;
    uint8_t             ver_sub;
    s_FW_support_dev    dev_type;    

} PACK_STRUCT_STRUCT s_IOT_GW_info;


typedef const struct
{
    e_dev_type  dev_type;
    uint8_t     CMD_list_num;
    uint8_t     CMD_list[256];
} s_dev_cmd_list;


extern s_dev_cmd_list device_cmd_list[];


//extern s_FW_update  FW_update;
extern s_file_trans_cb file_trans_cb;



extern uint8_t	g_UITD_addr[6];
extern uint64_t g_UITD_SN;

//-------------------松江3208 协议配套 用户信息传输装置
extern int UITD_SJ3208_send_pkg(t_server_handler *handler, int node);

extern int UITD_send_pkg(t_server_handler *handler, int node);
//-------------------
	
extern e_GB_err UITD_server(t_server_handler *handler);
extern int UITD_send_handler(t_server_handler *handler);
extern int UITD_send_data(t_server_handler *handler,
                    t_GB_pkt *pkt, 
                    t_GB_data_unit *data_unit,
					uint8_t	if_active_send);
extern int UITD_send_ack(t_server_handler *handler,
                    t_GB_pkt *pkt, 
					t_GB_data_unit *data_unit);
extern int UITD_transparent_send_data(t_server_handler *handler, s_transparent_data *data);


extern int UITD_file_trans_init(t_server_handler *handler, s_file_trans_cb *file_trans, uint8_t buf_num);
extern int UITD_connect(t_server_handler *handler, uint8_t if_UDP, uint8_t if_use_name, uint8_t *IP, uint16_t port, uint16_t listen_port);

extern t_server_handler *UITD_init(fun_send_data send_data, 
                            pFun_srv_connect connect, 
                            pFun_srv_connected connected,
                            pFun_srv_disconnect disconnect,
                            pFun_srv_disconnected disconnected,
                            pFun_srv_connect_fail connect_fail,
                            pFun_srv_received received,
                            pFun_srv_rejected rejected,
                            pFun_srv_closed closed,
                            pFun_srv_listen listen,
                            pFun_srv_accepted accepted,
                            pFun_srv_report_IP report_IP
                            );



extern int UITD_CMD_if_support(e_dev_type dev_type, uint8_t CMD);
extern int UITD_sensor_upload_rough_data(t_server_handler *handler, uint8_t ID, uint8_t out_type, uint16_t data, t_GB_ctrl_timestamp *TS);

#endif // __UITD_H__


