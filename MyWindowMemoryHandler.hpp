#ifndef MYWINDOWMEMORYHANDLER_HPP
#define MYWINDOWMEMORYHANDLER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "MyWindow.hpp"
using namespace std;

class MyWindowMemoryHandler{
private:
    fstream file;
    vector<MyWindow> windows;
    int count;
public:
    MyWindowMemoryHandler();
    void saveWindow(MyWindow myWindow);
    MyWindow getWindow(int id);
    void DeleteWindow(int id);
};
MyWindowMemoryHandler::MyWindowMemoryHandler(){
    file.open("myWindows.txt");
    file.close();
}
void MyWindowMemoryHandler::saveWindow(MyWindow myWindow){
    
}
MyWindow MyWindowMemoryHandler::getWindow(int id){
    return MyWindow("",0,0,0,0);
}
void MyWindowMemoryHandler::DeleteWindow(int id){
    
}
#endif // 