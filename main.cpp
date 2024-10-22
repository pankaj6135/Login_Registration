#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class userAuthentication{
    private:
    string userName,Password,ConfirmPassword,id,pass;
    int success = 0;
    public:
    //first create a methods for registration
    void Registeruser(){
        cout<<"Enter user Name"<<endl;
        cin>>userName;
         cout<<"Enter Password"<<endl;
        cin>>Password;
        cout<<"Enter Confirm Password"<<endl;
        cin>>ConfirmPassword;

        // first we check the password and confirm password validity
        
        if(Password!=ConfirmPassword)
        {
            cout<<"Password and confirm Password do not match \n try again"<<endl;
            Registeruser();
        }
        else{
            ofstream File("studentRecord.txt",ios::app);
            File<<userName<<" "<< Password<<"\n";
            cout<<"You are registered successfuly"<<endl;
            File.close();
        }
        
    }

    // now make a function to login
    void Loginuser(){
        cout<<"Enter user Name"<<endl;
        cin>>userName;
        cout<<"Enter Password"<<endl;
        cin>>Password;

       // now we check if the user is already exists in file or database
        ifstream input("studentRecord.txt");
        while(input>>id>>pass)
        {
            if(id == userName && pass == Password)
            {
                // increment the success value
                success =1;
                break;
            }
        }
          input.close();
          if(success == 1){
            cout<<"LOgin successful"<<endl;
          }

          else{
            cout<<"wrong username or password"<<endl;
          }
    }
};
int main()
{
   int option;
   userAuthentication user;
   cout<<"Enter option to proceed \n 1 For Registration \n 2 For login"<<endl;
   cin>>option;

   switch (option)
   {
    case 1:
    //Registration
    // Now call the function here
    user.Registeruser();
    break;

    case 2:
    // Login
    // here call login
    user.Loginuser();
    break;
  default:
    cout<<"Enter valid Data" <<endl;
   }
    return 0;
}
