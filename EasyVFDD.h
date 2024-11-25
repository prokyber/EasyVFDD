#ifndef _EASY_VFDD
#define _EASY_VFDD
#include "Arduino.h"

/*! \mainpage Intro
 * This is a little documentation for the EasyNixie module, before using the module be sure to checkout all the safety guidelines located at:
 * https://www.kickstarter.com/projects/esp32-stick/easynixie. 
 * The module uses a pretty high voltage(200V) to power up the nixies, so be sure to keep it unplugged from the PC when you turn the high-voltage on.
 * (Disconnect VPOWER pin->Flash the code->unplug from the pc->connect external source->connect VPOWER pin)
 */ 

/** @defgroup Colors Avalilable led colors
 *  @{
 */

/** @} */

/** @brief The main EasyNixie class**/
class EasyVFDD{
    public:
    /** @brief The microcontroller pin connected to OUT_EN pin of the EasyNixie**/
    uint8_t outputEnable;
    /** @brief The microcontroller pin connected to SHCP pin of the EasyNixie**/
    uint8_t shcp;
    /** @brief The microcontroller pin connected to STCP pin of the EasyNixie**/
    uint8_t stcp;
    /** @brief The microcontroller pin connected to DSIN pin of the EasyNixie**/
    uint8_t dsin;

    enum VFDDLedColors{
      Blue = 1,
      Green = 2,
      Red = 3,
      White = 4,
      RuB = 5,
      RuG = 6,
      BuG = 7
    };

    /** @brief This constructor takes 4 pin names as arguments, they are labeled OUT_EN, SHCP, STCP and DSIN on your EasyNixie module
     * @param outputEnable The microcontroller pin connected to OUT_EN pin of the EasyNixie
     * @param shcp The microcontroller pin connected to SHCP pin of the EasyNixie.
     * @param stcp The microcontroller pin connected to STCP pin of the EasyNixie.
     * @param dsin The microcontroller pin connected to DSIN pin of the EasyNixie.
      **/
    EasyVFDD(uint8_t outputEnable,uint8_t shcp, uint8_t stcp, uint8_t dsin);

    /** @brief Set nixie digit/symbol on your EasyNixie. If you have multiple modules connected 'in series' (EasyNixie1 DSOUT->EasyNixie2 DSIN)
    * the value is set to the first module in series(The one which has DSIN connected to the Arduino).
    * To display the value set with this method use the @ref Latch method!
    * @param number The digit/symbol you want to display. The digits can be swapped if you are using non-standard nixies(not In-12/In-17).
    * @param color Led color, checkout the \ref Colors, I should have probably used enum to avoid illegal arguments, 
    * but I am too lazy to rewrite and retest all the examples...
    * @param voltage This argument enables the high-voltage convertor, be sure to disconnect the EasyNixie from PC,
    *  when you are calling the function with this argument set to true. You can flash the code with VPOWER pin disconneted,
    *  then disconnect the board from PC, connect to some external power source, then connect the VPOWER pin.
    * @param comma Or the 'decimal point'. This argument controls the decimal point of In-12B.
    * @param dimming Basically, just PWM on the @ref outputEnable pin. 0 means max brightness, 255 means min brightness.
    **/

    uint8_t ColorReturn(EasyVFDD::VFDDLedColors color, uint8_t index);

    void SetVFDD(uint8_t lightValues[3], EasyVFDD::VFDDLedColors colors[3]=NULL, bool voltage=true,uint16_t dimming=0/*, VFDDLedColors color[] = NULL*/);
  
    /** @brief This method 'displays' the digit that you have set using @ref SetNixie, be sure to call it after @ref SetNixie**/
    void Latch(void);

    uint8_t _ReverseByte(uint8_t oldNumber);
};

#endif

