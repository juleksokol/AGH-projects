#include <iostream>
#include <string>


using namespace std;

int main(){
        string a = "2+i";
        string a_type = "C";
        string b_type = "PC";
        string b = "6i";
	int a1 = 0;
	int a2 = 0;
	int b1 = 0;
	int b2 = 0;
	if(a_type == "R"){
	  a1 = stoi(a);
	  a2 = 0;
	}
        if (a_type == "C"){
          int plus = a.find('+');
          int i = a.find('i');
          a1 = stoi(a.substr(0,plus));
          if(plus+1 == i){
            a2 = 1;
          }
          else{
        
          a2 = stoi(a.substr(plus+1,i-(plus+1)));
          }
        }
        if (a_type == "PC"){
          a2 = stoi(a.substr(0,a.length()-1));
        }
        
        cout << a1 << a2 << b1 << b2 << endl;


}
