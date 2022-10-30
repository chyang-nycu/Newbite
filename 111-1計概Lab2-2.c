#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main(){
    char key[] = "the quick brown fox jumps over the lazy dog";
    char from[]= "xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj";
    char note[105][85];//行數 字數
    int n;
    scanf("%d", &n);
    scanf(" ");//n後面ㄉ那個'\n'

    while(n--){
        scanf(" ");//n & case1 之間ㄉ'\n'
        bool solvable = false;
        int line = 0;
        while(++line){
            //if(fgets(note[line], 85, stdin) == NULL) break;
            gets(note[line]);
            if(note[line][0] == '\0' || note[line] == NULL) break;
            //printf("%s", note[line]);
        }

        for(int i = 1; i < line; i++){
            if(strlen(note[i]) == (int)(strlen(key))){
                bool haskey = true;
                for(int j = 0; j < (int)(strlen(key)); j++){
                    if((note[i][j] == ' ' && key[j] != ' ') || (note[i][j] != ' ' && key[j] == ' ')){
                        haskey = false;
                        break;
                    }
                }
                if(haskey){
                    strcpy(from, note[i]);
                    solvable = true;
                    break;
                }
            }
        }

        char trans[30];
        memset(trans, ' ', sizeof(trans));
        for(int i = 0; i < (int)(strlen(key)); i++){
            if(from[i] == ' ')continue;
            if(trans[(int)(from[i] - 'a')] == ' '){
                trans[(int)(from[i] - 'a')] = key[i];
            }
            else if (trans[(int)(from[i] - 'a')] != key[i]){
                solvable = false;
                break;
            }
        }

        if(!solvable){
            printf("No solution.\n");
            if(n) printf("\n");
            continue;
        }
        for(int i = 1; i < line; i++){
            for(int j = 0; j < (int)(strlen(note[i])); j++){
                if(note[i][j] < 'a' || note[i][j] > 'z') printf("%c", note[i][j]);
                else printf("%c", trans[(int)(note[i][j] - 'a')]);
            }
            printf("\n");
        }
        if(n) printf("\n");
    }
    return 0;
}
