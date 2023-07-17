//Jose Lara Hernandez

//Module 3 Project One

// July 16, 2023

/*The purpose of this assignment is to
 create a 12 and 24 hour clock with the
 ability to add an hour, minute, second, or exit program.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int hours = 0;
int minutes = 0;
int seconds = 0;

//function prototypes

string twoDigitString(unsigned int number);//formats numbers as two digits

string nCharString(size_t n, char c);//repeats '*' to use in formatting program output

string formatTime24(int h, int m, int s);//outputs time using 24-hour time format

string formatTime12(int h, int m, int s);//outputs time using 12-hour time format

void printMenu(unsigned char width);//prints menu with options for user to enter

unsigned int getMenuChoice(unsigned int maxChoice);//processes user input from menu choices in interface

void displayClocks(unsigned int h, unsigned int m, unsigned int s);//prints BOTH 12 and 24 hour time on interface at the same time

void addOneSecond();// adds ONE second to both times

void setSecond(int s);// sets new seconds

int getSecond();// gets new seconds

void addOneMinute();// adds ONE minute to both times

void setMinute(int m);//sets new minutes

int getMinute();//gets net minutes

void addOneHour();// adds ONE hour to both times

void setHour(int h);//sets new hour

int getHour();//gets new hour

int main() {
    
    int choice = 0;
    
    do{// loop to input menu choice until exit condition number 4 is selected from menu
        displayClocks(hours, minutes, seconds);
        printMenu(27);
        choice = getMenuChoice(4);
        
        if(choice == 1){
            addOneHour();
        }else if (choice == 2){
            addOneMinute();
        }else if (choice == 3){
            addOneSecond();
        }else{
            choice = 4;
        }
        
    }while(choice != 4);
    
    return 0;
}//main

// function declerations

string twoDigitString(unsigned int number){//formats numbers as two digits
    
    string strNumber = "";
    
    if (number < 10){//checks if single digit so it can add a zero to the start
        strNumber = to_string(number);
        strNumber = "0" + strNumber;
    } else {
        strNumber = to_string(number);
    }
    
    return strNumber;
}//twoDiggitString

string nCharString(size_t n, char c){//repeats '*' to use in formatting program output
    
    return string(n, c);
}//nCharString

string formatTime24(unsigned int h,unsigned int m,unsigned int s){//outputs time using 24-hour time format
    
    string hour = twoDigitString(h);
    string minute = twoDigitString(m);
    string second = twoDigitString(s);
    
    string time24 = hour + ":" + minute + ":" + second;
    
    return time24;
}//formatTime24

string formatTime12(unsigned int h,unsigned int m,unsigned int s){//outputs time using 12-hour time format
    
    string hour = twoDigitString(h);
    string minute = twoDigitString(m);
    string second = twoDigitString(s);
    string time12 = "";
    
    if (h >= 0 && h <= 11 && s <= 59){
        
        if (h == 0){
            hour = "12";
        }
        
        time12 = hour + ":" + minute + ":" + second;
        time12 += " A M";
        
    }
    
    if (h >= 12 && h <= 23 && s <= 59){
        if (h >= 13 && h <= 23){
            h = h - 12;
        }
        time12 = twoDigitString(h) + ":" + minute + ":" + second + " P M";
    }
    
    return time12;
}//formatTime12

void printMenu(unsigned char width){//prints menu with options for user to enter
    
    cout << nCharString(width, '*') << endl;
    cout << "* 1 - Add One Hour        *" << endl;
    cout << endl;
    cout << "* 2 - Add One Minute      *" << endl;
    cout << endl;
    cout << "* 3 - Add One Second      *" << endl;
    cout << endl;
    cout << "* 4 - Exit Program        *" << endl;
    cout << nCharString(width, '*') << endl;
}//printMenu

unsigned int getMenuChoice(unsigned int maxChoice){//processes user input from menu choices in interface
    
    unsigned int choice;
    
    while (true) {
        cin >> choice;
        if (choice >= 1 && choice <= maxChoice){
            return choice;
        }//if
    }//while
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s){//prints BOTH 12 and 24 hour time on interface at the same time
    
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
    cout << '*' << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << "   ";
    cout << '*' << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
    cout << endl;
    cout << '*' << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << "   ";
    cout << '*' << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
    
}//displayClocks

void addOneSecond(){// adds ONE second to both times
    
    if (getSecond() >= 0 && getSecond() <= 58) {
        setSecond(getSecond() + 1);
    }else if (getSecond() == 59) {
        setSecond(0);
        addOneMinute();
    }
    
}//addOneSecond

void setSecond(int s){
    seconds = s;
}//setSecond

int getSecond(){
    return seconds;
}//getSecond

void addOneMinute(){// adds ONE minute to both times
    
    if (getMinute() >= 0 && getMinute() <= 58) {
        setMinute(getMinute() + 1);
    }
    else if (getMinute() == 59) {
        setMinute(0);
        addOneHour();
    }
    
}//addOneMinute

void setMinute(int m){
    minutes = m;
}//setMinute

int getMinute(){
    return minutes;
}//getMinute

void addOneHour(){// adds ONE hour to both times
    
    if (getHour() >= 0 && getHour() <= 22) {
        setHour(getHour() + 1);
    }else if (getHour() == 23) {
        setHour(0);
    }
    
}//addOneHour

void setHour(int h){
    hours = h;
}//setHour

int getHour(){
    return hours;
}//getHour
