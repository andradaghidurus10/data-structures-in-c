//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//#include <stdlib.h>
//
//
//struct Student
//{
//	char* nume;
//	int varsta;
//	float medie;
//
//};
//
//typedef struct Student Student;
//
//struct Nod
//{
//	Student stud;
//	struct Nod* next;
//	struct Nod* prev;
//};
//typedef struct Nod Nod;
//
//struct Lista
//{
//	Nod* prim; 
//	Nod* ultim;
//};
//typedef struct Lista Lista;
//
////traversare inainte 
//
//void TraversareInainte(Lista lista)
//{
//	Nod* temp = lista.prim;
//
//	while (temp != NULL)
//	{
//		printf("studentul : %s , varsta: %d , media: %.2f\n", temp->stud.nume, temp->stud.varsta, temp->stud.medie);
//		temp = temp->next;
//	}
//}
//
//void TraversareInapoi(Lista lista)
//{
//	Nod* temp = lista.ultim;
//	while (temp != NULL)
//	{
//		printf("studentul : %s , varsta: %d , media: %.2f\n", temp->stud.nume, temp->stud.varsta, temp->stud.medie);
//		temp = temp->prev;
//	}
//}
//
//
////inserare poz
//Lista Inserare(Lista lista, Student s, unsigned int poz)
//{
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->stud = s;
//
//	if (lista.prim == NULL)
//	{
//		lista.prim = nou;
//		lista.ultim = nou;
//		nou->next = NULL;
//		nou->prev = NULL;
//
//		return lista;
//	}
//	else
//	{
//		if (poz == 1)
//		{
//			nou->next = lista.prim;
//			nou->prev = NULL;
//			lista.prim->prev = nou;
//			lista.prim = nou;
//
//			return lista;
//
//		}
//		Nod* temp = lista.prim;
//		unsigned int contor = 1;
//		while (temp->next != NULL && contor<poz-1)
//		{
//			temp = temp->next;
//			contor++;
//		}
//		if (temp->next != NULL)
//		{
//			nou->next = temp->next;
//			nou->prev = temp;
//			temp->next->prev = nou;
//			temp->next = nou;
//
//			return lista;
//		}
//		else
//		{
//			nou->next = NULL;
//			nou->prev = lista.ultim;
//			lista.ultim->next = nou;
//			lista.ultim = nou;
//
//			return lista;
//		}
//
//	}
//
//	return lista;
//}
//
////stergere dupa nume: 
//
//Lista Stergere(Lista lista, char* nume)
//{
//	if (lista.prim == NULL)
//	{
//		return lista;
//	}
//	else
//	{
//		while (lista.prim != NULL && strcmp(lista.prim->stud.nume, nume) == 0)
//		{
//			Nod* temp = lista.prim; 
//
//			if (temp == lista.prim && temp == lista.ultim)
//			{
//				lista.prim = NULL;
//				lista.ultim = NULL;
//				
//				free(temp->stud.nume);
//				free(temp);
//
//				return lista;
//			}
//			else
//			{
//				lista.prim = lista.prim->next;
//				lista.prim->prev = NULL;
//
//				free(temp->stud.nume);
//				free(temp);
//			}
//		}
//		if (lista.prim != NULL)
//		{
//			Nod* temp = lista.prim; 
//			while (temp->next != NULL)
//			{
//				Nod* urmator = temp->next;
//				if (strcmp(temp->stud.nume, nume) == 0)
//				{
//					//trebuie sa sterg temp 
//
//					temp->next->prev = temp->prev; 
//					temp->prev->next = temp->next; 
//
//					free(temp->stud.nume);
//					free(temp);
//				}
//				temp = urmator;
//			}
//			if (strcmp(temp->stud.nume, nume) == 0)
//			{
//				//trebuie sa sterg ultimul nod
//				lista.ultim = temp->prev; 
//				lista.ultim->next = NULL;
//
//				free(temp->stud.nume);
//				free(temp);
//			}
//
//		}
//	}
//	return lista;
//}
////stergere dupa pozitie: 
//
//
//Lista StergPoz(Lista lista, unsigned int poz)
//{
//	if (lista.prim == NULL)
//	{
//		return lista;
//	}
//	else
//	{
//		if (poz == 1)
//		{
//			Nod* temp = lista.prim;
//			if (temp == lista.prim && temp == lista.ultim)
//			{
//				lista.prim = NULL;
//				lista.ultim = NULL;
//
//				free(temp->stud.nume);
//				free(temp);
//
//				return lista;
//			}
//			else
//			{
//				lista.prim = lista.prim->next;
//				lista.prim->prev = NULL;
//
//				free(temp->stud.nume);
//				free(temp);
//				return lista;
//			}
//		}
//		Nod* temp = lista.prim;
//		unsigned int contor = 1;
//		while (temp->next != NULL && contor<poz-1)
//		{
//			temp = temp->next;
//			contor++;
//		}
//		if (temp->next != NULL)
//		{
//			//temp-> se afla pe pozitia contor
//			Nod* deSters = temp->next;
//			if (deSters->next != NULL)
//			{
//				temp->next = deSters->next;
//				deSters->next->prev = temp;
//
//			}
//			else
//			{
//				lista.ultim = temp;
//				lista.ultim->next = NULL;
//			}
//
//			free(deSters->stud.nume);
//			free(deSters);
//			return lista;
//		}
//	}
//	return lista;
//}
//int main()
//{
//
//	Lista lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//
//	FILE* f;
//	f = fopen("Studenti.txt", "r");
//
//	if (f == NULL)
//	{
//		printf("nu s a putut deschide fisierul");
//		return 0;
//	}
//
//	char buffer[256];
//	char seps[] = ",\n";
//	unsigned int poz = 1;
//	while (fgets(buffer, sizeof(buffer), f))
//	{
//		Student s;
//		char* token = strtok(buffer, seps);
//
//		s.nume = (char*)malloc(strlen(token) + 1);
//		strcpy(s.nume, token);
//
//		token = strtok(NULL, seps);
//		s.varsta = atoi(token);
//
//
//		token = strtok(NULL, seps);
//		s.medie = atof(token);
//
//
//		//inserare : 
//		lista = Inserare(lista, s, poz);
//		poz++;
//
//	}
//	fclose(f);
//
//	TraversareInainte(lista);
//
//	printf("\nstergere poz:\n");
//	lista = StergPoz(lista, 12);
//	TraversareInainte(lista);
//
//
//	return 0;
//}
//









