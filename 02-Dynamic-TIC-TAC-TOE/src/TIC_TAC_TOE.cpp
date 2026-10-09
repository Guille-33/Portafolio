#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 3
#define MAX 3

struct game{
    char board[N][N];
    int moves [3][N*N];
    char firstplayer;
    char winner;
};

void header();
void Guide_board(char [N][N]);
int check(char [N][N]);
char first_player();
int position(int*,int* );
char change(char);
void filled_board(char [N][N]);
int tic_tac(char [N][N],char*,int,int,char,int*);
void final_filled_board(char [N][N]);
int menu();
void Play(struct game [],int *,int [MAX]);
int Restart(int [MAX]);
void Delete(struct game [], int *,int[MAX]);
void Statistics(struct game []);

main(){
    struct game mygames[MAX];
    int count,turn,k,pause[MAX];
    int *option=(int*)malloc(sizeof(int));
    for (count=0; count<MAX; count++){
        for (k=0;k<3;k++){
            for(turn=0;turn<N*N;turn++){
                mygames[count].moves[k][turn]=0;
            }
        }
    }
    for(turn=0;turn<MAX;turn++){
        pause[turn]=0;
    }
    count=0;
    while(*option!=5){
        *option=menu();
        switch(*option){
            case 1:
                if(count<MAX){
                    Play(mygames,&count,pause);
                }
                else{
                    printf("\nREACHED MAX NUMBER OF GAMES!!!\n");
                }
                break;
            case 2:
                k=Restart(pause);
                pause[k]=0;
                if(k>=0&&k<MAX){
                    Play(mygames,&k,pause);
                }
                break;
            case 3:
                Delete(mygames,&count,pause);
                break;
            case 4:
                Statistics(mygames);
                break;
        }
    }
    free(option);
}

int menu(){
    int option;
    printf("\n1. Play Game\n2. Restar game\n3. Delete Game\n4. Statistics\n5. End of program\n\n");
    do{
        option=0;
        printf("ENTER OPTION: ");
        if (scanf("%i", &option) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
    }while(option<1||option>5);
    return option;
}

void Guide_board(char pos[N][N]){
    char inter=197, horiz=196, vert=179,i,j,k;
    for (k=1;k<N;k++){
        printf("\n ");
        for(j=1;j<=N-1;j++){
            if(pos[k-1][j-1]=='-'){
                printf("%i,%i %c ",k,j,vert);
            }
            else{
                printf("    %c ",vert);
            }
        }
        if(pos[k-1][j-1]=='-'){
            printf("%i,%i",k,j);
        }
        else{
            printf("    ");
        }
        printf("\n");
        for(i=0;i<N-1;i++){
            for(j=0;j<5;j++){
                printf("%c",horiz);
            }
            printf("%c",inter);
        }
        for(j=0;j<5;j++){
            printf("%c",horiz);
        }
    }
    printf("\n ");
    for(j=1;j<=N-1;j++){
        if(pos[k-1][j-1]=='-'){
            printf("%i,%i %c ",k,j,vert);
        }
        else{
            printf("    %c ",vert);
        }
    }
    if(pos[k-1][j-1]=='-'){
        printf("%i,%i\n",k,j);

    }
    else{
        printf("\n");

    }
}

void filled_board(char board[N][N]){
    char inter=197, horiz=196, vert=179,i,j,k;
    puts("");
    for(i=0;i<N-1;i++){
        printf("");
        for(j=0;j<N-1;j++){
            printf("%2c%2c",board[i][j],vert);
        }
        printf("%2c",board[i][j]);
        printf("\n");
        for(k=0;k<N-1;k++){
            for(j=0;j<3;j++){
                printf("%c",horiz);
            }
            printf("%c",inter);
        }
        for(j=0;j<3;j++){
            printf("%c",horiz);
        }
        puts("");
    }
    printf("");
    for(j=0;j<N-1;j++){
        printf("%2c%2c",board[i][j],vert);
    }
    printf("%2c",board[i][j]);
    printf("\n");
}
 
void final_filled_board(char board[N][N]){
    char inter=206, horiz=205, vert=186,i,j,k=0,l;
    puts("\n");
    char string_board[(N*N)+1];
    //frist convert the 2 dimentional array into a string
    for(i=0;i<N-1;i++){
        for(j=0;j<N-1;j++){
            string_board[k]=board[i][j];
            k++;
        }
        string_board[k]=board[i][j];
        k++;
    }
    for(j=0;j<N-1;j++){
        string_board[k]=board[i][j];
        k++;
    }
    string_board[k]=board[i][j];
    string_board[k+1]=0;
    //now print the board using the string
    k=0;
    for(i=0;i<N-1;i++){
        printf("");
        for(j=0;j<N-1;j++){
            printf("%2c%2c",string_board[k],vert);
            k++;
        }
        printf("%2c",string_board[k]);
        k++;
        printf("\n");
        for(l=1;l<N;l++){
            for(j=0;j<3;j++){
                        printf("%c",horiz);
            }
            printf("%c",inter);
        }
        for(j=0;j<3;j++){
            printf("%c",horiz);
        }
        puts("");
    }
    printf("");
    for(j=0;j<N-1;j++){
        printf("%2c%2c",string_board[k],vert);
        k++;
    }
    printf("%2c",string_board[k]);
}

char first_player(){
    char chip;
    //keeps asking until a right symbol is pressed but it doesnt show them so the program seems cleaner
    do{
        chip=getch();
    }while(chip!='x'&&chip!='X'&&chip!='O'&&chip!='o');
    if (chip=='x'||chip=='X'){
        chip='X';
    }
    else{
        chip='O';
    }
    return chip;
}

int check(char board[N][N]){
    int i,j,count=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if (board[i][j]=='-'){
                count++;
            }
        }
    }
    if(count>0){
        return 1;
    }
    else{
        return 0;
    }
}

