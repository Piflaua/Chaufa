#include <Chaufa.h>
#include <windows.h>

const char windowClassName[] = "chaufa_window";
HINSTANCE hInstance = NULL;
HWND hWindow = NULL;

void chaufaInitializeWindow(const char windowTitle[], int windowWidth, int windowHeight, bool isWindowResizable) {
	hInstance = GetModuleHandle(NULL);
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = windowClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wc);

	RECT screenRect;
	GetWindowRect(GetDesktopWindow(), &screenRect);

	DWORD style = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION;
	if (isWindowResizable) {
		style |= WS_MAXIMIZEBOX | WS_THICKFRAME;
	}

	hWindow = CreateWindowEx(
		WS_EX_APPWINDOW,
		windowClassName,
		windowTitle,
		style,
		(screenRect.right - screenRect.left - windowWidth) / 2,
		(screenRect.bottom - screenRect.top - windowHeight) / 2,
		windowWidth,
		windowHeight,
		NULL,
		NULL,
		hInstance,
		NULL
	);
}

void chaufaTerminateWindow() {
	DestroyWindow(hWindow);
	UnregisterClass(windowClassName, hInstance);
}