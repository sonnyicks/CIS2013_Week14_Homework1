#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Game{
	private:
		string name;
		int score=0;
	public:
		string get_name(){
			return name;
		}
		
		string set_name(){
			cout << "Name the game: ";
			cin >> name;
			return name;
		}
		
		int get_score(){
			return score;
		}
		
		int set_score(){
			score=0;
			return score;
		}
};

class Mine_Sweeper: public Game{
	private:
		char *brd_size;
		int rows=0;
		int clms=0;
		int area=0;
		char selected_squares='c';
		int bomb_squares=0;
		int *print;
		int x=0;
		int y=0;
		
	public:
		void set_brd_size(){
			
			srand(time(0));
			cout << "Number of Columns: ";
			cin >> clms;
			cout << "Number of Rows: ";
			cin >> rows;
			area=(clms*rows);
			brd_size = new char[area];
			for (int i=0; i<area; i++){
				brd_size[i]='.';
			}
			for (int i=0; i<=bomb_squares; i++){
				brd_size[(rand()%area)]='@';
			}
		}
			
		int set_bombs(){
			cout << "Number of bombs: ";
			cin >> bomb_squares;
			return bomb_squares;
		}
		//(x and y selection) if y = 1, brd_size[x-1] 7x8 grid selected
		//x6,y1 (max7*y=7)- (Max7-x+1)
		void prt_brd(){
			int a=0;
			cout << "   ";
			for (int i=0; i<clms; i++){
				cout << " " << i+1 << " ";
			}
			cout << endl << "  ";
			for (int i=0; i<clms; i++){
				cout << "~~~";
			}
			cout << endl;
			for (int i=0; i<rows; i++){
				if (i+1>9){
					cout << i+1 << "|";
				}
				else{
					cout << " " << i+1 << "|";
					}
				for (int j=0; j<clms; j++){
					cout << " " << brd_size[a] << " ";
					a++;
				}
				cout << endl;
			}
		}
		Mine_Sweeper(){
			set_name();
			set_score();
			set_bombs();
			set_brd_size();
			prt_brd();
		}
};

int main(){
	Mine_Sweeper test;
	
	return 0;
}