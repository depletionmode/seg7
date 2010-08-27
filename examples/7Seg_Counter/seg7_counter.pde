/*  7 segment display counter
    
    This sketch counts from 0 to 9 on a 7-segment display
    
    The circuit:
      
           A
          ____
         |    |
      F  |____|  B
         | G  |
      E  |____|  C 
                o DP
           D
           
      7-segment 10-pin package:
      
      10 9 8 7 6 
       ________
      |   __   |
      |  |__|  |
      |  |__|o |
      |________| 
      
      1 2 3 4 5  
      
      * If you have a common cathode device, uncomment line X
      * You only need to connect either pin 3 OR pin 8
      * 1 (E) connect to arduino pin 4
      * 2 (D) connect to arduino pin 3
      * 3 common-anode connect to +, common-cathode to -
      * 4 (C) connect to arduino pin 2
      * 5 (DP) connect to arduino pin 7
      * 6 (B) connect to arduino pin 1
      * 7 (A) connect to arduino pin 0
      * 8 common-anode connect to +, common-cathode to -
      * 9 (F) connect to arduino pin 5
      * 10 (G) connect to arduino pin 6
      
      This example is placed in the Public Domain and is free
      for your use/modification for any purpose
*/
  
#include "Seg7.h"

Seg7 s7;  // object

void setup()   {
  //s7.set_cathode(true);  // set for common-cathode
  s7.attach(0, 1, 2, 3, 4, 5, 6, 7);  // attach a single 7-segment display
}

void loop()                     
{
  for (int i = 0; i < 10; i++) {  // count from 0-9
    s7.write(i);
    delay(1000);  // wait 1 second
  }
}
