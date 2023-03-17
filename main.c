#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//beecrowd 1021 : Banknotes and Coins

double round(double num) {
    double integer_part = (double)(int)num;
    double fractional_part = num - integer_part;
    if (fractional_part >= 0.5) {
        return integer_part + 1.0;
    } else {
        return integer_part;
    }
}


int main() {
    double money;
    int notes[] = {100, 50, 20, 10, 5, 2};
    int coins[] = {100, 50, 25, 10, 5, 1};

    scanf("%lf", &money);
    
    // we use round() function becouse the floating-point number that needs to be rounded off to the nearest integer in our case .
     
    int money_in_cents = round(money * 100);

    printf("NOTAS:\n");

    for (int i = 0; i < 6; i++) {
        int remain = money_in_cents / (notes[i] * 100);
        printf("%d nota(s) de R$ %d.00\n", remain, notes[i]);
        money_in_cents -= remain * (notes[i] * 100);
    }

    printf("MOEDAS:\n");

    for (int i = 0; i < 6; i++) {
        int remain = money_in_cents / coins[i];
        printf("%d moeda(s) de R$ %.2lf\n", remain, coins[i] / 100.0);
        money_in_cents -= remain * coins[i];
    }

    return 0;
}

