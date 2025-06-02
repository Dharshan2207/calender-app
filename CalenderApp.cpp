#include <bits/stdc++.h>
using namespace std;

class Calendar {
private:
    string daysOfWeek[7] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
    int month = -1, date = -1, year = -1, weekdayIndex = -1;

    int getDayIndex(string day) {
        for (int i = 0; i < 7; i++) {
            if (daysOfWeek[i] == day) return i;
        }
        return -1;
    }

    bool isLeapYear(int year) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    int getDaysInMonth(int month, int year) {
        if (month == 2 && isLeapYear(year)) return 29;
        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};
        return days[month - 1];
    }

    string getMonthName(int month) {
        string names[] = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
        return names[month - 1];
    }

    int getFirstDayIndex(int date, int weekdayIndex) {
        return (weekdayIndex - ((date - 1) % 7) + 7) % 7;
    }

    void printMonth(int month, int year, int firstDayIndex) {
        int totalDays = getDaysInMonth(month, year);
        cout << "\n " << getMonthName(month) << " " << year << "\n";
        for (string day : daysOfWeek) cout << setw(4) << day;
        cout << "\n";

        int dayCount = 0;
        for (int i = 0; i < firstDayIndex; i++) {
            cout << "    ";
            dayCount++;
        }

        for (int date = 1; date <= totalDays; date++) {
            cout << setw(4) << date;
            dayCount++;
            if (dayCount % 7 == 0) cout << "\n";
        }
        cout << "\n";
    }

public:
    void enterOrUpdateDate() {
        cout << "Enter date: ";
        cin >> date;
        cout << "Enter month (1-12): ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
        string weekday;
        cout << "Enter weekday of that date (sun/mon/...): ";
        cin >> weekday;

        weekdayIndex = getDayIndex(weekday);
        if (weekdayIndex == -1) {
            cout << "Invalid weekday entered!\n";
            date = month = year = -1;
        }
    }

    void printCurrentMonth() {
        if (date == -1) {
            cout << "Please enter date first.\n";
            return;
        }
        int firstday = getFirstDayIndex(date, weekdayIndex);
        printMonth(month, year, firstday);
    }

    void printPreviousMonth() {
        if (date == -1) {
            cout << "Please enter date first.\n";
            return;
        }
        int firstdayCurr = getFirstDayIndex(date, weekdayIndex);
        int prevMonth = (month == 1) ? 12 : month - 1;
        int prevYear = (month == 1) ? year - 1 : year;
        int daysInPrev = getDaysInMonth(prevMonth, prevYear);
        int firstdayPrev = (firstdayCurr - (daysInPrev % 7) + 7) % 7;
        printMonth(prevMonth, prevYear, firstdayPrev);
    }

    void printNextMonth() {
        if (date == -1) {
            cout << "Please enter date first.\n";
            return;
        }
        int firstdayCurr = getFirstDayIndex(date, weekdayIndex);
        int nextMonth = (month == 12) ? 1 : month + 1;
        int nextYear = (month == 12) ? year + 1 : year;
        int daysInCurr = getDaysInMonth(month, year);
        int firstdayNext = (firstdayCurr + (daysInCurr % 7)) % 7;
        printMonth(nextMonth, nextYear, firstdayNext);
    }
};

int main() {
    Calendar cal;
    bool stillRunning = true;

    while (stillRunning) {
        cout << "\n--- Calendar Menu ---\n";
        cout << "1. Enter date\n";
        cout << "2. Update date\n";
        cout << "3. Print current month\n";
        cout << "4. Print previous month\n";
        cout << "5. Print next month\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
                cal.enterOrUpdateDate();
                break;
            case 3:
                cal.printCurrentMonth();
                break;
            case 4:
                cal.printPreviousMonth();
                break;
            case 5:
                cal.printNextMonth();
                break;
            case 6:
                stillRunning = false;
                cout << "Exited calender app."
                break;
            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}

