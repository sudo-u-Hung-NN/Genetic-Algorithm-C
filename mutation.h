//
// Created by sdragnol on 02/10/2019.
//

#ifndef GA_MUTATION_H
#define GA_MUTATION_H
void Bit_Flip_Mutation(information *individual)
{
    int point[_BIT_FLIP_MUTATION_];
    Random_Lay_n_So(_CHROMOSOME_SIZE_, _BIT_FLIP_MUTATION_, point);
    Bubble_Sort(point, _BIT_FLIP_MUTATION_);
    int bd = 0;
    for(int i = 0; i < _CHROMOSOME_SIZE_; i++)
    {
        if(i == point[bd])
        {
            bd++;
            if(individual->selection[i] == 0)
                individual->selection[i] = 1;
            else individual->selection[i] = 0;
        }
    }
    Individual_Generate(individual);
}
void Swap_Mutation(information *individual)
{
    int point[2];
    for(int i = 0; i < _SWAP_MUTATION_; i++)
    {
        Random_Lay_n_So(_CHROMOSOME_SIZE_, 2, point);
        Swap_Int(&individual->selection[point[0]], &individual->selection[point[1]]);
    }
    Individual_Generate(individual);
}
void Scramble_Mutation(information *individual)
{
    int First_Last[2];
    int random_point[2];
    Random_Lay_n_So(_CHROMOSOME_SIZE_, 2, First_Last);
    if(First_Last[0] > First_Last[1])
        Swap_Int(&First_Last[0], &First_Last[1]);
    for(int i = 0; i < (First_Last[1] - First_Last[0] + 1)*2; i++)
    {
        Random_Lay_n_So((First_Last[1] - First_Last[0] + 1), 2, random_point);
        random_point[0] += First_Last[0];
        random_point[1] += First_Last[0];
        Swap_Int(&individual->selection[random_point[0]], &individual->selection[random_point[1]]);
    }
    Individual_Generate(individual);
}
void Inversion_Mutation(information *individual)
{
    int First_Last[2];
    Random_Lay_n_So(_CHROMOSOME_SIZE_, 2, First_Last);
    if(First_Last[0] > First_Last[1])
        Swap_Int(&First_Last[0], &First_Last[1]);
    int tong = First_Last[0] + First_Last[1];
    for(int i = First_Last[0]; i <= tong/2; i++)
    {
        Swap_Int(&individual->selection[i], &individual->selection[tong - i]);
    }
    Individual_Generate(individual);
}

void Mutation(information *individual)
{
    int random;
    random = rand()%4;
    switch(random)
    {
        case 0:
        {
            Bit_Flip_Mutation(individual);
            break;
        }
        case 1:
        {
            Swap_Mutation(individual);
            break;
        }
        case 2:
        {
            Scramble_Mutation(individual);
            break;
        }
        case 3:
        {
            Inversion_Mutation(individual);
            break;
        }
    }
}
#endif //GA_MUTATION_H
