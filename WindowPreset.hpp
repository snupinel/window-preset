#ifndef WINDOWPRESET_HPP
#define WINDOWPRESET_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MyWindow {
private:
    
public:
    string className;
    int locX;
    int locY;
    int sizeX;
    int sizeY;
    string processPath;
    MyWindow(string _className, string _processPath,
    int _locX,
    int _locY,
    int _sizeX,
    int _sizeY);
    //~MyWindow();            // 생성자
    //void displayMessage();   // 멤버 함수
};
MyWindow::MyWindow(string _className, string _processPath, int _locX, int _locY, int _sizeX, int _sizeY)
    : className(_className), processPath(_processPath), locX(_locX), locY(_locY), sizeX(_sizeX), sizeY(_sizeY) {
    // 필요한 초기화 코드 작성
}

class WindowPreset{
private:
    
public:
    vector<MyWindow> windows;
    //int windowCount;
    int length();
    void add(MyWindow myWindow);
    void clear();
    WindowPreset();
    WindowPreset(vector<MyWindow> _windows);
};
int WindowPreset::length(){
    return windows.size();
}
void WindowPreset::add(MyWindow myWindow){
    windows.push_back(myWindow);
}
WindowPreset::WindowPreset(){
    ;
}
WindowPreset::WindowPreset(vector<MyWindow> _windows)
{
    windows=_windows;
}
void WindowPreset::clear(){
    windows.clear();
}
#endif // 