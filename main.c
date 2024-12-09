#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, ilk, son, orta, N, aranan, gecici;
    printf("BINARY SEARCH ALGORITHM\n");
    printf("Kac adet sayi uretilecek: ");
    scanf("%d", &N);
    int dizi[N];
    srand(time(0));
    printf("Dizi Elemanlari:\n");
    for (i = 0; i < N; i++) {
        dizi[i] = rand() % 100;
        printf("%d ", dizi[i]);
    }

    for (i = 0; i < (N-1); i++) {
        for (j = 0; j < (N-i-1); j++) {
            if(dizi[j] > dizi[j+1]) {
                gecici = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = gecici;
            }
        }
    }
    printf("\nSiralanmis Dizi Elemanlari:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\nAranan degeri giriniz: ");
    scanf("%d", &aranan);
    ilk = 0;
    son = N-1;
    orta = (ilk + son)/2;
    while (ilk <= son) {
        if(dizi[orta] < aranan) {
            ilk = orta+1;
        }
        else if(dizi[orta] == aranan) {
            printf("%d sayisi %d. sirada bulundu.\n", aranan, orta+1);
            break;
        }else {
            son = orta-1;
        }
        orta = (ilk + son)/2;
    }
    if(ilk>son)
        printf("Bulunamadi.\n", aranan);
    return 0;
}