//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//#include <stdlib.h>
//#define dim_hash_table 20
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
////functia hash : aleg ca si cheie identificarea studentilor dupa nume 
//
//unsigned int functieHash(unsigned int dim_ht, char* cheie)
//{
//	unsigned int suma = 0;
//
//	for (int i = 0; i < strlen(cheie); i++)
//	{
//		suma += cheie[i];
//
//	}
//
//	return suma % dim_ht;
//}
//
////inserare in lista simpla : 
//Nod* inserare(Nod* prim, Student s)
//{
//	//inserare la inceput 
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->stud = s;
//
//
//	nou->next = prim; 
//	prim = nou;
//
//	return prim;
//
//}
//
////inserare in tabela hash 
//
//void InserareHash(Nod** HT, unsigned int dim_ht, Student s)
//{
//	unsigned int poz = 0;
//	poz = functieHash( dim_ht, s.nume);
//
//	HT[poz] = inserare(HT[poz], s);
//}
//
//
////cautare dupa cheie 
//
////returneaza studentul: 
//Student* cautareCheie(Nod** HT, unsigned int dim_ht, char* cheie)
//{
//	unsigned int poz = 0;
//	poz = functieHash(dim_ht, cheie);
//
//	//HT[poz] <=> prim
//	Nod* temp = HT[poz]; // inceputul de lista 
//
//	while (temp != NULL)
//	{
//		if (strcmp(temp->stud.nume, cheie) == 0)
//		{
//			return &temp->stud;
//		}
//		temp = temp->next;
//	}
//	
//	return NULL;
//}
//
//
////stergere dupa cheie : 
//
//void Stergere(Nod** HT,unsigned int dim_ht, char* cheie)
//{
//	unsigned int poz = 0;
//	//caut pe ce pozitie se afla cheia mea 
//
//	poz = functieHash(dim_ht, cheie);
//
//	if (HT[poz] != NULL)
//	{
//		if (strcmp(HT[poz]->stud.nume, cheie) == 0)
//		{
//			Nod* temp = HT[poz];
//			HT[poz] = HT[poz]->next; 
//
//			free(temp->stud.nume);
//			free(temp);
//			return;
//
//			
//		}
//		Nod* temp = HT[poz];
//		while (temp->next != NULL)
//		{
//			Nod* deSters = temp->next;
//			if (strcmp(deSters->stud.nume, cheie) == 0)
//			{
//				temp->next = deSters->next;
//
//				free(deSters->stud.nume);
//				free(deSters);
//
//				return;
//			}
//			else
//			{
//				temp = temp->next;
//			}
//		}
//	}
//	
//}
//
////dezalocare hashtable 
//
//void Dezalocare(Nod** HT, unsigned int dim_ht)
//{
//	for (int i = 0; i < dim_ht; i++)
//	{
//		Nod* temp = HT[i];
//		while (temp != NULL)
//		{
//			Nod* aux = temp;
//			temp = temp->next;
//			free(aux->stud.nume);
//			free(aux);
//		}
//	}
//	free(HT);
//}
//
//float medie(Nod** HT, unsigned int dim_ht)
//{
//	float suma = 0;
//	int nr = 0;
//	for (int i = 0; i < dim_ht; i++)
//	{
//		Nod* temp = HT[i];
//		while (temp != NULL)
//		{
//			suma += temp->stud.medie;
//			nr++;
//			temp = temp->next;
//		}
//	}
//	return suma / nr;
//}
//
////creare vector studenti cu dim < medie 
//
//
//Student* VectorStud(Nod** HT, unsigned int dim_ht, float medie, unsigned char* nr)
//{
//	*nr = 0;
//	for (int i = 0; i < dim_ht; i++)
//	{
//		Nod* temp = HT[i];
//		while (temp != NULL)
//		{
//			if (temp->stud.medie<medie)
//			{
//				(*nr)++;
//			}
//			temp = temp->next;
//		}
//	}
//	if (*nr > 0)
//	{
//		Student* vector = (Student*)malloc((*nr) * sizeof(Student));
//		unsigned int poz = 0;
//		for (int i = 0; i < dim_ht; i++)
//		{
//			Nod* temp = HT[i];
//			while(temp != NULL)
//			{
//				if (temp->stud.medie < medie)
//				{
//					vector[poz].nume = (char*)malloc(strlen(temp->stud.nume)+1);
//					strcpy(vector[poz].nume, temp->stud.nume);
//
//					vector[poz].varsta = temp->stud.varsta;
//					vector[poz].medie = temp ->stud.medie;
//					poz++;
//				}
//				temp = temp->next;
//			}
//		}
//		return vector;
//
//
//	}
//	return NULL;
//}
//
//int nrNoduri(Nod** HT, unsigned int dim_ht)
//{
//	unsigned int nr = 0;
//	for (int i = 0; i < dim_ht; i++)
//	{
//		Nod* temp = HT[i];
//		while (temp != NULL)
//		{
//			temp = temp->next;
//			nr++;
//		}
//	}
//
//	return nr;
//}
//
//Student* tabelaHashInVector(Nod** HT, unsigned int dim_ht,unsigned char* nr)
//{
//	*nr = 0;
//
//	for (int i = 0; i < dim_ht; i++)
//	{
//		Nod* temp = HT[i];
//		while (temp != NULL)
//		{
//			temp = temp->next;
//			(*nr)++;
//		}
//		
//
//	}
//	if (*nr > 0)
//	{
//		Student* vector = (Student*)malloc((*nr) * sizeof(Student));
//		unsigned int poz = 0;
//		for (int i = 0; i < dim_ht; i++)
//		{
//			Nod* temp = HT[i];
//			while (temp != NULL)
//			{
//				vector[poz].nume = (char*)malloc(strlen(temp->stud.nume) + 1);
//				strcpy(vector[poz].nume, temp->stud.nume);
//
//				vector[poz].varsta = temp->stud.varsta;
//				vector[poz].medie = temp->stud.medie;
//				poz++;
//					
//				
//				temp = temp->next;
//			}
//		}
//		return vector;
//	}
//	return NULL;
//}
//
////cate elemente sunt pe fiecare pozitie : 
//void elementePeFiecarePoz(Nod** HT, unsigned int dim_ht)
//{
//	int nr = 0;
//	for (int i = 0; i < dim_ht; i++)
//	{
//		Nod* temp = HT[i];
//		while (temp != NULL)
//		{
//			nr++;
//			temp = temp->next;
//		}
//		printf("pe pozitia %d sunt %d elemente\n", i, nr);
//	}
//	
//}
//
////care este pozitia cea mai populata 
//
//void PozPopulata(Nod** HT, unsigned int dim_ht)
//{
//	int max = 0;
//	
//	int poz = -1;
//
//	for (int i = 0; i < dim_ht; i++)
//	{
//		int nr = 0;
//		Nod* temp = HT[i];
//		while (temp != NULL)
//		{
//			temp = temp->next;
//			nr++;
//		}
//
//		if (nr > max)
//		{
//			max = nr;
//			poz = i;
//			
//		}
//	}
//	printf("pozitia cea mai populata este: %d cu nr de elemente: %d", poz, max);
//}
//
//int main()
//{
//
//	Nod** hashTable;
//	FILE* f;
//
//	hashTable = (Nod**)malloc(dim_hash_table*sizeof(Nod*));
//	//initial tabela este goala 
//	for (int i = 0; i < dim_hash_table; i++)
//	{
//		hashTable[i] = NULL;
//	}
//
//	
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
//	
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
//	
//		InserareHash(hashTable, dim_hash_table, s);
//	
//
//	}
//	fclose(f);
//
//
//	//afisare:
//	printf("tabela hash:\n");
//	
//		for (int i = 0; i < dim_hash_table; i++)
//		{
//			printf("lista de pe pozitia %d este :\n", i);
//			Nod* temp = hashTable[i];
//			while(temp != NULL)
//			{
//				printf("studentul : %s , varsta: %d , media: %.2f\n", temp->stud.nume, temp->stud.varsta, temp->stud.medie);
//				temp = temp->next;
//			}
//
//		}
//
//		printf("\nCautare dupa cheie:\n");
//		Student* stud=cautareCheie(hashTable, dim_hash_table, "Enache");
//		if (stud != NULL)
//		{
//			printf("studentul %s a fost gasit\n",stud->nume);
//
//			
//			
//		}
//		else
//		{
//			printf("nu am gasit studentul");
//		}
//
//		printf("\nDupa stergere:\n");
//		Stergere(hashTable, dim_hash_table, "Popescu");
//		for (int i = 0; i < dim_hash_table; i++)
//		{
//			Nod* temp = hashTable[i];
//			while (temp != NULL)
//			{
//				printf("studentul : %s , varsta: %d , media: %.2f\n", temp->stud.nume, temp->stud.varsta, temp->stud.medie);
//				temp = temp->next;
//			}
//
//		}
//
//
//		printf("\nmedia: %.2f", medie(hashTable, dim_hash_table));
//		printf("\nNr noduri: %d", nrNoduri(hashTable, dim_hash_table));
//
//
//		//vector:
//		//float Medie = medie(hashTable, dim_hash_table);
//		//printf("\nVector:\n");
//		//unsigned char nr = 0;
//		//Student* vector = VectorStud(hashTable, dim_hash_table, Medie,&nr);
//
//		//if (vector != NULL)
//		//{
//		//	for (int i = 0; i < nr; i++)
//		//	{
//		//		printf("studentul: %s cu media %.2f\n", vector[i].nume, vector[i].medie);
//		//	}
//		//}
//
//		char nr = 0;
//		Student* vector = tabelaHashInVector(hashTable, dim_hash_table, &nr);
//		if (vector != NULL)
//		{
//			for (int i = 0; i < nr; i++)
//			{
//				printf("studentul: %s cuvarsta : %d si media %.2f\n", vector[i].nume,vector[i].varsta, vector[i].medie);
//			}
//		}
//		for (int i = 0; i < nr; i++)
//		{
//			free(vector[i].nume);
//		}
//		free(vector);
//
//		elementePeFiecarePoz(hashTable, dim_hash_table);
//		PozPopulata(hashTable, dim_hash_table);
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