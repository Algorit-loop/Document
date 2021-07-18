#include <iostream>

using namespace std;

int a[10][10],f[10][10];
int n , ans = 0 , sum = 0 , ans_2 = 0;
char p;
string s;

void see()
{
    cout << "==========================\n";
    for (int i=0; i<=9; i++)
    {
        for (int j=0; j<=9; j++) cout << f[i][j] << " ";
        cout << "\n";
    }
}
int check_trai(char g,int i,int j)
{
    if (g == 'N') return a[i][j-1];
    if (g == 'W') return a[i+1][j];
    if (g == 'E') return a[i-1][j];
    if (g == 'S') return a[i][j+1];
}
int check_thang(int q[10][10],char g,int i,int j)
{
    if (g == 'N') return q[i-1][j];
    if (g == 'W') return q[i][j-1];
    if (g == 'E') return q[i][j+1];
    if (g == 'S') return q[i+1][j];
}
void Back_Tracking(int i,int j)
{
    if (a[i][j] != 0)
    {
        sum--;
        return;
    }
    //cout << i << " " << j << " " << p << " " << check_thang(p,i,j) << " " << check_trai(p,i,j) <<"\n";
    a[i][j] = 2;
    if (check_thang(a,p,i,j) == 2)
    {
        ans = max(ans,sum);
        return;
    }
    if (check_thang(a,p,i,j) == 1 && (check_trai(p,i,j) == 1 || check_trai(p,i,j) == 2))
    {
        ans = max(ans,sum);
        return;
    }
    if (check_thang(a,p,i,j) == 0)
    {
        sum++;
        if (p == 'N') return Back_Tracking(i-1,j);
        if (p == 'W') return Back_Tracking(i,j-1);
        if (p == 'E') return Back_Tracking(i,j+1);
        if (p == 'S') return Back_Tracking(i+1,j);
        return;
    }
    if (check_thang(a,p,i,j) == 1 && check_trai(p,i,j) == 0)
    {
        sum++;
        if (p == 'N')
        {
            p = 'W';
            return Back_Tracking(i,j-1);
        }
        if (p == 'W')
        {
            p = 'S';
            return Back_Tracking(i+1,j);
        }
        if (p == 'E')
        {
            p = 'N';
            return Back_Tracking(i-1,j);
        }
        if (p == 'S')
        {
            p = 'E';
            return Back_Tracking(i,j+1);
        }
        return;
    }
}
void B_Tracking(int i,int j)
{
    sum++;
    if (f[i][j] != 0)
    {
        ans_2 = max(ans_2,sum);
        return;
    }
    else
    {
        f[i][j] = 2;
    }
    if (check_thang(f,p,i,j) == 1)
    {
        if (p == 'N')
        {
            p = 'W' , B_Tracking(i,j-1) , sum--;
            p = 'E' , B_Tracking(i,j+1) , sum--;
            f[i][j] = 0;
            return;
        }
        if (p == 'W')
        {
            p = 'S' , B_Tracking(i+1,j) , sum--;
            p = 'N' , B_Tracking(i-1,j) , sum--;
            f[i][j] = 0;
            return;
        }
        if (p == 'E')
        {
            p = 'N' , B_Tracking(i-1,j) , sum--;
            p = 'S' , B_Tracking(i+1,j) , sum--;
            f[i][j] = 0;
            return;
        }
        if (p == 'S')
        {
            p = 'E' , B_Tracking(i,j+1) , sum--;
            p = 'W' , B_Tracking(i,j-1) , sum--;
            f[i][j] = 0;
            return;
        }
    }
    else
    {
        if (p == 'N')
        {
            B_Tracking(i-1,j);
            sum--;
            f[i][j] = 0;
            return;
        }
        if (p == 'W')
        {
            B_Tracking(i,j-1);
            sum--;
            f[i][j] = 0;
            return;
        }
        if (p == 'E')
        {
            B_Tracking(i,j+1);
            sum--;
            f[i][j] = 0;
            return;
        }
        if (p == 'S')
        {
            B_Tracking(i+1,j);
            sum--;
            f[i][j] = 0;
            return;
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> s;
        a[(int)s[1] - 48][(int)s[0] - 64] = 1;
        f[(int)s[1] - 48][(int)s[0] - 64] = 1;
    }
    int m = 8;
    p = 'S';
    for (int i=0; i<=m+1; i++)
    {
        a[i][0] = 1;
        a[0][i] = 1;
        a[m+1][i] = 1;
        a[i][m+1] = 1;
        f[i][0] = 1;
        f[0][i] = 1;
        f[m+1][i] = 1;
        f[i][m+1] = 1;
    }
    /*for (int i=0; i<=m+1; i++)
    {
        for (int j=0; j<=m+1; j++) cout << a[i][j] << " ";
        cout <<"\n";
    }*/
    Back_Tracking(1,1);
    p = 'S'; sum = 0;
    B_Tracking(1,1);
    ans_2 = ans_2 - 2;
    if (ans_2 < 0) ans_2 = 0;
    cout << ans <<"\n" << ans_2;
    return 0;
}
