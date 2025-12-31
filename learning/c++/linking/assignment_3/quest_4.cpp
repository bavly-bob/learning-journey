#include <iostream>
#include <fstream>
#include <sstream> 
#include <vector>
#include <string>
#include "header.h"
using namespace std;



// Function to read billionaires from bil.csv
vector<billionaire> read_billionaires_from_csv(const string &filename)
{
    vector<billionaire> list;
    ifstream file(filename);
    
    if (!file.is_open())
    {
        cout << "Error: could not open file " << filename << endl;
        return list;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        billionaire b;
        string net_worth_str;

        getline(ss, b.first_name, ',');
        getline(ss, b.last_name, ',');
        getline(ss, net_worth_str, ',');
        getline(ss, b.source_of_wealth, ',');

        if (!net_worth_str.empty())
            b.net_worth = stod(net_worth_str); // convert string to double
        else
            b.net_worth = 0;

        list.push_back(b);
    }

    file.close();
    return list;
}

// Function to display billionaires
void display_billionair(const vector<billionaire> &list)
{
    cout << "-----------------------------------------------\n";
    cout << "First Name | Last Name | Net Worth | Source\n";
    cout << "-----------------------------------------------\n";
    for (const auto &b : list)
    {
        cout << b.first_name << " " << b.last_name
             << " | $" << b.net_worth << "B"
             << " | " << b.source_of_wealth << endl;
    }
}

void swap_billionaires(billionaire &a, billionaire &b)
{
    billionaire temp = a;
    a = b;
    b = temp;
}

void sort_billionaires(vector<billionaire> &list, int sort_choice)
{
    int n = list.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            bool shouldSwap = false;

            switch (sort_choice)
            {
                case 1: 
                    if (list[j].first_name > list[j + 1].first_name)
                        shouldSwap = true;
                    break;

                case 2: 
                    if (list[j].last_name > list[j + 1].last_name)
                        shouldSwap = true;
                    break;

                case 3:
                    if (list[j].net_worth < list[j + 1].net_worth)
                        shouldSwap = true;
                    break;

                default:
                    cout << "Invalid choice. Sorting by first name by default.\n";
                    if (list[j].first_name > list[j + 1].first_name)
                        shouldSwap = true;
                    break;
            }

            if (shouldSwap)
                swap_billionaires(list[j], list[j + 1]);
        }
    }
}

void quest_4()
{
    string filename = "bils.csv";
    vector<billionaire> billionaires = read_billionaires_from_csv(filename);

    if (billionaires.empty())
    {
        cout << "No billionaires data found.\n";
        return;
    }

    int sort_choice;
    cout << "Choose sorting criteria:\n";
    cout << "1. First Name\n";
    cout << "2. Last Name\n";
    cout << "3. Net Worth (Descending)\n";
    cout << "Enter your choice (1-3): ";
    cin >> sort_choice;

    sort_billionaires(billionaires, sort_choice);
    display_billionair(billionaires);
}