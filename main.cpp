/*Project done in Code::Blocks 20, It can be done also in VSCode, etc*/
#include <iostream>
//for reading/writing in files
#include <fstream>
//for using string functions
#include <string>

//function to verify if one is logged in
bool isLoggedIn(){
    std::string username, password, un, pw;
    std::cout<<"Enter Name: ";
    std::cin>>username;

    std::cout<<"Enter Password: ";
    std::cin>>password;
    /*
    ofstream: Stream class to write on files
    ifstream: Stream class to read from files
    fstream: Stream class to both read and write from/to files.
    */
    std::ifstream read("D:\\OneDrive - e-uvt.ro\\Informatica\\Programing\\C_Cpp_Applications\\Login_Registration_System\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int choice;
    std::cout<<"Type 1 to register\nType 2 to login\nType 3 to exit\nYour choice: ";
    std::cin>> choice;
    if(choice == 1){
        std::string username, password;

        std::cout<<"Choose a username: ";
        std::cin>>username;
        std::cout<<"Choose a password: ";
        std::cin>>password;

        std::ofstream file;
        file.open("D:\\OneDrive - e-uvt.ro\\Informatica\\Programing\\C_Cpp_Applications\\Login_Registration_System\\" +username+ ".txt");

        file << username << std::endl << password;
        file.close();

        main();
    } else if(choice == 2){
        bool status = isLoggedIn();
        if(!status){
            std::cout<<"Username or password doesn't exist!"<<std::endl;
            system("PAUSE");
            main();
        } else{
           std::cout<<"Successfully logged in!"<< std::endl;
           system("PAUSE");
           return 1;
        }
    } else if(choice == 3){
        exit(1);
    } else{
        std::cout<<"Invalid choice! Choose again!" <<std::endl;
        main();
    }

    return 0;
}
