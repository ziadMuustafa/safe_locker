/* 
 * File:   MOTOR.h
 * Author: el msria
 *
 * Created on October 31, 2023, 7:21 PM
 */

#ifndef MOTOR_H
#define	MOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

//INCLUDES
 #include "MOTOR_CFG.h"
 #include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"

 //MACROS
  #define MOTOR_ON 1
  #define MOTOR_OFF 0

 //USER DEFINED DATA TYPES 
    typedef struct{
        uint8 motor_pin  : 3 ;
        uint8 motor_port : 3 ;
        uint8 motor_state  : 3 ;
    }motor_pin_t; 

    typedef struct{
    motor_pin_t motor[2] ;

    }motor_t; 

 //FUNCTIONS DECLERATIONS 
 Std_ReturnType motor_init(const motor_t *motor) ;  
 Std_ReturnType motor_move_right(const motor_t *motor) ;  
 Std_ReturnType motor_move_left(const motor_t *motor) ;  
 Std_ReturnType motor_stop(const motor_t *motor) ;  




#ifdef	__cplusplus
}
#endif

#endif	/* MOTOR_H */

