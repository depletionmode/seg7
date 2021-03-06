Seg7 library 1.0 by David Kaplan (david@2of1.org), 2010
http://blog.2of1.org

About
------------------------------------------------------------------------------

Seg7 is an Arduino library that allows for easy control of LED 7 segment 
displays. It can currently support multiple displays and decimal digits and 
is licensed under GPL v3.0.


Installation
------------------------------------------------------------------------------

Place the Seg7 folder in <arduino software director>/libraries/.
You'll need to restart the Arduino software before you can use the library.


Usage
------------------------------------------------------------------------------

Firstly include the Seg7 header in your sketch:

#include <Seg7.h>

Then initialise an instance of the library as follows:

Seg7 display = Seg7();

You then need to specify the 7 segment display pinout buy calling the attach()
function (see 'Wiring' below):

display.attach(0, 1, 2, 3, 4, 5, 6, 7);    // a, b, c, d, e, f, g, dp

If you wish, you can specify the pin mapping (of the first display) in the 
constructor. The following is equivalent to the above two lines:

Seg7 display = Seg7(0, 1, 2, 3, 4, 5, 6, 7);

To write to the display, simply call the write() method:

display.write(7);

The Seg7 library has support for multiple displays. Simply attach each in turn
(starting from units, then tens, then hundreds...):

display.attach(0, 1, 2, 3, 4, 5, 6, 7);        // units
display.attach(8, 9, 10, 11, 12, 13, 14, 15);  // tens

You can then call write() with multiple digits:

display.write(39);

NOTE: You can add up to three displays. If you wish to add more than three,
simply increase the value of MAX_DISPLAYS in Seg7.h.

ALSO NOTE: By default, the Seg7 library assumes that your display is common-anode. If your display is in fact common-cathode, you need to call set_cathode(true).


Wiring
------------------------------------------------------------------------------

7 segment displays usually have 10 pins.
Pins 3 and 8 are common - and are connected in either a common-anode (+V) or
common-cathode (GND) configuration (you only need to connect one of them).

NOTE: Seg7 works in the common-anode configuration by default. If you have a 
common-cathode display, you'll need to call the set_cathode() function, e.g.: display1.set_cathode(true);

The rest of the pins are mapped as follows:

a - 7
b - 6
c - 4
d - 2
e - 1
f - 9
g - 10
dp/h - 5


Todo
------------------------------------------------------------------------------

1. Support for hexadecimal digits
2. Support for dp (decimal point)
3. Support for 4511 decoder chip

----------
!HAVE FUN!
----------
