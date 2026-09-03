#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool existusername(string usernmae){
    ifstream file("data.txt");
    string savedusername;
    string savedpassword;
    if(!file){
        cout<<"Username doesnot exist!"<<endl;
        return false;
    }
    while(file >> savedusername >> savedpassword){
        if(savedusername==usernmae) return true;
    }
    // cout<<"Username Dostn't exist!!!"<<endl;
    return false;
}
bool login(string username, string password){
    ifstream file("data.txt");
    string savedusername;
    string savedpassword;
    while(file >> savedusername >> savedpassword){
        if(username==savedusername){
            if(password==savedpassword){
                return true;
            } 
            else{
                cout<<"Incorrect Password"<<endl;
                return false;
            } 
        }
    }
    return false;
}
bool validusername(string username){
    if(username.length()<=3) return false;
    for(char ch: username){
        if(ch==' '){
            cout<<"Username cann't contains SPACE!!"<<endl;
            return false;
        }
    }
    return true;
}
bool validpassword(string password){
    bool character=false, digit=false,alpha=false;
    if(password.length()<=5){
        cout<<"Enter longer password"<<endl;
        return false;
    }
    for(char ch: password){
        if(isalpha(ch)) alpha=true;
        if(!isalnum(ch)) character= true;
        if(isdigit(ch)) digit=true;
    }
    if(!alpha){
        cout<<"Password must contains atleast one Alphabet"<<endl;
        return false;
    }
    if(!character){
        cout<<"Password must contain Special character!!!!!"<<endl;
        return false;
    }
    if(!digit){
        cout<<"Password must contain digit init!!!!"<<endl;
        return false;
    }
    return true;
}
void registration(string username, string password){
    ofstream file("data.txt",ios::app);
    file<<username<<" "<<password<<endl;
}
int main(){
    while(true){
        string x;
        cout<<endl<<endl;
        cout<<"*======== Main Menu ========*"<<endl;
        cout<<"Press 1 for login"<<endl;
        cout<<"Press 2 for Registration"<<endl;
        cout<<"Press 3 for Exit!"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>x;
        if(x=="1"){
            string username;
            string password;
            cout<<"Enter your Username : ";
            cin>>username;
            if(existusername(username)){
                cout<<"Enter Your Password :";
                cin>>password;
                if(login(username,password)){
                    cout<<"Login Successful!"<<endl;
                }
                else{
                    int attempts=3;
                    bool loggedin=false;
                    while(attempts--){
                        cout<<"Enter Correct Password :";
                        cin>>password;
                        if(login(username,password)){
                            cout<<"Login Successful!"<<endl;
                            loggedin= true;
                            break;
                        }
                    }
                    if(!loggedin){
                        cout<<"Maximun attempts exceeded!!!!!!!!!!!"<<endl;
                    }   
                }
            }
            else{
                cout<<"Please Enter correct username or register first!"<<endl;
            }
        }
        else if(x=="2"){
            string username;
            cout<<"Enter username: ";
            cin>>username;
            while(true){
                if(existusername(username)){
                    cout<<"<<<<This username already exist please use Unique username>>>>"<<endl;
                    cout<<"Enter unique username: ";
                    cin>>username;
                }
                else if(!validusername(username)){
                    cout<<"Enter username: ";
                    cin>>username;
                }
                else break;
            }
            string password;
            cout<<"Enter strong Password :";
            cin>>password;
            while(true){
                if(!validpassword(password)){
                    cout<<"Enter your Password: ";
                    cin>>password;
                }
                else break;
            }
            registration(username,password);
            cout<<"Registration Successful!!"<<endl;
        }
        else if(x=="3") break;
        else{
            cout<<"<<<<----Invalid Input---->>>>";
        }
    }
}