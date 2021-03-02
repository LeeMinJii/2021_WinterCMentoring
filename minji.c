#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char name[10];
    char prog[2];
    char math1[2];
    char math2[2];
    struct node *next;
}node;

node *head;

void int_into_char(int a,char score[2]){
    if (a>=97 && a<=100){
        score[0]='A';
        score[1]='+';
    }
    else if (a>=94&&a<=96){
       score[0]='A';
       score[1]='0';
    }
    else if (a>=90 && a<=93){
        score[0]='A';
        score[1]='-';
    }
    else if (a>=87&&a<=89){
        score[0]='B';
        score[1]='+';
    }
    else if (a>=84&&a<=86){
        score[0]='B';
        score[1]='0';
    }
    else if (a>=80&&a<=83){
        score[0]='B';
        score[1]='-';
    }  
    else if (a>=77&&a<=79){
        score[0]='C';
        score[1]='+';
    }  
    else if (a>=74&&a<=76){
        score[0]='C';
        score[1]='0';
    }  
    else if (a>=70&&a<=73){
        score[0]='C';
        score[1]='-';
    }  
    else if (a>=67&&a<=69){
        score[0]='D';
        score[1]='+';
    }  
    else if (a>=64&&a<=66){
        score[0]='D';
        score[1]='0';
    }
    else if (a>=60&&a<=63){
        score[0]='D';
        score[1]='-';
    }
    else if (a<60){
        score[0]='F';
    }  
}

void AddGrade(){
    node *grade=(node *)malloc(sizeof(node));
    head->next=grade;
    node *cur=(node *)malloc(sizeof(node));
    cur=grade;

    int p,m1,m2;
    printf("학생 이름 : ");
    scanf("%s",cur->name);

    printf("프로그래밍 및 실습1 : ");
    scanf("%d",&p);
    int_into_char(p,cur->prog);

    printf("컴퓨터수학1 : ");
    scanf("%d",&m1);
    int_into_char(m1,cur->math1);

    printf("컴퓨터수학2 : ");
    scanf("%d",&m2);
    int_into_char(m2,cur->math2);

    cur=cur->next;
}

void ConfirmGrade(){
    node *p=(node *)malloc(sizeof(node));
    p=head->next;
    printf("--------------------------------------------------\n 이름  프로그래밍 및 실습1 컴퓨터수학1 컴퓨터수학2 등수\n--------------------------------------------------\n");
    printf("%s        %s         %s          %s\n",p->name,p->prog,p->math1,p->math2);
}

int menu(){
    int num;
    printf("[ Menu ]\n1. 성적 입력\n2. 성적 확인\n3. 종료\n---------------\n번호를 입력하세요 : ");
    scanf("%d",&num);

    if (num==1){
        AddGrade();
        menu();
    }
    else if (num==2){
        ConfirmGrade();
        menu();
    }
    else if (num==3)
        return 0;
}

int main()
{
    head=(node *)malloc(sizeof(node));
    head->next=NULL;

    menu();

    return 0;
}
