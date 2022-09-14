#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Quiz #6
// 1. Utilizando esta classe agregue los atributos del vuelo: aerolinea, numero de vuelo, cantidad de pasajeros
// 2. Complete el constructor de la clase, de tal forma que se pueda modificar el flightTime para una hora y minutos específicos
// 3. Implementar alguna forma de convertir el time a un número entero de tal forma que entre menor la hora menor el número, eso en getIntTimeValue()
// 4. En el test.cpp, implementar la función fillFlights()
// fecha de entrega: jueves 8 de setiembre antes de las 10pm
// entrega al asistente al correo: kevinqj.2002@gmail.com
// subject: estructuras de datos - quiz #6
// adjuntan el archivo test.cpp y Flight.h

class Flight {

    private: 
        time_t flightTime;
        int aerolinea;
        int numeroVuelo;
        int cantidadPasajeros;


    public: 
        Flight(int pHour, int pMinutes, int pAerolinea, int pNumeroVuelo, int pCantidadPasajeros) {
            flightTime = time(NULL);
            
            tm *currentTime = localtime(&flightTime);

            aerolinea = pAerolinea;
            numeroVuelo = pNumeroVuelo;
            cantidadPasajeros = pCantidadPasajeros;

            currentTime->tm_hour = pHour;
            currentTime->tm_min = pMinutes;
        }
        
        char* flightTimeString() {
            char* result = ctime(&flightTime);
            return result;
        }

        int getIntTimeValue() {
            char buffer[5]; // buffer que contiene el timer
            int result = 0;

            time (&flightTime);
            strftime(buffer,sizeof(buffer),"%H%M",localtime(&flightTime)); // Obtener horas y minutos, colocar en el buffer
            string tostr(buffer); //convertir los 4 digitos a string
            result = stoi(tostr); // convertir el string a int

            return result;
        }


        void setAerolinea(int pAerolinea){
            aerolinea = pAerolinea;
        }

        int getAerolinea(){
            return aerolinea;
        }

        void setNumeroVuelo(int pNumeroVuelo){
            numeroVuelo = pNumeroVuelo;
        }

        int getNumeroVuelo(){
            return numeroVuelo;
        }


        void setCantidadPasajeros(int pCantidadPasajeros){
            cantidadPasajeros = pCantidadPasajeros;
        }

        int getCantidadPasajeros(){
            return cantidadPasajeros;
        }


        
};
