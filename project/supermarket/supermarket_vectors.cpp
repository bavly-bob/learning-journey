/*
• Designed and implemented a modular C++ e-commerce system using OOP principles 
  (ProductDB, UserDB, CartDB, WalletDB) with persistent storage via file I/O.

• Implemented role-based access control (customer, special customer, admin) 
  with dynamic privilege upgrades based on user spending.

• Built a shopping cart and checkout system with real-time inventory updates 
  and conditional discount logic.

• Developed input-safe console workflows and data validation, 
  including Luhn algorithm–based credit card verification.

• Collaborated in a 4-person team, contributing to system design, debugging, 
  and integration of multiple subsystems. 
  */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

#ifdef _WIN32
  #include <windows.h>
#endif

#define product_database_path "C:\\Users\\baboa\\OneDrive - aucegypt.edu\\Desktop\\code\\project\\products.txt"
#define user_database_path "C:\\Users\\baboa\\OneDrive - aucegypt.edu\\Desktop\\code\\project\\UserDB.txt"

using namespace std;

// Forward declarations
class ProductDB;
class CartDB;
class EWalletDB;
class UserDB;

// Utility function to validate credit card using Luhn algorithm
class CreditCardValidator
{
public:
    static bool isValidCardNumber(const string& cardNumber)
    {
        // Remove spaces and dashes
        string cleanCard;
        for(char c : cardNumber)
        {
            if(isdigit(c))
                cleanCard += c;
        }

        // Card must be 13-19 digits
        if(cleanCard.length() < 13 || cleanCard.length() > 19)
            return false;

        // Luhn algorithm
        int sum = 0;
        bool alternate = false;

        for(int i = cleanCard.length() - 1; i >= 0; i--)
        {
            int digit = cleanCard[i] - '0';

            if(alternate)
            {
                digit *= 2;
                if(digit > 9)
                    digit -= 9;
            }

            sum += digit;
            alternate = !alternate;
        }

        return (sum % 10 == 0);
    }

    static string getCardType(const string& cardNumber)
    {
        string cleanCard;
        for(char c : cardNumber)
        {
            if(isdigit(c))
                cleanCard += c;
        }

        if(cleanCard.empty()) return "Unknown";

        // Visa: starts with 4
        if(cleanCard[0] == '4')
            return "Visa";

        // Mastercard: starts with 51-55 or 2221-2720
        if(cleanCard.length() >= 2)
        {
            int first2 = stoi(cleanCard.substr(0, 2));
            if(first2 >= 51 && first2 <= 55)
                return "Mastercard";
        }
        if(cleanCard.length() >= 4)
        {
            int first4 = stoi(cleanCard.substr(0, 4));
            if(first4 >= 2221 && first4 <= 2720)
                return "Mastercard";
        }

        // American Express: starts with 34 or 37
        if(cleanCard.length() >= 2)
        {
            int first2 = stoi(cleanCard.substr(0, 2));
            if(first2 == 34 || first2 == 37)
                return "American Express";
        }

        // Discover: starts with 6011, 622126-622925, 644-649, or 65
        if(cleanCard.length() >= 4)
        {
            string first4 = cleanCard.substr(0, 4);
            if(first4 == "6011")
                return "Discover";
        }
        if(cleanCard.length() >= 2)
        {
            string first2 = cleanCard.substr(0, 2);
            if(first2 == "65")
                return "Discover";
        }

        return "Unknown";
    }
};

class ProductDB
{
public:
    struct Product
    {
        int id;
        string name;
        int quantity;
        double price;
        string category;
    };

private:
    vector<Product> products;

public:
    ProductDB() {}

    bool loadProducts(const string& path)
    {
        products.clear();
        ifstream file(path);
        if(!file.is_open())
        {
            cout << "Error: Could not open " << path << endl;
            return false;
        }

        Product p;
        while (file >> p.id >> p.name >> p.quantity >> p.price >> p.category)
        {
            products.push_back(p);
        }

        file.close();
        cout << "Loaded " << products.size() << " products from database.\n";
        return true;
    }

