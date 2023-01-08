#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
int getline1(char s[]){
    char getchar='\0';
    int chars=0;
    while(chars<LINE){
        if (scanf("%c",&getchar)==-1){
            *(s+chars)='\0';
            break;
        }
        else if(getchar=='\n'){
            *(s+chars)='\0';
            break;
        }
        else{
            *(s+chars)=getchar;
            chars++;
        }
    }
    return chars;
}
int getword(char w[]){
    char getchar='\0';
    int chars=0;
    while(chars<WORD){
        if (scanf("%c",&getchar)==-1){
            *(w+chars)='\0';
            break;
        }
        else if(getchar=='\n'||getchar=='\t'||getchar==' '){
            *(w+chars)='\0';
            break;
        }
        else{
            *(w+chars)=getchar;
            chars++;
        }
    }
    return chars;
}
int substring(char *str1,char *str2){
    for (int i=0;i<=strlen(str1)-strlen(str2);i++){
        int counter=0;
        for (int j=0;j<=strlen(str2);j++){
            if (*(str1+i+j)==*(str2+j)){
                counter++;
            }
        }
        if (counter>=strlen(str2)){
            return 1;
        }
    }
    return 0;
}
int similar(char *s,char *t,int n){
    if (strlen(s)-strlen(t)!=n){
        return 0;
    }
    int j=0;
    for (int i=0;i<strlen(s);i++){
        if(j>=strlen(t)){
            break;
        }
        if (*(s+i)==*(t+j)){
            j++;
        }
    }
    if(strlen(t)==j){
        return 1;
    }
    else{
        return 0;
    }
}
void print_lines(char *str){
    char line[LINE]={0};
    while(getline1(line)>0){
        if(substring(line,str)==1){
            printf("%s\n",line);
        }
    }
}
void print_similar_words(char *str){
    char word[WORD]={0};
    while(getword(word)>0){
        if(similar(word,str,1)==1||similar(word,str,0)==1){
            printf("%s\n",word);
        }
    }
}
int main(){
    char word[WORD]={0};
    char aorb='\0';
    getword(word);
    scanf(" %c\n",&aorb);
    if(aorb=='a'){
        print_lines(word);
    }
    else if(aorb=='b'){
        print_similar_words(word);
    }
    else{
        printf("error\n");
    }
    return 0;
}