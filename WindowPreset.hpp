#ifndef WINDOWPRESET_HPP
#define WINDOWPRESET_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MyWindow {
private:
    
public:
    string title;
    int locX;
    int locY;
    int sizeX;
    int sizeY;
    MyWindow(string _title,
    int _locX,
    int _locY,
    int _sizeX,
    int _sizeY);
    //~MyWindow();            // 생성자
    //void displayMessage();   // 멤버 함수
};
MyWindow::MyWindow(string _title, int _locX, int _locY, int _sizeX, int _sizeY)
    : title(_title), locX(_locX), locY(_locY), sizeX(_sizeX), sizeY(_sizeY) {
    // 필요한 초기화 코드 작성
}

class WindowPreset{
private:
    
public:
    vector<MyWindow> windows;
    int windowCount;
    WindowPreset(vector<MyWindow> _windows, int _windowCount);
};
WindowPreset::WindowPreset(vector<MyWindow> _windows, int _windowCount)
:windowCount(_windowCount){
    windows=_windows;
}

#endif // 