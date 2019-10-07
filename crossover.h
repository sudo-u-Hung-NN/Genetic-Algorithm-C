//
// Created by sdragnol on 02/10/2019.
//

#ifndef GA_CROSSOVER_H
#define GA_CROSSOVER_H
void One_Point_Crossover(information parent_1, information parent_2, information *sun_1, information *sun_2)
{
    int ngau_nhien;
    ngau_nhien = rand()%(_CHROMOSOME_SIZE_ - 1) + 1;
    for(int i = 0; i < ngau_nhien; i++)
    {
        sun_1->selection[i] = parent_1.selection[i];
        sun_2->selection[i] = parent_2.selection[i];
    }
    for(int i = ngau_nhien; i < _CHROMOSOME_SIZE_; i++)
    {
        sun_1->selection[i] = parent_2.selection[i];
        sun_2->selection[i] = parent_1.selection[i];
    }
    Individual_Generate(sun_1);
    Individual_Generate(sun_2);
}
void Multi_Point_Crossover(information parent_1, information parent_2, information *sun_1, information *sun_2)
{
    int point[_MULTI_POINT_CROSSOVER_];
    Random_Lay_n_So(_CHROMOSOME_SIZE_ - 1, _MULTI_POINT_CROSSOVER_, point);
    for(int i = 0; i < _MULTI_POINT_CROSSOVER_; i++)
        point[i]++;
    Bubble_Sort(point, _MULTI_POINT_CROSSOVER_);
    int suitchi = 1, bd = 0;
    for(int i = 0; i < _CHROMOSOME_SIZE_; i++)
    {
        if(point[bd] == i)
        {
            bd++;
            suitchi = suitchi * (-1);
        }
        if(suitchi == 1)
        {
            sun_1->selection[i] = parent_1.selection[i];
            sun_2->selection[i] = parent_2.selection[i];
        }
        else
        {
            sun_1->selection[i] = parent_2.selection[i];
            sun_2->selection[i] = parent_1.selection[i];
        }
    }
    Individual_Generate(sun_1);
    Individual_Generate(sun_2);
}
void Uniform_Crossover(information parent_1, information parent_2, information *sun_1, information *sun_2)
{
    int suitchi = 1;
    for(int i = 0; i < _CHROMOSOME_SIZE_; i++)
    {
        if(rand()%2)
            suitchi = suitchi * (-1);
        if(suitchi == 1)
        {
            sun_1->selection[i] = parent_1.selection[i];
            sun_2->selection[i] = parent_2.selection[i];
        }
        else
        {
            sun_1->selection[i] = parent_2.selection[i];
            sun_2->selection[i] = parent_1.selection[i];
        }
    }
    Individual_Generate(sun_1);
    Individual_Generate(sun_2);
}

void Cross_Over(information parent_1, information parent_2, information *sun_1, information *sun_2)
{
    Multi_Point_Crossover(parent_1, parent_2, sun_1, sun_2);
}
#endif //GA_CROSSOVER_H