    bool saveProducts(const string& path)
    {
        ofstream file(path);
        if(!file.is_open())
        {
            cout << "Error: Could not write to " << path << endl;
            return false;
        }

        for(size_t i = 0; i < products.size(); i++)
        {
            file << products[i].id << " "
                 << products[i].name << " "
                 << products[i].quantity << " "
                 << fixed << setprecision(2) << products[i].price << " "
                 << products[i].category;
            if (i != products.size() - 1) file << "\n";
        }
        file.close();
        return true;
    }

    bool addProduct(int id, const string& name, int qty, double price, const string& category)
    {
        // Check for duplicate ID
        for(const auto& p : products)
        {
            if(p.id == id)
            {
                cout << "Error: Product ID already exists!\n";
                return false;
            }
        }

        if(qty < 0 || price < 0)
        {
            cout << "Error: Quantity and price must be non-negative!\n";
            return false;
        }

        Product p = {id, name, qty, price, category};
        products.push_back(p);
        return true;
    }

    void displayProducts() const
    {
        cout << "\n==== PRODUCT LIST ====\n";
        cout << left << setw(6) << "ID" 
             << setw(20) << "Name" 
             << setw(10) << "Qty" 
             << setw(12) << "Price" 
             << "Category\n";
        cout << string(60, '-') << "\n";
        
        for (const auto& p : products)
        {
            cout << left << setw(6) << p.id
                 << setw(20) << p.name
                 << setw(10) << p.quantity
                 << "$" << setw(11) << fixed << setprecision(2) << p.price
                 << p.category << endl;
        }
    }

    int getQuantity(int id) const
    {
        for (const auto& p : products)
        {
            if (p.id == id) return p.quantity;
        }
        return -1;
    }

    int addQuantity(int id, int amount)
    {
        for (auto& p : products)
        {
            if (p.id == id)
            {
                if(amount < 0)
                {
                    cout << "Error: Cannot add negative quantity!\n";
                    return -1;
                }
                p.quantity += amount;
                cout << p.quantity << " " << p.name << " in stock!\n";
                return p.quantity;
            }
        }
        cout << "Error: Product not found!\n";
        return -1;
    }

    bool subtractQuantity(int id, int amount)
    {
        for (auto& p : products)
        {
            if (p.id == id)
            {
                if (amount <= 0) return true;
                if (p.quantity >= amount)
                {
                    p.quantity -= amount;
                    return true;
                }
                else
                {
                    cout << "Warning: Insufficient stock. Setting to 0.\n";
                    p.quantity = 0;
                    return false;
                }
            }
        }
        return false;
    }

    bool updatePrice(int id, double newPrice)
    {
        if(newPrice < 0)
        {
            cout << "Error: Price cannot be negative!\n";
            return false;
        }

        for (auto& p : products)
        {
            if (p.id == id)
            {
                p.price = newPrice;
                cout << "Price updated successfully!\n";
                return true;
            }
        }
        cout << "Error: Product not found!\n";
        return false;
    }

    bool getProductByID(int id, Product& outProduct) const
    {
        for(const auto& p : products)
        {
            if(p.id == id)
            {
                outProduct = p;
                return true;
            }
        }
        return false;
    }
};

class CartDB
{
public:
    struct CartItem
    {
        int productId;
        int quantity;
    };

    struct Cart
    {
        vector<CartItem> items;
        double totalCost;
    };

public:
    CartDB() {}

    Cart createCart()
    {
        Cart c;
        c.totalCost = 0.0;
        return c;
    }

    void display(const Cart& cart, const ProductDB& pdb) const
    {
        cout << "\n===== SHOPPING CART =====\n";
        if (cart.items.empty())
        {
            cout << "Your cart is empty.\n";
            return;
        }

        cout << left << setw(6) << "ID" 
             << setw(20) << "Name" 
             << setw(10) << "Qty" 
             << setw(12) << "Price" 
             << "Category\n";
        cout << string(60, '-') << "\n";

        for (const auto& item : cart.items)
        {
            ProductDB::Product p;
            if(pdb.getProductByID(item.productId, p))
            {
                cout << left << setw(6) << p.id
                     << setw(20) << p.name
                     << setw(10) << item.quantity
                     << "$" << setw(11) << fixed << setprecision(2) << p.price
                     << p.category << endl;
            }
            else
            {
                cout << "Product ID " << item.productId << " not found in database.\n";
            }
        }
    }

