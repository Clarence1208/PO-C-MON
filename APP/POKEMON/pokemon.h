

// struct pokemon
typedef struct pokemon {
    char *name;
    int hp;
    int hpMax;
    int attack;
    int defense;
    int speed;
    char *type;
} Pokemon;

Pokemon * newPokemon(char *name, int hpMax, int attack, int defense, int speed,  char*type);
