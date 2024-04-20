#include <iostream>
#include <vector>
#include<string>
using namespace std;
void solve(vector<string>& ans, string str, string output, int i)
{
    if(i>=str.length()) {
        if(output.length()>0)
        ans.push_back(output);
        return ;
        }
    
    //exclude
    solve(ans, str, output, i+1);
    //include
    output.push_back(str[i]);
    solve(ans, str, output, i+1);
}
vector<string> subsequences(string str){
	
vector<string> ans;
    string output = "";
    solve(ans,str,output,0);
    return ans;
}
int main() 
{
     string str = "nvsd";

    vector<string> result{subsequences(str)};

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}