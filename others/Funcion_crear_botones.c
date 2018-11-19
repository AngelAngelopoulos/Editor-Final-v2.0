void crearBotones(BOTONES bBot[10], int iNumBot, int iXx, int iYy, int iTamBot)
{
    int iCont,iXx,iYy, i;
    for(iCont=0;iCont<iNumBot;iCont++)
        {
        bBot[iCont].iCx=iXx;
        bBot[iCont].iCy=iYy;
        bBot[iCont].iCFx=iXx+iTamBot;
        bBot[iCont].iCFy=iYy+iTamBot/2;
        bBot[iCont].iColorF=7;
        bBot[iCont].iColorL=15;
        bBot[iCont].iCualBoton=iCont;

        if (bBot[iCont].iCualBoton % 2 == 0)
            bBot[iCont].iVisible = 0;
        else
            bBot[iCont].iVisible = 1;
        }
}
