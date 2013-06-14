//operator override
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class CMyString{
	public:
		CMyString(char* pData = NULL);
		CMyString(const CMyString& str);
		CMyString& operator=(const CMyString& str);
		~CMyString(void);
		void print();
	private:
		char* m_pData;
};

CMyString::CMyString(char* pData) {
	if(pData == NULL) {
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else {
		int len = strlen(pData);
		m_pData = new char[len + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::~CMyString() {
	delete[] m_pData;
}

CMyString::CMyString(const CMyString& str) {
	int len = strlen(str.m_pData);
	m_pData = new char[len + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString& CMyString::operator=(const CMyString& str) {
	if(this == &str || &str == NULL)
		return *this;
	//maybe throw exception 
	delete[] m_pData;
	m_pData = NULL;
	if(str.m_pData){
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
	}
	return *this;
}

void CMyString::print() {
	if(m_pData)
		cout << m_pData << endl;
	else
		cout << "NULL" << endl;
}

int main() {
	CMyString str;
	CMyString str1("hello");

	str.print();
	str1.print();
	CMyString str2;
	str = str1 = str2;
	cout << "---after operator=---" << endl;
	str.print();
	str1.print();
	str2.print();
	
	system("pause");
	return 0;
}
