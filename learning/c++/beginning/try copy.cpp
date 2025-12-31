#include <iostream>
using namespace std;
class Product
{
public:
    string name;
    float price;

    Product(string n, float p) : name(n), price(p) {}
    Product() : name(""), price(0.0) {}
};

class Cart
{
private:
    int quantity[20];
    Product contents[20];
    float totalCost;
    int itemCount;

public:
    Cart()
    {
        totalCost = 0;
        itemCount = 0;
    }

    void addProduct(Product p, int q)
    {
        if (itemCount < 20)
        {
            contents[itemCount] = p;
            quantity[itemCount] = q;

            totalCost += p.price * q;
            itemCount++;
        }
        else
        {
            cout << "Cart is full!\n";
        }
    }

    float getTotalCost() {
        return totalCost;
    }

    void display() {
        cout << "Cart Contents:\n";
        if (itemCount == 0) {
            cout << "Cart is empty\n";
        } else {
            for (int i = 0; i < itemCount; i++) {
                cout << contents[i].name
                     << " - Qty: " << quantity[i]
                     << " - Price: " << contents[i].price
                     << " - Subtotal: " << contents[i].price * quantity[i]
                     << endl;
            }
        }
        cout << "Total Cost: " << totalCost << endl;
    }

    void clear() {
        itemCount = 0;
        totalCost = 0;
    }

    bool isValid() {
        return itemCount > 0;
    }
};

int main() {
    Cart cart;
    Product apple("Apple", 0.5);
    Product banana("Banana", 0.3);

    cart.addProduct(apple, 3);
    cart.addProduct(banana, 5);

    cart.display();



    cart.clear();
    cart.display();

    return 0;
}