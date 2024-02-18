#include "LED.h"
#include <stdio.h>
Std_ReturnType ret = E_OK ;

///////////////////////////////////////////////////////
#if  PORT_PIN_CONFIGRATION==CONFIG_ENABLE
Std_ReturnType led_init(led_t *ptr){

    if(ptr == NULL || ptr->pin_num >MAX_PIN_NUM || ptr->port_name > MAX_PORT_NUM ){ret=E_NOT_OK ;}
    else{
        pin_config led ={.pin_direction =OUTPUT , .pin_num= ptr->pin_num,.pin_port =ptr->port_name ,.pin_state =ptr->led_state_t} ;
      
        gpio_pin_direction_init(&led) ;
       
    }
    return ret ;
}
#endif
/////////////////////////////////////////////////////////

#if  PORT_PIN_CONFIGRATION==CONFIG_ENABLE

Std_ReturnType led_turn_on(led_t *ptr){
    if(ptr == NULL || ptr->pin_num >MAX_PIN_NUM || ptr->port_name > MAX_PORT_NUM ){ret=E_NOT_OK ;}
    else{
  pin_config led ={.pin_direction =OUTPUT , .pin_num= ptr->pin_num,
  .pin_port =ptr->port_name ,.pin_state =ptr->led_state_t} ;

        gpio_pin_write_logic(&led , LED_ON) ;
    }

return ret ;
}
#endif

///////////////////////////////////////////////////////////

#if PORT_PIN_CONFIGRATION==CONFIG_ENABLE

Std_ReturnType led_turn_off(led_t *ptr) {
    if(ptr == NULL || ptr->pin_num >MAX_PIN_NUM || ptr->port_name > MAX_PORT_NUM ){ret=E_NOT_OK ;}
    else{
     pin_config led ={.pin_direction =OUTPUT , .pin_num= ptr->pin_num,
  .pin_port =ptr->port_name ,.pin_state =ptr->led_state_t} ;

    gpio_pin_write_logic(&led , LED_OFF)  ;
    }

return ret ;
}
#endif

////////////////////////////////////////////////////////////

#if  PORT_PIN_CONFIGRATION==CONFIG_ENABLE

Std_ReturnType led_toggle(led_t *ptr){
    if(ptr == NULL || ptr->pin_num >MAX_PIN_NUM || ptr->port_name > MAX_PORT_NUM ){ret=E_NOT_OK ;}
    else{
     pin_config led ={.pin_direction =OUTPUT , .pin_num= ptr->pin_num,
  .pin_port =ptr->port_name ,.pin_state =ptr->led_state_t} ;
     
     gpio_pin_toggle_logic(&led) ;
    
    }


return ret ;
}
#endif

////////////////////////////////////////////////////////////

