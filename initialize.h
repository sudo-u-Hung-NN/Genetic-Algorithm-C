//
// Created by sdragnol on 30/09/2019.
//

#ifndef GA_INITIALIZE_H
#define GA_INITIALIZE_H
void Initialize_Population(information individual[])
{
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        for(int j = 0; j < _CHROMOSOME_SIZE_; j++)
        {
            individual[i].selection[j] = rand()%2;
        }
        Individual_Generate(&individual[i]);
    }
}
#endif //GA_INITIALIZE_H
