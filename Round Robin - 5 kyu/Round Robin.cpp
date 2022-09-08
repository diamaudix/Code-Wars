#include <vector>
#include <iostream>
using namespace std;
unsigned int calculateGames(int players) {

    unsigned int games = 0;
    unsigned int playersLeft = players;

    if (players % 2 == 0) {

        while (playersLeft % 2 == 0) {

            games += (playersLeft /= 2);

        }


    }

    if (playersLeft > 1) {

        games += (playersLeft * (playersLeft - 1)) / 2;
    }

    return games;

}
std::vector<unsigned> find_player_counts(unsigned number_of_games) {

    if (number_of_games == 0 || number_of_games == 1) return { 0 };
    
    unsigned int one = calculateGames(2097152);
    unsigned int two = calculateGames(898392155);

    std::vector<unsigned> possibilities = {};

    for (unsigned int players = 2; (players <= (number_of_games * (number_of_games + 1)) / 2); players++) {
        if (players < 50000000 && calculateGames(players) == number_of_games) {
            possibilities.push_back(players);
        }
    }
    cout << "Number of Player Possiblities: ";
    for (unsigned int i = 0; i < possibilities.size(); i++) {
        cout << possibilities[i] << " ";
    }
    cout << endl;
    return possibilities;
}




int main(){

        
        find_player_counts(3);// equals(V{ 3, 4 }));
        find_player_counts(6);// equals(V{ 6 }));
        find_player_counts(7);// equals(V{ 8 }));
        find_player_counts(8);// equals(V{}));
        find_player_counts(10);// equals(V{ 5 }));
        find_player_counts(12);// equals(V{ 12 }));
        find_player_counts(15);// equals(V{ 10, 16 }));
        find_player_counts(21);// equals(V{ 7 }));
        find_player_counts(24);// equals(V{ 24 }));
        find_player_counts(28);// equals(V{ 14 }));
        find_player_counts(100);// equals(V{}));
        find_player_counts(4095);// equals(V{ 91, 2080, 4096 }));
        return 0;
}