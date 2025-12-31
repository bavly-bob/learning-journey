#include "header.h"
#include <iostream>
using namespace std;

book::book()
    : title(""), author(""), pages(0), price_per_page(0.0) {}

book::book(string t, string a, int p, float pp)
    : title(t), author(a), pages(p), price_per_page(pp) {}

float book::getTotalCost() 
{
    return pages * price_per_page;
}

void book::displayInfo() 
{
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Pages: " << pages << endl;
    cout << "Price per Page: " << price_per_page << endl;
    cout << "Total Cost: " << getTotalCost() << endl;
}

void book::change_price_per_page(float new_price) 
{
    price_per_page = new_price;
}

float book::get_price_per_page()  
{
    return price_per_page;
}


void quest_1() {
    book b1;
    book b2("Title 1","Author1",300,2);
    b1.displayInfo();
    b2.displayInfo();
    cout << b2.getTotalCost();
}
