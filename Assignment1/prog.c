#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 8 

typedef struct {
    char storage[BUFFER_SIZE];
    int head_ptr;   
    int tail_ptr;  
    int total_items;
} MyCircularQueue;

// تهيئة المخزن
void prepareQueue(MyCircularQueue* q) {
    q->head_ptr = 0;
    q->tail_ptr = 0;
    q->total_items = 0;
}

// دالة الإضافة مع رسالة
void addItem(MyCircularQueue* q, char character) {
    if (q->total_items >= BUFFER_SIZE) {
        printf("! Overflow: Cannot add '%c' (Buffer is Full)\n", character);
        return;
    }
    q->storage[q->head_ptr] = character;
    // تحريك المؤشر بشكل دائرى
    q->head_ptr = (q->head_ptr + 1) % BUFFER_SIZE;
    q->total_items += 1;
}

// دالة الازالة
char removeItem(MyCircularQueue* q) {
    if (q->total_items <= 0) {
        printf("! Underflow: Buffer is empty\n");
        return '\0';
    }
    char data = q->storage[q->tail_ptr];
    q->tail_ptr = (q->tail_ptr + 1) % BUFFER_SIZE;
    q->total_items -= 1;
    return data;
}

int main() {
    MyCircularQueue q;
    prepareQueue(&q);

    char fullName[50];
    printf("Please enter your name: ");
    //  لقراءة الاسم الأول
    scanf("%s", fullName);

    // دمج اللاحقة المطلوبة في الواجب
    strcat(fullName, "CE-ESY");
    printf(">> Full String to process: %s\n\n", fullName);

    // حلقة تكرار التخزين
    for (int i = 0; i < strlen(fullName); i++) {
        addItem(&q, fullName[i]);
    }

    printf("\n--- Reading from Buffer ---\n");
    while (q.total_items > 0) {
        printf("%c", removeItem(&q));
    }

    printf("\n\nProcess complete. Queue status: Empty.\n");

    return 0;
}