#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
void choice9(string dishnames[],int dishprices[]){
  for(int i=1;i<dishprices[0]+1;i++){
    cout<<i<<". "<<dishnames[i]<<" $"<<dishprices[i]<<endl;
  }
}
