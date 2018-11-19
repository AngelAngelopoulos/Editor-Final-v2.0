#ifndef EDITOR_WORDS_H_INCLUDED
#define EDITOR_WORDS_H_INCLUDED

int ponletras(char cadena[],int iXx,int iYy,int iTam,int iColorL,int iColorF);
int LetrasEnt(char cLetras[]);
void LetrasStr(char cNombre[], int ix, int iy);
void CuadroTexto();

#endif // EDITOR_WORDS_H_INCLUDED

int EscribeDato(int xL1, int yL1){
    CuadroTexto();
    setbkcolor(15);
    int borrar = 0;
    int res = 0;
    do {
    outtextxy(260, 300, "x = ");
    outtextxy(360, 300, "y = ");
    setbkcolor(0);
    char cLetras[25];
    borrar = ponletras(cLetras,xL1, yL1, 25, 15, 0);
    res = LetrasEnt(cLetras);
    printf("El numero es: %d\n", res);
    }while(borrar != 0);
    return (res);
}

//cadena: Variable para almacenar la cadena capturada
//iXx: Variable de la coordenada X a ser colocada en la pantalla la cadena de texto
//iYy: Variable de la coordenada Y a ser colocada en la pantalla la cadena de texto
//iTam: Tama�o de la variable cadena que es el m�ximo n�mero de caracteres a capturar
//iColorL: Color de la letra a visualizar
//iColorF: Color de fondo para dar el efecto de parpadeo.
int ponletras(char cadena[],int iXx,int iYy,int iTam,int iColorL,int iColorF){
     char tecla='0',auxLetras[30];
     int iBand1,iCont=0,iConta=0, borrar = 0;
     strncpy(cadena,"\0",iTam);
     strncpy(auxLetras,"\0",30);
     tecla='0';
     setcolor(iColorL);
     outtextxy(iXx,iYy,auxLetras);
     while(tecla!=13){
        iBand1=-1;
        do
		  {
		    while(!kbhit() && (iConta++ < 700));
		    setcolor(iColorL);
		    //(10+8)/2 es el tama�o de las letras modificar aqui si se cambia el tama�o de letra
		    outtextxy(iXx+(strlen(auxLetras)*(int)((10+8)/2)),iYy,"_");
		    iConta = 0;
		    while(!kbhit() && (iConta++ < 700));
		    setcolor(iColorF);
		    outtextxy(iXx+(strlen(auxLetras)*(int)((10+8)/2)),iYy,"_");
		    iConta=0;
		    if(kbhit()){
			   tecla=getch();
			   iBand1=-1;
			   if(tecla == 8)
                return 1;
			   if((tecla==0)||(tecla==27)){
				     tecla=getch();
				     iBand1=0;
               }
			   if(iBand1!=0)
				 iBand1=1;
		     }
		}while(iBand1!=1);
		if(tecla!=13){
		   setcolor(iColorF);
		   outtextxy(iXx,iYy,auxLetras);
		   setcolor(iColorL);
    	   cadena[iCont]   = tecla;
           cadena[iCont+1] = '\0';
           auxLetras[iCont]   = tecla;
           auxLetras[iCont+1] = '\0';
           outtextxy(iXx,iYy,auxLetras);
           iCont++;
		   }
		}
		return (borrar);
}

int LetrasEnt(char cLetras[])
{
    int numero = 0;
    numero = atoi(cLetras);
    return(numero);
}

void LetrasStr(char cNombre[], int ix, int iy)
{
    int borrar = 0;
    do {
        //strcpy()
        //char cNombre[] = "\0";
        CuadroTexto();
        setbkcolor(15);
        outtextxy(260, 300, "Escriba el nombre del archivo(con "); outtextxy(260, 315, "extension .dat): ");
        setbkcolor(0);
        borrar = ponletras(cNombre, ix, iy, 25, 15, 0);
        printf("%s", cNombre);
    } while(borrar != 0);
}

void CuadroTexto()
{
    exterior(250, 250, 550, 450, 7);
    interior(255, 255, 545, 445, 8);
}

