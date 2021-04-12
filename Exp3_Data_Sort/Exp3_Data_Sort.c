#include "REG51.H"
#include "ABSACC.H"

void main()
{
    unsigned char temp, i, j, n = 10, ave;
    int x = 0;
    unsigned char a[10] = {11, 44, 22, 55, 33, 69, 77, 66, 99, 10};
    for (i = 0; i < 10; i++)
    {
        DBYTE[0x30 + i] = a[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        DBYTE[0x30 + i] = a[i];
    }
    for (i = 1; i < 9; i++)
    {
        x += a[i];
    }
    DBYTE[0x40] = x / 256;
    DBYTE[0x41] = x % 256;
    ave = x / 8;
    DBYTE[0x50] = ave;
}