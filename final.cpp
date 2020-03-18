#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
/*每个设备的信息包括：设备编号（唯一），设备类型（笔记本、台式机、平板电脑、投影仪、扫描仪、打印机、照相机、摄像机），
设备型号，购买日期（年、月、日），购入价格，管理员，以及设备状态（良好、需维修、待报废）。*/
struct mo//元角分 
{
	int yuan;
	int jiao;
	int fen;
};
struct device//设备信息 
{
	char bh[20];//设备编号（唯一）
	char lx[20];//设备类型,ABCD...(笔记本对应A) 
	char xh[20];//设备型号
	int nian;//年 
	int yue;//月 
	int ri; //日 
	struct mo n;//购入价格	
	char xm[20];//管理员
	char T[20];//设备状态,Y对应设备良好，N对应待报废，P对应需维修 
	struct device *next;
}; 
struct device * top;//头指针
struct device * rear=NULL;//尾指针
void document();
void tj();//添加
void cx();//查询
void cx_bh(int u);//设备编号查询 
void cx_lx(int u);//设备类型查询
void cx_xh(int u);//设备型号查询
void cx_gmrq(int u);//设备购买日期查询
void cx_gmjg(int u);//设备购买价格查询
void cx_glyxm(int u);//设备管理员姓名查询
void cx_zt(int u);//设备状态查询
void sc();//删除 
void xg();//修改
void tji();//统计 
void sc2(char *qq);//删除 
void document(){//从文件录入信息 
	FILE *fp;
	struct device *p;
	p=top;
	fp=fopen("F:\\sysglxt.txt","r");//打开文件 
	if(fp==NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}//打开文件失败则退出       
	while(!feof(fp))
	{
		p=(struct device*)malloc(sizeof(struct device));//申请空间，地址传给p 
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
	}//将文件中的信息传入链表中 
	fclose(fp); 
	struct device *vv=top;
	while(vv->next!=rear)
	{
		vv=vv->next;
	}
	vv->next=NULL;
    free(rear);
    rear=vv;//寻找末尾地址 
}
void tj(){//添加模块 
      struct device *p;
      struct device *i;
      int c,v,t,j;
      printf("请输入添加设备的组数\n");
      scanf("%d",&t);
      for(j=1;j<=t;j++)
      {
      	  p=(struct device*)malloc(sizeof(struct device));
	      c=1;
	  	  while (c==1)//如果输入的编号重复，则反复输入编号，直到出现可用编号 
	        {
               printf("\n请输入设备编号（三位数字，如001 067):\n");   
               scanf("%s",p->bh); 
               i=top;
               v=1;  //v判断编号重复 ，当做boolean变量使用 
               while (i!=NULL)
               {
         	      if (strcmp(i->bh,p->bh)==0) v=0;
         	      i=i->next;
               }
               if (v==1) c=0;
	   	       else 
	           {
		        	printf("编号重复，请重新输入设备编号\n"); 
		       } 
		    }
         printf("\n请输入设备类型（A代表笔记本电脑 B代表台式电脑 C代表平板电脑 D代表投影仪 E代表打印机 F代表照相机 G代表摄像机):\n");      
         scanf("%s",&p->lx); 
         printf("\n请输入设备型号（五位小写字母,如gyghm):\n");      
         scanf("%s",&p->xh); 
         printf("\n请输入设备购买年份（四位数字如2017):\n");      
         scanf("%d",&p->nian); 
         printf("\n请输入设备购买月份（如1 11):\n");      
         scanf("%d",&p->yue); 
         printf("\n请输入设备购买日期（如 7 28):\n");      
         scanf("%d",&p->ri); 
         printf("\n请输入设备价格的元部分（如5668 789):\n");      
         scanf("%d",&p->n.yuan); 
         printf("\n请输入设备价格的角部分（如9):\n");      
         scanf("%d",&p->n.jiao); 
         printf("\n请输入设备价格的分部分（如7):\n");      
         scanf("%d",&p->n.fen); 
         printf("\n请输入设备管理员姓名拼音（如wangxiaoming):\n");      
         scanf("%s",&p->xm); 
         printf("\n请输入设备状态（Y代表良好 N代表待报废 P代表需维修):\n");      
         scanf("%s",&p->T); 
         rear->next=p;
		 rear=p;
		 rear->next=NULL; 
         printf("提示:已经完成一条记录的添加。\n");
      }
}
void liul()//浏览模块
{
    struct device * p;
	p=top;
	if(top!= NULL)
	{
		printf("\n编号 类型 型号  年    月  日   元    角 分 管理员             状态\n");
		do
		{
			printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
			p=p->next;
		}while(p != NULL);
    }
}
void cx()//查询设备信息 
{
	    int choice=1;
	    while(choice!=0)//查询方式 
	    {
         printf("输入1代表按设备编号查找\n");
         printf("输入2代表按设备类型查找\n");
         printf("输入3代表按设备型号查找\n");
         printf("输入4代表按设备购买日期查找\n");
         printf("输入5代表按设备购买价格查找\n");
         printf("输入6代表按设备管理员姓名查找\n");
         printf("输入7代表按设备状态查找\n");
         printf("输入0代表退出\n");
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
	  	       printf("输入无效请重新输入\n");cx(); break;
 	         }
	    }
}

