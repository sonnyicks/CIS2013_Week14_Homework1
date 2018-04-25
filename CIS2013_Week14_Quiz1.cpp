#include <iostream>
#include <string>
using namespace std;

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
		}
			for (int j=0; j<rows; j++){cout << " " << ".";}
				cout << endl;
		}
	
	mine_sweeper(){
		get_row();
		get_column();
		get_mines();
	}
	
};

int main(){
	mine_sweeper one;
	
	return 0;
}