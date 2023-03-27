//== LIBRERIAS ==
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//== LIBRERIA EXTRA - GOTOXY.H ==
void gotoxy(int x,int y){
	
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}

//== VARIBLES GLOBALES ==
int g_pasajero=0;
string g_salida,g_destino,g_aerolinea,g_carga;


//== CLASE PADRE ==
class Avion{
	
	protected: //Atributos
		
		string aerolinea,salida,destino;
	
	public: //Metodos
	
		Avion(); //Constructor
		~Avion(); //Destructor
		
		//Setters
		void setAerolinea(string);
		void setSalida(string);
		void setDestino(string);
		
		//Getters
		string getAerolinea();
		string getSalida();
		string getDestino();
		
		//Metodos - Acciones
		void despegue();
		void vuelo();
		void aterrizaje();
};

//Constructor
Avion::Avion(){
}

//Destructor
Avion::~Avion(){
}

//Metodos - Setters
void Avion::setAerolinea(string _aerolinea){
	
	this->aerolinea = _aerolinea;	
}

void Avion::setSalida(string _salida){
	
	this->salida = _salida;
}


void Avion::setDestino(string _destino){
	
	this->destino = _destino;
}

//Metodos - Getters
string Avion::getAerolinea(){
	
	return this->aerolinea;	
}

string Avion::getSalida(){
	
	return this->salida;
}


string Avion::getDestino(){
	
	return this->destino;
}


//Metodos - Acciones
void Avion::despegue(){
	
	//Mostrar punto de partida del avión hasta su destino
	gotoxy(41,8); cout<<"DESDE: "<<this->salida;
	gotoxy(60,8); cout<<"HASTA: "<<this->destino;

	//Barra de carga
	for(int i=41;i<77;i++){
		Sleep(10);
		Beep(750,250);
		gotoxy(i,6); printf("%c",219); //Pintar los cuadros blancos

	}
}

void Avion::vuelo(){
	
	gotoxy(14,7); printf("%c",158); //Pintar avión en el radar
}

void Avion::aterrizaje(){
	
	gotoxy(14,7); printf(" "); //Borrar del radar
	
	gotoxy(43,10); cout<<"EL AVION LLEGO CON EXITO!";
	
	Sleep(2000);
	
	for(int i=41;i<77;i++){
		
		gotoxy(i,6); printf(" "); //Borrar los cuadros blancos
	}
		
	Beep(1000,10);
}

//== CLASE HIJA == (AVIÓN COMERCIAL)
class Comercial : public Avion{
	
	protected: //Atributos
	
		int pasajeros=0;
	
	public: //Metodos
	
	Comercial();
	~Comercial();
	
	//Setters
	void setPasajeros(int);
	
	//Getters
	int getPasajeros();
};

//Constructor
Comercial::Comercial(){
}

//Destructor
Comercial::~Comercial(){
}

//Metodos - Setters
void Comercial::setPasajeros(int _pasajeros){
	
	this->pasajeros = _pasajeros;
	
}

//Metodos - Getters
int Comercial::getPasajeros(){
	
	return this->pasajeros;	
}

//== CLASE HIJA == (AVIÓN CARGA)
class Carga : public Avion{
	
	protected: //Atributos
	
	string carga;
	
	public: //Metodos
	
	Carga(); //Constructor
	~Carga(); //Destructor
	
	//Setters
	void setCarga(string);
	
	//Getters
	string getCarga();
};

//Constructor
Carga::Carga(){
}

//Destructor
Carga::~Carga(){
}

//Metodos - Setters
void Carga::setCarga(string _carga){
	
	this->carga = _carga;
	
}

//Metodos - Getters
string Carga::getCarga(){
	
	return this->carga;	
}

//== PROTOTIPO DE FUNCIÓN ==

void Menu();
void Progreso();
void Opciones();
void Graficos();

//== FUNCIÓN PRINCIPAL ==
int main(){
	
	//== CONFIGURACIÓN ESTETICA ==
	system("color A"); //Cambiar color del fondo y del texto
	
	
	//== TITULO SUPERIOR DE LA VENTANA ==
	SetConsoleTitle("AEREOPUERTO"); 
	
	Menu();
	
	getch();
	return 0;
}

