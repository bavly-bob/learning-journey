/*
supermarket.cpp
A C++ program to manage an e-commerce supermarket system with
product database, shopping cart, e-wallet, and user management
using static arrays for data storage.
this project was by me and 3 of my friends in AUC
This is an older version before we switched to the vectors version.
*/ 

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct product
{
    int id;
    string name;
    int quantity;
    int price;
};

class ProductDB
{
private:
    product products[100];
    int length = 0;

public:
    void loadProducts(string path)
    {
        length = 0;
        ifstream file;
        file.open(path);

        if(!file.is_open())
        {
            cout << "Error: Could not open " << path << endl;
            cout << "Make sure" << path << " exists in the same folder as your program.\n";
            return;
        }
        
        product p;
        while(file >> p.id >> p.name >> p.quantity >> p.price)
        {
            products[length++] = p;
        }
        
        file.close();
        cout << "Loaded " << length << " products from file.\n";
    }
    
    void saveProducts(string path)
    {
        ofstream file;
        file.open(path);
        
        for(int i = 0; i < length; i++)
        {
            file << products[i].id << " "
                 << products[i].name << " "
                 << products[i].quantity << " "
                 << products[i].price;
            
            if(i != length - 1) file << "\n";
        }
        
        file.close();
    }

    void addProduct(product p)
    {
        products[length++] = p;
    }

    void displayProducts()
    {
        cout << "\n==== PRODUCT LIST ====\n";
        for (int i = 0; i < length; i++)
        {
            cout << "ID: " << products[i].id
                 << " | " << products[i].name
                 << " | Qty: " << products[i].quantity
                 << " | Price: " << products[i].price << endl;
        }
    }

    bool updateQuantity(int id, int newQty)
    {
        for (int i = 0; i < length; i++)
        {
            if (products[i].id == id)
            {
                products[i].quantity = newQty;
                return true;
            }
        }
        return false;
    }

    bool updatePrice(int id, int newPrice)
    {
        for (int i = 0; i < length; i++)
        {
            if (products[i].id == id)
            {
                products[i].price = newPrice;
                return true;
            }
        }
        return false;
    }

    int getQuantity(int id)
    {
        for (int i = 0; i < length; i++)
        {
            if (products[i].id == id)
                return products[i].quantity;
        }
        return -1;
    }

    int getPrice(int id)
    {
        for (int i = 0; i < length; i++)
        {
            if (products[i].id == id)
                return products[i].price;
        }
        return -1;
    }
};

struct cart
{
    int length = 0;
    int products[100] = {0};
};

class cartDB /*Maya*/
{
    public:
    cart();
    
    void display() ;
    int calculateTotal(ProductDB& db) ;
};

struct eWallet
{
    int balance;
    string card_number;
};

class eWalletDB /*Zeina*/
{
    public:
    eWallet(int bal = 0 , string card = "");

    void deposit(int amount);
    bool withdraw(int amount);

    void setCardNumber(string card);

};

struct user
{
    int totalSpending;
    string username;
    string password;
    cart cart;
    eWallet wallet;
    int privilege; // 0: customer | 1: special customer | 2: admin
};

class userDB
{
    private:
    int length;
    user userArr[100];

    public:
    void loadUsers(string path){
        length = 0;
        ifstream file;
    
        string username;
        string password;
        int product_ID;
        int cart_length;
        int privilege;
        int balance;
        int totalSpending;
        string card_number;
    
    
        file.open(path);
        if(!file.is_open())
        {
            cout << "Error: Could not open " << path << endl;
            cout << "Make sure " << path  << " exists in the same folder as your program.\n";
            return;
        }

        while(file >> username >> password >> privilege >> totalSpending >> cart_length)
        {
            cart c;
            c.length = cart_length;

            for(int j = 0; j < cart_length; j++)
            {
                file >> product_ID;
                c.products[j] = product_ID;
            }

            file >> card_number;
            file >> balance;

            eWallet w = {balance, card_number};

            userArr[length] = user { totalSpending, username, password, c, w, privilege };
            
            length++;
        }

    
        file.close();
        cout << "Loaded " << length << " users from file.\n";
    }
    
    void saveUsers(string path)
    {
        ofstream file;
        string output;
        file.open(path);
        for(int i = 0; i < length; i++)
        {
            output = userArr[i].username + " " + 
                     userArr[i].password + " " + 
                     to_string(userArr[i].privilege) + " " + 
                     to_string(userArr[i].totalSpending) + " " + 
                     to_string(userArr[i].cart.length) + " ";
            
            for(int j = 0; j < userArr[i].cart.length; j++)
            {
                output += to_string(userArr[i].cart.products[j]) + " ";
            }
            output += userArr[i].wallet.card_number + " " + to_string(userArr[i].wallet.balance);

            if(i != length - 1) file << output << "\n";
            else file << output;
        }
        file.close();
    }
    
