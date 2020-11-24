#include <iostream>
#include <windows.h>
#include <winuser.h>
//#include <conio.h>

using namespace std;
void wellcome(int);

/*
void __fastcall onKey::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
  // do something with Key
}
 //*/

int main(){

    char key;
    bool key_up = false;
    int flag = 0;
bool loop = true;
wellcome(1);
while(loop && flag < 10){
    //cin >> key;
    /*
    if(key == "WHATEVER MATCHED"){
        loop = false;
    } 
    //*/
    //cout<<"neter \n";
    //getch();
    //if(kbhit())break;
    //cout<<key;
    //key_up = GetKeyState(VK_UP) & 0x8000;
    if(  GetKeyState(VK_UP) & 0x8000 ){
        cout<<"up"<< flag << endl;
        //key_up = false;
        //keybd_event(VkKeyScan('A'),0x9e,0,0);
        flag++;
        Sleep(100);

    }
    //*
     if( GetAsyncKeyState(VK_DOWN) & 0x8000){
        cout<<"down"<< flag<< endl;
        flag++;
        Sleep(100);
    }
     //*/
     Sleep(10);
}

    return 0;
}

void wellcome(int opc){
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"\t\t\t\t\t\tWELLCOME !! TO ......!!!\n";
    cout<<"\t\t\t=====\t===    =="   <<"\t=======\t  ==  =="  <<"\t====="   <<endl;
    cout<<"\t\t\t||   \t||\\\\   ||" <<"\t||   ||\t  || // "  <<"\t||"      <<endl;
    cout<<"\t\t\t=====\t|| \\\\  ||" <<"\t||===||\t  |||   "  <<"\t====="   <<endl;
    cout<<"\t\t\t   ||\t||  \\\\ ||" <<"\t||   ||\t  || \\\\ "<<"\t||"      <<endl;
    cout<<"\t\t\t=====\t==   ===="   <<"\t==   ==\t  ==  =="  <<"\t====="   <<endl;
}



