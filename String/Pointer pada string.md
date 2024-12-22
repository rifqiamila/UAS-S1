## Apa itu pointer?
Pointer adalah variabel khusus yang menyimpan alamat memori dari variabel lain, termasuk array atau string. Dalam konteks string, pointer sering digunakan untuk merujuk ke alamat elemen-elemen dalam array karakter.

## Hubungan pointer dengan array karakter
String dalam C biasanya direpresentasikan sebagai array karakter. Nama array (misalnya char str[]) sebenarnya adalah pointer ke elemen pertama array tersebut. 
Pointer dapt digunakan untuk mengakses elemen pertama string, iterasi string, mengakses karakter dalam posisi tertentu, dan lainnya.
```c
#include <stdio.h>

int main() {
    char str[] = "Mie Ayam"; 
    char *ptr = str; // Pointer menunjuk ke elemen pertama string

    printf("Karakter pertama: %c\n", *ptr);

    // Pointer untuk mengakses elemen string
    printf("\nKarakter indeks-2: %c\n\n", *(ptr + 2));

    // Pointer untuk iterasi string
    printf("Iterasi string\n");
    while (*ptr != '\0') {  // Iterasi hingga null terminator
        printf("%c ", *ptr);  // Cetak karakter yang ditunjuk pointer
        ptr++;  // Pindahkan pointer ke karakter berikutnya
    }
}
```
Kode di atas akan menghasilkan output:
```plaintext
Karakter pertama: M

Karakter indeks-2: e

M i e   A y a m
```
```
