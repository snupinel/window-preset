#ifndef MYWINDOWMEMORYHANDLER_HPP
#define MYWINDOWMEMORYHANDLER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "MyWindow.hpp"
#include <string>
using namespace std;

class MyWindowMemoryHandler{
private:
    fstream file;
    vector<MyWindow> windows;
    int count;
public:
    MyWindowMemoryHandler();
    void read();
    void write();
    void saveWindow(MyWindow myWindow);
    MyWindow getWindow(int id);
    void DeleteWindow(int id);
};
MyWindowMemoryHandler::MyWindowMemoryHandler(){
    if(!file.is_open()){
        file.open("myWindows.txt",ios::out|ios::in);
        file<<0;
        file.close();
    }
    read();
    
}

void MyWindowMemoryHandler::read(){
    file.open("myWindows.txt",ios::in);
    file>>count;
    file.ignore();
    for(int i=0;i<count;i++){
        string title;
        int locX,locY,sizeX,sizeY;
        getline(file, title);
        file >> locX >> locY >> sizeX >> sizeY;
        file.ignore();

        windows.push_back(MyWindow(title,locX,locY,sizeX,sizeY));
    }
    file.close();
}

void MyWindowMemoryHandler::write(){
    file.open("myWindows.txt",ios::out);
    file<<count<<endl;
    for(int i=0;i<count;i++){
        file<<windows[i].title<<endl;
        file<<windows[i].locX<<" ";
        file<<windows[i].locY<<" ";
        file<<windows[i].sizeX<<" ";
        file<<windows[i].sizeY<<endl;
    }
    file.close();
}

void MyWindowMemoryHandler::saveWindow(MyWindow myWindow){
    windows.push_back(myWindow);
}

MyWindow MyWindowMemoryHandler::getWindow(int id){
    try{
        return windows.at(id);
    } catch (const out_of_range& e){
        return MyWindow("",0,0,0,0);
    }
}

void MyWindowMemoryHandler::DeleteWindow(int id){
    ;
}
#endif // 