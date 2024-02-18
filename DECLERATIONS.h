/* 
 * File:   DECLERATIONS.h
 * Author: el msria
 *
 * Created on February 16, 2024, 12:13 AM
 */

#ifndef DECLERATIONS_H
#define	DECLERATIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ECU_LAYER/K_PAD/K_PAD.h"
#include "ECU_LAYER/LCD/LCD.h"    
#include "ECU_LAYER/LED/LED.h"
#include "ECU_LAYER/MOTOR/MOTOR.h"

    
///K_PAD_DECLERATION////////////////////////////////////////////////////////////    
k_pad_t k1 = {
 
 

.K_PAD_PINS_ROWS[0].pin_direction =OUTPUT ,.K_PAD_PINS_ROWS[0].pin_num = 0 ,
.K_PAD_PINS_ROWS[0].pin_port =PORTD_INDEX ,.K_PAD_PINS_ROWS[0].pin_state = LOW ,

.K_PAD_PINS_ROWS[1].pin_direction =OUTPUT ,.K_PAD_PINS_ROWS[1].pin_num = 1 ,
.K_PAD_PINS_ROWS[1].pin_port =PORTD_INDEX ,.K_PAD_PINS_ROWS[1].pin_state = LOW ,

.K_PAD_PINS_ROWS[2].pin_direction =OUTPUT ,.K_PAD_PINS_ROWS[2].pin_num = 2 ,
.K_PAD_PINS_ROWS[2].pin_port =PORTD_INDEX ,.K_PAD_PINS_ROWS[2].pin_state = LOW ,

.K_PAD_PINS_ROWS[3].pin_direction =OUTPUT ,.K_PAD_PINS_ROWS[3].pin_num = 3 ,
.K_PAD_PINS_ROWS[3].pin_port =PORTD_INDEX ,.K_PAD_PINS_ROWS[3].pin_state = LOW ,

.K_PAD_PINS_COLOMS[0].pin_direction =INPUT , .K_PAD_PINS_COLOMS[0].pin_num = 4 ,
.K_PAD_PINS_COLOMS[0].pin_port =PORTD_INDEX ,.K_PAD_PINS_COLOMS[0].pin_state = LOW ,

.K_PAD_PINS_COLOMS[1].pin_direction =INPUT , .K_PAD_PINS_COLOMS[1].pin_num = 5 ,
.K_PAD_PINS_COLOMS[1].pin_port =PORTD_INDEX ,.K_PAD_PINS_COLOMS[1].pin_state = LOW ,

.K_PAD_PINS_COLOMS[2].pin_direction =INPUT , .K_PAD_PINS_COLOMS[2].pin_num = 6 ,
.K_PAD_PINS_COLOMS[2].pin_port =PORTD_INDEX ,.K_PAD_PINS_COLOMS[2].pin_state = LOW ,

.K_PAD_PINS_COLOMS[3].pin_direction =INPUT , .K_PAD_PINS_COLOMS[3].pin_num = 7 ,
.K_PAD_PINS_COLOMS[3].pin_port =PORTD_INDEX ,.K_PAD_PINS_COLOMS[3].pin_state = LOW , 

 
 }; 
/***********************************************************************************/


///LCD_DECLERATION///////////////////////////////////////////////////////////////////
lcd_8bit_t lcd1 ={
.data_pins[0].pin_direction = OUTPUT , .data_pins[0].pin_num =0 ,
.data_pins[0].pin_port =PORTB_INDEX  , .data_pins[0].pin_state =HIGH ,

.data_pins[1].pin_direction = OUTPUT , .data_pins[1].pin_num =1 ,
.data_pins[1].pin_port =PORTB_INDEX  , .data_pins[1].pin_state =HIGH ,

.data_pins[2].pin_direction = OUTPUT , .data_pins[2].pin_num =2 ,
.data_pins[2].pin_port =PORTB_INDEX  , .data_pins[2].pin_state =HIGH ,

.data_pins[3].pin_direction = OUTPUT , .data_pins[3].pin_num =3 ,
.data_pins[3].pin_port =PORTB_INDEX  , .data_pins[3].pin_state =HIGH ,

.data_pins[4].pin_direction = OUTPUT , .data_pins[4].pin_num =4 ,
.data_pins[4].pin_port =PORTB_INDEX  , .data_pins[4].pin_state =HIGH ,

.data_pins[5].pin_direction = OUTPUT , .data_pins[5].pin_num =5 ,
.data_pins[5].pin_port =PORTB_INDEX  , .data_pins[5].pin_state =HIGH ,

.data_pins[6].pin_direction = OUTPUT , .data_pins[6].pin_num =6 ,
.data_pins[6].pin_port =PORTB_INDEX  , .data_pins[6].pin_state =HIGH ,

.data_pins[7].pin_direction = OUTPUT , .data_pins[7].pin_num =7 ,
.data_pins[7].pin_port =PORTB_INDEX  , .data_pins[7].pin_state =HIGH ,

.rs_pin.pin_direction = OUTPUT , .rs_pin.pin_num = 6 ,
.rs_pin.pin_port = PORTC_INDEX , .rs_pin.pin_state = HIGH ,

.enable_pin.pin_direction = OUTPUT , .enable_pin.pin_num =7 ,
.enable_pin.pin_port = PORTC_INDEX , .enable_pin.pin_state =HIGH ,   
};
/**********************************************************************************/    


///MOTOR_DECLERATION////////////////////////////////////////////////////////////////
motor_t motor1 ={
.motor[0].motor_pin = PIN0 ,
.motor[0].motor_port = PORTC_INDEX ,
.motor[0].motor_state =HIGH ,
.motor[1].motor_pin = PIN1 ,
.motor[1].motor_port = PORTC_INDEX ,
.motor[1].motor_state =HIGH ,

} ;
/**********************************************************************************/


///LED_DECLERATION/////////////////////////////////////////////////////////////////
led_t led1 ={
  .led_state_t = LED_OFF ,
  .pin_num =PIN2 ,
  .port_name =PORTC_INDEX} ;

/*********************************************************************************/

///LED_DECLERATION/////////////////////////////////////////////////////////////////
led_t led2 ={
  .led_state_t = LED_OFF ,
  .pin_num =PIN3 ,
  .port_name =PORTC_INDEX} ;

/*********************************************************************************/




///FUNCTIONS DECLERATIONS////////////////////////////////////////////////////////
void welcoming(void) ;
void pass_is_right(void) ;
void pass_is_wrong(void) ;
void get_pass(void) ;
void check_process(void) ;
void check_pass(void);
void change_pass(void);
/********************************************************************************/

#ifdef	__cplusplus
}
#endif

#endif	/* DECLERATIONS_H */

