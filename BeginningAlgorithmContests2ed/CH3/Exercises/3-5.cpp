/*
* UVa 227 - Puzzle
* https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=163
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define U_MAX 200
char *stdin_get_str(char *str)
{
	fgets(str,U_MAX,stdin);
	if(str[strlen(str)-1] == '\n')
		str[strlen(str)-1] = '\0';
	return str;
}
char matrix[6][6] = {0};
struct Point{
	int x, y;
} blank, square;

bool check(const Point &p){
	if(p.x < 0 || p.x >=5 || p.y < 0 || p.y >= 5) return false;
	else return true;
}

int main(){
	int idx = 0;
	while(stdin_get_str(matrix[0]) && matrix[0][0] != 'Z'){
		for(int i = 1; i < 5; ++i){
			stdin_get_str(matrix[i]);
		}
		for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
				if(matrix[i][j] == ' '){
					blank.x = i;
					blank.y = j;
				}
			}
		}
		if(idx > 0) printf("\n");
		printf("Puzzle #%d:\n", ++idx);
		char str[1024];
		bool flag = true;
		while(stdin_get_str(str)){
			int len = strlen(str);
			for(int i = 0; i < len && flag == true; ++i){
				square = blank;
				if(str[i] == 'A'){
					square.x--;
				}else if(str[i] == 'B'){
					square.x++;
				}else if(str[i] == 'R'){
					square.y++;
				}else if(str[i] == 'L'){
					square.y--;
				}
				if(check(square)){
					swap(matrix[square.x][square.y], matrix[blank.x][blank.y]);
					blank = square;
				}else{
					flag = false;
				}
			}
			if(str[len-1] == '0') break;
		}
		if(flag){
			for(int i = 0; i < 5; ++i){
				for(int j = 0; j < 5; ++j){
					if(j > 0) printf(" ");
					printf("%c", matrix[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("This puzzle has no final configuration.\n");
		}
	}
	return 0;
}