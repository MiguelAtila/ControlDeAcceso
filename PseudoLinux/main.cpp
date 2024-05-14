#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Archivo {
    string nombre;
};

struct Usuario {
    int id;
    string nombre;
    vector<Archivo> archivos;
};



// Función para crear un nuevo usuario
Usuario crearUsuario(int id, string nombre) {
    Usuario nuevoUsuario;
    nuevoUsuario.id = id;
    nuevoUsuario.nombre = nombre;
    return nuevoUsuario;
}

// Función para crear un nuevo archivo
Archivo crearArchivo(string nombre) {
    Archivo nuevoArchivo;
    nuevoArchivo.nombre = nombre;
    return nuevoArchivo;
}

// Función para mostrar los archivos de un usuario
void mostrarArchivos(const Usuario& usuario) {
    cout << "Archivos de " << usuario.nombre << ":" << endl;
    for (const auto& archivo : usuario.archivos) {
        cout << archivo.nombre << endl;
    }
}


int main() {
    vector<Usuario> usuarios;

    // Creamos usuarios predeterminados
    usuarios.push_back(crearUsuario(0, "root"));
    usuarios.push_back(crearUsuario(1, "Usuario1"));
    usuarios.push_back(crearUsuario(2, "Usuario2"));
    usuarios.push_back(crearUsuario(3, "Usuario3"));

    while (true) {
        int idUsuario;
        cout << "Ingrese el ID de usuario (0 para root, 1 para Usuario1, 2 para Usuario2, 3 para Usuario3, -1 para salir): ";
        cin >> idUsuario;

        // Verificamos si el usuario quiere salir del programa
        if (idUsuario == -1) {
            cout << "Programa terminado." << endl;
            break;
        }

        // Verificamos si el ID de usuario es válido
        if (idUsuario < 0 || idUsuario >= usuarios.size()) {
            cout << "ID de usuario inválido." << endl;
            continue;
        }

        // Creamos la carpeta del usuario si no existe
        string nombreCarpeta = "Carpeta_" + usuarios[idUsuario].nombre;
        cout << "Bienvenido, " << usuarios[idUsuario].nombre << ". Se creará o se accederá a la carpeta '" << nombreCarpeta << "'." << endl;

        // Lógica de manejo de archivos
        while (true) {
            int opcion;
            cout << "Seleccione una opción:" << endl;
            cout << "1. Ver archivos" << endl;
            cout << "2. Crear archivo" << endl;
            cout << "3. Salir" << endl;
            cin >> opcion;

            if (opcion == 1) {
                mostrarArchivos(usuarios[idUsuario]);
            } else if (opcion == 2) {
                string nombreArchivo;
                cout << "Ingrese el nombre del archivo: ";
                cin >> nombreArchivo;
                usuarios[idUsuario].archivos.push_back(crearArchivo(nombreArchivo));
                cout << "Archivo creado exitosamente." << endl;
            } else if (opcion == 3) {
                cout << "Sesión cerrada." << endl;
                break;
            } else {
                cout << "Opción inválida." << endl;
            }
        }
    }

    return 0;
}
