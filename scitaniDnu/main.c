#include <stdio.h>

int prestupnyRok(int rok) {
    return rok % 4 == 0 && rok % 100 != 0 || rok % 400 == 0;
}

int RokMesicInput(int poradi, int min, int max, char *slovo) {
    int output;
    int charCount;

    do {
        printf("%d. Zadejte %s v intervalu %d - %d\n",poradi, slovo, min, max);
        scanf("%d", &output);

        charCount = 0;
        while (getchar() != '\n') {
            charCount++;
        }
        if (charCount > 0) {
            printf("Neplatne znaky. Zkuste to znovu.\n");
        } else if (output < min || output > max) {
            printf("Cisla musi byt v intervalu. Zkuste to znovu.\n");
        }
    } while (charCount != 0 || output < min || output > max);

    return output;
}

int denMax(int rok, int mesic){
    if (mesic == 2 && prestupnyRok(rok) == 1){
        return 29;
    }
    else if (mesic == 2 && prestupnyRok(rok) == 0){
        return 28;
    }
    else if (mesic == 1 || mesic == 3 || mesic == 5 ||mesic == 7 || mesic == 8 || mesic == 10 || mesic == 12){
        return 31;
    }
    else if (mesic == 4 || mesic == 6 || mesic == 9 ||mesic == 11){
        return 30;
    }
}

int denInput(int poradi, int max) {

    int charCount;
    int output;

    do {
        printf("%d. Zadejte den v intervalu %d - %d\n",poradi, 1, max);
        scanf("%d", &output);

        charCount = 0;
        while (getchar() != '\n') {
            charCount++;
        }
        if (charCount > 0){
            printf("Neplatne znaky. Zkuste to znovu.\n");
        }
        else if (output < 1 || output > max) {
            printf("Cisla musi byt v intervalu. Zkuste to znovu.\n");
        }
    }while(charCount > 0 || output > max ||output < 1);


    return output;
}

int konecDoZacRoku(int rok, int mesic, int dny){
    int output = 0;
    for (int m = mesic; m <= 12; m++) {
        output+= denMax(rok, m);
    }
    return output - dny;
}
int konecDoMesiceDruhehoRoku(int rok, int mesic, int den){
    int output = 0;
    for (int m = 1; m < mesic; ++m) {
        output+= denMax(rok, m);
    }
    return output + den;

}
int mezidoba(int rok1, int rok2){
    int output =0;
    for (int r = rok1 + 1; r < rok2;r++)
    {
        output += prestupnyRok(r)? 366 : 365;
    }
    return output;
}
int stejnyRokDny(int rok,int mesic1, int mesic2,int dny1, int dny2){
    int output = 0;
    for(int m = mesic1; m < mesic2; m++){
        output+= denMax(rok, m);
    }
    output - dny1;
    return output - (denMax(rok, mesic2) - dny2);
}

int main() {
    int rok1 = RokMesicInput(1,1800, 2100, "rok");
    int mesic1 = RokMesicInput(1,1, 12, "mesic");
    int den1 = denInput(1, denMax(rok1, mesic1));

    int rok2= RokMesicInput(1,1800, 2100, "rok");
    int mesic2 = RokMesicInput(1,1, 12, "mesic");
    int den2 = denInput(1, denMax(rok2, mesic2));
    
    int konecnyPocet = 0;

    if (rok1 == rok2){
    stejnyRokDny(rok1, mesic1,mesic2,den1,den2);
    }else{
        konecnyPocet = konecDoZacRoku(rok1, mesic1, den1) + konecDoMesiceDruhehoRoku(rok2, mesic2, den2) + mezidoba(rok1, rok2) ;
    }
    

    printf("\nMezi daty %2d.%2d.%4d a %2d.%2d.%4d ubehlo %d dni", den1, mesic1, rok1, den2, mesic2, rok2, konecnyPocet);
    return 0;
}
