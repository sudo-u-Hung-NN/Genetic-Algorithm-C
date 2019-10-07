//
// Created by sdragnol on 04/10/2019.
//

#ifndef GA_CALCULATOR_H
#define GA_CALCULATOR_H
void Random_Lay_n_So(int Khoang_random, int n, int mang[])
{
    mang[0] = rand() % Khoang_random;
    int boolean;
    for(int i = 1; i < n; i++)
    {
        boolean = 0;
        while(!boolean)
        {
            boolean = 1;
            mang[i] = rand() % Khoang_random;
            for (int j = 0; j < i; j++)
            {
                if (mang[i] == mang[j])
                {
                    boolean = 0;
                    break;
                }
            }
        }
    }
}
int Individual_Compare(information individual_1, information individual_2)
{
    if(individual_1.fitness > individual_2.fitness)
        return 1;
    else if(individual_1.fitness < individual_2.fitness)
        return -1;
    else if(individual_1.weigh < individual_2.weigh)
        return 1;
    else if(individual_1.weigh > individual_2.weigh)
        return -1;
    else return 0;
}
void Swap_Int(int *a, int *b)
{
    int tg;
    tg = *a;
    *a = *b;
    *b = tg;
}
void Bubble_Sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                Swap_Int(&arr[j], &arr[j + 1]);
}

#endif //GA_CALCULATOR_H