void cx_bh(int u)//按设备编号查询 
{
	int choice;
	int t=0;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("请输入您要查询的设备编号:\n");
    scanf ("%s",find);//输入查询的设备编号 
		while(p!=NULL){//检索
		p0=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->bh,find  )==0)
	    {
	     printf("\n编号 类型 型号  年    月  日   元    角 分    管理员            状态\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;//计数器，计算查找到的设备总数 
         p1=p;
	    }
	    else;
	   }
	   if(u==0&&t==0)//找到的个数为0，即没有符合要求的设备 
	   {
	   	    printf("没有您要查找的信息！\n");printf("输入数字1返回上层菜单\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1)//用u分辨是否为需要删除的指令，此处查找到的课供选择的设备信息大于一条 ，选择编号 
	   {
	      printf("请输入要删除的设备信息的编号\n");
	      char yy[20];
	      scanf("%s",yy);
	      sc2(yy);
       }
       else if(u==1&&t==1)//用u分辨是否为需要删除的指令，此处查找到的课供选择的设备信息只有一条，直接删除 
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
void cx_lx(int u)//按设备类型查询 
{
	int choice;
	int t=0;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("请输入您要查询的设备类型（A代表笔记本电脑，B代表台式电脑，C代表平板电脑，D代表投影仪，E代表打印机，F代表照相机，G代表摄像机):\n");
    scanf ("%s",find);//输入查询的设备类型 
		while(p!=NULL){//检索
		p0=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->lx,find   )==0)
	    {
	     printf("\n编号 类型 型号  年    月  日   元    角 分    管理员            状态\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;
         p1=p;
	    }
	    else;
	   }
	   if(u==0&&t==0)
	   {
	   	    printf("没有您要查找的信息！\n");printf("输入数字1返回上层菜单\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("请输入要删除的设备信息的编号\n");
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
void cx_xh(int u)//按设备型号查询 
{
	int choice;
	int t=0;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("请输入您要查询的设备型号:\n");
    scanf ("%s",find);//输入查询的设备型号 
		while(p!=NULL)
		{//检索
		  p0=p;
		  p=p->next;
	     if(p!=NULL&&strcmp(p->xh,find  )==0)
	       {
	        printf("\n编号 类型 型号  年    月  日   元    角 分    管理员            状态\n");
            printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
            t++;
            p1=p;
	       }
	    else;
	    }
	   if(u==0&&t==0)
	   {
	   	    printf("没有您要查找的信息！\n");printf("输入数字1返回上层菜单\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1)
	   {
	      printf("请输入要删除的设备信息的编号\n");
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
void cx_gmrq(int u)//按设备购买日期查询 
{
	int choice;
	int t=0;
	int nf,yf,rq;
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("请输入您要查询的设备购买年份:\n");
    scanf ("%d",&nf);
	printf("请输入您要查询的设备购买月份:\n");
    scanf ("%d",&yf);
    printf("请输入您要查询的设备购买日期:\n");
    scanf ("%d",&rq);//输入查询的设备购买日期 
		while(p!=NULL)
		{//检索
		   p0=p;
		   p=p->next;
	       if(p!=NULL&&p->nian==nf&&p->yue==yf&&p->ri==rq)
	       {
	          printf("\n编号 类型 型号  年    月  日   元    角 分    管理员            状态\n");
              printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
              t++;
              p1=p;
	       }
	    else;
	    }
	   if(u==0&&t==0)
	   {
	   	    printf("没有您要查找的信息！\n");printf("输入数字1返回上层菜单\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("请输入要删除的设备信息的编号\n");
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
void cx_gmjg(int u)//按设备购买价格查询 
{
	int choice;
	int t=0;
	int y,j,f;
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("请输入您要查询的设备购买价格元:\n");
    scanf ("%d",&y);
	printf("请输入您要查询的设备购买价格角:\n");
    scanf ("%d",&j);
    printf("请输入您要查询的设备购买价格分:\n");
    scanf ("%d",&f);//输入查询的设备购买价格 
		while(p!=NULL){//检索
		p0=p;
		p=p->next;
	    if(p!=NULL&&p->n.yuan==y&&p->n.jiao==j&&p->n.fen==f)
	    {
	     printf("\n编号 类型 型号  年    月  日   元    角 分    管理员            状态\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;
         p1=p;
	    }
	    else;
	   }
	   if(u==0&&t==0)
	   {
	   	    printf("没有您要查找的信息！\n");printf("输入数字1返回上层菜单\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("请输入要删除的设备信息的编号\n");
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
void cx_glyxm(int u)//按设备管理员姓名查询 
{
	int choice;
	int t=0;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	p0=NULL;
	p=top;
	printf("请输入您要查询的设备管理员姓名（如wangxiaoming):\n");
    scanf ("%s",find);//输入查询的设备管理员姓名 
		while(p!=NULL){//检索
		p0=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->xm,find)==0)
	    {
	     printf("\n编号 类型 型号  年    月  日   元    角 分    管理员            状态\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;
         p1=p;
	    }
	    else;
	   }
	   if(u==0&&t==0)
	   {
	   	    printf("没有您要查找的信息！\n");printf("输入数字1返回上层菜单\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("请输入要删除的设备信息的编号\n");
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
void cx_zt(int u)//按设备状态查询 
{
	int choice;
	char find[20];
	struct device *p;
	struct device *p0;
	struct device *p1;
	int t=0;
	p0=NULL;
	p=top;
	printf("请输入您要查询的设备编号状态:\n");
    scanf ("%s",find);//输入查询的设备状态 
		while(p!=NULL){//检索
		p0=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->T,find )==0)
	    {
	     printf("\n编号 类型 型号  年    月  日   元    角 分    管理员            状态\n");
         printf("%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
         t++;
         p1=p;
	    }
	    else ;
		}
		if(u==0&&t==0)
	   {
	   	    printf("没有您要查找的信息！\n");printf("输入数字1返回上层菜单\n");
  	        scanf("%d",&choice);
	        if (choice==1)
	        cx();   
	   }
	   else if(u==1&&t!=1){
	   printf("请输入要删除的设备信息的编号\n");
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
	    while(p!=NULL){//检索
		q=p;
		p=p->next;
	    if(p!=NULL&&strcmp(p->bh,qq)==0)
	    {
	    	q->next=p->next;//释放所删的内存
	        r=p;
	        p=p->next;
	        free(r);
	    }
	    else;}	
}
void sc(){
	int choice=1;
	while(choice!=0)//查询方式 
	    {
         printf("输入1代表按设备编号删除\n");
         printf("输入2代表按设备类型删除\n");
         printf("输入3代表按设备型号删除\n");
         printf("输入4代表按设备购买日期删除\n");
         printf("输入5代表按设备购买价格删除\n");
         printf("输入6代表按设备管理员姓名删除\n");
         printf("输入7代表按设备状态删除\n");
         printf("输入0代表退出\n");
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
	  	       printf("输入无效请重新输入\n");cx(); break;
 	         }
 	         printf("删除成功！\n");
 	         break;
	    }
}
void xg(){
	struct device* p;
	p=top;
    printf("请输入要修改的设备信息的编号\n");
	char find[20];
	char z[5];
	scanf ("%s",find);//输入查询的设备编号 
	printf("请输入所要修改的项目的字母，包括 lxd类型 xhd型号 mod购买价格 nian购买年份 yue购买月份 ri购买日期 gly管理员 ztd状态\n");//所要改的选项
	scanf("%s",z);
	while((strcmp(z,"lxd")!=0)&&(strcmp(z,"xhd")!=0)&&(strcmp(z,"mod")!=0)&&(strcmp(z,"nian")!=0)&&(strcmp(z,"yue")!=0)&&(strcmp(z,"ri")!=0)&&(strcmp(z,"gly")!=0)&&(strcmp(z,"ztd")!=0)){
		printf("请重新输入\n");
		 scanf("%s",z);
	}
	while(p!=NULL&&strcmp(p->bh,find)!=0)
		p=p->next;
	if(p==NULL) {
			printf("没有此信息\n"); 
               }
	else{
	if((strcmp(z,"lxd")==0)) {
	printf("设备类型修改为：(A代表笔记本电脑，B代表台式电脑，C代表平板电脑，D代表投影仪，E代表打印机，F代表照相机，G代表摄像机)\n");
	scanf("%4s",p->lx);
	printf("修改成功为：%4s\n",p->lx);
	}//改选项
	else if(strcmp(z,"xhd")==0) {
		printf("修改设备类型为：(eg:fjkla)\n");
	    scanf("%7s",p->xh);
	    printf("修改成功为：%7s\n",p->xh);}
	else if(strcmp(z,"mod")==0) {
		printf("修改花费金额为：(eg:34 7 8)\n");
	    scanf("%d%d%d",&p->n.yuan,&p->n.jiao,&p->n.fen);
	    if(p->n.jiao>59) p->n.jiao=59;
	    if(p->n.fen>59) p->n.fen=59;
	    printf("修改成功为：%d元%d角%d分\n",p->n.yuan,p->n.jiao,p->n.fen);}
	else if(strcmp(z,"nian")==0) { 
        printf("修改年为：\n");
	    scanf("%d",&p->nian);
	    printf("修改成功为：%d\n",p->nian);}
	else if(strcmp(z,"yue")==0) {
	    printf("修改月为(eg:7 8)：\n");
		scanf("%d",&p->yue);
	    printf("修改成功为：%d\n",p->yue);}
	else if(strcmp(z,"ri")==0) {
		printf("修改日为：（eg:2 4）\n");
		scanf("%d",&p->ri);
		printf("修改成功为：%d\n",p->ri);}
	else if(strcmp(z,"gly")==0) {
		printf("修改设备管理员姓名为：(eg:wangxiaoming)\n");
	    scanf("%20s",p->xm);
	    printf("修改成功为：%20s\n",p->xm);}
	else if(strcmp(z,"ztd")==0) {
		printf("修改设备状态为：(Y代表良好，N代表待报废，P代表需维修）\n");
	    scanf("%2s",p->T);
	    printf("修改成功为：%7s\n",p->T);}
}}

void tji()//统计功能 
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
    	k1=k1+p->n.yuan ;}  //统计设备总金额 
		}
	n1=n1+(w-w%10)/10;
	h=w%10;
	g=n1%10;
	f=k1+(n1-n1%10)/10;
	printf("实验室设备总数量是%d",t);	
	printf("实验室设备总价格是%10d元%4d%角%4d分\n",f,g,h);		
}
void bc(){//保存模块
	FILE *fp;
	struct device *p;
	p=top;
	fp=fopen("F:\\sysglxt.txt","w");//打开文件 
	if(fp==NULL){
		printf("打开文件失败\n");
		exit(0);
	}//打开文件失败则退出       
	while(p!= NULL){
			fprintf(fp,"%5s%4s%7s%6d%4d%4d%6d%3d%3d%20s%2s\n",p->bh,p->lx,p->xh,p->nian,p->yue,p->ri,p->n.yuan,p->n.jiao,p->n.fen,p->xm,p->T);
			p=p->next;
		}//将各项信息录入	
	fclose(fp); 
	printf("保存成功！\n");
}
main()//主菜单 
{
 	char R;
 	char U;
 	document();
 	printf("已完成从文件录入信息\n");
 	while(1)
	 {
      	printf("请选择您要做的项目：A添加设备信息  B浏览所有的设备信息 C查询设备信息 \n"); //根据选项进行工作 
        printf("D删除设备信息 E修改设备信息 F代表统计设备总价或数量  \n");
	    printf("G保存设备信息到文件中 H退出本系统 \n");
	   scanf("%c",&R);
	   if (R==10)  scanf("%c",&R);
	    getchar();
	    if (R<'A'||R>'H')//合法输入的容错性 
    	{
	     	printf("输入不合法，请重新输入\n");
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
			printf("是否要保存？保存输入Y，不保存输入N\n");//以防退出丢失数据，退出时询问是否保存 
			scanf("%c",&U);
			if (U=='Y') bc(); 
			break;			
		}

     }
}   
