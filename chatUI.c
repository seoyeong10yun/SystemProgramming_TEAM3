/*
 * Chatting System UI : version 0.1
 *  - ncurses header file
 *  - left window: print command contents
 *    right window: print escape window and new chatting room window
 *  - unable to chat by korean
 */

#include <ncurses.h>
#include <string.h>
#include <locale.h>

#define ESCAPE 27
#define ENTER 10

void init_scr();		//initiallize screen
void new_chatting_room();	//1:1 or 1:n chatting room
int check_escape();		//when to input 'quit', print check-escape window
void print_help(WINDOW*);

int main()
{
	setlocale(LC_ALL, "");

	WINDOW *help_input, *help_input_panel;
	WINDOW *help_output, *help_output_panel;
	
	char buf[100];
	//char* check=NULL;
	//string split

	//initiallize window
	init_scr();
	bkgd(COLOR_PAIR(1));
	start_color();
	attron(COLOR_PAIR(2)|A_BOLD);
	mvprintw(1,3,"CHATTING SYSTEM");
	attroff(COLOR_PAIR(1));
	box(stdscr,0,0);
	refresh();
	
	//help windows: help output, help input
	//	
	help_output=subwin(stdscr,30, 36, 5, 4);
	scrollok(help_output,TRUE);
	wrefresh(help_output);
	help_output_panel=subwin(stdscr,34, 40, 2, 2);
	box(help_output_panel,0,0);
	wrefresh(help_output_panel);

	help_input_panel=subwin(stdscr,6, 40, 36 , 2);
	box(help_input_panel,0,0);
	wrefresh(help_input_panel);
	help_input=subwin(stdscr,4, 37, 37 , 3);

	attron(COLOR_PAIR(3));	
	mvprintw(3,10,"'!quit' quits.");
	attroff(COLOR_PAIR(1));
	refresh();

	while(1){
		mvwgetstr(help_input,1,1,buf);

		if(strstr(buf,"!quit")!=NULL){
			if(check_escape()==1)
				break;
		}
		else if(strstr(buf,"!help")!=NULL){
			print_help(help_output);	
		}
		else if(strstr(buf,"!DM")!=NULL){
			//서버로  신호 보낸 후 수락되면 new_chatting_roon() open
			new_chatting_room();
			refresh(); //window update
		}else
			wprintw(help_output, "%s\n",buf);

		wclear(help_input);
		wrefresh(help_output);
		wrefresh(help_input);
		
	}

	endwin();
}

void init_scr()
{
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	curs_set(1);
	keypad(stdscr,TRUE);
}

void new_chatting_room()
{
	WINDOW *chat_input, *chat_input_panel;
	WINDOW *chat_output, *chat_output_panel;
	char chatbuf[100];

        chat_output_panel=newwin(22,36,4,43);
        box(chat_output_panel,0,0);
        wrefresh(chat_output_panel);
	chat_output=newwin(19,33,5,44);
        scrollok(chat_output,TRUE);
	wrefresh(chat_output);

	chat_input_panel=newwin(8,36,24,43);
        box(chat_input_panel,0,0);
        wrefresh(chat_input_panel);
	chat_input=newwin(5,33,25,44);
	wattron(chat_input,COLOR_PAIR(1));

        wattron(chat_output,COLOR_PAIR(3));
        mvwprintw(chat_output,1,10,"'bye' quits\n\n");
        wattroff(chat_output,COLOR_PAIR(1));
        wrefresh(chat_output);

        while(1){
                mvwgetstr(chat_input,1,1,chatbuf);

                if(strstr(chatbuf,"bye")!=NULL){
			break;
		}
                wprintw(chat_output, "me:%s\n",chatbuf);

                wclear(chat_input);
                wrefresh(chat_output);
                wrefresh(chat_input);

        }
	
	wborder(chat_input_panel,' ',' ',' ', ' ', ' ', ' ', ' ',' ');
	wborder(chat_output_panel,' ',' ',' ', ' ', ' ', ' ', ' ',' ');
	wrefresh(chat_input_panel); wrefresh(chat_output_panel);
	delwin(chat_input);
	delwin(chat_input_panel);
	delwin(chat_output);
	delwin(chat_output_panel);
}

int check_escape()
{
	WINDOW *escape_bar;
	int key;

	escape_bar=newwin(5,30,15,44);

	mvwprintw(escape_bar, 2,5,"Exit program (y/n)?");
	wbkgd(escape_bar, COLOR_PAIR(2));
	wrefresh(escape_bar);

        key=wgetch(escape_bar);
	wbkgd(escape_bar,COLOR_PAIR(1));
	wclear(escape_bar);
	wrefresh(escape_bar);
	delwin(escape_bar);

	if(key=='y')
		return 1;
	else
		return 0;
}

void print_help(WINDOW* w_under){
	WINDOW* for_helps;
	int key;
	
	noecho();
	
	for_helps=subwin(w_under,20,36,5,4);
	scrollok(for_helps,TRUE);
	wattron(for_helps,COLOR_PAIR(2));
	wrefresh(for_helps);
	wprintw(for_helps,"\n!help	print helps\n");
	wrefresh(for_helps);

	while((key=getch())!=ENTER);

	wclear(for_helps);
	wrefresh(for_helps);
	delwin(for_helps);
	echo();
}
