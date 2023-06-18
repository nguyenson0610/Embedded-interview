#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> array;
    // array.push_back(5);
    // array.push_back(6);
    
    // array.assign(5,1);

    // array.clear();
    // for (int item : array)
    // {
    //     cout<<" "<<item<<endl;

    // }

    // list<int> array1;
    
    map<string,int> SinhVien;
    SinhVien["ID"] = 100;
    SinhVien["Tuoi"] = 20;
    SinhVien["Lop"] = 12;

    for (auto item : SinhVien)
    {
        cout<<"Key la "<<item.first.c_str()<<" Value la "<<item.second<<endl;
    }
    


    return 0;
}
