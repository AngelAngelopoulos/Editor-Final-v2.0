
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <string.h>
#include <math.h>
#include <dos.h>
#include <windows.h>
//#include <alloc.h>
#include "LIB01.h"
#include "EDITOR_BUTTON.h"
#include "EDITOR_PALETA.h"
#include "EDITOR_WORDS.h"
#include "EDITOR_INTERFACE.h"


void guardarArch(PIX **ptrPixel, int n, int m, char Name[]);
void leerArch(PIX **ptrPixel, int n, int m, char Name[]);
int leerPrimario(char Name[], int *fila, int *colu);
void guardarImagen();

int main()
{
    PIX **ptrPixel;
    PALETA paleta[5];
    int opc = 0, fila = 0, colu = 0, malla = 0, res = 0;
    int lect = 1;
    int renDes = 0, colDes = 0;
    int posxL = 300, posyL = 300;
    int band = 0;
    char cTecla = 0;
    char nombre[30], nomPal[20];
    //strcpy(nomPal, "pal2.txt");
    opc = MenuPrincipal();
    //closegraph();
    printf("%d", opc);

do{
    if (band == 0)
        {
            switch(opc)
            {
                case 1:
                    band = 0;
                    closegraph();
                    initwindow(800, 600, "NUEVO GRAFICO");
                    fila = EscribeDato(posxL, posyL);
                    colu = EscribeDato(posxL+100, posyL);
                    res = asignaMem(&ptrPixel, fila, colu);
                    iniStru(ptrPixel, fila, colu);
                    LetrasStr(nombre, posxL, posyL+50);
                    guardarArch(ptrPixel, fila, colu, nombre);
                    malla = menu(ptrPixel, fila, colu, paleta);
                    //CreaPaleta(nombre);
                    if (malla)
                    {
                        band = 0;
                        break;
                    }
                    //malla = StartSpace(ptrPixel, fila, colu);
                    //guardarArch(ptrPixel, fila, colu, nombre);
                    //leerArch(ptrPixel, fila, colu, nombre);
                    //impStruc(ptrPixel, fila, colu);
                    //getch();
                    //liberaMem(ptrPixel, fila, colu);
                break;

                case 2:
                    band = 0;
                    closegraph();
                    initwindow(800, 600, "ABRIR GRAFICO");
                    do{
                    LetrasStr(nombre, posxL, posyL+50);
                    lect = leerPrimario(nombre, &renDes, &colDes);
                    }while(lect == 0);
                    res = asignaMem(&ptrPixel, renDes, colDes);
                    leerArch(ptrPixel, renDes, colDes, nombre);
                    fila = renDes;
                    colu = colDes;
                    malla = menu(ptrPixel, renDes, colDes, paleta);
                    //CreaPaleta(nombre);
                    //impStruc(ptrPixel, renDes, colDes);
                    //getch();
                break;

                case 3:
                    band = 0;
                    res = asignaMem(&ptrPixel, fila, colu);
                    leerArch(ptrPixel, fila, colu, nombre);
                    malla = menu(ptrPixel, fila, colu, paleta);
                    //CreaPaleta(nombre);
                break;
            }
        }

        switch (malla)
        {
            setcolor(0);
            setbkcolor(0);
            case 0:
                band = 0;
                malla = menu(ptrPixel, fila, colu, paleta);
            break;

            case 1:
                band = 0;
                liberaMem(ptrPixel, fila, colu);
                opc = 1;
            break;

            case 2:
                band = 0;
                liberaMem(ptrPixel, fila, colu);
                opc = 2;
            break;

            case 3:
                band = 0;
                guardarColor(ptrPixel, fila, colu);
                guardarArch(ptrPixel, fila, colu, nombre);
                liberaMem(ptrPixel, fila, colu);
                opc = 3;
            break;

            case 4:
                band = 0;
                guardarColor(ptrPixel, fila, colu);
                LetrasStr(nombre, 300, 350);
                guardarArch(ptrPixel, fila, colu, nombre);
                liberaMem(ptrPixel, fila, colu);
                opc = 3;
            break;

            case 5:
                do
                {
                    fflush(stdin);
                    if(kbhit())
                    {
                        cTecla=getch();
                    }
                }
                while(cTecla == 0);

                switch(cTecla)
                {
                    case 121:
                        exit(1);
                    break;
                    case 110:
                       malla = menu(ptrPixel, fila, colu, paleta);
                       //CreaPaleta(paleta, 0);
                       band = 1;
                    break;
                }
                break;

                case 6:
                band = 1;
                LetrasStr(nomPal, 300, 350);
                CreaPaleta(nomPal, paleta);
                malla = menu(ptrPixel, fila, colu, paleta);
                break;
    }
    //malla = menu(ptrPixel, fila, colu);
}
while ( 1 == 1);
    return 0;
}




    void guardarArch(PIX **ptrPixel, int n, int m, char Name[])
    {
        FILE *arch;

        char filenam[30];
        strcpy(filenam, "sprites/");
        strcat(filenam, Name);

        arch = fopen(filenam, "wb+");

        if (arch)
            {
                for (int i = 0; i < n; i ++)
                {
                    for(int j = 0; j < m; j++)
                    {
                        fwrite(&(*(ptrPixel+i)+j)->nFil, sizeof(int), 1, arch);
                        fwrite(&(*(ptrPixel+i)+j)->nCol, sizeof(int), 1, arch);
                        fwrite(&(*(ptrPixel+i)+j)->ix, sizeof(int), 1, arch);
                        fwrite(&(*(ptrPixel+i)+j)->iy, sizeof(int), 1, arch);
                        fwrite(&(*(ptrPixel+i)+j)->iColor, sizeof(int), 1, arch);
                    }
                }
                printf("El archivo se guardo\n");
            }
            fclose(arch);
            guardarImagen();
    }

