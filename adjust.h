//
// Created by sdragnol on 30/09/2019.
//

#ifndef GA_ADJUST_H
#define GA_ADJUST_H
void Individual_Weigh_Adjust(information *individual)
{
    int start, min_gold, danh_dau;
    while(individual->weigh > _CAPABILITY_)
    {
        for(int i = 0; i < _CHROMOSOME_SIZE_; i++)
        {
            if(individual->selection[i] == 1)
            {
                min_gold = individual->gold;
                start = i;
                danh_dau = i;
                break;
            }
        }
        for(int i = start + 1; i < _CHROMOSOME_SIZE_; i++)
        {
            if(individual->selection[i] == 1)
                if(min_gold > problem.gold[i])
                {
                    min_gold = problem.gold[i];
                    danh_dau = i;
                }
        }
        individual->selection[danh_dau] = 0;
        Individual_Weigh_Calculator(individual);
    }
}
void Population_Weigh_Adjust(information individual[])
{
    for(int i = 0; i < _POPULATION_SIZE_; i++)
    {
        Individual_Weigh_Adjust(&individual[i]);
    }
}

/// ADJUST WEIGH, RESET AGE, GOLD, FITNESS CALCULATOR
void Individual_Generate(information *individual)
{
    Individual_Weigh_Calculator(individual);
    Individual_Weigh_Adjust(individual);
    Individual_Calculator(individual);
    individual->age = 0;
}
#endif //GA_ADJUST_H
