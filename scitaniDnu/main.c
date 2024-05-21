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

int konecDoZacRoku(int mesic, int rok, int dny){
    int output = 0;
    for (int m = mesic; m <= 12; m++) {
        output+= denMax(rok, m);
    }
    return output - dny;
}
int konecDoMesiceDruhehoRoku(int rok, int mesic, int den){
    int output = 0;
    for (int m = 1; m <= mesic; ++m) {
        output+= denMax(rok, m);
    }
    return output -  (denMax(rok, mesic) - den);

}
int mezidoba(int rok1, int rok2){
    int prestupnychUbehloRok1 = rok1 / 400 + rok1 / 4 - rok1 / 100;
    int prestupnychUbehloRok2 = rok2 / 400 + rok2 / 4 - rok2 / 100;

    return (rok2-rok1) * 365 + (prestupnychUbehloRok2 - prestupnychUbehloRok1);

    int roky = rok2-rok1;
    int mezipocet = roky / 4;
    int zbyleroky = roky - mezipocet;
    int output = (zbyleroky * 365) + (mezipocet * 366);
    return output;
}

int main() {
    int rok1 = RokMesicInput(1,1800, 2100, "rok");
    int mesic1 = RokMesicInput(1,1, 12, "mesic");
    int den1 = denInput(1, denMax(rok1, mesic1));

    int rok2= RokMesicInput(1,1800, 2100, "rok");
    int mesic2 = RokMesicInput(1,1, 12, "mesic");
    int den2 = denInput(1, denMax(rok2, mesic2));

    int konecnyPocet = konecDoZacRoku(rok1, mesic1, den1) + konecDoMesiceDruhehoRoku(rok2, mesic2, den2) + mezidoba(rok1, rok2) ;

    printf("\nMezi daty %2d.%2d.%4d a %2d.%2d.%4d ubehlo %d dni", den1, mesic1, rok1, den2, mesic2, rok2, konecnyPocet);
    return 0;
}
