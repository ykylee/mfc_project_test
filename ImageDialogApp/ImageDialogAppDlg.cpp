#include "stdafx.h"
#include "ImageDialogApp.h"
#include "ImageDialogAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CImageDialogDlg::CImageDialogDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_IMAGEDIALOG_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageDialogDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_IMAGE_AREA, m_imageBox);
    DDX_Control(pDX, IDC_OPEN_BUTTON, m_openButton);
    DDX_Control(pDX, IDC_CLOSE_BUTTON, m_closeButton);
}

BEGIN_MESSAGE_MAP(CImageDialogDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_OPEN_BUTTON, &CImageDialogDlg::OnOpenImage)
    ON_BN_CLICKED(IDC_CLOSE_BUTTON, &CImageDialogDlg::OnCloseApp)
END_MESSAGE_MAP()

BOOL CImageDialogDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    return TRUE;
}

void CImageDialogDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this);
        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

HCURSOR CImageDialogDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CImageDialogDlg::OnOpenImage()
{
    CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, _T("Image Files|*.bmp;*.jpg;*.png;*.gif|All Files|*.*||"));
    if (dlg.DoModal() == IDOK)
    {
        CString path = dlg.GetPathName();
        HBITMAP hBmp = (HBITMAP)::LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        if (hBmp)
        {
            m_imageBox.SetBitmap(hBmp);
        }
    }
}

void CImageDialogDlg::OnCloseApp()
{
    EndDialog(IDCANCEL);
}
