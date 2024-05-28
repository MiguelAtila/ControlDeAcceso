#include <iostream>
#include <list>
#include <fstream>
using namespace std;

// Estructura que representa a un usuario y su lista de archivos
struct Users {
    string User;              // Nombre del usuario
    list<string> Files;       // Lista de archivos del usuario
};

int main() {
    list<Users> users;        // Lista que contiene todos los usuarios
    Users user, * localUser;   // Estructura temporal para el usuario y puntero para el usuario local
    string username;          // Variable para almacenar el nombre del usuario ingresado
    int salir, menu, optUser;          // Variables para controlar la salida y la selección del menú
    string tmp, user_root, file_user;      // Variable temporal para almacenar el nombre del archivo
    ofstream fuser, ofRoot;             // Variable para escribir en el archivo de usuario
    ofstream tmpFile;          // Variable para escribir en el archivo de usuario
    ifstream ifRoot ("root");    // Variable para leer en el archivo de usuario
    

    if (ifRoot.is_open())//Existe
    {
        while (getline(ifRoot, user_root)) //Lee el archivo root
        {
            cout << "Loading user: " << user_root << endl;
            user.User = user_root;   // Asigna el nombre ingresado al nuevo usuario
            user.Files.clear();     // Limpia la lista de archivos del nuevo usuario (asegurando que esté vacía)

            ifstream fuser (user_root + ".usr");
            cout << "Archivos dentro del usuario: ";
            while (getline(fuser, file_user)) //Lee el archivo root
            {
                cout << file_user << " - ";
                user.Files.push_back(file_user);
            }
            cout << endl;
            users.push_back(user);  // Añade el nuevo usuario a la lista de usuarios
        }
        ifRoot.close();
    }
    else //No existe el archivo root
    {
        //Crear archivo root
        tmpFile.open("root");
        tmpFile.close(); 
    }
    

    do {

        cout << "\nMENU: " << endl << "1) Listar" << endl << "2) Agregar usuario" << endl;
        cin >> optUser;

        switch (optUser)
        {
        case 1:
            for (auto i : users)
            {
                cout << "user_:" << i.User << endl;
            }
            break;
        
        case 2:
            // Solicita el nombre del usuario
            cout << "Ingresa username: ";
            cin >> username;

            localUser = nullptr;  // Inicializa el puntero a null

            // Busca si el usuario ya existe en la lista
            for (auto& i : users) { // Se usa referencia para evitar copia innecesaria
                if (i.User == username) {
                    localUser = &i;     // Si encuentra el usuario, apunta a él
                    cout << "User exists" << endl;
                    break;              // Sale del bucle si encuentra el usuario
                }
            }

            // Si el usuario no existe, crea uno nuevo
            if (localUser == nullptr) {
                user.User = username;   // Asigna el nombre ingresado al nuevo usuario
                user.Files.clear();     // Limpia la lista de archivos del nuevo usuario (asegurando que esté vacía)

                users.push_back(user);  // Añade el nuevo usuario a la lista de usuarios
                localUser = &(users.back()); // Apunta al nuevo usuario añadido
            }

            // Bucle para manejar las opciones del menú
            do {
                cout << "Opciones:" << endl
                    << "\t1) Listar" << endl
                    << "\t2) Crear" << endl
                    << "\t3) Mostrar todos los usuarios y archivos" << endl
                    << "\t4) Salir" << endl
                    << "Selecciona una opcion: ";
                cin >> menu;

                switch (menu) {
                case 1: // Listar archivos del usuario actual
                    cout << "Archivos del usuario " << localUser->User << ":" << endl;
                    for (const auto& file : localUser->Files) {
                        cout << file << " - ";
                    }
                    cout << endl << endl;
                    break;

                case 2: // Crear un nuevo archivo para el usuario actual
                    cout << "Ingresa archivo: ";
                    cin >> tmp;
                    localUser->Files.push_back(tmp); // Añade el nuevo archivo a la lista del usuario
                    break;

                case 3: // Mostrar todos los usuarios y sus archivos en forma de tabla
                    cout << "Usuarios y sus archivos:" << endl;
                    for (const auto& i : users) {
                        cout << i.User << ":\t"; // Imprime el nombre del usuario seguido de dos puntos y una tabulación
                        for (const auto& file : i.Files) {
                            cout << file << "\t"; // Imprime cada archivo del usuario separado por tabulación
                        }
                        cout << endl; // Imprime un salto de línea para el siguiente usuario
                    }
                    break;

                case 4: // Salir del menú
                    break;

                default:
                    cout << "Opción no válida" << endl;
                    break;
                }
            } while (menu != 4); // Repite el menú hasta que el usuario elija salir
        break;
        }

            // Pregunta al usuario si desea salir del programa principal
            cout << "Quieres salir? (0: yes 1: no): ";
            cin >> salir;
            cout << endl;

        } while (salir == 1); // Repite el bucle principal hasta que el usuario decida salir

    // Guardar en archivo
    ofRoot.open("root");
    // Muestra todos los usuarios y sus archivos (este bucle es redundante y no se necesita en este contexto)
    for (const auto& i : users) {
        cout << i.User << " - ";
        ofRoot << i.User << endl;
        fuser.open(i.User + ".usr");
        
        for (const auto& file : i.Files) 
        {
            fuser << file << endl;
            cout << file << " ";
        }
        cout << endl;
        fuser.close();
    }
    ofRoot.close();
    cout << "Guardado" << endl;

    return 0;
}