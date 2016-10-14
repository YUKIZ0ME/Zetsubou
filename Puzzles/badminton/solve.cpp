#include <iostream>
using namespace std;
int Week(int year, int month, int date){
    int week = (date + 1 + 2*month + 3*(month + 1)/5 + year + year/4 - year/100 + year/400) % 7;
    return week;
}

int Field(int M){
    int T = 0, X = 0;
    if(M < 4)
        return T;
    else{
        T = M/6;
        X = M%6;
        if(T == 0 && X >= 4){
            T++;
        }
        else if(T == 1){
            T++;
        }
        else if((T == 2 || T ==3) && X >= 4){
            T++;
        }
    }
    return T;
}

int Payment(int week, int starttime, int endtime){
    int payment;
    if(1 <= week <= 5){
        if(starttime >= 9 && endtime <= 12){
            payment = 30 * (endtime - starttime);
        }
        else if(starttime < 12 && endtime >12){
            payment = 30 * (12 - starttime) + 50 * (endtime - 12);
        }
        else if(starttime >=12 && endtime <= 18){
            payment = 50 * (endtime - starttime);
        }
        else if(starttime <18 && endtime >18){
            payment = 50 * (18 - starttime) + 80 * (endtime - 18);
        }
        else if(starttime >= 18 && endtime <= 20){
            payment = 80 * (endtime - starttime);
        }
        else if(starttime < 20 && endtime > 20){
            payment = 80 * (20 - starttime) + 60 * (endtime - 20);
        }
        else if(starttime >= 20){
            payment = 60 * (endtime - starttime);
        }
    }
    
    else{
        if(starttime >= 9 && endtime <= 12){
            payment = 30 * (endtime - starttime);
        }
        else if(starttime < 12 && endtime >12){
            payment = 30 * (12 - starttime) + 50 * (endtime - 12);
        }
        else if(starttime >=12 && endtime <= 18){
            payment = 50 * (endtime - starttime);
        }
        else if(starttime <18){
            payment = 60 * (endtime - starttime);
        }
    }
    
    return payment;
}

int main(){
    int year, month, date, starttime, endtime, M;
    char s;
    int k;
    int income, payment, total_income = 0, total_payment = 0, profit = 0, total_profit = 0;
    while(cin>>year>>s>>month>>s>>date>>starttime>>s>>s>>k>>s>>endtime>>s>>k>>M){
        int week = Week(year, month, date);
        int field = Field(M);
        payment = field * Payment(week, starttime, endtime);
        if(field == 0){
            income = 0;
        }
        else{
            income = 30 * M;
        }
        profit = income - payment;
        total_income+=income;
        total_payment-=payment;
        cout<<year<<"-";
        if(month < 10)
            cout<<"0"<<month<<"-";
        else
            cout<<month<<"-";
        if(date < 10)
            cout<<"0"<<date<<" ";
        else
            cout<<date<<" ";
        if(starttime < 10)
            cout<<"0"<<starttime;
        else
            cout<<starttime;
        cout<<":00~"<<endtime<<":00 ";
        if(income == 0)
            cout<<"0 ";
        else
            cout<<"+"<<income<<" ";
        if(payment == 0)
            cout<<"0 ";
        else
            cout<<"-"<<payment<<" ";
        if(profit == 0)
            cout<<"0"<<endl;
        else
            cout<<"+"<<profit<<endl;
    }
    cout<<endl;
    cout<<"Total Income: "<<total_income<<endl;
    cout<<"Total Payment "<<0 - total_payment<<endl;
    cout<<"Profit "<<total_income + total_payment<<endl;
    return 0;
}
