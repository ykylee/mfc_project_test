#include "stdafx.h"
#include "ImageDialogApp.h"
#include "ImageDialogAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CImageDialogApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CImageDialogApp theApp;

BOOL CImageDialogApp::InitInstance()
{
    CWinApp::InitInstance();

    AfxEnableControlContainer();

    CImageDialogDlg dlg;
    m_pMainWnd = &dlg;
    INT_PTR nResponse = dlg.DoModal();
    if (nResponse == IDOK)
    {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with OK
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: Place code here to handle when the dialog is
        //  dismissed with Cancel
    }

    return FALSE;
}