    double calculateTotal(const Cart& cart, int privilege, const ProductDB& pdb) const
    {
        double total = 0.0;
        for(const auto& item : cart.items)
        {
            ProductDB::Product p;
            if(pdb.getProductByID(item.productId, p))
            {
                double itemCost = p.price * item.quantity;
                
                // Apply 70% discount for Skin_Care products for special customers
                if(p.category == "Skin_Care" && privilege >= 1)
                {
                    itemCost *= 0.3; // Pay 30%
                }
                
                total += itemCost;
            }
        }
        return total;
    }

    bool addToCart(Cart& cart, int productId, int quantity)
    {
        if (quantity <= 0)
        {
            cout << "Error: Quantity must be positive!\n";
            return false;
        }

        // Check if product already in cart
        for (auto& item : cart.items)
        {
            if(item.productId == productId)
            {
                item.quantity += quantity;
                return true;
            }
        }

        // Add new item
        cart.items.push_back({productId, quantity});
        return true;
    }

    bool removeFromCart(Cart& cart, int productId, int& removedQuantity)
    {
        for(size_t i = 0; i < cart.items.size(); i++)
        {
            if(cart.items[i].productId == productId)
            {
                removedQuantity = cart.items[i].quantity;
                cart.items.erase(cart.items.begin() + i);
                return true;
            }
        }
        return false;
    }

    void clearCart(Cart& cart)
    {
        cart.items.clear();
        cart.totalCost = 0.0;
    }

    size_t getLength(const Cart& cart) const
    {
        return cart.items.size();
    }

    const vector<CartItem>& getItems(const Cart& cart) const
    {
        return cart.items;
    }
};

class EWalletDB
{
public:
    struct EWallet
    {
        double balance;
        string cardNumber;
        string cardType;
    };

public:
    EWalletDB() {}

    EWallet createWallet(double balance, const string& cardNumber)
    {
        EWallet w;
        w.balance = balance;
        w.cardNumber = cardNumber;
        w.cardType = CreditCardValidator::getCardType(cardNumber);
        return w;
    }

    bool deposit(EWallet& wallet, double amount)
    {
        if(amount <= 0)
        {
            cout << "Error: Deposit amount must be positive!\n";
            return false;
        }

        wallet.balance += amount;
        cout << "Deposited $" << fixed << setprecision(2) << amount 
             << " successfully. New balance: $" << wallet.balance << endl;
        return true;
    }

    bool withdraw(EWallet& wallet, double amount)
    {
        if(amount <= 0)
        {
            cout << "Error: Withdrawal amount must be positive!\n";
            return false;
        }

        if(wallet.balance >= amount)
        {
            wallet.balance -= amount;
            cout << "Withdrew $" << fixed << setprecision(2) << amount 
                 << " successfully. New balance: $" << wallet.balance << endl;
            return true;
        }
        else
        {
            cout << "Error: Insufficient balance!\n";
            return false;
        }
    }

    bool setCardNumber(EWallet& wallet, const string& cardNumber)
    {
        if(!CreditCardValidator::isValidCardNumber(cardNumber))
        {
            cout << "Error: Invalid card number!\n";
            return false;
        }

        wallet.cardNumber = cardNumber;
        wallet.cardType = CreditCardValidator::getCardType(cardNumber);
        cout << "Card number updated successfully. Card type: " << wallet.cardType << endl;
        return true;
    }

    void displayWallet(const EWallet& wallet) const
    {
        cout << "\n===== WALLET INFO =====\n";
        cout << "Card Number: " << wallet.cardNumber << endl;
        cout << "Card Type: " << wallet.cardType << endl;
        cout << "Balance: $" << fixed << setprecision(2) << wallet.balance << endl;
    }

    double getBalance(const EWallet& wallet) const
    {
        return wallet.balance;
    }

    string getCardNumber(const EWallet& wallet) const
    {
        return wallet.cardNumber;
    }

    void deductBalance(EWallet& wallet, double amount)
    {
        wallet.balance -= amount;
    }
};

class UserDB
{
private:
    struct User
    {
        double totalSpending;
        string username;
        string password;
        int privilege; // 0: customer | 1: special customer | 2: admin
    };

    vector<User> users;

public:
    UserDB() {}

