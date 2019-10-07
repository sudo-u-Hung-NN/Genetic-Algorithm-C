//
// Created by sdragnol on 02/10/2019.
//

#ifndef GA_SURVIVOR_SELETION_H
#define GA_SURVIVOR_SELETION_H
void Population_Age_Up(information individual[])
{
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        individual[i].age++;
    }
}
void Age_Based_Survivor(information individual[],int *count, information sun_1, information sun_2)
{
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        if(individual[i].age > _AGE_MAX_)
        {
            if(*count == 0)
                individual[i] = sun_1;
            else if(*count == 1)
                individual[i] = sun_2;
            (*count)++;
            if(*count == 2) break;
        }
    }
}
void Roulette_Wheel_Survivor();
void Tournament_Survivor(information individual[], int *count, information sun_1, information sun_2)
{
    if(*count != 2)
    {
        int mang_random[_TOURNAMENT_SURVIVOR_];
        int boolean = 0;
        int dead_1, dead_2;
        Random_Lay_n_So(_POPULATION_SIZE_, _TOURNAMENT_SURVIVOR_, mang_random);
        dead_1 = mang_random[0];
        for (int i = 1; i < _TOURNAMENT_SURVIVOR_; i++)
        {
            if (Individual_Compare(individual[dead_1], individual[mang_random[i]]) == 1)
                dead_1 = mang_random[i];
            else if (Individual_Compare(individual[dead_1], individual[mang_random[i]]) == 0)
            {
                if (rand() % 2)
                    dead_1 = mang_random[i];
            }
        }
        if (*count == 1)
        {
            individual[dead_1] = sun_2;
        }
        else if(*count == 0)
        {
            int boolean = 0;
            while(!boolean)
            {
                boolean = 1;
                Random_Lay_n_So(_POPULATION_SIZE_, _TOURNAMENT_SURVIVOR_, mang_random);
                for(int i = 0; i < _TOURNAMENT_SURVIVOR_; i++)
                {
                    if(dead_1 == mang_random[i])
                    {
                        boolean = 0;
                        break;
                    }
                }
            }
            dead_2 = mang_random[0];
            for(int i = 1; i < _TOURNAMENT_SURVIVOR_; i++)
            {
                if (Individual_Compare(individual[dead_2], individual[mang_random[i]]) == 1)
                    dead_2 = mang_random[i];
                else if (Individual_Compare(individual[dead_2], individual[mang_random[i]]) == 0)
                {
                    if (rand() % 2)
                        dead_2 = mang_random[i];
                }
            }
            individual[dead_1] = sun_1;
            individual[dead_2] = sun_2;
        }
    }
    *count = 2;
}
void Rank_Survivor();

void Survivor_Selection(information individual[], information sun_1, information sun_2)
{
    int count = 0;
    Age_Based_Survivor(individual, &count, sun_1, sun_2);
    Tournament_Survivor(individual, &count, sun_1, sun_2);
}
#endif //GA_SURVIVOR_SELETION_H
