#include "fire_alarm.h"
#include "sys_config.h"
//#include <stdio.h>
#include <rtdevice.h>
#include "board.h"

struct rt_device * device_FAC; 

static uint32_t  cmd_status = 0;
static uint8_t *remark = 0;

static uint8_t data_trans[256] = {0};
static uint32_t data_trans_len = 0;

static uint8_t *p_data_meta = NULL;
static uint8_t  data_meta_num = 0;

const uint8_t FAC_alarm_head[] = {0x0D, 0xDD};
const uint8_t FAC_fault_head[] = {0x0E, 0xEE};
const uint8_t FAC_reset_head[] = {0x0A, 0xAA};

const uint8_t FAC_tail_buf[] = {0xBB};

static uint8_t	FAC_2nd_ID[4] = {0};
static uint8_t  FAC_status = 0;

static uint8_t	FAC_controller_ID = 0;

#define FAC_MSG_TYPE_NONE  		0
#define FAC_MSG_TYPE_ALARM		1
#define FAC_MSG_TYPE_FAULT		2
#define FAC_MSG_TYPE_RESET		3


static uint8_t	FAC_msg_type = FAC_MSG_TYPE_NONE;	




s_com_bus_cfg FAC_com_cfg = {2400, 8, PARITY_NONE, 1};




int FAC_unusual_rx_handler(s_com_bus_cb * cb);


int FAC_unusual_rx_init(s_com_bus_cb * cb)
{
	
	rt_memcpy(&cb->FAC_config.cfg, &FAC_com_cfg, sizeof(s_com_bus_cfg));
	//cb->FA_listen = 1;
	return 0;
}


int FAC_unusual_rx_parser(s_com_bus_cb * cb)
{
    //uint8_t data = 0x00;
    uint8_t data_temp = 0x00;
    int res = 0;
    
    while(1)
    {
        res = rt_device_read(cb->dev, 0, &data_temp, 1);
        if (res < 1)
        {
            return -1;
        }
        cb->rec_buf[cb->rec_len] = data_temp;
        cb->rec_len ++;

				switch (cb->parse.status)
				{
					case FAC_parse_idle:
		                
		                if (cb->rec_len >= 3) // -- 01 0A AA   -- 01 0E EE
		                {
		                    if (rt_memcmp(&cb->rec_buf[cb->rec_len - sizeof(FAC_alarm_head)], 
		                                    FAC_alarm_head, 
		                                    sizeof(FAC_alarm_head)) == 0)
		                    {
		                        rt_memcpy(cb->parse.buf, FAC_alarm_head, sizeof(FAC_alarm_head));
		                        cb->parse.len = sizeof(FAC_alarm_head);
		                        cb->parse.status = FAC_parse_data;
		                        FAC_controller_ID = cb->rec_buf[cb->rec_len - sizeof(FAC_alarm_head) - 1];
		                        FAC_msg_type = FAC_MSG_TYPE_ALARM;
		                    }
		                    else if (rt_memcmp(&cb->rec_buf[cb->rec_len - sizeof(FAC_fault_head)], 
		                                    FAC_fault_head, 
		                                    sizeof(FAC_fault_head)) == 0)
		                    {
		                        rt_memcpy(cb->parse.buf, FAC_fault_head, sizeof(FAC_fault_head));
		                        cb->parse.len = sizeof(FAC_fault_head);
		                        cb->parse.status = FAC_parse_data;
		                        FAC_controller_ID = cb->rec_buf[cb->rec_len - sizeof(FAC_alarm_head) - 1];
		                        FAC_msg_type = FAC_MSG_TYPE_FAULT;
		                    }
		                    // controller reset : 0A AA BB. 
		                    else if (rt_memcmp(&cb->rec_buf[cb->rec_len - sizeof(FAC_reset_head)], 
		                                    FAC_reset_head, 
		                                    sizeof(FAC_reset_head)) == 0)
		                    {
		                        rt_memcpy(cb->parse.buf, FAC_reset_head, sizeof(FAC_reset_head));
		                        cb->parse.len = sizeof(FAC_reset_head);
		                        cb->parse.status = FAC_parse_data;
		                        FAC_controller_ID = cb->rec_buf[cb->rec_len - sizeof(FAC_alarm_head) - 1];
		                        FAC_msg_type = FAC_MSG_TYPE_RESET;
		                    }
		                    else
		                    {
		                        if (cb->rec_len > COM_BUS_REC_MAX/2)
		                        {
		                            cb->rec_len = 0;
		                        }
		                    }
		                }
						break;
					case FAC_parse_data:
		                //if (cb->FAC_config.alarm.tail.if_tail)
		                {
		                    cb->parse.buf[cb->parse.len] = data_temp;
		                    cb->parse.len ++;
		                    
		                    if (cb->parse.len >= sizeof(cb->parse.buf))
		                    {
		                        cb->rec_len = 0;
		                        cb->parse.len = 0;
		                        cb->parse.status = FAC_parse_idle;
		                        break;
		                    }
		                    
		                    if (cb->parse.len >= (sizeof(FAC_alarm_head) + sizeof(FAC_tail_buf)))
		                    {
		                        if (rt_memcmp(&cb->parse.buf[cb->parse.len - sizeof(FAC_tail_buf)], 
		                                       FAC_tail_buf,
		                                       sizeof(FAC_tail_buf)) == 0)
		                        {
		                            
		                            cb->rec_len = 0;
		                            cb->parse.status = FAC_parse_idle;
		                            cb->parse.valid = 1;
		                            return 0;
		                        }
		                        
		                    }
		                    
		                }
						break;
					case FAC_parse_tail:
						
						break;
		      case FAC_parse_end:
		                break;
					default:
						
						break;
				}
        
    
    }
    
    
    
    return -1;		
}




