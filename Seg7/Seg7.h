/*
  Seg7lib - Arduino library for control of 7 segment displays
  by David Kaplan <david@2of1.org>, 2010
  
  This fine is part of Seg7lib.
  
  This library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SEG7_H
#define SEG7_H

#include "WProgram.h"

#define MAX_DISPLAYS 3

class Seg7
{
public:
    Seg7();
    Seg7(int a, int b, int c, int d, int e, int f, int g, int dp);
    
    void attach(int a, int b, int c, int d, int e, int f, int g, int dp);
    void write(int val);
    void set_cathode(boolean cathode);

private:
    void process_mask(int idx, int mask);
    void write_internal(int idx, int val);
    int pow(int x, int y);
    
    int _a[MAX_DISPLAYS],
        _b[MAX_DISPLAYS],
        _c[MAX_DISPLAYS],
        _d[MAX_DISPLAYS],
        _e[MAX_DISPLAYS],
        _f[MAX_DISPLAYS],
        _g[MAX_DISPLAYS],
        _dp[MAX_DISPLAYS];
    int _count;
    boolean _cathode;
};

#endif
