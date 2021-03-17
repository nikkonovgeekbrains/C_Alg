#include <stdio.h>
#include <math.h>

int main()
{
    printf("Input integer number:\n");
    int inp_num;
    scanf("%d",&inp_num);

    int cur_num = 2;
    int easyFl = 1;
    while(cur_num <= (sqrt((float)inp_num))){
        if (inp_num % cur_num == 0){
            easyFl = 0;
            break;
        }
            cur_num++;
    }
    if(easyFl){
        printf("Number %d is simple.", inp_num);
    }
    else{
        printf("Number %d isn`t simple.", inp_num);
    }
    return 0;
}
