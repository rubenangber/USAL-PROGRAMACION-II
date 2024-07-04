#include <stdlib.h>
#include <stdio.h>

union Dato {
    signed char caracter;
    struct {
        unsigned int bit0 : 1;
        unsigned int bit1 : 1;
        unsigned int bit2 : 1;
        unsigned int bit3 : 1;
        unsigned int bit4 : 1;
        unsigned int bit5 : 1;
        unsigned int bit6 : 1;
        unsigned int bit7 : 1;
        unsigned int extendido : 1;
    } bits;
};

int main() {
    union Dato dato;
    
    printf("Introduce un número tipo char (de -128 a 127) >> ");
    scanf("%hhd", &dato.caracter);
    
    dato.bits.extendido = (dato.caracter < 0) ? 1 : 0;

    printf("La representación binaria es >> %d%d%d%d%d%d%d%d%d\n",dato.bits.extendido, dato.bits.bit7, dato.bits.bit6, dato.bits.bit5, 
        dato.bits.bit4, dato.bits.bit3, dato.bits.bit2, dato.bits.bit1, dato.bits.bit0);
    
    return 0;
}
