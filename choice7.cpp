#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
void choice7(int availability[], string dishnames[], int dishprices[], int customer_bill[], int sitting_start, int sitting_end){
  if (sitting_start==sitting_end){
    cout<<"No customers are in the restaurant"<<endl;
  }
  else{
    int code;
    int order;
    cout<<"Enter the customer code"<<endl;
    if(sitting_start+1==sitting_end){
      cout<<"(Please enter "<<sitting_start+1<<" as it is the only customer now)"<<endl;
    }
    else{
      cout<<"Please enter a positive integer (from "<<sitting_start+1<<" to "<<sitting_end<<")"<<endl;
    }
    cin>>code;
    while (availability[code-1]==0){
      cout<<"Customer code "<<code<<"is not in the restaurant"<<endl;
      cout<<"Please try again:"<<endl;
      cin>>code;
    }
    for(int i=1;i<dishprices[0]+1;i++){
      cout<<i<<". "<<dishnames[i]<<" $"<<dishprices[i]<<endl;
    }
    cout<<"INPUT INSTRUCTIONS"<<endl;
    cout<<"Input the dish code(1-"<<dishprices[0]<<") to order the dish"<<endl;
    cout<<"Input -1 to finish ordering"<<endl;
    cin>>order;
    while(order!= -1){
      customer_bill[code]+=dishprices[order];
      cin>>order;
    }
    cout<<"Total: $"<<customer_bill[code]<<endl;
  }
}
