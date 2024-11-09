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
    int presetCount;
public:
    PresetMemoryHandler();
    void read();
    void write();
    void savePreset(WindowPreset myPreset);
    //MyWindow getWindow(int id);
    //void DeleteWindow(int id);
};
PresetMemoryHandler::PresetMemoryHandler(){
    if(!file.is_open()){
        file.open("myPresets.txt",ios::out|ios::in);
        file<<0;
        file.close();
    }
    read();
    
}

void PresetMemoryHandler::read(){
    file.open("myPresets.txt",ios::in);
    file>>presetCount;
    file.ignore();
    for(int i=0;i<presetCount;i++){

        int windowCount;
        file>>windowCount;
        file.ignore();

        vector<MyWindow> windows;

        for(int j=0;j<windowCount;j++){

            string title;
            int locX,locY,sizeX,sizeY;
            getline(file, title);
            file >> locX >> locY >> sizeX >> sizeY;
            file.ignore();

            windows.push_back(MyWindow(title,locX,locY,sizeX,sizeY));
        }

        presets.push_back(WindowPreset(windows,windowCount));
        /*
        
        */
    }
    file.close();
}

void PresetMemoryHandler::write(){
    file.open("myWindows.txt",ios::out);
    file<<presetCount<<endl;

    for(int i=0;i<presetCount;i++){

        file<<presets[i].windowCount<<endl;

        for(int j=0;j<presets[i].windowCount;j++){
            file<<presets[i].windows[j].title<<endl;
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
/*
MyWindow PresetMemoryHandler::getWindow(int id){
    try{
        return windows.at(id);
    } catch (const out_of_range& e){
        return MyWindow("",0,0,0,0);
    }
}

void PresetMemoryHandler::DeleteWindow(int id){
    ;
}*/
#endif // 