char change(char chip){
    if (chip=='X'){
        return 'O';
    }
    else{
        return 'X';
    }
}

int position(int*i,int*j){
    int row,column;
    char getting;
    do{
        row=0;column=0;
        printf("\nrow: ");
        do{
            fflush(stdin);
            getting=getch();
            if (getting==13){
                puts("");
            }
        }while((getting<'1'||getting>'9')&&getting!=27);
        if(getting==27){
            return 0;
        }
        row=row+(getting-'0');
        printf("%c",getting);
        do{
            fflush(stdin);
            getting=getch();
            if(getting!=13){
                row=row*10;
                row=row+(getting-'0');
                printf("%c",getting);
            }
        }while(getting!=13&&getting!=27);
        if(getting==27){
            return 0;
        }
        printf("\ncolumn: ");
        do{
            fflush(stdin);
            getting=getch();
            if (getting==13){
                puts("");
            }
        }while((getting<'1'||getting>'9')&&getting!=27);
        if(getting==27){
            return 0;
        }
        column=column+(getting-'0');
        printf("%c",getting);
        do{
            fflush(stdin);
            getting=getch();
            if(getting!=13){
                column=column*10;
                column=column+(getting-'0');
                printf("%c",getting);
            }
        }while(getting!=13&&getting!=27);
        if(getting==27){
            return 0;
        }
    }while (!(row>=1&&row<=N&&column>=1&&column<=N)&&getting!=27);
    *i=row-1;
    *j=column-1;
    return 1;
}
 
