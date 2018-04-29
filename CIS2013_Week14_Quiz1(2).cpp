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
		char selected_squares='c';
		int bomb_squares=0;
		int *print;
		
	public:
		void set_brd_size(){
			cout << "Number of Columns: ";
			cin >> clms;
			cout << "Number of Rows: ";
			cin >> rows;
			brd_size = new char[(clms*rows)];
		}
		
		int set_bombs(){
			cout << "Number of bombs: ";
			cin >> bomb_squares;
			return bomb_squares;
		}
		
		void prt_brd(){
			for (int i=0; i<clms; i++){
				cout << " " << i << " ";
			}
			cout << endl;
			for (int i=0; i<clms; i++){
				cout << "~~~";
			}
			cout << endl;
			for (int i=0; i<rows; i++){
				for (int j=0; j<clms; j++){
					
				}
				
			}
		}
		Mine_Sweeper(){
			set_name();
			set_score();
			set_brd_size();
			set_bombs();
			prt_brd();
		}
};

int main(){
	Mine_Sweeper test;
	
	return 0;
}