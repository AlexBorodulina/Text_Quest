#include <iostream>
#include <cmath>
#include <conio.h>
#include <string.h>
#include <ctime>
#include "p-ki.h"
#include <cstdlib>
#include <map>
#include <iterator>
#include <fstream>
#define N 10//size
#define M 3//number of trees
#define Y 8
#define X 5
using namespace std;
string random_funny_phrases[Y];
string questions[X];
string answers[X];
void init_guestions_and_answers(){
    questions[0]="who lives longer cat or dog?";
    answers[0]="dog";
    questions[1]="who lives longer man or woman?";
    answers[1]="woman";
    questions[2]="a and b were sitting on the pipe. A fell, b fell. Who stayed on the pipe??";
    answers[2]="and";
    questions[3]="What should I drink at 5 o'clock?";
    answers[3]="tee";
    questions[4]="A sign of what is a clean apartment?";
    answers[4]="boring life";
}
void init_random_funny_phrases(){
    random_funny_phrases[0]="You met a bear. He did not eat you)";
    random_funny_phrases[1]="You mum called you and asked:'what have you eaten?!'";
    random_funny_phrases[2]="Be careful";
    random_funny_phrases[3]="You are slaw";
    random_funny_phrases[4]="Somewhere here you can find a tree, but it is not exactly)";
    random_funny_phrases[5]="Ooooo Z-z-z--z";
    random_funny_phrases[6]="Do you whant to sleep?";
    random_funny_phrases[7]="Joke: gingerbread man hanged";

}

step::step(const string& a){
    this->name=a;
    if(a=="up"){
        this->step_pair.first=-1;
        this->step_pair.second=0;
    }
    if(a=="down"){
        this->step_pair.first=1;
        this->step_pair.second=0;
    }
    if(a=="right"){
        this->step_pair.first=0;
        this->step_pair.second=1;
    }
    if(a=="left"){
        this->step_pair.first=0;
        this->step_pair.second=-1;
    }
}

step::step(){
    int a=getch();
    while(a!=75&&a!=77&&a!=72&&a!=80)
        a=getch();
    if (a==80){
        this->step_pair.first=1;
        this->step_pair.second=0;
    }
    if (a==75){
        this->step_pair.first=0;
        this->step_pair.second=-1;
    }
    if (a==72){
        this->step_pair.first=-1;
        this->step_pair.second=0;
    }
    if (a==77){
        this->step_pair.first=0;
        this->step_pair.second=1;
    }
}
const void step::print(){
    cout << this->name << endl;
}
field::field(const string){


}

field::field(){
    int a,b;
    srand( time( 0 ) );
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            this->the_field[i][j]=0;
        }

    }
    a=rand()%(N-5)+5;
    b=rand()%(N-5)+5;
    this->the_field[a][b]=1;
    this->home_position=pair<int,int>(a,b);

    a=rand()%(N-5)+5;
    b=rand()%(N-5)+5;
    while(the_field[a][b]!=0){
        a=rand()%(N-5)+5;
        b=rand()%(N-5)+5;
    }
    this->the_field[a][b]=2;
    this->death_position=pair<int,int>(a,b);

    a=rand()%(N-5)+5;
    b=rand()%(N-5)+5;
    while(the_field[a][b]!=0){
        a=rand()%(N-5)+5;
        b=rand()%(N-5)+5;
    }
    this->the_field[a][b]=3;

    a=rand()%(N-5)+5;
    b=rand()%(N-5)+5;
    while(the_field[a][b]!=0){
        a=rand()%(N-5)+5;
        b=rand()%(N-5)+5;
    }
    this->the_field[a][b]=4;

    for(int i=0;i<M;i++){
        a=rand()%(N-5)+5;
        b=rand()%(N-5)+5;
        while(the_field[a][b]!=0){
            a=rand()%(N-1)+1;
            b=rand()%(N-1)+1;
        }
        this->the_field[a][b]=5+i;

    }

    this->position=pair<int,int>(0,0);
    this->finish=0;
    this->number_of_gifts=0;
    this->number_of_gifts=0;
    this->gifts.resize(0);
}

void field::print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<this->the_field[i][j] << " ";
        }
        cout << "\n";
    }

}


