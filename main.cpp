
#include <iostream>
#include<cstring>
#include <vector>
using namespace std;
/*Дано два рядки. Обчислити відстань Левенштейна між ними*/

unsigned long lev(string s1, string s2)
{
     size_t size1 = s1.size();
     size_t size2 = s2.size();
     size_t d[size1 + 1][size2 + 1];
     for (int i = 0; i <= size1; i ++)
       d[i][0] = i;
     for (int i = 0; i <= size2; i ++)
       d[0][i] = i;

     int cost = 0;
     for (int i = 1; i <= size1; i ++)
       for (int j = 1; j <= size2; j ++)
       {
         cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1 ;
         if ( (i > 1) && (j > 1) && (s1[i] == s2[j - 1]) && (s1[i - 1] == s2[j]))
         {
           size_t a = min(d[i - 1][j], d[i][j - 1] + 1);
           size_t b = min(d[i][j] + cost, d[i - 2][j - 2]);
           d[i][j] = min(a, b);
         }
         else
         {
           d[i][j] = min(min(d[i][j -1] + 1, d[i - 1][j] + 1), d[i - 1][j - 1] + cost);
         }
       }
    cout<<d[size1][size2]<<endl;
     return d[size1][size2];
}

void task_String_4(){
    char str1[20];
    char str2[20];
    cout<<"string 1 : ";
    cin>>str1;
    cout<<"string 2 : ";
    cin>>str2;
    
    lev(str1, str2);
}

/*
 Дано послідовність додатних чисел. Розставити між ними знаки «+» та «-» так,
 щоб у результаті ми одержали 0. Якщо це не можливо, вивести відповідне
 повідомлення.
 */

int task_mass_5(){
    int n;
        cout<<"Enter the number of numbers : ";
        cin>>n;
    int a[25];
        for (int i=0;i<(n);i++){
            cin>>a[i];
        }
    int b;
    b=pow(2,n-1);
     
    while(--b>-1){
        int num = 25;
        int *a1 = new int[num];
        int b1=b,c=0,ans=a[0];
     
        for (int i=0;i<n-1;i++){
            if (b1%2)a1[c]=1;
            b1/=2;
            if (a1[i])ans+=a[i+1];else ans-=a[i+1];
            c++;
       }
        
       if (ans == 0){
           for (int i=0;i<n-1;i++){
                if (a1[i])cout<<a[i]<<"+"; else cout<<a[i]<<"-";
            }
           cout<<a[n-1]<<"="<<0<<endl;
           return 0;
        }
    }
    cout<<"No solutions"<<endl;
    return 0;
}

int main(){
    task_mass_5();
}


//int main(){
//
//    task_String_4();
//    return 0;
//}
