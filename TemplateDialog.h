// TemplateDialog.h

#pragma once

#include <windows.h>

#include "..\Common\Ascii.h"
#include "..\Common\Common.h"

#ifndef IDC_STATIC
#define IDC_STATIC																-1
#endif

#define IDD_TEMPLATE_DIALOG														9000
#define IDC_EDITTEXT                                                            9001

BOOL ShowTemplateDialog( HWND hWndParent, HINSTANCE hInstance, LPTSTR lpszInputText );
