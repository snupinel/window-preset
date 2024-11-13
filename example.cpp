#include <Windows.h>
#include <commdlg.h>  // GetOpenFileName 함수를 사용하기 위해 필요
#include <iostream>

void OpenFileDialog() {
    // 파일 경로를 저장할 버퍼
    char filePath[MAX_PATH] = {0};

    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;  // 소유자 윈도우 핸들
    ofn.lpstrFile = filePath;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = "All Files\0*.*\0Text Files\0*.TXT\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    // 파일 선택창을 띄우고 파일을 선택했는지 확인
    if (GetOpenFileName(&ofn)) {
        std::cout << "Selected File: " << ofn.lpstrFile << std::endl;
    } else {
        std::cout << "File selection canceled or failed." << std::endl;
    }
}

int main() {
    OpenFileDialog();
    return 0;
}
