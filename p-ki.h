#include <iostream>
#include <cmath>
#include <conio.h>
#include <string.h>
#include <vector>
#include <list>
#define N 10
#define X 5
using namespace std;
class step{

    public:
    pair<int,int> step_pair;
        string name;
        step(const string& );
        step(int i);
        step();
        const void print();
};
class tree{
    public:
    vector<string> gifts;
    int n;

    tree(char* filename);
    string get_gift();

};

class field{
    protected:
        int the_field[N][N];

        pair<int,int> home_position;
        pair<int,int> death_position;


    public:
        int number_of_gifts;
        vector<string> gifts;
        bool finish;
        pair<int,int> position;
        field(const string filename);
        field();
        void comunication();
        void finish_game();
        const field up();
        const field down();
        const field left();
        const field right();
        const void do_step(const step&);
        void print();

};

