#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);

//Variables globales
const int MAXCANDITATOS = 100;
string nombrecandidato[MAXCANDITATOS];
string apellidocandidato[MAXCANDITATOS];
string partido[MAXCANDITATOS];
int todosloscandidatos = 0;
int votos[MAXCANDITATOS] = {0};
int votostotal = 0;
// voids necesarios
void gotoxy();
void cuadro();
void ingresarcandidatos();
void mostrarcandidatos();
void votar();
void resultados();
void salir();
void menu();


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void cuadro(int x1, int y1, int x2, int y2){
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}
	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}

void ingresarcandidatos(){
	
	char respagregar;
	
	do{
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
	cuadro(20, 5, 100, 19);
	gotoxy(30,10);cout << "ingresar nombre sin apellido del candidato" << endl;
	gotoxy(80,10);cin >> nombrecandidato[todosloscandidatos];
	gotoxy(30,11);cout << "ingresar apellido del candidato" << endl;
	gotoxy(70,11);cin >> apellidocandidato[todosloscandidatos];
	gotoxy(30,12);cout << "ingresar partido politico" << endl;
	gotoxy(65,12);cin >> partido[todosloscandidatos];
	todosloscandidatos++;

	gotoxy(30,15);cout << "Candidato agregado." << endl;
	
	gotoxy(30,17);cout<< "Desea agregar otro candidato?  (S/N)" << endl;
	gotoxy(70,17);cin >> respagregar; 
	
	
	} while(respagregar == 's'|| respagregar == 'S');

	menu();
	
}
	
void mostrarcandidatos(){
	char respmostrar;
	int posy = 11;
	
	do{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
		cuadro(20, 3, 100, 26);
		gotoxy(45,8);cout << "Candidatos disponibles:" << endl;
    	for (int i = 0; i < todosloscandidatos; ++i) {
    	gotoxy(30,posy); cout << "ID Candidato: " << i+1 << "Nombre: " << nombrecandidato[i] << ", Apellido: " << apellidocandidato[i] << ", Partido: " << partido[i] << endl;
    	posy++;
	}
	gotoxy(30,25);cout << "Desea regresar al menu?  (S/N)";
	gotoxy(65,25);respmostrar = tolower(getchar());
	
	} while (respmostrar != 's');

	menu();    
    
}
	
void votar() {
	char respvotar;
    int idcandidato;
    int posy = 11;
    
    
    system("cls");
    SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
	cuadro(20, 5, 100, 19);
    
    gotoxy(37,8); cout << "Seleccione el ID del candidato al que desea votar: ";
    cin >> idcandidato;
	votostotal++;
    if (idcandidato >= 1 && idcandidato <= todosloscandidatos) {
        votos[idcandidato - 1]++;
		gotoxy(30,posy);cout << "¡Ha votado por " << nombrecandidato[idcandidato - 1] << " " << apellidocandidato[idcandidato - 1] << " del partido " << partido[idcandidato - 1] << "!" << endl;
		
    } 
	else {
        cout << "ID de candidato inválido. Vuelva a intentarlo." << endl;
    }
    
    menu(); 
	 
}

void resultados(){
	char respresultados;
	int posy = 11;
	
	do{
	
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
	cuadro(20, 3, 100, 26);
	gotoxy(40,8); cout << "Resultados" << endl;
	
	for (int i = 0; i < todosloscandidatos; ++i) {
        gotoxy(30,posy);cout << "Candidato: " << nombrecandidato[i]<< " "<< apellidocandidato[i] << ", Partido: " << partido[i] << ", Votos: " << votos[i] << ", Porcentaje:  " << (votos[i] * 100)/ votostotal << " %"<< endl;
        posy++;
    }
    gotoxy(30,25);cout << "Desea regresar al menu?  (S/N)";
	gotoxy(65,25);respresultados = tolower(getchar());
    
	} while (respresultados != 's');
    
   menu();  

}

void salir(){
	
	gotoxy(45, 28);cout << "Saliendo del programa..." << std::endl;
    exit(0);
	
}

void menu(){
	
	int respmenu;

	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, FOREGROUND_RED | FOREGROUND_GREEN);
	cuadro(20, 5, 100, 19);
	gotoxy(43,7);cout << "Bienvenido sistema de votaciones local."<< endl;
	gotoxy(55,9);cout << "TANGAMANDAPIO." << endl;
	gotoxy(30,11);cout << "1 - Agregar candidatos." << endl;
	gotoxy(30,12);cout << "2 - Mostrar candidatos." << endl;
	gotoxy(30,13);cout << "3 - Votaciones." << endl;
	gotoxy(30,14);cout << "4 - Resultados." << endl;
	gotoxy(30,15);cout << "5 - Salir." << endl;
	gotoxy(30,17);cout << "Digite una opcion" << endl;
	gotoxy(50,17);cin >> respmenu;
	
	switch (respmenu){
		
		case 1:
		ingresarcandidatos();
		break;
		case 2:
		mostrarcandidatos();
		break;
		case 3:
		votar();
		break;
		case 4:
		resultados();
		break;
		case 5:
		salir();
		break;
		default:
		cout << "Opcion no valida" << endl;
		break;

	}
}

int main() {
	
	menu();

    return 0;
}
