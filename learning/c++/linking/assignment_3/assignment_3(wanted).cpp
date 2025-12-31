#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// ---------------- Quest 1 ----------------
int getlength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

void copystring(char cpy_str[], const char source_str[]) {
    while (*source_str != '\0') {
        *cpy_str = *source_str;
        cpy_str++;
        source_str++;
    }
    *cpy_str = '\0';
}

void concatstring(char combined[], const char s1[], const char s2[]) {
    while (*s1 != '\0') {
        *combined = *s1;
        combined++;
        s1++;
    }
    while (*s2 != '\0') {
        *combined = *s2;
        combined++;
        s2++;
    }
    *combined = '\0';
}

// ---------------- Quest 3 ----------------
int num_words(const char str[]) {
    int count = 0;
    bool inWord = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !inWord) {
            inWord = true;
            count++;
        } else if (str[i] == ' ') {
            inWord = false;
        }
    }
    return count;
}

string replace_blanks_with_underscores(const char str[]) {
    string result;
    for (int i = 0; str[i] != '\0'; i++)
        result += (str[i] == ' ') ? '_' : str[i];
    return result;
}

string remove_punctuation(const char str[]) {
    string result;
    for (int i = 0; str[i] != '\0'; i++)
        result += (!ispunct(str[i])) ? str[i] : ' ';
    return result;
}

void safeInput(char str[], int size, const string &prompt) {
    while (true) {
        cout << prompt;
        cin.getline(str, size);
        if (cin.fail()) {
            cout << "Input too long! Please enter fewer than " << size - 1 << " characters.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } 
        else break;
    }
}

// ---------------- Quest 4 ----------------
struct billionaire {
    string first_name;
    string last_name;
    double net_worth;
    string source_of_wealth;
};

void swap_billionaires(billionaire &a, billionaire &b) {
    billionaire temp = a;
    a = b;
    b = temp;
}

void sort_by_first_name(billionaire arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j].first_name > arr[j + 1].first_name)
                swap_billionaires(arr[j], arr[j + 1]);
}

void sort_by_last_name(billionaire arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j].last_name > arr[j + 1].last_name)
                swap_billionaires(arr[j], arr[j + 1]);
}

void sort_by_net_worth(billionaire arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j].net_worth < arr[j + 1].net_worth)
                swap_billionaires(arr[j], arr[j + 1]);
}

void display_billionaires(const billionaire arr[], int size) {
    cout << "\nList of Billionaires:\n";
    cout << "------------------------------------------------------\n";
    for (int i = 0; i < size; i++)
        cout << i + 1 << ". " << arr[i].first_name << " " << arr[i].last_name
             << " | Net worth: $" << arr[i].net_worth << "B"
             << " | Source: " << arr[i].source_of_wealth << endl;
    cout << "------------------------------------------------------\n";
}

void search_billionaire_by_last_name(const billionaire arr[], int size, const string &last_name) 
{
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].last_name == last_name) {
            cout << "Found: " << arr[i].first_name << " " << arr[i].last_name
                 << " | Net worth: $" << arr[i].net_worth << "B"
                 << " | Source: " << arr[i].source_of_wealth << endl;
            found = true;
        }
    }
    if (!found) cout << "No billionaire found with last name: " << last_name << endl;
}

void search_billionaire_by_net_worth(const billionaire arr[], int size, double net_worth) 
{
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].net_worth == net_worth) {
            cout << "Found: " << arr[i].first_name << " " << arr[i].last_name
                 << " | Net worth: $" << arr[i].net_worth << "B"
                 << " | Source: " << arr[i].source_of_wealth << endl;
            found = true;
        }
    }
    if (!found) cout << "No billionaire found with net worth: $" << net_worth << "B" << endl;
}

void search_billionaire_by_source(const billionaire arr[], int size, const string &source) 
{
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].source_of_wealth == source) {
            cout << "Found: " << arr[i].first_name << " " << arr[i].last_name
                 << " | Net worth: $" << arr[i].net_worth << "B"
                 << " | Source: " << arr[i].source_of_wealth << endl;
            found = true;
        }
    }
    if (!found) cout << "No billionaire found with source of wealth: " << source << endl;
}

void search_by_first_name(const billionaire arr[], int size, const string &first_name) 
{
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].first_name == first_name) {
            cout << "Found: " << arr[i].first_name << " " << arr[i].last_name
                 << " | Net worth: $" << arr[i].net_worth << "B"
                 << " | Source: " << arr[i].source_of_wealth << endl;
            found = true;
        }
    }
    if (!found) cout << "No billionaire found with first name: " << first_name << endl;
}

void search(const billionaire arr[], int size) 
{
    int choice;
    cout << "\nSearch Billionaires by:\n";
    cout << "1. First Name\n";
    cout << "2. Last Name\n";
    cout << "3. Net Worth\n";
    cout << "4. Source of Wealth\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            string first_name;
            cout << "Enter first name: ";
            getline(cin, first_name);
            search_by_first_name(arr, size, first_name);
            break;
        }
        case 2: {
            string last_name;
            cout << "Enter last name: ";
            getline(cin, last_name);
            search_billionaire_by_last_name(arr, size, last_name);
            break;
        }
        case 3: {
            double net_worth;
            cout << "Enter net worth (in billions): ";
            cin >> net_worth;
            search_billionaire_by_net_worth(arr, size, net_worth);
            break;
        }
        case 4: {
            string source;
            cout << "Enter source of wealth: ";
            getline(cin, source);
            search_billionaire_by_source(arr, size, source);
            break;
        }
        default:
            cout << "Invalid choice.\n";
    }
}

