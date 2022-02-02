//
// Tester 541
// by cloudree@naver.com
//
// Checks only
// if Dx = Low then Yx = Low
// if Dx = High then Yx = Low
// when E1=Low, E2=Low
// 

#include <Arduino.h>
#include "Common.h"
#include "Debug.h"

void setup() 
{
    DebugInit();

    for( int i=0; i<pinCount; i++ )
    {
        pinMode( pin_WData[i], OUTPUT );
        pinMode( pin_RData[i], INPUT_PULLUP );
    }

    pinMode( pin_Eb[0], OUTPUT );
    pinMode( pin_Eb[1], OUTPUT );

    // Enable 
    digitalWrite( pin_Eb[0], LOW );
    digitalWrite( pin_Eb[1], LOW );
}

void WriteAll( bool b )
{
    for( int i=0; i<pinCount; i++ )
    {
        digitalWrite( pin_WData[i], b ? HIGH : LOW );
    }
}

void WriteValue( int val )
{
    DBG( val );
    DBG(" : ");
    for( int i=0; i<pinCount; i++ )
    {
        int b = (val >> i) & 1;   // get 1 bit
        digitalWrite( pin_WData[i], b ? HIGH : LOW );
        DBG(b);
    }
}

void CheckAll( bool b )
{
    for( int i=0; i<pinCount; i++ )
    {
        if( ( b ? HIGH : LOW ) == digitalRead( pin_RData[i] ) )
        {
            DBG(".");
        }
        else
        {
            DBG(" #ERROR#\n");
        }
    }
}

void CheckValue( int val )
{
    bool result = true;
    DBG(" = ");
    for( int i=0; i<pinCount; i++ )
    {
        int b = (val >> i) & 1;   // get 1 bit
        int v = digitalRead( pin_RData[i] );
        if( (b ? HIGH : LOW) != v )
            result = false;
        DBG(v);
    }
    if( result )
        DBGLN(" OK ");
    else
        DBGLN(" #ERROR# ");
}

void loop() 
{
    DBGLN("Phase 1");    
    WriteAll( LOW );
    CheckAll( LOW );
    WriteAll( HIGH );
    CheckAll( HIGH );

    DBGLN("\n\nPhase 2");
    for( int i=0; i< 256; i++ )
    {
        WriteValue( i );
        CheckValue( i );
    }

    DBGLN("\n\nCompleted");
    DBGPAUSE();

    while(true);
}
