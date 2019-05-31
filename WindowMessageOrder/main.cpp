﻿#include <Windows.h>
#include <map>
#include <strsafe.h>

using std::map;
using std::string;
map<UINT, PCTSTR> MsgMap;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
PCTSTR GetStringMessage(UINT msg);
void InitMessageStruct();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    InitMessageStruct();
    WNDCLASS wndclass;
    TCHAR pAppName[] = TEXT("WINDCLASS");
    HWND hWnd;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.hCursor = LoadCursor(NULL, IDC_HAND);
    wndclass.hIcon = LoadIcon(NULL, IDI_ASTERISK);
    wndclass.hInstance = hInstance;
    wndclass.lpfnWndProc = WndProc;
    wndclass.lpszClassName = TEXT("WINDCLASS");
    wndclass.lpszMenuName = NULL;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("CANNOT run on windows 98"), TEXT("This is caption"), MB_OK | MB_ICONERROR);
        return -1;
    }

    hWnd = CreateWindow(pAppName, TEXT("This is window title"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    TCHAR str[100];
    StringCbPrintf(str, _countof(str), TEXT("Message ID:%-6x:%s"), msg, GetStringMessage(msg));
    OutputDebugString(str);
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
    switch (msg)
    {
    case  WM_CREATE:
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        GetClientRect(hWnd, &rect);
        DrawText(hdc, TEXT("DRAW TEXT ON CLIENT AREA"), -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

PCTSTR GetStringMessage(UINT msg)
{
    if (MsgMap.count(msg))
    {
        return MsgMap[msg];
    }
    else
    {
        return TEXT("UNKNOW MESSAGE");
    }
}

void InitMessageStruct()
{
    MsgMap[WM_ACTIVATEAPP] = TEXT("WM_ACTIVATEAPP");
    MsgMap[WM_SYNCPAINT] = TEXT("WM_SYNCPAINT");
    MsgMap[WM_NCPAINT] = TEXT("WM_NCPAINT");
    MsgMap[WM_PAINT] = TEXT("WM_PAINT");
    MsgMap[WM_IME_SETCONTEXT] = TEXT("WM_IME_SETCONTEXT");
    MsgMap[WM_IME_NOTIFY] = TEXT("WM_IME_NOTIFY");
    MsgMap[WM_IME_SETCONTEXT] = TEXT("WM_IME_SETCONTEXT");
    MsgMap[WM_IME_SETCONTEXT] = TEXT("WM_IME_SETCONTEXT");
    MsgMap[WM_IME_SETCONTEXT] = TEXT("WM_IME_SETCONTEXT");
    MsgMap[WM_CANCELMODE] = TEXT("WM_CANCELMODE");
    MsgMap[WM_CHILDACTIVATE] = TEXT("WM_CHILDACTIVATE");
    MsgMap[WM_CLOSE] = TEXT("WM_CLOSE");
    MsgMap[WM_COMPACTING] = TEXT("WM_COMPACTING");
    MsgMap[WM_CREATE] = TEXT("WM_CREATE");
    MsgMap[WM_DESTROY] = TEXT("WM_DESTROY");
    MsgMap[WM_DPICHANGED] = TEXT("WM_DPICHANGED");
    MsgMap[WM_ENABLE] = TEXT("WM_ENABLE");
    MsgMap[WM_ENTERSIZEMOVE] = TEXT("WM_ENTERSIZEMOVE");
    MsgMap[WM_EXITSIZEMOVE] = TEXT("WM_EXITSIZEMOVE");
    MsgMap[WM_GETICON] = TEXT("WM_GETICON");
    MsgMap[WM_GETMINMAXINFO] = TEXT("WM_GETMINMAXINFO");
    MsgMap[WM_INPUTLANGCHANGE] = TEXT("WM_INPUTLANGCHANGE");
    MsgMap[WM_INPUTLANGCHANGEREQUEST] = TEXT("WM_INPUTLANGCHANGEREQUEST");
    MsgMap[WM_MOVE] = TEXT("WM_MOVE");
    MsgMap[WM_MOVING] = TEXT("WM_MOVING");
    MsgMap[WM_NCACTIVATE] = TEXT("WM_NCACTIVATE");
    MsgMap[WM_NCCALCSIZE] = TEXT("WM_NCCALCSIZE");
    MsgMap[WM_NCCREATE] = TEXT("WM_NCCREATE");
    MsgMap[WM_NCDESTROY] = TEXT("WM_NCDESTROY");
    MsgMap[WM_NULL] = TEXT("WM_NULL");
    MsgMap[WM_QUERYDRAGICON] = TEXT("WM_QUERYDRAGICON");
    MsgMap[WM_QUERYOPEN] = TEXT("WM_QUERYOPEN");
    MsgMap[WM_QUIT] = TEXT("WM_QUIT");
    MsgMap[WM_SHOWWINDOW] = TEXT("WM_SHOWWINDOW");
    MsgMap[WM_SIZE] = TEXT("WM_SIZE");
    MsgMap[WM_SIZING] = TEXT("WM_SIZING");
    MsgMap[WM_STYLECHANGED] = TEXT("WM_STYLECHANGED");
    MsgMap[WM_STYLECHANGING] = TEXT("WM_STYLECHANGING");
    MsgMap[WM_THEMECHANGED] = TEXT("WM_USERCHANGED");
    MsgMap[WM_WINDOWPOSCHANGED] = TEXT("WM_WINDOWPOSCHANGED");
    MsgMap[WM_WINDOWPOSCHANGING] = TEXT("WM_WINDOWPOSCHANGING");
    MsgMap[WM_ACTIVATE] = TEXT("WM_ACTIVATE");
    MsgMap[WM_APPCOMMAND] = TEXT("WM_APPCOMMAND");
    MsgMap[WM_ASKCBFORMATNAME] = TEXT("WM_ASKCBFORMATNAME");
    MsgMap[WM_CANCELJOURNAL] = TEXT("WM_CANCELJOURNAL");
    MsgMap[WM_CAPTURECHANGED] = TEXT("WM_CAPTURECHANGED");
    MsgMap[WM_CHANGECBCHAIN] = TEXT("WM_CHANGECBCHAIN");
    MsgMap[WM_CHANGEUISTATE] = TEXT("WM_CHANGEUISTATE");
    MsgMap[WM_CHAR] = TEXT("WM_CHAR");
    MsgMap[WM_CHARTOITEM] = TEXT("WM_CHARTOITEM");
    MsgMap[WM_CHOOSEFONT_GETLOGFONT] = TEXT("WM_CHOOSEFONT_GETLOGFONT");
    MsgMap[WM_CHOOSEFONT_SETFLAGS] = TEXT("WM_CHOOSEFONT_SETFLAGS");
    MsgMap[WM_CHOOSEFONT_SETLOGFONT] = TEXT("WM_CHOOSEFONT_SETLOGFONT");
    MsgMap[WM_CLEAR] = TEXT("WM_CLEAR");
    MsgMap[WM_CLIPBOARDUPDATE] = TEXT("WM_CLIPBOARDUPDATE");
    MsgMap[WM_COMMAND] = TEXT("WM_COMMAND");
    MsgMap[WM_COMPAREITEM] = TEXT("WM_COMPAREITEM");
    MsgMap[WM_CONTEXTMENU] = TEXT("WM_CONTEXTMENU");
    MsgMap[WM_COPY] = TEXT("WM_COPY");
    MsgMap[WM_COPYDATA] = TEXT("WM_COPYDATA");
    MsgMap[WM_CTLCOLORBTN] = TEXT("WM_CTLCOLORBTN");
    MsgMap[WM_CTLCOLORDLG] = TEXT("WM_CTLCOLORDLG");
    MsgMap[WM_CTLCOLOREDIT] = TEXT("WM_CTLCOLOREDIT");
    MsgMap[WM_CTLCOLORLISTBOX] = TEXT("WM_CTLCOLORLISTBOX");
    MsgMap[WM_CTLCOLORSCROLLBAR] = TEXT("WM_CTLCOLORSCROLLBAR");
    MsgMap[WM_CTLCOLORSTATIC] = TEXT("WM_CTLCOLORSTATIC");
    MsgMap[WM_CUT] = TEXT("WM_CUT");
    MsgMap[WM_DDE_ACK] = TEXT("WM_DDE_ACK");
    MsgMap[WM_DDE_ADVISE] = TEXT("WM_DDE_ADVISE");
    MsgMap[WM_DDE_DATA] = TEXT("WM_DDE_DATA");
    MsgMap[WM_DDE_EXECUTE] = TEXT("WM_DDE_EXECUTE");
    MsgMap[WM_DDE_INITIATE] = TEXT("WM_DDE_INITIATE");
    MsgMap[WM_DDE_POKE] = TEXT("WM_DDE_POKE");
    MsgMap[WM_DDE_REQUEST] = TEXT("WM_DDE_REQUEST");
    MsgMap[WM_DDE_TERMINATE] = TEXT("WM_DDE_TERMINATE");
    MsgMap[WM_DDE_UNADVISE] = TEXT("WM_DDE_UNADVISE");
    MsgMap[WM_DEADCHAR] = TEXT("WM_DEADCHAR");
    MsgMap[WM_DELETEITEM] = TEXT("WM_DELETEITEM");
    MsgMap[WM_DESTROYCLIPBOARD] = TEXT("WM_DESTROYCLIPBOARD");
    MsgMap[WM_DEVICECHANGE] = TEXT("WM_DEVICECHANGE");
    MsgMap[WM_DRAWCLIPBOARD] = TEXT("WM_DRAWCLIPBOARD");
    MsgMap[WM_DRAWITEM] = TEXT("WM_DRAWITEM");
    MsgMap[WM_DWMCOLORIZATIONCOLORCHANGED] = TEXT("WM_DWMCOLORIZATIONCOLORCHANGED");
    MsgMap[WM_DWMCOMPOSITIONCHANGED] = TEXT("WM_DWMCOMPOSITIONCHANGED");
    MsgMap[WM_DWMNCRENDERINGCHANGED] = TEXT("WM_DWMNCRENDERINGCHANGED");
    MsgMap[WM_DWMSENDICONICLIVEPREVIEWBITMAP] = TEXT("WM_DWMSENDICONICLIVEPREVIEWBITMAP");
    MsgMap[WM_DWMSENDICONICTHUMBNAIL] = TEXT("WM_DWMSENDICONICTHUMBNAIL");
    MsgMap[WM_DWMWINDOWMAXIMIZEDCHANGE] = TEXT("WM_DWMWINDOWMAXIMIZEDCHANGE");
    MsgMap[WM_ENTERIDLE] = TEXT("WM_ENTERIDLE");
    MsgMap[WM_ENTERMENULOOP] = TEXT("WM_ENTERMENULOOP");
    MsgMap[WM_ERASEBKGND] = TEXT("WM_ERASEBKGND");
    MsgMap[WM_EXITMENULOOP] = TEXT("WM_EXITMENULOOP");
    MsgMap[WM_GETDLGCODE] = TEXT("WM_GETDLGCODE");
    MsgMap[WM_GETFONT] = TEXT("WM_GETFONT");
    MsgMap[WM_GETHOTKEY] = TEXT("WM_GETHOTKEY");
    MsgMap[WM_GETTEXT] = TEXT("WM_GETTEXT");
    MsgMap[WM_GETTEXTLENGTH] = TEXT("WM_GETTEXTLENGTH");
    MsgMap[WM_GETTITLEBARINFOEX] = TEXT("WM_GETTITLEBARINFOEX");
    MsgMap[WM_HOTKEY] = TEXT("WM_HOTKEY");
    MsgMap[WM_HSCROLL] = TEXT("WM_HSCROLL");
    MsgMap[WM_HSCROLLCLIPBOARD] = TEXT("WM_HSCROLLCLIPBOARD");
    MsgMap[WM_INITDIALOG] = TEXT("WM_INITDIALOG");
    MsgMap[WM_INITMENU] = TEXT("WM_INITMENU");
    MsgMap[WM_INITMENUPOPUP] = TEXT("WM_INITMENUPOPUP");
    MsgMap[WM_INPUT] = TEXT("WM_INPUT");
    MsgMap[WM_INPUT_DEVICE_CHANGE] = TEXT("WM_INPUT_DEVICE_CHANGE");
    MsgMap[WM_KEYDOWN] = TEXT("WM_KEYDOWN");
    MsgMap[WM_KEYUP] = TEXT("WM_KEYUP");
    MsgMap[WM_KILLFOCUS] = TEXT("WM_KILLFOCUS");
    MsgMap[WM_LBUTTONDBLCLK] = TEXT("WM_LBUTTONDBLCLK");
    MsgMap[WM_LBUTTONDOWN] = TEXT("WM_LBUTTONDOWN");
    MsgMap[WM_LBUTTONUP] = TEXT("WM_LBUTTONUP");
    MsgMap[WM_MBUTTONDBLCLK] = TEXT("WM_MBUTTONDBLCLK");
    MsgMap[WM_MBUTTONDOWN] = TEXT("WM_MBUTTONDOWN");
    MsgMap[WM_MBUTTONUP] = TEXT("WM_MBUTTONUP");
    MsgMap[WM_MDIACTIVATE] = TEXT("WM_MDIACTIVATE");
    MsgMap[WM_MDICASCADE] = TEXT("WM_MDICASCADE");
    MsgMap[WM_MDICREATE] = TEXT("WM_MDICREATE");
    MsgMap[WM_MDIDESTROY] = TEXT("WM_MDIDESTROY");
    MsgMap[WM_MDIGETACTIVE] = TEXT("WM_MDIGETACTIVE");
    MsgMap[WM_MDIICONARRANGE] = TEXT("WM_MDIICONARRANGE");
    MsgMap[WM_MDIMAXIMIZE] = TEXT("WM_MDIMAXIMIZE");
    MsgMap[WM_MDINEXT] = TEXT("WM_MDINEXT");
    MsgMap[WM_MDIREFRESHMENU] = TEXT("WM_MDIREFRESHMENU");
    MsgMap[WM_MDIRESTORE] = TEXT("WM_MDIRESTORE");
    MsgMap[WM_MDISETMENU] = TEXT("WM_MDISETMENU");
    MsgMap[WM_MDITILE] = TEXT("WM_MDITILE");
    MsgMap[WM_MEASUREITEM] = TEXT("WM_MEASUREITEM");
    MsgMap[WM_MENUCHAR] = TEXT("WM_MENUCHAR");
    MsgMap[WM_MENUCOMMAND] = TEXT("WM_MENUCOMMAND");
    MsgMap[WM_MENUDRAG] = TEXT("WM_MENUDRAG");
    MsgMap[WM_MENUGETOBJECT] = TEXT("WM_MENUGETOBJECT");
    MsgMap[WM_MENURBUTTONUP] = TEXT("WM_MENURBUTTONUP");
    MsgMap[WM_MENUSELECT] = TEXT("WM_MENUSELECT");
    MsgMap[WM_MOUSEACTIVATE] = TEXT("WM_MOUSEACTIVATE");
    MsgMap[WM_MOUSEHOVER] = TEXT("WM_MOUSEHOVER");
    MsgMap[WM_MOUSEHWHEEL] = TEXT("WM_MOUSEHWHEEL");
    MsgMap[WM_MOUSELEAVE] = TEXT("WM_MOUSELEAVE");
    MsgMap[WM_MOUSEMOVE] = TEXT("WM_MOUSEMOVE");
    MsgMap[WM_MOUSEWHEEL] = TEXT("WM_MOUSEWHEEL");
    MsgMap[WM_NCHITTEST] = TEXT("WM_NCHITTEST");
    MsgMap[WM_NCLBUTTONDBLCLK] = TEXT("WM_NCLBUTTONDBLCLK");
    MsgMap[WM_NCLBUTTONDOWN] = TEXT("WM_NCLBUTTONDOWN");
    MsgMap[WM_NCLBUTTONUP] = TEXT("WM_NCLBUTTONUP");
    MsgMap[WM_NCMBUTTONDBLCLK] = TEXT("WM_NCMBUTTONDBLCLK");
    MsgMap[WM_NCMBUTTONDOWN] = TEXT("WM_NCMBUTTONDOWN");
    MsgMap[WM_NCMBUTTONUP] = TEXT("WM_NCMBUTTONUP");
    MsgMap[WM_NCMOUSEHOVER] = TEXT("WM_NCMOUSEHOVER");
    MsgMap[WM_NCMOUSELEAVE] = TEXT("WM_NCMOUSELEAVE");
    MsgMap[WM_NCMOUSEMOVE] = TEXT("WM_NCMOUSEMOVE");
    MsgMap[WM_NCRBUTTONDBLCLK] = TEXT("WM_NCRBUTTONDBLCLK");
    MsgMap[WM_NCRBUTTONDOWN] = TEXT("WM_NCRBUTTONDOWN");
    MsgMap[WM_NCRBUTTONUP] = TEXT("WM_NCRBUTTONUP");
    MsgMap[WM_NCXBUTTONDBLCLK] = TEXT("WM_NCXBUTTONDBLCLK");
    MsgMap[WM_NCXBUTTONDOWN] = TEXT("WM_NCXBUTTONDOWN");
    MsgMap[WM_NCXBUTTONUP] = TEXT("WM_NCXBUTTONUP");
    MsgMap[WM_NEXTDLGCTL] = TEXT("WM_NEXTDLGCTL");
    MsgMap[WM_NEXTMENU] = TEXT("WM_NEXTMENU");
    MsgMap[WM_NOTIFY] = TEXT("WM_NOTIFY");
    MsgMap[WM_NOTIFYFORMAT] = TEXT("WM_NOTIFYFORMAT");
    MsgMap[WM_PAINTCLIPBOARD] = TEXT("WM_PAINTCLIPBOARD");
    MsgMap[WM_PASTE] = TEXT("WM_PASTE");
    MsgMap[WM_PSD_ENVSTAMPRECT] = TEXT("WM_PSD_ENVSTAMPRECT");
    MsgMap[WM_PSD_FULLPAGERECT] = TEXT("WM_PSD_FULLPAGERECT");
    MsgMap[WM_PSD_GREEKTEXTRECT] = TEXT("WM_PSD_GREEKTEXTRECT");
    MsgMap[WM_PSD_MARGINRECT] = TEXT("WM_PSD_MARGINRECT");
    MsgMap[WM_PSD_MINMARGINRECT] = TEXT("WM_PSD_MINMARGINRECT");
    MsgMap[WM_PSD_PAGESETUPDLG] = TEXT("WM_PSD_PAGESETUPDLG");
    MsgMap[WM_PSD_YAFULLPAGERECT] = TEXT("WM_PSD_YAFULLPAGERECT");
    MsgMap[WM_QUERYUISTATE] = TEXT("WM_QUERYUISTATE");
    MsgMap[WM_QUEUESYNC] = TEXT("WM_QUEUESYNC");
    MsgMap[WM_RBUTTONDBLCLK] = TEXT("WM_RBUTTONDBLCLK");
    MsgMap[WM_RBUTTONDOWN] = TEXT("WM_RBUTTONDOWN");
    MsgMap[WM_RBUTTONUP] = TEXT("WM_RBUTTONUP");
    MsgMap[WM_RENDERALLFORMATS] = TEXT("WM_RENDERALLFORMATS");
    MsgMap[WM_RENDERFORMAT] = TEXT("WM_RENDERFORMAT");
    MsgMap[WM_SETCURSOR] = TEXT("WM_SETCURSOR");
    MsgMap[WM_SETFOCUS] = TEXT("WM_SETFOCUS");
    MsgMap[WM_SETFONT] = TEXT("WM_SETFONT");
    MsgMap[WM_SETHOTKEY] = TEXT("WM_SETHOTKEY");
    MsgMap[WM_SETICON] = TEXT("WM_SETICON");
    MsgMap[WM_SETTEXT] = TEXT("WM_SETTEXT");
    MsgMap[WM_SIZECLIPBOARD] = TEXT("WM_SIZECLIPBOARD");
    MsgMap[WM_SYSCHAR] = TEXT("WM_SYSCHAR");
    MsgMap[WM_SYSCOMMAND] = TEXT("WM_SYSCOMMAND");
    MsgMap[WM_SYSDEADCHAR] = TEXT("WM_SYSDEADCHAR");
    MsgMap[WM_SYSKEYDOWN] = TEXT("WM_SYSKEYDOWN");
    MsgMap[WM_SYSKEYUP] = TEXT("WM_SYSKEYUP");
    MsgMap[WM_TIMER] = TEXT("WM_TIMER");
    MsgMap[WM_UNDO] = TEXT("WM_UNDO");
    MsgMap[WM_UNICHAR] = TEXT("WM_UNICHAR");
    MsgMap[WM_UNINITMENUPOPUP] = TEXT("WM_UNINITMENUPOPUP");
    MsgMap[WM_UPDATEUISTATE] = TEXT("WM_UPDATEUISTATE");
    MsgMap[WM_VKEYTOITEM] = TEXT("WM_VKEYTOITEM");
    MsgMap[WM_VSCROLL] = TEXT("WM_VSCROLL");
    MsgMap[WM_VSCROLLCLIPBOARD] = TEXT("WM_VSCROLLCLIPBOARD");
    MsgMap[WM_XBUTTONDBLCLK] = TEXT("WM_XBUTTONDBLCLK");
    MsgMap[WM_XBUTTONDOWN] = TEXT("WM_XBUTTONDOWN");
    MsgMap[WM_XBUTTONUP] = TEXT("WM_XBUTTONUP");
}