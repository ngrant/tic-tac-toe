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

void printboard() {
    std::cout << "Board: " << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i * 3 + j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int newgame() {
    resetboard();
    printboard();
    char result = '_';
    int usermove;
    while (result == '_') {
        std::cout << "Your move: " << std::endl;
        std::istringstream iss(getline());
        iss >> usermove >> std::ws;
        if (usermove <= 9) {
            if (board[usermove - 1] == '_') {
                board[usermove-1] = 'x';
            }
        }
        result = evaluate();
        std::cout << "Result: " << result << std::endl;
        printboard();
    }
    if (result == 'x') return 1;
    else if (result == 'o') return -1;
    return 0;
}

int main(int argc, char *argv[]) {
    char choice = 'Y';
    while (choice == 'Y' || choice == 'y') {
        newgame();
        std::cout << "Play again?" << std::endl;
        std::istringstream iss(getline());
        iss >> choice >> std::ws;
        if (iss.fail() || !iss.eof()) {
            std::cout << "An error occurred." <<std::endl;
        }
    }
    return 0;
}
