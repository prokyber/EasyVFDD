# EasyVFDD Library

Library for controling EasyVFDD desk  by providing an array of three uint8_t nums as a binary representation of display columns. User can also control built in RGB LEDs.

## VFDDLedColor (Enum)

- Representation of LED color

### Values

- Blue = 1
- Green = 2
- Red = 3
- White = 4
- RuB = 5 (purple)
- RuG = 6 (yellow)
- BuG = 7 (cyan)

## All user methods

- EasyVFDD
- SetVFDD
- Latch

## EasyVFDD

Constructor method that sets all necesery pins

### Paramers

- uint8_t outputEnable - number of pin that enables voltage on desk
- uint8_t shcp - number of shcp pin
- uint8_t stcp - number of stcp pin
- uint8_t dsin - number of data input pin

## SetVFDD

Method used to set up shift registers of VFDDs. Don't forget to call the Latch method after to see the resaults.

### Parametrs

- `uint8_t lightValues[3]` - array of three byte sized numbers, each representing one column of display in binary (example of one number: 0b0110001)

- `EasyVFDD::VFDDLedColors colors[3]` - array of three VFDDLedColors (default is threetimes white)

- `bool voltage = true` - variable that determins if we want to let voltage in, can be used for testing stuff up (default value = true)

- `uint16_t dimming` -

### Call example

("e" is an EasyVFDD instance)

```cpp
uint8_t columns[3] = {
  0b01000000,
  0b00000000,
  0b0111111};

EasyVFDD::VFDDLedColor colors[3] = {
  EasyVFDD::Blue;
  EasyVFDD::Red;
  EasyVFDD::Green;
};

e.SetVFDD(columns, colors);
```

Resault of this call will be that after calling the Latch() method in left coloumn only the top light will be ON and its LED will shine blue light, whole center column will be OFF and its LED will shine red light and the whole right column will be ON and its LED will shine green light

## Latch

Method that latches all shift registers. Don't forget to use the SetVFDD method to set them up first.

### Call example

("e" is an EasyVFDD instance)

```cpp
e.SetVFDD(/*your values*/);
e.Latch();
```
