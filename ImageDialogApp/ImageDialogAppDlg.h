#pragma once

class CImageDialogDlg : public CDialogEx
{
public:
    CImageDialogDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_IMAGEDIALOG_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    HICON m_hIcon;
    CStatic m_imageBox;
    CButton m_openButton;
    CButton m_closeButton;

    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnOpenImage();
    afx_msg void OnCloseApp();
    DECLARE_MESSAGE_MAP()
};
