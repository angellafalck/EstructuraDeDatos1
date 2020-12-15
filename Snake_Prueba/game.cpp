#include "game.h"

using namespace std;


int main()
{
    int op;
    do{
        rlutil::cls(); 
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<<"\n\tSNAKE GAME"<<endl;
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout<<"1- Play Game"<<"\n";
        rlutil::setColor(rlutil::LIGHTRED);
        cout<<"2- Exit Game"<<"\n";
        rlutil::setColor(rlutil::LIGHTBLUE);
        "Option: ";
        cin>>op;

        switch(op)
        {
            case 1:
            start();
            if(!running)
            {
                cout<<"Will you like to play again?"<<endl;
                cout<<"1. YES  2. NO"<<endl;
                cout<<"Option: "<<endl;
                cin>>op;
                
            }
            break;

            case 2:
            rlutil::setColor(rlutil::LIGHTBLUE);
            cout<<"\t....:) Goodbye :).... "<<endl;
            rlutil::setColor(rlutil::LIGHTGREEN);
            break;

            default:
            rlutil::setColor(rlutil::LIGHTRED);
            cout<<"\t..-_- Option not available, please press ENTER -_-.."<<endl;
            cin.get();
            rlutil::anykey();
            rlutil::setColor(rlutil::LIGHTGREEN);
            break;
        }

    }while(op!=2);
    return 0;
}


