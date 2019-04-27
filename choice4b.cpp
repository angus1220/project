void choice4b(int availability[], int tablenumber[],int timing[], int seating_plan[], int seatsavailable[], int queue[], int &sitting_end, int no_of_customers, int &queue_start, int &queue_end, int&indication){
  int indicator;
  indicator=queue_start;
  for(int i=0;i<seatsavailable[0];i++){
    if (queue[queue_end-1]<=seatsavailable[i+1]){
      seatsavailable[i+1]-=no_of_customers;
      cout<<"Table "<<i+1<<" is available"<<endl;
      indication=1;
      availability[queue_start]=1;
      seating_plan[queue_start]=i+1;
      timing[queue_start]=timer();
      queue_start++;
      sitting_end++;
      break;
    }
  }
  if (indicator==queue_start){
    cout<<"No tables are available at the moment"<<endl;
    timing[queue_end-1]=timer();
  }
}
