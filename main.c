/// MONDAI
///  {0,1,2,3,4,5,6,7,8,9}   //NUMBER
///  {3,5,7,6,5,4,4,7,2,6},  //WEIGH
///  {7,4,8,5,6,4,4,7,3,1}   //VALUE
///


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constan.h"
#include "Kieu_du_lieu.h"
#include "print.h"
#include "individual_ calculator.h"
#include "calculator.h"
#include "adjust.h"
#include "initialize.h"
#include "parents_seletion.h"
#include "crossover.h"
#include "mutation.h"
#include "survivor_seletion.h"



int main() {
    srand(time(NULL));
    information individual[_POPULATION_SIZE_];
    Initialize_Population(individual);
    ///////////////////////////////////////////////
    int count_end_game = 0, count_generation = 0;
    float fitness_population = Population_Fitness_Addition(individual);
    int parent_1, parent_2;
    int random;
    information sun_1, sun_2, best;
    while(count_end_game < _END_GAME_)
    {
        count_generation++;
        printf("-------------------\n");
        printf("Generation [%d]:\n", count_generation);
        Print_Information_Population(individual);
        /////////////////////
        Population_Age_Up(individual);
        Parents_Selection(individual, &parent_1, &parent_2);
        Cross_Over(individual[parent_1], individual[parent_2], &sun_1, &sun_2);
        random = rand()%100;
        if(random < _MUTATION_CHANCE_)
            Mutation(&sun_1);
        random = rand()%100;
        if(random < _MUTATION_CHANCE_)
            Mutation(&sun_2);
        Survivor_Selection(individual, sun_1, sun_2);
        if(fitness_population == Population_Fitness_Addition(individual))
            count_end_game++;
        else
        {
            fitness_population = Population_Fitness_Addition(individual);
            count_end_game = 0;
        }
        printf("TONG FITNESS: %f\n\n", fitness_population);
    }
    best = individual[0];
    for(int i = 1; i < _POPULATION_SIZE_; i++)
    {
        if(best.fitness < individual[i].fitness)
            best = individual[i];
    }
    //////////////////////
    printf("Best: ");
    Print_Information_Individual(best);
    printf("Over\n");
    return 1;
}
