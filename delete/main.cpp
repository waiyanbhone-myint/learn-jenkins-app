#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Class to store menu item details
class menuItemType {
public:
    string name;   // Name of the breakfast item
    double price;  // Price of the breakfast item
};

// Function to load menu data into menuList array
void getData(menuItemType menuList[], int size) {
    // Hardcode the menu items and their prices
    menuList[0] = {"Plain Egg", 1.45};
    menuList[1] = {"Bacon and Egg", 2.45};
    menuList[2] = {"Muffin", 0.99};
    menuList[3] = {"French Toast", 1.99};
    menuList[4] = {"Fruit Basket", 2.49};
    menuList[5] = {"Cereal", 0.69};
    menuList[6] = {"Coffee", 0.50};
    menuList[7] = {"Tea", 0.75};
}

// Function to display the menu to the customer
void showMenu(menuItemType menuList[], int size) {
    cout << "Welcome to Joe's Restaurant" << endl;
    cout << "Menu:" << endl;
    for (int i = 0; i < size; i++) {
        // Print item number, name, and price with two decimals
        cout << setw(2) << (i + 1) << ") "
             << left << setw(20) << menuList[i].name
             << " $" << fixed << setprecision(2) << menuList[i].price
             << endl;
    }
    cout << endl;
    cout << "Enter your order by typing the item number and quantity." << endl;
    cout << "Type 0 for item number when you are finished." << endl;
}

// Function to calculate and print the check
void printCheck(menuItemType menuList[], int orderedItems[][2], int count) {
    const double TAX_RATE = 0.05;  // 5% tax
    double subtotal = 0.0;

    cout << endl << fixed << setprecision(2);
    // Loop through each ordered item and print line
    for (int i = 0; i < count; i++) {
        int itemIndex = orderedItems[i][0];   // index in menuList
        int quantity  = orderedItems[i][1];   // quantity ordered
        double itemTotal = menuList[itemIndex].price * quantity;
        subtotal += itemTotal;
        // Print quantity, item name, and line total
        cout << setw(2) << quantity << " x "
             << left << setw(20) << menuList[itemIndex].name
             << " $" << itemTotal << endl;
    }
    double tax   = subtotal * TAX_RATE;
    double total = subtotal + tax;

    // Print tax and total
    cout << endl;
    cout << right << setw(25) << "Tax: "    << " $" << tax   << endl;
    cout << right << setw(25) << "Total: "  << " $" << total << endl;
}

int main() {
    const int MENU_SIZE = 8;
    menuItemType menuList[MENU_SIZE];
    getData(menuList, MENU_SIZE);
    showMenu(menuList, MENU_SIZE);

    int orderedItems[10][2]; // [][0]=index, [][1]=quantity
    int count = 0;

    while (true) {
        int choice;
        int quantity;
        cout << "Item number (0 to finish): ";
        cin >> choice;
        if (choice == 0) break;
        if (choice < 1 || choice > MENU_SIZE) {
            cout << "Invalid item number. Please try again." << endl;
            continue;
        }
        cout << "Quantity: ";
        cin >> quantity;
        if (quantity <= 0) {
            cout << "Invalid quantity. Please try again." << endl;
            continue;
        }
        orderedItems[count][0] = choice - 1;
        orderedItems[count][1] = quantity;
        count++;
    }

    if (count > 0) {
        printCheck(menuList, orderedItems, count);
    } else {
        cout << "No items ordered." << endl;
    }

    return 0;
}
