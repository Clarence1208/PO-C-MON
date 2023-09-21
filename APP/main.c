#include "POKEMON/pokemon.h"
#include "POKEDEX/pokedex.h"

int main(int argc, char ** argv) {
    Pokemon *p = newPokemon("Pikachu", 100, 100, 100, 100, 0, "Electric");

    Pokedex *pokedex = newPokedexFromCsv("../FILES/pokedex.csv");
    return 0;
}