#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
/*ÿ���豸����Ϣ�������豸��ţ�Ψһ�����豸���ͣ��ʼǱ���̨ʽ����ƽ����ԡ�ͶӰ�ǡ�ɨ���ǡ���ӡ��������������������
�豸�ͺţ��������ڣ��ꡢ�¡��գ�������۸񣬹���Ա���Լ��豸״̬�����á���ά�ޡ������ϣ���*/
struct mo//Ԫ�Ƿ� 
{
	int yuan;
	int jiao;
	int fen;
};
struct device//�豸��Ϣ 
{
	char bh[20];//�豸��ţ�Ψһ��
	char lx[20];//�豸����,ABCD...(�ʼǱ���ӦA) 
	char xh[20];//�豸�ͺ�
	int nian;//�� 
	int yue;//�� 
	int ri; //�� 
	struct mo n;//����۸�	
	char xm[20];//����Ա
	char T[20];//�豸״̬,Y��Ӧ�豸���ã�N��Ӧ�����ϣ�P��Ӧ��ά�� 
	struct device *next;
}; 
struct device * top;//ͷָ��
struct device * rear=NULL;//βָ��
void document();
void tj();//���
void cx();//��ѯ
void cx_bh(int u);//�豸��Ų�ѯ 
void cx_lx(int u);//�豸���Ͳ�ѯ
void cx_xh(int u);//�豸�ͺŲ�ѯ
void cx_gmrq(int u);//�豸�������ڲ�ѯ
void cx_gmjg(int u);//�豸����۸��ѯ
void cx_glyxm(int u);//�豸����Ա������ѯ
void cx_zt(int u);//�豸״̬��ѯ
void sc();//ɾ�� 
void xg();//�޸�
void tji();//ͳ�� 
void sc2(char *qq);//ɾ�� 
void document(){//���ļ�¼����Ϣ 
	FILE *fp;
	struct device *p;
	p=top;
	fp=fopen("F:\\sysglxt.txt","r");//���ļ� 
	if(fp==NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}//���ļ�ʧ�����˳�       
	while(!feof(fp))
	{
		p=(struct device*)malloc(sizeof(struct device));//����ռ䣬��ַ����p 
		fscanf(fp,"%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s",p->bh,p->lx,p->xh,&p->nian,&p->yue,&p->ri,&p->n.yuan,&p->n.jiao,&p->n.fen,p->xm,p->T);
		p->next=NULL;
		if(rear==NULL){
			rear=p;
			top=p;
		}
		else{
			rear->next=p;
			rear=p;
		}
	}//���ļ��е���Ϣ���������� 
	fclose(fp); 
	struct device *vv=top;
	while(vv->next!=rear)
	{
		vv=vv->next;
	}
	vv->next=NULL;
    free(rear);
    rear=vv;//Ѱ��ĩβ��ַ 
}
void tj(){//���ģ�� 
      struct device *p;
      struct device *i;
      int c,v,t,j;
      printf("����������豸������\n");
      scanf("%d",&t);
      for(j=1;j<=t;j++)
      {
      	  p=(struct device*)malloc(sizeof(struct device));
	      c=1;
	  	  while (c==1)//�������ı���ظ����򷴸������ţ�ֱ�����ֿ��ñ�� 
	        {
               printf("\n�������豸��ţ���λ���֣���001 067):\n");   
               scanf("%s",p->bh); 
               i=top;
               v=1;  //v�жϱ���ظ� ������boolean����ʹ�� 
               while (i!=NULL)
               {
         	      if (strcmp(i->bh,p->bh)==0) v=0;
         	      i=i->next;
               }
               if (v==1) c=0;
	   	       else 
	           {
		        	printf("����ظ��������������豸���\n"); 
		       } 
		    }
         printf("\n�������豸���ͣ�A����ʼǱ����� B����̨ʽ���� C����ƽ����� D����ͶӰ�� E�����ӡ�� F��������� G���������):\n");      
         scanf("%s",&p->lx); 
         printf("\n�������豸�ͺţ���λСд��ĸ,��gyghm):\n");      
         scanf("%s",&p->xh); 
         printf("\n�������豸������ݣ���λ������2017):\n");      
         scanf("%d",&p->nian); 
         printf("\n�������豸�����·ݣ���1 11):\n");      
         scanf("%d",&p->yue); 
         printf("\n�������豸�������ڣ��� 7 28):\n");      
         scanf("%d",&p->ri); 
         printf("\n�������豸�۸��Ԫ���֣���5668 789):\n");      
         scanf("%d",&p->n.yuan); 
         printf("\n�������豸�۸�Ľǲ��֣���9):\n");      
         scanf("%d",&p->n.jiao); 
         printf("\n�������豸�۸�ķֲ��֣���7):\n");      
         scanf("%d",&p->n.fen); 
         printf("\n�������豸����Ա����ƴ������wangxiaoming):\n");      
         scanf("%s",&p->xm); 
         printf("\n�������豸״̬��Y�������� N��������� P������ά��):\n");      
         scanf("%s",&p->T); 
         rear->next=p;
		 rear=p;
		 rear->next=NULL; 
         printf("��ʾ:�Ѿ����һ����¼����ӡ�\n");
      }
}
void liul()//���ģ��
{
    struct device * p;
	p=top;
	if(top!= NULL)
	{
		printf("\n��� ���� �ͺ�  ��    ��  ��   Ԫ    �� �� ����Ա             ״̬\n");
		do
		{
			printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
			p=p->next;
		}while(p != NULL);
    }
}
void cx()//��ѯ�豸��Ϣ 
{
	    int choice=1;
	    while(choice!=0)//��ѯ��ʽ 
	    {
         printf("����1�����豸��Ų���\n");
         printf("����2�����豸���Ͳ���\n");
         printf("����3�����豸�ͺŲ���\n");
         printf("����4�����豸�������ڲ���\n");
         printf("����5�����豸����۸����\n");
         printf("����6�����豸����Ա��������\n");
         printf("����7�����豸״̬����\n");
         printf("����0�����˳�\n");
	     scanf("%d",&choice);	
         switch(choice)
  	         {
	  	       case 0:break;
	  	       case 1:cx_bh(0);break;
	  	       case 2:cx_lx(0);break;
	  	       case 3:cx_xh(0);break;
	  	       case 4:cx_gmrq(0);break;
	  	       case 5:cx_gmjg(0);break;
	  	       case 6:cx_glyxm(0);break;
	  	       case 7:cx_zt(0);break;
	  	       default:
	  	       printf("������Ч����������\n");cx(); break;
 	         }
	    }
}

