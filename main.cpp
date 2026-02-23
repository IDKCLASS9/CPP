#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Restaurant {
private:
    string menu[11] = {"Pizza", "Burger", "Pasta", "Fries", "Coke", "Momo", "Ice Cream", "Pasta Salad", "Hot Dog", "Milkshake", "French Toast"};
    int prices[11] = {250, 150, 200, 100, 50, 180, 50, 120, 170, 90, 80};

public:
    void displayMenu() {
        cout << "\nWelcome to Foodie Heaven!" << endl;
        cout << "Here is our delicious menu:\n";
        cout << setw(25) << left << "Item" << "Price (Rs.)\n";
        cout << "----------------------------\n";
        for (int i = 0; i < 11; i++) {
            cout << setw(25) << left << menu[i] << prices[i] << endl;
        }
    }

    void takeOrder() {
        string item;
        int quantity, totalBill = 0;

        displayMenu();

        while (true) {
            cout << "\nWhat would you like to order? (Enter 'done' to finish) ";
            getline(cin, item);

            if (item == "done") {
                break;
            }

            bool itemFound = false;
            for (int i = 0; i < 11; i++) {
                if (item == menu[i]) {
                    cout << "How many " << item << "(s) would you like? ";
                    cin >> quantity;
                    cin.ignore();

                    if (quantity > 0) {
                        totalBill += prices[i] * quantity;
                        cout << "Added " << quantity << " " << item << "(s) to your order." << endl;
                    } else {
                        cout << "Quantity must be at least 1." << endl;
                    }
                    itemFound = true;
                    break;
                }
            }

            if (!itemFound) {
                cout << "Sorry, we do not have that item on the menu." << endl;
            }
        }

        cout << "\nGenerating your bill...\n";
        cout << "----------------------------\n";
        cout << setw(25) << left << "Item" << setw(10) << left << "Quantity" << setw(10) << left << "Price" << "Total (Rs.)\n";
        cout << "------------------------------------------------------\n";
        cout << setw(45) << left << "Grand Total: Rs." << totalBill << endl;
        cout << "\nThank you for dining with us! Have a great day!" << endl;
    }
};

int main() {
    cout << "==============================\n";
    cout << "||    FOODIE RESTAURANT SYSTEM    ||\n";
    cout << "==============================\n";

    Restaurant restaurant;
    restaurant.takeOrder();

    return 0;
}