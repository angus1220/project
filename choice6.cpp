int choice6(int availability[], int seating_plan[],int sitting_end,int sitting_start){
  if (sitting_start==sitting_end){
    cout<<"No customers are in the restaurant"<<endl;
    return 0;
  }
  else{
  int which_table;
    cout<<"Enter the customer code you want to search"<<endl;
    if(sitting_start+1==sitting_end){
      cout<<"(Please enter "<<sitting_start+1<<" as it is the only customer now)"<<endl;
    }
    else{
      cout<<"(Please enter a positive integer from "<<sitting_start+1<<" to "<<sitting_end<<")"<<endl;
    }
    cin>>which_table;
    while (availability[which_table-1]==0){
      cout<<"Customer code "<<which_table<<"is not in the restaurant"<<endl;
      cout<<"Please try again:"<<endl;
      cin>>which_table;
    }
    cout<<"Customer code "<<which_table<<" are sitting at Table "<<seating_plan[which_table-1]<<endl;
    return seating_plan[which_table-1];
  }
}
