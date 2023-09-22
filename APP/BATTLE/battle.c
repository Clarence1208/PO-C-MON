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

void choosePokemon (Player *player, int *pokemonUseInd){
    int choice;
    printf("Choose a pokemon to fight !\n");
    int count = player->team->alivePokemons;
    for (int i = 0; i < count; i++){
        if (player->team->pokemons[i] <= 0){
            count++;
            continue;
        }
        printf("%d. - %s\n", i+1, player->team->pokemons[i]->name);
    }
    scanf("%d", &choice);
    while (choice < 1 || choice > player->team->alivePokemons){
        printf("You can only choose a pokemon in your team !\n");
        scanf("%d", &choice);
    }
    *pokemonUseInd = choice - 1;
    printf("You choose %s !\n\n", player->team->pokemons[*pokemonUseInd]->name);
    printf("Go %s !\n", player->team->pokemons[*pokemonUseInd]->name);
}

int playerTurn(Player *player, Pokemon *enemy, int *pokemonUseInd){
    int choice;
    printf("What do you want to do ?\n");
    printf("1. Attack\n");
    printf("2. Change pokemon\n");
    printf("3. Run\n");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            printf("You attack !\n");
            double multiplier = getMultiplier(player->team->pokemons[*pokemonUseInd], enemy);
            int damages = (player->team->pokemons[*pokemonUseInd]->attack - enemy->defense) * multiplier ;
            enemy->hp -= damages;
            printf("%s is using %s against the  %s enemy !\n", player->team->pokemons[*pokemonUseInd]->name, player->team->pokemons[*pokemonUseInd]->attackName, enemy->name);
            printf("You deal %d damages !\n", damages);
            if (multiplier > 1){
                printf("It's super effective !\n");
            } else if (multiplier < 1){
                printf("It's not very effective...\n");
            }
            printf("The enemy has %d HP left\n", enemy->hp);
            break;
        case 2:
            printf("You change pokemon !\n");
            choosePokemon(player, pokemonUseInd);
            break;
        case 3:
            printf("You are trying to run !\n");
            srand(time(NULL));
            int rand = random()%2;
            if (rand == 0){
                printf("You escaped !\n");
                return 1;
            } else {
                printf("You failed to escape !\n");
            }
            break;
        default:
            printf("You do nothing !\n");
            break;
    }
    return 0;
}

void enemyTurn(Player *player, Pokemon *enemy, int *pokemonUseInd){
    printf("The enemy attacks !\n");
    double multiplier = getMultiplier(enemy, player->team->pokemons[*pokemonUseInd]);
    int damages = (enemy->attack - player->team->pokemons[*pokemonUseInd]->defense) * multiplier ;
    player->team->pokemons[*pokemonUseInd]->hp -= damages;

    printf("the %s enemy is using %s against %s !\n", enemy->name, enemy->attackName, player->team->pokemons[*pokemonUseInd]->name);
    printf("The enemy deals %d damages !\n", damages);
    if (multiplier > 1){
        printf("It's super effective !\n");
    } else if (multiplier < 1){
        printf("It's not very effective...\n");
    }

    if(player->team->pokemons[*pokemonUseInd]->hp <= 0){
        printf("Your pokemon is dead !\n");
        player->team->alivePokemons--;
        if(player->team->alivePokemons == 0){
            printf("!!!!!!!!!!! You lost !!!!!!!!!!!\n");
            exit(0);
        }
        choosePokemon(player, pokemonUseInd);

    }
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

    /*printf("%d", *pokemonUseInd);
    printf("%p", player->team->pokemons[0]);*/

    int escape = 0;


    printf("A wild %s appeared !\n", enemy->name);
    printf("Starting battle...\n\n");

    if (player->team->pokemons[*pokemonUseInd]->speed > enemy->speed){
        printf("You start !\n");
        escape = playerTurn(player, enemy, pokemonUseInd);
        if (escape == 1){
            return;
        }
        turn = 0;
    } else {
        printf("The enemy starts !\n");
        enemyTurn(player, enemy, pokemonUseInd);
        turn = 1;
    }

    while (player->team->alivePokemons > 0 || enemy->hp > 0){
        if (turn == 0){
            escape = playerTurn(player, enemy, pokemonUseInd);
            if (escape == 1){
                return;
            }
            turn = 1;
        } else {
            enemyTurn(player, enemy, pokemonUseInd);
            turn = 0;
        }
    }



    printf("Pokemons: %d\n", pokedex->nbPokemons);
}