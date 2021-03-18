#include <stdio.h>

void dec_to_bin(int num){
    if(num==0){
        return;
    }
    dec_to_bin(num/2);
    printf("%d", num%2);
}

int num_pow(int num, int exp){
    if(exp == 0){
        return 1;
    }
    else{
        return num*num_pow(num, exp-1);
    }
}

float num_pow_ext(float num, int exp){
    if(exp < 0){
        num = (float)1/num;
        exp = - exp;
    }
    if(exp == 0){
        return 1;
    }
    else if(exp%2){
        return num*num_pow_ext(num, exp-1);
    }
    else{
        return num_pow_ext(num*num, exp/2);

    }
}

void init_field(int** arr, int x, int y, int count){
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            arr[i][j] = 0;
        }
    }

    for(int i =0; i<count; i++){
        int fl = 1;
        do{
           int x1 = rand() % x;
           int y1 = rand() % y;
           if(arr[x1][y1] == 0){
               arr[x1][y1]=1;
               fl = 0;
           }
        } while(fl);
    }
    printf("\n\n\n");
}

void print_field(int** arr, int x, int y){
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
          printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

int king_routes(int** arr, int x, int y){
    if(arr[x][y] == 1){
        return 0;
    }
    if(x==0 && y==0){
        return 0;
    }
    else if (x==0){
        if(king_routes(arr ,x, y-1)==0 && y!=1){
            return 0;
        }
        return 1;
    }
    else if (y==0){
        if(king_routes(arr ,x-1, y)==0 && x!=1){
            return 0;
        }
        return 1;
    }
    else{
        return king_routes(arr ,x, y-1) + king_routes(arr ,x-1, y);
    }
}


int main()
{
    dec_to_bin(103);
    printf("\n");
    printf("%d", num_pow(2,10));
    printf("\n");
    printf("%f", num_pow_ext(2,11));
    printf("\n");
    printf("%f", num_pow_ext(2,-4));
    printf("\n\n");

    const int sizeX = 8;
    const int sizeY = 8;
    int field[sizeX][sizeY];
    int* p_field[sizeX];
    for (int i=0; i<sizeX; i++) {
        p_field[i] = field[i];
        }

    init_field(p_field, sizeX, sizeY, 10);
    print_field(p_field, sizeX, sizeY);


    for(int i=0; i<sizeY; i++){
        for(int j=0; j<sizeX; j++){
          printf("%5d", king_routes(p_field ,i, j));
        }
        printf("\n");
    }

    return 0;
}
