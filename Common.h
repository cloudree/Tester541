/*
 * Common.h
 * by cloudree
 *
 */

#define PRODUCT       "Tester_541"
#define MAJOR_VERSION "0"
#define MINOR_VERSION "1"
#define VERSION       ("v" MAJOR_VERSION "." MINOR_VERSION)

#define _DEBUG
// 91% is safe : 120544
// 92% has error : 121192

// Global --------------
/*
Arduino Pin   74LS541 Pin
D2  --------- 1/~E1
D3  --------- 2/D1
D4  --------- 3/D2
D5  --------- 4/D3
D6  --------- 5/D4
D7  --------- 6/D5
D8  --------- 7/D6
D9  --------- 8/D7
D10 --------- 9/D8
GND --------- 10/GND
D11 --------- 11/Y8
D12 --------- 12/Y7
D13 --------- 13/Y6
A0  --------- 14/Y5
A1  --------- 15/Y4
A2  --------- 16/Y3
A3  --------- 17/Y2
A4  --------- 18/Y1
A5  --------- 19/~E2
VCC --------- 19/VCC

A6,A7 support only "Analog In"
*/

// 74LS541
const int pinCount = 8;
const int pin_WData[pinCount] = {  3,  4,  5, 13,  6,  7,  8,  9 };   // LED = 13
const int pin_RData[pinCount] = { A4, A3, A2, A1, A0, 12, 11, 10 };
const int pin_Eb[2] = { 2, A5 };
