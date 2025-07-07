#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class userinfo{
public:
	string filename="userinfo.txt";
void file(string username,string password) {
		ifstream file(filename);
		if(file.is_open()){
			string line;
			while(getline(file,line)){
				if(line==username){
					cout<<"UserName already found"<<endl;
					return;
				}
				if(password==line){
					cout<<"Enter a New Password"<<endl;
					return;
				}
			}
		ofstream newFile(filename,ios::app);
		newFile<<username<<endl;
		newFile<<password<<endl;
		newFile.close();
		cout<<"Registration is sucessfull"<<endl;}
}
void validate(string username,string password){
	ifstream file(filename);
	string line;
	bool userfound=false;
	bool passfound=false;
	if(file.is_open()){
		while(getline(file,line)){
			if(line==username){
				userfound=true;
			}
			if(line==password){
				passfound=true;
			}
		}
	}
	if(userfound){
		if(passfound){
			cout<<"User found"<<endl;
			cout<<"Welcome"<<endl;
		}else{
			cout<<"Incorrect Password";
		}}
	else{
		cout<<"User Not found"<<endl;
		cout<<"Please Enter a valid data and try again"<<endl;
	}
}
};
int main(){
	cout<<setw(10)<<"------ Welcome to Login ----------"<<endl;
	cout<<"1.Log in"<<endl;
	cout<<"2.New User? Register now"<<endl;
	int a;
	cin>>a;
	userinfo obj;
	if(a==1){
		string name,passwd;
		cout<<"Enter your user name:";
		cin>>name;
		cout<<"Enter your password:";
		cin>>passwd;
		obj.validate(name, passwd);
	}
	if(a==2){
		string name,passwd,passwd2;
		bool userdatavalid=true;
		while(userdatavalid){
				cout<<"Enter your user name:";
				cin>>name;
				cout<<"Enter your password:";
				cin>>passwd;
				cout<<"Renter Your password:";
				cin>>passwd2;
				if(passwd==passwd2){
				obj.file(name, passwd);
				userdatavalid=false;
				}
				else{
					userdatavalid=true;
					cout<<"Please Enter your details again Carefully"<<endl;
					name="";
					passwd="";
					passwd2="";
				}
		}
	}
}

