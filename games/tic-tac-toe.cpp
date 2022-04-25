#include <iostream>
using namespace std;

int main(){
  int times = 0;
  int x, y;
  char s[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  while (times < 9){
    
    for (int i = 0; i < 3; ++i){
      cout << s[i][0] << "|" << s[i][1] << "|" << s[i][2] << endl;
    }

    for (int i = 0; i < 3; ++i){
      if (s[i][0] == s[i][1] && s[i][1] == s[i][2]){
        if (s[i][0] == 'O'){
          cout << "O wins" << endl;
          return 0;
        } else if (s[i][0] == 'X'){
          cout << "X wins" << endl;
          return 0;
        }
      }

      if (s[0][i] == s[1][i] && s[1][i] == s[2][i]){
        if (s[0][i] == 'O'){
          cout << "O wins" << endl;
          return 0;
        } else if (s[0][i] == 'X'){
          cout << "X wins" << endl;
          return 0;
        }
      }

      if ((s[0][0] == s[1][1] && s[1][1] == s[2][2]) || (s[0][2] == s[1][1] && s[1][1] == s[2][0])){
        if (s[1][1] == 'O'){
          cout << "O wins" << endl;
          return 0;
        } else if (s[1][1] == 'X'){
          cout << "X wins" << endl;
          return 0;
        }
      }
    }

    cin >> x >> y;
    if ( x > 4 || x < 1 || y > 4 || y < 1 || s[x-1][y-1] == 'O' || s[x-1][y-1] == 'X'){
      cout << "input error" << endl;
      return 0; 
    }
    s[x-1][y-1] = times % 2 == 0 ? 'O' : 'X';
    times++;
  }

  return 0;
}