    void displayUsers()
    {
        for(int i = 0; i < length; i++)
        {
            cout << "Name: " << userArr[i].username << " | ";
            switch (userArr[i].privilege)
            {
            case 0:
                cout << "Customer";
                break;
            case 1:
                cout << "Special customer";
                break;
            case 2: 
                cout << "Admin";
                break;
            }

            cout << endl;
        }
    }

    void addUser(user newUser)
    {
        userArr[length] = newUser;
        length++;
    }

    bool isUnique(string username)
    {
        for(int i = 0; i<length; i++)
        {
            if(username == userArr[i].username) return false;
        }
        return true;
    }

    int GetLength()
    {
        return length;
    }

    bool LogIn(string username, string password, user &loggedInUser)
    {
        for(int i = 0; i<length; i++)
        {
            if(userArr[i].username == username && userArr[i].password == password)
            {
                loggedInUser = userArr[i];
                cout << "======================================" << endl;
                cout << "Logged in as " << loggedInUser.username << "!" << endl;
                cout << "======================================" << endl;
                return true;
            }
        }

        cout << "Wrong username or password" << endl;
        return false;
    }

    void updateUser(user &updatedUser)
    {
        for(int i = 0; i < length; i++)
        {
            if(userArr[i].username == updatedUser.username)
            {
                userArr[i] = updatedUser;
                return;
            }
        }
    }
};

void customerMenu(user &currentUser, ProductDB &pdb, userDB &database)
{
    int choice;

    while (true)
    {
        cout << "\n===== CUSTOMER MENU =====\n";
        cout << "1. View Products\n";
        cout << "2. Buy Product\n";
        cout << "3. View Cart\n";
        cout << "4. Return Product\n";
        cout << "5. Checkout\n";
        cout << "6. View Purchase History\n";
        cout << "7. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            pdb.displayProducts();
        }

        else if (choice == 2)
        {
            int id;
            cout << "Enter product ID to buy: ";
            cin >> id;

            int qty = pdb.getQuantity(id);
            if (qty <= 0)
            {
                cout << "Product OUT OF STOCK!\n";
            }
            else
            {
                // Add to cart
                currentUser.cart.products[currentUser.cart.length++] = id;
                // Reduce stock
                pdb.updateQuantity(id, qty - 1);

                cout << "Product added to cart!\n";
            }
        }

        else if (choice == 3)
        {
            cout << "\n===== CART =====\n";
            if (currentUser.cart.length == 0)
            {
                cout << "Your cart is empty.\n";
            }
            else
            {
                for (int i = 0; i < currentUser.cart.length; i++)
                    cout << "- Product ID: " << currentUser.cart.products[i] << endl;
            }
        }

        else if (choice == 4)
        {
            if (currentUser.cart.length == 0)
            {
                cout << "No items to return.\n";
                continue;
            }

            int id;
            cout << "Enter product ID to return: ";
            cin >> id;

            bool found = false;

            // Search item in cart
            for (int i = 0; i < currentUser.cart.length; i++)
            {
                if (currentUser.cart.products[i] == id)
                {
                    found = true;

                    // Remove the item from cart by shifting
                    for (int j = i; j < currentUser.cart.length - 1; j++)
                        currentUser.cart.products[j] = currentUser.cart.products[j + 1];

                    currentUser.cart.length--;

                    // Increase quantity in stock
                    int qty = pdb.getQuantity(id);
                    pdb.updateQuantity(id, qty + 1);

                    cout << "Product returned successfully!\n";
                    break;
                }
            }

            if (!found)
                cout << "That product is not in your cart.\n";
        }

        else if (choice == 5)
        {
            if (currentUser.cart.length == 0)
            {
                cout << "Your cart is empty. Nothing to checkout.\n";
                continue;
            }

            int totalPrice = 0;
            cout << "\n===== CHECKOUT =====\n";
            cout << "Items in your cart:\n";
            for (int i = 0; i < currentUser.cart.length; i++)
            {
                int productId = currentUser.cart.products[i];
                int price = pdb.getPrice(productId);
                totalPrice += price;
                cout << "- Product ID: " << productId << " | Price: " << price << endl;
            }
            
            cout << "\nTotal Amount: " << totalPrice << endl;
            cout << "Your Wallet Balance: " << currentUser.wallet.balance << endl;

            if (currentUser.wallet.balance >= totalPrice)
            {
                currentUser.wallet.balance -= totalPrice;
                currentUser.totalSpending += totalPrice;
                currentUser.cart.length = 0; // Clear cart
                
                database.updateUser(currentUser);
                
                cout << "\n*** PURCHASE SUCCESSFUL! ***\n";
                cout << "Remaining Balance: " << currentUser.wallet.balance << endl;
                cout << "Thank you for your purchase!\n";
            }
            else
            {
                cout << "\n*** INSUFFICIENT BALANCE! ***\n";
                cout << "You need " << (totalPrice - currentUser.wallet.balance) << " more.\n";
            }
        }

        else if (choice == 6)
        {
            cout << "\n===== PURCHASE HISTORY =====\n";
            cout << "Total Spending: " << currentUser.totalSpending << endl;
        }

        else if (choice == 7)
        {
            database.updateUser(currentUser);
            cout << "Logging out...\n";
            break;
        }

        else cout << "Invalid option.\n";
    }
}

