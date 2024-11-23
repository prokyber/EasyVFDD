#include <Arduino.h>
#include <EasyVFDD.h>

EasyVFDD e(3,2,6,7);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // Colors
  EasyVFDD::VFDDLedColors b[3] = {EasyVFDD::Red, EasyVFDD::Blue, EasyVFDD::Green};

  // A
  uint8_t a[3] = {0b0111111, 0b1001000, 0b0111111};
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // B
  a[0]=0b1111111; 
  a[1]=0b1001001; 
  a[2]=0b0110110; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // C
  a[0]=0b0111110; 
  a[1]=0b1000001; 
  a[2]=0b1000001; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // D
  a[0]=0b1111111; 
  a[1]=0b1000001; 
  a[2]=0b0111110; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // E
  a[0]=0b1111111; 
  a[1]=0b1001001; 
  a[2]=0b1000001; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // F
  a[0]=0b1111111; 
  a[1]=0b1001000; 
  a[2]=0b1000000; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // G
  a[0]=0b1111111; 
  a[1]=0b1001001; 
  a[2]=0b1001111; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // H
  a[0]=0b1111111; 
  a[1]=0b0001000; 
  a[2]=0b1111111; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // I
  a[0]=0b0000000; 
  a[1]=0b1111111; 
  a[2]=0b0000000; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // J
  a[0]=0b0000110; 
  a[1]=0b0000001; 
  a[2]=0b1111110; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // K
  a[0]=0b1111111; 
  a[1]=0b0001000; 
  a[2]=0b1110111; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // L
  a[0]=0b1111111; 
  a[1]=0b0000001; 
  a[2]=0b0000001; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // M
  a[0]=0b1111111; 
  a[1]=0b0110000; 
  a[2]=0b1111111; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // N
  a[0]=0b1111111; 
  a[1]=0b0011000; 
  a[2]=0b1111111; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // O
  a[0]=0b0111110; 
  a[1]=0b1000001; 
  a[2]=0b0111110; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // P
  a[0]=0b1111111; 
  a[1]=0b1001000; 
  a[2]=0b0110000; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);
  
  // Q
  a[0]=0b0111100; 
  a[1]=0b1000010; 
  a[2]=0b0111101; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // R
  a[0]=0b1111111; 
  a[1]=0b1001000; 
  a[2]=0b0110111; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // S
  a[0]=0b0110001; 
  a[1]=0b1001001; 
  a[2]=0b1000110; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // T
  a[0]=0b1000000; 
  a[1]=0b1111111; 
  a[2]=0b1000000; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // U
  a[0]=0b0111110; 
  a[1]=0b0000001; 
  a[2]=0b0111110; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // V
  a[0]=0b0111100; 
  a[1]=0b0000011; 
  a[2]=0b0111100; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // W
  a[0]=0b0111111; 
  a[1]=0b0000110; 
  a[2]=0b0111111; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // X
  a[0]=0b1110111; 
  a[1]=0b0001000; 
  a[2]=0b1110111; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // Y
  a[0]=0b1110000; 
  a[1]=0b0001111; 
  a[2]=0b1110000; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);

  // Z
  a[0]=0b1000011; 
  a[1]=0b1001101; 
  a[2]=0b1110001; 
  e.SetVFDD(a, b);
  e.Latch();
  delay(1000);
}