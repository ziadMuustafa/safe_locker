#include "C:\EMBEDDED_SYSTEMS\PIC\pic.X\ECU_LAYER\MOTOR\MOTOR.h"
#include <stdio.h>
Std_ReturnType ret = E_OK ;

////////////////////////////////////////////////////////////
 Std_ReturnType motor_init(const motor_t *motor) {
   if(motor == NULL){ret =E_NOT_OK ;}    
   else{
        pin_config MotorPin1 ={
       .pin_direction = OUTPUT ,
       .pin_num = motor->motor[0].motor_pin ,
       .pin_port = motor->motor[0].motor_port ,
       .pin_state = motor->motor[0].motor_state
      
       };
        pin_config MotorPin2 ={
       .pin_direction = OUTPUT ,
       .pin_num = motor->motor[1].motor_pin ,
       .pin_port = motor->motor[1].motor_port ,
       .pin_state = motor->motor[1].motor_state
      
       };       
   
        gpio_pin_init(&MotorPin1) ;
        gpio_pin_init(&MotorPin2) ;

   }
     return ret ;                                      
 } ;
//////////////////////////////////////////////////////////////
 
 Std_ReturnType motor_move_left(const motor_t *motor){
 
     if(NULL == motor){ret = E_NOT_OK ;} 
     else{
      pin_config MotorPin1 ={
       .pin_direction = OUTPUT ,
       .pin_num = motor->motor[0].motor_pin ,
       .pin_port = motor->motor[0].motor_port ,
       .pin_state = motor->motor[0].motor_state
      
       };
        pin_config MotorPin2 ={
       .pin_direction = OUTPUT ,
       .pin_num = motor->motor[1].motor_pin ,
       .pin_port = motor->motor[1].motor_port ,
       .pin_state = motor->motor[1].motor_state
      
       };       
     
        gpio_pin_write_logic(&MotorPin1, LOW);
        gpio_pin_write_logic(&MotorPin2, HIGH);
        
     }
     return ret ;
 }  ;
 /////////////////////////////////////////////////////////////
 Std_ReturnType motor_move_right(const motor_t *motor){
 
     if(NULL == motor){ret = E_NOT_OK ;} 
     else{
      pin_config MotorPin1 = {
       .pin_direction = OUTPUT ,
       .pin_num = motor->motor[0].motor_pin ,
       .pin_port = motor->motor[0].motor_port ,
       .pin_state = motor->motor[0].motor_state
      
       };
        pin_config MotorPin2 ={
       .pin_direction = OUTPUT ,
       .pin_num = motor->motor[1].motor_pin ,
       .pin_port = motor->motor[1].motor_port ,
       .pin_state = motor->motor[1].motor_state
      
       };       
     
        gpio_pin_write_logic(&MotorPin1, HIGH);
        gpio_pin_write_logic(&MotorPin2, LOW);
        
     }
     return ret ;
 }  ;

 /////////////////////////////////////////////////////////////

 Std_ReturnType motor_stop(const motor_t *motor){
      if(NULL == motor){ret = E_NOT_OK ;} 
     else{
      pin_config MotorPin1 = {
       .pin_direction = OUTPUT ,
       .pin_num = motor->motor[0].motor_pin ,
       .pin_port = motor->motor[0].motor_port ,
       .pin_state = motor->motor[0].motor_state
      
       };
        pin_config MotorPin2 ={
       .pin_direction = OUTPUT ,
       .pin_num = motor->motor[1].motor_pin ,
       .pin_port = motor->motor[1].motor_port ,
       .pin_state = motor->motor[1].motor_state
      
       };       
     
        gpio_pin_write_logic(&MotorPin1, LOW);
        gpio_pin_write_logic(&MotorPin2, LOW);
        
     }
     return ret ;
 
 } ; 
 ////////////////////////////////////////////////////////