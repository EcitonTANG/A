#include "Game.h"

Game::Game(){
    option = 0;
    playing = true;
    //some code
}

void Game::mainMenu() {
    cout<<"Main menu"<<endl<<endl;
    cout<<"1. Start"<<endl;
    cout<<"0. Quit"<<endl<<endl;

    cout<<"Choose option: ";
    cin>>option;
    switch (option) {
        case 0: playing = false; break;
        case 1: {
            startGame();
            playMenu();
        };
        default: break;

    }
}

void Game::playMenu(){

    while (option !=0) {
        cout << "Play menu" << endl << endl;
        cout << "1. Explore" << endl;
        cout << "2. Show stats" << endl;
        cout << "0. Quit" << endl << endl;

        cout << "Choose option: ";
        cin >> option;
        switch (option) {
            case 0:
                mainMenu();
                break;
            case 1:
                exploreMenu();
                break;
            case 2: {
                showStats();
                break;
            }
            default:
                break;

        }
    }
}

void Game::exploreMenu(){

    while (option !=0) {
        cout << "Explore menu" << endl << endl;
        //TODO display Enemy encountered


        cout << "1. Fight" << endl;
        cout << "2. Rest (heal HP)" << endl;
        cout << "0. Go back" << endl << endl;

        cout << "Choose option: ";
        cin >> option;
        switch (option) {
            case 0:
                option = 5;
                playMenu();
                break;
            case 1: {
                fight.Battle();
                character.gainExp(10);
                getItem();
                break;
            }
            case 2:
                break;//TODO setHP to maxHP
            default:
                break;

        }
    }
}



void Game::startGame(){
    cout<<"Enter your name: ";
    string name;
    cin>>name;
    character.initialize(name);
}

void Game::getItem(){
    Item item;
    character.setItem(*item.createItem("Sword",1));
}

void Game::showStats(){
    cout<<character.showStats();
}

int Game::getOption() const{
    return option;
}

bool Game::isPlaying() const {
    return playing;
}
