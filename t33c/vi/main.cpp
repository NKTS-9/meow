#include <iostream>

using namespace std;

class Device {
private:
    bool pwr_;
    bool cl_;
    bool nl_;

public: Device ()
    {
     pwr_=0;
     cl_=0;
     nl_=0;
    }
    void change_pwr () {
        if (pwr_) {pwr_=0; cl_=0; nl_=0;}
        else pwr_=1;
    }
    void change_cl (){
        if (pwr_= 1) cl_=!cl_;
        else cl_=0;
    }
    void change_nl (){
        if (pwr_= 1) nl_=!nl_;
        else nl_=0;
    }
    void change_nlcl (){
        if (pwr_= 1) cl_=!cl_;
        else cl_=0;
    }
    void status (){
    cout << pwr_ << "\t" << cl_ << "\t" << nl_ << "\n" ;
   }
};
int main()
{  Device device;
while (1)
{ device.status ();
  int ch;
  cin >> ch;
  switch ( ch ){
  case 1: device.change_pwr (); break;
  case 2: device.change_cl (); break;
  case 3: device.change_nl (); break;
  case 4: device.change_nlcl (); break;
  default: break;
  }
}
 return 0;
}