void cx_bh(int u)//���豸��Ų�ѯ 
{
	int choice;
	int t=0;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("��������Ҫ��ѯ���豸���:\n");
    scanf ("%s",find);//�����ѯ���豸��� 
		while(p!=NULL){//����
		p0=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->bh,find  )==0)
	    {
	     printf("\n��� ���� �ͺ�  ��    ��  ��   Ԫ    �� ��    ����Ա            ״̬\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;//��������������ҵ����豸���� 
         p1=p;
	    }
	    else;
	   }
	   if(u==0&&t==0)//�ҵ��ĸ���Ϊ0����û�з���Ҫ����豸 
	   {
	   	    printf("û����Ҫ���ҵ���Ϣ��\n");printf("��������1�����ϲ�˵�\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1)//��u�ֱ��Ƿ�Ϊ��Ҫɾ����ָ��˴����ҵ��Ŀι�ѡ����豸��Ϣ����һ�� ��ѡ���� 
	   {
	      printf("������Ҫɾ�����豸��Ϣ�ı��\n");
	      char yy[20];
	      scanf("%s",yy);
	      sc2(yy);
       }
       else if(u==1&&t==1)//��u�ֱ��Ƿ�Ϊ��Ҫɾ����ָ��˴����ҵ��Ŀι�ѡ����豸��Ϣֻ��һ����ֱ��ɾ�� 
	   {
       	 struct device* q=top;
	     struct device* r=top;
	     while(q!=NULL&&q->next!=p1)
		 {
	    	q=q->next;
	     }
	     r=p1->next;
	     q->next=r;
	     free(p1);
       }
}
void cx_lx(int u)//���豸���Ͳ�ѯ 
{
	int choice;
	int t=0;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("��������Ҫ��ѯ���豸���ͣ�A����ʼǱ����ԣ�B����̨ʽ���ԣ�C����ƽ����ԣ�D����ͶӰ�ǣ�E�����ӡ����F�����������G���������):\n");
    scanf ("%s",find);//�����ѯ���豸���� 
		while(p!=NULL){//����
		p0=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->lx,find   )==0)
	    {
	     printf("\n��� ���� �ͺ�  ��    ��  ��   Ԫ    �� ��    ����Ա            ״̬\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;
         p1=p;
	    }
	    else;
	   }
	   if(u==0&&t==0)
	   {
	   	    printf("û����Ҫ���ҵ���Ϣ��\n");printf("��������1�����ϲ�˵�\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("������Ҫɾ�����豸��Ϣ�ı��\n");
	   char yy[20];
	   scanf("%s",yy);
	   sc2(yy);
       }
       else if(u==1&&t==1){
       	struct device* q=top;
	    struct device* r=top;
	    while(q!=NULL&&q->next!=p1){
	    	q=q->next;
	    }
	    r=p1->next;
	    q->next=r;
	    free(p1);
       }
}
void cx_xh(int u)//���豸�ͺŲ�ѯ 
{
	int choice;
	int t=0;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("��������Ҫ��ѯ���豸�ͺ�:\n");
    scanf ("%s",find);//�����ѯ���豸�ͺ� 
		while(p!=NULL)
		{//����
		  p0=p;
		  p=p->next;
	     if(p!=NULL&&strcmp(p->xh,find  )==0)
	       {
	        printf("\n��� ���� �ͺ�  ��    ��  ��   Ԫ    �� ��    ����Ա            ״̬\n");
            printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
            t++;
            p1=p;
	       }
	    else;
	    }
	   if(u==0&&t==0)
	   {
	   	    printf("û����Ҫ���ҵ���Ϣ��\n");printf("��������1�����ϲ�˵�\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1)
	   {
	      printf("������Ҫɾ�����豸��Ϣ�ı��\n");
	      char yy[20];
	      scanf("%s",yy);
	      sc2(yy);
       }
       else if(u==1&&t==1)
	   {
       	struct device* q=top;
	    struct device* r=top;
	    while(q!=NULL&&q->next!=p1)
		{
	    	q=q->next;
	    }
	    r=p1->next;
	    q->next=r;
	    free(p1);
       }
}
void cx_gmrq(int u)//���豸�������ڲ�ѯ 
{
	int choice;
	int t=0;
	int nf,yf,rq;
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("��������Ҫ��ѯ���豸�������:\n");
    scanf ("%d",&nf);
	printf("��������Ҫ��ѯ���豸�����·�:\n");
    scanf ("%d",&yf);
    printf("��������Ҫ��ѯ���豸��������:\n");
    scanf ("%d",&rq);//�����ѯ���豸�������� 
		while(p!=NULL)
		{//����
		   p0=p;
		   p=p->next;
	       if(p!=NULL&&p->nian==nf&&p->yue==yf&&p->ri==rq)
	       {
	          printf("\n��� ���� �ͺ�  ��    ��  ��   Ԫ    �� ��    ����Ա            ״̬\n");
              printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
              t++;
              p1=p;
	       }
	    else;
	    }
	   if(u==0&&t==0)
	   {
	   	    printf("û����Ҫ���ҵ���Ϣ��\n");printf("��������1�����ϲ�˵�\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("������Ҫɾ�����豸��Ϣ�ı��\n");
	   char yy[20];
	   scanf("%s",yy);
	   sc2(yy);
       }
       else if(u==1&&t==1){
       	struct device* q=top;
	    struct device* r=top;
	    while(q!=NULL&&q->next!=p1){
	    	q=q->next;
	    }
	    r=p1->next;
	    q->next=r;
	    free(p1);
       }
}
void cx_gmjg(int u)//���豸����۸��ѯ 
{
	int choice;
	int t=0;
	int y,j,f;
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("��������Ҫ��ѯ���豸����۸�Ԫ:\n");
    scanf ("%d",&y);
	printf("��������Ҫ��ѯ���豸����۸��:\n");
    scanf ("%d",&j);
    printf("��������Ҫ��ѯ���豸����۸��:\n");
    scanf ("%d",&f);//�����ѯ���豸����۸� 
		while(p!=NULL){//����
		p0=p;
		p=p->next;
	    if(p!=NULL&&p->n.yuan==y&&p->n.jiao==j&&p->n.fen==f)
	    {
	     printf("\n��� ���� �ͺ�  ��    ��  ��   Ԫ    �� ��    ����Ա            ״̬\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;
         p1=p;
	    }
	    else;
	   }
	   if(u==0&&t==0)
	   {
	   	    printf("û����Ҫ���ҵ���Ϣ��\n");printf("��������1�����ϲ�˵�\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("������Ҫɾ�����豸��Ϣ�ı��\n");
	   char yy[20];
	   scanf("%s",yy);
	   sc2(yy);
       }
       else if(u==1&&t==1){
       	struct device* q=top;
	    struct device* r=top;
	    while(q!=NULL&&q->next!=p1){
	    	q=q->next;
	    }
	    r=p1->next;
	    q->next=r;
	    free(p1);
       }
}
void cx_glyxm(int u)//���豸����Ա������ѯ 
{
	int choice;
	int t=0;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("��������Ҫ��ѯ���豸����Ա��������wangxiaoming):\n");
    scanf ("%s",find);//�����ѯ���豸����Ա���� 
		while(p!=NULL){//����
		p0=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->xm,find)==0)
	    {
	     printf("\n��� ���� �ͺ�  ��    ��  ��   Ԫ    �� ��    ����Ա            ״̬\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;
         p1=p;
	    }
	    else;
	   }
	   if(u==0&&t==0)
	   {
	   	    printf("û����Ҫ���ҵ���Ϣ��\n");printf("��������1�����ϲ�˵�\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("������Ҫɾ�����豸��Ϣ�ı��\n");
	   char yy[20];
	   scanf("%s",yy);
	   sc2(yy);
       }
       else if(u==1&&t==1){
       	struct device* q=top;
	    struct device* r=top;
	    while(q!=NULL&&q->next!=p1){
	    	q=q->next;
	    }
	    r=p1->next;
	    q->next=r;
	    free(p1);
       }
}
void cx_zt(int u)//���豸״̬��ѯ 
{
	int choice;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	int t=0;
	p0=NULL;
	p=top;
	printf("��������Ҫ��ѯ���豸���״̬:\n");
    scanf ("%s",find);//�����ѯ���豸״̬ 
		while(p!=NULL){//����
		p0=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->T,find )==0)
	    {
	     printf("\n��� ���� �ͺ�  ��    ��  ��   Ԫ    �� ��    ����Ա            ״̬\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;
         p1=p;
	    }
	    else ;
		}
		if(u==0&&t==0)
	   {
	   	    printf("û����Ҫ���ҵ���Ϣ��\n");printf("��������1�����ϲ�˵�\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("������Ҫɾ�����豸��Ϣ�ı��\n");
	   char yy[20];
	   scanf("%s",yy);
	   sc2(yy);
       }
       else if(u==1&&t==1){
       	struct device* q=top;
	    struct device* r=top;
	    while(q!=NULL&&q->next!=p1){
	    	q=q->next;
	    }
	    r=p1->next;
	    q->next=r;
	    free(p1);
       }
}
void sc2(char *qq){
	    struct device *p;
	    struct device* q;
	    struct device* r;
	    p=top;
	    while(p!=NULL){//����
		q=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->bh,qq)==0)
	    {
	    	q->next=p->next;//�ͷ���ɾ���ڴ�
	        r=p;
	        p=p->next;
	        free(r);
	    }
	    else;}	
}
void sc(){
	int choice=1;
	while(choice!=0)//��ѯ��ʽ 
	    {
         printf("����1�����豸���ɾ��\n");
         printf("����2�����豸����ɾ��\n");
         printf("����3�����豸�ͺ�ɾ��\n");
         printf("����4�����豸��������ɾ��\n");
         printf("����5�����豸����۸�ɾ��\n");
         printf("����6�����豸����Ա����ɾ��\n");
         printf("����7�����豸״̬ɾ��\n");
         printf("����0�����˳�\n");
	     scanf("%d",&choice);	
         switch(choice)
  	         {
	  	       case 0:break;
	  	       case 1:cx_bh(1);break;
	  	       case 2:cx_lx(1);break;
	  	       case 3:cx_xh(1);break;
	  	       case 4:cx_gmrq(1);break;
	  	       case 5:cx_gmjg(1);break;
	  	       case 6:cx_glyxm(1);break;
	  	       case 7:cx_zt(1);break;
	  	       default:
	  	       printf("������Ч����������\n");cx(); break;
 	         }
 	         printf("ɾ���ɹ���\n");
 	         break;
	    }
}
void xg(){
	struct device* p;
	p=top;
    printf("������Ҫ�޸ĵ��豸��Ϣ�ı��\n");
	char find[20];
	char z[5];
	scanf ("%s",find);//�����ѯ���豸��� 
	printf("��������Ҫ�޸ĵ���Ŀ����ĸ������ lxd���� xhd�ͺ� mod����۸� nian������� yue�����·� ri�������� gly����Ա ztd״̬\n");//��Ҫ�ĵ�ѡ��
	scanf("%s",z);
	while((strcmp(z,"lxd")!=0)&&(strcmp(z,"xhd")!=0)&&(strcmp(z,"mod")!=0)&&(strcmp(z,"nian")!=0)&&(strcmp(z,"yue")!=0)&&(strcmp(z,"ri")!=0)&&(strcmp(z,"gly")!=0)&&(strcmp(z,"ztd")!=0)){
		printf("����������\n");
		 scanf("%s",z);
	}
	while(p!=NULL&&strcmp(p->bh,find)!=0)
		p=p->next;
	if(p==NULL) {
			printf("û�д���Ϣ\n"); 
               }
	else{
	if((strcmp(z,"lxd")==0)) {
	printf("�豸�����޸�Ϊ��(A����ʼǱ����ԣ�B����̨ʽ���ԣ�C����ƽ����ԣ�D����ͶӰ�ǣ�E�����ӡ����F�����������G���������)\n");
	scanf("%4s",p->lx);
	printf("�޸ĳɹ�Ϊ��%4s\n",p->lx);
	}//��ѡ��
	else if(strcmp(z,"xhd")==0) {
		printf("�޸��豸����Ϊ��(eg:fjkla)\n");
	    scanf("%7s",p->xh);
	    printf("�޸ĳɹ�Ϊ��%7s\n",p->xh);}
	else if(strcmp(z,"mod")==0) {
		printf("�޸Ļ��ѽ��Ϊ��(eg:34 7 8)\n");
	    scanf("%d%d%d",&p->n.yuan,&p->n.jiao,&p->n.fen);
	    if(p->n.jiao>59) p->n.jiao=59;
	    if(p->n.fen>59) p->n.fen=59;
	    printf("�޸ĳɹ�Ϊ��%dԪ%d��%d��\n",p->n.yuan,p->n.jiao,p->n.fen);}
	else if(strcmp(z,"nian")==0) { 
        printf("�޸���Ϊ��\n");
	    scanf("%d",&p->nian);
	    printf("�޸ĳɹ�Ϊ��%d\n",p->nian);}
	else if(strcmp(z,"yue")==0) {
	    printf("�޸���Ϊ(eg:7 8)��\n");
		scanf("%d",&p->yue);
	    printf("�޸ĳɹ�Ϊ��%d\n",p->yue);}
	else if(strcmp(z,"ri")==0) {
		printf("�޸���Ϊ����eg:2 4��\n");
		scanf("%d",&p->ri);
		printf("�޸ĳɹ�Ϊ��%d\n",p->ri);}
	else if(strcmp(z,"gly")==0) {
		printf("�޸��豸����Ա����Ϊ��(eg:wangxiaoming)\n");
	    scanf("%20s",p->xm);
	    printf("�޸ĳɹ�Ϊ��%20s\n",p->xm);}
	else if(strcmp(z,"ztd")==0) {
		printf("�޸��豸״̬Ϊ��(Y�������ã�N��������ϣ�P������ά�ޣ�\n");
	    scanf("%2s",p->T);
	    printf("�޸ĳɹ�Ϊ��%7s\n",p->T);}
}}

void tji()//ͳ�ƹ��� 
{
	int t=0;
	int w=0,n1=0,k1=0;
	int f=0,g=0,h=0;
	struct device *p;
	struct device *p0;
	p=top;
	while(p!=NULL){
		p0=p;
		p=p->next;
		t++;
		if(p!=NULL){
		w=w+p->n.fen ;
    	n1=n1+p->n.jiao ;
    	k1=k1+p->n.yuan ;}  //ͳ���豸�ܽ�� 
		}
	n1=n1+(w-w%10)/10;
	h=w%10;
	g=n1%10;
	f=k1+(n1-n1%10)/10;
	printf("ʵ�����豸��������%d",t);	
	printf("ʵ�����豸�ܼ۸���%10dԪ%4d%��%4d��\n",f,g,h);		
}
void bc(){//����ģ��
	FILE *fp;
	struct device *p;
	p=top;
	fp=fopen("F:\\sysglxt.txt","w");//���ļ� 
	if(fp==NULL){
		printf("���ļ�ʧ��\n");
		exit(0);
	}//���ļ�ʧ�����˳�       
	while(p!= NULL){
			fprintf(fp,"%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
			p=p->next;
		}//��������Ϣ¼��	
	fclose(fp); 
	printf("����ɹ���\n");
}
main()//���˵� 
{
 	char R;
 	char U;
 	document();
 	printf("����ɴ��ļ�¼����Ϣ\n");
 	while(1)
	 {
      	printf("��ѡ����Ҫ������Ŀ��A����豸��Ϣ  B������е��豸��Ϣ C��ѯ�豸��Ϣ \n"); //����ѡ����й��� 
        printf("Dɾ���豸��Ϣ E�޸��豸��Ϣ F����ͳ���豸�ܼۻ�����  \n");
	    printf("G�����豸��Ϣ���ļ��� H�˳���ϵͳ \n");
	   scanf("%c",&R);
	   if (R==10)  scanf("%c",&R);
	    getchar();
	    if (R<'A'||R>'H')//�Ϸ�������ݴ��� 
    	{
	     	printf("���벻�Ϸ�������������\n");
            scanf("%c",&R);
	    }
	    if(R=='A') tj();
        else if(R=='B') liul();
        else if(R=='C') cx();
        else if(R=='D') sc();
        else if(R=='E') xg();
        else if(R=='F') tji();
        else if(R=='G') bc();
        else if (R=='H') 
		{
			printf("�Ƿ�Ҫ���棿��������Y������������N\n");//�Է��˳���ʧ���ݣ��˳�ʱѯ���Ƿ񱣴� 
			scanf("%c",&U);
			if (U=='Y') bc(); 
			break;			
		}

     }
}   
