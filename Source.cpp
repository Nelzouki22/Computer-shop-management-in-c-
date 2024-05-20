#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Computer {
public:
    int id;
    string brand;
    string model;
    double price;

    Computer(int id, string brand, string model, double price) {
        this->id = id;
        this->brand = brand;
        this->model = model;
        this->price = price;
    }
};

class Shop {
private:
    vector<Computer> inventory;
    int nextId;

public:
    Shop() {
        nextId = 1;
    }

    void addComputer(string brand, string model, double price) {
        Computer newComputer(nextId, brand, model, price);
        inventory.push_back(newComputer);
        cout << "Computer added with ID: " << nextId << endl;
        nextId++;
    }

    void displayInventory() {
        if (inventory.empty()) {
            cout << "No computers in inventory." << endl;
            return;
        }
        cout << "Inventory: " << endl;
        for (const auto& computer : inventory) {
            cout << "ID: " << computer.id
                << ", Brand: " << computer.brand
                << ", Model: " << computer.model
                << ", Price: $" << computer.price << endl;
        }
    }

    void sellComputer(int id) {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->id == id) {
                cout << "Selling Computer: " << it->brand << " " << it->model << " for $" << it->price << endl;
                inventory.erase(it);
                return;
            }
        }
        cout << "Computer with ID " << id << " not found." << endl;
    }
};

void showMenu() {
    cout << "Computer Shop Management System" << endl;
    cout << "1. Add a new computer to the inventory" << endl;
    cout << "2. Display inventory" << endl;
    cout << "3. Sell a computer" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    Shop shop;
    int choice;
    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string brand, model;
            double price;
            cout << "Enter brand: ";
            cin >> brand;
            cout << "Enter model: ";
            cin >> model;
            cout << "Enter price: ";
            cin >> price;
            shop.addComputer(brand, model, price);
        }
        else if (choice == 2) {
            shop.displayInventory();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID of computer to sell: ";
            cin >> id;
            shop.sellComputer(id);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
