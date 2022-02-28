#include "crc8.h"

unsigned char crc8(unsigned char *pcBlock, unsigned int len)
{
    unsigned char crc = 0x00;
    while (len--)
        crc ^= *pcBlock++;
    return crc;
}
