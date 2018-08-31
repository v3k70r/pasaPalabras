#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>
using namespace std;

#define MAX 40
void textColor(const unsigned short text_color,const unsigned short background_color ){
	cout << "33[38;5;" << text_color << "m";
	cout << "33[48;5;" << background_color << "m";
}
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
void cargarUsuarios(string usuarios[], int &cu){
	ifstream ent;
  int i;
  ent.open("usuarios.dat");
  for(i = 0; !ent.eof() ; i++){
    ent >> usuarios[i];
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
string obtener(int p, string texto){
  int i;
  int s = 0;
  string retornar;
  if(p == 0){
    for(i = 0; texto[i] != ':'; i++){
      retornar += texto[i];
    }
    return retornar;
  }
  else if(p == 1){
    for(i = 0; s < 2; i++){
      if(s == 1){
        if(texto[i] != ':'){
          retornar += texto[i];
        }
      }
      if(texto[i] == ':'){
        s++;
      }
    }
    return retornar;
  }
  else{
    cout << "Indice fuera de rango" << endl;
  }
  return 0;
}
void rosco(char letra){
	ifstream rosco;
	string linea;
  int i, j;
	rosco.open("Rosco.txt");
	for(i = 0; i < 26; i++){
		getline(rosco,linea);
		for(j = 0; j < linea.length(); j++){
			if(linea[j]==letra){
        cout << "\033[1;31m" << linea[j] << "\033[0m\n";

			}
			else{
				cout << linea[j];
			}
		}
			cout<<endl;
	}
	return;
}

void cargarDiccionario(string nombre, string lcc[], string observatorios[], string lugares[],int &clcc, int &co, int &cl){
  ifstream ent;
  int i;
  ent.open(nombre);
  cout << nombre << endl;
  if(ent.fail()){
    cout << "Ha ocurrido un fallo a cargar el diccionario " << nombre << endl;
  }
  else{
      if(nombre == "lcc.dat"){
        for(i = 0; ent.eof() ; i++){
					cout << ent << endl;
          ent >> lcc[i];
          clcc++;
        }
      }
      else if(nombre == "observatorios.dat"){
        for(i = 0; ent.eof() ; i++){
          ent >> observatorios[i];
          co++;
        }
      }
      else if(nombre == "lugares.dat"){
        for(i = 0; ent.eof() ; i++){
          ent >> lugares[i];
          cl++;
        }
      }
  }
  ent.close();
}

int juego(){
  string lcc[MAX], lugares[MAX], observatorios[MAX];

  return 0;
}
void menu(string usuarios[], int &cu){
    int o;
    string nombre;
    printf("1)Leer reglas del juego\n2)Continuar partida\n3)Nueva Partida :D\n4)Ver Rankin\nIngrese opcion: ");
    cin >> o;
    int i;
    string buscar;
    switch (o) {
      case 1:
        cout << "Reglas de Ejecución: \n 1)Si ejecuta este juego desde consola, esta debe estar posicionada en la carpeta que contiene este archivo, pues es ahí donde buscará los archivos requeridos por el juego." << endl;
        menu(usuarios, cu);
      case 2:
        cout << "Ingrese su nombre de usuario: " << endl;
        cin >> nombre;
        for(i = 0; i < cu; i++){
          if(obtener(0, usuarios[i]) == nombre){
            ifstream ent;
            buscar = obtener(1, usuarios[i]) + ".dat";
            cout << buscar << endl;
            ent.open(buscar);
            if(ent.fail()){
              cout << "El usuario no tiene registros." << endl;
              menu(usuarios, cu);
            }
            else{
              juego();
            }
          }
        }
        break;
      case 3:
        break;
      case 4:
        break;
    }

}
void inicio(string usuarios[], int &cu){
    cout << "Bienvenido al juego!" << endl;
    if (hayUsuarios()){
    	cargarUsuarios(usuarios, cu);
    	menu(usuarios, cu);
     }
    else{
    	juegoVacio(cu);
    	menu(usuarios, cu);
    }
}
int main(){
	  string usuarios[40], lcc[40], observatorios[40], lugares[40];
    int i, clcc, co, cl;
    int cu = 0;
		cargarUsuarios(usuarios, cu);
		for(i = 0; i < cu; i++){
			cout << usuarios[i] << endl;
		}
    cargarDiccionario("lcc.dat", lcc, observatorios, lugares, clcc, co, cl);
    cargarDiccionario("lugares.dat", lcc, observatorios, lugares, clcc, co, cl);
    cargarDiccionario("observatorios.dat", lcc, observatorios, lugares, clcc, co, cl);
		cout << clcc << endl;
		cout << co << endl;
		cout << cl << endl;
    for(i = 0; i < clcc; i++){
      cout << lcc[i] << endl;
    }
    for(i = 0; i < co; i++){
      cout << observatorios[i] << endl;
    }
    for(i = 0; i < cl; i++){
      cout << lugares[i] << endl;
    }
}
