//the problem is to put 8 chess queens on a table of 8 * 8 without being eliminated between them stating with the position of a queen

#include <bits/stdc++.h>

using namespace std;

int arrayRow[8];
int x,y; //Position x,y of the first queen
int counter;//this is the counter of the num of solutions
//this function verific if in this place it is posible to put a queen
bool verPlace(int row,int col){
    //arrayRow[i]==row this is to compare if in the same row
    //the col is not necesary to compare because it is done in the for
    //abs(x1-x2)!=abs(y1-y2) is the condition to diagonal lines
    for(int i=0;i<col;i++)
        if(arrayRow[i]==row || (abs(arrayRow[i]-row)==abs(i-col))){
            return false;
        }
        return true;
}

//this function as their name say it calling her self put a queen in a place and calling her self
void autoCalling(int col){
    if(col == 8 && arrayRow[y]==x){
        //print the num of the solution and the first position of the row
        printf("%2d      %d", ++counter, arrayRow[0] + 1);
        for(int i=1;i<8;i++){
            //print the rest of the position of in row of the solution
            cout<<" "<<arrayRow[i]+1;
        }
        cout<<""<<endl;
    }
    //is try all the possibles next row
    for(int j=0;j<8;j++){
        //verific if the row is correct to put a queen
        if(verPlace(j,col)){
            //assign a row to a col
            arrayRow[col]=j;
            //call her self
            autoCalling(col+1);
        }
    }
}





int main() {
    int n;
    //number of cases
    cin>>n;
    while(n--){
        //get the position of the first queen
        scanf("%d %d", &x, &y); x--; y--;
        //filling the array with 0
        memset(arrayRow,0,sizeof arrayRow);
        counter=0;
        //Simple decoration
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        //call the function that find all the queens
        autoCalling(0);
        if(n){
            printf("\n");
        }
    }
    return 0;

}
