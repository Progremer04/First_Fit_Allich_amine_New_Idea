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

// For Zone Memoire
// Struct name should start with a capital letter
struct Zone_Memoire {
    string Name_Zone;
    int size_zone;
    int oc_lib;
    Zone_Memoire *next;
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

int sum_zones(Zone_Memoire*zone){
    return (zone==NULL)? 0: zone->size_zone+sum_zones(zone->next);
}
int sum_zones_allocation_unit(Zone_Memoire*zone,int Allocational_unit){
    return (zone==NULL)? 0: ((zone->size_zone/Allocational_unit)+sum_zones_allocation_unit(zone->next,Allocational_unit));
}

void show_zone(Zone_Memoire* head) {
    // Fix the while loop condition, replace !zone with zone!=NULL
    if (head == NULL) {
        cout<<"\n OOPS! Zone Is Vide \n";
    } else {
        Zone_Memoire* zone = head;
        while (zone != NULL) {
            cout << "Name Of Zone " << "\tSize of Zone ";
 (zone->oc_lib==0)?cout<<"\t\t is Libre":cout<<"\t\t is Occupee";
            cout << endl << "\t" << zone->Name_Zone << "\t" << zone->size_zone <<"\t KO"<<endl;
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

/*
seme code
bool is_available_to_divide_with_allocational_unit(int size, int allocational_unit) {
    if ((size % allocational_unit == 0) && (size >= allocational_unit)) {
        return true;
    } else if (!((size % allocational_unit == 0) && (size >= allocational_unit))) {
            return false;
        }
    }
*/
bool is_available_to_divide_with_allocational_unit(int size, int allocational_unit) {
    return ((size % allocational_unit == 0) && (size >= allocational_unit)) ? true : (!((size % allocational_unit == 0) && (size >= allocational_unit)) ? false : false);
}
// creat table de bit
// this function using for table de bits
// we gonna using linked list to creat
void Init_Table(int arrayes[],int sizes,int value){ fill(arrayes,arrayes + sizes,value);}
void reversearray(int e[],int size)
{
    int array1[size];int i=size-1,j=0;
    while(i>=0){
            array1[j]=e[i];
        --i;
        ++j;
    }
    Init_Table(e,size,0);
    for (i=0;i<size;++i) e[i]=array1[i];

    }
// show array of array of bit
void show_arryofbit(int array[],int Allocational_unit,int size)
{
    reversearray(array,size);
    int j;
    for (int i=0;i<size;++i){
        cout<<endl<<"\t"<<i+1<<"\t \t"<<array[i];
    if ((i+1) % Allocational_unit == 0){cout<<endl;j=i;}
    }
}
void show_Preseccus(vector <Processus> array) {
    cout << "Name Of Preseccus " << "\t\tTime came " << "\t\t Time execution" << "\t\tSize of Preseccus ";

    for (Processus p : array){
            cout << endl << "\t" << p.name_process << "\t\t\t" << p.time_came << "\t\t\t" << p.time_execute << "\t\t\t\t" << p.size_process <<"  KO"<<endl;

        }
    }
void array_bits(Zone_Memoire*zone,int arrays[],int Allocational_unit){
    int sizes=sum_zones_allocation_unit(zone,Allocational_unit);
    if (zone!=NULL)
    {
        while(zone!=NULL)
        {
            sizes-=(zone->size_zone/Allocational_unit);
            Init_Table(arrays + sizes,(zone->size_zone/Allocational_unit),1);
            zone=zone->next;
        }
    }
}
//  tri vectors
auto compair(Processus p1,Processus p2)
{
    return (p1.time_came<p2.time_came)? true:false;
}
void tridecroisant(vector <Processus>& processuses)
{
    sort(processuses.begin(),processuses.end(),compair);
}
void first_fit_array(Zone_Memoire* zone, int array[], int size, int Allocational_unit, vector <Processus>& processuses)
{
    array_bits(zone, array, Allocational_unit);
    Init_Table(array, sum_zones_allocation_unit(zone,Allocational_unit), 0);
    reversearray(array, size);
    tridecroisant(processuses);
    Zone_Memoire* zone1=NULL;
if (!processuses.empty()){
    for (Processus p : processuses) {
        zone1 = zone;
        bool trouve = false;
        while (zone1 != NULL && !trouve) {
            int n1 = zone1->size_zone / Allocational_unit;
            int n2 = p.size_process / Allocational_unit;
            if (n1 >= n2 && zone1->oc_lib == 0) {
                Init_Table(array + (zone1->size_zone / Allocational_unit) - n2, n2,0);
                trouve = true;
                zone1->size_zone-=(n2*Allocational_unit);
                cout << endl << p.name_process << " is working "<<endl;
for (int i = 0; i < p.time_execute; ++i) {
cout << "\r ...";
Sleep(1);
            }
                cout<<endl;
        }
            zone1 = zone1->next;
    }
    if (!trouve) cout<<endl<<"\t    Presseccus    \t"<<p.name_process<<"didn'twork oops!"<<endl;
}
}
}
int main() {
    Zone_Memoire* head = NULL;
    // Parties To Add Zone For similator First Fit
/*

Color_id	Color	        Color_id  Color
1	        Blue	        9	      Light Blue
2	        Green	        0         Black
3	        Aqua	        A	      Light Green
4	        Red	            B	      Light Aqua
5	        Purple	        C	      Light Red
6	        Yellow	        D	      Light Purple
7	        White	        E	      Light Yellow
8	        Gray	        F	      Bright White
*/
    string name;
    int size_zone,j;
    bool occ_libre;
    bool exit_full_up_zone=1;
    int Allocational_unit;

    system("color a1");
    cout<<endl<<"|\t------------------------------------------------------------\t|"<<endl;
    cout<<endl<<"|\t\t give me  Allocational unit \t\t";cin>>Allocational_unit;
    cout<<endl<<"|\t------------------------------------------------------------\t|"<<endl;
    cout<<endl;
    system("color 0F");

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
        break;
        }
        case 2:{exit_full_up_zone=false;break;}
        }
    }
    show_zone(head);
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


cout<<endl<<"before"<<endl;
int size =sum_zones_allocation_unit(head,Allocational_unit);
show_arryofbit(ar,Allocational_unit,sum_zones_allocation_unit(head,Allocational_unit));
first_fit_array(head,ar,size,Allocational_unit,processuses);
cout<<endl<<"After"<<endl;
show_arryofbit(ar,Allocational_unit,size);
    return 0;
}
