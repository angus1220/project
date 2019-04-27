void choice3(int seatsavailable[], int tablenumber[]){
  int search;
  cout<<"Number of table to be checked:"<<endl;
  cout<<"(Please input a integer between 1 and "<<seatsavailable[0]<<")"<<endl;
  cin>>search;
  if (seatsavailable[search]==tablenumber[search]){
    cout<<"Table number "<<search<<" is available"<<endl;
    cout<<"There are "<<seatsavailable[search]<<"/"<<tablenumber[search]<<" seats left"<<endl;
  }
  else if(seatsavailable[search]<tablenumber[search] and seatsavailable[search]!=0){
    cout<<"Table number "<<search<<" is partly available"<<endl;
    cout<<"There are "<<seatsavailable[search]<<"/"<<tablenumber[search]<<" seats left"<<endl;
  }
  else if(seatsavailable[search]==0){
    cout<<"Table number "<<search<<" is not available"<<endl;
    cout<<"There are "<<seatsavailable[search]<<"/"<<tablenumber[search]<<" seats left"<<endl;
  }
}
