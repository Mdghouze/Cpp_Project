#include<iostream>

using namespace std;

class SingleTone
{
	private :
		int m_variable;
		SingleTone(int temp=100):m_variable(temp){
			cout<<"initializing member m_variable"<<endl;
		}
		static SingleTone* itsSingletone;

	public:
		static SingleTone * m_getinstance(){

				cout<<"initializing singletone instance"<<endl;

				if(itsSingletone == NULL)
				{
					itsSingletone = new SingleTone;
					return itsSingletone;
				}
				else
				{
					return itsSingletone;
				}

			}
				void DisplayMvalue()
				{

				cout<<"Value in M_Variable is "<<m_variable<<endl;
				}

		void SetMvariable(int SetVal)
		{
			this->m_variable = SetVal;
		}

};


SingleTone* SingleTone::itsSingletone = NULL;

int  main(void)
{

	SingleTone *SingleInstance = SingleTone::m_getinstance();

	cout<<"First Instance is created"<<endl;
	SingleInstance->DisplayMvalue();

	SingleInstance->SetMvariable(20);

	cout<<"Change in m_variable is ";
	SingleInstance->DisplayMvalue();	
	return 0;

}