#include <bits/stdc++.h>

using namespace std;
string s;
char p;
int x , y;
void _check(char gr)
{
    if (gr == 'N') y++;
    if (gr == 'E') x++;
    if (gr == 'S') y--;
    if (gr == 'W') x--;
}
bool LABAN(char r)
{
    if (r == 'N' || r == 'E' || r == 'W' || r == 'S') return true;
    else
    return false;
}
void bocua(char r)
{
    if (p == 'N')
    {
        if (r == 'L') x-- , p = 'W';
        if (r == 'R') x++ , p = 'E';
        if (r == 'B') y++;
        if (r == 'C') y-- , p = 'S';
        return;
    }
    if (p == 'W')
    {
        if (r == 'L') y-- , p = 'S';
        if (r == 'R') y++ , p = 'N';
        if (r == 'B') x-- ;
        if (r == 'C') x++ , p = 'E';
        return;
    }
    if (p == 'E')
    {
        if (r == 'L') y++ , p = 'N';
        if (r == 'R') y-- , p = 'S';
        if (r == 'B') x++ ;
        if (r == 'C') x-- , p = 'W';
        return;
    }
    if (p == 'S')
    {
        if (r == 'L') x++ , p = 'W';
        if (r == 'R') x-- , p = 'E';
        if (r == 'B') y-- ;
        if (r == 'C') y++ , p = 'N';
        return;
    }
}
int main()
{
    while (cin >> s)
    {
        x = 0 ; y = 0;
        p = s[0];
        _check(s[0]);
        for (int i=1; i<s.size(); i++)
        {
            if (LABAN(s[i]) == true)
            {
                _check(s[i]);
                p = s[i];
            }
            else
            {
                bocua(s[i]);
            }
            //cout << x << " " << y << " " << LABAN(s[i]) << " " << p << "\n";
        }
        double ans = sqrt((x*x) + (y*y));
        //cout << x << " " << y << "\n";
        cout << setprecision(2) << fixed << ans << "\n";
    }
    return 0;
}
