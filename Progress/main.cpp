//
//  main.cpp
//  Progress
//
//  Created by joao lopes on 28/06/16.
//  Copyright © 2016 joao lopes. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <stdio.h>


using namespace std;


class pBar {
public:
    void update(double newProgress) {
        currentProgress += newProgress;
        amountOfFiller = (int)((currentProgress / neededProgress)*(double)pBarLength);
    }
    void print() {
        currUpdateVal %= pBarUpdater.length();
        cout << "\r" //Bring cursor to start of line
        << firstPartOfpBar; //Print out first part of pBar
        for (int a = 0; a < amountOfFiller; a++) { //Print out current progress
            cout << pBarFiller;
        }
        cout << pBarUpdater[currUpdateVal];
        for (int b = 0; b < pBarLength - amountOfFiller; b++) { //Print out spaces
            cout << " ";
        }
        cout << lastPartOfpBar //Print out last part of progress bar
        << " (" << (int)(100*(currentProgress/neededProgress)) << "%)" //This just prints out the percent
        << flush;
        currUpdateVal += 1;
    }
    std::string firstPartOfpBar = "[", //Change these at will (that is why I made them public)
    lastPartOfpBar = "]",
    pBarFiller = "█",
    pBarUpdater = "/-\\|";
private:
    int amountOfFiller,
    pBarLength = 50, //I would recommend NOT changing this
    currUpdateVal = 0; //Do not change
    double currentProgress = 0, //Do not change
    neededProgress = 100; //I would recommend NOT changing this
};


int main(int argc, const char * argv[]) {
    //Setup:
    pBar bar;
    //Main loop:
    for (int i = 0; i < 100; i++) { //This can be any loop, but I just made this as an example
        //Update pBar:
        bar.update(1); //How much new progress was added (only needed when new progress was added)
        //Print pBar:
        bar.print(); //This should be called more frequently than it is in this demo (you'll have to see what looks best for your program)
        sleep(1);
        
    }
    cout << endl;
    return 0;
}
