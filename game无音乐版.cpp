//ע����Ϸ��Ƶĳ��������Թ���������Һ�����������һ���� 
//0�յ�  1�ϰ�  2��  3��  4 ħ�� 5 ���������� -1�յ�
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
struct arr{int x,y;}q[50*100],stack1[50*100],pre[50][100];
struct arr1{int x,y,z;}a[50*100];
int f[50][100],dist[50][100],flag[50][100],fff[50][100],flag1[50][100],ff[50][100],hp[50][100],jineng[50][100];
int dx[4]={-1,0,0,1};int dy[4]={0,-1,1,0};
int nowx,nowy,yes,zhongx,zhongy,dist1,top,guais,ts,zjhp,jy,wangmusic,shenmusic,starttime,endtime,yuce,mltime,mls,killlong;
int js,cd,N,M,nandu,yourbs,zuobi,guaiiq,jngx,lengque,kill,qp,gongji,level,manhp,sg,huixue,wang,killwang,wangtime,ls,noguai;
char ch;
double bs,dtime;
int sortcmp(arr1 a,arr1 b){return a.z>b.z;}    //�������򰴴Ӵ�С
int sortcmp2(arr1 a,arr1 b){return a.z<b.z;}	//���������С���� 
void draw(int x,int y);
void addguai();
void mljn(int longx,int longy);
void addlong();
void addwang();
void setpos(int x,int y){          //ȡ��꣬�ѹ���ƶ���x,y��λ�� 
    COORD pos={y,x};
    HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out,pos);
}
void color(int x){				//ȡ��ɫ
	HANDLE y=GetStdHandle((STD_OUTPUT_HANDLE));//�趨��Ӧ��ɫ 
	SetConsoleTextAttribute(y,x);
}
void dfs(int x,int y){             //���ҳ�һ�������ұߵ�·������������Ȧ�У���Ҫ�޶�����
	int i,sum,xx,yy,temp,cz[5];
	js++;
	if(js>10000)return;            //��������ֱ���˳����������һ��·
	if(f[x][y]==0)return;          // ����û���ϰ��ĵ�
	sum=f[x-1][y]+f[x][y-1]+f[x][y+1]+f[x+1][y];  //Ҫ������Щ���ᷢ����ͨ����ĵ�
	if(sum<=2)return;
	if((y==M-1)&&(x==N-1)){f[x][y]=0;yes=1;return;}         //����Ѿ��ѵ������½ǣ��ɹ�
	if(x==1||x==N||y==1||y==M)return;            //����ѵ��߽磬�˳�
	f[x][y]=0;                                   //������ģ��ȥ��
	for(i=0;i<4;i++)cz[i]=i;						//ͨ���������ö��˳�� 
	for(i=1;i<=10;i++){								//��������˳��
		xx=rand()%4;yy=rand()%4;
		temp=cz[xx];cz[xx]=cz[yy];cz[yy]=temp;
	}                                             
	for(i=0;i<4;i++){							//��· 
		if(cz[i]==0)dfs(x-1,y);					//�ĸ��������� 
		if(cz[i]==1)dfs(x,y-1);
		if(cz[i]==2)dfs(x,y+1);
		if(cz[i]==3)dfs(x+1,y);
		if(yes==1)return;                         //����Ѿ��ҵ����˳�
	}                                             //ģ��
	f[x][y]=1;                                    //���ݷ���
	if(js>10000)return;                           //��������ֱ���˳����������һ��·
}
void dfs2(int x,int y,int bs){                     //��ԭ�е�ͼ�����������һ��·��������
	int sum,cz1,i,xx,yy,temp,cz[5];
	js++;
	if(js>10000)return;                           //ͬ��Ҫ�޶�����
	if(f[x][y]==0)return;                         //����û���ϰ��ĵ�
	if(x==1||x==N||y==1||y==M)return;             //�߽�
	sum=f[x-1][y]+f[x][y-1]+f[x][y+1]+f[x+1][y];  //������Щ���ᷢ����ͨ����ĵ�
	if(sum<=2)return;
	f[x][y]=0;
	if(bs>=cd){yes=1;return;}                     //�޶���������
	for(i=0;i<3;i++)cz[i]=i;
	for(i=1;i<=10;i++){                            //��������˳��
		xx=rand()%4;yy=rand()%4;
		temp=cz[xx];cz[xx]=cz[yy];cz[yy]=temp;
	}
	for(i=0;i<4;i++){                               //��������˳��ö���ĸ�����
		cz1=cz[i];
		if(cz1==0)dfs2(x-1,y,bs+1);
		if(cz1==1)dfs2(x,y-1,bs+1);
		if(cz1==2)dfs2(x,y+1,bs+1);
		if(cz1==3)dfs2(x+1,y,bs+1);
		if(yes==1)return;                         //����Ѿ��ҵ�����
	}                                             //ģ��
	f[x][y]=1;                                    //���ݷ���
	if(js>10000)return;
}
void dfs3(int x,int y){                            //�������ʣ��ռ�                                                 //�˺����пռ����������Ҫ�û��ݣ���Ҫ����������Թ�
	int sum,xx,yy,temp,cz1,i,cz[5];
	if(f[x][y]==0)return;
	if(x==1||x==N||y==1||y==M)return;
	sum=f[x-1][y]+f[x][y-1]+f[x][y+1]+f[x+1][y];
	if(sum<=2)return;
	f[x][y]=0;
	for(i=0;i<3;i++)cz[i]=i;                     //�������˳��
	for(i=1;i<=10;i++){
		xx=rand()%4;yy=rand()%4;
		temp=cz[xx];cz[xx]=cz[yy];cz[yy]=temp;
	}
	for(i=0;i<4;i++){                            //ö������������˳��
		cz1=cz[i];
		if(cz1==0)dfs3(x-1,y);
		if(cz1==1)dfs3(x,y-1);
		if(cz1==2)dfs3(x,y+1);
		if(cz1==3)dfs3(x+1,y);
	}
}
void spfa(int qix,int qiy,int zhongx,int zhongy){                   //������֮������·
	int mo,l,r,x,y,xx,yy,i,j;
	mo=N*M;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)dist[i][j]=100000;
	dist[qix][qiy]=0;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)flag[i][j]=0;
	flag[qix][qiy]=1;
	l=0;r=1;q[0].x=qix;q[0].y=qiy;                              //��ѭ������
	while(l!=r){
		x=q[l].x;y=q[l].y;l=(l+1)%mo;flag[x][y]=0;
		for(i=0;i<4;i++){
			xx=x+dx[i];yy=y+dy[i];
			if(f[xx][yy]==0||f[xx][yy]==-1){
				if(dist[x][y]+1>=dist[zhongx][zhongy])continue; //����������������̾��룬�����ǰ�����ĵ�ľ����Ѿ�����
				if(dist[x][y]+1<dist[xx][yy]){                  //��Ŀ�����̾��룬�Ժ��û��Ҫȥ�������ˣ��Ǹ��Ż���spfa
					dist[xx][yy]=dist[x][y]+1;
					if(flag[xx][yy]==0)flag[xx][yy]=1,q[r].x=xx,q[r].y=yy,r=(r+1)%mo;
				}
			}
		}
	}
}
void spfa2(int qix,int qiy,int zhongx,int zhongy){                  //������֮������·����������·��
	int mo,l,r,x,y,xx,yy,i,j,xxx,yyy;
	arr temp;
	mo=N*M;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)dist[i][j]=100000;
	dist[qix][qiy]=0;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)flag[i][j]=0;
	flag[qix][qiy]=1;
	l=0;r=1;q[0].x=qix;q[0].y=qiy;                                 //��ѭ������
	while(l!=r){
		x=q[l].x;y=q[l].y;l=(l+1)%mo;flag[x][y]=0;
		for(i=0;i<4;i++){
			xx=x+dx[i];yy=y+dy[i];
			if(f[xx][yy]==0||f[xx][yy]==-1){                         //�ǿյػ��յ�
				if(dist[x][y]+1>=dist[zhongx][zhongy])continue;     //����������������̾��룬�����ǰ�����ĵ�ľ����Ѿ�����
				if(dist[x][y]+1<dist[xx][yy]){                 //��Ŀ�����̾��룬�Ժ��û��Ҫȥ�������ˣ��Ż�spfa
					dist[xx][yy]=dist[x][y]+1;
					pre[xx][yy].x=x;pre[xx][yy].y=y;                            //����·��
					if(flag[xx][yy]==0)flag[xx][yy]=1,q[r].x=xx,q[r].y=yy,r=(r+1)%mo;
				}
			}
		}
	}
	xxx=zhongx;yyy=zhongy;                                                       //����������յ��·����Ϊ���ó���ʵ���Զ���
	for(;;){
		top++;stack1[top].x=xxx;stack1[top].y=yyy;                                //�ø�stack1���鱣�浹�˵�·��
		xx=pre[xxx][yyy].x;yy=pre[xxx][yyy].y;
		xxx=xx;yyy=yy;
		if(xxx==qix&&yyy==qiy)break;
	}
	for(i=1;i<=top/2;i++)temp=stack1[i],stack1[i]=stack1[top-i+1],stack1[top-i+1]=temp;  //�ѵ��˵�·�����˳���·��
}
void spfa3(int qix,int qiy,int pd){       //��ǰ�㵽�������е�����·,pd�������ж�����ͨħ�����Ǹ߼�ħ�� 
	int mo,l,r,x,y,xx,yy,i,j;
	mo=N*M;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)dist[i][j]=100000;
	dist[qix][qiy]=0;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)flag[i][j]=0;
	flag[qix][qiy]=1;
	l=0;r=1;q[0].x=qix;q[0].y=qiy;                              //��ѭ������
	while(l!=r){
		x=q[l].x;y=q[l].y;l=(l+1)%mo;flag[x][y]=0;
		for(i=0;i<4;i++){
			xx=x+dx[i];yy=y+dy[i];
			if((xx<=1)||(xx>=N)||(yy<=1)||(yy>=M))continue; 						//�����Գ����߽� 
			if((f[xx][yy]==0)||(f[xx][yy]==3)||(f[xx][yy]==4)||(f[xx][yy]==5)||((f[xx][yy]==1)&&(pd==5))){ //����Ǹ߼������������ϰ� 
				if(dist[x][y]+1<dist[xx][yy]){
					dist[xx][yy]=dist[x][y]+1;
					if(flag[xx][yy]==0)flag[xx][yy]=1,q[r].x=xx,q[r].y=yy,r=(r+1)%mo;
				}
			}
		}
	}
}
void gouzao(){                    //����һ�����Թ��ĺ���
	int i,j,xx,yy,sum,xxx,yyy,xxxx,yyyy,js2;
	yes=0;
 	for(i=1;i<=N;i++)for(j=1;j<=M;j++)f[i][j]=1;    //�Ȱ�ͼ���ȫ�ϰ�
	for(;;){                                        //�������·����ֱ�������һ������ͼ�����½ǵ�·
	    js=0;
        dfs(2,2);									//��������ֱ���ҵ�һ���ܴ�(2,2)��(N-1,M-1)��· 
        if(yes)break;
	}
	for(i=1;i<=N*M;i++){                            //�����һЩ�µ���·�����������Թ����Ѷ�
		xx=rand()%(N-2)+2;							//��·�Ǵ��ϰ���ʼ�����ȥ�� 
		yy=rand()%(M-2)+2;
		if(f[xx][yy]==1){
			sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];//ȷ�������Ժ󲻻���ͨ�Թ�������·����ʹ���Ѷȱ�� 
			if(sum==3){
				yes=0;js=0;cd=(N+M)/6+rand()%20;       //�����·��Ҫ�ĳ���
				dfs2(xx,yy,1);						//��dfs������һ���Ƚϳ�������ͬ 
			}
		}
	}
	for(i=2;i<=N-1;i++)                                 //��˳���ѳ�����������·
		for(j=2;j<=M-1;j++){							//�����һ��dfs2���������ģ�������һ����� 												//���죬�ӵ�ͼ���ϵ����£������ĺô�����Ϊ��Ҵ����ϳ����� 
			xx=i;yy=j;									//�������Ծ����ܴ��������Թ��Ѷ� 
			if(f[xx][yy]==1){
				sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];
				if(sum==3){
					yes=0;js=0;cd=rand()%10;
					dfs2(xx,yy,1);
				}
			}
		}
	for(i=1;i<=N*M;i++){                             //������ʣ��ռ䣬��ʣ�µĿռ���������һ��  			
		xx=rand()%(N-2)+2;
		yy=rand()%(M-2)+2;
		if(f[xx][yy]==1){
			sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];
			if(sum==3)dfs3(xx,yy);
		}
	}
	for(i=2;i<=N-1;i++)                                  //��˳�����ʣ��ռ䣬ͼ������
		for(j=2;j<=M-1;j++){							//��ʣ�µĿռ���ȫ���һ�飬ʹ�������Թ��Ƚ��� 
			xx=i;
			yy=j;
			if(f[xx][yy]==1){
				sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];
				if(sum==3)dfs3(xx,yy);
			}
		}
	setpos(N+1,0);                                        //��spfa�㷨�ҳ�����㵽�յ�����·
	spfa(2,2,N-1,M-1);dist1=dist[N-1][M-1];
	memset(fff,0,sizeof(fff));
	for(;;){
	    js2=0;
		for(i=2;i<=N-1;i++)                                    //��ǰ����ͼ��������ͼ��Ҫ���뻷�����
			for(j=2;j<=M-1;j++){                                //ö����ȥ�����ϰ�
				xx=i;
				yy=j;
				if((f[xx][yy]==1)&&(fff[xx][yy]==0)){
					sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];
					if(sum==2){
						f[xx][yy]=0;
						spfa(2,2,N-1,M-1);                   //����Ҫ��֤ȥ��������飬Ҫʹͼ�����·���Ȳ��䣬��Ȼ���ֽݾ��ѶȾͷǳ����� 
						f[xx][yy]=1;                         //��ԭ����
						if(dist[N-1][M-1]==dist1){           //Ȼ�����������ͨ�������ո���֮ǰ�����·
							if(f[xx-1][yy]==0)xxx=xx-1,yyy=yy;
								else if(f[xx][yy-1]==0)xxx=xx,yyy=yy-1;				//�����ͨ�������������
									else if(f[xx][yy+1]==0)xxx=xx,yyy=yy+1;
										else xxx=xx+1,yyy=yy;	
							if((f[xx][yy-1]==0)&&((xx!=xxx)||(yy-1!=yyy)))xxxx=xx,yyyy=yy-1;
								else if((f[xx][yy+1]==0)&&((xx!=xxx)||(yy+1!=yyy)))xxxx=xx,yyyy=yy+1;
									else xxxx=xx+1,yyyy=yy;
							spfa(xxx,yyy,xxxx,yyyy);         //�㷨����spfa
							if(dist[xxxx][yyyy]>30)js2++,a[js2].x=xx,a[js2].y=yy,a[js2].z=dist[xxxx][yyyy];//ֻ��Ҫ�����㹻��������
								else fff[xx][yy]=1;                     //Ϊ�˳�����ٶȣ���Щ����֮����̾��뱾��ͺܽ�
						}                                               //������ȥ���Ժ���̾���һ������䳤��������ø�
						else fff[xx][yy]=1;                             //fff������¼�´�������ֱ����������ΪС���Ǹ����Բ����� 
					}
				}
			}
		if(js2==0)break;                                                         //����ѭ����ֱ���Ҳ��������ĵ�
		sort(a+1,a+js2+1,sortcmp);                                             //�����������ĵ�������������������������
		xx=a[1].x;yy=a[1].y;f[xx][yy]=0;                                       //������̾����ĵ�
	}
}
void begin(){
	int i,j,xx,yy;
	wangmusic=0;												//������һ�γ��������������� 
	shenmusic=0;												//�����ĳ������ֱ�ǿ��� 
	ls=2;														//���������ƣ�ÿ�μ�1�����������������������֮��ˢ���� 
	yourbs=0;guais=0;js=0;										//������ҵĲ���   �ֵ�����    ����·ˢ��
	guaiiq=5; 													//�ֵ�Ĭ������
	mltime=0;                                                   //ħ��ˢ��
	mls=0;                                                      //ħ������
	killlong=0;                                                 //���������
	zuobi=0;									              //Ĭ�ϲ�����
	qp=0;														//�������ܴ���
	lengque=1;												//������ȴ
	sg=0;                                                   //ˢ��
	kill=0;													//ɱʷ��ķͳ��
	zjhp=100;                                               //��ǰhp
	manhp=100;                                          //hp����
	level=1;                                                   //��ǰ�ȼ�
	gongji=30;                                          //��ǰ����
	jy=0;                                               //��ǰ����
	huixue=0;											//��hp��ʱ
	wang=0;                                             //�Ƿ��������
	killwang=0;											//ɱ������ 
	wangtime=0;											//����ʱ�� 
	memset(hp,0,sizeof(hp));							//���������ͼ�����йֵ�Ѫ 
	starttime=clock();                                 //��Ϸ��ʼʱ��
	system("cls");                                                         //��ʼ����
	setpos(10,40);
	printf("����Ѷȼ������Ҽ��߿����Բ����н���������Ļ��С�ʹ��ڿ�ȵ���170");		//��ʾ 
	setpos(12,40);
	//printf("������Ϊwohenlihai");								//�㶮�� 
	setpos(15,40);
	printf("��ϷĿ��Ϊ�����½��ҵ�����");					//��ѩ�������㶮�� 
	setpos(18,40);
	printf("��������:�� w  �� s  �� a  �� d");					//������ö�˵�� 
	setpos(20,40);
	printf("�������Ѷ�0-9(��סshiftѡ0-9Ϊ�޹�ģʽ)");							//���ö�˵+1 
	noguai=0;
	//mciSendString("close mymusic", NULL, 0, NULL);								//�ر�֮ǰ������ 
	//mciSendString("open music\\��֮������.mp3 alias mymusic", NULL, 0, NULL);	// ��������
	//mciSendString("setaudio mymusic volume to 600",NULL,0,NULL);		//����������С
	//mciSendString("play mymusic repeat", NULL, 0, NULL);				//ѭ������
	for(;;){
		ch=getch();                                          //�����Ѷ�
		if(ch==')')ch='0',noguai=1;							//���������ֲ�ͬ���� 
		if(ch=='!')ch='1',noguai=1;							//���������йֵ����ƣ���סshift������ľͱ�� 
		if(ch=='@')ch='2',noguai=1;							//����Ӧ�����ַ� 
		if(ch=='#')ch='3',noguai=1;							//��noguai��Ϊ�����ȷ����ǰ���� 
		if(ch=='$')ch='4',noguai=1;
		if(ch=='%')ch='5',noguai=1;
		if(ch=='^')ch='6',noguai=1;
		if(ch=='&')ch='7',noguai=1;
		if(ch=='*')ch='8',noguai=1;
		if(ch=='(')ch='9',noguai=1;
		nandu=ch-'0';										//ͨ���ַ�ASCII�ļ�������Ӧ���㵱ǰ�Ѷ� 
		if(ch>='0'&&ch<='9'){
			N=(int)((double)(ch-'0'+1)*3.8);                            //�����Ѷȹ����Թ�����Ӧ��С
			M=(ch-'0'+1)*8;
			break;
		}
	}
	gouzao();                                                              //��f���鹹���Թ�
	system("cls");                                                         //����
	setpos(0,0);														//��굽�����Ͻ� 
	color(8);														//���ɻ�ɫ 
	for(i=1;i<=N;i++){                                                     //����Թ�
		for(j=1;j<=M;j++)
		if(f[i][j]==1)printf("��");                                        //1��ʾ��ǰ�����ϰ��飬���԰ч廻���������� 
		else if(f[i][j]==0)printf("  ");                                //0��ʾ��ǰ���ǿյ�
		putchar('\n');
	}
	color(7);setpos(N+2,0);printf("�ȼ� %d Ѫ %d/100 �� %d",level,zjhp,gongji);	//���������ڵ���� 
	color(7);setpos(N,4);printf("����һ�� n  �Զ��� p  �ӹ� g  ��߹������� t  ���͹������� y  ���� j  ���������� ~");
	nowx=2;nowy=2;                                    				//��㣬Ҳ���ǿ�ʼλ�� 
	zhongx=N-1;zhongy=M-1;                                      //�յ㣬Ҳ����Ŀ��λ�� 
	f[zhongx][zhongy]=-1;										//�����е�-1��ʾ�յ� 
	setpos(zhongx-1,(zhongy-1)*2);color(6);printf("��");color(7);
	draw(nowx,nowy);
	for(i=1;i<=(ch-'0');i++)addguai();									//������Ϸ�Ѷ�����һ��������ʷ��ķ
	if((ch-'0')>5)addlong();											//�Ѷ�6Ϊ����һ��ħ�� 
	if((ch-'0')>6)addlong();											//�Ѷ�7Ϊ����һ��ħ�� 
	if((ch-'0')>7)addlong();											//�Ѷ�8Ϊ����һ��ħ�� 
	if((ch-'0')>8)addlong();											//�Ѷ�9Ϊ����һ��ħ��  
}
void draw(int x,int y){                                                 //�������ڵ������ 
	f[x][y]=2;x=x-1;y=(y-1)*2;		
	setpos(x,y);color(6);printf("��");color(7);								//����Ϊ���ɫ 
}
void redraw(int x,int y){f[x][y]=0;x=x-1;y=(y-1)*2;setpos(x,y);printf("  ");}    //����ԭ�е�
void drawguai(int x,int y){									//��ӹ���
	f[x][y]=3;
	x=x-1;y=(y-1)*2;
	setpos(x,y);color(2);printf("��");color(7);					//��ɫ��ʺ��ķ 
}
void reguai(int x,int y){										//���������ɿո� 
	f[x][y]=0;
	x=x-1;y=(y-1)*2;
	setpos(x,y);printf("  ");
}
void drawlong(int x,int y){										//����
    f[x][y]=4;												//f������4Ϊ��ͨ�� 
    x=x-1;y=(y-1)*2;
    setpos(x,y);color(12);printf("��");color(7);			//��ɫcolor(12)Ϊ��ɫ,color(7)Ϊ�л���Ĭ�ϻ�ɫ 
}
void drawwang(int x,int y){										//���߼�����λ�� 
    f[x][y]=5;													//5Ϊ�߼��� 
    x=x-1;y=(y-1)*2;
    setpos(x,y);color(5);
	if(killwang==0)printf("��");								//��һ��Ϊ���� 
	else if(killwang>=1)printf("��");							//���ܹ����������������ʵ��ôд��Ҫ�ǱȽ�͵�� 
	color(7);
}
void relong(int x,int y){f[x][y]=0;x=x-1;y=(y-1)*2;setpos(x,y);printf("  ");}		//������
void rewang(int x,int y){f[x][y]=0;x=x-1;y=(y-1)*2;setpos(x,y);printf("  ");}		//�����߼��������������������� 
int judge(int x,int y){return(f[x][y]==0||f[x][y]==-1);}//�ж��ǿյػ��յ�	
void run();
void printprincess(){											//����������� 
	char ch=92;
	system("cls");
	setpos(10,0);printf("                                                �ɹ��ҵ�����");
	setpos(12,0);
	printf("                                                       .   |   . \n");
	printf("                                                        %c  :  / \n",ch);
	printf("                                                     -= <*****> =- \n");
	printf("                                                        //^^^%c%c \n",ch,ch);
	printf("                                                     . (( '_' )) \n");
	printf("                                                      %c ))-_-(( \n",ch);
	printf("                                                  -= <*^*^*>`%c)) \n",ch);
	printf("                                                     /( ^ )   , %c \n",ch);
	printf("                                                     %c)`^`()  / / \n",ch);
	printf("                                                      (___)==(%c/ \n",ch);
	for(int i=1;i<=6;i++)printf("                                                        |     | \n");
	printf("\n\n\n");
	Sleep(2000);
}
void win(){                                                              //���ʤ����Ľ���
	endtime=clock();                                                   //��ǰʱ��
	dtime=(double)(endtime-starttime)/CLOCKS_PER_SEC;                  //�������ʱ��֮���ʱ���
	printprincess();
	system("cls");														//����
	setpos(13,60);printf("�Թ����ٲ�����%d",dist1);						//ֱ�ӿ����� 
	setpos(14,60);printf("��Ĳ���:%d",yourbs);							//ֱ�ӿ����� 
	setpos(15,60);printf("����ʱ:%.3lf s",dtime);						//ֱ�ӿ����� 
	setpos(16,60);printf("����Ѷ��ǣ�%d",nandu);						//ֱ�ӿ����� 
	setpos(17,60);printf("�����ʷ��ķ������%d �����ħ��������%d",guais,mls);
	yuce=dist1/4;                                                  //Ԥ��ʱ��Ϊ�ܲ�����Ԥ��ÿ���ߵĲ���
	bs=dtime/yuce;                                                 //������ҵ�ʱ�������ҵĵȼ�
	setpos(18,60);printf("��ļ�����");				//ֱ�ӿ����֣�����ĵȼ��ǰ��Ӹߵ������һ���ˣ��������ģ�����ǫ���� 
	if(bs<=1)printf("You are superman!");			//��ǰ��ʱ/Ԥ����ʱ�������ԣ����ֵԽС��˵����Խ����					
	else if(bs<=2)printf("�������");				//����Խ��˵������ߵ�Խ�� 
	else if(bs<=3)printf("��ܰ�");
	else if(bs<=4)printf("You are good");
	else if(bs<=5)printf("����ս���߼���");
	else if(bs<=6)printf("����¸�");
	else if(bs<=7)printf("����ֹ�");
	else if(bs<=8)printf("��ܼ�ǿ");
	else if(bs<=9)printf("����Ŭ��������");
	else printf("Ү");
	setpos(19,60);printf("������%dֻʷ��ķ",kill);						//ֱ�ӿ����� 
	setpos(20,60);printf("������%dֻħ��",killlong);					//ֱ�ӿ����� 
    if(guais==0)setpos(21,60),printf("��������ʷ��ķ����óƺ� prince");//ֱ�ӿ����� 
	if(killlong>=2)setpos(22,60),printf("���ܶ�ֻħ������óƺ� KING");				//ֱ�ӿ����� 
    if(zuobi==1)setpos(23,60),printf("���ӱ��飬��óƺ� �۲���");					//ֱ�ӿ����� 
    if(qp==1)setpos(24,60),printf("ʱ֮��������óƺ� ������");					//ֱ�ӿ����� 
	if(killwang>=1)setpos(25,60),printf("������������óƺ� warrior");				//ֱ�ӿ����� 
	if(killwang>=2)setpos(26,60),printf("������������óƺ� The Incredible Hulk");	//ֱ�ӿ����� 
	setpos(30,50);printf("����һ�� n ");						//ֱ�ӿ����� 
	for(;;)                                                  //����ѭ����ֱ����Ҽ����ж���
		if(kbhit()){										//ֱ������������ 
			char ch=getch();
		 	if(ch=='n'||ch=='N'){begin();return;}                          //����nΪ����һ��
		}
}
void AI(){							//�����Զ��������ܣ��������ԭ���ǲⴿ�Թ�ʱ�õģ����Ǻ���Խ��Խ�࣬��������Ϸ�Ѿ��� 									//�Թ�ûʲô��ϵ�ˣ������������Ҳ�����ţ����йֵ���������ڻ���ֶ�·�����������ܾͷ����� 
	int i,limit,js;					//Ҫ�����Ļ������������뿪�����ӱ���������������Ȼ���ٰ�p�������Զ���· 
	if(guais>0||mls>0||wang>0){						//���йֵ�������Զ���û�� 
		setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");//�����һ�� 
		setpos(N+1,0);ts=0;printf("��Ϊ�й���Ĵ��ڣ���ʱ�޷��Զ��ߣ�����ʹ�����ӱ�����");
		return;
	}
	top=0;
	spfa2(nowx,nowy,zhongx,zhongy); //��spfa�����ǰ�㵽�յ�����·
	setpos(N,0);for(i=1;i<=160;i++)printf(" ");
    setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");                                       //ͬʱ��¼·��
	setpos(N,M/2);printf("��ͣ b   ���� u  ���� i");     //���±�Ϊ������ʾ���ɵ����Զ��ߵ��ٶ� 
	limit=8;                                                            //���ٱ���
	for(i=1;i<=top;i++){//�ö��д�����ÿһ����topΪ������������������spfa2��������· 
		js=0;
		for(;;){
			if(kbhit()){					//������������Ļ� 
				ch=getch();
				if(ch=='b'||ch=='B')break;                         //�����ߵ�һ���ʱ����ͣ��Ȼ���ֿ�������� 
				if(ch=='u'||ch=='U'){limit/=2;if(limit==0)limit=1;}     //����
				if(ch=='i'||ch=='I'){limit*=2;if(limit>32768)limit=32768;}        //����
			}
			Sleep(16);                                            //������ͣ�Ĵ������������ٶ�
			js++;
			if(js>=limit)break;
		}
		if(ch=='b'||ch=='B'){
			setpos(N,0);for(i=1;i<=160;i++)printf(" ");
			setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
			setpos(N,M/2);printf("����һ�� n  �Զ����� p  �ӹ� g  ��߹������� t  ���͹������� y  ���� j  ���������� ~");
			setpos(nowx-1,nowy*2);
			break;
		}
		redraw(nowx,nowy);                      //�Զ���
		nowx=stack1[i].x;nowy=stack1[i].y;
		draw(nowx,nowy);yourbs++;
		if(nowx==zhongx&&nowy==zhongy)win();           //������յ����ʤ��
	}
}
void addguai(){							//�����������ӹ���
    int js=0,x,y,i;
	if(noguai==1)return;
    for(;;){
        js++;
        x=rand()%(N-2)+2;y=rand()%(M-2)+2;       //���
        if((f[x][y]==0)&&(abs(nowx-x)+abs(nowy-y)>15))break;     //����ǿյز��Ҿ����Զ������
        if(js>100){
			setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");          //�����ζ��޷������������û�������
            setpos(N+1,0);ts=0;printf("�޷�����Ч���������ʷ��ķ");
            return;
        }
    }
    guais++;drawguai(x,y); 									//�������λ�õĹ�
	hp[x][y]=rand()%80+20;									//������ֵ�Ѫ
}
void addwang(){									//���Ӹ߼��� ������ͬaddlong 
    int js=0,x,y,i;
	if(noguai==1)return;
    for(;;){
        js++;
        x=rand()%(N-2)+2;y=rand()%(M-2)+2;
        if((f[x][y]==0)&&(abs(nowx-x)+abs(nowy-y)>15))break;			//�����ǿյأ�Ȼ���������ұ���һ�����룬��Ȼ����̫������ 
        if(js>100){													//ö����100�λ���û���ҵ����ʵĿ�λ
            setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
            setpos(N+1,0);ts=0;
			if(killwang==0)printf("�޷�����Ч�������������");		//��ȷ������Ч��Χ�ڿ��Լӣ����ܳ������� 
			else if(killwang>=1)printf("�����޷�����"); 			//���ܳ�������		
            return;
        }
    }
    wang++;drawwang(x,y);											//����һ������������ 
    if(killwang==0)hp[x][y]=1000+rand()%1000;						//����Ѫ 
    else if(killwang>=1)hp[x][y]=gongji*30+rand()%1000;					//����Ѫ��������ʵ���������level������Ҳ 
    setpos(N+1,0);for(i=1;i<=160;i++)printf(" "); 						//��������ǿ����������Ѫ�ȽϺ� 
    setpos(N+1,0);ts=0;
	if(killwang==0){
		printf("��λ���ħ�����������֣�������������Ⱥ"),Sleep(1500); 		//���������ֻ���ӳ���ͨħ���Ļ���	
		if(wangmusic==0){
    		wangmusic=1;
			//mciSendString("close mymusic", NULL, 0, NULL);							//�ر�֮ǰ������ 
			//mciSendString("open music\\����-��.mp3 alias mymusic", NULL, 0, NULL);	// �����֣������������֣� 
			//mciSendString("play mymusic repeat", NULL, 0, NULL);				//ѭ������
		}
	} 
	else if(killwang>=1){
		if(shenmusic<=2){
    		shenmusic++;
			//mciSendString("close mymusic", NULL, 0, NULL);							//�ر�֮ǰ������ 
			//mciSendString("open music\\����-��.mp3 alias mymusic", NULL, 0, NULL);	// �����֣�����������֣� 
			//mciSendString("play mymusic repeat", NULL, 0, NULL);				//ѭ������
		}
		else if(shenmusic<=6){
			shenmusic++;
			//mciSendString("close mymusic", NULL, 0, NULL);								//�ر�֮ǰ������ 
			//mciSendString("open music\\����-����̳.mp3 alias mymusic", NULL, 0, NULL);	// �����֣������ǿ�ˣ� 
			//mciSendString("play mymusic repeat", NULL, 0, NULL);				//ѭ������
		}
		else if(shenmusic<=10){
			shenmusic=16;
			//mciSendString("close mymusic", NULL, 0, NULL);							//�ر�֮ǰ������ 
			//mciSendString("open music\\battle.mp3 alias mymusic", NULL, 0, NULL);	// �����֣��ǳ�ǿ�ĵ��˳������֣�
			//mciSendString("play mymusic repeat", NULL, 0, NULL);				//ѭ�����ţ���������������� 
    	}
		printf("�������٣�������������Ⱥ"),Sleep(1500/(level/10+1)); 				////���������ֻ���ӳ����Ļ���
	}
}
void addlong(){											//��ħ��,ͬaddwang 
    int js=0,x,y,i;
	if(noguai==1)return;
    for(;;){
        js++;
        x=rand()%(N-2)+2;y=rand()%(M-2)+2;
        if((f[x][y]==0)&&(abs(nowx-x)+abs(nowy-y)>15))break;		//�ڵ�ǰ��ҽ�Զ��λ������ħ�� 
        if(js>100){													//����������100�����ϻ�û���ҵ��Ϸ�λ�� 
            setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");				//�ͱ�ʾ��ͼ����ӵ����û��λ���� 
            setpos(N+1,0);ts=0;printf("�޷�����Ч���������ħ��");		//ȷ�������� 
            return;
        }
    }
    mls++;drawlong(x,y);
    setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
    setpos(N+1,0);color(12);printf("��ͼ�ϵ���һֻħ��");color(7);				//��������ɫΪ��ɫ 
    hp[x][y]=600+rand()%100;								//��ͨħ��Ѫ��Ϊ600-699��������ʵ��ʷ��ķ����� 
}
void loss(){												//���ִ�HPΪ0 
	Sleep(3000);
	system("cls");									//���� 
	setpos(10,0);
	printf("    L         OOOOOO     SSSSS      EEEEE   \n");					//������ý����� 
	printf("    L         O    O     S          E       \n");
	printf("    L         O    O     SSSSS      EEEEE   \n");
	printf("    L         O    O         S      E       \n");
	printf("    LLLLLL    OOOOOO     SSSSS      EEEEE   \n");
	setpos(20,20);printf("You are a loser");					//����ͼ�ε�ע�� 
	setpos(21,20);printf("����һ�� n ");					//��Ϸ��������ʾ 
	for(;;)                                               //����ѭ����ֱ����Ҽ����ж���
		if(kbhit()){
			char ch=getch();
		 	if(ch=='n'||ch=='N'){begin();return;}                     //nΪ����һ��
		}
}
void shua(){											//����ˢ��ʷ��ķ����·
	int i,j,w,k,xx,yy,sj,z;
	arr1 a[5],temp;
	memset(flag1,0,sizeof(flag1));						//Ϊ�˱����ظ���ͬһֻ�����������ж�
	spfa3(nowx,nowy,3);									//������е㵽��ҵ��������
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
		if((f[i][j]==3)&&(flag1[i][j]==0)){					//��ʷ��ķ����û�б�ö�ٵ�
			w=0;
			for(k=0;k<4;k++){								//�ĸ�����ѡ�����ߵ�
				xx=i+dx[k];yy=j+dy[k];
				if((f[xx][yy]==0)||(f[xx][yy]==2))w++,a[w].x=xx,a[w].y=yy,a[w].z=dist[xx][yy];
			}
			if(w){												//����������ߵ�·
				sort(a+1,a+w+1,sortcmp2);					//�������������
				xx=a[1].x;yy=a[1].y;
				if(w>1){                                   //���ݹֵ�������ѡ�������ѡ·����һ��
					sj=rand()%10+1;                          //���1-10�е�һ����
					if(sj<=guaiiq)xx=a[1].x,yy=a[1].y;        //�����������ȵ�ǰ���̸߾�ѡ���·
					if(sj>guaiiq)xx=a[2].x,yy=a[2].y;			//����ѡ��ζ�·
				}
				if((xx==nowx)&&(yy==nowy)){						//�������ĵ�����ҵ�λ�ã�������˺� 
				    z=rand()%20+1;zjhp-=z;xx=i;yy=j;if(zjhp<0)zjhp=0;//�˺�Ϊ1��20���ٵÿ��� 
				    setpos(N+1,0);for(k=1;k<=160;k++)printf(" ");
				    setpos(N+1,0);printf("ʷ��ķ�������%d���˺�",z);ts=0;//˵���������ɵ��˺� 
				    setpos(N+2,0);for(k=1;k<=160;k++)printf(" ");
                    setpos(N+2,0);printf("�ȼ� %d Ѫ %d/%d �� %d",level,zjhp,manhp,gongji);//��ҵ�ǰ����� 
				    if(zjhp<=0){loss();return;}
				    continue;							//����ܵ��˺��ˣ��Ͳ����ƶ�ʷ��ķλ���ˣ�ֱ��continue 
                }
                reguai(i,j);drawguai(xx,yy);				//���¹�������λ�� 
				hp[xx][yy]=hp[i][j];hp[i][j]=0;
				flag1[xx][yy]=1;					//ѡΪ�Ѿ��߹�
			}
		}
}
void shua3(){										//����ˢ��������· 
    int i,j,w,k,xx,yy,sj,z;
    arr1 a[5];
    memset(flag1,0,sizeof(flag1));
    spfa3(nowx,nowy,4);								//���������ҵ����·������ͬʷ��ķ 
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
        if((f[i][j]==4)&&(flag1[i][j]==0)){
            w=0;
            if((rand()%10)==0){mljn(i,j);continue;}				//ʮ��֮һ�������� 
            for(k=0;k<4;k++){									//ö���ĸ����� 
                xx=i+dx[k];yy=j+dy[k];
                if((f[xx][yy]==0)||(f[xx][yy]==2))w++,a[w].x=xx,a[w].y=yy,a[w].z=dist[xx][yy];//������ħ�����ߵ�λ�� 
            }
			if(w){												//����������ߵ�·
				sort(a+1,a+w+1,sortcmp2);					//�������������
				xx=a[1].x;yy=a[1].y;
				if((xx==nowx)&&(yy==nowy)){				//����ߵ�����ҵ�λ�� 
				    z=rand()%100+80;zjhp-=z;xx=i;yy=j;if(zjhp<0)zjhp=0;//����˺����˺�Ϊ80-179 
				    setpos(N+1,0);for(k=1;k<=160;k++)printf(" ");
				    setpos(N+1,0);printf("ħ���������%d���˺�",z);ts=0;
				    setpos(N+2,0);for(k=1;k<=160;k++)printf(" ");
                    setpos(N+2,0);printf("�ȼ� %d Ѫ %d/%d �� %d",level,zjhp,manhp,gongji);
				    if(zjhp<=0){loss();return;}					//ѪΪ0������ 
				    continue;
                }
                relong(i,j);drawlong(xx,yy);						//�ƶ��� 
				hp[xx][yy]=hp[i][j];hp[i][j]=0;
				flag1[xx][yy]=1;					//ѡΪ�Ѿ��߹�
			}
        }
}
void shua4(){									//����ˢ�¸߼�������·���������ٻ�ħ������� 
    int i,j,w,k,xx,yy,sj,z;
    arr1 a[5];
    memset(flag1,0,sizeof(flag1));
    spfa3(nowx,nowy,5);
    if(rand()%10==0)addlong();					//ÿ��һ��ʱ��ˢ��ħ�����൱���ٻ�����Ⱥ 
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
        if((f[i][j]==5)&&(flag1[i][j]==0)){				//����Ǹ߼�������û���߹� 
            w=0;
            if((rand()%5)==0){mljn(i,j);continue;}			//���֮һ���������񣩴������� 
            for(k=0;k<4;k++){
                xx=i+dx[k];yy=j+dy[k];
                if(xx<=1||xx>=N||yy<=1||yy>=M)continue;
                if((f[xx][yy]==0)||(f[xx][yy]==2)||f[xx][yy]==1)w++,a[w].x=xx,a[w].y=yy,a[w].z=dist[xx][yy];
            }
			if(w){												//����������ߵ�·
				sort(a+1,a+w+1,sortcmp2);					//�������������
				xx=a[1].x;yy=a[1].y;
				if((xx==nowx)&&(yy==nowy)){
				    z=rand()%(manhp/7)+100;zjhp-=z;xx=i;yy=j;if(zjhp<0)zjhp=0;		//����ҵİٷֱȿ�Ѫ 
				    setpos(N+1,0);for(k=1;k<=160;k++)printf(" ");
				    setpos(N+1,0);printf("�����������%d���˺�",z);ts=0;
				    setpos(N+2,0);for(k=1;k<=160;k++)printf(" ");
                    setpos(N+2,0);printf("�ȼ� %d Ѫ %d/%d �� %d",level,zjhp,manhp,gongji);
				    if(zjhp<=0){loss();return;}
				    continue;
                }
                rewang(i,j);drawwang(xx,yy);		//�ƶ��߼��� 
				hp[xx][yy]=hp[i][j];hp[i][j]=0;		//����ԭ��λ�õ�hp��0,�µĵص�������Ӧhp 
				flag1[xx][yy]=1;					//ѡΪ�Ѿ��߹�
			}
        }
}
void mljn(int longx,int longy){								//�������ļ��� 
	int fw=3,i,j,x,y,z,px=0;							//����Χ=3,pxĬ��Ϊ0Ϊ���� 
	setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
	memset(ff,0,sizeof(ff));						
	color(12);if(rand()%4==0)px=1;				//�������
	setpos(N+1,0);
	if(px==1)fw=8,printf("ħ����������");		//��ΧΪ8
		else if(px==0)printf("ħ����������");				//��ΧΪ3 
	color(7);
	for(i=-fw;i<=fw;i++)						//ö����Χ��Χ���������ӱ��� 
		for(j=-fw;j<=fw;j++){
			if(abs(i)+abs(j)>fw)continue;
			x=longx+i;y=longy+j;
			if((x>=1)&&(x<=N)&&(y>=1)&&(y<=M)){
				if(f[x][y]==0){
					setpos(x-1,(y-1)*2);
					if(px==1)color(7);else color(12);//������ʾΪ��ɫ������Ϊ��ɫ 
					printf("#");ff[x][y]=1;			//���#�ű�ʾ������Χ 
				}
				if(f[x][y]==2){
					if(px)z=30;else z=rand()%50+10;					//�����̶��˺�30������Ϊ10��59���һ���� 
					color(7);
					setpos(N+1,10);printf("�������%d���˺�",z);
					zjhp-=z;if(zjhp<0)zjhp=0;
					if(zjhp<=0){loss();return;}
				}
			}
		}
	color(7);
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(ff[i][j])setpos(i-1,(j-1)*2),printf("  ");
	setpos(N+2,0);for(i=1;i<=160;i++)printf(" ");
    setpos(N+2,0);printf("�ȼ� %d Ѫ %d/%d �� %d",level,zjhp,manhp,gongji);
}
void fazhao(){
	int i,j,x,y,fw,szpx=0;
	setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
	memset(ff,0,sizeof(ff));
	setpos(N+1,0);
	fw=rand()%6+2;									//�������Χ��2-8���ܱ� 
	color(14);
	if(rand()%100<5)fw=120,printf("���ӱ��� - ʱ֮���� ������޴��˺�"),qp=1,szpx=1;//ȫ���˺����ٷ�֮����ʴ���� 
	else printf("���ӱ���");						//������Ƿ�ΧСһЩ�Ĺ����ռ� 
	color(7);
	for(i=-fw;i<=fw;i++)
		for(j=-fw;j<=fw;j++){
			if(abs(i)+abs(j)>fw)continue;
			x=nowx+i;y=nowy+j;
			if((x>=1)&&(x<=N)&&(y>=1)&&(y<=M)){				//�ж����ڵ�ͼ��
				if(f[x][y]==3)reguai(x,y),hp[x][y]=0,guais--,kill++;				//�ǹ־���
				if(f[x][y]==4)relong(x,y),hp[x][y]=0,mls--,killlong++;				//��ɱһ�� 
				if(f[x][y]==5)rewang(x,y),hp[x][y]=0,wang--,killwang++;				//��������ͬ���� 
				if((f[x][y]==0)||(f[x][y]==3)||(f[x][y]==4)||f[x][y]==5){		//�ǹֻ�յؾ���ʾ���ӱ���Ч�� 
					setpos(x-1,(y-1)*2);
					color(rand()%100);printf("*");ff[x][y]=1;
				}
			}
		}
	color(7);
	if(szpx==1)Sleep(2000);else Sleep(150);
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(ff[i][j])setpos(i-1,(j-1)*2),printf("  ");
}
void fazhao2(){										//�����ף�ƽA��������ͨ���� 
	int x,y,i,j,z,sum=0,bj=0;
	memset(jineng,0,sizeof(jineng));
	setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
	setpos(N+1,0);color(3);printf("������");ts=0;color(7);
	if(rand()%10==0)color(12),bj=1,printf("  ����"),color(7);				//���������
	x=nowx;y=nowy;
	while(f[x-1][y]==0||f[x-1][y]==3||f[x-1][y]==4||f[x-1][y]==5)x--,jineng[x][y]=1;	//ö���ĸ�����
	x=nowx;y=nowy;
	while(f[x][y-1]==0||f[x][y-1]==3||f[x][y-1]==4||f[x][y-1]==5)y--,jineng[x][y]=1;
	x=nowx;y=nowy;
	while(f[x][y+1]==0||f[x][y+1]==3||f[x][y+1]==4||f[x][y+1]==5)y++,jineng[x][y]=1;
	x=nowx;y=nowy;
	while(f[x+1][y]==0||f[x+1][y]==3||f[x+1][y]==4||f[x+1][y]==5)x++,jineng[x][y]=1;
	z=rand()%10+gongji;if(bj)z=rand()%100+gongji*2;
	for(i=1;i<=N;i++)											//ɱ�ּӻ���
		for(j=1;j<=M;j++)
		if(jineng[i][j]==1){
			if(f[i][j]==3){										//��ʷ��ķ�����
				sum+=z;hp[i][j]-=z;
				if(hp[i][j]<=0)hp[i][j]=0,reguai(i,j),guais--,kill++,jy+=1;//�����1 
			}
			if(f[i][j]==4){									  //��ħ�������
			    sum+=z;hp[i][j]-=z;
			    if(hp[i][j]<=0)hp[i][j]=0,relong(i,j),mls--,killlong++,jy+=15;  //ħ��20�㾭��
			}
			if(f[i][j]==5){
				sum+=z;hp[i][j]-=z;
				if(hp[i][j]<=0)hp[i][j]=0,rewang(i,j),wang--,killwang++,jy+=max(40,level*2);//������λ�����40�𲽣����ߵȼ���*2 
			}
			if(f[i][j]==0){
				setpos(i-1,(j-1)*2);
				if(bj)color(12);else color(3);
				if(j==nowy)printf("|");
				if(i==nowx)printf("-");
			}
		}
	if(bj)color(12);else color(3);
	setpos(N+1,15);printf("�����%d���˺�",sum);
	if(jy>=level){
        ts=0;color(6);printf("  ����");color(7);								//��������� ���ӵ����
	    while(jy>=level)jy-=level,level++,gongji+=rand()%5+7,manhp+=rand()%10+20,zjhp+=manhp/6;//���ľ��飬�ȼ����� 
	    if(zjhp>manhp)zjhp=manhp;									//�������hp������ͬʱ��Ѫ����֮һ
	    setpos(N+2,0);for(i=1;i<=160;i++)printf(" ");
        setpos(N+2,0);printf("�ȼ� %d Ѫ %d/%d �� %d",level,zjhp,manhp,gongji);
	}
	color(7);jngx=0;lengque=0;									//������ȴ
}
void shua2(){
	for(int i=1;i<=N;i++)										//��������ȴ
		for(int j=1;j<=M;j++)
			if(jineng[i][j]==1){
				jineng[i][j]=0;
				if(f[i][j]==0)setpos(i-1,(j-1)*2),printf("  ");
			}
	lengque=1;												//��ȴ���
}
void huihp(){												//���������Ǽ�Ѫ 
    zjhp+=level;if(zjhp>manhp)zjhp=manhp;					//�����ǵĵȼ�����Ѫ����һ��Ϊ�˷�ֹ��Ѫ 
    setpos(N+2,0);for(int i=1;i<=160;i++)printf(" ");
    setpos(N+2,0);printf("�ȼ� %d Ѫ %d/%d �� %d",level,zjhp,manhp,gongji);			//ͬʱˢ������Ѫ����� 
}
void work(){
	Sleep(10);js++;ts++;jngx++;sg++;huixue++;mltime++;wangtime++;		//�������ƻ������
	if((wang==0)&&(killlong>=ls)&&(killlong>0)){
		ls+=1;
		for(int i=1;i<=level/10+1;i++)addwang();
	}
	if(wang&&(wangtime>=max(40-level/2,7)))shua4(),wangtime=0;//������λ��·ʱ��10-(40-level),����7��λʱ����һ��(���66��ʱ) 
	if(js>=50)shua(),js=0;									//ʷ��ķˢ��Ϊ500���� 
	if(ts>=200){							//����������ʾ����ʧʱ�䣬����2��
		setpos(N+1,1);for(int i=1;i<=160;i++)printf(" ");
		ts=0;
	}
	if(jngx>=25)shua2(),jngx=0;//���ܸ���
	if(sg>=300){						//ÿ��3��ˢһֻʷ��ķ 
        setpos(N+1,0);for(int i=1;i<=160;i++)printf(" ");
        setpos(N+1,0);color(2);printf("��ͼ�ϵ���һֻ�µ�ʷ��ķ");ts=0;color(7);
        addguai();sg=0;
    }
    if(huixue>150)huihp(),huixue=0;					//ÿ��1.5��ָ�һ��Ѫ 
    if(mltime>=100){								//��ͨħ���ƶ�Ϊ1����һ�� 
		shua3();
        if(rand()%100==0)addlong();
        mltime=0;
    }
}
void zb(){                        //��������ģʽ
	char ch1[11];
	setpos(N,1);
	for(int i=1;i<=10;i++)ch1[i]=getch();		//����10���ַ�������ȫ�����
		if(ch1[1]=='w'&&ch1[2]=='o')				//������Ϊwohenlihai 
			if(ch1[3]=='h'&&ch1[4]=='e'&&ch1[5]=='n')
				if(ch1[6]=='l'&&ch1[7]=='i'&&ch1[8]=='h')
					if(ch1[9]=='a'&&ch1[10]=='i'){
						//mciSendString("close mymusic", NULL, 0, NULL);
						//mciSendString("open music\\ս��.mp3 alias mymusic", NULL, 0, NULL);	// ������
						//mciSendString("play mymusic repeat", NULL, 0, NULL);				//ѭ������
						zuobi=1;							//��������
						setpos(N+1,1);for(int i=1;i<=160;i++)printf(" ");
						setpos(N+1,1);printf("��ѧ�������ӱ���,ע�����ӱ���ɱ�в���þ��� k");ts=0;	//��ʾ�Ѿ�����������Ϊk
					}
}
void printfiq(){											//����������� 
	setpos(N+1,1);for(int i=1;i<=160;i++)printf(" ");
	setpos(N+1,1);printf("�ֵĵ�ǰ����Ϊ%d",guaiiq*15);
	ts=0;
}
void jnlq(){												//������δ��ȴ 
	setpos(N+1,1);for(int i=1;i<=160;i++)printf(" ");
	setpos(N+1,1);printf("������δ��ȴ");ts=0; 				//������ȴ
}
void run(){												//������ȡ��ҵ����룬���ж� 
	for(;;){
		work();
    	if(kbhit()){						//������������ 
			ch=getch();
			if(ch=='a'||ch=='A')                        //��
				if(judge(nowx,nowy-1))redraw(nowx,nowy),nowy--,draw(nowx,nowy),yourbs++;
			if(ch=='d'||ch=='D')                         //��
				if(judge(nowx,nowy+1))redraw(nowx,nowy),nowy++,draw(nowx,nowy),yourbs++;
			if(ch=='w'||ch=='W')                         //��
				if(judge(nowx-1,nowy))redraw(nowx,nowy),nowx--,draw(nowx,nowy),yourbs++;
			if(ch=='s'||ch=='S')                         //��
				if(judge(nowx+1,nowy))redraw(nowx,nowy),nowx++,draw(nowx,nowy),yourbs++;
			if(nowx==zhongx&&nowy==zhongy)win();        //���յ�ʤ��
			if(ch=='n'||ch=='N')begin();               //����һ��
			if(ch=='p'||ch=='P')AI();                 //�Զ���
			if(ch=='g'||ch=='G')addguai();
			if((ch=='k'||ch=='K')&&(zuobi==1))fazhao();
			if((ch=='t'||ch=='T')){guaiiq++;if(guaiiq>10)guaiiq=10;printfiq();}   //���߹ֵ�����
			if((ch=='y'||ch=='Y')){guaiiq--;if(guaiiq<1)guaiiq=1;printfiq();}     //���͹ֵ�����
			if(ch=='j'||ch=='J'){							//����
				if(lengque==1)fazhao2();						//����ܷ�
				else jnlq();									//������ʾ
			}
			if(ch=='~')zb();					//����������ģʽ 
		}
	}
}
int main(){
	srand(time(NULL));                             //����������� 
    begin();										//�����ͼ 
    run();											//������� 
    return 0;
}
