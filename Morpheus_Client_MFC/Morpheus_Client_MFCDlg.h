
// Morpheus_Client_MFCDlg.h : 헤더 파일
//

#pragma once


// CMorpheus_Client_MFCDlg 대화 상자
class CMorpheus_Client_MFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CMorpheus_Client_MFCDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MORPHEUS_CLIENT_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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

	CString m_strAddress; //*IP컨트롤에 입력받은 서버의 IP주소를 저장할 변수
	//CMorpheus_Client_MFCApp app;
	afx_msg void OnBnClickedSendtoserver();
};
