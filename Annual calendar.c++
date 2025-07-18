#include <iostream>
#include <iomanip>
using namespace std;
// The isLeapYear function determines whether the year is a leap year or not.
bool isLeapYear(int year){
    return ((year % 4 == 0 && year % 100 !=0 )||year % 400 == 0 ) ;
}
// The getMonthDays function determines the number of days in each month.
int getMonthDays(int month, int year){
    if(month == 1)return isLeapYear(year)?  29 : 28 ;
    else if(month == 3 || month == 5 || month == 8 || month == 10 )return 30 ;
    else return 31 ;
}
//The showCalendar function prints each month with its dates.
void showCalendar(int year){
    string months[12] = {"January" , "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
        
    string days[7] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};
    
    int startDay = 0;
    
    for(int m = 0 ; m < 12 ; m++){
        cout<<" \n " <<months[m] <<" "<< year << " \n " ;
    
    
    for(int d = 0 ; d < 7 ; d++){
        cout<<setw(5) << days [d] ;
    }
    
    cout<<endl;
    int daysInMonth = getMonthDays(m, year);
    
    for(int i = 0 ; i <startDay ; i++){
        cout<<setw(5) << " ";
    }
    
    for(int date = 1 ; date <=daysInMonth ; date++){
        cout<< setw(5) << date ;
        if((startDay + date) % 7 == 0) cout<<endl;
    }
    
    startDay = (startDay + daysInMonth )% 7 ;
    
    cout<<" \n ";
   }
    
}
//The Determinetheday function determines the first day of each month.
int Determinetheday( int num){
    if(num == 1 || num == 2 ||  num == 10)return 3 ;
    else if(num == 0 || num == 9 )return 0 ;
    else if(num == 3 || num == 6)return 6 ;
    else if(num == 7 )return 2 ;
    else if(num == 8 || num == 11)return 5 ;
    else if( num == 4)return 1;
    else return 4 ;
}
//The Searchforamonth function prints the month specified by the user.
void Searchforamonth( int year){
     int num ;
     cout<<"Search betrayed "<<endl;
    do{
     cout<<"Enter the number of the month you are searching for : ";
     cin>>num ;
     
     string months[12] = {"January" , "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
        
     string days[7] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};
     
     int startDay = Determinetheday(num );//3
     if(num >11|| num < 0)break ;
     if(num <= 11){
     
         cout<<" \n " <<months[num] <<" " << year << endl;
       
       for(int d = 0 ; d < 7 ; d++){
           cout<<setw(5)<<days[d] ;
       }
       cout<<endl;
       int daysInMonth = getMonthDays(num,year);
       for(int i = 0 ; i < startDay ; i++){
           cout<<setw(5)<<" ";
       }
       
       for(int date = 1 ; date <=daysInMonth ; date++){
           cout<<setw(5) <<date ;
           if((startDay + date)% 7==0)cout<<endl;
       }
       cout<<endl;
    }
        
  }while(true);
} 
//The NumberOfDaysintheMonth function prints the number of days in each month.
void NumberOfDaysintheMonth(int month , int year){
     string months[12] = {"January" , "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
        
     string days[7] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};
     
     for(int m = 0 ; m < 12 ; m++){
         cout<<months[m] <<" : ";
         cout<<getMonthDays( m,  year)<<" days "<<endl;
     }
     
}
//The Dayswithweeks function prints each month with its weeks.
void Dayswithweeks(  int year){
    string months[12] = {"January" , "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
        
    string days[7] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};

    int startDay = 0;
    
    for(int m = 0 ; m < 12 ; m++){
        int w = 2 ;
        cout<<"\n" <<months[m] <<" "<<year <<endl; 
            cout<<setw(20) <<" week: 1 " <<endl;
            for(int d = 0 ; d < 7 ; d++){
                cout<<setw(5) <<days[d] ; 
            }
            cout<<endl;
            
            for(int i = 0 ; i <startDay ; i++){
                cout<<setw(5)<<" ";
            }
            int daysInMonth = getMonthDays(m, year);
            
            for(int date = 1 ; date<=daysInMonth ; date++){
                cout<<setw(5)<<date ;
                if((startDay + date)%7==0){
                    cout<<endl;
                    if(date != daysInMonth){
                    cout<<setw(20) <<"week: " <<w <<endl;
                     w++;
                    }
                }
            }
        
        startDay = (startDay + daysInMonth) %7 ;
        cout<<endl;
    }
}
//The NumberOfWeeks function determines the number of weeks in each month.
int NumberOfWeeks(int month , int year , int startDay){
    int days = getMonthDays(month , year);
    return(startDay + days + 6)/7 ;
}
//The NumberOfWeeksInEachMonth function prints the number of weeks in each month.
void NumberOfWeeksInEachMonth(int year){
    string months[12] = {"January" , "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
        int startDay = 0;
        for(int m = 0 ; m < 12 ; m++){
            int weeks = NumberOfWeeks(m, year, startDay);
            cout<<"\n" <<months[m] <<" "<<year <<endl;
            cout<<"Number of weeks : "<<weeks;
            startDay = (startDay + getMonthDays(m, year)) % 7;
            cout<<endl;
        }
}
//The NumberOfDaysInTheYear function determines the number of days in a year.
void NumberOfDaysInTheYear (int year){
    if ((year % 4 == 0 && year % 100 !=0 )||year % 400 == 0 ) {
        cout<<"Number of days in the year   "<<year << " : "<< 366 ;
    }
    else 
    cout<<"Number of days in the year   "<<year << " : "<< 365 ;
}
int main() {
    int year  ;
    int month  ;
    int num ;
    cout<<"Enter the year : ";
    cin>>year ;
    if(year < 1000){
        cout<<" lease enter a valid year greater than 1000. ";
    }
    
    cout<<(isLeapYear(year)? " leap year \n" :  " Not a leap year\n ");
    
    cout<<"Checkbox "<<endl;
    string num1 = "The whole year  ";
    string num2 = "Specific month ";
    string num3 = "Number of days in a month each year ";
    string num4 = "Print months with weeks ";
    string num5 = "Number of weeks each month ";
    string num6 = "Number of days in the year ";
    string num7 = "View the entire program ";
    cout<<"Do you want to print the whole year or a new month? \n ";
    cout<<"Choose number 1 for  "<<num1<<endl;
    cout<<"Choose number 2 for  "<<num2<<endl;
    cout<<"Choose number 3 for "<<num3<<endl;
    cout<<"Choose number 4 for "<<num4<<endl;
    cout<<"Choose number 5 for "<<num5<<endl;
    cout<<"Choose number 6 for "<<num6<<endl;
    cout<<"Choose number 6 for "<<num7<<endl;
    cin>>num ;
    
    switch(num){
        case 1 :
        showCalendar(year);
        break ;
        
        case 2 :
        Searchforamonth(year);
        break ;
        
        case 3 :
        NumberOfDaysintheMonth( month , year);
        break ;
        
        case 4 :
        Dayswithweeks( year);
        break;
        case 5 :
        NumberOfWeeksInEachMonth( year);
        break ;
        
        case 6 :
        NumberOfDaysInTheYear ( year);
        break ;
        
        case 7 :
        showCalendar(year);
        cout<<endl;
        Searchforamonth(year);
        cout<<endl;
        NumberOfDaysintheMonth( month , year);
        cout<<endl;
        Dayswithweeks( year);
        cout<<endl;
        NumberOfWeeksInEachMonth( year);
        cout<<endl;
        NumberOfDaysInTheYear ( year);
        
        default :
        cout<<"Sorry, this option is not available. ";
    }
    return 0;
}