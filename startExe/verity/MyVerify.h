#pragma once
/*
У����
�ṩ�ӿ�:

*/
#include <vector>

typedef  std::vector<CString>  MYVECTOR;
class MyVerify
{
private:
	MyVerify();
	

private:
	//���汾��mac��ַ
	MYVECTOR m_strMac;
	BOOL GetLocoalIPandMac(MYVECTOR &strMac);
	CString m_strFileName;
public:
	/*��ȡ����mac��ַ*/
	CString ReturnPcMac();
	CString GetEncryptStr(CString const&); //��ȡ���ܺ������
	BOOL  VerityExe();
	BOOL  WriteAndVerityExe(CString const& strVerity);
	~MyVerify();
	static MyVerify* m_singleton;
	static MyVerify* GetInstance();
};

