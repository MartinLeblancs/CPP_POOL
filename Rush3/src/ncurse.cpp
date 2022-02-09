/*
** EPITECH PROJECT, 2022
** ncurses
** File description:
** ncurses
*/

#include <string.h>
#include <cstdlib>
#include <iomanip>
#include "../include/IMonitorDisplay.hpp"

void print_welcome_msg(WINDOW *Box)
{
    attron(A_BOLD | COLOR_PAIR(1));
    mvprintw(4, (COLS / 2) - 5, "WELCOME");
    mvprintw(5, (COLS / 2) - 3, "TO");
    mvprintw(6, (COLS / 2) - 6, "MYGKRELLM");
    attroff(A_BOLD | COLOR_PAIR(1));

}

void print_data(Data::UserInfo Info, Data::DateTime Date, Data::SystemInfo Sysinfo, Data::CPUinfos Cpu)
{
    int x = 0;
    int y = 0;

    attron(A_DIM);
    mvprintw(2, COLS - 30   , Date.getTime().c_str());
    attroff(A_DIM);

    attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    mvprintw(14, 10, "USERNAME :");
    attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    attron(A_BOLD);
    mvprintw(14, 21, Info.getUserName().c_str());
    attroff(A_BOLD);
    attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    mvprintw(16, COLS - 40, "HOSTNAME :");
    attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    attron(A_BOLD);
    mvprintw(16, COLS - 29, Info.getHostName().c_str());
    attroff(A_BOLD);
    attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    mvprintw(18, 10, "KERNEL VERSION :");
    attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    attron(A_BOLD);
    mvprintw(18, 27, Sysinfo.getKernelVersion().c_str());
    attroff(A_BOLD);
    attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    mvprintw(20, COLS - 37, "OPERATING SYSTEM :");
    attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    attron(A_BOLD);
    mvprintw(20, COLS - 18, Sysinfo.getOpSystem().c_str());
    attroff(A_BOLD);
    attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    mvprintw(22, 10, "CPU Model :");
    attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    Cpu.getCPUInfos();
    attron(A_BOLD);
    mvprintw(22, 22, Cpu.getModel().c_str());
    attroff(A_BOLD);
    attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    mvprintw(24, COLS - 36, "CPU Frequency :");
    attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    attron(A_BOLD);
    mvprintw(24, COLS - 20, Cpu.getGhz().c_str());
    attroff(A_BOLD);
    attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    mvprintw(26, 10, "CPU Number of cores :");
    attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    attron(A_BOLD);
    mvprintw(26, 32, std::to_string(Cpu.getThreadsNumber()).c_str());
    mvprintw(26, 34, "cores");
    attroff(A_BOLD);
    attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    mvprintw(30, 10, "CPU Activity :");
    attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
    attron(A_BOLD);
    Cpu.getCPUInfos();
    if (std::stof(Cpu.getPercent(0)) <= 30) {
        attron(COLOR_PAIR(4));
        mvprintw(30, 25, Cpu.getPercent(0).c_str());
        mvprintw(30, 33, " %%");
        attroff(COLOR_PAIR(4));
    }
    else if (std::stof(Cpu.getPercent(0)) >= 70)
    {
        attron(COLOR_PAIR(5));
        mvprintw(30, 25, Cpu.getPercent(0).c_str());
        mvprintw(30, 33, " %%");
        attroff(COLOR_PAIR(5));
    }
    else
    {
        mvprintw(28, 25, Cpu.getPercent(0).c_str());
        mvprintw(28, 33, " %%");
    }
    attroff(A_BOLD);

    y = 29;
    x = 37;
    for (int i = 0; i < 8; i++) {
        attron(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));
        mvprintw(y, COLS - x - 4, "CPU%d Utilisation :", i);
        attroff(A_BOLD | A_UNDERLINE | COLOR_PAIR(2));

        Cpu.getCPUInfos();
        if (std::stof(Cpu.getPercent(i)) <= 30) {
            attron(COLOR_PAIR(4) | A_BOLD);
            mvprintw(y, COLS - (x - 15), Cpu.getPercent(i).c_str());
            mvprintw(y, COLS - (x - 22), " %%");
            attroff(COLOR_PAIR(4) | A_BOLD);
        }
        else if (std::stof(Cpu.getPercent(i)) >= 70)
        {
            attron(COLOR_PAIR(5) | A_BOLD);
            mvprintw(y, COLS - (x - 15), Cpu.getPercent(i).c_str());
            mvprintw(y, COLS - (x - 22), " %%");
            attroff(COLOR_PAIR(5) | A_BOLD);
        }
        else
        {
            attron(A_BOLD);
            mvprintw(y, COLS - (x - 15), Cpu.getPercent(i).c_str());
            mvprintw(y, COLS - (x - 22), " %%");
            attroff(A_BOLD);

        }
        y += 1;
    }
}

void Display::displayNCurse()
{
    Data::UserInfo Info;
    Data::DateTime Date;
    Data::SystemInfo Sysinfo;
    Data::CPUinfos Cpu;
    WINDOW *Box;
    int Key = 0;

    initscr();
    noecho();

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);

    while (1) {
        clear();
        curs_set(0);
        Date.refreshInfo();
        attron(A_DIM | A_BLINK);
        mvprintw(2, 5, "Press 'Q' or ECHAP to leave");
        attroff(A_DIM | A_BLINK);
        print_data(Info, Date, Sysinfo, Cpu);
        attron(COLOR_PAIR(1));
        Box = subwin(stdscr, 12, COLS, 0, 0);
        box(Box, ACS_VLINE, ACS_HLINE);
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        Box = subwin(stdscr, 10, COLS - 2, 1, 1);
        box(Box, ACS_VLINE, ACS_HLINE);
        attroff(COLOR_PAIR(2));
        Box = subwin(stdscr, 5, 17, 3, (COLS / 2) - 10);
        box(Box, ACS_VLINE, ACS_HLINE);
        print_welcome_msg(Box);
        wattron(Box, COLOR_PAIR(0));
        print_data(Info, Date, Sysinfo, Cpu);
        refresh();
        wrefresh(Box);
        timeout(100);
        if ((Key = getch()) == 'q' || Key == 'Q' || Key == 27)
            break;
    }
    endwin();
}