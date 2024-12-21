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
