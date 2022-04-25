#include <iostream>
#include <random>
#include <cmath>
using namespace std;

int main(){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<float> unif(0.0, 1.0);

    float x = unif(generator);
    int num = (int)(x * 100 + 1); // let num ranged from 1 to 100.

    int guess;
    int min = 1;
    int max = 100;
    int cnt = 0;
    while (true){
        cnt++;
        cout << "Please guess a number between " << min << " and " << max << endl;
        cin >> guess;
        if (guess == num){
            break;
        } else if (guess < num){
            min = guess > min ? guess : min;
        } else {
            max = guess < max ? guess : max;
        }
        system("clear");
    }
    cout << "You win! Total try: " << cnt << endl;
    cout << "Do you want to play again? [y/n]" << endl;
    char ch;
    cin >> ch;
    if (ch == 'y') system("./guessNum");

    return 0;
}