// ---------------- Main ----------------
int main() {
    int choice;

    while (choice != 5) {
        cout << "\nassignment 3 test program\n";
        cout << "=========================\n";
        cout << "1. Quest 1 - String functions\n";
        cout << "2. Quest 2 - Repeated string separation\n";
        cout << "3. Quest 3 - Word count / underscore / punctuation\n";
        cout << "4. Quest 4 - Billionaire sorting\n";
        cout << "5. Exit\n";
        cout << "Enter quest number: ";
        cin >> choice;
        cin.ignore();


        switch (choice) {
            case 1: {
                cout << "=== String Length, Copy, and Concatenate ===\n";
                while (true) {
                    cout << "\n-------------------------------------------\n";
                    cout << "1. Calculate String Length\n";
                    cout << "2. Copy String\n";
                    cout << "3. Concatenate Strings\n";
                    cout << "4. Exit Quest 1\n";
                    cout << "-------------------------------------------\n";
                    cout << "Enter your choice (1-4): ";

                    int quest1_choice;
                    cin >> quest1_choice;
                    cin.ignore();

                    if (quest1_choice == 4) break;

                    switch (quest1_choice) {
                        case 1: {
                            char inputString[100];
                            safeInput(inputString, 100, "Enter a string: ");
                            cout << "Length of the string: " << getlength(inputString) << endl;
                            break;
                        }
                        case 2: {
                            char source_str[100], cpy_str[100];
                            safeInput(source_str, 100, "Enter a string to copy: ");
                            copystring(cpy_str, source_str);
                            cout << "Copied string: " << cpy_str << endl;
                            break;
                        }
                        case 3: {
                            char s1[50], s2[50], combined[100];
                            safeInput(s1, 50, "Enter first string: ");
                            safeInput(s2, 50, "Enter second string: ");
                            concatstring(combined, s1, s2);
                            cout << "Concatenated string: " << combined << endl;
                            break;
                        }
                        default:
                            cout << "Invalid choice!\n";
                    }
                }
                break;
            }

            case 2: {
                char input[100];
                safeInput(input, 100, "Enter a string: ");
                cout << "\nSeparated repeated sequences:\n";
                int i = 0;
                while (input[i] != '\0') {
                    cout << input[i];
                    if (input[i] != input[i + 1]) cout << endl;
                    i++;
                }
                break;
            }

            case 3: {
                while (true) {
                    int quest3_choice;
                    cout << "\nChoose an option:\n";
                    cout << "1. Count words\n";
                    cout << "2. Replace blanks with underscores\n";
                    cout << "3. Remove punctuation\n";
                    cout << "4. Exit Quest 3\n";
                    cout << "Enter your choice: ";
                    cin >> quest3_choice;
                    cin.ignore();

                    if (quest3_choice == 4) break;

                    char input[200];
                    safeInput(input, 200, "Enter a string: ");

                    switch (quest3_choice) {
                        case 1:
                            cout << "Word count: " << num_words(input) << endl;
                            break;
                        case 2:
                            cout << "Modified: " << replace_blanks_with_underscores(input) << endl;
                            break;
                        case 3:
                            cout << "Modified: " << remove_punctuation(input) << endl;
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                }
                break;
            }

            case 4: {
                billionaire arr[] = {
                    {"Jeff", "Bezos", 177.0, "Amazon"},
                    {"Elon", "Musk", 151.0, "Tesla, SpaceX"},
                    {"Bernard", "Arnault", 150.0, "LVMH"},
                    {"Bill", "Gates", 124.0, "Microsoft"},
                    {"Mark", "Zuckerberg", 97.0, "Facebook"}};
                int size = 5;
                int menu_choice;

                while (true) {
                    cout << "\n=== Quest 4: Billionaire Records ===\n";
                    cout << "1. Display\n";
                    cout << "2. Sort by FIRST name (A-Z)\n";
                    cout << "3. Sort by LAST name (A-Z)\n";
                    cout << "4. Sort by NET WORTH (High-Low)\n";
                    cout << "5. Search\n";
                    cout << "6. Exit Quest 4\n";
                    cout << "Enter your choice: ";
                    cin >> menu_choice;

                    if (menu_choice == 6) break;

                    switch (menu_choice) {
                        case 1: display_billionaires(arr, size); break;
                        case 2: sort_by_first_name(arr, size); display_billionaires(arr, size); break;
                        case 3: sort_by_last_name(arr, size); display_billionaires(arr, size); break;
                        case 4: sort_by_net_worth(arr, size); display_billionaires(arr, size); break;
                        case 5: search(arr, size); break;
                        default: cout << "Invalid choice.\n";
                    }
                }
                break;
            }

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