    void updateUser(int index, double totalSpending, const string& username, 
                   const string& password, int privilege)
    {
        if(index < 0 || index >= (int)users.size()) return;
        users[index].totalSpending = totalSpending;
        users[index].username = username;
        users[index].password = password;
        users[index].privilege = privilege;
    }

    bool loadUsers(const string& path, ProductDB& pdb, CartDB& cdb, EWalletDB& wdb,
                   vector<CartDB::Cart>& carts, vector<EWalletDB::EWallet>& wallets)
    {
        users.clear();
        carts.clear();
        wallets.clear();

        ifstream file(path);
        if (!file.is_open())
        {
            cout << "Warning: Could not open user database. Starting fresh.\n";
            return false;
        }

        string username;
        while (file >> username)
        {
            string password;
            int privilege;
            int cartLength;
            file >> password >> privilege >> cartLength;

            CartDB::Cart cart = cdb.createCart();

            for(int j = 0; j < cartLength; j++)
            {
                int productId, qty;
                file >> productId >> qty;

                ProductDB::Product p;
                if(pdb.getProductByID(productId, p))
                {
                    cdb.addToCart(cart, productId, qty);
                }
                else
                {
                    cout << "Warning: Invalid product ID " << productId 
                         << " in user " << username << "'s cart.\n";
                }
            }

            string cardNumber;
            double balance;
            file >> cardNumber >> balance;

            EWalletDB::EWallet wallet = wdb.createWallet(balance, cardNumber);

            users.push_back({0.0, username, password, privilege});
            carts.push_back(cart);
            wallets.push_back(wallet);
        }

        file.close();
        cout << "Loaded " << users.size() << " users from database.\n";
        return true;
    }

    bool saveUsers(const string& path, CartDB& cdb, EWalletDB& wdb,
                   const vector<CartDB::Cart>& carts, 
                   const vector<EWalletDB::EWallet>& wallets)
    {
        ofstream file(path);
        if(!file.is_open())
        {
            cout << "Error: Could not write to " << path << endl;
            return false;
        }

        for(size_t i = 0; i < users.size(); i++)
        {
            file << users[i].username << " "
                 << users[i].password << " "
                 << users[i].privilege << " "
                 << carts[i].items.size() << " ";

            for(const auto& item : carts[i].items)
            {
                file << item.productId << " " << item.quantity << " ";
            }

            file << wallets[i].cardNumber << " " 
                 << fixed << setprecision(2) << wallets[i].balance;
            
            if(i != users.size() - 1) file << "\n";
        }
        file.close();
        return true;
    }

    void displayUsers() const
    {
        cout << "\n===== REGISTERED USERS =====\n";
        for(size_t i = 0; i < users.size(); i++)
        {
            cout << (i + 1) << ". " << users[i].username << " - ";
            switch (users[i].privilege)
            {
            case 0:
                cout << "Customer";
                break;
            case 1:
                cout << "Special Customer";
                break;
            case 2:
                cout << "Administrator";
                break;
            default:
                cout << "Unknown";
            }
            cout << "\n";
        }
    }

    bool addUser(const string& username, const string& password, int privilege)
    {
        // Validate username
        if(username.empty() || password.empty())
        {
            cout << "Error: Username and password cannot be empty!\n";
            return false;
        }

        users.push_back({0.0, username, password, privilege});
        return true;
    }

    bool isUnique(const string& username) const
    {
        for(const auto& user : users)
        {
            if(user.username == username) return false;
        }
        return true;
    }

    size_t getLength() const
    {
        return users.size();
    }

    bool login(const string& username, const string& password, int& index, 
              string& outUsername, int& outPrivilege, double& outTotalSpending)
    {
        for(size_t i = 0; i < users.size(); i++)
        {
            if(users[i].username == username && users[i].password == password)
            {
                index = i;
                outUsername = users[i].username;
                outPrivilege = users[i].privilege;
                outTotalSpending = users[i].totalSpending;

                cout << "\n" << string(40, '=') << endl;
                cout << "  Welcome back, " << outUsername << "!" << endl;
                cout << string(40, '=') << "\n" << endl;
                return true;
            }
        }

        cout << "Error: Invalid username or password!\n";
        return false;
    }

    void addTotalSpending(int index, double amount)
    {
        if(index < 0 || index >= (int)users.size()) return;
        users[index].totalSpending += amount;
    }

