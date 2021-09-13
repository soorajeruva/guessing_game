#include <ctime>
#include "support.h"

auto game()
{
    bool running=true;
    bool success=false;
    int upto=10;
    int turn=0;
    int guessed_num;
    string quit;
    string name;

    cout<<"----------New game---------\n";
    while(true)
    {
        input("\nEnter your name:- ",name);
        if (name.length()>=3)   
        {
            break;
        }
        else
        {
            cout<<"\nTHE NAME SHOULD HAVE ATLEAST 3 CHARACTER.\n";
        }
    }
    cout<<"Hey! "<<name<<", guess a number between 0 and "<<upto<<"; Press any other number to exit\n\n";

    while(running){
        turn++;
        srand(time(NULL));
        int random_num=rand()%(upto+1);

        string out="Chance No."+std::to_string(turn)+" :";
        input(out,guessed_num);

        if (guessed_num<=upto){
            if(guessed_num==random_num){
                success=true;
                cout<<"You won. \nYour took:\t"<<turn<<" chance.\n";
                break;
            }
        }
        else{
            while(true){
                input("\nDo you want to quit?\npress 'Q' to quit\npress 'N' to continue\n\t",quit);
                if (quit =="q" || quit =="Q")
                {
                    running=false;
                    break;
                }
                else if (quit=="n"||quit=="N")
                {
                    turn--;
                    break;
                }
                else{cout<<"\nINVALID ENTRY\n";}
            }
        }
    }
    if (!success){
        cout<<"sorry, you lost!\ntry again?. \n";
        turn=0;
    }
    return std::make_tuple(name,turn);
}
//----------------------------------------------------------------------------------------------------------
int main()
{
    int select;
    bool running=true;
    File file("out/scores.csv");
    while (running)
    {   cout<<"\n---------Welcome to the game---------\n\n";
        input("\n1 ) New Game\n2 ) High-Score\n3 ) Quit\n",select);

        switch(select)
        {
            case 1:
            {
                auto game_data=game();
                if (std::get<1>(game_data))
                {
                    file.write_file(game_data);
                }
                break;
            }
            case 2:
            {   cout<<"\n--------------Highscores-------------\n\n";
                auto print_data=file.get();
                for (auto data:print_data)
                {
                    cout<<data<<"\n";
                }
                break;
            }
            case 3:
                running=false;
                break;
            default:
                cout<<"ENTER VALID NUMBER\n";
        }
    }
    return EXIT_SUCCESS;
}