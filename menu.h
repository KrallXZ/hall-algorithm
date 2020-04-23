#include <stdio.h>
#include <stdlib.h>

unsigned int showMenu(char *options[], unsigned int optionsCount)
{
  printf("\nWybierz jedną z opcji i zatwierdź ją enterem:\n");
  for (int i = 1; i <= optionsCount; i++)
  {
    printf("\t%d. %s\n", i != optionsCount ? i : 0, options[i - 1]);
  }

  int choice;
  do
  {
    printf("Wybór: ");
    scanf("%d", &choice);
  } while (!(choice >= 0) || !(choice <= optionsCount));

#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

  return choice;
}

unsigned int showMainMenu()
{
  char *options[] = {"Wyświetl listę kobiet 👩", "Wyświetl listę mężczyzn 👨", "Stwórz pary 🥰", "Zakończenie programu ❌"};
  const int optionsCount = sizeof(options) / sizeof(char *);

  return showMenu(options, optionsCount);
}

unsigned int showPrintMenu()
{
  char *options[] = {"Wyświetl pary kobiet 👩", "Wyświetl pary mężczyzn 👨", "Powrót do głównego menu ↩"};
  const int optionsCount = sizeof(options) / sizeof(char *);

  return showMenu(options, optionsCount);
}

unsigned int showPersonsMenu()
{
  char *options[] = {"Dodaj kolejną osobę ➕", "Edytuj osobę 🖊", "Powrót do poprzedniego menu ↩"};
  const int optionsCount = sizeof(options) / sizeof(char *);

  return showMenu(options, optionsCount);
}

unsigned int showBackMenu()
{
  char *options[] = {"Powrót do głównego menu ↩"};
  const int optionsCount = sizeof(options) / sizeof(char *);

  return showMenu(options, optionsCount);
}