void Divisiones_Grafico(){
	
	//==MARCO==

		//Top-Bottom
		for(int i=0;i<79;i++){
		gotoxy(i,0); printf("%c",205);
		gotoxy(i,24); printf("%c",205);
		gotoxy(i,12); printf("%c",205); //Relleno - Uniones
	}
	
		//Left-Right
		for(int i=1;i<24;i++){
		gotoxy(0,i); printf("%c",186);
		gotoxy(79,i); printf("%c",186);
		gotoxy(20,i); printf("%c",186);	//Relleno - Uniones
	}
	
		//Esquinas - Inferio izquierda
		gotoxy(0,24); printf("%c",200);
	
		//Esquinas - Inferio Derecha
		gotoxy(79,24); printf("%c",188);
		
		//Esquinas - Superior derecha
		gotoxy(79,0); printf("%c",187);
		
		//Esquinas - Superior izquierda
		gotoxy(0,0); printf("%c",201);
		
		//Uniones
		gotoxy(20,0); printf("%c",203); //Top
		gotoxy(20,24); printf("%c",202); //Bottom
		gotoxy(0,12); printf("%c",204); //Left
		gotoxy(79,12); printf("%c",185); //Right
		gotoxy(20,12); printf("%c",206); //Center
}

void Radar_Grafico(){
	
	//gotoxy(8,1); printf("RADAR"); //Title
	
	for(int i=3;i<=9;i++){  //Top - Bottom
		gotoxy(10,i); printf("%c",179);
	}
	
	for(int i=5;i<=15;i++){  ////Left - Right
		gotoxy(i,6); printf("%c",196);
	}
	
	gotoxy(10,6); printf("%c",197); //Center

	//Flechas

	gotoxy(10,2); printf("N"); //Top
	gotoxy(10,10); printf("S"); //Bottom
	
	gotoxy(4,6); printf("O"); //Left
	gotoxy(15,6); printf("E"); //Right
	
}


