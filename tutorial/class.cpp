#include <iostream>
using namespace std;

class Book{
private:
    string title;
    string author;
    int pages;
public:
    Book(){
        title = "no title";
        author = "no author";
        pages = 0;
    }
    Book(string t, string a, int p){
        title = t;
        author = a;
        pages = p;
    }

    void intro(){
        cout << "****************BOOK INTRODUCTION******************" << endl;
        cout << " Book Title: " << title << endl;
        cout << "     Author: " << author << endl;
        cout << "      pages: " << pages << endl;
        cout << "***************************************************" << endl;
    }
};

int main(){
    Book book1 = Book("Harry Potter", "JK Rowling", 500);
    Book book2 = Book("Lord of the Rings", "Tolkein", 700);
    book1.intro();
    book2.intro();

    return 0;
}
