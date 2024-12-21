## Apa itu string
String merupakan kumpulan dari karakter yang berurutan, misalnya "Hello".
String dalam bahasa C akan disimpan sebagai array of characters. 
Pada setiap string akan diakhiri dengan karakter khusus \0 yang menandai akhir string

## Cara mendeklarasikan string
1. Deklarasi dengan panjang yang ditetapkan
   ```c
   char string[5] = "Lima";
   // panjang string tersebut adalah 5 dengan elemen ['L', 'i', 'm', 'a', '\0']
   ```
2. Deklarasi tanpa panjang ditetapkan
   ```c
   char string = "Lima";
   // panjang string akan dihitung secara otomatis sesuai jumlah karakter +1 untuk '\0'
   ```
3. Inisialisasi manual
   ```c
   char string[5] = {'L', 'i', 'm', 'a'}
   ```
   
## Cara membaca input string
Sebelum membaca variabel, pertama pastikan variabel telah dibuat terlebih dahulu. Contoh:
```c
char warna[20];
printf("Apa warna kesukaanmu?\t");
scanf("%s", warna);
```
Namun input di atas hanya dapat membaca input sampai spasi saja, jadi semisal user memasukkan input yang lebih dari 1 kata misal "merah muda", yang terbaca hanya "merah" saja.
Untuk mengambil input dengan spasi bisa menggunakan:
```c
char warna[20];
printf("Apa warna kesukaanmu?\t");
scanf("%[^\n]", warna);
// atau
fgets(warna, sizeof(warna), stdin); // pilih salah satu saja
```
dengan begitu input spasi bisa ikut terbaca.
%[^\n] akan membaca karakter sampai menemui newline

## Cara menulis string ke output
untuk mencetak string secara keseluruhan dapat menggunakan fungsi printf
```c
char warna[20];
warna = "Ungu";
printf("Aku tebak warna kesukaanmu %s\n", warna);
```
outputnya akan menjadi
```plaintext
Aku tebak warna kesukaanmu ungu
```
Atau kita bisa mengiterasikan setiap karakter hingga menemukan \0
```c
char warna[20];
warna = "Ungu";
printf("Aku tebak warna kesukaanmu %s\n", warna);
for (int i = 0; warna[i] != '\0'; i++) {
   printf("%c", warna[i]);
}
```
output yang dihasilkan akan sama dengan output di atas

## Contoh penerapan
```c
#include <stdio.h>

int main() {
    char warna[20];

    printf("Apa warna kesukaanmu?\t");
    scanf("%[^\n]", warna);

    printf("\nAku tebak warna kesukaanmu %s\n", warna);
    printf("Dapat dieja\n");

    for(int i = 0; warna[i] != '\0'; i++) {
        printf("%c\t karakter ke-%d\n", warna[i], i);
    }

    return 0;
}
```
Tampilan output
```plaintext
Apa warna kesukaanmu?   ungu janda

Aku tebak warna kesukaanmu ungu janda
Dapat dieja
u        karakter ke-0
n        karakter ke-1
g        karakter ke-2
u        karakter ke-3
         karakter ke-4
j        karakter ke-5
a        karakter ke-6
n        karakter ke-7
d        karakter ke-8
a        karakter ke-9
```
