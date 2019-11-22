#include <iostream>
using namespace std;

class nodo{
private:
	int m_pdato;
	nodo * m_psig;
public:
	nodo(int dato){
		m_pdato = dato;
		m_psig = NULL;
	}
friend class lista_simple;
};

class lista_simple{
private:
	nodo * m_phead;
	nodo * m_plast;
public:
	lista_simple(){
		m_phead = NULL;
		m_plast = NULL;
	}
	void agregar_nodo(int dato);
	void imprimir_lista();
	bool buscar_dato(int dato);
	bool eliminar_dato(int dato);
	void agregar_dato_inicio(int dato);
};

void lista_simple::agregar_dato_inicio(int dato){
	nodo * nuevo_nodo = new nodo(dato);
	nuevo_nodo->m_psig = m_phead;
	m_phead = nuevo_nodo;
}

bool lista_simple::eliminar_dato(int dato){
	if(dato == m_phead->m_pdato){
		m_phead = m_phead->m_psig;
		cout<< dato <<" dato eliminado "<<endl;
		return 1;
	}
	nodo * temporal = m_phead;
	while(temporal->m_psig != NULL){
		if(dato == temporal->m_psig->m_pdato){
			temporal->m_psig = temporal->m_psig->m_psig; 
			cout<< dato <<" dato eliminado "<<endl;
			return 1;
		}
		temporal = temporal->m_psig;
	}
	cout<< dato <<" dato no eliminado "<<endl;
	return 0;
}

bool lista_simple::buscar_dato(int dato){
	nodo * temporal = m_phead;
	while(temporal != NULL){
		if(dato == temporal->m_pdato){
			cout<< dato <<" dato encontrado "<<endl;
			return 1;
		}
		temporal = temporal->m_psig;
	}
	cout<< dato <<" dato no encontrado "<<endl;
	return 0;
}

void lista_simple::imprimir_lista(){
	nodo * temporal = m_phead;
	while(temporal != NULL){
		cout<<temporal->m_pdato<<" , ";
		temporal = temporal->m_psig;
	}
	cout<<endl;
	return;
}

void lista_simple::agregar_nodo(int dato){
	nodo * nuevo_nodo = new nodo(dato);
	if( m_phead == NULL ){
		m_phead = nuevo_nodo;
		m_plast = nuevo_nodo;
		return;
	}
	else{
		m_plast->m_psig = nuevo_nodo;
		m_plast = nuevo_nodo;
		return;
	}
}

int main(){
	lista_simple lista;
	lista.agregar_nodo(4);
	lista.agregar_nodo(5);
	lista.agregar_nodo(6);
	lista.agregar_nodo(7);
	lista.imprimir_lista();
	lista.buscar_dato(4);
	lista.buscar_dato(5);
	lista.buscar_dato(6);
	lista.buscar_dato(7);
	lista.buscar_dato(2);
	lista.buscar_dato(9);
	lista.eliminar_dato(6);
	lista.eliminar_dato(2);
	lista.eliminar_dato(4);
	lista.imprimir_lista();
	lista.agregar_dato_inicio(8);
	lista.agregar_dato_inicio(12);
	lista.imprimir_lista();
	return 0;
}
