#include <iostream>

using namespace std;
int n,k;
long long power(long long x,int y)
{
    long long result = 1;
    for (int i=1; i<=y; i++)
        result = result * x;
    return result;
}
int main()
{
    cin >> k >> n;
    long long sum = power(2,k);
    long long lop = 1 , ans = 1;
    //cout << sum << " " << n << " " << ans << "\n";
    while (sum > 1)
    {
        if (n <= sum >> 1)
        {
            sum = sum >> 1;
            lop = lop << 1;
        }
        else
        if (n > sum / 2)
        {
            ans = ans + ((lop - ans) << 1) + 1;
            lop = lop << 1;
            n = (sum >> 1) - (n - ((sum >> 1) + 1));
            sum = sum >> 1;
        }
        //cout << sum << " " << n << " " << ans << "\n";
    }
    cout << ans;
    return 0;
}
