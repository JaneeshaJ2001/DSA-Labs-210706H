#include <cstring>
#include <string>
#include <iostream>
using namespace std;


struct HashTable{
    int MAX_LENGTH = 4;
    string * password = new string[MAX_LENGTH];

    void intialize_hashtable(){
        for (int i = 0; i < 4; i++){
            password[i].clear();
        }
    }
    bool isFull(){
        bool full = true;
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++){
            if(password[i].empty()){
                full = false;
            }
        }
        return full;
    }
    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
	//add your code below
    //here we iterate each character in the given string and add all the characters, then we obtain sum.
        for(int i = 0;i< user_name.length(); i++){
            sum += int(user_name[i]);

        }
	
	
        hash = sum % MAX_LENGTH;

        return hash;
    }
    bool is_slot_empty(int hash){
        bool empty = password[hash].empty();
        return empty;
    }
    void insert(string user_name,string user_password){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
	//add an if condition to complete the code here

    //here we check the location is empty, then we assign password at that hash value of the location.
    //simply hash value gives the index of the location where we gonna store the value..

        if (empty){
            password[hash] = user_password;
        }else{
            cout << "The location is already assigned" << endl;
        }
        

    }
    void hash_lookup(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
	//add an if condition to complete the code here
	
    //if the location is empty (means nothig has stored in that location) we simply print a message
    //otherwise print the value that stored at that location
        if (empty){
            cout << "The password you're looking is not stored ." << endl;
        }else{
            cout << password[hash] << endl;
        }
	
    }
    void delete_item(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        if(empty){
            cout<<"No item found\n";
        }
        else{
            password[hash].clear();
            cout<<"User deleted\n";
        }

    }
    void print_hashtable(){
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->"<<password[i]<<"\n";
        }
    }

};

int main(){
    HashTable * hashtbl = new HashTable;
    hashtbl->intialize_hashtable();
    cout<< hashtbl->isFull()<<"\n";

    int command=0;
    string user_name;
    string password;
    while (command!=-1){
        /* code */
        cout << "Type command: ";
        cin >> command;
        switch (command){
        case 1:
            /* insert the new item*/
            cout << "\nEnter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name,password);
            break;
        case 2:
            /* delete item */
            cout << "\nEnter item to be deleted: ";
            cin >> user_name;
            hashtbl->delete_item(user_name);
            break;
        case 3:
            /* hash lookup password*/
            cout << "\nEnter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 4:
            hashtbl->print_hashtable();
            break;
        case -1:
            /* hash lookup password*/
            cout << "Exiting...\n";
            break;
        
        }

    
    }
    return 0;
}
