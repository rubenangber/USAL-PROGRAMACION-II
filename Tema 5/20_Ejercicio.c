#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIF 10
#define MAX_NOMBRE 26
#define MAX_NOTAS 5
#define FILE_PATH "c:\\datos\\alumnos.bin"

typedef struct {
    char rnif[MAX_NIF];
    long rmatricula;
    char rnombre[MAX_NOMBRE];
    float rnotas[MAX_NOTAS];
} reg_alumno;

void buscarPorNIF(FILE *file, const char *nif) {
    reg_alumno registro;
    int encontrado = 0;

    while (fread(&registro, sizeof(reg_alumno), 1, file)) {
        if (strcmp(registro.rnif, nif) == 0) {
            mostrarRegistro(&registro);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontró el NIF %s.\n", nif);
    }
}

void buscarPorMatricula(FILE *file, long matricula) {
    reg_alumno registro;
    int encontrado = 0;

    while (fread(&registro, sizeof(reg_alumno), 1, file)) {
        if (registro.rmatricula == matricula) {
            mostrarRegistro(&registro);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontró la matrícula %ld.\n", matricula);
    }
}

void buscarPorNombre(FILE *file, const char *nombre) {
    reg_alumno registro;
    int encontrado = 0;

    while (fread(&registro, sizeof(reg_alumno), 1, file)) {
        if (strstr(registro.rnombre, nombre) != NULL) {
            mostrarRegistro(&registro);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontró el nombre que contiene %s.\n", nombre);
    }
}

void buscarPorNota(FILE *file, float nota) {
    reg_alumno registro;
    int encontrado = 0;
    
    while (fread(&registro, sizeof(reg_alumno), 1, file)) {
        for (int i = 0; i < MAX_NOTAS; i++) {
            if (registro.rnotas[i] == nota) {
                mostrarRegistro(&registro);
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        printf("No se encontró la nota %.2f.\n", nota);
    }
}

void mostrarRegistro(reg_alumno *registro) {
    printf("NIF >> %s\n", registro->rnif);
    printf("Matrícula >> %ld\n", registro->rmatricula);
    printf("Nombre >> %s\n", registro->rnombre);
    printf("Notas >> ");
    for (int i = 0; i < MAX_NOTAS; i++) {
        printf("%.2f ", registro->rnotas[i]);
    }
    printf("\n\n");
}

void menu() {
    printf("Menú de búsqueda >>\n");
    printf("1. Buscar por NIF\n");
    printf("2. Buscar por número de matrícula\n");
    printf("3. Buscar por parte del nombre\n");
    printf("4. Buscar por nota\n");
    printf("5. Salir\n");
}

int main() {
    FILE *file;
    int opcion;
    char nif[MAX_NIF];
    long matricula;
    char nombre[MAX_NOMBRE];
    float nota;

    menu();
    while (1) {
        printf("Seleccione una opción (1-5) >> ");
        scanf("%d", &opcion);
        getchar();

        file = fopen(FILE_PATH, "rb");
        if (file == NULL) {
            printf("Error al abrir el fichero.\n");
            continue;
        }

        switch (opcion) {
            case 1:
                printf("Ingrese el NIF a buscar >> ");
                fgets(nif, MAX_NIF, stdin);
                nif[strcspn(nif, "\n")] = '\0';
                buscarPorNIF(file, nif);
                break;
            case 2:
                printf("Ingrese el número de matrícula a buscar >> ");
                scanf("%ld", &matricula);
                buscarPorMatricula(file, matricula);
                break;
            case 3:
                printf("Ingrese parte del nombre a buscar >> ");
                fgets(nombre, MAX_NOMBRE, stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                buscarPorNombre(file, nombre);
                break;
            case 4:
                printf("Ingrese la nota a buscar >> ");
                scanf("%f", &nota);
                buscarPorNota(file, nota);
                break;
            case 5:
                fclose(file);
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opción no válida. Inténtelo de nuevo\n");
        }

        fclose(file);
        menu();
    }

    return 0;
}