    double getTotalSpending(int index) const
    {
        if(index < 0 || index >= (int)users.size()) return 0.0;
        return users[index].totalSpending;
    }

    int getPrivilege(int index) const
    {
        if(index < 0 || index >= (int)users.size()) return 0;
        return users[index].privilege;
    }

    void setPrivilege(int index, int privilege)
    {
        if(index < 0 || index >= (int)users.size()) return;
        users[index].privilege = privilege;
    }
};

// Utility functions
void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseConsole()
{
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// Menu functions
void customerMenu(int userIndex, const string& username, int& privilege, double& totalSpending,
                  CartDB::Cart& cart, EWalletDB::EWallet& wallet,
                  ProductDB& pdb, CartDB& cdb, EWalletDB& wdb)
{
    int choice;
    char ynChoice;

    while (true)
    {
        cout << "\n" << string(80, '=') << "\n";
        cout << "CUSTOMER MENU - Logged in as: " << username << "\n";
        cout << string(80, '=') << "\n";
        cout << "1. View Products\n";
        cout << "2. Buy Products\n";
        cout << "3. View Cart\n";
        cout << "4. Return Product\n";
        cout << "5. Checkout\n";
        cout << "6. View Wallet\n";
        cout << "7. Deposit Money\n";
        cout << "8. Withdraw Money\n";
        cout << "9. Logout\n";
        cout << string(80, '=') << "\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pdb.displayProducts();
            pauseConsole();
            break;

        case 2:
        {
            int id, qty;
            pdb.displayProducts();
            cout << "\nEnter product ID to add to cart: ";
            cin >> id;

            ProductDB::Product p;
            if(!pdb.getProductByID(id, p))
            {
                cout << "Error: Invalid product ID!\n";
                pauseConsole();
                break;
            }

            cout << "Available quantity: " << p.quantity << endl;
            cout << "Enter quantity to purchase: ";
            cin >> qty;

            if(qty <= 0)
            {
                cout << "Error: Quantity must be positive!\n";
                pauseConsole();
                break;
            }

            if(qty <= p.quantity)
            {
                cdb.addToCart(cart, id, qty);
                pdb.subtractQuantity(id, qty);
                cout << "Success: " << qty << " x " << p.name << " added to cart!\n";
            }
            else
            {
                cout << "Error: Insufficient stock available!\n";
            }
            pauseConsole();
            break;
        }

        case 3:
        {
            cdb.display(cart, pdb);

            if(cdb.getLength(cart) > 0)
            {
                double totalCost = cdb.calculateTotal(cart, privilege, pdb);

                if(privilege >= 1)
                    cout << "\n* Special Customer Discount: 70% off Skin Care products!\n";
                
                cout << "\nTotal Cost: $" << fixed << setprecision(2) << totalCost << endl;
            }
            pauseConsole();
            break;
        }

        case 4:
        {
            if (cdb.getLength(cart) == 0)
            {
                cout << "Your cart is empty!\n";
                pauseConsole();
                break;
            }

            cdb.display(cart, pdb);
            cout << "\nEnter product ID to return: ";
            int returnId;
            cin >> returnId;
            
            int removedQty;
            if(cdb.removeFromCart(cart, returnId, removedQty))
            {
                pdb.addQuantity(returnId, removedQty);
                cout << "Product returned successfully!\n";
            }
            else
            {
                cout << "Error: Product not found in cart!\n";
            }
            pauseConsole();
            break;
        }

        case 5:
        {
            if(cdb.getLength(cart) == 0)
            {
                cout << "Your cart is empty!\n";
                pauseConsole();
                break;
            }

            cdb.display(cart, pdb);
            double totalCost = cdb.calculateTotal(cart, privilege, pdb);

            cout << "\n" << string(40, '-') << "\n";
            cout << "Total Amount: $" << fixed << setprecision(2) << totalCost << endl;
            cout << "Current Balance: $" << wdb.getBalance(wallet) << endl;
            cout << string(40, '-') << "\n";

            if(totalCost > wdb.getBalance(wallet))
            {
                cout << "Insufficient balance! Please deposit more funds.\n";
                pauseConsole();
                break;
            }

            cout << "Proceed with payment? (y/n): ";
            cin >> ynChoice;

            if(ynChoice == 'y' || ynChoice == 'Y')
            {
                wdb.deductBalance(wallet, totalCost);
                totalSpending += totalCost;
                
                cout << "\n*** PAYMENT SUCCESSFUL ***\n";
                cout << "Amount charged: $" << totalCost << endl;
                cout << "New balance: $" << wdb.getBalance(wallet) << endl;

                cdb.clearCart(cart);

                // Check for privilege upgrade
                if(totalSpending >= 10000 && privilege == 0)
                {
                    privilege = 1;
                    cout << "\n" << string(50, '*') << "\n";
                    cout << "*** CONGRATULATIONS! ***\n";
                    cout << "You've been upgraded to SPECIAL CUSTOMER!\n";
                    cout << "Enjoy 70% off on all Skin Care products!\n";
                    cout << string(50, '*') << "\n";
                }
            }
            else
            {
                cout << "Checkout cancelled.\n";
            }
            pauseConsole();
            break;
        }

        case 6:
            wdb.displayWallet(wallet);
            pauseConsole();
            break;

        case 7:
        {
            double amount;
            cout << "Enter amount to deposit: $";
            cin >> amount;
            wdb.deposit(wallet, amount);
            pauseConsole();
            break;
        }

        case 8:
        {
            double amount;
            cout << "Current balance: $" << fixed << setprecision(2) 
                 << wdb.getBalance(wallet) << endl;
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            wdb.withdraw(wallet, amount);
            pauseConsole();
            break;
        }

        case 9:
            cout << "Logging out...\n";
            return;

        default:
            cout << "Invalid option! Please try again.\n";
            pauseConsole();
            break;
        }
    }
}

