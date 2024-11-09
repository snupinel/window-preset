#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include <string>
#include <iostream>

using namespace std;

class MyWindow {
private:
    string title;
    int locX;
    int locY;
    int sizeX;
    int sizeY;
public:
    MyWindow(string _title,
    int _locX,
    int _locY,
    int _sizeX,
    int _sizeY);
    //~MyWindow();            // 생성자
    //void displayMessage();   // 멤버 함수
};
MyWindow::MyWindow(string _title,
    int _locX,
    int _locY,
    int _sizeX,
    int _sizeY){
    title=_title;
    locX=_locX;
    locY=_locY;
    sizeX=_sizeX;
    sizeY=_sizeY;
}
#endif // 