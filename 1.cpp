#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
void setup(int tableseats[], string dishnames[], int dishprices[]){
  int max_num_seats;
  int count=0;
  int num_seats;
  string restaurant_name;
  cout<<"Please enter restaurant name: ";
  cin>>restaurant_name;
  cout<<"Welcome to "<<restaurant_name<<endl;
  cout<<"------------TABLES SETTINGS------------"<<endl;
  cout<<"Enter the number of seats for the largest table: ";
  cin>>max_num_seats;
  for(int i=1;i<=max_num_seats;i++){
    cout<<"Please enter number of tables with "<<i<<" seats: ";
    cin>>num_seats;
    count+=num_seats;
    tableseats[i-1]=num_seats;}
  cout<<"-------------MENU SETTINGS-------------"<<endl;
  int dish_number;
  cout<<"Enter the number of dishes on your menu: ";
  cin>>dish_number;
  cout<<"Enter the dish name and the price one by one"<<endl;
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
  if (testing2==0){
    int max_num_seats;
    int count=0;
    int num_seats;
    string restaurant_name;
    cout<<"Please enter restaurant name: ";
    cin>>restaurant_name;
    cout<<"Welcome to "<<restaurant_name<<endl;
    cout<<"------------TABLES SETTINGS------------"<<endl;
    cout<<"Enter the number of seats for the largest table: ";
    cin>>max_num_seats;
    int*tableseats=new int[max_num_seats];
    for(int i=1;i<=max_num_seats;i++){
      cout<<"Please enter number of tables with "<<i<<" seats: ";
      cin>>num_seats;
      count+=num_seats;
      tableseats[i-1]=num_seats;}
    int*seatsavailable=new int[count];
    int*tablenumber=new int[count];
    int*availability=new int[count];
    for(int i=0;i<count;i++){
      availability[i]=0;
    }
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
      k+=tableseats[i+2];
    }
    for(int i=0;i<count;i++){
      cout<<seatsavailable[i]<<endl;
    }
    cout<<"-------------MENU SETTINGS-------------"<<endl;
    int dish_number;
    cout<<"Enter the number of dishes on your menu: ";
    cin>>dish_number;
    string*dishnames=new string[dish_number];
    int*dishprices=new int[dish_number];
    cout<<"Enter the dish name and the price one by one"<<endl;
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
    for(int i=0;i<dish_number;i++){
      cout<<dishprices[i];
      cout<<dishnames[i]<<endl;
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
  }
  fin.open("dishprices.txt",ios::in);
  int dishpricelen;
  fin>>dishpricelen;
  int*dishprices=new int[dishpricelen];
  for(int i=1;i<stoi(to_string(dishpricelen))+1;i++){
    fin>>dishprices[i];
  }
  fin.close();
  for(int i=1;i<stoi(to_string(dishpricelen))+1;i++){
    cout<<dishprices[i];
  }
  cout<<"5678";
  fin.open("dishnames.txt",ios::in);
  int dishnamelen;
  fin>>dishnamelen;
  string*dishnames=new string[dishnamelen];
  for(int i=1;i<stoi(to_string(dishnamelen))+1;i++){
    fin>>dishnames[i];
  }
  fin.close();
  for(int i=1;i<stoi(to_string(dishpricelen))+1;i++){
    cout<<dishnames[i];
  }
  fin.open("tableseats.txt",ios::in);
  int tablelen;
  fin>>tablelen;
  int*tableseats=new int[tablelen];
  for(int i=1;i<stoi(to_string(tablelen))+1;i++){
    fin>>tableseats[i];
  }
  fin.close();
  for(int i=1;i<stoi(to_string(tablelen))+1;i++){
    cout<<tableseats[i];
  cout<<"----FIRST TIME USER SETUP COMPLETE----"<<endl;
  int choice;
  while(choice!=6){
    cout<<"Please enter command code (1-6)"<<endl;
    cout<<"1. Change user-setup(tables/menu)"<<endl;
    cout<<"2. Check availability of table"<<endl;
    cout<<"3. Register new customers"<<endl;
    cout<<"4. Recieve payment and release table"<<endl;
    cout<<"5. Taking orders from customer"<<endl;
    cout<<"6. Close the restaurant(Terminate program)"<<endl;
    cin>>choice;
    if(choice==1){
      setup(tableseats, dishnames, dishprices);
    }
    if(choice==2){
      cout<<"haa"<<endl;
    }
  }
  cout<<"Thanks for using this program"<<endl;
  cout<<"The tables and menu settings are saved"<<endl;
  cout<<"They will be available when this program is run next time"<<endl;
  return 0;
}
}
