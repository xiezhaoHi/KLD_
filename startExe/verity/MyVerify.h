#pragma once
/*
校验类
提供接口:

*/
#include <vector>

typedef  std::vector<CString>  MYVECTOR;
class MyVerify
{
private:
	MyVerify();
	

private:
	//保存本机mac地址
	MYVECTOR m_strMac;
	BOOL GetLocoalIPandMac(MYVECTOR &strMac);
	CString m_strFileName;
public:
	/*获取本地mac地址*/
	CString ReturnPcMac();
	CString GetEncryptStr(CString const&); //获取加密后的数据
	BOOL  VerityExe();
	BOOL  WriteAndVerityExe(CString const& strVerity);
	~MyVerify();
	static MyVerify* m_singleton;
	static MyVerify* GetInstance();
};

