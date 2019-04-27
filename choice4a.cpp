void choice4a(int tablenumber[],int queue[],int max_num_seats,int customercounter,int &indicator,int &no_of_customers){
  cout<<"Input the number of customers"<<endl;
  cout<<"(Please input a positive integer)"<<endl;
  cin>>no_of_customers;
  if(no_of_customers>max_num_seats){
    cout<<"Sorry, no tables are large enough"<<endl;
    cout<<"Please consider splitting tables and register again"<<endl;
    indicator=-1;
  }
  else{
    queue[customercounter]=no_of_customers;
  }
}
