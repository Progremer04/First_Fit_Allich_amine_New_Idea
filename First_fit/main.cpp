// time in this code cheack secend is like bite ;
/*
راه يافيشي صحيحة
عندك كي تافيشيلك preoccssuc didn't work معنتها
مالقاش بلصة فال zone الولة
و راه يرروح للزاوجة
و راك قالبهم 0 معنتها libre و 1 ocopy
*/

#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

// For Zone Memoire
// Struct name should start with a capital letter
struct Zone_Memoire {
    string Name_Zone;
    int size_zone;
    int oc_lib;
    Zone_Memoire* next;
};

// Constructor name must match the struct name
Zone_Memoire* new_Zone_Memoire(string name_zone, int size_zone, int oc_lib) {
    Zone_Memoire* zone = new Zone_Memoire();
    zone->Name_Zone = name_zone;
    zone->size_zone = size_zone;
    zone->oc_lib = oc_lib;
    zone->next = NULL;
    return zone;
}

// Method name must match the struct name
Zone_Memoire* addatend(Zone_Memoire* head, string name_zo, int size_zo, int o_l) {
    if (head == NULL) {
        head = new_Zone_Memoire(name_zo, size_zo, o_l);
    } else {
        head->next = addatend(head->next, name_zo, size_zo, o_l);
    }
    return head;
}

int sum_zones(Zone_Memoire* zone) {
    return (zone == NULL) ? 0 : zone->size_zone + sum_zones(zone->next);
}

int sum_zones_allocation_unit(Zone_Memoire* zone, int Allocational_unit) {
    return (zone == NULL) ? 0 : ((zone->size_zone / Allocational_unit) + sum_zones_allocation_unit(zone->next, Allocational_unit));
}

void show_zone(Zone_Memoire* head) {
    if (head == NULL) {
        cout << "\n OOPS! Zone Is Vide \n";
    } else {
        Zone_Memoire* zone = head;
        while (zone != NULL) {
            cout << "Name Of Zone " << "\tSize of Zone ";
            (zone->oc_lib == 0) ? cout << "\t\t is Libre" : cout << "\t\t is Occupee";
            cout << endl << "\t" << zone->Name_Zone << "\t" << zone->size_zone << "\t KO" << endl;
            zone = zone->next;
        }
    }
}

// Struct name should start with a capital letter
struct Processus {
public:
    string name_process;
    int time_came;
    int time_execute;
    int size_process;
};

bool is_available_to_divide_with_allocational_unit(int size, int allocational_unit) {
    return ((size % allocational_unit == 0) && (size >= allocational_unit));
}

void Init_Table(int arrayes[], int sizes, int value) {
    fill(arrayes, arrayes + sizes, value);
}

void reversearray(int e[], int size) {
    int array1[size];
    int i = size - 1, j = 0;
    while (i >= 0) {
        array1[j] = e[i];
        --i;
        ++j;
    }
    Init_Table(e, size, 0);
    for (i = 0; i < size; ++i) e[i] = array1[i];
}

void show_arryofbit(int array[], int Allocational_unit, int size) {
    reversearray(array, size);
    int j;
    for (int i = 0; i < size; ++i) {
        cout << endl << "\t" << i + 1 << "\t \t" << array[i];
        if ((i + 1) % Allocational_unit == 0) { cout << endl; j = i; }
    }
}

void show_Preseccus(vector<Processus> array) {
    cout << "Name Of Preseccus " << "\t\tTime came " << "\t\t Time execution" << "\t\tSize of Preseccus ";

    for (Processus p : array) {
        cout << endl << "\t" << p.name_process << "\t\t\t" << p.time_came << "\t\t\t" << p.time_execute << "\t\t\t\t" << p.size_process << "  KO" << endl;
    }
}

void array_bits(Zone_Memoire* zone, int arrays[], int Allocational_unit) {
    int sizes = sum_zones_allocation_unit(zone, Allocational_unit);
    if (zone != NULL) {
        while (zone != NULL) {
            sizes -= (zone->size_zone / Allocational_unit);
            (zone->oc_lib == 1) ? Init_Table(arrays + sizes, (zone->size_zone / Allocational_unit), 1) : Init_Table(arrays + sizes, (zone->size_zone / Allocational_unit), 0);
            zone = zone->next;
        }
    }
}

