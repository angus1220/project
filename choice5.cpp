void choice5(int availability[], int timing[],int queue[],int queue_start, int queue_end){
  if(queue_start==queue_end){
    cout<<"No customers are in the queue"<<endl;
  }
  else{
    int indicator=0;
    for(int i=queue_start;i<queue_end;i++){
      if (availability[i]==0){
        int a=timer()-timing[i];
        if (a>=3600){
          if(indicator==0){
            cout<<"WARNING: The following customers have waited for over 15 minutes"<<endl;
            indicator=1;
          }
          cout<<"Customer code: "<<i+1<<" Number of customers: "<<queue[i]<<" Waited for: "<<a/3600<<" hrs "<<(a%3600)/60<<" mins "<<a%60<<" secs"<<endl;
        }
        else if(a<3600 and a>900){
          if(indicator==0){
            cout<<"WARNING: The following customers have waited for over 15 minutes"<<endl;
            indicator=1;
          }
          cout<<"Customer code: "<<i+1<<" Number of customers: "<<queue[i]<<" Waited for: "<<a/60<<" mins "<<a%60<<" secs"<<endl;
        }
        else if(a<=900 and a>=60){
          if (indicator==1){
            cout<<"************************************************************"<<endl;
            indicator=2;
          }
          cout<<"Customer code: "<<i+1<<" Number of customers: "<<queue[i]<<" Waited for: "<<a/60<<" mins "<<a%60<<" secs"<<endl;
        }
        else if(a<60){
          if (indicator==1){
            cout<<"************************************************************"<<endl;
            indicator=2;
          }
          cout<<"Customer code: "<<i+1<<" Number of customers: "<<queue[i]<<" Waited for: "<<a<<" secs"<<endl;
        }
      }
    }
  }
}
