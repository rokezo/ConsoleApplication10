#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

void printBook(Book book) {
    cout << "Назва: " << book.title << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Видавництво: " << book.publisher << endl;
    cout << "Жанр: " << book.genre << endl;
}

void editBook(Book& book) {
    cout << "Введіть нову назву книги: ";
    cin >> book.title;

    cout << "Введіть нового автора книги: ";
    cin >> book.author;

    cout << "Введіть нове видавництво книги: ";
    cin >> book.publisher;

    cout << "Введіть новий жанр книги: ";
    cin >> book.genre;
}

void printAllBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        printBook(books[i]);
        cout << endl;
    }
}

void searchBookByAuthor(Book books[], int size, string author) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            printBook(books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Книга автора " << author << " не знайдена" << endl;
    }
}

void searchBookByTitle(Book books[], int size, string title) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (books[i].title == title) {
            printBook(books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Книга з назвою " << title << " не знайдена" << endl;
    }
}

void sortBooksByTitle(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (books[i].title > books[j].title) {
                swap(books[i], books[j]);
            }
        }
    }
}

void sortBooksByAuthor(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (books[i].author > books[j].author) {
                swap(books[i], books[j]);
            }
        }
    }
}

void sortBooksByPublisher(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (books[i].publisher > books[j].publisher) {
                swap(books[i], books[j]);
            }
        }
    }
}

int main() {
    Book books[10];

    for (int i = 0; i < 10; i++) {
        cout << "Введіть назву книги " << i + 1 << ": ";
        cin >> books[i].title;

        cout << "Введіть автора книги " << i + 1 << ": ";
        cin >> books[i].author;

        cout << "Введіть видавництво книги " << i + 1 << ": ";
        cin >> books[i].publisher;

        cout << "Введіть жанр книги " << i + 1 << ": ";
        cin >> books[i].genre;
    }

    int choice;
    while (true) {
        cout << "Виберіть дію:" << endl;
        cout << "1. Редагувати книгу" << endl;
        cout << "2. Друк усіх книг" << endl;
        cout << "3. Пошук книг за автором" << endl;
        cout << "4. Пошук книги за назвою" << endl;
        cout << "5. Сортування масиву за назвою книг" << endl;
        cout << "6. Сортування масиву за автором" << endl;
        cout << "7. Сортування масиву за видавництвом" << endl;
        cout << "8. Вихід" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            int index;
            cout << "Введіть номер книги для редагування: ";
            cin >> index;
            editBook(books[index - 1]);
            break;
        }
        case 2:
            printAllBooks(books, 10);
            break;
        case 3: {
            string author;
            cout << "Введіть автора для пошуку: ";
            cin >> author;
            searchBookByAuthor(books, 10, author);
            break;
        }
        case 4: {
            string title;
            cout << "Введіть назву для пошуку: ";
            cin >> title;
            searchBookByTitle(books, 10, title);
            break;
        }
        case 5:
            sortBooksByTitle(books, 10);
            break;
        case 6:
            sortBooksByAuthor(books, 10);
            break;
        case 7:
            sortBooksByPublisher(books, 10);
            break;
        case 8:
            return 0;
        default:
            cout << "Неправильний вибір" << endl;
        }
    }

    return 0;
}