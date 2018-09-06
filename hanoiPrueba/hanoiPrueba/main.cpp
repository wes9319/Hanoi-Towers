//
//  main.cpp
//  hanoiPrueba
//
//  Created by Elvis Vasquez on 11/25/16.
//  Copyright © 2016 EWVV. All rights reserved.
//
#include <iostream>
//#include <conio.h>
using namespace std;

void ToresDeHanoiIterativo(int num,char origen,char destino,char auxiliar)
{
    char pilaO[10],pilaD[10],pilaX[10];
    int pilaN[10];
    int tope;
    char varaux;
    bool band;
    tope=0;
    band=false;
    while(num>0 && band==false)
    {
        while(num>1)
        {
            tope=tope+1;
            pilaN[tope]=num;
            pilaO[tope]=origen;
            pilaD[tope]=destino;
            pilaX[tope]=auxiliar;
            num=num-1;
            varaux=destino;
            destino=auxiliar;
            auxiliar=varaux;
        }
        cout<<"Mover un disco de"<<origen<<"-->"<<destino<<endl;
        band=true;
        if(tope>0)
        {
            num=pilaN[tope];
            origen=pilaO[tope];
            destino=pilaD[tope];
            auxiliar=pilaX[tope];
            tope=tope-1;
            cout<<"Mover un disco de"<<origen<<"-->"<<destino<<endl;
            num=num-1;
            varaux=origen;
            origen=auxiliar;
            auxiliar=varaux;
            band=false;
        }
    }
}
int main(int argc, const char * argv[])
{
    int num;
    cout<<"Ingrese el numero de discos:";
    cin>>num;
    ToresDeHanoiIterativo(num,'O','D','A');
    return 0;
}
