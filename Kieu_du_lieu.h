//
// Created by sdragnol on 30/09/2019.
//

#ifndef GA_KIEU_DU_LIEU_H
#define GA_KIEU_DU_LIEU_H
typedef struct
{
    int selection[_CHROMOSOME_SIZE_];
    int gold;
    int weigh;
    float fitness;
    int age;
} information;

struct mondai
{
    int weigh[_CHROMOSOME_SIZE_];
    int gold[_CHROMOSOME_SIZE_];
};
struct mondai problem =
        {
                     /// {0,1,2,3,4,5,6,7,8,9}   ///NUMBER
                {3,5,7,6,5,4,4,7,2,6},  ///WEIGH
                {7,4,8,5,6,4,4,7,3,1}   ///GOLD
        };

#endif //GA_KIEU_DU_LIEU_H
