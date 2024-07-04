#include <stdlib.h>
#include <stdio.h>

struct Mes {
    char nombre[10];
    char abr[4];
    int dias;
    int orden;
};

int main(int argc, char const *argv[]) {
    struct Mes meses[12];

    for(int i = 0; i < 12; i++) {
        if(i == 1) {
            meses[i].dias = 28;
        } else if(i % 2 == 0) {
            meses[i].dias = 31;
        } else {
            meses[i].dias = 30;
        }

        meses[i].orden = i + 1;
    }

    strcpy(meses[0].nombre, "Enero");
    strcpy(meses[0].abr, "Ene");
    strcpy(meses[1].nombre, "Febrero");
    strcpy(meses[1].abr, "Feb");
    strcpy(meses[2].nombre, "Marzo");
    strcpy(meses[2].abr, "Mar");
    strcpy(meses[3].nombre, "Abril");
    strcpy(meses[3].abr, "Abr");
    strcpy(meses[4].nombre, "Mayo");
    strcpy(meses[4].abr, "May");
    strcpy(meses[5].nombre, "Junio");
    strcpy(meses[5].abr, "Jun");
    strcpy(meses[6].nombre, "Julio");
    strcpy(meses[6].abr, "Jul");
    strcpy(meses[7].nombre, "Agosto");
    strcpy(meses[7].abr, "Ago");
    strcpy(meses[8].nombre, "Septiembre");
    strcpy(meses[8].abr, "Sep");
    strcpy(meses[9].nombre, "Octubre");
    strcpy(meses[9].abr, "Oct");
    strcpy(meses[10].nombre, "Noviembre");
    strcpy(meses[10].abr, "Nov");
    strcpy(meses[11].nombre, "Diciembre");
    strcpy(meses[11].abr, "Dic");

    printf("Introduce el mes >> ");
    int mes;
    scanf("%d", &mes);
    printf("Introduce el dia >> ");
    int dia;
    scanf("%d", &dia);

    int dias = dia;

    for(int i = 0; i < mes - 1; i++) {
        dias += meses[i].dias;
    }

    printf("Han pasado %d\n", dias);

    return 0;
}
