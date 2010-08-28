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

#include "Seg7.h"

Seg7::Seg7()
  : _count(0), _cathode(false)
{}

Seg7::Seg7(int a, int b, int c, int d, int e, int f, int g, int dp)
  : _count(0), _cathode(false)
{
  attach(a, b, c, d, e, f, g, dp);
}

void Seg7::attach(int a, int b, int c, int d, int e, int f, int g, int dp)
{
  _a[_count] = a;
  _b[_count] = b;
  _c[_count] = c;
  _d[_count] = d;
  _e[_count] = e;
  _f[_count] = f;
  _g[_count] = g;
  _dp[_count] = dp;

  _count++;
    
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  
  digitalWrite(a, HIGH ^ _cathode);
  digitalWrite(b, HIGH ^ _cathode);
  digitalWrite(c, HIGH ^ _cathode);
  digitalWrite(d, HIGH ^ _cathode);
  digitalWrite(e, HIGH ^ _cathode);
  digitalWrite(f, HIGH ^ _cathode);
  digitalWrite(g, HIGH ^ _cathode); 
  digitalWrite(dp, HIGH ^ _cathode);
}

void Seg7::process_mask(int idx, int mask)
{
  int i;
  for (i = 0; i < 8; i++) {
    int val = (mask & 1) ^ !_cathode;
    mask >>= 1;
    switch(i) {
      case 0:
        digitalWrite(_a[idx], val);
        break;
      case 1:
        digitalWrite(_b[idx], val);
        break;
      case 2:
        digitalWrite(_c[idx], val);
        break;
      case 3:
        digitalWrite(_d[idx], val);
        break;
      case 4:
        digitalWrite(_e[idx], val);
        break;
      case 5:
        digitalWrite(_f[idx], val);
        break;
      case 6:
        digitalWrite(_g[idx], val);
        break;
      case 7:
        digitalWrite(_dp[idx], val);
        break;
    }
  }
}

void Seg7::write_internal(int idx, int val)
{
  switch(val) {
    case 0:
      process_mask(idx, 1+2+4+8+16+32);
      break;
    case 1:
      process_mask(idx, 2+4);
      break;
    case 2:
      process_mask(idx, 1+2+8+16+64);
      break;
    case 3:
      process_mask(idx, 1+2+4+8+64);
      break;
    case 4:
      process_mask(idx, 2+4+32+64);
      break;
    case 5:
      process_mask(idx, 1+4+8+32+64);
      break;
    case 6:
      process_mask(idx, 1+4+8+16+32+64);
      break;
    case 7:
      process_mask(idx, 1+2+4);
      break;
    case 8:
      process_mask(idx, 1+2+4+8+16+32+64);
      break;
    case 9:
      process_mask(idx, 1+2+4+32+64);
      break;
  }
}

void Seg7::set_cathode(boolean cathode)
{
  _cathode = cathode;
}

// not using math.h here as this code compiles smaller 
int Seg7::pow(int x, int y)
{
  for (int i = 0; i < y - 1; i++)
    x *= x;
    
  if (!y)
    x = 1;  
  
  return x;
}

void Seg7::write(int val)
{
  for (int i = 0; i < _count; i++) {
      int d = val % pow(10, i + 1);
      d /= pow(10, i);
      write_internal(i, d);
  }
}
