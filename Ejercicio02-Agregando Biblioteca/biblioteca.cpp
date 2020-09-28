#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

string libros[15][3];

void cargarLibros() {
    
	libros[0][0] = "Algoritmos"; 
    libros[0][1] = "Algoritmos y Programacion (Guia para docentes)";
    libros[0][2] = "Juan Carlos Lopez Garcia";

	libros[1][0] = "Algoritmos"; 
    libros[1][1] = "Apuntes de Algoritmos y Estructuras de Datos";
    libros[1][2] = "ALfred V. Aho, Jeffrey D. Ullman";

	libros[2][0] = "Algoritmos"; 
    libros[2][1] = "Breves Notas sobre Analisis de Algoritmos";
    libros[2][2] = "Jorge L. Ortega Arjona";

	libros[3][0] = "Algoritmos"; 
    libros[3][1] = "Fundamentos de Informatica y Programacion";
    libros[3][2] = "Gregorio Martin Quetglas";

	libros[4][0] = "Algoritmos"; 
    libros[4][1] = "Temas selectos de estructuras de datos";
    libros[4][2] = "Jorge L. Ortega Arjona";

	libros[5][0] = "Algoritmos"; 
    libros[5][1] = "Teoria sintactico-gramatical de objetos";
    libros[5][2] = "Eugenio Bahit";

	libros[6][0] = "Base de Datos"; 
    libros[6][1] = "Apuntes de Base de Datos 1";
    libros[6][2] = "Eva Gomez Ballester";

	libros[7][0] = "Base de Datos"; 
    libros[7][1] = "Base de Datos (2005)";
    libros[7][2] = "Antonio Hernandez";

	libros[8][0] = "Base de Datos"; 
    libros[8][1] = "Base de Datos (2011)";
    libros[8][2] = "Mercedez Marques";

	libros[9][0] = "Base de Datos"; 
    libros[9][1] = "Base de Datos Avanzadas (2013)";
    libros[9][2] = "Juan Carlos Amaya";

	libros[10][0] = "Base de Datos"; 
    libros[10][1] = "Diseno Conceptual de Bases de Datos";
    libros[10][2] = "Elena Castro";

    libros[11][0] = "Ciencia Computacional"; 
    libros[11][1] = "Breves Notas sobre Automatas y Lenguajes";
    libros[11][2] = "Maria Elizabeth Villeda";

	libros[12][0] = "Ciencia Computacional"; 
    libros[12][1] = "Breves Notas sobre Teoria de la Computacion";
    libros[12][2] = "Mateo Quintanilla";

	libros[13][0] = "Metodologias de desarrollo de software"; 
    libros[13][1] = "Compendio de Ingenieria del Software";
    libros[13][2] = "Elmer Zacarias";

	libros[14][0] = "Metodologias de desarrollo de software"; 
    libros[14][1] = "Diseno agil con TDD";
    libros[14][2] = "Stephan Aguilar";

}


int main(int argc, char const *argv[])
{
    cargarLibros();

    srand (time(NULL));
    
    bool salir = false;

    while (salir == false)
    {
        string buscar = "";
        system("cls");
        cout << "Ingrese la descripcion del libro que busca: ";
        cin >> buscar;

        
        for (int i = 0; i < 15; i++)
        {
            string libro = libros[i][1];
            string autor = libros[i][2];
            string libroEnminuscula = libro;
            
            transform(libroEnminuscula.begin(), libroEnminuscula.end(), libroEnminuscula.begin(), ::tolower);
            transform(buscar.begin(), buscar.end(), buscar.begin(), ::tolower);

            if (libroEnminuscula.find(buscar) != string::npos) {
                cout << "Libro encontrado: " << libro << endl << "Autor: " << autor << endl;
                cout << endl;
                cout << "Tambien te sugerimos estos libros: " << endl;

                int sugerencia1 = rand() % 14 + 1;
                int sugerencia2 = rand() % 14 + 1;
                int sugerencia3 = rand() % 14 + 1;

                cout << " Sugerencia 1: " << libros[sugerencia1][1] << endl;
                cout << " Sugerencia 2: " << libros[sugerencia2][1] << endl;
                cout << " Sugerencia 3: " << libros[sugerencia3][1] << endl;

                salir = true;
                break;
            }
        }
        

        if (salir == false) {
            char continuar = 'n';

            while(true) {
                system("cls");
                cout << "No se encontro el libro que busca. Desea continuar? s/n ";
                cin >> continuar;

                if (continuar == 's' || continuar == 'S') {
                    break;
                } else if (continuar == 'n' || continuar == 'N') {
                    salir = true;
                    break;
                }
            }
        }
    }
    

    return 0;
}