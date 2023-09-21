#include "battle.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Tableau des types de Pokémon
const char *types[] = {
        "Normal", "Feu", "Eau", "Plante", "Electrique", "Glace", "Combat",
        "Poison", "Sol", "Vol", "Psy", "Insecte", "Roche", "Spectre", "Acier",
        "Dragon", "Ténèbres", "Fée"
};

int getTypeIndex(const char *type) {
    for (int i = 0; i < 18; i++) {
        if (strcmp(type, types[i]) == 0) {
            return i;
        }
    }
    return -1;
}

double getMultiplier(Pokemon *attacker, Pokemon *defender){
    double type_bonus[][18] = {
            //   Normal  Feu   Eau  Plante  Electrique  Glace  Combat  Poison  Sol   Vol   Psy   Insecte  Roche  Spectre  Acier  Dragon  Ténèbres  Fée
            {   1.0,   1.0,  1.0,   1.0,       1.0,   1.0,    1.0,    1.0,  1.0,  1.0,  1.0,     1.0,   0.5,    0.0,   1.0,    1.0,      1.0,  1.0},  // Normal
            {   1.0,   0.5,  0.5,   2.0,       1.0,   2.0,    1.0,    1.0,  1.0,  1.0,  1.0,     2.0,   0.5,    1.0,   0.5,    1.0,      1.0,  1.0},  // Feu
            {   1.0,   2.0,  0.5,   0.5,       1.0,   1.0,    1.0,    1.0,  2.0,  1.0,  1.0,     1.0,   2.0,    1.0,   1.0,    1.0,      1.0,  1.0},  // Eau
            {   1.0,   0.5,  2.0,   0.5,       1.0,   1.0,    1.0,    0.5,  2.0,  0.5,  1.0,     0.5,   2.0,    1.0,   1.0,    1.0,      1.0,  1.0},  // Plante
            {   1.0,   1.0,  2.0,   0.5,       0.5,   1.0,    1.0,    1.0,  0.0,  2.0,  1.0,     1.0,   1.0,    1.0,   1.0,    1.0,      1.0,  1.0},  // Electrique
            {   1.0,   1.0,  1.0,   2.0,       1.0,   0.5,    1.0,    1.0,  2.0,  2.0,  1.0,     1.0,   2.0,    1.0,   1.0,    1.0,      1.0,  1.0},  // Glace
            {   2.0,   1.0,  1.0,   1.0,       1.0,   1.0,    1.0,    0.5,  1.0,  0.5,  0.5,     0.5,   2.0,    0.0,   1.0,    2.0,      1.0,  0.5},  // Combat
            {   1.0,   1.0,  1.0,   2.0,       1.0,   1.0,    1.0,    0.5,  0.5,  1.0,  1.0,     1.0,   1.0,    0.5,   1.0,    1.0,      1.0,  2.0},  // Poison
            {   1.0,   2.0,  1.0,   0.5,       2.0,   0.0,    1.0,    2.0,  1.0,  0.0,  1.0,     0.5,   2.0,    1.0,   1.0,    1.0,      1.0,  1.0},  // Sol
            {   1.0,   1.0,  1.0,   1.0,       0.5,   2.0,    1.0,    1.0,  1.0,  1.0,  1.0,     1.0,   0.5,    1.0,   1.0,    1.0,      1.0,  1.0},  // Vol
            {   1.0,   1.0,  1.0,   1.0,       2.0,   1.0,    1.0,    1.0,  1.0,  1.0,  0.5,     1.0,   2.0,    2.0,   1.0,    1.0,      1.0,  1.0},  // Psy
            {   1.0,   0.5,  0.5,   2.0,       1.0,   2.0,    1.0,    0.5,  2.0,  0.5,  2.0,     1.0,   1.0,    2.0,   0.5,    1.0,      1.0,  0.5},  // Insecte
            {   1.0,   2.0,  1.0,   1.0,       1.0,   0.5,    2.0,    0.5,  1.0,  2.0,  1.0,     2.0,   1.0,    1.0,   0.5,    1.0,      1.0,  1.0},  // Roche
            {   0.0,   1.0,  1.0,   1.0,       1.0,   1.0,    0.5,    0.5,  1.0,  0.0,  2.0,     1.0,   1.0,    2.0,   1.0,    1.0,      1.0,  1.0},  // Spectre
            {   1.0,   0.5,  0.5,   0.5,       0.5,   2.0,    1.0,    2.0,  1.0,  1.0,  1.0,     2.0,   1.0,    1.0,   0.5,    0.5,      1.0,  2.0},  // Acier
            {   1.0,   1.0,  1.0,   1.0,       1.0,   1.0,    2.0,    1.0,  1.0,  1.0,  1.0,     1.0,   1.0,    1.0,   1.0,    2.0,      0.5,  1.0},  // Dragon
            {   1.0,   1.0,  1.0,   1.0,       1.0,   1.0,    0.5,    1.0,  1.0,  1.0,  2.0,     1.0,   1.0,    0.5,   2.0,    1.0,      0.5,  2.0},  // Ténèbres
            {   1.0,   1.0,  1.0,   1.0,       1.0,   1.0,    0.5,    2.0,  1.0,  1.0,  0.5,     1.0,   1.0,    2.0,   1.0,    0.5,      1.0,  1.0}   // Fée
    };
    int attackTypeIndex = getTypeIndex(attacker->type);
    int defenseTypeIndex = getTypeIndex(defender->type);
    return type_bonus[attackTypeIndex][defenseTypeIndex];

}

