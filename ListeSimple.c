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
//};
//typedef struct Nod Nod;
//
//
//void afisare(Nod* prim)
//{
//	Nod* temp = prim; 
//	while (temp != NULL)
//	{
//		printf("studentul : %s , varsta: %d , media: %.2f\n", temp->stud.nume, temp->stud.varsta, temp->stud.medie);
//		temp = temp->next;
//	}
//}
//
//// inserare dupa pozitie:
////Nod* inserare(Nod* prim, Student s, unsigned int poz)
////{
////	Nod* nou = (Nod*)malloc(sizeof(Nod));
////	nou->stud = s; 
////
////	if (prim == NULL)
////	{
////		prim = nou;
////		nou->next = NULL;
////		return prim; 
////	}
////	else
////	{
////		if (poz == 1)
////		{
////			nou->next = prim; 
////			prim = nou;
////			return prim; 
////		}
////		Nod* temp = prim; 
////		unsigned int contor = 1;
////
////		while (temp->next != NULL && contor < poz - 1)
////		{
////			temp = temp->next; 
////			contor++;
////		}
////		//inserare la final si mijloc 
////		nou->next = temp->next;
////		temp->next = nou;
////		return prim;
////	}
////	return prim;
////}
//
////stergere dupa nume: 
////strgem recursiv toti studentii
//
//Nod* stergereNume(Nod* prim, char* nume)
//{
//	if (prim == NULL)
//	{
//		return prim;
//	}
//	else
//	{
//		while (prim != NULL && strcmp(prim->stud.nume, nume) == 0)
//		{
//			Nod* temp = prim; 
//
//			prim = prim->next; 
//
//			free(temp->stud.nume);
//			free(temp);
//		}
//
//		if (prim != NULL) // daca mai avem elemente in lista 
//		{
//			Nod* temp = prim; 
//			
//			while (temp->next != NULL)
//			{
//				Nod* deSters = temp->next;
//				Nod* urmator = temp->next;
//				if (strcmp(deSters->stud.nume, nume) == 0)
//				{
//					temp->next = deSters->next;
//
//					free(deSters->stud.nume);
//					free(deSters);
//				}
//				else
//				{
//					temp = urmator;
//				}
//			}
//			
//
//		}
//	}
//	return prim;
//}
//
//
//
//
//// nr noduri: 
//
//
//int nrNoduri(Nod* prim)
//{
//	Nod* temp = prim;
//	unsigned int nr = 0;
//	while (temp != NULL)
//	{
//		temp = temp->next;
//		nr++;
//	}
//	return nr;
//}
//
//
//
//
//
//float medie(Nod* prim)
//{
//	Nod* temp = prim; 
//	float suma = 0;
//	unsigned int nr = 0;
//	while (temp != NULL)
//	{
//		suma += temp->stud.medie;
//		nr++;
//		temp = temp->next;
//		
//	}
//	return suma/nr;
//}
//
////vector cu studenti sub medie : 
//Student* vectorStudenti(Nod* prim, float medie, unsigned char* nr)
//{
//	*nr = 0;
//	Nod* temp = prim; 
//	while (temp != NULL)
//	{
//		if (temp->stud.medie < medie)
//		{
//			(*nr)++;
//		}
//		temp = temp->next;
//	} // dimensiunea totala pe care o va avea vectorul 
//
//	if (*nr > 0)
//	{
//		Student* vector = (Student*)malloc((*nr) * sizeof(Student));
//		Nod* temp = prim;
//		unsigned int poz = 0;
//		
//		while (temp != NULL)
//		{
//			if (temp->stud.medie < medie)
//			{
//				vector[poz].nume = (char*)malloc(strlen(temp->stud.nume) + 1);
//				strcpy(vector[poz].nume, temp ->stud.nume);
//
//				vector[poz].varsta = temp ->stud.varsta;
//				vector[poz].medie = temp->stud.medie;
//
//				poz++;
//			}
//			temp = temp->next;
//		}
//		return vector;
//	}
//
//	return NULL;
//
//}
////stergere dupa pozitie
//Nod* stergerePoz(Nod* prim, unsigned int poz)
//{
//	if (prim == NULL)
//	{
//		return prim;
//	}
//	else
//	{
//		if (poz == 1)
//		{
//			Nod* temp = prim;
//			prim = prim->next;
//
//			free(temp->stud.nume);
//			free(temp);
//			return prim;
//		}
//
//		Nod* temp = prim; 
//		unsigned int contor = 1;
//		
//		while (temp->next != NULL && contor < poz - 1)
//		{
//			temp = temp->next; 
//			
//			contor++;
//		}
//		// cand ies din while , cel putin o conditie e falsa 
//		if (temp->next != NULL) // daca suntem la mijloc 
//		{
//			Nod* deSters = temp->next;
//			temp->next = deSters->next;
//
//			free(deSters->stud.nume);
//			free(deSters);
//
//			return prim;
//		}
//	}
//	return prim;
//}









//
//int main()
//{
//
//	Nod* prim = NULL;
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
//		prim = inserare(prim, s, poz);
//		poz++;
//
//	}
//	fclose(f);
//
//	afisare(prim);
//
//	//printf("\n lista dupa stergere : \n");
//	//prim = stergere(prim, "Popescu");
//	//afisare(prim);
//
//	//printf("\nNr Noduri:%d", nrNoduri(prim));
//
//	//printf("\nMedia totala :%.2f", medie(prim));
//	//printf("\n");
//
//	////vector studenti;
//	//unsigned int nr = 0;
//	//float Medie = medie(prim);
//	//
//	//printf("vector:\n");
//	//Student* vector =vectorStudenti(prim,Medie,&nr) ; 
//	//
//	//if (vector != NULL)
//	//{
//	//	for (int i = 0; i < nr; i++)
//	//	{
//	//		printf("studentul : %s , varsta: %d , media: %.2f\n", vector[i].nume, vector[i].varsta,vector[i].medie);
//	//	}
//	//}
//
//
//
//	//for (int i = 0; i < nr; i++)
//	//{
//	//	free(vector[i].nume);
//	//}
//	//free(vector);
//	
//	//printf("\nStergere dupa poz:\n");
//	//prim = stergerePoz(prim, 12);
//	//afisare(prim);
//
//
//	printf("\nStergere dupa nume:\n");
//	prim = stergereNume(prim, "Enache");
//	afisare(prim);
//
//
//
//	return 0;
//
//
//
//
//
//
//
//
//
//
//}