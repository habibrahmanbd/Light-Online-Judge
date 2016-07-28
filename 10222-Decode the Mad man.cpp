#include<stdio.h>
#include<string.h>
int main()
{
char l[200];
int i,n,k,len;
while(gets(l)){
len=strlen(l);
for(i=0;i<len;i++){
if(l[i]==']') printf("p");
else if(l[i]=='[') printf("o");
else if((l[i]=='p')||(l[i]=='P')) printf("i");
else if((l[i]=='o')||(l[i]=='O')) printf("u");
else if((l[i]=='i')||(l[i]=='I')) printf("y");
else if((l[i]=='u')||(l[i]=='U')) printf("t");
else if((l[i]=='y')||(l[i]=='Y')) printf("r");
else if((l[i]=='t')||(l[i]=='T')) printf("e");
else if((l[i]=='r')||(l[i]=='R')) printf("w");
else if((l[i]=='e')||(l[i]=='E')) printf("q");
else if((l[i]=='w')||(l[i]=='W')) printf("w");
else if((l[i]=='q')||(l[i]=='Q')) printf("q");
else if(l[i]=='"') printf("l");
else if((l[i]==';')||(l[i]==')')) printf("k");
else if((l[i]=='l')||(l[i]=='L')) printf("j");
else if((l[i]=='k')||(l[i]=='K')) printf("h");
else if((l[i]=='j')||(l[i]=='J')) printf("g");
else if((l[i]=='h')||(l[i]=='H')) printf("f");
else if((l[i]=='g')||(l[i]=='G')) printf("d");
else if((l[i]=='f')||(l[i]=='F')) printf("s");
else if((l[i]=='d')||(l[i]=='D')) printf("a");
else if((l[i]=='/')||(l[i]=='?')) printf(",");
else if((l[i]=='.')||(l[i]=='>')) printf("m");
else if((l[i]==',')||(l[i]=='<')) printf("n");
else if((l[i]=='m')||(l[i]=='M')) printf("b");
else if((l[i]=='n')||(l[i]=='N')) printf("v");
else if((l[i]=='b')||(l[i]=='B')) printf("c");
else if((l[i]=='v')||(l[i]=='V')) printf("x");
else if((l[i]=='c')||(l[i]=='C')) printf("z");
else if((l[i]=='x')||(l[i]=='X')) printf("x");
else if((l[i]=='z')||(l[i]=='Z')) printf("z");
else if(l[i]=='\'')printf("l");
else if(l[i]=='=') printf("0");
else if(l[i]=='-') printf("9");
else if(l[i]=='0') printf("8");
else if(l[i]=='9') printf("7");
else if(l[i]=='8') printf("6");
else if(l[i]=='7') printf("5");
else if(l[i]=='6') printf("4");
else if(l[i]=='5') printf("3");
else if(l[i]=='4') printf("2");
else if(l[i]=='3') printf("1");
else if(l[i]=='2') printf("`");
else printf("%c",l[i]);
}
printf("\n");
}
return 0;
}
