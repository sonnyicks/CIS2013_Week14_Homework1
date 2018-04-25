#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef char* IPtr;
IPtr b;
int x, y;
// srand(time(0));

class Game{
	private:
	string name;
	int score;
	
	public:
	string get_name(){
		cout << name;
		return name;
	}
	int set_score(){
		score=0;
		return score;
	}
	
	int get_score(){
		cout << score;
		return score;
	}
	
	string set_name(){
		cout << "Enter a name: ";
		cin >> name;
		return name;
	}
	
	Game(){
		set_name();
	}
	
};

class mine_sweeper: public Game{
	public:
	int rows = 0;
	int columns = 0;
	char selected_squares = ' ';
	int bomb_squares = 0;
	
	
	
	int get_row(){
		cout << "Number of rows: ";
		cin >> rows;
		return rows;
	}
	int get_column(){
		cout << "Number of columns: ";
		cin >> columns;
		return columns;
	}
	int get_mines(){
		cout << "Number of mines: ";
		cin >> bomb_squares;
		return bomb_squares;
	}
	
	void print_board(){
		cout << "   ";
		for (int i=0; i<rows; i++){cout << i << " ";}
			cout << endl;
		cout << "   ";
		for (int i=0; i<rows; i++){cout << "__";}
		cout << endl;
		for (int i=0; i<columns; i++){
			cout << i << "|";
			for (int j=0; j<rows; j++){cout << " " << ".";}
				cout << endl;
		}
	}
	
	void board(){
		IPtr *b = new IPtr[columns];
		for (int i=0; i<columns; i++){
			b[i] = new char[rows];
		}

//initialize array values
		for (int i=0; i<columns; i++){
			for (int j=0; j<rows; j++){
			b[i][j]= '.';
			}
		}
		while (bomb_squares>0){
			int rand_one = (rand() % columns);
			int rand_two = (rand() % rows);
			if (b[rand_one][rand_two]!='X'){
			b[rand_one][(rand_two)] = 'X';
			bomb_squares--;
			}
		}
		
	}
	
	mine_sweeper(){
		get_row();
		get_column();
		get_mines();
		board();
	}
};

int main(){
	mine_sweeper one;
	one.print_board();
	
	
	
	return 0;
}

void coordinates(){
	cout << "Pick x and y coordinates: ";
	cin >> x >> y;
}










