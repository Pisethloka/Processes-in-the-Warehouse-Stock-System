#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

void stockMenu();
void itemInfoMenu();

void CreateStockRecord();
void SearchStockDetails();
void UpdateStockDetails();
void DeleteStockRecord();

void CreateItemInfo();
void SearchItemInfo();
void UpdateItemInfo();
void DeleteItemInfo();

void stockMenu() {
    int choice;
    cout <<"1. Create Stock records" <<endl;
    cout <<"2. Search Stock detail by ID: "<<endl;
    cout <<"3. Update Stock for quantities (for incoming and outgoing stocks): "<<endl;
    cout <<"4. Delete Stock record "<<endl;
    cout <<"5. Exit"<<endl;
    
    cout <<"Enter your choice: "; cin>>choice;

    switch (choice) {
    case 1:
        stockMenu;
        break;
    case 2:
        itemInfoMenu();
        break;
    case 3:
        UpdateStockDetails();
        break;
    case 4:
        DeleteStockRecord();
        break;
    case 5:
        cout <<"Exiting the Program.";
        break;

    default: cout << "Invalid choice\n";
    }
}

void itemInfoMenu() {
    int choice;
    cout <<"1. Create item information records."<<endl;
    cout <<"2. Search item details by ID."<<endl;
    cout <<"3. Update item details."<<endl;
    cout <<"4. Delete item records."<<endl;
    cout <<"5.Exit."<<endl;

    switch (choice) {
    case 1:
        CreateItemInfo();
        break;
    case 2:
        SearchItemInfo();
        break;
    case 3:
        UpdateItemInfo();
        break;
    case 4:
        DeleteItemInfo();
        break;
    case 5:
        cout <<"Exiting the Program.";
        break;
    default: cout<<"invalid choice."<<endl;
    
        break;
    }
}
void UpdateItemInfo()
{
    fstream fin("ItemInfo.csv");
    ofstream fout("ItemInfo_new.csv");

    int idnum, id2, count = 0;
    string new_qty, new_price;
    string line, word;
    vector<string> row;

    cout << "Enter Item ID to update: ";
    cin >> idnum;
    cin.ignore(); // Clear newline left in input buffer
    cout << "Enter new quantity: ";
    getline(cin, new_qty);
    cout << "Enter new price: ";
    getline(cin, new_price);

    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        id2 = stoi(row[0]);
        int row_size = row.size();
        if (id2 == idnum) {
            count = 1;
            row[2] = new_qty;
            row[3] = new_price;
        }

        for (int i = 0; i < row_size - 1; i++) {
            fout << row[i] << ",";
        }
        fout << row[row_size - 1] << "\n";
    }

    if (count == 0)
        cout << "Update not successful.\n";

    fin.close();
    fout.close();

    remove("ItemInfo.csv");
    rename("ItemInfo_new.csv", "ItemInfo.csv");
};
void DeleteItemInfo() {
    ifstream fin("ItemInfo.csv");
    ofstream fout("ItemInfo_new.csv");

    int idnum, id2, count = 0;
    string line;
    vector<string> row;

    cout << "Enter the ID of item to be deleted: ";
    cin >> idnum;

    while (getline(fin, line)) {
        row.clear();
        stringstream s(line);
        string word;

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        id2 = stoi(row[0]);

        if (id2 != idnum) {
            for (size_t i = 0; i < row.size() - 1; i++) {
                fout << row[i] << ",";
            }
            fout << row.back() << "\n";
        } else {
            count = 1;
        }
    }

    if (count == 1) {
        cout << "Item Deleted\n";
    } else {
        cout << "Item not found\n";
    }

    fin.close();
    fout.close();

    remove("ItemInfo.csv");
    rename("ItemInfo_new.csv", "ItemInfo.csv");
};


