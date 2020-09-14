//
//  TerminalEngine.cpp
//  NeuralNet
//
//  Created by Eshaan Arnav on 9/9/20.
//  Copyright © 2020 Eshaan. All rights reserved.
//
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <string>
#include <unistd.h>
using namespace std;
class TerminalEngine {
public:
    int terminal_xSize;
    int terminal_ySize;
    int y_count = 1;
    TerminalEngine (bool no_delay = true, bool hide_cursor = true, bool echo = false) {
        initscr();
        if (no_delay) nodelay(stdscr, TRUE);
        getmaxyx(stdscr, terminal_ySize, terminal_xSize);
        if (hide_cursor) {
            curs_set(0);
        }
        if (!has_colors()) {
            endwin();
            throw invalid_argument("Terminal doesn't support colors");
        }
        if (!echo) noecho();
        keypad(stdscr, TRUE);
        cbreak();
        start_color();
    };
    void set_attr (int index, int colorOne, int colorTwo) {
        init_pair(index, colorOne, colorTwo);
    }
    int get_key_pressed () {
        return getch();
    }
    void print (string text, int xCoord, int yCoord, int attr = -1, bool bold = false) {
        if (attr != -1) attron(COLOR_PAIR(attr));
        if (bold) attron(A_BOLD);
        if (yCoord == -1) mvprintw(y_count, xCoord, text.c_str());
        else mvprintw(yCoord, xCoord, text.c_str());
        
        if (bold) attroff(A_BOLD);
        if (attr != -1) attroff(COLOR_PAIR(attr));
        refresh();
        y_count++;
    }
    void end () {
        refresh();
        getch();
        endwin();
    }
    
    void wait (int millisec) {
        usleep(millisec);
    }
};
