#include <iostream>
#include <iomanip>

using namespace std;

bool isLeapYear(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    return year % 400 == 0;
}


int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

// алгоритм зеллера
int getFirstDayOfMonth(int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int K = year % 100;
    int J = year / 100;

    int h = (1 + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    int dayOfWeek = (h + 5) % 7;

    return dayOfWeek;
}

void printCalendar(int year) {
    string months[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    string days[] = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};

    for (int month = 1; month <= 12; ++month) {
        cout << "--------------------" << months[month - 1] << " " << year << "--------------------\n";

        for (int dayWeek = 0; dayWeek < 7; ++dayWeek) {
            cout << setw(1) << " " << days[dayWeek] << "\t";
        }
        cout << endl;

        int firstDay = getFirstDayOfMonth(month, year);
        int daysInMonth = getDaysInMonth(month, year);

        for (int tab = 0; tab < firstDay; ++tab) {
            cout << setw(3) << "\t";
        }

        for (int day = 1; day <= daysInMonth; ++day) {
            cout << setw(3) << day << "\t";
            if ((day + firstDay) % 7 == 0 || day == daysInMonth) {
                cout << endl;
            }
        }
        cout << endl;
    }
}

int main() {
    int year;
    cout << "Введите год: ";
    cin >> year;
    printCalendar(year);
}
