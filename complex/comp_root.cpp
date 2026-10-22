#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string type(string a){
      string a_type = "";
	if (a.find('i') != string::npos){
		if(a.find('+') != string::npos){
			a_type = "C";	
		}
		else{
		  a_type = "PC";	
		}
	}
	else{
		a_type = "R";
	}
	return a_type;
}

tuple <int, int> parse_all(string a){
        int a1 = 0;
        int a2 = 0;
        string a_type = (type(a));
       
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
   
    return{a1, a2};
        

}

string addition(string a, string b){
	auto [a1,a2] = parse_all(a);
	auto [b1,b2] = parse_all(b);
  
	int w1 = a1 + b1;
	int w2 = a2 + b2;
        
	string w1str = to_string(w1);
	string w2str = to_string(w2);
	if(w2>0){
	  return (w1str + "+" + w2str + "i");
	}
	else 
	  return (w1str);
	
}

string substr (string a, string b){
        auto [a1,a2] = parse_all(a);
	auto [b1,b2] = parse_all(b);
        int w1 = a1 - b1;
	int w2 = a2 - b2;
	string w1str = to_string(w1);
	string w2str = to_string(w2);
	
	  return (w1str + "+" + w2str + "i");
	
}
string multi(string a, string b){
        auto [a1,a2] = parse_all(a);
	auto [b1,b2] = parse_all(b);
        string w1str = to_string((a1*b1)-(a2*b2));
        string w2str = to_string((a2*b1)+(a1*b2));
  
	  return (w1str + "+" + w2str + "i");
}
string divid(string a,string b){}
string sqr(int n, string a){}
int main(){
	cout << "complex numbers calculator" << endl;
	int option = 0;
	

	string a, b = "";
	int n = 0;
	int k = 1;
	do{
	  cout << "choose what to do" << endl;
	  	
	  cout << "1: addition" << endl;
	  cout << "2: subtraction" << endl;
	  cout << "3: multicipation" << endl;
	  cout << "4: dividion" << endl;
	  cout << "5: square root" << endl;
	  cout << "6: Exit the program" << endl;
	  cin >> option;
	  cout << endl;
	  cout << "root = for example 2sq5 - square root of 5" << endl; 
	  switch(option){
		case 1:
			cout << "first number (x+yi): ";
			cin >> a;
			cout << endl;
			cout << "second number (x+yi): ";
			cin >> b;
			cout << "Resoult: " << addition(a,b) << endl;
			break;
		case 2: 
		        cout << "first number (x+yi): ";
			cin >> a;
			cout << endl;
			cout << "second number (x+yi): ";
			cin >> b;
			cout << "Resoult: " << substr(a,b) << endl;
			break;
		case 3: cout << "first number (x+yi): ";
			cin >> a;
			cout << endl;
			cout << "second number (x+yi): ";
			cin >> b;
			cout << "Resoult: " << multi(a,b) << endl;
			break;
		case 4: divid(a,b); break;
		case 5: sqr(n,a); break;
		case 6: cout << "Exiting program" << endl; break;
	}
	}
	while(option!=6);
}