int tic_tac(char board[N][N],char *winner,int row,int column,char chip,int *score){
    int i,j,x=0,o=0,d1x=0,d1o=0,d2o=0,d2x=0;
    char control,control1,control2;
    for(i=0;i<N&&x<N&&o<N;i++){
        x=0;
        o=0;
        control=0;control1=0;control2=0;
        for(j=0;j<N;j++){
            if(board[i][j]=='X'){
                if(row==i&&column==j&&chip=='X'){
                    control='X';
                }
                x=x+1;
                if(i==j){
                    d1x++;
                    if(row==i&&column==j&&chip=='X'){
                        control1='X';
                    }
                }
                if(i+j==N-1){
                    d2x=d2x+1;
                    if(row==i&&column==j&&chip=='X'){
                        control='X';
                    }
                }
            }
            if(board[i][j]=='O'){
                if(row==i&&column==j&&chip=='O'){
                    control='O';
                }
                o=o+1;
                if(i==j){
                    d1o++;
                    if(row==i&&column==j&&chip=='O'){
                        control1='O';
                    }
                }
                if(i+j==N-1){
                    d2o++;
                    if(row==i&&column==j&&chip=='O'){
                        control2='O';
                    }
                }
            }
        }
        if(x==2&&control=='O'||d1x==2&&control1=='O'||d2x==2&&control2=='O'||o==2&&control=='X'||d1o==2&&control1=='X'||d2o==2&&control2=='X'){
                        *score=*score+2;
        }
        if(x==2&&control=='X'&&o==0||d1x==2&&control1=='X'&&d1o==0||d2x==2&&control2=='X'&&d2o==0||o==2&&control=='O'&&x==0||d1o==2&&control1=='O'&&d1x==0||d2o==2&&control2=='O'&&d2x==0){
                        *score=*score+1;
        }
    }
    if(x==N||d1x==N||d2x==N){
        *winner='X';
        return 1;
    }
    if(o==N||d1o==N||d2o==N){
        *winner='O';
        return 1;
    }
    x=0; o=0;          
    for(j=0;j<N&&x<N&&o<N;j++){
        x=0;
        o=0;
        control=0;
        for(i=0;i<N;i++){
            if(board[i][j]=='X'){
                x++;
                if(row==i&&column==j&&chip=='X'){
                    control='X';
                }
            }
            if(board[i][j]=='O'){
                o++;
                if(row==i&&column==j&&chip=='O'){
                    control='O';
                }
            }
        }
        if(x==2&&control=='O'||o==2&&control=='X'){
            *score=*score+2;
        }
        if(x==2&&control=='X'&&o==0||o==2&&control=='O'&&x==0){
            *score=*score+1;
        }
    }
    if(x==N||o==N){
        if(x==N){
            *winner='X';
        }
        else{
            *winner='O';                                
        }
        return 1;
    }
    else{
        return 0;
    }
}
 
void Play(struct game mygames[],int *count,int pause[]){
    int i,j,r,turn=0,k;
    char chip,fst,snd;
    float pos;
    if(mygames[*count].firstplayer!='X'&&mygames[*count].firstplayer!='O'){
        printf("\n\nWhich player starts? ");
        chip=first_player();
        mygames[*count].firstplayer=chip;
        printf ("%c",chip);
        //store who starts
        if(chip=='X'){
            fst=chip;
            snd='O';
            printf("\n\nFirst player plays with X and Secon player plays with O\n");
        }
        else{
            fst=chip;
            snd='X';
            printf("\n\nFirst player plays with O and Secon player plays with X\n");
        }
    }
    else{
        chip=mygames[*count].firstplayer;
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(mygames[*count].board[i][j]!='X'&&mygames[*count].board[i][j]!='O'){
                mygames[*count].board[i][j]='-';
            }
            else{
                turn++;
            }
        }
    }
    if(turn%2==1){
        chip=change(chip);
    }
    do{
        Guide_board(mygames[*count].board);
        filled_board(mygames[*count].board);
        do{
            k=position(&i,&j);
        }while(mygames[*count].board[i][j]!='-'&&k==1);
        if(k==0){
            pause[*count]=1;
        }
        mygames[*count].moves[0][turn]=i+1;
        mygames[*count].moves[1][turn]=j+1;
        if(mygames[*count].board[i][j]=='-'){
            mygames[*count].board[i][j]=chip;
        }
        r=tic_tac(mygames[*count].board,&mygames[*count].winner,i,j,chip,&mygames[*count].moves[2][turn]);
        chip=change(chip);
        turn++;
    }while (r==0&&check(mygames[*count].board)==1&&k==1);
    if(r==1){
        printf("\n %c WINS!!",mygames[*count].winner);
    }
    if(r==0&&check(mygames[*count].board)==0&&k==1){
        printf("\n STALEMATE!!");
    }
    if(k==1){
        final_filled_board(mygames[*count].board);
    }
    if(r==0&&check(mygames[*count].board)==0&&k==1){
        int scorex=0,scoreo=0;
        if(mygames[*count].firstplayer=='X'){
            for(turn=1;turn<=N*N;turn++){
                if(turn%2==1){
                    scorex=scorex+mygames[*count].moves[2][turn-1];
                }
                else{
                    scoreo=scoreo+mygames[*count].moves[2][turn-1];
                }
            }
        }
        else{
            for(turn=1;turn<=N*N;turn++){
                if(turn%2==0){
                    scorex=scorex+mygames[*count].moves[2][turn-1];
                }
                else{
                    scoreo=scoreo+mygames[*count].moves[2][turn-1];
                }
            }
        }
        if(scorex>scoreo){
            mygames[*count].winner='X';
        }
        else{
            if (scorex==scoreo){
                mygames[*count].winner=change(mygames[*count].firstplayer);
            }
            else{
                mygames[*count].winner='O';
            }
        }
        printf ("\n\nscore X: %i\nscore O: %i",scorex,scoreo);
    }
    if(k==1){
        printf("\n\n\nfirst: %c\nwinner: %c\nrow:              ",mygames[*count].firstplayer,mygames[*count].winner);
        for(turn=0;turn<N*N;turn++){
            printf("%i ",mygames[*count].moves[0][turn]);
        }
        printf("\ncolumn:           ");
        for(turn=0;turn<N*N;turn++){
            printf("%i ",mygames[*count].moves[1][turn]);
        }
        printf("\nscore:              ");
        for(turn=0;turn<N*N;turn++){
            printf("%i ",mygames[*count].moves[2][turn]);
        }
    }
    puts("\n");
    *count=*count+1;
}
 
