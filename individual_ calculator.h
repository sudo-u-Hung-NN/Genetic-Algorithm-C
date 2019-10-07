//
// Created by sdragnol on 30/09/2019.
//

#ifndef GA_INDIVIDUAL__CALCULATOR_H
#define GA_INDIVIDUAL__CALCULATOR_H
void Individual_Gold_Calculator(information *individual)
{
    int tong = 0;
    for(int i = 0; i < _CHROMOSOME_SIZE_; i++)
    {
        if(individual->selection[i] == 1)
        {
            tong += problem.gold[i];
        }
    }
    individual->gold = tong;

}
void Individual_Weigh_Calculator(information *individual)
{
    int tong = 0;
    for(int i = 0; i < _CHROMOSOME_SIZE_; i++)
    {
        if(individual->selection[i] == 1)
        {
            tong += problem.weigh[i];
        }
    }
    individual->weigh = tong;
}
void Individual_Fitness_Calculator(information *individual)
{
    individual->fitness = individual->gold;
}
void Individual_Calculator(information *individual)
{
    Individual_Gold_Calculator(individual);
    Individual_Weigh_Calculator(individual);
    Individual_Fitness_Calculator(individual);
}

void Population_Gold_Calculator(information individual[])
{
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        Individual_Gold_Calculator(&individual[i]);
    }
}
void Population_Weigh_Calculator(information individual[])
{
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        Individual_Weigh_Calculator(&individual[i]);
    }
}
void Population_Fitness_Calculator(information individual[])
{
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        Individual_Fitness_Calculator(&individual[i]);
    }
}
void Population_Calculator(information individual[])
{
    Population_Gold_Calculator(individual);
    Population_Weigh_Calculator(individual);
    Population_Fitness_Calculator(individual);
}


float Population_Fitness_Addition(information individual[])
{
    float tong = 0;
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        tong += individual[i].fitness;
    }
    return tong;
}
#endif //GA_INDIVIDUAL__CALCULATOR_H
