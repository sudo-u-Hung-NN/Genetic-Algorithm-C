//
// Created by sdragnol on 02/10/2019.
//

#ifndef GA_PARENTS_SELETION_H
#define GA_PARENTS_SELETION_H
void Roulette_Wheel_Selection(information individual[], int *parent_1, int *parent_2)
{
    int tong = 0, ngau_nhien, mang_wheel[_POPULATION_SIZE_];
    tong = individual[0].fitness;
    mang_wheel[0] = individual[0].fitness;
    for(int i = 1; i < _POPULATION_SIZE_; i++)
    {
        tong += individual[i].fitness;
        mang_wheel[i] = mang_wheel[i-1] + individual[i].fitness;
    }
    ngau_nhien = rand()%tong;
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        if(mang_wheel[i] > ngau_nhien)
        {
            *parent_1 = i;
            break;
        }
    }
    *parent_2 = *parent_1;
    while(*parent_2 == *parent_1)
    {
        ngau_nhien = rand()%tong;
        for(int i = 0; i < _POPULATION_SIZE_; i++)
        {
            if(mang_wheel[i] > ngau_nhien)
            {
                *parent_2 = i;
                break;
            }
        }
    }
}
void Stochastic_Universal_Sampling(information individual[], int *parent_1, int *parent_2)
{
    int tong, ngau_nhien, doi_ngau_nhien, mang_wheel[_POPULATION_SIZE_];
    tong = individual[0].fitness;
    mang_wheel[0] = individual[0].fitness;
    for(int i = 1; i < _POPULATION_SIZE_; i++)
    {
        tong += individual[i].fitness;
        mang_wheel[i] = mang_wheel[i-1] + individual[i].fitness;
    }
    ngau_nhien = rand()%tong;
    doi_ngau_nhien = (ngau_nhien >= tong/2)? ngau_nhien - tong/2: ngau_nhien + tong/2;
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        if(mang_wheel[i] > ngau_nhien)
        {
            *parent_1 = i;
            break;
        }
    }
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        if(mang_wheel[i] > doi_ngau_nhien)
        {
            *parent_2 = i;
            break;
        }
    }
}
void Tournament_Seletion(information individual[], int *parent_1, int *parent_2)
{
    int mang_random[_TOURNAMENT_SELECTION_];
    Random_Lay_n_So(_POPULATION_SIZE_, _TOURNAMENT_SELECTION_, mang_random);
    *parent_1 = mang_random[0];
    for(int i = 1; i < _TOURNAMENT_SELECTION_; i++)
    {
        if(Individual_Compare(individual[mang_random[i]], individual[*parent_1]) == 1)
        {
            *parent_1 = mang_random[i];
        }
        else if(Individual_Compare(individual[mang_random[i]], individual[*parent_1]) == 0)
        {
            if(rand()%2)
                *parent_1 = mang_random[i];
        }
    }
    int boolean = 0;
    while(!boolean)
    {
        boolean = 1;
        Random_Lay_n_So(_POPULATION_SIZE_, _TOURNAMENT_SELECTION_, mang_random);
        for(int i = 0; i < _TOURNAMENT_SELECTION_; i++)
        {
            if(*parent_1 == mang_random[i])
            {
                boolean = 0;
                break;
            }
        }
    }
    *parent_2 = mang_random[0];
    for(int i = 1; i < _TOURNAMENT_SELECTION_; i++)
    {
        if(Individual_Compare(individual[mang_random[i]], individual[*parent_2]) == 1)
        {
            *parent_2 = mang_random[i];
        }
        else if(Individual_Compare(individual[mang_random[i]], individual[*parent_2]) == 0)
        {
            if(rand()%2)
                *parent_2 = mang_random[i];
        }
    }
}
void Rank_Selection(information individual[], int *parent_1, int *parent_2);

void Parents_Selection(information individual[], int *parent_1, int *parent_2)
{
    Roulette_Wheel_Selection(individual, parent_1, parent_2);
}
#endif //GA_PARENTS_SELETION_H
