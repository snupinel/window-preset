#ifndef PRESETMEMORYHANDLER_HPP
#define PRESETMEMORYHANDLER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "WindowPreset.hpp"
#include <string>
using namespace std;

class PresetMemoryHandler{
private:
    fstream file;
    vector<WindowPreset> presets;
public:
    PresetMemoryHandler();
    int length();
    void read();
    void write();
    WindowPreset getPreset(int id);
    void savePreset(WindowPreset myPreset);
    //MyWindow getWindow(int id);
    //void DeleteWindow(int id);
};
PresetMemoryHandler::PresetMemoryHandler(){
    file.open("myPresets.txt",ios::in);
    if(!file.is_open()){
        cout<<"not open"<<endl;
        file.close();
        file.open("myPresets.txt",ios::out);
        file<<0;
    }
    file.close();
    read();
    
}
int PresetMemoryHandler::length(){
    return presets.size();
}
void PresetMemoryHandler::read(){
    file.open("myPresets.txt",ios::in);
    int n;
    file>>n;
    file.ignore();
    for(int i=0;i<n;i++){

        int windowCount;
        file>>windowCount;
        file.ignore();

        vector<MyWindow> windows;

        for(int j=0;j<windowCount;j++){

            string className, processPath;
            int locX,locY,sizeX,sizeY;
            file >>className>>processPath>>locX >> locY >> sizeX >> sizeY;
            file.ignore();

            windows.push_back(MyWindow(className,processPath,locX,locY,sizeX,sizeY));
        }

        presets.push_back(WindowPreset(windows));
        /*
        
        */
    }
    file.close();
}

void PresetMemoryHandler::write(){
    file.open("myPresets.txt",ios::out);
    file<<length()<<endl;
    cout<<presets.size();
    for(int i=0;i<length();i++){

        file<<presets[i].length()<<endl;

        for(int j=0;j<presets[i].length();j++){
            file<<presets[i].windows[j].className<<" ";
            file<<presets[i].windows[j].processPath<<" ";
            file<<presets[i].windows[j].locX<<" ";
            file<<presets[i].windows[j].locY<<" ";
            file<<presets[i].windows[j].sizeX<<" ";
            file<<presets[i].windows[j].sizeY<<endl;
        }
    }
    /*
    */
    file.close();
}

void PresetMemoryHandler::savePreset(WindowPreset myPreset){
    presets.push_back(myPreset);
    write();
}

WindowPreset PresetMemoryHandler:: getPreset(int id){
    try{
        return presets.at(id);
    } catch (const out_of_range& e){
        return WindowPreset();
    }
}
/*
void PresetMemoryHandler::DeleteWindow(int id){
    ;
}*/
#endif // 