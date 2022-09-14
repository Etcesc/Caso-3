#include <iostream>
#include "conio.h"
#include <string.h>
#include "queue.h"
#include "stack.h"
#include "Flight.h"

using namespace std;

Stack<int>* cola1 = new Stack<int>();

        int Dentro(char dato){ // Posicion Dentro de Parentesis
            if (dato == '+' || dato == '-'){
                return 1;
            }
            else if (dato == '*' || dato == '/'){
                return 2;
            }
            else if (dato == '^'){
                return 3;
            }
            else{
                return 0;
            }
        }

        int Fuera(char dato){ // Posicion Fuera de Parentesis
            if (dato == '+' || dato == '-'){
                return 1;
            }
            else if (dato == '*' || dato == '/'){
                return 2;
            }
            else{
                return 4;
            }
        }   

        void enqueue(int a) {
            cola1->push(new int (a));
        }

        void dequeue() {
            cola1->pop();            
        }

        void front() {
            cola1->top();
        }
/*
        bool isEmpty1() {
            return cola1->isEmpty();
        }*/

        void fillFlights(int pCantidad, int pStartHour, int pEndHour) {
            for(int i =0; i<= pCantidad; i++)
            {
                int var = rand()%2400 + 1;
                cout << var << endl;
            }
        } 

int main() {

    Stack<char>* pila1 = new Stack<char>();
    

    pila1->push(new char('1'));
    pila1->push(new char('+'));
    pila1->push(new char('('));
    pila1->push(new char('4'));
    pila1->push(new char('*'));
    pila1->push(new char('7'));
    pila1->push(new char(')'));
    pila1->push(new char('/'));
    pila1->push(new char('5'));
    pila1->push(new char('-'));
    pila1->push(new char('4'));
    pila1->push(new char('^'));
    pila1->push(new char('9'));

    // 1) Proceso de infijo y posfijo 
    // Por mas que la fila este construida, no estan funcionando los outputs, en su lugar, se puede escribir el input en la consola 
    // y esta resolvera el ejercicio que se introduzca a traves de las funciones utilizadas.
    char *expr[13]; 
    char* dato;
    cout<< "Infijo: \t";
    for (int i=0; i<13; i++){
        cout<<expr[i]<<" ";
    }
    cout<< "\n\nPosfijo: \t";
    for (int i=0; i<13; i++){
        switch(*expr[i]){
            

            case '+': case '-': case '*': case '/': case '^': case '(':
                if(pila1 != NULL){
                    dato = pila1->pop();

                    while (pila1 != NULL && Dentro(*dato) >= Fuera(*expr[i])){
                        cout<< dato<<" ";
                        dato = pila1->pop();
                    }
                    pila1->push(dato);
                    pila1->push(expr[i]);
                }
                else{
                    pila1->push(expr[i]);
                }
            break;
        case ')':
            if(pila1!=NULL){
                dato = pila1->pop();
                while(pila1!=NULL && *dato != '('){
                    cout<< dato << " ";
                    dato = pila1->pop();
                }
            }
        break;
        default:
            cout<< *expr[i]<<" ";
        }
    }

    while(pila1 !=NULL){
        cout<<pila1->pop();
    }



    // 2) creacion de cola a partir de pila
    // Las funciones se encuentran mas arriba en este .cpp
    // Debido a problemas con el control de la pila, y para no influenciar a errores del programa, no se pueden correr las funciones
 /*    enqueue(5);
     enqueue(9);
     enqueue(14);
     enqueue(6);
     enqueue(2);

     dequeue();
     dequeue();
     
     front();

     isEmpty1();*/



// 3) administracion de queues de aviones
// Solucion no disponible, no se pudo terminar a tiempo, y faltan funciones


    Flight vuelo(4, 35, 5, 2323, 450);
    cout << vuelo.flightTimeString() << "y el entero es: " << vuelo.getIntTimeValue() << endl;

    Flight otroVuelo(14, 20, 8, 123123, 651);
    cout << otroVuelo.flightTimeString() << "y el entero es: " << otroVuelo.getIntTimeValue() << endl;

    cout << endl << "Horas de salida de vuelos: " << endl;

    fillFlights(7,1945,2114);



}
