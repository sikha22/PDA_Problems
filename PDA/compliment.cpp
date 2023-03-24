#include <iostream>
using namespace std;
class Solution
{
public:
    int complementBase(int n)
    {
        int m = n;
        int mask = 0;
        if (n == 0)
        {
            return 1;
        }
        while (m != 0)
        {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        int ans = (~n) & mask;
        return ans;
    }
} rs;
int main()
{
    int n;
    cout << "ENter n : ";
    cin >> n;
    cout << "Complement Base 10 is : " << rs.complementBase(n) << endl;
}
