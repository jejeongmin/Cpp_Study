// SmartPtr.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Dummy.h"

void	AutoPtrFunction(auto_ptr<CDummy>& ptr);	// ���������� ����

void	AutoPtrTest();
void	SharedPtrTest();
void	UniquePtrTest();
// scoped_ptr �� boost ���� �����ϳ� tr1 ������ �������� �ʴ� �� ����.
// �ٵ� weak_ptr �� �����ϳ�

int _tmain(int argc, _TCHAR* argv[])
{
	AutoPtrTest();
	//SharedPtrTest();
	//UniquePtrTest();

	_getch();

	return 0;
}

void AutoPtrTest()
{
	auto_ptr<CDummy> ptr1(new CDummy);
	auto_ptr<CDummy> ptr2;
	CDummy	*ptr3	= NULL;

	ptr1->print();	// ȣ�� �� ��

	AutoPtrFunction(ptr1);	// ���������� �Լ��� �������� ������ �� �Լ� ȣ���� ���� �������� ptr1 �� ��ȿ���� ����ϰ� ����.

	//ptr2 = ptr1;	// ptr2 �� ������ ����, �� �������� ptr1 �� invalid

	/* 
		raw pointer�� ��ü�� �����ϸ� �ش� smart ptr �ν��� ����� ������ ����.. 
		�̶�� �������, VS 2010 ~ VS2017 ������ raw pointer ���� �ڿ��� �� ������.
		�Ƹ� VS2008 �����̳�, Boost ������ �׷������� ������
		auto_ptr ��ü�� ���� deprecated spec �̾ �� ã�ƺ� �ʿ�� ������
	*/
	ptr3	= ptr1.get();	
	ptr1->print();	// ȣ�� �� ��
	ptr3->print();	// ȣ�� �� ��
	ptr2->print();	// ȣ�� �� ��

	ptr1->print();	// �̹� invalid �� ������ �̹Ƿ� ����

	ptr2.reset();

	ptr2->print();	// �����͸� �ʱ�ȭ �ع������� ȣ�� �� ��
}

void	AutoPtrFunction(auto_ptr<CDummy>& ptr)
{
	ptr->print();
}

void SharedPtrTest()
{
	shared_ptr<CDummy> ptr1(new CDummy);
	vector<shared_ptr<CDummy>> dummys;

	ptr1->print();

	dummys.push_back(ptr1);
	dummys.push_back(ptr1);
	dummys.push_back(ptr1);

	for each(auto i in dummys)	// ��� shared_ptr�� ���ؼ� ������ ������ ���� ���� �� �������� ������ ��
	{
		(*i).print();
	}
}

void UniquePtrTest()
{
	unique_ptr<CDummy>	ptr1(new CDummy);
	unique_ptr<CDummy>	ptr2;

	ptr1->print();

	ptr2 = move(ptr1);			// ptr1 �� ��ȿȭ ��
	ptr2->print();				// ȣ�� ����

	ptr2.reset();				// ptr2 �� ��ȿȭ ��

	ptr1->print();				// ȣ�� ����
	ptr2->print();				// ȣ�� ����
}