const void field::do_step(const step& a){
    this->position.first+=a.step_pair.first;
    this->position.second+=a.step_pair.second;
    if(this->position.second==-1)
        this->position.second+=1;
    if(this->position.first==-1)
        this->position.first+=1;
    if(this->position.second==N)
        this->position.second-=1;
    if(this->position.first==N)
        this->position.first-=1;
}
void field::finish_game(){
    this->finish=1;
    if(this->the_field[this->position.first][this->position.second]==1){
        cout<<"Your gifts:" <<endl;
        for(int i=0;i<this->number_of_gifts;i++){
           cout << this->gifts[i]<<endl;
        }
    }
    else{
        cout << "you are looser";
        int y=getch();
    }

}

void field::comunication(){
    int a=this->the_field[this->position.first][this->position.second];
    if(a==9){
        cout<<"there was a tree, but stupid boy crushed it"<<endl;
    }
    if(a==0){
        int e=rand()%10;
        if(e<9){
            int r=rand()%Y;
            cout << random_funny_phrases[r]<< endl;
        }
        else{
                int u,v;
            cout<<"You met a stupid boy"<<endl;
            cout<<"stupid boy: where can i find a tree?"<<endl;
            cin >>u >>v;
            if(this->the_field[u][v]>4)
                this->the_field[u][v]=9;
        }
    }
    if(a==1){
        cout << "You find home. press SPACE to come and finish the game or press any key to continue."<<endl;
        int space=getch();
        if(space==32)
            this->finish_game();
    }
    if(a==3){
        int u=rand()%50,v=rand()%50;

        cout << "You met a magician.\nIf you answer the question, he would tell you the position of home.\nHow much is "<<u<< "+"<<v<<" ?\n";
        int ans;
        cin >> ans;
        if(ans==u+v)
            cout << "home pos: " <<this->home_position.first<<" "<<this->home_position.second<< endl;
        else
            cout << "You are looser! Get out of here!"<< endl;
    }
    if(a==2){
        cout <<"You died((("<<endl;
        this->finish_game();
    }
    if(a==4){
        cout << "You met a magician.\nIf you answer the question, he would tell you the position of death."<<endl;

        int t=rand()%X;
        string ans;
        cout << questions[t] << endl;
        cin >> ans;
        if(ans==answers[t])
            cout << "home pos: " <<this->home_position.first<<" "<<this->home_position.second<< endl;
        else
            cout << "You are looser! Get out of here!"<< endl;
    }
    if(a>4&&a!=9){
        cout << "you found a tree number "<<a-4<<endl;
        char* filename;
        if(a-4==1)
            filename="tree1.txt";
        if(a-4==2)
            filename="tree2.txt";
        if(a-4==3)
            filename="tree3.txt";
        if(a-4==4)
            filename="tree4.txt";
        cout << "under the tree you can see:" << endl;
        tree T=tree(filename);
        for(int i=0;i<T.n;i++){
            cout <<T.gifts[i]<<endl;
        }
        if(T.n!=0){
                cout << "press SPACE to take gift, press any other key to ignore gifts" << endl;
            int space=getch();
            if(space==32){
                this->number_of_gifts++;
                this->gifts.resize(this->number_of_gifts+1);
                this->gifts[this->number_of_gifts-1]=T.gifts[0];
                ofstream file(filename);
                file<<T.n-1<< endl;
                for(int i=1;i<T.n;i++)
                    file<<T.gifts[i];
            }
        }
        else cout << "no gifts";
        int a=rand()%(N-5)+5;
        int b=rand()%(N-5)+5;
        while(the_field[a][b]!=0){
            a=rand()%N;
            b=rand()%N;
        }
        this->the_field[a][b]=a;
        the_field[this->position.first][this->position.second]=0;
    }
}
tree::tree(char* filename){
    ifstream file(filename);
    file >> this->n;
    this->gifts.resize(n);
    for(int i=0;i<n;i++){
        file>>this->gifts[i];
    }
}
int main(){
    init_guestions_and_answers();
    init_random_funny_phrases();
    field f=field();
    f.print();
    step a=step("up");
    while(f.finish!=1){
        a=step();
        f.do_step(a);
        cout << "your pos:"<<f.position.first<<" "<<f.position.second<< " ";
        f.comunication();

    }
    return 0;
}

