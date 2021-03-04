#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char name[10];
    int stnum;
    char pwd[15];
    int subject[15];
    int grade;
    int credit;
    struct node *next;
}node;
node *head;
int menu();

void confirm_grade(){
    node *list=(node *)malloc(sizeof(node));
    list=head->next;
    node a;
    printf("학번 : ");
    scanf("%d",&a.stnum);

   // if (strcmp(a.stnum,list->stnum)!=0)   //존재하는 학번인지 확인
    printf("\n비밀번호 : ",a.pwd);
   // if //비밀번호 확인
    printf("\n<%s>님의 성적\n");


}
void add_grade(){
    node *list=(node *)malloc(sizeof(node));
    head->next=list;
    printf("학번 : \n");
    scanf("%d",&list->stnum);
    //존재하는 학번인지 확인
    printf("과목 : \n");
    scanf("%s",list->subject);
    printf("성적 : \n");
    scanf("%d",&list->grade);
    printf("학점 : \n");
    scanf("%d",&list->credit);
    FILE *fp=fopen("Grade.txt","w");
    fprintf("학번 : %d 과목 :  %s 성적 : %d 학점 :  %d",&list->stnum,list->subject,&list->grade,&list->credit);
    fclose(fp);
    printf("성적을 더 입력하시려면 1, 그만 입력 받으려면 0을 입력하시오 : <1 or 0 입력>\n");
    int a;
    scanf("%d",&a);
    if (a==1){
        list=list->next;
        add_grade();
    }
    if (a==0){
        printf("성적입력 종료\n");
        menu();
    }
}

void add_student(){
    node *list=(node *)malloc(sizeof(node));
    head->next=list;
    printf("학생이름 : ");
    scanf("%s",list->name);
    printf("\n학번 : ");
    scanf("%d",&list->stnum);
    printf("\n비밀번호 : ");
    scanf("%s",list->pwd);

    FILE *fp=fopen("student.txt","w");
    fprintf(fp,"학생이름 : %s 학번 :  %d 비밀번호 :  %s\n",list->name,&list->stnum,list->pwd);
    fclose(fp);
    list=list->next;
    menu();
}
/*
void delete_student(){
    
}
*/
int menu (){
    printf("[Menu]\n1. 성적확인 2. 성적입력 3. 학생정보등록 4. 학생정보삭제 0. 프로그램 종료\n");
    int a;
    scanf("%d",&a);
    switch(a){
        case 1:
            confirm_grade();
        case 2:
            add_grade();
        case 3:
            add_student();
    //    case 4:
  //          delete_student();
        case 0:
            return 0;
    }
}

int main()
{
    head=(node *)malloc(sizeof(node));
    head->next=NULL;

    menu();
    return 0;
}