int Restart(int pause[MAX]){
    int i,j=0,yes[MAX],pos;
    for(i=0;i<MAX;i++){
        yes[i]=-1;
    }
    for(i=0;i<MAX;i++){
        if(pause[i]==1){
            yes[j]=i;
            j++;
        }
    }
    if(yes[0]>-1){
        puts("POSSIBLE GAMES");
        puts("**************");
        for (i=0;i<MAX;i++){
            if(pause[i]==1){
                printf("\ngame in positon %i",i);
            }
        }
        do{
            puts("\nSELECT POSITION: ");
            scanf("%i",&pos);
            for(i=0;i<j;i++){
                if(pos==yes[i]){
                    i=MAX;
                }
            }
            if(i!=(MAX+1)){
                pos=-1;
            }
        }while(pos==-1);
    }
}
 
void Delete(struct game mygames[], int *count,int pause[]) {
    if (*count==0&&mygames[*count].firstplayer!='X'&&mygames[*count].firstplayer!='O') {
        printf("\n''NO GAMES TO DELETE!!!\n");
    }
    else{
        int i,game_num,j;
        printf("Select a game to delete:\n");
        for (i=0;i<*count;i++) {
            printf("Game %d\n", i);
        }
        do {
            printf("Enter a number (0-%d): ",*count-1);
            scanf("%d",&game_num);
        } while (game_num<0||game_num>*count);
        for ( i=game_num; i<*count;i++) {
            mygames[i]=mygames[i+1];
        }
        (*count)--;
        for(i=0;i<MAX;i++){
            if(pause[i]==game_num){
                for(j=i;j<MAX;j++){
                    pause[j]=pause[j+1];
                }
                pause[j]=0;
            }
        }
    }  
}
 
void Statistics(struct game mygames[]){
    int played=0,end=0,stop=0,win=0,steal=0,j=-1,k=-1,i,r;
    int turn=0;
    char chip='X';
    for(i=0;i<MAX;i++){
        if(mygames[i].firstplayer=='X'||mygames[i].firstplayer=='O'){
            played++;
        }
        if(mygames[i].winner=='X'||mygames[i].winner=='O'){
            end++;
            r=tic_tac(mygames[i].board,&mygames[i].winner,i,j,chip,&mygames[i].moves[2][turn]);
            if(r==0){
                            steal++;
            }
        }
    }
    stop=played-end;
    win=end-steal;
    printf("\nNumber of played games:     %i\nNumber of ended games: %i\nNumber of stopped games:             %i\nNumber of games won getting a tic_tac_toe:       %i\nNumber of games won by points (stalemate situation):     %i\n",played,end,stop,win,steal);
}