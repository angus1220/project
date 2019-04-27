void choice8(int timing[],int availability[],int queue[], int seatsavailable[], int customer_bill[],int seating_plan[],int &sitting_end,int &sitting_start, int &queue_start, int &queue_end){
  if (sitting_start==sitting_end){
    cout<<"No customers are in the restaurant"<<endl;
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
      cout<<"Customer code "<<which_table<<" is not in the restaurant"<<endl;
      cout<<"Please try again:"<<endl;
      cin>>which_table;
    }
    cout<<"Customer code "<<which_table<<" are sitting at Table "<<seating_plan[which_table-1]<<endl;
    seatsavailable[seating_plan[which_table-1]]+=queue[which_table-1];
    cout<<"Bill of customer code "<<which_table<<": $"<<customer_bill[which_table]<<endl;
    availability[which_table-1]=0;
    if(which_table==sitting_start+1){
      int i=0;
      while(availability[i]!=1){
        i++;
      }
      sitting_start=i;
    }
    if(timer()-timing[queue_start]>600){
      int tempor;
      tempor=queue_start;
      if (queue[tempor]<=seatsavailable[seating_plan[which_table-1]]){
        seatsavailable[seating_plan[which_table-1]]-=queue[tempor];
        availability[tempor]=1;
        seating_plan[tempor]=seating_plan[which_table-1];
        cout<<"Table "<<seating_plan[which_table-1]<<" is available for customer code "<<tempor+1<<endl;
        timing[tempor]=timer();
        sitting_end=tempor+1;
        }
      else{
        cout<<"No tables available for the queue"<<endl;
      }

    }
    else{
      int tempor;
      tempor=queue_start;
      while(tempor!=queue_end){
        if (queue[tempor]<=seatsavailable[seating_plan[which_table-1]]){
          seatsavailable[seating_plan[which_table-1]]-=queue[tempor];
          availability[tempor]=1;
          seating_plan[tempor]=seating_plan[which_table-1];
          cout<<"Table "<<seating_plan[which_table-1]+1<<" is available for customer code "<<tempor+1<<endl;
          timing[tempor]=timer();
          if (sitting_end<tempor+1){
            sitting_end=tempor+1;
          }
          break;
        }
        else{
          tempor+=1;
        }
      }
    }
  }
}
