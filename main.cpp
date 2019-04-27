#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
void choice8(int timing[],int availability[],int queue[], int seatsavailable[], int customer_bill[],int seating_plan[],int &sitting_end,int &sitting_start, int &queue_start, int &queue_end);
void choice7(int availability[], string dishnames[], int dishprices[], int customer_bill[], int sitting_start, int sitting_end);
int choice6(int availability[], int seating_plan[],int sitting_end,int sitting_start);
void choice5(int availability[], int timing[],int queue[],int queue_start, int queue_end);
void choice4b(int availability[], int tablenumber[],int timing[], int seating_plan[], int seatsavailable[], int queue[], int &sitting_end, int no_of_customers, int &queue_start, int &queue_end, int&indication);
void choice4a(int tablenumber[],int queue[],int max_num_seats,int customercounter,int &indicator,int &no_of_customers);
void choice3(int seatsavailable[], int tablenumber[]);
void choice2(int wow[], int tablenumber[]);
  cout<<"Input the number of customers"<<endl;
int timer(){
  time_t current_time;
	current_time = time(NULL);
	tm *local = localtime(&current_time);
  return (3600*(local->tm_hour)+60*(local->tm_min)+local->tm_sec);
}
void choice10(int timing[], int availability[], int sitting_start, int sitting_end){
  for (int i=sitting_start+1;i<sitting_end+1;i++){
    if(availability[i]==1 and timer()-timing[i]>3600){
      cout<<"Customer code "<<i<<" has been in the restaurant for over 1 hour";
    }
  }
}
void choice9(string dishnames[],int dishprices[]){
  for(int i=1;i<dishprices[0]+1;i++){
    cout<<i<<". "<<dishnames[i]<<" $"<<dishprices[i]<<endl;
  }
}
void choice1(int tableseats[], string dishnames[], int dishprices[], int seatsavailable[], int tablenumber[]){
  int max_num_seats;
  int count=0;
  int num_seats;
  string restaurant_name;
  cout<<"Please enter restaurant name: ";
  cin>>restaurant_name;
  cout<<"Welcome to "<<restaurant_name<<endl;
  cout<<"------------TABLES SETTINGS------------"<<endl;
  cout<<"Enter the number of seats for the largest table: "<<endl;
  cout<<"(Please input a positive integer)"<<endl;
  cin>>max_num_seats;
  for(int i=1;i<=max_num_seats;i++){
    cout<<"Please enter the number of tables with "<<i<<" seats: "<<endl;
    cout<<"(Please input a positive integer)"<<endl;
    cin>>num_seats;
    count+=num_seats;
    tableseats[i-1]=num_seats;}
  for(int i=0;i<tableseats[0];i++){
    seatsavailable[i]=1;
    tablenumber[i]=1;
  }
  int a=tableseats[0];
  int k=tableseats[0]+tableseats[1];
  for(int i=0;i<max_num_seats-1;i++){
    for(int j=a;j<k;j++){
      seatsavailable[j]=i+2;
      tablenumber[j]=i+2;
    }
    a=k;
    k+=tableseats[i+2];}
  for(int i=0;i<count;i++){
    cout<<"Table "<<i+1<<": "<<seatsavailable[i]<<" seats"<<endl;
  }
  for(int i=0;i<seatsavailable[0];i++){
    int temp;
    temp=seatsavailable[i];
    tablenumber[i]=temp;

  }
  cout<<"-------------MENU SETTINGS-------------"<<endl;
  int dish_number;
  cout<<"Enter the number of dishes on your menu: "<<endl;
  cout<<"(Please input a positive integer)"<<endl;
  cin>>dish_number;
  cout<<"INPUT INSTRUCTIONS"<<endl;
  cout<<"Enter the dish names and their relative prices one by one"<<endl;
  cout<<"For dishes with spaces, please replace with underscores"<<endl;
  cout<<"Example: Lemonade 10"<<endl;
  cout<<"Example: Apple_Juice 10"<<endl;
  for(int i=0;i<dish_number;i++){
    string dishname;
    int dishprice;
    cin>>dishname;
    cin>>dishprice;
    dishnames[i]=dishname;
    dishprices[i]=dishprice;
  }
  ofstream fout;
  fout.open("dishprices.txt",ios::out);
  fout<<dish_number<<" ";
  for(int i=0;i<dish_number;i++){
    fout<<dishprices[i]<<" ";
  }
  fout.close();
  fout.open("dishnames.txt",ios::out);
  fout<<dish_number<<" ";
  for(int i=0;i<dish_number;i++){
    fout<<dishnames[i]<<" ";
  }
  fout.close();
  fout.open("tableseats.txt",ios::out);
  fout<<max_num_seats<<" ";
  for(int i=0;i<max_num_seats;i++){
    fout<<tableseats[i]<<" ";
  }
  fout.close();
  fout.open("seatsavailable.txt",ios::out);
  fout<<count<<" ";
  for(int i=0;i<count;i++){
    fout<<seatsavailable[i]<<" ";
  }
  fout.close();
  fout.open("tablenumber.txt",ios::out);
  fout<<count<<" ";
  for(int i=0;i<count;i++){
    fout<<tablenumber[i]<<" ";
  }
  fout.close();
  cout<<"*";
  ifstream fin;
  fin.open("dishprices.txt",ios::in);
  int dishpricelen;
  fin>>dishpricelen;
  dishprices[0]=dishpricelen;
  for(int i=1;i<stoi(to_string(dishpricelen))+1;i++){
    fin>>dishprices[i];
  }
  fin.close();
  fin.open("dishnames.txt",ios::in);
  int dishnamelen;
  fin>>dishnamelen;
  dishnames[0]=dishnamelen;
  for(int i=1;i<stoi(to_string(dishnamelen))+1;i++){
    fin>>dishnames[i];
  }
  fin.close();
  fin.open("tableseats.txt",ios::in);
  int tablelen;
  fin>>tablelen;
  tableseats[0]=tablelen;
  for(int i=1;i<stoi(to_string(tablelen))+1;i++){
    fin>>tableseats[i];
  }
  fin.close();
  fin.open("seatsavailable.txt",ios::in);
  int seatsavailablelen;
  fin>>seatsavailablelen;
  seatsavailable[0]=seatsavailablelen;
  for(int i=1;i<stoi(to_string(seatsavailablelen))+1;i++){
    fin>>seatsavailable[i];
  }
  fin.close();
  fin.open("tablenumber.txt",ios::in);
  int tablenumberlen;
  fin>>tablenumberlen;
  tablenumber[0]=tablenumberlen;
  for(int i=1;i<stoi(to_string(tablenumberlen))+1;i++){
    fin>>tablenumber[i];
  }
  fin.close();
}
int main(){
  string testing;
  int testing2=0;
  ifstream fin;
  fin.open("dishprices.txt");
  while(getline(fin,testing)){
    testing2++;
  }
  fin.close();
  int max_num_seats;
  int count=0;
  int num_seats;
  string restaurant_name;
  if (testing2==0){
    cout<<"Please enter restaurant name: ";
    cin>>restaurant_name;
    cout<<"Welcome to "<<restaurant_name<<endl;
    cout<<"------------TABLES SETTINGS------------"<<endl;
    cout<<"Enter the number of seats for the largest table: "<<endl;
    cout<<"(Please input a positive integer)"<<endl;
    cin>>max_num_seats;
    int*tableseats=new int[max_num_seats];
    for(int i=1;i<=max_num_seats;i++){
      cout<<"Please enter the number of tables with "<<i<<" seats: "<<endl;
      cout<<"(Please input a positive integer)"<<endl;
      cin>>num_seats;
      count+=num_seats;
      tableseats[i-1]=num_seats;}
    int*seatsavailable=new int[count];
    int*tablenumber=new int[count];
    for(int i=0;i<tableseats[0];i++){
      seatsavailable[i]=1;
      tablenumber[i]=1;
    }
    int a=tableseats[0];
    int k=tableseats[0]+tableseats[1];
    for(int i=0;i<max_num_seats-1;i++){
      for(int j=a;j<k;j++){
        seatsavailable[j]=i+2;
        tablenumber[j]=i+2;
      }
      a=k;
      k+=tableseats[i+2];}
    for(int i=0;i<count;i++){
      cout<<"Table "<<i+1<<": "<<tablenumber[i]<<" seats"<<endl;
    }
    cout<<"-------------MENU SETTINGS-------------"<<endl;
    int dish_number;
    cout<<"Enter the number of dishes on your menu: "<<endl;
    cout<<"(Please input a positive integer)"<<endl;
    cin>>dish_number;
    string*dishnames=new string[dish_number];
    int*dishprices=new int[dish_number];
    cout<<"INPUT INSTRUCTIONS"<<endl;
    cout<<"Enter the dish names and their relative prices one by one"<<endl;
    cout<<"For dishes with spaces, please replace with underscores"<<endl;
    cout<<"Example: Lemonade 10"<<endl;
    cout<<"Example: Apple_Juice 10"<<endl;
    for(int i=0;i<dish_number;i++){
      string dishname;
      int dishprice;
      cin>>dishname;
      cin>>dishprice;
      dishnames[i]=dishname;
      dishprices[i]=dishprice;
    }
    ofstream fout;
    fout.open("dishprices.txt",ios::out);
    fout<<dish_number<<" ";
    for(int i=0;i<dish_number;i++){
      fout<<dishprices[i]<<" ";
    }
    fout.close();
    fout.open("dishnames.txt",ios::out);
    fout<<dish_number<<" ";
    for(int i=0;i<dish_number;i++){
      fout<<dishnames[i]<<" ";
    }
    fout.close();
    fout.open("tableseats.txt",ios::out);
    fout<<max_num_seats<<" ";
    for(int i=0;i<max_num_seats;i++){
      fout<<tableseats[i]<<" ";
    }
    fout.close();
    fout.open("seatsavailable.txt",ios::out);
    fout<<count<<" ";
    for(int i=0;i<count;i++){
      fout<<seatsavailable[i]<<" ";
    }
    fout.close();
    fout.open("tablenumber.txt",ios::out);
    fout<<count<<" ";
    for(int i=0;i<count;i++){
      fout<<tablenumber[i]<<" ";
    }
    fout.close();
  }
  fin.open("dishprices.txt",ios::in);
  int dishpricelen;
  fin>>dishpricelen;
  int*dishprices=new int[dishpricelen];
  dishprices[0]=dishpricelen;
  for(int i=1;i<stoi(to_string(dishpricelen))+1;i++){
    fin>>dishprices[i];
  }
  fin.close();
  fin.open("dishnames.txt",ios::in);
  int dishnamelen;
  fin>>dishnamelen;
  string*dishnames=new string[dishnamelen];
  dishnames[0]=dishnamelen;
  for(int i=1;i<stoi(to_string(dishnamelen))+1;i++){
    fin>>dishnames[i];
  }
  fin.close();
  fin.open("tableseats.txt",ios::in);
  int tablelen;
  fin>>tablelen;
  int*tableseats=new int[tablelen];
  tableseats[0]=tablelen;
  for(int i=1;i<stoi(to_string(tablelen))+1;i++){
    fin>>tableseats[i];
  }
  fin.close();
  fin.open("seatsavailable.txt",ios::in);
  int seatsavailablelen;
  fin>>seatsavailablelen;
  int*seatsavailable=new int[seatsavailablelen];
  seatsavailable[0]=seatsavailablelen;
  for(int i=1;i<stoi(to_string(seatsavailablelen))+1;i++){
    fin>>seatsavailable[i];
  }
  fin.close();
  fin.open("tablenumber.txt",ios::in);
  int tablenumberlen;
  fin>>tablenumberlen;
  int*tablenumber=new int[tablenumberlen];
  tablenumber[0]=tablenumberlen;
  for(int i=1;i<stoi(to_string(tablenumberlen))+1;i++){
    fin>>tablenumber[i];
  }
  fin.close();
  cout<<"----FIRST TIME USER SETUP COMPLETE----"<<endl;
  int choice;
  int customer_counter=0;
  int customer_bill[999]={};
  int queue[999]={};
  int seating_plan[999]={};
  int timing[999]={};
  int availability[999]={};
  int sitting_start=0;
  int sitting_end=0;
  int queue_start=0;
  int queue_end=0;
  while(choice!=11){
    cout<<"************************************************************"<<endl;
    cout<<"Please enter command code (1-11)"<<endl;
    cout<<"1. Change user-setup(tables/menu)"<<endl;
    cout<<"2. Check table information"<<endl;
    cout<<"3. Check availability of table"<<endl;
    cout<<"4. Register new customers"<<endl;
    cout<<"5. Check queue"<<endl;
    cout<<"6. Check seating plan"<<endl;
    cout<<"7. Taking orders from customers"<<endl;
    cout<<"8. Receive payment and release table"<<endl;
    cout<<"9. Look at menu"<<endl;
    cout<<"10. Check for tables occupied for over one hour"<<endl;
    cout<<"11. Close the restaurant(Terminate program)"<<endl;
    cin>>choice;
    if(choice==1){
      choice1(tableseats, dishnames, dishprices,seatsavailable,tablenumber);
      for (int i=0;i<1000;i++){
        timing[i]=0;
        customer_bill[i]=0;
        queue[i]=0;
        seating_plan[i]=0;
        timing[i]=0;
        availability[i]=0;
      }
      customer_counter=0;
      queue_start=0;
      queue_end=0;
      sitting_start=0;
      sitting_end=0;
    }
    if(choice==2){
      choice2(seatsavailable,tablenumber);
    }
    if(choice==3){
      choice3(seatsavailable,tablenumber);
    }
    if(choice==4){
      int no_of_customers;
      int max_seats;
      int indicator=0;
      max_seats=tableseats[0];
      choice4a(tablenumber,queue,max_seats,customer_counter,indicator,no_of_customers);
      if(indicator==0){
        customer_counter++;
        queue_end++;
        int indication=0;
        choice4b(availability,tablenumber,timing,seating_plan,seatsavailable,queue,sitting_end,no_of_customers,queue_start,queue_end,indication);
        if(indication==1){
          timing[queue_start]=timer();
        }
      }
    }
    if(choice==5){
      choice5(availability,timing,queue,queue_start,queue_end);
    }
    if(choice==6){
      int ans;
      ans=choice6(availability,seating_plan,sitting_end,sitting_start);
    }
    if(choice==7){
      choice7(availability,dishnames,dishprices,customer_bill,sitting_start,sitting_end);
    }
    if(choice==8){
      choice8(timing,availability,queue,seatsavailable,customer_bill,seating_plan,sitting_end,sitting_start,queue_start,queue_end);
    }
    if(choice==9){
      choice9(dishnames,dishprices);
    }
    if(choice==10){
      choice10(timing,availability,sitting_start,sitting_end);
    }
  }
  cout<<"************************************************************"<<endl;
  cout<<"Thank you for using this program"<<endl;
  cout<<"The tables and menu settings are saved"<<endl;
  cout<<"They will be available when this program is run next time"<<endl;
  cout<<"************************************************************"<<endl;
  return 0;
}
