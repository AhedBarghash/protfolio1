#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// الخطوة 1: تعريف الحجم
#define SIZE 10

// الخطوة 2: تعريف هيكل المخزن الدائري
typedef struct {
    char buffer[SIZE];
    int head;   
    int tail;   
    int count;  
} CircularBuffer;

// دالة التهيئة
void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// التحقق من الامتلاء
bool isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

// التحقق من الفراغ
bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

// دالة الكتابة
void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\n[!] Buffer Overflow: %c", data);
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

// دالة القراءة
char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        return '\0';
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;
    return data;
}

// الدالة الرئيسية
int main() {
    CircularBuffer cb;
    init(&cb);

    char name[100];
    char suffix[] = "CE-ESY";

    printf("أدخل اسمك: ");
    scanf("%s", name);

    strcat(name, suffix);
    printf("البيانات للمعالجة: %s\n", name);

    printf("\n--- جاري التخزين ---\n");
    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    printf("\n--- جاري القراءة ---\n");
    while (!isEmpty(&cb)) {
        printf("%c", read(&cb));
    }

    printf("\n\nتمت العملية بنجاح.\n");

    return 0;
}