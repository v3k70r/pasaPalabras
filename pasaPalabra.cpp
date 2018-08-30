#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>

#define MAX 40
using namespace std;
string toString(int n){
    stringstream ss;
	ss << n;
	return ss.str();
}
int hayUsuarios(){
	ifstream ent;
    ent.open("usuarios.dat");
    if (ent.fail()){
    	ent.close();
    	return 0;
	}
	ent.close();
	return 1;
}
void cargarUsuarios(string &usuarios, int &cu){
	ifstream ent;
    ent.open("usuarios.dat");
    while(cu < 400){
    	stringstream ss;
    	ss << ent;
        cout << ss.str() << endl;
        cu++;
    }
    ent.close();
}
void crearUsuario(string nombre, int &cu){
    if (hayUsuarios()){

     }
     else{
     	string archivo;
    	nombre = nombre + ':' + toString(cu) + '\n';
    	archivo = "usuarios.dat";
    	ofstream fs(archivo.c_str());
    	fs << nombre << endl;
    	fs.close();
     }
}
void juegoVacio(int &cu){
    string nombre;
    cout << "Ingrese su nombre: " << endl;
    cin >> nombre;
	crearUsuario(nombre, cu);
}
void menu(int &cu){
    cout << "Existe una sesion con " << (cu + 1) << " Usuarios." << endl;

}
void inicio(string &usuarios, int &cu){
    cout << "Bienvenido al juego!" << endl;
    if (hayUsuarios()){
    	cargarUsuarios(usuarios, cu);
    	menu(cu);
     }
    else{
    	juegoVacio(cu);
    	menu(cu);
    }
}


int main(){
	string usuarios[MAX];
    int cu = 0;
    inicio(usuarios[MAX], cu);
}
