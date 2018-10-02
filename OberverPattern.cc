
#include <iostream>
#include<vector>
using namespace std;
class KeySwitchObserver
{
  public:
    virtual void update(int value) = 0;
};

class Subject
{
private:
    int m_value;
    vector<KeySwitchObserver *> m_views;
  public:
  	Subject()
  	{
  		cout<<"dummy constructor"<<endl;
  		m_value = 0;
  	}
    void attach(KeySwitchObserver *obs)
    {
        m_views.push_back(obs);
    }
    void set_val(int value)
    {
        m_value = value;
        notify();
    }
    void notify()
    {
        for (int i = 0; i < m_views.size(); ++i)
        {
        	cout<<"notify is called"<<endl;
          m_views[i]->update(m_value);
        }
    }
};

class KeySwitchListerner: public KeySwitchObserver
{
    int m_Switch_Status;
  public:
    KeySwitchListerner(Subject *model, int status)
    {
        model->attach(this);
        m_Switch_Status = status;
        cout<<"print status "<<m_Switch_Status<<endl;
    }
     virtual void update(int update_Status)
    {
    	cout<<"KeySwitchListerner update is called"<<endl;
    	this->m_Switch_Status = update_Status;
    	if(m_Switch_Status == 1)
    	{
    		cout<<"Key Switch is ON"<<endl;
    	}

        else if( m_Switch_Status == 0)
    	{
    		cout<<"Key Switch is OFF"<<endl;
    	}

    }
};


int main()
{
  Subject subj;
  cout<<"Reached here"<<endl;
  KeySwitchListerner divObs1(&subj, 0);
  subj.set_val(1);
  subj.set_val(0);
  subj.set_val(1);
  subj.set_val(0);
}