/* 
 * File:   application.c
 * Author: el msria
 *
 * Created on February 15, 2024, 11:38 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "application.h"
/*
 * 
 */

///GLOBAL SCOOPE////////////////////////////////////////////////////////////////
volatile int x ;
volatile uint8 input_pass_1  ;
volatile uint8 input_pass_2  ;
volatile uint8 input_pass_3  ;
volatile uint8 input_pass_4  ;
volatile int check = 99 ; int counter = 0 ; uint8 passward = 5 ;
char pass[4] ={'4','3','2','5'} ;
////////////////////////////////////////////////////////////////////////////////

int main(void) {

///ECU_LAYER INITS//////////////////////////////////////////////////////////////
k_pad_init(&k1) ;
lcd_8bit_init(&lcd1) ; 
motor_init(&motor1) ; 
led_init(&led1) ;
led_init(&led2) ;
//motor_move_right(&motor1) ; 
////////////////////////////////////////////////////////////////////////////////


welcoming() ;    

while(1){
  
   check_process() ;
   
} 
    return (EXIT_SUCCESS);
}


////////////////////////////////////////////////////////////////////////////////
void welcoming(void){
lcd_8bit_send_string_pos(&lcd1,2,2,"**** Welcome ****") ;
__delay_ms(1000);
lcd_8bit_send_command(&lcd1 , LCD_CLEAR );    
}
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
void pass_is_right(void){

led_turn_off(&led1) ; 
led_turn_on(&led2) ; 
motor_move_right(&motor1) ; 
lcd_8bit_send_string(&lcd1, "CORRECT PASS") ;
__delay_ms(2000);
led_turn_off(&led2) ; 

}
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
void pass_is_wrong(void){

led_turn_on(&led1) ;
led_turn_off(&led2) ;
motor_stop(&motor1); 
lcd_8bit_send_string(&lcd1, "WRONG PASS") ;
__delay_ms(2000);
led_turn_off(&led1) ; 

}
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
void get_pass(void){
    lcd_8bit_send_command(&lcd1 , LCD_CLEAR ); lcd_8bit_send_string(&lcd1, "Please enter here   "); int chk =0 ;
    while(chk == 0){
    check = 99 ; k_pad_read_number(&k1, &check) ; 
    if(check != 99){
        counter ++ ;
        if (counter == 1)    {input_pass_1 = check ;lcd_8bit_send_char_data(&lcd1,'*');}
        else if(counter == 2){input_pass_2 = check ;lcd_8bit_send_char_data(&lcd1,'*');}
        else if(counter == 3){input_pass_3 = check ;lcd_8bit_send_char_data(&lcd1,'*');}
        else if(counter == 4){input_pass_4 = check ;lcd_8bit_send_char_data(&lcd1,'*');}
      //  else{counter = 0 ;}
        check = 99 ;
    }
    if(counter == 4 ){counter= 0;break ;}
    }
}
////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////
void check_pass(void){
    if(input_pass_1 == pass[0] && input_pass_2 == pass[1] && input_pass_3 == pass[2] && input_pass_4 == pass[3] ){
    
    lcd_8bit_send_command(&lcd1 , LCD_CLEAR );
    pass_is_right() ;
    
    lcd_8bit_send_command(&lcd1 , LCD_CLEAR );
    while(1){} ;
    }
    
    else{
        lcd_8bit_send_command(&lcd1 , LCD_CLEAR ) ;
        pass_is_wrong();
        lcd_8bit_send_command(&lcd1 , LCD_CLEAR );
    }
}
////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////
void change_pass(void){
    
   
    lcd_8bit_send_command(&lcd1 , LCD_CLEAR ); 
    lcd_8bit_send_string_pos(&lcd1,1,1, "Please enter the  ");lcd_8bit_send_string_pos(&lcd1,2,1," old passward       ");
    int chk =0 ;
    while(chk == 0){
    check = 99 ; k_pad_read_number(&k1, &check) ; 
    
    if(check != 99){
        counter ++ ;
        if (counter == 1)    {input_pass_1 = check ;lcd_8bit_send_char_data(&lcd1,'*');}
        else if(counter == 2){input_pass_2 = check ;lcd_8bit_send_char_data(&lcd1,'*');}
        else if(counter == 3){input_pass_3 = check ;lcd_8bit_send_char_data(&lcd1,'*');}
        else if(counter == 4){input_pass_4 = check ;lcd_8bit_send_char_data(&lcd1,'*');}
      //  else{counter = 0 ;}
        check = 99 ;
    }
    
    if(counter == 4 ){counter= 0;break ;}
    }
    

    
    
    if(input_pass_1 == pass[0] && input_pass_2 == pass[1] && input_pass_3 == pass[2] && input_pass_4 == pass[3] ){
    
    lcd_8bit_send_command(&lcd1 , LCD_CLEAR );
    pass_is_right() ;
  
    lcd_8bit_send_command(&lcd1 , LCD_CLEAR );
   
    lcd_8bit_send_string(&lcd1, "ENTER THE NEW PASS  ") ;
    
    
    
    
    int chk =0 ;
    while(chk == 0){
    check = 99 ; k_pad_read_number(&k1, &check) ; 
    if(check != 99){
        counter ++ ;
        if (counter == 1)    {pass[0] = check ;lcd_8bit_send_char_data(&lcd1,pass[0] );}
        else if(counter == 2){pass[1] = check ;lcd_8bit_send_char_data(&lcd1,pass[1] );}
        else if(counter == 3){pass[2] = check ;lcd_8bit_send_char_data(&lcd1,pass[2] );}
        else if(counter == 4){pass[3] = check ;lcd_8bit_send_char_data(&lcd1,pass[3] );}
      //  else{counter = 0 ;}
        check = 99 ;
    }
    if(counter == 4 ){counter= 0;break ;}
    }
   
    
    
    lcd_8bit_send_command(&lcd1 , LCD_CLEAR );
    lcd_8bit_send_string(&lcd1, "new pass is reset") ; 
    __delay_ms(1500)  ;   
    lcd_8bit_send_command(&lcd1 , LCD_CLEAR ); 

    }
    
    
    else{
        lcd_8bit_send_command(&lcd1 , LCD_CLEAR ) ;
        lcd_8bit_send_string(&lcd1, "WRONG PASS") ;
        lcd_8bit_send_string_pos(&lcd1,2,1, "cant change the pass") ;
        __delay_ms(2000);
        lcd_8bit_send_command(&lcd1 , LCD_CLEAR );
    }
}
////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////
void check_process(void){
    lcd_8bit_send_string(&lcd1, "Please choose option");
    lcd_8bit_send_string_pos(&lcd1,3,1, "1-Enter  passward");
    lcd_8bit_send_string_pos(&lcd1,4,1, "2-change passward    ");
    int check_pass_ = 99;
    k_pad_read_number(&k1, &check_pass_) ;
    if(check_pass_ == '1'){get_pass();check_pass();}
    else if(check_pass_ == '2'){change_pass() ;}
    else{}
}
////////////////////////////////////////////////////////////////////////////////