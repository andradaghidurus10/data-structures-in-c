#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>



struct Student
{
	char* nume; 
	int varsta; 
	float medie;

};

typedef struct Student Student; 

struct Nod
{
	Student stud; 
	struct Nod* next;
};
typedef struct Nod Nod;


void Afisare(Nod* prim)
{
	printf("studentul : %s , varsta: %d , media: %.2f\n", prim->stud.nume, prim->stud.varsta, prim->stud.medie);
	Nod* temp = prim->next;
	while (temp != prim)
	{
		printf("studentul : %s , varsta: %d , media: %.2f\n", temp->stud.nume, temp->stud.varsta, temp->stud.medie);
		temp = temp->next;
	}
}

//inserare : 

Nod* inserare(Nod* prim, Student s, unsigned int poz)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->stud = s;

	if (prim == NULL)
	{
		prim = nou;
		nou->next = prim; 

		return prim;
	}
	else
	{
		if (poz == 1)
		{
			Nod* temp = prim; 

			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			//ma aflu pe ultima pozitie 
			nou->next = prim; 
			prim = nou;
			temp->next = prim;

			return prim;
		}
		Nod* temp = prim;
		unsigned int counter = 1;
		while (temp->next != prim && counter<poz-1)
		{
			temp = temp->next;
			counter++;

		}
		nou->next = temp->next;
		temp->next = nou;

	}
	return prim;
}


//stergere nume 

Nod* stergereNume(Nod* prim, char* nume)
{
	if (prim == NULL)
	{
		return prim;
	}
	else
	{
		while (prim != NULL && strcmp(prim->stud.nume, nume) == 0)
		{
			Nod* temp = prim; 
			Nod* urmator = temp->next;
			while (urmator->next != prim)
			{
				urmator = urmator->next;
			}
			prim = prim->next;
			urmator->next = prim;

			free(temp->stud.nume);
			free(temp);
		}

		if (prim != NULL) // daca mai avem elemente in lista 
		{
			Nod* temp = prim; 
			
			while (temp->next != prim)
			{
				Nod* deSters = temp->next;
			
				if (strcmp(deSters->stud.nume, nume) == 0)
				{
					temp->next = deSters->next;

					free(deSters->stud.nume);
					free(deSters);
				}
				else
				{
					temp = temp->next;
				}
			}
			

		}
	}
	return prim;
}


int main()
{

	Nod* prim = NULL;

	FILE* f;
	f = fopen("Studenti.txt", "r");

	if (f == NULL)
	{
		printf("nu s a putut deschide fisierul"); 
		return 0;
	}

	char buffer[256]; 
	char seps[] = ",\n"; 
	unsigned int poz = 1;
	while (fgets(buffer, sizeof(buffer), f))
	{
		Student s; 
		char* token = strtok(buffer, seps);

		s.nume = (char*)malloc(strlen(token) + 1);
		strcpy(s.nume, token); 

		token = strtok(NULL, seps);
		s.varsta = atoi(token);


		token = strtok(NULL, seps);
		s.medie = atof(token);


		//inserare : 
		prim = inserare(prim, s, poz);
		poz++;

	}
	fclose(f);

	Afisare(prim);

	printf("stergere:\n");
	prim = stergereNume(prim, "Popescu");
	Afisare(prim);
	return 0;










}


