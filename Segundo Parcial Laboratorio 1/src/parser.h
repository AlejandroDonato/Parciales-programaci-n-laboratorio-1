#include <stdio.h>
#include <stdlib.h>

#include "Arcade.h"
#include "Salon.h"
#include "Juego.h"

#ifndef PARSER_H_
#define PARSER_H_

/////////////////SALON/////////////////

int parser_SalonFromText(FILE* pFile ,LinkedList* pArrayListSalon);

int parser_SalonFromBinary(FILE* pFile, LinkedList* pArrayListSalon);

/////////////////ARCADE/////////////////

int parser_ArcadeFromText(FILE* pFile ,LinkedList* pArrayListArcade);

int parser_ArcadeFromBinary(FILE* pFile, LinkedList* pArrayListArcade);

/////////////////JUEGO//////////////////

int parser_GameFromText(FILE* pFile ,LinkedList* pArrayListGame);

int parser_GameFromBinary(FILE* pFile , LinkedList* pArrayListGame);

#endif
