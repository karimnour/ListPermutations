#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector <string> vec;

void  RecPermute(string soFar, string rest)
{
    if (rest == "")
    {    // No more characters
         // cout << "soFar"<< endl;
         // cout << soFar<< endl;

    }

    for (int i = 0; i < rest.length(); ++i)
    {
        string next = soFar + rest[i];// Glue next char
        //cout <<"next"<<endl;
        //cout <<next<<endl;
        string remaining = rest.substr(0, i)+ rest.substr(i+1);
        //cout<<"remaining"<<endl;
        //cout<<remaining<<endl;
        if (remaining=="")
        {

            vec.push_back(next);

            //cout <<vec.size()<<endl;
            //cout <<vec[t]<<endl;

           RecPermute(next, remaining);
        }
        else
        {
             RecPermute(next, remaining);

        }



    }


}
/*--------------------------------------------------------------*/
// "wrapper" function
void ListPermutations(string s ) {
    RecPermute("", s );
}
/*-------------------------------------------------------------------*/

int main()
{
    string input ;
    cout <<"enter your string "<<endl;
    cin >>input;
    ListPermutations(input);

    /*
    cout << "size = " << vec.size() << endl;

    for(auto i = 0; i < vec.size(); ++i)
    {
        cout << "vec[" << i << "] = " << vec.at(i)<< endl;
    }
    */

    sort(vec.begin(), vec.end());

    auto it = unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());

    for(auto i = 0; i < vec.size(); ++i)
    {
        cout << "vec[" << i << "] = " << vec.at(i)<< endl;
    }

    return 0;
}
