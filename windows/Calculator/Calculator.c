#include <windows.h>
#include <stdlib.h>
#include <string.h>

#define ID_EDIT_RESULT 1000
#define ID_BUTTON_0    1001
#define ID_BUTTON_1    1002
#define ID_BUTTON_2    1003
#define ID_BUTTON_3    1004
#define ID_BUTTON_4    1005
#define ID_BUTTON_5    1006
#define ID_BUTTON_6    1007
#define ID_BUTTON_7    1008
#define ID_BUTTON_8    1009
#define ID_BUTTON_9    1010
#define ID_BUTTON_ADD   2000
#define ID_BUTTON_SUB   2001
#define ID_BUTTON_MUL   2002
#define ID_BUTTON_DIV   2003
#define ID_BUTTON_EQUAL 3000

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nShowCmd) {
    HWND hwnd;
    MSG msg;

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = "Calculator";

    RegisterClass(&wc);

    hwnd = CreateWindow("Calculator", "간단한 Windows 계산기",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 400, NULL, NULL, hInstance, NULL);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HWND hEditResult;

    switch (msg) {
    case WM_CREATE:
        // 결과 텍스트박스 생성
        hEditResult = CreateWindow("EDIT", "",
            WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_NUMBER,
            10, 10, 280, 30, hwnd, (HMENU)ID_EDIT_RESULT, NULL, NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == ID_BUTTON_EQUAL) {
            // 계산 버튼 눌렀을 때
            char buffer[256];
            GetWindowText(hEditResult, buffer, sizeof(buffer));
            double result = 0;
            int len = strlen(buffer);

            // 간단한 수식 처리 (예: 1+2*3/4)
            // 이 예제에서는 단순히 입력된 값을 사용합니다. 실際에는 계산기를 구현해야 합니다.
            // 여기서는 예시를 위해 0을 반환하도록 하겠습니다.
            SetWindowText(hEditResult, "0");
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}