auto compair(Processus p1, Processus p2) {
    return (p1.time_came < p2.time_came) ? true : false;
}

void tridecroisant(vector<Processus>& processuses) {
    sort(processuses.begin(), processuses.end(), compair);
}

void first_fit_array(Zone_Memoire* zone, int array[], int size, int Allocational_unit, vector<Processus>& processuses) {
    array_bits(zone, array, Allocational_unit);
    Init_Table(array, size, 0);  // Initialize the array to 0

    tridecroisant(processuses);

    Zone_Memoire* zone1 = NULL;

    for (Processus p : processuses) {
        zone1 = zone;
        bool trouve = false;

        while (zone1 != NULL && !trouve) {
            int n1 = zone1->size_zone / Allocational_unit;
            int n2 = p.size_process / Allocational_unit;

            if (n1 >= n2 && zone1->oc_lib == 0) {
                // Find the first suitable zone and allocate the process
                int start_index = (zone1->size_zone / Allocational_unit) - n2;

                for (int i = start_index; i < start_index + n2; ++i) {
                    array[i] = 1;  // Mark the allocated blocks as occupied
                }

                trouve = true;
                zone1->size_zone -= (n2 * Allocational_unit);
                cout << endl << p.name_process << " is working " << endl;

                for (int i = 0; i < p.time_execute; ++i) {
                    cout << "\r ...";
                    Sleep(1);  // Uncomment if you want to introduce a delay
                }

                cout << endl;
            }

            zone1 = zone1->next;
        }

        if (!trouve) {
            cout << endl << "\t Presseccus \t" << p.name_process << " didn't work, oops!" << endl;
        }
    }
}


struct linked_list {
    string name;
    bool free_occupy;
    int address_begin;
    int size;
    linked_list* next;

    linked_list(string name, int address, int size, bool free_occupy) :
        name(name), free_occupy(free_occupy), address_begin(address), size(size), next(nullptr) {}
};

