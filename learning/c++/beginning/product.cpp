#include <iostream>
using namespace std;

class product
{
    int id;
    string name;
    string category;
    float price;
    int stock;

public:
    product(int prod_id, string prod_name, string prod_category, float prod_price, int prod_stock)
    {
        id = prod_id;
        name = prod_name;
        category = prod_category;
        price = prod_price;
        stock = prod_stock;
    }

    void display_info()
    {
        cout << "Product ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stock << " units" << endl;
    }

    void add_to_stock(int quantity)
    {
        if (quantity >= 0)
        {
            stock += quantity;
            cout << "Stock updated. New stock: " << stock << " units." << endl;
        }
        else
        {
            cout << "Invalid quantity. Please enter a non-negative value." << endl;
        }
    }

    void change_price(float new_price)
    {
        if (new_price >= 0)
        {
            price = new_price;
            cout << "Price updated. New price: $" << price << endl;
        }
        else
        {
            cout << "Invalid price. Please enter a non-negative value." << endl;
        }
    }


};


int main()
{
    product prod1(101, "Laptop", "Electronics", 1000, 50);
    prod1.display_info();
    prod1.add_to_stock(20);
    prod1.change_price(2000);
    prod1.display_info();
    return 0;
}