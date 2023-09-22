#include "../POKEMON/pokemon.h"
#include "../POKEDEX/pokedex.h"
#include "../PLAYER/player.h"

#ifndef BATTLE_H
#define BATTLE_H

void launchBattle(Player *player, Pokedex *pokedex);

void enemyTurn(Player *player, Pokemon *enemy, int *pokemonUseInd);

void healPokemon(Player *player);

#endif