void adminMenu(ProductDB& pdb)
{
    int choice;

    while (true)
    {
        cout << "\n" << string(80, '=') << "\n";
        cout << "ADMINISTRATOR MENU\n";
        cout << string(80, '=') << "\n";
        cout << "1. Add Product\n";
        cout << "2. Modify Product Quantity\n";
        cout << "3. Modify Product Price\n";
        cout << "4. View Products\n";
        cout << "5. Logout\n";
        cout << string(80, '=') << "\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id, qty;
            double price;
            string name, category;

            cout << "\n--- Add New Product ---\n";
            cout << "Enter Product ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Product Name: ";
            getline(cin, name);
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Price: $";
            cin >> price;
            cin.ignore();
            cout << "Enter Category: ";
            getline(cin, category);

            if(pdb.addProduct(id, name, qty, price, category))
                cout << "Product added successfully!\n";
            
            pauseConsole();
            break;
        }

        case 2:
        {
            pdb.displayProducts();
            int id, qty;
            cout << "\nEnter Product ID: ";
            cin >> id;
            cout << "Enter quantity to add: ";
            cin >> qty;

            pdb.addQuantity(id, qty);
            pauseConsole();
            break;
        }

        case 3:
        {
            pdb.displayProducts();
            int id;
            double price;
            cout << "\nEnter Product ID: ";
            cin >> id;
            cout << "Enter new price: $";
            cin >> price;

            pdb.updatePrice(id, price);
            pauseConsole();
            break;
        }

        case 4:
            pdb.displayProducts();
            pauseConsole();
            break;

        case 5:
            cout << "Logging out...\n";
            return;

        default:
            cout << "Invalid option! Please try again.\n";
            pauseConsole();
            break;
        }
    }
}

