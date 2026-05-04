#include <iostream>
#include <string>

using namespace std;

struct Mascota {
    string nombre;
    string especie;
    string raza;
    int edad;
    float peso;
};

void mostrarMenu(){
    cout << "\n=== Registro de mascota ===" << endl;
    cout << "1. Registrar mascota" << endl;
    cout << "2. Mostrar mascota" << endl;
    cout << "3. Clasificar por peso" << endl;
    cout << "4. Calcular edad equivalente" << endl;
    cout << "5. Modificar datos" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccionar una opcion: ";
}

string clasificarPeso(float peso) {
    if (peso < 5.0) return "Ligero";
    else if (peso <= 9.0) return "Medio";
    else return "Pesado";
}

int calcularEdadHumana(int edadMascota) {
    return edadMascota * 7;
}

int main(){
    Mascota m1;
    int opcion;
    bool registrada = false;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: 
                cout << "Nombre: "; getline(cin, m1.nombre);
                cout << "Especie: "; getline(cin, m1.especie);
                cout << "Raza: "; getline(cin, m1.raza);
                cout << "Edad: "; cin >> m1.edad;
                cout << "Peso (lbs): "; cin >> m1.peso;
                registrada = true;
                cout << "Mascota registrada con exito." << endl;
                break;

            case 2: 
                if(registrada) {
                    cout << "\n--- Datos de la Mascota ---" << endl;
                    cout << "Nombre: " << m1.nombre << "\nEspecie: " << m1.especie
                         << "\nRaza: " << m1.raza << "\nEdad: " << m1.edad
                         << " años\nPeso: " << m1.peso << " lbs" << endl;
                } else {
                    cout << "Primero registre una mascota (Opcion 1)." << endl;
                    cout << "Segundo registrar una mascota (Opcion 1)." << endl ;
                               }
                break;

            case 3: 
                if(registrada) {
                    cout << "Clasificacion de peso: " << clasificarPeso(m1.peso) << endl;
                } else {
                    cout << "Primero registre una mascota." << endl;
                }
                break;

            case 4: 
                if(registrada) {
                    cout << "Edad humana equivalente: " << calcularEdadHumana(m1.edad) << " anos." << endl;
                } else {
                    cout << "Primero registre una mascota." << endl;
                }
                break;

            case 5:
                if(registrada) {
                    cout << "--- Modificar Datos ---" << endl;
                    cout << "Nuevo Nombre (" << m1.nombre << "): "; getline(cin, m1.nombre);
                    cout << "Nueva Especie (" << m1.especie << "): "; getline(cin, m1.especie);
                    cout << "Nueva Raza (" << m1.raza << "): "; getline(cin, m1.raza);
                    cout << "Nueva Edad (" << m1.edad << "): "; cin >> m1.edad;
                    cout << "Nuevo Peso (" << m1.peso << "): "; cin >> m1.peso;
                    cout << "Datos actualizados." << endl;
                } else {
                    cout << "Primero registre una mascota." << endl;
                }
                break;

            case 6:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }
    } while(opcion != 6);

    return 0;
}
