#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int toInt(char a);
string multiplySingle(char a, char b);
string addSingle(char a, char b, char c = '0');
void padzeroleft(string &s, size_t n);
void padzeroright(string &a, int n);
string addmultiple(string a, string b);
string multiplyTwoNumbers(string a, string b);
int main()
{
    char c1 = '7';
    char c2 = '4';
    cout << toInt(c1) << endl;
    cout << addSingle(c1,c2) << endl;
    cout << multiplySingle(c1,c2) << endl;
    
    string s1 = "3141592653589793238462643383279502884197169399375105820974944592";
    string s2 = "2718281828459045235360287471352662497757247093699959574966967627";
    cout << multiplyTwoNumbers(s1,s2) << endl;

}

int toInt(char a)
{
    return (int)a-'0';
}

string addSingle(char a, char b, char c)
{
    return to_string(toInt(a)+toInt(b)+toInt(c));
}

string multiplySingle(char a, char b)
{
    return to_string(toInt(a)*toInt(b));
}

void padzeroleft(string &s, size_t n)
{
    while(s.length()<n)
        s = "0" + s;
    return;
}

void padzeroright(string &a, int n)
{
    for(int i{0}; i< n; i++)
        a = a + '0';
    return;
}
 
string addmultiple(string a, string b)
{
    if(a.length()>b.length())
        padzeroleft(b,a.length());
    else if(b.length() > a.length())
        padzeroleft(a, b.length());
    
    int n = a.length();
    char carryover{'0'};
    string result{""};
    for(int i{n-1}; i>=0; i--)
    {
        string res = addSingle(a[i],b[i],carryover);
        carryover = (res.length()>1) ? res[0]:'0';
        result = res[res.length()-1]+result;
    }
    
    if (toInt(carryover)>0)
        result = carryover + result;
        
    return result;
}

string multiplyTwoNumbers(string a, string b)
{
    if (a.length() != b.length())
        return "Not Supported";
    
    int n = a.length();
    if(n > 1)
    {
        int nBy2 = floor(n/2);
        string a1 = a.substr(0,nBy2);
        string a2 = a.substr(nBy2, n);
        string b1 = b.substr(0,nBy2);
        string b2 = b.substr(nBy2, n);
        
        string a1b1 = multiplyTwoNumbers(a1,b1);
        string a2b2 = multiplyTwoNumbers(a2,b2);
        string a1b2 = multiplyTwoNumbers(a1,b2);
        string a2b1 = multiplyTwoNumbers(a2,b1);
        
        padzeroright(a1b1, n);
        padzeroright(a1b2, n-nBy2);
        padzeroright(a2b1, n-nBy2);
                       
        string sum{a1b1};
        sum = addmultiple(sum,a1b2);
        sum = addmultiple(sum, a2b1);
        sum = addmultiple(sum, a2b2);
        
        return sum;
    }
    else if(n == 1)
        return multiplySingle(a[0], b[0]);
    
    return "Notfound";
}