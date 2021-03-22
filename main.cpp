#include<iostream>
using namespace std;
int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int norma[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int Discriminate(int year)//�ж��Ƿ�Ϊ����
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
    char weekday[7][10]={"����һ","���ڶ�","������","������","������","������","������"};
    for(i=0;i<7;i++)
    {
        cout<<weekday[i]<<"\t";
    }
    cout<<endl;
}
int Sum(int year,int month,int leap[],int norma[])
{
    //19000101 ����һ
    int i,sum=0;
    for(i=1900;i<year;i++)
    {
        int m;//������ǩ�����껹��ƽ��  m==1,��������
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
    //���·ݵ�����
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
    remainder=sum%7;//�õ������������Ȼ���ں�һ���·��ÿո��ʾ����
    for(i=0;i<remainder;i++)
        cout<<"\t";//����ո�
    temp=7-remainder;
    if(Discriminate(year)==1)
    {
        for(i=1;i<=leap[month-1];i++)//��ӡ31��
        {
            cout<<i<<"\t";
            if(i==temp||(i-temp)%7==0)
                cout<<"\n";
        }
        cout<<"\n";
    }
    else
    {
        for(i=1;i<=norma[month-1];i++)//��ӡ30��
        {
            cout<<i<<"\t";
            if(i==temp||(i-temp)%7==0)
                cout<<"\n";
        }
        cout<<"\n";
    }
}
int Identify(int month)//�ж��·��Ƿ��������
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
    cout<<"��ӭʹ��������~"<<endl;
    cout<<"��������Ҫ�鿴������(����֮���ÿո�ֿ�):";
    cin>>year>>month;
    n=Identify(month);
    if(n==0)
    {
        cout<<"��������ȷ���·ݣ�����"<<endl;
        cin>>month;
    }
    he = Sum(year, month, leap, norma);
    cout<<"������������"<<year<<"��"<<month<<"�µ�������"<<endl;
    cout << "*****************������******************" << endl;
    head();
    show(he, year, month);
    cout << endl << "****************************************" << endl;
    return 0;
}