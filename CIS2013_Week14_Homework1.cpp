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
			score++;
			return score;
		}
};

class Mine_Sweeper: public Game{
	private:
		char *brd_size;
		int rows=0;
		int clms=0;
		int area=0;
		int bomb_squares=0;
		int *print;
		int x=0;
		int y=0;
		int selected_square=0;

		
	public:
		bool alive=true;
		void set_brd_size(){
			bool valid=false;
			int left=bomb_squares;
			srand(time(0));
			while (!valid){
				cout << "Number of Columns: ";
				cin >> clms;
				cout << "Number of Rows: ";
				cin >> rows;
				area=(clms*rows);
				if (area<=bomb_squares){
					cout << "Area not big enough for # of bombs; "
							 << "choose again -" << endl;
				}
				else {valid=-true;}
			}
			brd_size = new char[area];
			for (int i=0; i<area; i++){
				brd_size[i]='.';
			}
			while(left!=0){
				int r=(rand()%area);
				if (brd_size[r]!='@'){
					brd_size[r]='@';
					left--;
				}
			}	
		 }
			
		int set_bombs(){
			cout << "Number of bombs: ";
			cin >> bomb_squares;
			return bomb_squares;
		}

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
						if (!alive){
							cout << " " << brd_size[a] << " ";
						}
						else if (brd_size[a]==' '){
							cout << "   ";
						}
						else{
							cout << " . ";
						}
					a++;
				}
				cout << endl;
			}
			cout << "Score: " << get_score() << endl;
			if (alive){
				cout << "No bomb found, still safe..." << endl;
			}
		}

		int get_square(){
			cout << "Enter X and Y coordinates," 
					 <<	"press enter between each: ";
		  cin >> x >> y;
			selected_square=(clms*y)-(clms-x+1);
			return selected_square;
		}
		
		void try_bomb(){
			if(brd_size[selected_square]=='@'){
				brd_size[selected_square]='X';
				cout << "        BOMB FOUND, YOU DIED!!!" << endl;
				alive=false;
			}
			else if (brd_size[selected_square]==' '){
				cout << "Square already searched; pick another -";
			}
			else {
				brd_size[selected_square]=' ';
				set_score();
			}
		}
		Mine_Sweeper(){
			set_name();
			set_bombs();
			set_brd_size();
			prt_brd();
		}
};

int main(){
	Mine_Sweeper mygame;
	while(mygame.alive){
		mygame.get_square();
		mygame.try_bomb();
		mygame.prt_brd();
	}
	return 0;
}


