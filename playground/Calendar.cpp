#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class Calendar {
private:
    vector<string> months = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = 0;
    int day_num = 365;
    int start = 0;

    void printHeader(int month) {
        cout << "\n" << string(10, ' ') << months[month] << " " << year << "\n";
        cout << "-----------------------------\n";
        cout << " Sun Mon Tue Wed Thu Fri Sat\n";
    }
    void printBlank(int start) {
        for (int i = 0; i < start; i++) {
            cout << string(4, ' ');
        }
    }
    int start_day(int year) {
        int day = 6;
        for (int i = 0; i < year; i++) {
            day = ((day + (isLunar(i) ? 366 : 365) % 7) % 7);
        }
        return day;
    }

    static bool isLunar(int year) {
        if (year % 4 != 0) 
            return false;
        else if (year % 100 != 0)
            return true;
        else if (year % 400 != 0)
            return false;
        return true;
    }
public:
    Calendar(int year) 
        : year(year) {
        if (isLunar(year)) {
            days[1] = 29;
            day_num = 366;
        }
        start = start_day(year);
    }

    void print() {
        int s = start;
        for (int i = 0; i < 12; i++) {
            printHeader(i);
            printBlank(s);
            for (int d = 0; d < days[i]; d++) {
                printf("%4d", d+1);
                s = (s + 1) % 7;
                if (s == 0) cout << "\n";
            }
        }
    }
};

int main(){

    while (true) {
        cout << "Enter a year: ";
        string str;
        int year;
        while (cin >> str) {
            string tmp = str.substr(0, 1);
            if (tmp == "q" || tmp == "Q") break;
            year = stoi(str);

            if (year < 0 || year > 9999) {
                cout << "Input out of range. (Please enter a year between 0 to 9999.)";
                break;
            }

            Calendar calendar(year);
            calendar.print();
        }
    }
    return 0;
}
