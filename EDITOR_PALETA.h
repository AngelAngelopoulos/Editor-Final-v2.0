#ifndef EDITOR_PALETA_H_INCLUDED
#define EDITOR_PALETA_H_INCLUDED

 typedef struct
    {
        int Rojo;
        int Verde;
        int Azul;
    }PALETA;

    int ConvierteDec(char hex[], int len);
    void imprimePaleta(PALETA color[]);
     void CreaPaleta(char nombre[], PALETA color[]);


#endif // EDITOR_PALETA_H_INCLUDED

    void CreaPaleta(char nombre[], PALETA color[])
    {
        //initwindow(800, 600, "Paleta");
        char hexa[4]; //nombre[20];
        int len;
       FILE *arch;
       //if (opcion == 1){
       //LetrasStr(nombre, 300, 350);
       char filenam[30];
        strcpy(filenam, "palettes/");
        strcat(filenam, nombre);
       arch=fopen(filenam,"r");  //Nombre del archivo de texto con los nombres de los botones
       if(arch==NULL){
        printf("No existe el archivo");
        //exit(1);
       }

        int j = 0;
        int i = 0;
        do{

           fgets(hexa,3,arch); //Leer linea por linea
            len = strlen(hexa);
            len--;

                switch (j)
                {
                case 0:
                    color[i].Rojo = ConvierteDec(hexa, len);
                    break;
                case 1:
                    color[i].Verde = ConvierteDec(hexa, len);
                    break;
                case 2:
                    color[i].Azul = ConvierteDec(hexa, len);
                    break;
                }
                if (j == 2){
                    j = 0;
                    i++;
                }
                else
                    j++;
        }while(!feof(arch));
         fclose(arch);  //cierra el archivo
       //}
       //malla = menu();
        imprimePaleta(color);
    }

    int ConvierteDec(char hex[], int len)
    {
        int decimal = 0;
        int val = 0;

        for(int i=0; i < 2; i++)
        {

            /* Find the decimal representation of hex[i] */
            if(hex[i]>='0' && hex[i]<='9')
            {
                val = hex[i] - 48;
            }
            else if(hex[i]>='a' && hex[i]<='f')
            {
                val = hex[i] - 97 + 10;
            }
            else if(hex[i]>='A' && hex[i]<='F')
            {
                val = hex[i] - 65 + 10;
            }

            decimal += val * pow(16, len);
            len--;
        }

        printf("Hexadecimal number = %s\n", hex);
        printf("Decimal number = %d", decimal);
        return (decimal);
    }

    void imprimePaleta(PALETA color[])
    {
        int x1 = 45, y1 = 370, x2 = 105, y2 = 400;
        for (int i = 0; i < 5; i++)
        {
            setfillstyle(1, COLOR(color[i].Rojo, color[i].Verde, color[i].Azul));
            exterior(x1, y1, x2, y2, COLOR(color[i].Rojo, color[i].Verde, color[i].Azul));
            y1 = y2;
            y2 +=30;
        }
    }


void pideNombrePal(char nombre[])
{

}
