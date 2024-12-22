###***Contoh program perkalian matriks***
---
// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    int k1,b1,k2,b2;
    
    printf("Masukkan jumlah baris matriks A: ");
    scanf("%d", &b1);
    printf("\nMasukkan jumlah kolom matriks A: ");
    scanf("%d", &k1);
    
    printf("Masukkan jumlah baris matriks B: ");
    scanf("%d", &b2);
    printf("\nMasukkan jumlah kolom matriks B: ");
    scanf("%d", &k2);
    
    if (k1 != b2){
        printf("maaf, matriks tidak bisa dikalikan");
        
        return 1;
    }
    
    int matriksAB[b1][k2];
    int matriksA[b1][k1];
    int matriksB[b2][k2];
    
    for (int i = 0; i < b1; i++){
        for (int j = 0; j < k1; j++){
            scanf("%d", &matriksA[i][j]);
        }
    }

    for (int i = 0; i < b2; i++){
        for (int j = 0; j < k2; j++){
            scanf("%d", &matriksB[i][j]);
        }
    }
    
    for (int i = 0; i < b1; i++){
        for (int j = 0; j< k2; j++){
            matriksAB[i][j] = 0;
            for (int k = 0; k < k1; k++) {
                matriksAB[i][j] += matriksA[i][k] * matriksB[k][j];
            }

        }
    }
    
    for (int i = 0; i < b1; i++){
        for (int j = 0; j < k2; j++){
            printf("%d\t", matriksAB[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
---

#****Penjumlahan Matriks**
---
// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    int k1,b1,k2,b2;
    
    printf("Masukkan jumlah baris matriks A: ");
    scanf("%d", &b1);
    printf("\nMasukkan jumlah kolom matriks A: ");
    scanf("%d", &k1);
    
    printf("Masukkan jumlah baris matriks B: ");
    scanf("%d", &b2);
    printf("\nMasukkan jumlah kolom matriks B: ");
    scanf("%d", &k2);
    
    if (k1 != k2 && b1 != b2){
        printf("maaf, matriks tidak bisa dijumlahkan");
        
        return 1;
    }
    
    int matriksAB[b1][k1];
    int matriksA[b1][k1];
    int matriksB[b2][k2];
    
    printf("input matriks A\n");
    for (int i = 0; i < b1; i++){
        for (int j = 0; j < k1; j++){
            scanf("%d", &matriksA[i][j]);
        }
    }

    printf("input matriks B\n");
    for (int i = 0; i < b2; i++){
        for (int j = 0; j < k2; j++){
            scanf("%d", &matriksB[i][j]);
        }
    }
    
    for (int i = 0; i < b1; i++){
        for (int j = 0; j< k2; j++){
                matriksAB[i][j] = matriksA[i][j] +  matriksB[i][j];
            }
    }
    
    for (int i = 0; i < b1; i++){
        for (int j = 0; j < k1; j++){
            printf("%d\t", matriksAB[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
---
