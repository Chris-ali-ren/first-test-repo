#include"stdio.h"

#define TOPBIT               0x8000
#define POLYNOM_1            0x8408
#define POLYNOM_2            0x8025
#define BITMASK              0x0080
#define INITAL_REMINDER      0xfffe
#define MSG_LEN              2

short calCRC(short data)
{
    short remainder;
    char bseed[2];
    char n;
    char i;
    bseed[0] = (char)(data >> 8);
    bseed[0] = (char)data;
    remainder = INITAL_REMINDER;
    for(n =0; n < MSG_LEN; n++)
    {
        remainder ^= ((bseed[n])<<8);
        for(i =0; i< 8; i++)
        {
            if(remainder & TOPBIT)
            {
                if(remainder & BITMASK)
                    remainder = (remainder << 1)^POLYNOM_1;
                else
                    remainder = (remainder<< 1)^POLYNOM_2;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }
    }
    return remainder;
}
short a = 0x0185;
short b;
int main(void)
{
    b = calCRC(a);
    printf("%x",b);
    return;
}