int main()
{
    UserDB database;
    ProductDB pdb;
    CartDB cdb;
    EWalletDB wdb;
    int mainChoice;

    vector<CartDB::Cart> userCarts;
    vector<EWalletDB::EWallet> userWallets;

    cout << "\n" << string(60, '=') << "\n";
    cout << "  E-COMMERCE MANAGEMENT SYSTEM\n";
    cout << string(60, '=') << "\n\n";

    // Load product and user databases (if they exist)
    pdb.loadProducts(product_database_path);
    database.loadUsers(user_database_path, pdb, cdb, wdb, userCarts, userWallets);

    while (true)
    {
        clearConsole();
        cout << string(60, '=') << "\n";
        cout << " MAIN MENU\n";
        cout << string(60, '=') << "\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. View Products (guest)\n";
        cout << "4. Save Databases\n";
        cout << "5. Exit\n";
        cout << string(60, '=') << "\n";
        cout << "Enter choice: ";

        if (!(cin >> mainChoice))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            pauseConsole();
            continue;
        }

        if (mainChoice == 1) // Login
        {
            string username, password;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            int userIndex = -1;
            string outUsername;
            int outPrivilege = 0;
            double outTotalSpending = 0.0;

            if (database.login(username, password, userIndex, outUsername, outPrivilege, outTotalSpending))
            {
                // Ensure carts and wallets vectors are sized to match users
                if ((size_t)userIndex >= userCarts.size())
                {
                    userCarts.resize(database.getLength()); // make sure vector large enough
                }
                if ((size_t)userIndex >= userWallets.size())
                {
                    userWallets.resize(database.getLength());
                }

                // If no wallet/cart exists for this loaded user (e.g., user was created in-memory),
                // create default ones.
                if (userCarts[userIndex].items.empty() && userWallets[userIndex].cardNumber.empty()
                    && userWallets[userIndex].balance == 0.0)
                {
                    // It's possible loadUsers created them; this just ensures no out-of-range access.
                    // If they were properly loaded they are already populated.
                }

                // Get references to this user's cart and wallet (create if necessary)
                if (userIndex >= (int)userCarts.size())
                    userCarts.resize(userIndex + 1, cdb.createCart());
                if (userIndex >= (int)userWallets.size())
                    userWallets.resize(userIndex + 1, wdb.createWallet(0.0, ""));

                CartDB::Cart& cart = userCarts[userIndex];
                EWalletDB::EWallet& wallet = userWallets[userIndex];

                // Local copies of privilege & spending that menus will update by reference
                int privilege = outPrivilege;
                double totalSpending = outTotalSpending;

                // Call appropriate menu
                if (privilege == 2)
                {
                    // Administrator
                    adminMenu(pdb);

                    // After admin finishes, save products (admins typically change products)
                    pdb.saveProducts(product_database_path);
                }
                else
                {
                    customerMenu(userIndex, outUsername, privilege, totalSpending,
                                 cart, wallet, pdb, cdb, wdb);

                    // Save updated user info back into UserDB
                    // We need the user's password to call updateUser; we have it as `password`
                    database.updateUser(userIndex, totalSpending, outUsername, password, privilege);
                }

                // After logout, continue to main menu
            }
            else
            {
                pauseConsole();
            }
        }
        else if (mainChoice == 2) // Register
        {
            string username, password;
            cout << "Choose a username: ";
            cin >> username;
            cout << "Choose a password: ";
            cin >> password;

            if (!database.isUnique(username))
            {
                cout << "Error: Username already taken.\n";
                pauseConsole();
                continue;
            }

            // Add user with default privilege 0 (customer)
            if (!database.addUser(username, password, 0))
            {
                cout << "Failed to add user.\n";
                pauseConsole();
                continue;
            }

            // Create default cart and wallet for new user
            CartDB::Cart newCart = cdb.createCart();
            EWalletDB::EWallet newWallet = wdb.createWallet(0.0, ""); // empty card, zero balance

            userCarts.push_back(newCart);
            userWallets.push_back(newWallet);

            cout << "Registration successful! You can now login.\n";
            pauseConsole();
        }
        else if (mainChoice == 3) // View Products as guest
        {
            pdb.displayProducts();
            pauseConsole();
        }
        else if (mainChoice == 4) // Save Databases
        {
            if (pdb.saveProducts(product_database_path))
                cout << "Products saved successfully.\n";
            else
                cout << "Failed to save products.\n";

            if (database.saveUsers(user_database_path, cdb, wdb, userCarts, userWallets))
                cout << "Users saved successfully.\n";
            else
                cout << "Failed to save users.\n";

            pauseConsole();
        }
        else if (mainChoice == 5) // Exit
        {
            cout << "Saving databases before exit...\n";

            if (pdb.saveProducts(product_database_path))
                cout << "Products saved successfully.\n";
            else
                cout << "Failed to save products.\n";

            if (database.saveUsers(user_database_path, cdb, wdb, userCarts, userWallets))
                cout << "Users saved successfully.\n";
            else
                cout << "Failed to save users.\n";

            cout << "Goodbye!\n";
            break;
        }
        else
        {
            cout << "Invalid option. Try again.\n";
            pauseConsole();
        }
    }

    return 0;
}
