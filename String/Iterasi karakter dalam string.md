## Konsep iterasi dalam string
String di C adalah array karakter, sehingga untuk mengakses karakter di dalamnya kita bisa langsung menggunakan indeks array biasa
Contoh:
```c
char string[20] = "martabak keju";

    printf("%c\n", string[0]);
    printf("%c\n", string[3]);
    printf("%c\n", string[10]);
```
yang akan menghasilkan output
```plaintext
m
t
e
```


## Cara iterasi string
Selain dengan secara langsung menggunakan indeks array, iterasi array juga dapat dilakukan dengan beberapa cara
### Menggunakan for loop
Pada program di bawah, program akan mencetak karakter yang ada dalam string sampai mencapai karakter \0.
```c
#include <stdio.h>

int main() {
    char string[20] = "martabak keju";

    for (int i = 0; string[i] != '\0'; i++) {
        printf("Karakter pada indeks ke %d: %c\n", i, string[i]);
    }

    return 0;
}
```
Yang akan menghasilkan output
```plaintext
Karakter pada indeks ke 0: m
Karakter pada indeks ke 1: a
Karakter pada indeks ke 2: r
Karakter pada indeks ke 3: t
Karakter pada indeks ke 4: a
Karakter pada indeks ke 5: b
Karakter pada indeks ke 6: a
Karakter pada indeks ke 7: k
Karakter pada indeks ke 8:
Karakter pada indeks ke 9: k
Karakter pada indeks ke 10: e
Karakter pada indeks ke 11: j
Karakter pada indeks ke 12: u
```
### Menggunakan while loop
Iterasi string juga dapat dilakukan menggunakan while loop dengan konsep yang hampir sama
kode akan mencetak karakter dari indeks ke-0 sebelum mencapai \0.
```c
#include <stdio.h>

int main() {
    char string[] = "martabak keju";

    int i = 0;
    while (string[i] != '\0') {
        printf("Karakter: %c\n", string[i]);
        i++;
    }

    return 0;
}
```
akan menghasilkan output
```plaintext
Karakter: m
Karakter: a
Karakter: r
Karakter: t
Karakter: a
Karakter: b
Karakter: a
Karakter: k
Karakter:
Karakter: k
Karakter: e
Karakter: j
Karakter: u
```
### Menggunakan pointer
pointer dapat digunakan untuk iterasi tanpa indeks. Contoh kode yang akan menhasilkan output sama dengan iterasi dengan while loop
```c
#include <stdio.h>

int main() {
    char string[] = "martabak keju";
    char *ptr = string;  // Pointer menunjuk ke elemen pertama string
    while (*ptr != '\0') {
        printf("Karakter: %c\n", *ptr);
        ptr++;  // Pindah ke elemen berikutnya
    }
    
    return 0;
}
```

## Manipulasi dalam iterasi
### Menghitung jumlah karakter
Ada dua cara yang bisa dilakukan untuk menetahui jumlah karakter dalam suatu string, yaitu dengan menggunakan strlen atau tidak. 
Menggunakan strlen:
```c
#include <stdio.h>
#include <string.h> // menambahkan library string agar bisa menggunakan fungsi strlen

int main() {
    char string[] = "ungu janda";
    
    int panjangString = strlen(string);
    printf("panjang string di atas adalah %d", panjangString);

    return 0;
}
```
Kita juga bisa menghitung langsung dengan looping tanpa menggunakan strlen
```c
#include <stdio.h>

int main() {
    char string[] = "ungu janda";
    
    int panjangString = 0; // nilai awal panjangString adalah 0

    for (int i = 0; string[i] != '\0'; i++) {
        panjangString++; // panjang string akan bertambah jika karakter belum habis atau tidak sama dengan \0
    }

    printf("panjang string di atas adalah %d", panjangString);

    return 0;
}
```
Kedua kode di atas akan menghasilkan output yang sama, yaitu:
```plaintext
panjang string di atas adalah 10
```
### Membalik string
Untuk membalik suatu string, maka output yang ditampilkan dimulai dari paling belakang terlebih dahulu
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "batu bata";
    int panjangString = strlen(str);

    printf("string yang dibalik: ");
    for (int i = panjangString - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}
```
Menghasilkan output
```plaintext
string yang dibalik: atab utab
```
### Mengubah huruf kecil ke huruf besar
Untukmengkapitalkan suatu string sebenarnya bisa mengunakan fungsi toupper dengan library <cctype,h>. Namun juga bisa mengubah satu persatu karakter, menyesuaikan dengan tabel ASCII.
```c
#include <stdio.h>
int main() {
    char str[] = "jadi besar";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') { // Mengecek apakah huruf kecil
            str[i] -= 32;  // Konversi ke huruf besar dengan tabel ASCII
        }
    }
    printf("string modifikasi: %s\n", str);
    return 0;
}
```
Outputnya akan menjadi
```plaintext
string modifikasi: JADI BESAR
```
