/* 
 * File:   LED.h
 * Author: el msria
 *
 * Created on October 31, 2023, 6:58 PM
 */

#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C" {
#endif

// MACROS
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
#include "LED_CFG.h"



//DATA TYPES DECLERATIONS
typedef enum {
    LED_OFF ,
    LED_ON ,

}led_state;

typedef struct {
    uint8 port_name : 4 ; 
    uint8 pin_num : 3 ;
    uint8 led_state_t :1 ;


} led_t; 




//FUNCTIONS DECLERATIONS
Std_ReturnType led_init(led_t *ptr) ;
Std_ReturnType led_turn_on(led_t *ptr) ;
Std_ReturnType led_turn_off(led_t *ptr) ;
Std_ReturnType led_toggle(led_t *ptr) ;





#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

