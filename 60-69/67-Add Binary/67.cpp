#include <bits/stdc++.h>
using namespace std;

//不管效率直接在头加 
struct Solution {
    string addBinary(string a, string b) {
        string sum;
        int i = a.size(), j = b.size(), c = 0;
        while (i || j || c) {
            c += (i && a[--i] & 1) + (j && b[--j] & 1);
            sum = char(c % 2 + '0') + sum;
            c /= 2;
        }
        return sum;
    }
};

int main(){
	
}
