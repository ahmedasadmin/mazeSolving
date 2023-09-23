#include <iostream>
#include <stack>
#include <cstdlib>


#define ROWS 10
#define CLS 10
char WALL = '#';
char PATH = '.';
char GOAL = 'G';
char START = 'S';
char VISITED = 'O';

char maze[10][10];

const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};


// Maze solving function using DFS
bool solveMazeDFS(int x, int y) {
    std::stack<std::pair<int, int>> stack;
    stack.push({x, y});
    
    while (!stack.empty()) {
        std::pair<int, int> current = stack.top();
        stack.pop();
        x = current.first;
        y = current.second;
        
        if (maze[y][x] == GOAL) {
            return true;  // Goal reached!
        }
        
        maze[y][x]= (x==1 && y==1)? START : VISITED;  // Mark the cell as visited
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ((nx >= 0 && ny>= 0)){
            if ((maze[ny][nx] != WALL )&& (maze[ny][nx] != VISITED)) {
                stack.push({nx, ny});
            }
			}
        }
    }
    
    return false;  // Goal not reachable
}

void initMaze(){
	 maze[1][1] = START;
	 maze[8][8] = GOAL;
	srand((unsigned) time(NULL));

	for(int y=0; y<ROWS; y++){
		for(int x=0; x<CLS; x++){
		if((y == 8 && x == 8) || (x == 1 && y == 1) )
			 continue;
	int random = 1 + rand()%9;
	
	if(random%2==0) {
		maze[y][x]= '#';
	}
	else{
		maze[y][x]= '.';
	}
	}
	}
}

void showMaze(void){
	
		for(int y=0; y<ROWS; y++){
		std::cout << "| ";
		for(int x=0; x<CLS; x++)
			std::cout << maze[y][x] << " | ";

		std::cout << std::endl;
	}
}
int main(){

	initMaze();
	int startX=1;
	int startY=1;
	
	if(solveMazeDFS(startX, startY) ){
		std::cout << "Goal is reached!!!"<< std::endl;
	}
	else{
    	std::cout << "Goal is not reachable"<< std::endl;
		}
		showMaze();
		return 0;
}
