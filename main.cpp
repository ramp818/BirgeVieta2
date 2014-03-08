#include <iostream>
#include <stdlib.h>

using namespace std;

//division sintetica
void Division(double polinomio[],int grado,double x,double &residuo,double &residuoDerivada){
    double aux=polinomio[grado],division[grado];
    division[grado]=aux;
    for(int i=grado-1;i>=0;i--){
        division[i]=polinomio[i]+aux;
        aux=0;
        aux=division[i]*x;
    }
    residuo=division[0];
    int tam=grado;
    for(int i=tam;i>=1;i--)
        residuoDerivada=residuoDerivada*x+division[i];

}

int main()
{
    int grado,iteraciones,contRaices=1,contIteracion=1;
    double error,residuo=0,residuoDerivada=0;

    cout<<"Grado del polinomio"<<endl;
    cin>>grado;
    double polinomio[grado];
    for(int i=grado;i>=0;i--)
    {
        cout<<"Coeficiente x^"<<i<<" ";
        cin>>polinomio[i];
    }
    //double x=-(polinomio[1])/polinomio[0];
    double x=1, xAnt;
    cout << "x inicial es: " << x;
    cout<<endl;
    cout<<"Maximo de iteraciones: ";
    cin>>iteraciones;
    cout<<endl;
    cout<<"Toleracia de error: ";
    cin>>error;
    do
    {
       xAnt=x;
       Division(polinomio,grado,x,residuo,residuoDerivada);
       x=xAnt-(residuo/residuoDerivada);
       contIteracion++;

    }while(contIteracion<=iteraciones);
    cout<<residuo<<" "<<residuoDerivada<<endl;
    cout<<xAnt<<endl;

    return 0;
}