void playerTurn(Player *player, Pokemon *enemy, int *pokemonUseInd){
    int choice;
    printf("What do you want to do ?\n");
    printf("1. Attack\n");
    printf("2. Change pokemon\n");
    printf("3. Run\n");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            printf("You attack !\n");
            enemy->hp -= player->team->pokemons[*pokemonUseInd]->attack;
            printf("The enemy has %d HP left\n", enemy->hp);
            break;
        case 2:
            printf("You change pokemon !\n");
            break;
        case 3:
            printf("You run !\n");
            break;
        default:
            printf("You do nothing !\n");
            break;
    }
}

void enemyTurn(Player *player, Pokemon *enemy, int *pokemonUseInd){
    printf("The enemy attacks !\n");
    double multiplier = getMultiplier(player->team->pokemons[*pokemonUseInd], enemy);
    int damages = (enemy->attack - player->team->pokemons[*pokemonUseInd]->defense) * multiplier ;
    player->team->pokemons[*pokemonUseInd]->hp -= damages;
    printf("You have %d HP left\n", player->team->pokemons[*pokemonUseInd]->hp);
}


void launchBattle(Player *player, Pokedex *pokedex){
    srand(time(NULL));
    int rand = random() % pokedex->nbPokemons - 1;
    pokedex->pokemons[rand]->isSeen = 1;
    Pokemon *enemy = pokedex->pokemons[rand];

    int *pokemonUseInd = malloc(sizeof(int));
    *pokemonUseInd = 0;
    int turn;

    printf("%d", *pokemonUseInd);
    //printf("%s", player->team->pokemons[0]->name);


    printf("A wild %s appeared !\n", enemy->name);
    printf("Starting battle...\n\n");

    if (player->team->pokemons[*pokemonUseInd]->speed > enemy->speed){
        printf("You start !\n");
        playerTurn(player, enemy, pokemonUseInd);
        turn = 0;
    } else {
        printf("The enemy starts !\n");
        enemyTurn(player, enemy, pokemonUseInd);
        turn = 1;
    }

    while (player->team->alivePokemons > 0 || enemy->hp > 0){
        if (turn == 0){
            playerTurn(player, enemy, pokemonUseInd);
            turn = 1;
        } else {
            enemyTurn(player, enemy, pokemonUseInd);
            turn = 0;
        }
    }



    printf("Pokemons: %d\n", pokedex->nbPokemons);
}