#include <iostream>
using namespace std;

int year, month, date, starttime, endtime, M;
char char1;                    //存放输入数据中不需要的字符
int minute;                    //存放预约时间中的分钟数（均为00）
int income, payment, total_income = 0, total_payment = 0, profit = 0, total_profit = 0;
int times = 0;                 //统计数据组数
//Week函数将年月日转化为星期
int Week(int year, int month, int date){
    int week = (date + 1 + 2*month + 3*(month + 1)/5 + year + year/4 - year/100 + year/400) % 7;  //基姆拉尔森星期公式
    return week; 
}

//Field函数根据报名人数确定订场数量
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
        else if(T == 1){                                                                   //根据题中条件计算预约球场个数，注意只要M/6 = 1就多预约一个（M=6,时T=2）
            T++;
        }
        else if((T == 2 || T ==3) && X >= 4){
            T++;
        }
    }
    return T;
}

//Payment函数计算每场根据时间所需支出
int Payment(int week, int starttime, int endtime){
    int payment;
    if(1 <= week <= 5){                                                                    //星期1-5的情况
        if(starttime >= 9 && endtime <= 12){
            payment = 30 * (endtime - starttime);                                          //上午9-12点时段
        }
        else if(starttime < 12 && endtime >12){
            payment = 30 * (12 - starttime) + 50 * (endtime - 12);                         //12点前开打，最多三小时，因此不会超过18点
        }
        else if(starttime >=12 && endtime <= 18){                                          //下午12-18点时段
            payment = 50 * (endtime - starttime);
        }
        else if(starttime <18 && endtime >18){
            payment = 50 * (18 - starttime) + 80 * (endtime - 18);                         //18点前开打，最多3小时，因此不会超过20点
        }
        else if(starttime >= 18 && endtime <= 20){
            payment = 80 * (endtime - starttime);                                          //晚间18-20点时段
        }
        else if(starttime < 20 && endtime > 20){
            payment = 80 * (20 - starttime) + 60 * (endtime - 20);                         //晚间从20点前打到20点以后
        }
        else if(starttime >= 20){
            payment = 60 * (endtime - starttime);                                          //晚间20-22点时段
        }
    }
    
    else{                                                                                  //周末情况
        if(starttime >= 9 && endtime <= 12){
            payment = 30 * (endtime - starttime);                                          //上午9-12点时段                                     
        }
        else if(starttime < 12 && endtime >12){
            payment = 30 * (12 - starttime) + 50 * (endtime - 12);                         //12点前开打，最多三小时，因此不会超过18点
        }
        else if(starttime >=12 && endtime <= 18){ 
            payment = 50 * (endtime - starttime);                                          //下午12-18点时段
        }
        else if(starttime <18 && endtime > 18){
            payment = 50 * (18 - starttime) + 60 * (endtime - 18);                         //从18点前打到18点以后
        }
        else if(starttime >= 18){
            payment = 60 * (endtime - starttime);                                          //晚间18-22点时段
        }
    }
    
    return payment;
}

//Output函数计算每场收入支出利润并显示
void Output(){
    if(times == 0){
       cout<<"[Summary]"<<endl<<endl;
    }
    cin>>year>>char1>>month>>char1>>date;
    cin>>starttime>>char1>>minute>>char1>>endtime>>char1>>minute>>M;
    if(date == 0)
        return;
    int week = Week(year, month, date);
    int field = Field(M);
    if(starttime < 9 || endtime > 22 || starttime >= endtime || endtime - starttime > 3){
        cout<<"Put the wrong time!"<<endl;
        return;
	}
    payment = field * Payment(week, starttime, endtime);
    if(field == 0){
        income = 0;
    }
    else{
        income = 30 * M;
    }
    profit = income - payment;
    total_income+=income;
    total_payment+=payment;
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
    if(profit <= 0)
        cout<<profit<<endl;
    else
        cout<<"+"<<profit<<endl;
    times++;
    date = 0;
}

//Total 函数计算总收入，总支出及利润并显示
void Total(){
    cout<<"Total Income: "<<total_income<<endl;
    cout<<"Total Payment "<<total_payment<<endl;
    cout<<"Profit "<<total_income - total_payment<<endl;
}

int main(){
    while(cin){
        Output();
    }
    cout<<endl;
    Total();
    return 0;
}
