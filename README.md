# Tester541
74LS541 Tester (74HC541, 74HCT541)

Just a simple 74LS541 tester with Arduino Nano

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


It checks only

 if Dx = Low then Yx = Low

 if Dx = High then Yx = Low

when E1=Low, E2=Low
