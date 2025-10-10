#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура Book (старая версия)
typedef struct {
    char title[50];
    int pages;
    float price;
} Book;

// Структура Book (новая версия с указателем)
typedef struct {
    char* title;
    int pages;
    float price;
} BookPtr;

// Функция для печати старой структуры Book
void print_book(Book b) {
    printf("Title: %s, Pages: %d, Price: %.2f\n", b.title, b.pages, b.price);
}

// Функция для печати новой структуры BookPtr
void print_book_ptr(BookPtr* b) {
    printf("Title: %s, Pages: %d, Price: %.2f\n", b->title, b->pages, b->price);
}

int main() {
    // a
    size_t* num = malloc(sizeof(size_t));
    *num = 100;
    printf("a. Number: %zu\n", *num);
    free(num);

    // b
    char* str = malloc(50 * sizeof(char));
    strcpy(str, "Hello, World!");
    printf("b. String: %s\n", str);
    free(str);

    // c
    char** str_ptr = malloc(sizeof(char*));
    *str_ptr = malloc(50 * sizeof(char));
    strcpy(*str_ptr, "Pointer to string");
    printf("c. String via pointer: %s\n", *str_ptr);
    free(*str_ptr);
    free(str_ptr);

    // d
    Book* book = malloc(sizeof(Book));
    strcpy(book->title, "C Programming");
    book->pages = 300;
    book->price = 29.99;
    printf("d. Book: ");
    print_book(*book);
    free(book);

    // e
    Book stack_book;
    Book* book_ptr = &stack_book;
    printf("e. Pointer to stack book: %p\n", (void*)book_ptr);

    // f
    Book* heap_book = malloc(sizeof(Book));
    printf("f. Pointer to heap book: %p\n", (void*)heap_book);
    free(heap_book);

    // g
    Book* books = malloc(3 * sizeof(Book));
    for (int i = 0; i < 3; i++) {
        snprintf(books[i].title, 50, "Book %d", i+1);
        books[i].pages = 100 + i*50;
        books[i].price = 10.0 + i*5;
    }
    printf("g. Book array:\n");
    for (int i = 0; i < 3; i++) {
        print_book(books[i]);
    }
    free(books);

    // h
    BookPtr* bookp = malloc(sizeof(BookPtr));
    bookp->title = malloc(50 * sizeof(char));
    strcpy(bookp->title, "Dynamic Title");
    bookp->pages = 250;
    bookp->price = 19.99;
    printf("h. Book with dynamic title: ");
    print_book_ptr(bookp);
    free(bookp->title);
    free(bookp);

    return 0;
}
