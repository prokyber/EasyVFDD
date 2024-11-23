#include "EasyVFDD.h"

EasyVFDD::EasyVFDD(uint8_t outputEnable,uint8_t shcp, uint8_t stcp, uint8_t dsin):
        outputEnable(outputEnable),
        shcp(shcp),
        stcp(stcp),
        dsin(dsin)
{
    pinMode(outputEnable, OUTPUT);  
    pinMode(shcp, OUTPUT);
    pinMode(stcp, OUTPUT);
    pinMode(dsin, OUTPUT);
}

void EasyVFDD::SetVFDD(uint8_t lightValues[3],EasyVFDD::VFDDLedColors colors[3],bool voltage,uint16_t dimming){
    #if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)//AnalogWrite is supported for some platfroms and not supported for others(Esp32?). if you want to use dimming on these platoforms you have to implement it yourself:)
    analogWrite(outputEnable,dimming);
    #endif


    if(colors == NULL)
    {
        VFDDLedColors _color[3] = {VFDDLedColors::White, VFDDLedColors::White, VFDDLedColors::White};
        colors = _color;
        pinMode(4, OUTPUT);
        digitalWrite(4, HIGH);
    }

    lightValues[0] = EasyVFDD::_ReverseByte(lightValues[0]);
    lightValues[1] = EasyVFDD::_ReverseByte(lightValues[1]);
    lightValues[2] = EasyVFDD::_ReverseByte(lightValues[2]);

    uint8_t firstShiftRegisterData=0b00000000;
    uint8_t secondShiftRegisterData=EasyVFDD::ColorReturn(colors[0], 0);
    uint8_t thirdShiftRegisterData=EasyVFDD::ColorReturn(colors[1], 1);
    uint8_t fourthShiftRegisterData=EasyVFDD::ColorReturn(colors[2], 2);
    if(voltage)secondShiftRegisterData|=0b00100000;

    //first register
    firstShiftRegisterData |= (0b00000001 & lightValues[2]);
    firstShiftRegisterData |= (0b00000010 & lightValues[2]);
    firstShiftRegisterData |= (0b00000100 & lightValues[2]);
    firstShiftRegisterData |= (0b00001000 & lightValues[2]);
    firstShiftRegisterData |= (0b00010000 & lightValues[2]);
    firstShiftRegisterData |= (0b00100000 & lightValues[2]);
    firstShiftRegisterData |= (0b01000000 & lightValues[2]);
    firstShiftRegisterData |= ((0b00000001 & lightValues[1]) << 7) & 0b10000000;

    //second register
    secondShiftRegisterData |= ((0b00000010 & lightValues[1]) >> 1) & 0b00000001;
    secondShiftRegisterData |= ((0b00000100 & lightValues[1]) >> 1) & 0b00000010;
    secondShiftRegisterData |= ((0b00001000 & lightValues[1]) << 3) & 0b01000000;
    secondShiftRegisterData |= ((0b00010000 & lightValues[1]) << 3) & 0b10000000;
    //third register
    thirdShiftRegisterData |= ((0b00100000 & lightValues[1]) >> 5) & 0b00000001;
    thirdShiftRegisterData |= ((0b01000000 & lightValues[1]) >> 5) & 0b00000010;
    thirdShiftRegisterData |= ((0b00000001 & lightValues[0]) << 5) & 0b00100000;
    thirdShiftRegisterData |= ((0b00000010 & lightValues[0]) << 5) & 0b01000000;
    thirdShiftRegisterData |= ((0b00000100 & lightValues[0]) << 5) & 0b10000000;

    //fourth register
    fourthShiftRegisterData |= ((0b00001000 & lightValues[0]) >> 3) & 0b00000001;
    fourthShiftRegisterData |= ((0b00010000 & lightValues[0]) >> 3) & 0b00000010;
    fourthShiftRegisterData |= ((0b00100000 & lightValues[0]) >> 3) & 0b00000100;
    fourthShiftRegisterData |= ((0b01000000 & lightValues[0]) >> 3) & 0b00001000;

    shiftOut(dsin, shcp, MSBFIRST, fourthShiftRegisterData);
    shiftOut(dsin, shcp, MSBFIRST, thirdShiftRegisterData);
    shiftOut(dsin, shcp, MSBFIRST, secondShiftRegisterData);
    shiftOut(dsin, shcp, MSBFIRST, firstShiftRegisterData);
}

void EasyVFDD::Latch(void){
    digitalWrite(stcp, LOW);
    delay(1);
    digitalWrite(stcp, HIGH);
}

uint8_t EasyVFDD::ColorReturn(EasyVFDD::VFDDLedColors color, uint8_t index){
    if(index > 2 || index < 0)
        return -1;
    uint8_t registerValue;
    switch(color){
        case EasyVFDD::Blue:
            registerValue=0b00011000;
            break;

        case EasyVFDD::Green:
            registerValue=0b00010100;
            break;

        case EasyVFDD::Red:
            registerValue=0b00001100;
            break;

        case EasyVFDD::White:
            registerValue=0b00000000;
            break;

        case EasyVFDD::RuB:
            registerValue=0b00001000;
            break;

        case EasyVFDD::RuG:
            registerValue=0b00000100;
            break;

        case EasyVFDD::BuG:
            registerValue=0b0010000;
            break;
    }

    if(index == 2)
    registerValue = (registerValue << 2) & 0b01110000;

    return registerValue;
}

uint8_t EasyVFDD::_ReverseByte(uint8_t oldNumber){
    uint8_t newNumber = 0; 
    for (int i = 0; i<8; i++){
        if (!(oldNumber & (1 << i))) newNumber |= 1 << i;
    }
    return newNumber;
}