void add_node(linked_list*& head, string name, int address, int size, bool free_occupy) {
    auto new_node = new linked_list(name, address, size, free_occupy);

    if (head == nullptr) {
        head = new_node;
        head->next = head;
    }
    else {
        auto temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

void update_node(linked_list* head, int address, int new_size, bool free_occupy) {
    linked_list* curr = head;
    do {
        if (curr->address_begin == address) {
            curr->free_occupy = free_occupy;
            curr->size = new_size;
            break;
        }
        curr = curr->next;
    } while (curr != head);
}

void remove_node(linked_list*& head, int address) {
    if (head == nullptr) {
        return;
    }

    linked_list* curr = head;
    linked_list* prev = nullptr;

    do {
        if (curr->address_begin == address) {
            if (prev == nullptr) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}

linked_list* find_node(linked_list* head, int address) {
    linked_list* curr = head;
    do {
        if (curr->address_begin == address) {
            return curr;
        }
        curr = curr->next;
    } while (curr != head);
    return nullptr;
}

void show_linked(linked_list* head) {
    linked_list* curr = head;
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
        return;
    }
    do {
        cout << "Name: " << curr->name << endl;
        cout << "Address begin: " << curr->address_begin << endl;
        cout << "Size: " << curr->size << endl;
        cout << "Free/Occupied: " << (curr->free_occupy ? "Free" : "Occupied") << endl;
        cout << endl;
        curr = curr->next;
    } while (curr != head);
}

void first_fit_linked_list(linked_list* head, int Allocational_unit, vector<Processus>& processuses) {
    linked_list* curr = head;
    do {
        curr->free_occupy = true;
        curr = curr->next;
    } while (curr != head);

    sort(processuses.begin(), processuses.end(), compair);

    for (Processus p : processuses) {
        curr = head;
        bool found = false;
        do {
            int n1 = curr->size / Allocational_unit;
            int n2 = p.size_process / Allocational_unit;

            if (n1 >= n2 && curr->free_occupy) {
                // Allocate the process in the linked list
                int start_address = curr->address_begin;

                if (n2 < n1) {
                    linked_list* new_node = new linked_list(curr->name, 0, 0, 0);
                    new_node->address_begin = start_address;
                    new_node->size = curr->size - p.size_process;
                    new_node->free_occupy = true;
                    new_node->next = curr->next;
                    curr->next = new_node;
                    curr = new_node;
                } else {
                    curr->free_occupy = false;
                    curr->size = 0;
                    curr = curr->next;
                }

                cout << endl << p.name_process << " is working " << endl;

                for (int i = 0; i < p.time_execute; ++i) {
                    cout << "\r ...";
                    Sleep(1);  // Uncomment if you want to introduce a delay
                }

                cout << endl;
                found = true;
            }

            curr = curr->next;
        } while (curr != head && !found);

        if (!found) {
            cout << endl << "\t Error! \t" << p.name_process << " couldn't be allocated memory!" << endl;
        }
    }
}

class looding{
public:
    int secend=80;
    string namefile;
  void menu()
{

    system("COLOR 0e");
    system("cls");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    printf_s("\n\n\n\t\t\t\t Looding");
    for (int j = 0; j < 10; j++)
    {
        printf_s(".");
        Sleep(10);
    }
    printf_s("\n\n\n\t\t\t\t");
    printf_s("\n\t\t\t\t This Work Was Creating By ");
    printf_s("\n\n\n\t\t\t\t");
    printf_s("\n\t\t\t\t    \t Alliche Amine Mohamed ");
    printf_s("\n\t\t\t\t Hello In Memoire Similateur Programme You Find 2 Methods {\t array of bits | Linked List\t} \n\n\t\t\t\t This Programme Make You had a similateur about 2 type of similateur first fit \n\n\t\t\t\t Enjoy");
    printf_s("\n\n\n\t\t\t\t");
    Sleep(4);
    for (int i = 0; i < 80; i++)
    {

        printf("%c", (char)bar2);
        Sleep(100);
    }
    system("COLOR 0e");
    printf_s("\n\n\n\t\t\t\t\n\n\n\t\t\t\t");
    system("pause");
    system("cls");
    system("COLOR 0F");
}
  void menu1()
{

    system("COLOR 08");
    system("cls");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    printf_s("\n\n\n\t\t\t\t Looding");
    for (int j = 0; j < 10; j++)
    {
        printf_s(".");
        Sleep(1);
    }
    printf_s("\n\n\n\t\t\t\t");
    printf_s("\n\n\n\t\t\t\t");
    //Sleep(4);
    for (int i = 0; i <25; i++)
    {
        printf("%c", (char)bar2);
        Sleep(20);
    }

    system("cls");
    system("COLOR 0F");
}

void gotoxy(int x, int y)
{
    COORD coord = {0, 0}; // this is global variable
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showfile(string name)
{

    system("cls");
    system("COLOR 07");
    std:: ifstream inputFile(name);
    int spaceCount = 0; // initialize a counter for spaces
    char currentChar; // variable to store the current character

    while (inputFile >> std::noskipws >> currentChar) { // read the file character by character
        std::cout << currentChar;
        if (currentChar ==' ') { // check if the current character is a space
           Sleep(secend); // if it is, increment the counter
        }else
        {
            Sleep(20);
        }
    }
    inputFile.close(); // close the file

    system("cls");
    system("COLOR 0F");
}
};
int main() {

    looding Menues;
    Menues.menu();
    system("cls");
    Zone_Memoire* head = NULL;
    linked_list * linked_circulaire = NULL;
  string name;
    int size_zone,j;
    bool occ_libre;
    bool exit_full_up_zone=1;
    int Allocational_unit;
    int i=0;
    Menues.menu1();
    system("cls");
    Menues.showfile("code.txt");
    Menues.gotoxy(10,15);
    system("cls");
    system("color a1");
    cout<<endl<<"|\t------------------------------------------------------------\t|"<<endl;
    cout<<endl<<"|\t\t give me  Allocational unit \t\t";cin>>Allocational_unit;
    cout<<endl<<"|\t------------------------------------------------------------\t|"<<endl;
    cout<<endl;
    system("color 0F");
 Menues.gotoxy(10,15);
    system("cls");
    while (exit_full_up_zone)
    {
        int choix;
        cout<<endl<<"\t\t 1-\t Add New Zone "<<endl<<"\t\t 2-\t Stop Add New Zones "<<endl<<"\t\t Give Me Your Choice :\t";cin>>choix;
        switch(choix){
        case 1:{
        cout<<endl<<"Give me Name Zone \t:\t";cin>>name;
        do{
        cout<<endl<<"Give me size Zone {\t|\t To Accept Value Of Size Of Proceess Must Be >= Allocational Unit \t"<<Allocational_unit<<"\t and can divise with here  \t|\t}\t:\t";cin>>size_zone;
        }while(!is_available_to_divide_with_allocational_unit(size_zone,Allocational_unit));

        cout<<endl<<"Give me if Your Zone Libre Or Occopy  {\t   if your zone occopy write 1 or your zone is libre write  0  \t} ";cin>>j;
        occ_libre = (j==1)?1:0;
        head=addatend(head,name,size_zone,occ_libre);

i = (i == 0) ? 0 : i + (size_zone / Allocational_unit);
        add_node(linked_circulaire, name, i, size_zone, occ_libre);
        break;
        }
        case 2:{exit_full_up_zone=false;break;}
        }
    }

    show_zone(head);
    Sleep(2000);
    int ar[sum_zones_allocation_unit(head,Allocational_unit)];
    array_bits(head,ar,Allocational_unit);
    //show_arryofbit(ar,Allocational_unit,(sum_zones(head)/Allocational_unit));

    // Read Pressecur

    string name_process;
    int time_came;
    int time_execute;
    int size_process;
    vector <Processus> processuses;
    Processus per;
    exit_full_up_zone=1;
     Menues.gotoxy(10,15);
    system("cls");
    while (exit_full_up_zone)
    {
        int choix;
        cout<<endl<<"\t\t 1-\t Add New Preseccus "<<endl<<"\t\t 2-\t Stop Add New Preseccus "<<endl<<"\t\t Give Me Your Choice :\t";cin>>choix;
        switch(choix){
        case 1:{
        cout<<endl<<"Give me Name Preseccus \t:\t";cin>>per.name_process;
        cout<<endl<<"Give me time came of Preseccus \t:\t";cin>>per.time_came;
        cout<<endl<<"Give me time exucute of Preseccus \t:\t";cin>>per.time_execute;
        do{
       cout<<endl<<"Give me size Pressecure {\t|\t To Accept Value Of Size Of Proceess Must Be >= Allocational Unit \t"<<Allocational_unit<<"\t and can divise with here  \t|\t}\t:\t";cin>>per.size_process;
        }while(!is_available_to_divide_with_allocational_unit(per.size_process,Allocational_unit));
        processuses.push_back(per);
        break;
        }
        case 2:{exit_full_up_zone=false;break;}
        }
    }
    // end reading pressusse
    tridecroisant(processuses);

    show_Preseccus(processuses);
Sleep(10);
/*
  */

 int n;
  Menues.gotoxy(10,15);
    system("cls");
   cout<<"1- USING ARRAY OF BITS \n 2- USING LINKED LIST \n 3- EXIT\n 4- GIVE CHTOX";cin>>n;
    switch(n){
         Menues.gotoxy(10,15);
    system("cls");
case 1:
    {
cout<<endl<<"before"<<endl;
int size =sum_zones_allocation_unit(head,Allocational_unit);
show_arryofbit(ar,Allocational_unit,sum_zones_allocation_unit(head,Allocational_unit));
first_fit_array(head,ar,size,Allocational_unit,processuses);
cout<<endl<<"After"<<endl;
show_arryofbit(ar,Allocational_unit,size);
        break;
    }
    case 2:{
cout<<endl<<"before"<<endl;
  show_linked(linked_circulaire);
  first_fit_linked_list(linked_circulaire,Allocational_unit,processuses);
cout<<endl<<"After"<<endl;
  show_linked(linked_circulaire);
    break;
    }
    case 3:{
         Menues.gotoxy(10,15);
    string s="Thanks Using My Code";
    for (int j=0;j<s.length();++j)
        Sleep(10);
exit(0);
    }
    }

    return 0;
}
