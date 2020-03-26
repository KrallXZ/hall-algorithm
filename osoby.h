#define LICZBA_MEZCZYZN 11
#define LICZBA_KOBIET 9
#define LICZBA_OSOB 20

enum osoby
{
  andrzej,
  bartosz,
  cyprian,
  daniel,
  edward,
  franciszek,
  grzegorz,
  henryk,
  ignacy,
  juliusz,
  maciej,
  anna,
  barbara,
  celina,
  danuta,
  ewa,
  faustyna,
  hanna,
  iwona,
  julia
};

const char *imiona[LICZBA_OSOB] = {
    "Andrzej", "Bartosz", "Cyprian", "Daniel", "Edward", "Franciszek", "Grzegorz", "Henryk", "Ignacy", "Juliusz", "Maciej",
    "Anna", "Barbara", "Celina", "Danuta", "Ewa", "Faustyna", "Hanna", "Iwona", "Julia"};

int preferencje[LICZBA_MEZCZYZN][LICZBA_KOBIET] = {
    {anna},
    {celina, hanna, anna, danuta, ewa, faustyna, barbara, iwona},
    {hanna, ewa, anna, danuta, barbara},
    {danuta},
    {danuta, barbara, celina, faustyna, ewa, anna, iwona, hanna},
    {barbara, anna, danuta, hanna, faustyna},
    {ewa, anna, danuta, hanna, faustyna},
    {anna, ewa, hanna, iwona, celina, barbara, danuta},
    {julia},
    {anna, faustyna, ewa, iwona, hanna},
    {anna}};