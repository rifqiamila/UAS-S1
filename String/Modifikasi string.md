## Mengubah karakter tertentu
Karakter yang ingin di edit bisa langsung diakses dengan indeks. 
Contoh mengganti karakter tertentu dalam string:
```c
#include <stdio.h>
int main() {
    char str[] = "tahu bulat goreng panas";

    for (int i = 0; str[i] != '\0'; i++) {
        // Mengubah karakter a menjadi o
        if (str[i] == 'a') { 
            str[i] = 'o';  
        }
    }

    printf("string modifikasi: %s\n", str);
    
    return 0;
}
```
Akan menghasilkan output
```plaintext
string modifikasi: tohu bulot goreng ponos
```
## Membalik string dengan pointer
Selain dengan langsung akses indeks dari belakang saat mencetak output, memebalik string juga bisa menggunakan pointer
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "0123456789";
    char *start = str; // Pointer ke karakter pertama
    char *end = str + strlen(str) - 1;  // Pointer ke karakter terakhir
    char temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
```
Karakter di posisi start dan end akan ditukar, kedua pointer bererak ke tengah. 
Akan menghasilkan output
```plaintext
Reversed string: 9876543210
```

## Menyalin string dengan pointer
Menyalin string artinya kita memberi karakter yang sama ke string tujuan dari string sumber. Contoh
```c
#include <stdio.h>

int main() {
    char source[] = "Copy copy"; // String asal (sumber)
    char destination[50];  // Pastikan ukuran string tujuan cukup
    char *src = source;    // Pointer ke sumber
    char *dest = destination;  // Pointer ke tujuan

    while (*src != '\0') {
        *dest = *src;  // Salin karakter
        src++;
        dest++;
    }
    *dest = '\0';  // Tambahkan null terminator

    printf("Sumber: %s\n", source);
    printf("Tujuan: %s\n", destination);

    return 0;
}
```
Output:
```plaintext
Sumber: Copy copy
Tujuan: Copy copy
```

## Beberapa fungsi di library <string.h>
Kode:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Konsep Pengawuran ";
    char str2[] = "Konsep Pemograman";
    char str3[30] = "kosong";
    
    printf("Kondisi awal string\n");
    printf("String 1:\t%s\n", str1);
    printf("String 2:\t%s\n", str2);
    printf("String 3:\t%s\n", str3);

    // strcpy untuk menyalin string (tujuan, asal)
    strcpy(str3, str1); // str3 berisi str1
    printf("\nKondisi string setelah strcpy\n");
    printf("String 1:\t%s\n", str1);
    printf("String 2:\t%s\n", str2);
    printf("String 3:\t%s\n", str3);

    // strcat untuk menggabungkan string
    strcat(str1, str2); // Menggabungkan str2 ke str1
    printf("\nKondisi string setelah strcat\n");
    printf("String 1:\t%s\n", str1);
    printf("String 2:\t%s\n", str2);
    printf("String 3:\t%s\n", str3);

    // strcmp untuk membandingkan dua strng berdasarkan tabel ASCII
    int cmp = strcmp(str2, str3);

    if (cmp == 0) { // Mengembalikan nilai 0 jika str2 = str3
        printf("\nString sama\n");
    } else if (cmp < 0) { // Mengembalikan nilai negatif jika str2 < str3
        printf("\nString 2 lebih kecil daripada String 3\n");
    } else { // Mengembalikan nilai positif jika str2 > str3
        printf("\nString 2 lebih besar daripada String 3\n");
    }

    return 0;
}
```
Output:
```plaintext
Kondisi awal string
String 1:       Konsep Pengawuran
String 2:       Konsep Pemograman
String 3:       kosong

Kondisi string setelah strcpy
String 1:       Konsep Pengawuran
String 2:       Konsep Pemograman
String 3:       Konsep Pengawuran

Kondisi string setelah strcat
String 1:       Konsep Pengawuran Konsep Pemograman        
String 2:       Konsep Pemograman
String 3:       Konsep Pengawuran

String 2 lebih kecil daripada String 3
```
