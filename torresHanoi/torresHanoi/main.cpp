//
//Nombre: Sara Vargas
//Torres de Hanoi
//

#include <iostream>
#include <math.h>
using namespace std;

void imprimirTorre(int num, int m, int o, int nl){//funcion para imprimir las torres
    while (nl <= num)
    {
        while (m < num - nl)
        {
            cout<<" ";
            m++;
        }
        while (o < ((nl * 2) - 1))
        {
            cout<<"*";
            o++;
        }
        m = 0;
        o = 0;
        nl++;
        cout<<"\n";
    }

}

void hanoi(int num, char A, char B, char C){// Funcion que recibe el numero de discos para trabajar y los nombres de cada torre
    
    char X[10], Y[10], Z[10];
    int N[10];
    int lim=0;
    char aux;
    bool cond = false;
    int m = 0;
    int o = 0;
    int nl = 0;
    
    while(num>0 && cond==false){ //ciclo que condiciona todas las repeticiones para que se realicen todos los movimientos
        
        while(num>1){//ciclo de cambio de posiciones cuando la cantidad de discos es mayor a uno
            lim=lim+1;
            N[lim]=num;
            X[lim]=A;
            Y[lim]=B;
            Z[lim]=C;
            num=num-1;//condicion que detiene este ciclo
            aux=B;
            B=C;
            C=aux;
        }
        cout<<"Mover un disco de"<<A<<" hacia "<<B<<endl;
        cond=true;//variable que puede detener el ciclo de repeticion principal
        
        if(lim>0){//ciclo de cambio de posicion cuando el lim es mayor a 0
            num=N[lim];
            A=X[lim];
            B=Y[lim];
            C=Z[lim];
            lim=lim-1;
            cout<<"Mover un disco de"<<A<<" hacia "<<B<<endl;
            imprimirTorre(num, m, o, nl);
            num=num-1;//variable que puede detener el ciclo principal
            aux=A;
            A=C;
            C=aux;
            cond=false;//variable que permite seguir con los demas movimientos
        
        }
    }
}


int main(int argc, const char * argv[]) {//main, aqui esta el codigo principal del programa
    int num;
    int mov;
    cout<<"Torres de Hanoi (Sara Vargas)"<<endl;
    cout<<"Ingrese el numero de discos que va a tener La torre: "<<endl;
    cin>>num;//ingreso y almacenamiento del numero de discos en la variable num
    mov=(pow(2,num)-1);//calculo del numero de movimientos base necesarios con la formula (2^n)-1
    cout<<"El numero de movimientos necesarios son: ";
    cout<<mov<<endl;
    
    hanoi(num,'1','2', '3');//Se hace el llamado de la funcion que realiza las operaciones
    
    return 0;
}
