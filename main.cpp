#include <iostream>
#include <cmath>

using namespace std;

float p[6], ply[6],q[6];

float division(int m, float r){
                q[0] = p[0];
                for(int i=1;i<=m;i++){
                    q[i] = (q[i-1]*r)+p[i];
                }
                cout << endl;

                for(int i=0;i<=m;i++){
                    cout << q[i] << " ";
                }

                return(q[m]);
}

int main(){
                int grado, menorAEpsilon=0;
                float r, x,x1, fx, fdx;
                float epsilon;
                cout << "Metodo Birge Vieta" << endl;
                cout << "Escribe el grado del polinomio: ";
                cin >> grado;
                cout << "Tolerancia de error: ";
                cin >> epsilon;

                for(int i = 0; i <= grado; i++){
                    cout << "Coeficiente x[" << grado-i << "] = ";
                    cin >> p[i];
                    ply[i] = p[i];
                }

                r = 1;
                x = r;

                do{
                    cout << endl << x << endl;
                    fx = division(grado,x);
                        for(int i=0;i<=grado;i++)
                            p[i]=q[i];

                    fdx = division(grado-1,x);
                    x1 = x - (fx/fdx);

                    if(fabs(x1-x) <= epsilon)
                        menorAEpsilon = true;

                    x = x1;

                    for(int i=0;i<=5;i++){
                        p[i]=ply[i];
                    }

                }while(!menorAEpsilon);

                cout << endl << "La raiz es: " << x1 << endl;
}
