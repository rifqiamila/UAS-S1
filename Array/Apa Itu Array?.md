### **Apa itu Array?**

**Array** adalah struktur data yang digunakan untuk menyimpan sejumlah elemen dengan tipe data yang sama dalam satu variabel. Elemen-elemen array disimpan secara berurutan di dalam memori, dan setiap elemen dapat diakses menggunakan indeks.

### **Ciri-Ciri Array**
1. **Tipe Data Sama**: Semua elemen dalam array harus memiliki tipe data yang sama, seperti `int`, `float`, atau `char`.
2. **Ukuran Tetap**: Saat array dideklarasikan, ukurannya harus ditentukan, dan ukuran ini tidak dapat diubah selama program berjalan.
3. **Indeks Dimulai dari 0**: Indeks array dimulai dari 0 hingga ukuran array dikurangi 1.
4. **Akses Elemen Cepat**: Array memungkinkan akses langsung ke elemen berdasarkan indeks, sehingga sangat cepat.

---

Array tidak harus bertipe int, bisa juga buat array of character atau string.
Biasanya, kita pakai buat menyimpan kata di C.

---

### **Deklarasi dan Inisialisasi Array**
#### **Deklarasi Array**
Format umum untuk mendeklarasikan array adalah:
```
tipe_data nama_array[ukuran];
```

#### **Contoh dalam C**:
```
int angka[5];  // Array untuk menyimpan 5 bilangan bulat
```

#### **Inisialisasi Array**
Array dapat diinisialisasi saat deklarasi:
```
int angka[5] = {1, 2, 3, 4, 5};
```

Atau elemen dapat ditentukan satu per satu:
```
angka[0] = 1;  // Elemen pertama
angka[1] = 2;  // Elemen kedua
```

---

### **Jenis-Jenis Array**
1. **Array 1 Dimensi (1D)**  
   Digunakan untuk menyimpan data linear atau satu baris, seperti daftar angka.  
   **Contoh:**  
   ```
   int angka[5] = {10, 20, 30, 40, 50};
   ```

2. **Array Multidimensi**  
   Array dengan lebih dari satu dimensi, seperti array 2 dimensi yang menyerupai matriks atau tabel.  
   **Contoh Array 2D:**  
   ```
   int matriks[2][3] = {
       {1, 2, 3},
       {4, 5, 6}
   };
   ```
