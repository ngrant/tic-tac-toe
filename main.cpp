#include <iostream>
#include <string>
#include <sstream>
#include <array>

std::array <char, 9> board;

void resetboard() {
    std::fill(board.begin(), board.end(), '_');
}

std::string getline() {
    std::string str;
    std::getline(std::cin, str);
    return str;
}

char check_horizontal(int start) {

    if ((start % 3) != 0) return '_';
    // horizontal
    if (board[start] == board[start+1] && board[start] == board[start+2]) return board[start];
    else return '_';
}

char check_vertical(int start) {

    if (start >= 3) return '_';
    //vertical
    if (board[start] == board[start+3] && board[start] == board[start+6]) return board[start];
    else return '_';
}
char evaluate() {
    char check;

    if ((check = check_horizontal(0)) != '_') return check;
    if ((check = check_horizontal(3)) != '_') return check;
    if ((check = check_horizontal(6)) != '_') return check;

    if ((check = check_vertical(0)) != '_') return check;
    if ((check = check_vertical(1)) != '_') return check;
    if ((check = check_vertical(2)) != '_') return check;

    //diagonal
    if (board[0] == board[4] && board[0] == board[8]) return board[0];
    //reverse diagonal
    if (board[2] == board[4] && board[2] == board[6]) return board[2];

    return '_';
}

void moveprompt(char letter) {
    while (true) {
        int usermove;
        std::cout << "Your move(" << letter << "): " << std::endl;
        std::istringstream iss(getline());
        iss >> usermove >> std::ws;
        if (usermove <= 9) {
            if (board[usermove - 1] == '_') {
                board[usermove-1] = letter;
                break;
            }
        }
    }
}

void printboard() {
    std::cout << "Board: " << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char val = board[i * 3 + j];
            if (val != '_') 
                std::cout << val; 
            else 
                std::cout << (i * 3 + j + 1);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

char printresult() {
    char result = evaluate();
    std::cout << "Result: " << result << std::endl;
    if (result != '_') std::cout << result << " wins!" << std::endl;
    return result;
}

void cpumove() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == '_') {
            board[i] = 'o';
            break;
        }
    }
}

int newgame(int players) {
    resetboard();
    printboard();
    char result = '_';
    while (result == '_') {
        moveprompt('x');
        printboard();
        result = printresult();
        if (result != '_') break;
        if (players == 1) cpumove();
        else {
            moveprompt('o');
        }
        result = printresult();
        printboard();
    }
    if (result == 'x') return 1;
    else if (result == 'o') return -1;
    return 0;
}

int main(int argc, char *argv[]) {
    char choice = 'Y';
    int players = 1;
    while (choice == 'Y' || choice == 'y') {
        std::cout << "Players? [" << players << "]";
        std::istringstream iss(getline());
        iss >> players >> std::ws;
        newgame(players);
        std::cout << "Play again? [" << choice << "]";
        iss.str(getline());
        iss >> choice >> std::ws;
    }
    return 0;
}
