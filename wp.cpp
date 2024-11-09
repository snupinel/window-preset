#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <Psapi.h>
#include "MyWindow.hpp"
#include "MyWindowMemoryHandler.hpp"
#pragma comment(lib, "Psapi.lib")  // Psapi 라이브러리 링크
using namespace std;


void save();
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
int main(int argc, char *argv[])
{
    cout<<"wp launched."<<endl;
    vector<string> args(argv, argv + argc);
    MyWindowMemoryHandler myWindowMemoryHandler = MyWindowMemoryHandler();

    //cout<<argc;
    //cout<<args[1];


    if(argc<=1){
        ;
    }
    else if (args[1]=="save"){
        EnumWindows(EnumWindowsProc, 0);
        //save();
    }
    
    return 0;
}
void save(){
    cout<<"Saving..."<<endl;
}
// 콜백 함수: 각 창에 대해 호출됨


// 콜백 함수: 각 창에 대해 호출됨
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    // 창이 보이는 상태인지 확인
    if (IsWindowVisible(hwnd) && IsWindowEnabled(hwnd)) {
        char windowTitle[256];
        GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle));

        // 제목이 있는 창만 확인
        if (strlen(windowTitle) > 0) {
            // 창의 스타일 확인
            LONG style = GetWindowLong(hwnd, GWL_STYLE);

            // 작업 표시줄에 나타나는 일반 창 스타일 필터링
            if ((style & WS_OVERLAPPEDWINDOW) == WS_OVERLAPPEDWINDOW) {
                // 창의 프로세스 ID 가져오기
                DWORD processID;
                GetWindowThreadProcessId(hwnd, &processID);

                // 프로세스 핸들 얻기
                HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);
                if (processHandle) {
                    char processName[MAX_PATH];
                    if (GetModuleFileNameExA(processHandle, NULL, processName, sizeof(processName) / sizeof(char))) {
                        // 'ApplicationFrameHost' 등 시스템 창을 제외할 수 있음
                        std::string name(processName);
                        if (name.find("ApplicationFrameHost") == std::string::npos) {
                            // 창의 위치와 크기를 가져옴
                            RECT rect;
                            GetWindowRect(hwnd, &rect);

                            int x = rect.left;       // 창의 X 좌표 (왼쪽)
                            int y = rect.top;        // 창의 Y 좌표 (위쪽)
                            int width = rect.right - rect.left;   // 창의 너비
                            int height = rect.bottom - rect.top;  // 창의 높이

                            // 최소 크기를 가진 창만 표시 (너비, 높이 모두 100 이상)
                            if (width >= 100 && height >= 100) {
                                
                                std::cout << "Window Handle: " << hwnd 
                                          << " | Title: " << windowTitle 
                                          << " | Process: " << processName
                                         // << " | Position: (" << x << ", " << y << ")"
                                         // << " | Width: " << width 
                                          << " | Height: " << height << std::endl;
                            }
                        }
                    }
                    // 프로세스 핸들 닫기
                    CloseHandle(processHandle);
                }
            }
        }
    }
    return TRUE;  // 다음 창으로 이동
}