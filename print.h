//
// Created by sdragnol on 30/09/2019.
//

#ifndef GA_PRINT_H
#define GA_PRINT_H
void Print_Information_Population(information individual[])
{
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        printf("Individual[%d]: ", i);
        for(int j = 0; j < _CHROMOSOME_SIZE_; j++)
        {
            printf("%d ", individual[i].selection[j]);
        }
        printf("\n");
        printf("Gold: %d\n", individual[i].gold);
        printf("Weigh: %d\n", individual[i].weigh);
        printf("Fitness: %.2f\n", individual[i].fitness);
        printf("Age: %d\n", individual[i].age);
    }
}
void Print_Information_Individual(information individual)
{
    for(int j = 0; j < _CHROMOSOME_SIZE_; j++)
    {
        printf("%d ", individual.selection[j]);
    }
    printf("\n");
    printf("Gold: %d\n", individual.gold);
    printf("Weigh: %d\n", individual.weigh);
    printf("Fitness: %.2f\n", individual.fitness);
    printf("Age: %d\n", individual.age);

    printf("\n");
}

#endif //GA_PRINT_H
