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
