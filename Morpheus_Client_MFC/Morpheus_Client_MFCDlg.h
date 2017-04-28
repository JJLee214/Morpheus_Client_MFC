
// Morpheus_Client_MFCDlg.h : ��� ����
//

#pragma once


// CMorpheus_Client_MFCDlg ��ȭ ����
class CMorpheus_Client_MFCDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMorpheus_Client_MFCDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MORPHEUS_CLIENT_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnIpnFieldchangedMylocalip(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnIpnFieldchangedServerlocalip(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedDisconnect();

	CString m_strAddress; //*IP��Ʈ�ѿ� �Է¹��� ������ IP�ּҸ� ������ ����
	//CMorpheus_Client_MFCApp app;
	afx_msg void OnBnClickedSendtoserver();
};
