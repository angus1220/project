#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
void choice2(int wow[], int tablenumber[]){
  for(int i=0;i<wow[0];i++){
    cout<<"Table "<<i+1<<": "<<tablenumber[i+1]<<" seats     "<<wow[i+1]<<"/"<<tablenumber[i+1]<<endl;
  }

}
