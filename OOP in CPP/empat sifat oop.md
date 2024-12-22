### **Empat Konsep Utama dalam OOP**:

### **1. Encapsulation (Enkapsulasi)**
Enkapsulasi adalah proses menyembunyikan detail implementasi internal dari pengguna dan hanya menyediakan antarmuka untuk berinteraksi dengan objek. Data dan metode yang bekerja dengan data tersebut digabungkan dalam satu kesatuan yang disebut **kelas**.

#### **Contoh Enkapsulasi**:
Di C++, kita menggunakan **access modifiers** (`public`, `private`, `protected`) untuk mengatur akses ke data anggota kelas.

```cpp
#include <iostream>
using namespace std;

class Person {
private:
    string name;  
    int age;     
    
public:
    // Setter method (Public)
    void setName(string n) {
        name = n;
    }
    
    void setAge(int a) {
        age = a;
    }
    
    // Getter method (Public)
    void displayInfo() {
        cout << "Nama: " << name << ", Umur: " << age << endl;
    }
};

int main() {
    Person p1;
    p1.setName("Alice");  // Akses setter untuk mengatur nama
    p1.setAge(25);        // Akses setter untuk mengatur umur
    p1.displayInfo();     // Akses method untuk menampilkan informasi
    
    return 0;
}
```

**Penjelasan:**
- **Private members** (`name` dan `age`) hanya bisa diakses melalui **public methods** (misalnya `setName`, `setAge`, dan `displayInfo`).
- Jadi ini kalau mau akses name dan age pakai fungsi yang ada di public.
- Hal ini menyembunyikan implementasi internal dan hanya mengizinkan akses terbatas melalui antarmuka publik.

---

### **2. Abstraction (Abstraksi)**
Abstraksi adalah konsep menyembunyikan detail implementasi dan hanya menunjukkan fungsionalitas kepada pengguna. Ini membantu menyederhanakan kompleksitas dengan memberikan antarmuka yang jelas.

#### **Contoh Abstraksi**:
Di C++, abstraksi sering dicapai menggunakan **kelas abstrak** dan **pure virtual functions**.

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function, kelas ini abstrak
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Menggambar Lingkaran" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Menggambar Persegi" << endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();
    
    shape1->draw();  // Menggambar Lingkaran
    shape2->draw();  // Menggambar Persegi
    
    delete shape1;
    delete shape2;
    
    return 0;
}
```

**Penjelasan:**
- **`Shape`** adalah kelas abstrak karena memiliki fungsi virtual murni (`draw()`), yang HARUS diimplementasikan oleh kelas turunan.
- **`Circle`** dan **`Square`** mengimplementasikan metode `draw()` mereka sendiri, menunjukkan cara konkret menggambar.

---

### **3. Inheritance (Pewarisan)**
Pewarisan adalah mekanisme yang memungkinkan sebuah kelas untuk mewarisi properti dan perilaku (data dan metode) dari kelas lain. Hal ini memungkinkan **reusability** (penggunaan kembali) kode dan membuat hierarki kelas.

Simpelnya, turunannya bisa pakai fungsi yang ada di kelas induk

#### **Contoh Pewarisan**:
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Hewan sedang makan." << endl;
    }
};

class Dog : public Animal {  // Dog mewarisi dari Animal
public:
    void bark() {
        cout << "Anjing menggonggong." << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();  // Memanggil metode dari kelas induk (Animal)
    dog.bark(); // Memanggil metode dari kelas turunan (Dog)
    
    return 0;
}
```

**Penjelasan:**
- **Kelas `Dog`** mewarisi metode `eat()` dari kelas induk `Animal`, dan dapat menambahkan metode khusus seperti `bark()`.
- Dengan pewarisan, kita dapat menggunakan kembali kode yang sudah ada (seperti `eat()`), sehingga menghindari pengulangan kode.

---

### **4. Polymorphism (Polimorfisme)**
Polimorfisme memungkinkan satu interface (antarmuka) digunakan untuk berbagai tipe objek. Ada dua jenis polimorfisme di C++: **polimorfisme statis (overloading)** dan **polimorfisme dinamis (overriding)**.

#### **Polimorfisme Dinamis (Overriding)**:
Polimorfisme dinamis terjadi ketika fungsi yang sama di dalam kelas induk di-override oleh kelas turunan.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {  // Fungsi virtual
        cout << "Hewan berbunyi!" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {  // Override fungsi dari kelas induk
        cout << "Anjing menggonggong!" << endl;
    }
};

int main() {
    Animal* animal = new Dog();  // Pointer ke kelas induk, objek kelas turunan
    animal->sound();  // Memanggil metode yang di-override
    delete animal;
    
    return 0;
}
```

**Penjelasan:**
-** override dipakai buat nurunin fungsi dari kelas induk, tapi kelas induknya diberi virtual duluu
-** ini nnati fungsinya ke change sama fungsi di kelas turunan, tergantung juga sih
- **`sound()`** adalah fungsi virtual yang di-override oleh kelas turunan `Dog`.
- Ketika pointer `animal` yang bertipe `Animal*` menunjuk ke objek `Dog`, yang dipanggil adalah metode `sound()` dari kelas `Dog`, meskipun tipe variabelnya adalah `Animal*`.
- **Polimorfisme** memungkinkan kita untuk menggunakan metode yang sama (`sound()`), tetapi implementasi yang berbeda tergantung pada tipe objek yang digunakan.

---