int GST_CRT_parse(s_com_bus_cb * cb, uint8_t *data, uint32_t len)
{
	int i = 0;
	
  
  if (FAC_msg_type == FAC_MSG_TYPE_ALARM)
  {
  	
			FAC_2nd_ID[0] = data[2];
			FAC_2nd_ID[1] = data[3];
			FAC_2nd_ID[2] = data[4];
			FAC_2nd_ID[3] = data[5];
		
		  FAC_status = data[6];
  	
  		if ((FAC_2nd_ID[3] <= 0x11) && (FAC_status == 0x01))
  		{
						cb->alarm_fire.valid = 1;
						cb->alarm_fire.sys_addr = FAC_controller_ID;
						cb->alarm_fire.addr_sub = 0x00 + FAC_2nd_ID[0]*256;
						cb->alarm_fire.addr_main = FAC_2nd_ID[1] + FAC_2nd_ID[2]*256;
//						cb->alarm_fire.addr_sub = FAC_2nd_ID[0] + FAC_2nd_ID[1]*256;
//						cb->alarm_fire.addr_main = FAC_2nd_ID[2] + FAC_2nd_ID[3]*256;
						
						//rt_memcpy(cb->alarm_fire.remark, &data[2], 5);

						fire_alarm_struct_init(&cb->alarm_fire.dev_info);
						cb->alarm_fire.dev_info.port = cb->port;
						cb->alarm_fire.dev_info.controller = FAC_controller_ID;
						cb->alarm_fire.dev_info.loop = FAC_2nd_ID[1] + FAC_2nd_ID[2]*256;
						cb->alarm_fire.dev_info.device_ID = 0x00 + FAC_2nd_ID[0]*256;
						
		  			FA_mq_fire(&cb->alarm_fire, sizeof(s_com_bus_R_alarm));
		  			FA_mq_fire_2(&cb->alarm_fire, sizeof(s_com_bus_R_alarm));
		  			
						SYS_log(SYS_DEBUG_INFO,("FireAlarm device %02X %02X %02X %02X     ALARM .\n Controller ID : %d \n\n", 
																	FAC_2nd_ID[0], FAC_2nd_ID[1], FAC_2nd_ID[2], FAC_2nd_ID[3], FAC_controller_ID));
  		}	
  		
  }
  else if (FAC_msg_type == FAC_MSG_TYPE_FAULT)
  {
			FAC_2nd_ID[0] = data[2];
			FAC_2nd_ID[1] = data[3];
			FAC_2nd_ID[2] = data[4];
			FAC_2nd_ID[3] = data[5];
		
		  FAC_status = data[6];

  		if (FAC_status == 0x00)
  		{
						cb->alarm_fault.valid = 1;
						cb->alarm_fault.sys_addr = FAC_controller_ID;
						cb->alarm_fault.addr_sub = 0x00 + FAC_2nd_ID[0]*256;
						cb->alarm_fault.addr_main = FAC_2nd_ID[1] + FAC_2nd_ID[2]*256;
//						cb->alarm_fault.addr_sub = FAC_2nd_ID[0] + FAC_2nd_ID[1]*256;
//						cb->alarm_fault.addr_main = FAC_2nd_ID[2] + FAC_2nd_ID[3]*256;
						
						//rt_memcpy(cb->alarm_fault.remark, &data[2], 5);

						fire_alarm_struct_init(&cb->alarm_fault.dev_info);
						cb->alarm_fault.dev_info.port = cb->port;
						cb->alarm_fault.dev_info.controller = FAC_controller_ID;
						cb->alarm_fault.dev_info.loop = FAC_2nd_ID[1] + FAC_2nd_ID[2]*256;
						cb->alarm_fault.dev_info.device_ID = 0x00 + FAC_2nd_ID[0]*256;
							
				  	FA_mq_fault(&cb->alarm_fault, sizeof(s_com_bus_R_alarm));
				  	FA_mq_fault_2(&cb->alarm_fault, sizeof(s_com_bus_R_alarm));

						SYS_log(SYS_DEBUG_INFO,("FireAlarm device %02X %02X %02X %02X     FAULT .\n Controller ID : %d \n\n", 
														FAC_2nd_ID[0], FAC_2nd_ID[1], FAC_2nd_ID[2], FAC_2nd_ID[3], FAC_controller_ID));
  					
  		}
  		
  }
  else if (FAC_msg_type == FAC_MSG_TYPE_RESET)
  {
			cb->alarm_reset.valid = 1;
			cb->alarm_reset.port = cb->port;
			cb->alarm_reset.sys_addr = FAC_controller_ID;
							
			FA_mq_reset(&cb->alarm_reset, sizeof(s_com_bus_R_reset));
			FA_mq_reset_2(&cb->alarm_reset, sizeof(s_com_bus_R_reset));

		  SYS_log(SYS_DEBUG_INFO,("Controller reset : %d.         RESET .\n\n", FAC_controller_ID));
  		
  }

	return 0;
}



int FAC_unusual_rx_handler(s_com_bus_cb * cb)
{

    int res = 0;
    
    if (cb->parse.valid)
    {
        cb->parse.valid = 0;
        
        res = GST_CRT_parse(cb, cb->parse.buf, cb->parse.len);
        

    }
    
    return 0;
}

int FAC_unusual_server(s_com_bus_cb *cb)
{

    

    return 0;
}
