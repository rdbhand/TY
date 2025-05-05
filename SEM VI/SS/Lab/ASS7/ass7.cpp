#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Class to represent a single Symbol
class Symbol {
public:
    string type;
    int scopeLevel;

    Symbol() {}

    Symbol(string t, int s) : type(t), scopeLevel(s) {}

    void display() const {
        cout << "Type: " << type << ", Scope Level: " << scopeLevel << endl;
    }
};

// Class to manage the Symbol Table
class SymbolTable {
private:
    unordered_map<string, Symbol> table;

public:
    // Add a symbol to the table
    void addSymbol(const string& name, const string& type, int scopeLevel) {
        if (table.find(name) != table.end()) {
            cout << "Symbol '" << name << "' already exists.\n";
            return;
        }
        table[name] = Symbol(type, scopeLevel);
        cout << "Symbol '" << name << "' added.\n";
    }

    // Delete a symbol from the table
    void deleteSymbol(const string& name) {
        if (table.erase(name)) {
            cout << "Symbol '" << name << "' deleted.\n";
        } else {
            cout << "Symbol '" << name << "' not found.\n";
        }
    }

    // Update an existing symbol
    void updateSymbol(const string& name, const string& newType, int newScopeLevel) {
        auto it = table.find(name);
        if (it != table.end()) {
            it->second.type = newType;
            it->second.scopeLevel = newScopeLevel;
            cout << "Symbol '" << name << "' updated.\n";
        } else {
            cout << "Symbol '" << name << "' not found.\n";
        }
    }

    // Display the entire symbol table
    void display() const {
        if (table.empty()) {
            cout << "Symbol table is empty.\n";
            return;
        }

        cout << "\n--- Symbol Table ---\n";
        for (const auto& entry : table) {
            cout << "Name: " << entry.first << ", ";
            entry.second.display();
        }
        cout << "---------------------\n";
    }
};

// Main driver function
int main() {
    SymbolTable symTable;
    int choice;
    string name, type;
    int scopeLevel;

    do {
        cout << "\n--- Symbol Table Menu ---\n";
        cout << "1. Add Symbol\n";
        cout << "2. Delete Symbol\n";
        cout << "3. Update Symbol\n";
        cout << "4. Display Symbol Table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Symbol Name: ";
                cin >> name;
                cout << "Enter Symbol Type: ";
                cin >> type;
                cout << "Enter Scope Level: ";
                cin >> scopeLevel;
                symTable.addSymbol(name, type, scopeLevel);
                break;

            case 2:
                cout << "Enter Symbol Name to Delete: ";
                cin >> name;
                symTable.deleteSymbol(name);
                break;

            case 3:
                cout << "Enter Symbol Name to Update: ";
                cin >> name;
                cout << "Enter New Type: ";
                cin >> type;
                cout << "Enter New Scope Level: ";
                cin >> scopeLevel;
                symTable.updateSymbol(name, type, scopeLevel);
                break;

            case 4:
                symTable.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
