#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int getlength(const char str[]);
void copystring(char cpy_str[], const char source_str[]);
void concatstring(char combined[], const char s1[], const char s2[]);
void safeInput(char str[], int size, const string &prompt);
void quest_1();
void quest_2();
int num_words(const char str[]);
string replace_blanks_with_underscores(const char str[]);
string remove_punctuation(const char str[]);
void quest_3();
struct billionaire
{
    string first_name;
    string last_name;
    double net_worth;
    string source_of_wealth;
};
vector<billionaire> read_billionaires_from_csv(const string &filename);
void display_billionair(const vector<billionaire> &list);
void swap_billionaires(billionaire &a, billionaire &b);
void sort_billionaires(vector<billionaire> &list, int sort_choice);
void quest_4();

#endif