void leerArch(PIX **ptrPixel, int n, int m, char Name[])
    {

        FILE *arch;
        char filenam[30];
        strcpy(filenam, "sprites/");
        strcat(filenam, Name);

        arch = fopen(filenam, "rb+");

        if (arch)
            {
                for (int i = 0; i < n; i ++)
                {
                    for(int j = 0; j < m; j++)
                    {
                        fread(&(*(ptrPixel+i)+j)->nFil, sizeof(int), 1, arch);
                        fread(&(*(ptrPixel+i)+j)->nCol, sizeof(int), 1, arch);
                        fread(&(*(ptrPixel+i)+j)->ix, sizeof(int), 1, arch);
                        fread(&(*(ptrPixel+i)+j)->iy, sizeof(int), 1, arch);
                        fread(&(*(ptrPixel+i)+j)->iColor, sizeof(int), 1, arch);
                    }
                }
            }
            else
            {
                outtextxy(35, 565,"El archivo no se encuentra");
            }
            fclose(arch);
    }

int leerPrimario(char Name[], int *renDes, int *colDes)
    {
        int res = 1;
        //char *rest;
        FILE *arch;
        char filenam[30];
        strcpy(filenam, "sprites/");
        strcat(filenam, Name);

        if(strstr(Name, ".dat")){
            arch = fopen(filenam, "rb+");
        }
        else
            arch = 0;

        if (arch)
        {
            fread(renDes, sizeof(int), 1, arch);
            fread(colDes, sizeof(int), 1, arch);
        }
        else
        {
            setbkcolor(0);
            outtextxy(35, 565,"El archivo no se encuentra");
            res = 0;
        }
        fclose(arch);
        return (res);
}

void guardarImagen()
{
    int band = 0;
    long tam;
    char *img;
    tam = long(imagesize(150, 50, 650, 550));
    img = (char*)malloc(tam);
    getimage(150, 50, 650, 550, img);
    FILE *arch;
    arch = fopen("img.bmp", "wb+");
    fwrite(img, sizeof(img), 1, arch);
    fclose(arch);
}
