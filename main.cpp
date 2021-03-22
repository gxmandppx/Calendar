#include<iostream>
using namespace std;
int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int norma[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int Discriminate(int year)//判断是否为闰年
{
    if(year%4==0&&year%100!=0||year%400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void head()
{
    int i;
    char weekday[7][10]={"星期一","星期二","星期三","星期四","星期五","星期六","星期日"};
    for(i=0;i<7;i++)
    {
        cout<<weekday[i]<<"\t";
    }
    cout<<endl;
}
int Sum(int year,int month,int leap[],int norma[])
{
    //19000101 星期一
    int i,sum=0;
    for(i=1900;i<year;i++)
    {
        int m;//用来标签是闰年还是平年  m==1,就是闰年
        m=Discriminate(i);
        if(m==1)
        {
            sum=sum+366;
        }
        else
        {
            sum=sum+365;
        }
    }
    //加月份的天数
    for(i=0;i<month-1;i++)
    {
        if(Discriminate(year)==1)
            sum=sum+leap[i];
        else
            sum=sum+norma[i];
    }
    return sum;
}
void show(int sum,int year,int month)
{
    int remainder,temp,i;
    remainder=sum%7;//得到多余的天数，然后在后一个月份用空格表示出来
    for(i=0;i<remainder;i++)
        cout<<"\t";//输出空格
    temp=7-remainder;
    if(Discriminate(year)==1)
    {
        for(i=1;i<=leap[month-1];i++)//打印31天
        {
            cout<<i<<"\t";
            if(i==temp||(i-temp)%7==0)
                cout<<"\n";
        }
        cout<<"\n";
    }
    else
    {
        for(i=1;i<=norma[month-1];i++)//打印30天
        {
            cout<<i<<"\t";
            if(i==temp||(i-temp)%7==0)
                cout<<"\n";
        }
        cout<<"\n";
    }
}
int Identify(int month)//判定月份是否符合条件
{
    if(month<=12)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    int year,month,day,he,n;
    cout<<"欢迎使用万年历~"<<endl;
    cout<<"请输入你要查看的年月(它们之间用空格分开):";
    cin>>year>>month;
    n=Identify(month);
    if(n==0)
    {
        cout<<"请输入正确的月份！！！"<<endl;
        cin>>month;
    }
    he = Sum(year, month, leap, norma);
    cout<<"您所看到的是"<<year<<"年"<<month<<"月的日历。"<<endl;
    cout << "*****************万年历******************" << endl;
    head();
    show(he, year, month);
    cout << endl << "****************************************" << endl;
    return 0;
}