#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Node
{
    int value;
    struct Node* nextNode;
} Node;

typedef Node* NodePtr;

NodePtr start = NULL;
NodePtr temp;
NodePtr last;

// ==============================================================

void clear();
void insert();
void delete();
void check(NodePtr *start, NodePtr *last);
void endProgram();
void mainMenu();
void insertLast(NodePtr *start, NodePtr *last, int value);
void insertStart(NodePtr *start, NodePtr *last, int value);
void insertAfter(NodePtr *start, NodePtr *last, int value);
void deleteLast(NodePtr *start, NodePtr *last);
void deleteStart(NodePtr *start, NodePtr *last);
void deleteAfter(NodePtr *start, NodePtr *last);
void deleteAt(NodePtr *start, NodePtr *last);
void printList();
void pause();

// MAIN ============================================================
int main() {
    clear();

    mainMenu();

    return 0;
}

// =========================================================

void clear() {
    system("CLS");
}

void pause() {
    printf("\nTekan Enter untuk kembali ke menu utama...");
    getchar();
    getchar();
}

void mainMenu() {
    int choice;

    do {
        clear();
        printf("Apa yang ingin dilakukan?\n");
        printf("1. Menambah data\n");
        printf("2. Menghapus data\n");
        printf("3. Mengecek data\n");
        printf("4. Cetak linked list\n");
        printf("5. Keluar program\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            check(&start, &last);
            break;
        case 4:
            printList();
            break;
        default:
            return;
        }

        pause();
    } while (choice != 5);
}

// =================================================================

void insert() {
    clear();
    int choice;
    int value;

    printf("Apa yang ingin dilakukan?\n");
    printf("1. Menambah data di belakang\n");
    printf("2. Menambah data di depan\n");
    printf("3. Menambah data setelah\n");
    printf(" >> ");
    scanf("%d", &choice);

    printf("Data yang ingin ditambah\t");
    scanf("%d", &value);

    switch (choice) {
    case 1:
        insertLast(&start, &last, value);
        break;
    case 2:
        insertStart(&start, &last, value);
        break;
    case 3:
        insertAfter(&start, &last, value);
        break;
    default:
        return;
    }
}

void insertLast(NodePtr *start, NodePtr *last, int value) {
    NodePtr newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->nextNode = NULL;

    if (*start == NULL) {
        *start = newNode;
        *last = *start;
    }
    else {
        (*last)->nextNode = newNode;
        *last = newNode;
    }
}

void insertStart(NodePtr *start, NodePtr *last, int value) {
    NodePtr newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->nextNode = NULL;

    if (*start == NULL) {
        *start = newNode;
        *last = *start;
    }
    else {
        newNode->nextNode = *start;
        *start = newNode;
    }
}

void insertAfter(NodePtr *start, NodePtr *last, int value) {
    int after;
    printf("Data akan dimasukan setelah data apa?\t");
    scanf("%d", &after);

    NodePtr newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->nextNode = NULL;

    if (*start == NULL) {
        printf("Linked list kosong\n");
        free(newNode);
        return;
    }

    temp = *start;
    while (temp != NULL && temp->value != after) {
        temp = temp->nextNode;
    }

    if (temp == NULL) {
        printf("Data yang dimaksud tidak ditemukan\n");
        free(newNode);
        return;
    }

    newNode->nextNode = temp->nextNode;
    temp->nextNode = newNode;

    if (temp == *last) {
        *last = newNode;
    }
}

// ======================================================================

void delete() {
    clear();
    int choice;

    printf("Apa yang ingin dilakukan?\n");
    printf("1. Menghapus data di belakang\n");
    printf("2. Menghapus data di depan\n");
    printf("3. Menghapus data setelah\n");
    printf("4. Menghapus data apa\n");
    printf(" >> ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        deleteLast(&start, &last);
        break;
    case 2:
        deleteStart(&start, &last);
        break;
    case 3:
        deleteAfter(&start, &last);
        break;
    case 4:
        deleteAt(&start, &last);
        break;
    default:
        return;
    }
}

void deleteLast(NodePtr *start, NodePtr *last) {
    if (*start == NULL) {
        printf("Linked list kosong\n");
        return;
    }

    if ((*start)->nextNode == NULL) {
        free(*start);
        *start = NULL;
        *last = NULL;
        return;
    }

    temp = *start;
    while (temp->nextNode != *last) {
        temp = temp->nextNode;
    }

    *last = temp;
    (*last)->nextNode = NULL;
    free(temp->nextNode);
}

void deleteStart(NodePtr *start, NodePtr *last) {
    if (*start == NULL) {
        printf("Linked list kosong\n");
        return;
    }

    if ((*start)->nextNode == NULL) {
        free(*start);
        *start = NULL;
        *last = NULL;
        return;
    }

    temp = *start;
    *start = (*start)->nextNode;
    free(temp);
}

void deleteAfter(NodePtr *start, NodePtr *last) {
    if (*start == NULL) {
        printf("Linked list kosong\n");
        return;
    }

    int after;
    printf("Data yang dihapus setelah apa?\t");
    scanf("%d", &after);

    temp = *start;
    while (temp != NULL && temp->value != after) {
        temp = temp->nextNode;
    }

    if (temp == NULL || temp->nextNode == NULL) {
        printf("Tidak ada data yang bisa dihapus / data yang diminta tidak sesuai\n");
        return;
    }

    NodePtr p = temp->nextNode;
    temp->nextNode = p->nextNode;
    
    if (p == *last) {
        *last = temp;
    }

    free(p);
}

void deleteAt(NodePtr *start, NodePtr *last) {
    if (*start == NULL) {
        printf("Linked list kosong\n");
        return;
    }

    int value;
    printf("Data yang ingin dihapus?\t");
    scanf("%d", &value);

    if ((*start)->value == value) {
        deleteStart(start, last);
        return;
    }

    temp = *start;
    while (temp->nextNode != NULL && temp->nextNode->value != value) {
        temp = temp->nextNode;
    }

    if (temp->nextNode == NULL) {
        printf("Data yang dimaksud tidak ditemukan\n");
        return;
    }

    NodePtr p = temp->nextNode;
    temp->nextNode = p->nextNode;

    if (p == *last) {
        *last = temp;
    }

    free(p);
}

// =======================================================================

void check(NodePtr *start, NodePtr *last) {
    if (*start == NULL) {
        printf("Linked list kosong\n");
        return;
    }

    int value;
    printf("Data yang ingin dicari?\t");
    scanf("%d", &value);

    temp = *start;
    while (temp != NULL && temp->value != value) {
        temp = temp->nextNode;
    }

    if (temp == NULL) {
        printf("%d tidak terdapat dalam linked list\n", value);
    } else {
        printf("%d ditemukan dalam linked list\n", value);
    }
}

void printList() {
    if (start == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    NodePtr current = start;
    printf("Isi linked list:\n");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->nextNode;
    }
    printf("NULL\n");
}
