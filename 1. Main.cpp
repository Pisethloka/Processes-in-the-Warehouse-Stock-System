#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

void scoreMenu();
void itemInfoMenu;

void scoreMenu() {
    int choice;
    cout <<"1. Create Stock records" <<endl;
    cout <<"2. Search Stock detail by ID: "<<endl;
    cout <<"3. Update Stock for quantities (for incoming and outgoing stocks): "<<endl;
    cout <<"4. Delete Stock record "<<endl;
    cout <<"5. Exit"<<endl;
    
    cout <<"Enter your choice: "; cin>>choice;

    switch (choice) {
    case 1:
        break;
    
    default:
        break;
    }
    cout << "Hello world";
}
