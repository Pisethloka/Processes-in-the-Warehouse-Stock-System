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
