#include <iostream>
#include <stdlib.h>
#define Max 100 // inicializan con 100 posiciones pero esto cambia cada que inicializa el programa
using namespace std;

void menu();

//Matriz de adyacencia 
int MatrizAdyacente[Max][Max];
class nodoa {
	public:
		int ady;
		int peso; //nombramos variables enteras
		nodoa *siguiente; //creamos un puntero de tipo nodoa
		nodoa(int v,int p, nodoa *sig = NULL)
		{
			ady = v;
			peso = p; //constructores para nuestro grafo
			siguiente = sig;
		}				
};
struct nodo {
	public:
		 int vertice;
		 nodoa *puntero;
		 nodo *siguiente;
		 nodo(int v, nodo *sig = NULL, nodoa *punt=NULL)
		{
			vertice = v;
			siguiente = sig;   // creamor primer nodo constructor
			puntero = punt;
		}
		
		class lista;		 
};
typedef nodo *pnodo; //creamos un nuevo puntero

class lista {
	public:
		
		pnodo primero;
		
		lista() { primero = NULL; }//crear una lista vacio
		
		//nuestras funciones principales 
		void Insertarv(int v); //funcion para insertar datos 
		bool ListavVacia(); //Verificar si nuestra lista esta vacia
		 pnodo Buscarv(int v); //funcion para buscar
		bool listavexiste(int i,int f);
		void creararco(int i,int f,int peso);
		void CrearMatriz();
		void mostrarmatriz();
		int CantidadVertices();
		int ExisteArco(int i,int f);
		bool BuscarAdy(pnodo aux,int ad); //retorna dos valores 
};
 
void lista::creararco (int i,int f,int peso){
	pnodo pos;
	pos=primero;
	if(listavexiste(i,f)){
	while(pos!=NULL){
		if (i == pos->vertice){
			
			if(pos->puntero==NULL){
				pos->puntero=new nodoa(f,peso);
			}
			else{
				nodoa *temp=pos->puntero;
				    while(temp->siguiente!=NULL){
				    	temp=temp->siguiente;
				    	}
				    	temp->siguiente=new nodoa(f,peso);
				    	temp=NULL;
				    	delete temp;
				    	}
				    	}
			pos=pos->siguiente;
			}	    	
	}
}

bool lista::listavexiste(int i,int f){
	if (Buscarv(i)!=NULL&&Buscarv(f)!=NULL){
		return true;
		}
		else{
		return false;
		}
}

void lista::Insertarv(int v){
	pnodo anterior;
	if(ListavVacia())
	{
		primero = new nodo(v,primero);
	}else{ if (v<=primero->vertice){
		primero =new nodo (v,primero);
		}else{
			anterior = primero;
			while((anterior->siguiente)&&(anterior->siguiente->vertice<=v)){
				anterior = anterior->siguiente; }
				
				anterior->siguiente = new nodo(v, anterior->siguiente);
			}
// para insertar los datos a nuestro grafo
}
}

bool lista::ListavVacia(){ //funcion booleana 
	return primero == NULL; //verificamos si nuestro grafo esta vacio 
}

int lista::CantidadVertices(){
	pnodo nodo=primero;
	int i=0;
	while(nodo!=NULL){
		i++;
		nodo=nodo->siguiente;
	}
	return i; //retornamos i
}

int lista::ExisteArco(int i, int f){
	pnodo nodo;
	int a=1;
	nodo=Buscarv(i);
	if (nodo){
		if (BuscarAdy(nodo,f)){
		return a;
		}else{
		return a=0;
		}
	}
}
bool lista::BuscarAdy(pnodo aux,int ad){
     nodoa *temp=aux->puntero;
	 bool a;
	 while(temp){
	    if(ad==temp->ady){
		   return a=true;}
		temp=temp->siguiente;
		}
		return a=false;
}

pnodo lista::Buscarv(int valor){
    int z;
	pnodo indice,n=NULL;
	indice=primero;
	while(indice!=NULL){
	if (valor ==indice->vertice ){
	          return indice;
	          }
		indice=indice->siguiente;
	}
	cout<<"\n\n\tEL VALOR BUSCADO NO ESTA EN EL GRAFO";
return n;
}


void lista::CrearMatriz(){
     pnodo nodo=primero,nodotemp;
	 int i,j,inicio, fin;
	 int cant=CantidadVertices();
	 for (i=0;i<cant;i++){
	     nodotemp=primero;
		for(j=0;j<cant;j++){
		
		 MatrizAdyacente[i][j]=ExisteArco(nodo->vertice,nodotemp->vertice);
		 nodotemp=nodotemp->siguiente;
		}
		nodo=nodo->siguiente;
	}
	delete nodo;
	delete nodotemp;
}

void lista::mostrarmatriz(){
	int i,j,cant;
	pnodo nodo=primero;
	cant=CantidadVertices();
	cout<<" ";
	
	for(i=0;i<cant;i++){
	cout<<"\t"<<nodo->vertice<<" ";
	nodo=nodo->siguiente;
	}
	nodo=primero;
	cout<<"\n\n";
	
	for( i=0;i<cant;i++){
		
		cout<<nodo->vertice;
		for(j=0;j<cant;j++){
			cout<<"\t"<<MatrizAdyacente[i][j]<<" ";
			}
			nodo=nodo->siguiente;
			cout<<"\n";
		}
	}
	
int main(){
system ("color 0B");
menu();
return 0;
}

void menu(){
	system ("cls");
	int op1=0,valor=0;
	lista l;
	    l.Insertarv(1);
	    l.Insertarv(2);
	    l.Insertarv(3); // creamos y asignamos valores a nuestros vertices 
	    l.Insertarv(4);
	    l.Insertarv(5);
	    l.creararco(1,2,1);
	    l.creararco(2,1,1);
	    l.creararco(1,4,2);
	    l.creararco(4,1,2);
	    l.creararco(4,3,3);
		l.creararco(3,4,3);	    
	    
	    cout<<"\n";
	cout<<"\n\n\tPROGRAMA GRAFO";
	cout<<"\n";
	cout<<"\n\n\t1. MOSTRAR MATRIZ ADYACENTE";
	cout<<"\n\n\t2. BUSCAR";
	cout<<"\n\n\t3. SALIR";
	cout<<"\n";
	cout<<"\n";
	cout<<"\nINGRESE LA OPCION";
	cin>>op1;
switch(op1){
case 1:
     system("cls");
     cout<<"\n";
    cout<<"\n\nMATRIZ GRAFO"<<"\n\n";
    l.CrearMatriz();
    l.mostrarmatriz();
    cout<<"\n";
    cout<<"\n";
    system("pause");
    menu();
break;
case 2:
	system("cls");
	cout<<"\n\nINGRESE EL NUMERO A BUSCAR: ";
	cin>>valor;
	l.Buscarv(valor);
	cout<<"\n";
    cout<<"\n";
    system("pause");
    menu();
break;
case 3:
	system("cls");
	cout<<"\n";
	cout<<"FIN DEL PRGRAMA";
break;
}
}



	
	
	

    
	    
	
		
			
		 	  		
		
				
			
			 
		
 