void Menu(){
	
	int opc=0; //Variable del menú
	
	//== ISTANCIAR OBJETOS ==
	Comercial obj1;
	Carga obj2;
	
	
	gotoxy(8,14); printf("MENU"); //Titulo
	
	do{
			
	system("cls"); //Borrar pantalla
	Graficos(); //Llama a todo lo visual
		
		//Menu
		gotoxy(2,16); printf("[1]- USAR AVION");
		gotoxy(2,17); printf("[2]- ESTADISTICAS");
		gotoxy(2,18); printf("[3]- PAPELES");
		gotoxy(2,19); printf("[4]- SALIR");
		gotoxy(10,22); //Posición del cursor
		cin>>opc;
		
	}while(opc>5 || opc<0); //Condiciones de repetición
	
	
	switch(opc){
		
	case 1: //Seleccionar avión
		
		do{
			system("cls"); //Borrar pantalla
			Graficos(); //Llama a todo lo visual
			
			//Menu
			gotoxy(40,14); printf("SELECCIONE EL TIPO DE AVION");
			gotoxy(35,16); cout<<"[1]-COMERCIAL";
			gotoxy(35,17); cout<<"[2]-CARGA";
			gotoxy(35,18); //Posición del cursor
			cin>>opc;
			
		}while(opc>3 || opc<0);//Condiciones de repetición
		
		switch(opc){
			
			case 1: //Avion comercial
			
					system("cls"); //Borrar pantalla
					Graficos(); //Llama a todo lo visual
					
					//Menu
					gotoxy(40,14); printf("RELLENE LOS DATOS DE VUELO");
					
					gotoxy(35,16); cout<<"Punto de salida del avion:";
					gotoxy(62,16); cin>>g_salida;
					gotoxy(35,17); cout<<"Destino del avion:";
					gotoxy(54,17); cin>>g_destino;
					gotoxy(35,18); cout<<"Cantidad de pasajeros:";
					gotoxy(58,18); cin>>g_pasajero;
					gotoxy(35,19); cout<<"Aerolinea:";
					gotoxy(46,19); cin>>g_aerolinea;
					
					//== LLAMAR METODOS ==
					
						//Setters
							obj1.setSalida(g_salida);
							obj1.setDestino(g_destino);
							obj1.setPasajeros(g_pasajero);
							obj1.setAerolinea(g_aerolinea);
						
						//Acciones
							obj1.vuelo();
							Sleep(500);
							obj1.despegue();
							Sleep(500);
							obj1.aterrizaje();
							Menu();
				break;
			
			case 2: //Avion de carga
				
					system("cls"); //Borrar pantalla
					Graficos(); //Llama a todo lo visual
					
					//Menu
					gotoxy(40,14); printf("RELLENE LOS DATOS DE VUELO");
					
					gotoxy(35,16); cout<<"Punto de salida del avion:";
					gotoxy(62,16); cin>>g_salida;
					gotoxy(35,17); cout<<"Destino del avion:";
					gotoxy(54,17); cin>>g_destino;
					gotoxy(35,18); cout<<"Nombre de la carga:";
					gotoxy(55,18); cin>>g_carga;
					gotoxy(35,19); cout<<"Aerolinea:";
					gotoxy(46,19); cin>>g_aerolinea;
					
					//== LLAMAR METODOS ==
					
						//Setters
							obj2.setSalida(g_salida);
							obj2.setDestino(g_destino);
							obj2.setCarga(g_carga);
							obj2.setAerolinea(g_aerolinea);
						
						//Acciones
							obj2.vuelo();
							Sleep(500);
							obj2.despegue();
							Sleep(500);
							obj2.aterrizaje();
							Menu();
			break;
			
			default:
				
				Menu();
			break;
}
		
	break;
	
	case 2: //Mostrar estadisticas	
	
		do{
			system("cls"); //Borrar pantalla
			Graficos(); //Llama a todo lo visual
			
			//Menu
			gotoxy(40,14); printf("SELECCIONE EL TIPO DE AVION");
			gotoxy(35,16); cout<<"[1]-COMERCIAL";
			gotoxy(35,17); cout<<"[2]-CARGA";
			gotoxy(35,18); //Posición del cursor
			cin>>opc;
			
		}while(opc>3 || opc<0);//Condiciones de repetición
		
		switch(opc){
		
		case 1:
			
			gotoxy(40,14); printf("LOS DATOS DEL VUELO COMERCIAL SON:");
			
			gotoxy(35,16); cout<<"Punto de salida del avion:"<<g_salida;
			gotoxy(35,17); cout<<"Destino del avion:"<<g_destino;
			gotoxy(35,18); cout<<"Cantidad de pasajeros:"<<g_pasajero;
			gotoxy(35,19); cout<<"Aerolinea:"<<g_aerolinea;
			gotoxy(35,20); //Posición del cursor
			
		break;
			
		case 2:
			
			gotoxy(40,14); printf("LOS DATOS DEL VUELO DE CARGA SON:");
			
			gotoxy(35,16); cout<<"Punto de salida del avion:"<<g_salida;
			gotoxy(35,17); cout<<"Destino del avion:"<<g_destino;
			gotoxy(35,18); cout<<"El nombre de la carga es:"<<g_carga;
			gotoxy(35,19); cout<<"Aerolinea:"<<g_aerolinea;
			gotoxy(35,20); //Posición del cursor
			
		break;
		
		default:
			
			Menu();
		break;		
		}

			
			getch();
			Menu();
	break;
	
	case 3: //Control manual del avión
			
	
	do{
		system("cls"); //Borrar pantalla
		Graficos(); //Llama a todo lo visual
		gotoxy(40,14); printf("DATOS DEL PASAPORTE:");
			
		gotoxy(35,16); cout<<"Nombre:Jose"<<g_salida;
		gotoxy(35,17); cout<<"Estado de origen:Buenos aires"<<g_destino;
		gotoxy(35,18); cout<<"Pais de origen:Venezuela"<<g_carga;
		gotoxy(35,19); cout<<"Edad:20"<<g_aerolinea;
		
		gotoxy(30,21); cout<<"1-[DEJARLO PASAR]";
		gotoxy(55,21); cout<<"2-[NO DEJARLO PASAR]";
		gotoxy(50,22); //Posición del puntero
		
		cin>>opc;
		}while(opc>3 || opc<0);//Condiciones de repetición
	
		if(opc==1){
	
			gotoxy(22,23); cout<<"PERDISTE! EL PASAJERO RESULTO TENER ANTECEDENTES LEGALES";
			Sleep(2000);
			Menu();
		}
		
		else if(opc==2){
			
			gotoxy(29,23); cout<<"GANASTE! LOS DATOS DEL PASAJERO NO COINCIDIAN";
			Sleep(2000);
			Menu();
		}
		
		else{
			
			Menu();
			
		}
		
	break;
	
	case 4:
		exit(0);
	break;
	
	default:
		system("cls"); //Borrar pantalla
		Menu(); //Llama a todo lo visual
	break;	
		
	}
	
	getch();
	Menu();
}

void Progreso(){
	
	//==EFECTO DE CARGA==
	
	gotoxy(22,6); printf("PROGRESO DEL VUELO"); //Texto

	for(int i=40;i<78;i++){
	
	gotoxy(i,5); printf("%c",205);
	gotoxy(i,7); printf("%c",205);
	
	}
	
	//Laterales
	gotoxy(40,6); printf("%c",186);
	gotoxy(77,6); printf("%c",186);
	
	//Esquinas - Superior derecha
	gotoxy(77,5); printf("%c",187);
	
	//Esquinas - Superior izquierda
	gotoxy(40,5); printf("%c",201);

	//Esquinas - Inferio izquierda
	gotoxy(77,7); printf("%c",188);

	//Esquinas - Inferio Derecha
	gotoxy(40,7); printf("%c",200);
}

void Opciones(){
	
	//Title
	gotoxy(40,14); printf("CAJA DE MENSAJES");
	
}

void Graficos(){
	
	//Llamado a la función
	Divisiones_Grafico();
	Radar_Grafico();
	Progreso();
}

void Papeles(){
	
	
	
	
	
	
}
