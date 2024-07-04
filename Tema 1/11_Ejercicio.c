#include <stdio.h>
#include <string.h>

union dato {
    long numero;
    struct {
        unsigned int bit0 : 1;
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
        unsigned int bit6 : 1;
        unsigned int bit7 : 1;
        unsigned int bit8 : 1;
        unsigned int bit9 : 1;
        unsigned int bit10 : 1;
        unsigned int bit11 : 1;
        unsigned int bit12 : 1;
        unsigned int bit13 : 1;
        unsigned int bit14 : 1;
        unsigned int bit15 : 1;
        unsigned int bit16 : 1;
        unsigned int bit17 : 1;
        unsigned int bit18 : 1;
        unsigned int bit19 : 1;
        unsigned int bit20 : 1;
        unsigned int bit21 : 1;
        unsigned int bit22 : 1;
        unsigned int bit23 : 1;
        unsigned int bit24 : 1;
        unsigned int bit25 : 1;
        unsigned int bit26 : 1;
        unsigned int bit27 : 1;
        unsigned int bit28 : 1;
        unsigned int bit29 : 1;
        unsigned int bit30 : 1;
        unsigned int bit31 : 1;
    } bits;
};

int main(int argc, char const *argv[]) {
    union dato dato;

    printf("Ingrese un número tipo long >> ");
    scanf("%ld", &dato.numero);

    printf("La representación binaria es >> %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",
        dato.bits.bit31, dato.bits.bit30, dato.bits.bit29, dato.bits.bit28,
        dato.bits.bit27, dato.bits.bit26, dato.bits.bit25, dato.bits.bit24,
        dato.bits.bit23, dato.bits.bit22, dato.bits.bit21, dato.bits.bit20,
        dato.bits.bit19, dato.bits.bit18, dato.bits.bit17, dato.bits.bit16,
        dato.bits.bit15, dato.bits.bit14, dato.bits.bit13, dato.bits.bit12,
        dato.bits.bit11, dato.bits.bit10, dato.bits.bit9, dato.bits.bit8,
        dato.bits.bit7, dato.bits.bit6, dato.bits.bit5, dato.bits.bit4,
        dato.bits.bit3, dato.bits.bit2, dato.bits.bit1, dato.bits.bit0);

    return 0;
}