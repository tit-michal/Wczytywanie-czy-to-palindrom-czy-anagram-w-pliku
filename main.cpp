#include <iostream>
#include <fstream>

using namespace std;

bool sprawdz (string s);
bool sprawdzana (string s1, string s2);

fstream pliczek;

string s, s1, s2;

int main()
{
   pliczek.open("dane.txt", ios::out|ios::app);


    cout << "Wprowadz palindrom" << endl;
    cin >> s;
    if(sprawdz(s)==true) pliczek << "Jest to palindrom" << endl;
    else
         pliczek<< "Nie jest to palindrom" << endl;



    cout << "Wprowadz pierwszy wyraz anagramu" << endl;
    cin >> s1;
    cout << "Wprowadz drugi wyraz anagramu" << endl;
    cin >> s2;
    if(sprawdzana(s1,s2)==true) pliczek << "Jest to anagram" << endl;
    else
        pliczek << "Nie jest to anagram" << endl;
    return 0;
}



bool sprawdz (string s)
{
    int dl=s.size();
    for (int i=0;i<dl/2;i++)
        if (s[i]!=s[dl-i-1]) return false;
    return true;

}






bool sprawdzana (string s1, string s2)
{
    int dl=s1.size();
    if (dl!=s2.size()) return false;
    else
    {
        int T1[2]={0,0}, T2[2]={0,0};
        for (int i=0;i<dl;i++)
        {
            if (s1[i]=='X') T1[0]++;
            else T1[1]++;
            if (s2[i]=='X') T2[0]++;
            else T2[1]++;
        }
        for (int i=0;i<2;i++)
            if(T1[i]!=T2[i]) return false;

    }
    return true;

}
