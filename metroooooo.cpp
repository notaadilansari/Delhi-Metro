#include <iostream>
#include <string>
using namespace std;

class metro{
    public:
        string fstation,lstation;
        int findex=-1,lindex=-1;
        float dis=0;
        float time=0;
        int fare=0;
        string station[26]={"Krishna Park Ext.","Janakpuri West","Dabri Mor","Dashrathpuri","Palam","Sadar Bazar Cantonment","Terminal 1 IGI Airport","Shankar Vihar","Vasant Vihar","Munirka","R.K. Puram","IIT Delhi","Hauz Khas","Panchsheel Park","Chirag Delhi","Greater Kailash","Nehru Enclave","Kalkaji Mandir","Okhla NSIC","Sukhdev Vihar","Jamia Millia Islamia","Okhla Vihar","Jasola Apollo","Kalindi Kunj","Okhla Bird Sanctuary","Botanical Garden"};
        float distance[25]={5.5,1.5,1.2,1.4,1.3,1.6,1.4,1.2,1.1,1.0,1.2,1.3,1.1,1.2,1.0,1.1,1.0,1.3,1.2,1.1,1.0,1.2,1.4,1.5,2.0};
        void getdata();
        void getdistance();
        void getfare();
        void gettime();
};

void metro::getdata(){
    cout<<endl;
    cout<<"Which way you wanna select station?"<<endl;
    cout<<"1.By number "<<endl<<"2.By station name "<<endl;
    int userchoice;
    cout<<"Enter your choice(1-2) - ";
    cin>>userchoice;
    if (userchoice==2)
    {
        cin.ignore();
        cout<<"Enter your first station name - ";
        getline(cin, fstation);
        cout<<"Enter your second station name - ";
        getline(cin, lstation);
    }
    else if (userchoice==1)
    {
        cout<<"Enter your first station number - ";
        cin>>findex;
        cout<<"Enter your second station number - ";
        cin>>lindex;
    }
    
}

void metro::getdistance(){
    
    if (findex!=-1&&lindex!=-1)
    {
        findex--;
        lindex--;
    }
    
    for (int i = 0; i < sizeof(station)/sizeof(station[0]); i++)
    {
        if (fstation==station[i])
        {
            findex=i;
        }
        if (lstation==station[i])
        {
            lindex=i;
        }

    }
    if (findex==-1&&lindex==-1)
    {
        cout<<endl;
        cout<<"========================================="<<endl;
        cout<<"No such Station found in magenta line!!"<<endl;
        cout<<"exiting...."<<endl;
        exit(0);
    }
    
    if (findex!=-1&&lindex!=-1)
    {
        if (findex>lindex)
        {
            swap(findex,lindex);
        }
        
        for (int i = findex; i < lindex; i++)
        {
            dis=dis+distance[i];
        }
    }
    
}

void metro::getfare(){
    if (dis<=2) fare = 11;
    else if (dis<=5) fare = 21;
    else if (dis<=12) fare = 32;
    else if (dis<=21) fare = 43;
    else if (dis<=32) fare = 54;
    else fare = 64;
}

void metro::gettime(){
    time=(dis/32)*60;
}

int main(){
    cout << "=========================================" << endl<<endl;
    cout<<"           WELCOME TO DELHI METRO           "<<endl<<endl;
    cout << "=========================================" << endl<<endl;
    cout<<"Station Name (Magenta line only) : "<<endl;
    metro user;
    for (int i = 0; i < sizeof(user.station)/sizeof(user.station[0]); i++)
    {
        cout<<"\t"<<i+1<<"."<<user.station[i]<<endl;
    }
    // cin.ignore();
    string userchoice;
    while(true){
    cout<<"Do you want to exit?(yes/no or y/n) - ";
    cin>>userchoice;
    if (userchoice=="yes"||userchoice=="y"||userchoice=="Yes")
    {
        cout<<endl;
            cout << "=========================================" << endl<<endl;
            cout << "     Thanks for using delhi metro !!"<<endl<<endl;
            cout << "=========================================" << endl<<endl;
            cout<<"Exiting...."<<endl;
            exit(0);
        
    }
    else{
        user.getdata();
        user.getdistance();
        user.getfare();
        user.gettime();
        cout<<endl;
        if (user.findex!=-1&&user.lindex!=-1)
        {
            cout<<"the distance between "<<user.station[user.findex]<<" and "<<user.station[user.lindex]<<" is "<<user.dis<<"km"<<endl;
        }
        else{
        cout<<"The distance between "<<user.fstation<<" and "<<user.lstation<<" is "<<user.dis<<"km"<<endl;
        }
        cout<<"The fare is - "<<user.fare<<"Rs"<<endl;
        cout<<"The time it will take is "<<user.time<<"minutes"<<endl;
        user.dis=0;
    }
}
    return 0;
}