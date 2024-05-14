#include <stdio.h>
#include <string.h>

#define DENMAX 31
#define DENMESICMIN 1
#define MESICMAX 12
#define ROKMAX 2100
#define ROKMIN 1800
int leapYear(int year){
    if (year % 4 == 0 && year % 100 != 0 ||year % 400 == 0)
    {
        return 1;
    }
    return 0;
}

int vstup(int poradi, char* denMesicRok, int min, int max, int rok, int mesic ){
    int vystup;
    int charr = 0;
    if (strcmp(denMesicRok, 'den') == 1 && leapYear(rok) == 1 && mesic == 2)
    {
            max=29;
    }
    else if(strcmp(denMesicRok, 'den') == 1 && leapYear(rok) == 0 && mesic == 2){
        max=28;
    }
    do {
        printf("%d. Zadejte %s v intervalu %d - %d: ",poradi, denMesicRok, min, max);
        scanf("%d", &vystup);


        while(getchar()!= '\n'){
            charr++;
        }
        if(charr!= 0){
            printf("Spatny/e znak/y :/\n");
        }
        else if (vystup < min || vystup > max){
            printf("Cislo nebylo v intervalu\n");
        }
    }while(vystup < min || vystup > max||charr!= 0);


    return vystup;
}

int main() {
    int rok1 = vstup(1,"rok", ROKMIN, ROKMAX, 0, 0);
    int mesic1 = vstup(1,"mesic", DENMESICMIN, MESICMAX, rok1, 0);
    int den1 = vstup(1,"den", DENMESICMIN, DENMAX, rok1, mesic1);


    int rok2 = vstup(2,"rok", ROKMIN, ROKMAX, 0,0);
    int mesic2 = vstup(2,"mesic", DENMESICMIN, MESICMAX, rok2, 0);
    int den2 = vstup(2,"den", DENMESICMIN, DENMAX, rok2, mesic2);

    return 0;
}