void adminMenu(ProductDB &pdb)
{
    int choice;

    while (true)
    {
        cout << "\n===== ADMIN MENU =====\n";
        cout << "1. Add Product\n";
        cout << "2. Modify Product Quantity\n";
        cout << "3. Modify Product Price\n";
        cout << "4. View All Products\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            product p;
            cout << "Enter Product ID: ";
            cin >> p.id;
            cout << "Enter Product Name: ";
            cin >> p.name;
            cout << "Enter Quantity: ";
            cin >> p.quantity;
            cout << "Enter Price: ";
            cin >> p.price;

            pdb.addProduct(p);
            cout << "Product added!\n";
        }
        else if (choice == 2)
        {
            int id, qty;
            cout << "Enter Product ID to update: ";
            cin >> id;
            cout << "Enter new quantity: ";
            cin >> qty;

            if (pdb.updateQuantity(id, qty))
                cout << "Quantity updated!\n";
            else
                cout << "Product not found.\n";
        }
        else if (choice == 3)
        {
            int id, price;
            cout << "Enter Product ID to update: ";
            cin >> id;
            cout << "Enter new price: ";
            cin >> price;

            if (pdb.updatePrice(id, price))
                cout << "Price updated!\n";
            else
                cout << "Product not found.\n";
        }
        else if (choice == 4)
        {
            pdb.displayProducts();
        }
        else if (choice == 5)
        {
            cout << "Logging out...\n";
            break;
        }
        else cout << "Invalid option.\n";
    }
}

int main()
{
    user currentUser;
    userDB database;
    ProductDB pdb;
    
    // Load products from TXT file
    pdb.loadProducts("C:\\Users\\baboa\\OneDrive - aucegypt.edu\\Desktop\\code\\products.txt");
    database.loadUsers("C:\\Users\\baboa\\OneDrive - aucegypt.edu\\Desktop\\code\\UserDB.txt");
    database.displayUsers();

    string name;
    string phone;
    string location;
    string username;
    string password;
    string card_number;

    char inputControls;
    cout << "Do you have an account? (y/n): ";
    cin >> inputControls;
    cout << endl;

    if(inputControls == 'y')
    {
        do
        {
            cout << "Enter username and password: ";
            cin >> username >> password;
        } 
        while(!database.LogIn(username, password, currentUser));
    }

    else if(inputControls == 'n')
    {
        cout << "Creating a new account ..." << endl;

        cout << "Enter your name (no spaces): ";
        cin >> name;

        do
        {
            cout << "Create a unique username (no spaces): ";
            cin >> username;

        } 
        while (!database.isUnique(username));

        cout << "Create a password: ";
        cin >> password;

        cout << "Enter your phone number: ";
        cin >> phone;

        cout << "Enter your location: ";
        cin >> location;

        cout << "Enter credit/debit card number: ";
        cin >> card_number;

        
        database.addUser({0, username, password, {0}, {0, card_number}, 0});
        database.LogIn(username, password, currentUser);

        cout << "========================\n";
        cout << "Welcome, " << name << "!\n";
        cout << "========================\n";
    }

    // Route to appropriate menu based on privilege
    if(currentUser.privilege == 2)
    {
        adminMenu(pdb);
    }
    else
    {
        customerMenu(currentUser, pdb, database);
    }

    // Save products and users
    pdb.saveProducts("C:\\Users\\baboa\\OneDrive - aucegypt.edu\\Desktop\\code\\products.txt");
    database.saveUsers("C:\\Users\\baboa\\OneDrive - aucegypt.edu\\Desktop\\code\\UserDB.txt");

    return 0;
}