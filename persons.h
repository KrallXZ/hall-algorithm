#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

typedef enum
{
  lady,
  gentleman
} Gender;

typedef struct
{
  unsigned int id;
  char *name;
  unsigned int *preferences;
  unsigned int preferencesCount;
} Person;

typedef struct
{
  Person *array[MAX];
  unsigned int count;
} Persons;

void setPreferences(Person *person, Persons *other)
{
  if (other->count > 0)
  {
    unsigned int i = 0;
    int id;
    printf("Podaj preferencje dla %s.\n", person->name);
    printf("Każdą zatwierdź ENTERem. Gdy będziesz chciał przestać wprowadź -1.\n");
    printf("Możliwe opcje: \n");
    for (int i = 0; i < other->count; i++)
    {
      printf("\t[%d] %s\n", i, other->array[i]->name);
    }

    do
    {
      printf("\tMiejsce %d: ", i + 1);
      scanf("%d", &id);
      if ((id >= 0) && (id <= other->count))
      {
        person->preferences[i] = id;
        person->preferencesCount += 1;
        i += 1;
      }
    } while (id != -1 && i != other->count);
  }
}

void createPerson(Persons *persons, char name[], Persons *other)
{
  if (persons->count == MAX)
  {
    printf("Nie można dodać więcej osób! 😪\n");
    return;
  }
  Person *newPerson = malloc(sizeof(Person));
  newPerson->id = persons->count;
  newPerson->name = name;
  newPerson->preferences = malloc(MAX * sizeof(unsigned int));
  newPerson->preferencesCount = 0;
  persons->array[persons->count] = newPerson;
  persons->count += 1;

  setPreferences(newPerson, other);
}

void printPersons(Persons *persons, Persons *other)
{
  for (int i = 0; i < persons->count; i++)
  {
    printf("\t%d. %s (ID: %d), preferencje:\n", i + 1, persons->array[i]->name, persons->array[i]->id);
    for (int j = 0; j < persons->array[i]->preferencesCount; j++)
    {
      printf("\t\t%d. %s\n", j + 1, other->array[persons->array[i]->preferences[j]]->name);
    }
    printf("\n");
  }

  unsigned int choice = showPersonsMenu();

  switch (choice)
  {
  case 1:
    printf("Podaj imię nowej osoby: ");
    char *name = malloc(sizeof(char) * 16);
    scanf("%s", name);
    createPerson(persons, name, other);
    break;
  case 2:
    printf("Możesz edytować następujące osoby:\n");
    for (int i = 0; i < persons->count; i++)
    {
      printf("[%d] %s\n", i, persons->array[i]->name);
    }
    printf("Podaj ID osoby do edycji: ");
    unsigned int id;
    scanf("%d", &id);

    if (id >= 0 && id < persons->count)
    {
      setPreferences(persons->array[id], other);
    }
    break;
  case 0:
    return;
  }
}

Persons *createPersons()
{
  Persons *newPersons = malloc(sizeof(Persons));
  newPersons->count = 0;
  return newPersons;
}