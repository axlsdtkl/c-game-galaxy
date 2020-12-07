//注：游戏设计的初衷是走迷宫，但是玩家很容易忘记这一初衷 
//0空地  1障碍  2人  3怪  4 魔龙 5 龙王或龙神 -1终点
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
int sortcmp(arr1 a,arr1 b){return a.z>b.z;}    //快速排序按从大到小
int sortcmp2(arr1 a,arr1 b){return a.z<b.z;}	//快速排序从小到大 
void draw(int x,int y);
void addguai();
void mljn(int longx,int longy);
void addlong();
void addwang();
void setpos(int x,int y){          //取光标，把光标移动到x,y的位置 
    COORD pos={y,x};
    HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out,pos);
}
void color(int x){				//取颜色
	HANDLE y=GetStdHandle((STD_OUTPUT_HANDLE));//设定相应颜色 
	SetConsoleTextAttribute(y,x);
}
void dfs(int x,int y){             //先找出一条到最右边的路，很容易陷入圈中，需要限定次数
	int i,sum,xx,yy,temp,cz[5];
	js++;
	if(js>10000)return;            //超过次数直接退出，继续随机一条路
	if(f[x][y]==0)return;          // 搜索没有障碍的点
	sum=f[x-1][y]+f[x][y-1]+f[x][y+1]+f[x+1][y];  //要搜索那些不会发生连通情况的点
	if(sum<=2)return;
	if((y==M-1)&&(x==N-1)){f[x][y]=0;yes=1;return;}         //如果已经搜到最右下角，成功
	if(x==1||x==N||y==1||y==M)return;            //如果搜到边界，退出
	f[x][y]=0;                                   //回溯先模拟去掉
	for(i=0;i<4;i++)cz[i]=i;						//通过随机交换枚举顺序 
	for(i=1;i<=10;i++){								//随机方向的顺序
		xx=rand()%4;yy=rand()%4;
		temp=cz[xx];cz[xx]=cz[yy];cz[yy]=temp;
	}                                             
	for(i=0;i<4;i++){							//找路 
		if(cz[i]==0)dfs(x-1,y);					//四个方向搜索 
		if(cz[i]==1)dfs(x,y-1);
		if(cz[i]==2)dfs(x,y+1);
		if(cz[i]==3)dfs(x+1,y);
		if(yes==1)return;                         //如果已经找到，退出
	}                                             //模拟
	f[x][y]=1;                                    //回溯返回
	if(js>10000)return;                           //超过次数直接退出，继续随机一条路
}
void dfs2(int x,int y,int bs){                     //在原有地图基础上随机出一条路，尽量长
	int sum,cz1,i,xx,yy,temp,cz[5];
	js++;
	if(js>10000)return;                           //同样要限定次数
	if(f[x][y]==0)return;                         //搜索没有障碍的点
	if(x==1||x==N||y==1||y==M)return;             //边界
	sum=f[x-1][y]+f[x][y-1]+f[x][y+1]+f[x+1][y];  //搜索那些不会发生连通情况的点
	if(sum<=2)return;
	f[x][y]=0;
	if(bs>=cd){yes=1;return;}                     //限定跳出步数
	for(i=0;i<3;i++)cz[i]=i;
	for(i=1;i<=10;i++){                            //随机方向的顺序
		xx=rand()%4;yy=rand()%4;
		temp=cz[xx];cz[xx]=cz[yy];cz[yy]=temp;
	}
	for(i=0;i<4;i++){                               //按随机后的顺序枚举四个方向
		cz1=cz[i];
		if(cz1==0)dfs2(x-1,y,bs+1);
		if(cz1==1)dfs2(x,y-1,bs+1);
		if(cz1==2)dfs2(x,y+1,bs+1);
		if(cz1==3)dfs2(x+1,y,bs+1);
		if(yes==1)return;                         //如果已经找到跳出
	}                                             //模拟
	f[x][y]=1;                                    //回溯返回
	if(js>10000)return;
}
void dfs3(int x,int y){                            //用来填充剩余空间                                                 //此函数有空间就扩，不需要用回溯，主要作用是填充迷宫
	int sum,xx,yy,temp,cz1,i,cz[5];
	if(f[x][y]==0)return;
	if(x==1||x==N||y==1||y==M)return;
	sum=f[x-1][y]+f[x][y-1]+f[x][y+1]+f[x+1][y];
	if(sum<=2)return;
	f[x][y]=0;
	for(i=0;i<3;i++)cz[i]=i;                     //随机搜索顺序
	for(i=1;i<=10;i++){
		xx=rand()%4;yy=rand()%4;
		temp=cz[xx];cz[xx]=cz[yy];cz[yy]=temp;
	}
	for(i=0;i<4;i++){                            //枚举随机后的搜索顺序
		cz1=cz[i];
		if(cz1==0)dfs3(x-1,y);
		if(cz1==1)dfs3(x,y-1);
		if(cz1==2)dfs3(x,y+1);
		if(cz1==3)dfs3(x+1,y);
	}
}
void spfa(int qix,int qiy,int zhongx,int zhongy){                   //求两点之间的最短路
	int mo,l,r,x,y,xx,yy,i,j;
	mo=N*M;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)dist[i][j]=100000;
	dist[qix][qiy]=0;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)flag[i][j]=0;
	flag[qix][qiy]=1;
	l=0;r=1;q[0].x=qix;q[0].y=qiy;                              //用循环队列
	while(l!=r){
		x=q[l].x;y=q[l].y;l=(l+1)%mo;flag[x][y]=0;
		for(i=0;i<4;i++){
			xx=x+dx[i];yy=y+dy[i];
			if(f[xx][yy]==0||f[xx][yy]==-1){
				if(dist[x][y]+1>=dist[zhongx][zhongy])continue; //由于是求两点间的最短距离，如果当前搜索的点的距离已经超过
				if(dist[x][y]+1<dist[xx][yy]){                  //到目标的最短距离，以后就没必要去更新它了，是个优化的spfa
					dist[xx][yy]=dist[x][y]+1;
					if(flag[xx][yy]==0)flag[xx][yy]=1,q[r].x=xx,q[r].y=yy,r=(r+1)%mo;
				}
			}
		}
	}
}
void spfa2(int qix,int qiy,int zhongx,int zhongy){                  //求两点之间的最短路，并保存下路径
	int mo,l,r,x,y,xx,yy,i,j,xxx,yyy;
	arr temp;
	mo=N*M;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)dist[i][j]=100000;
	dist[qix][qiy]=0;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)flag[i][j]=0;
	flag[qix][qiy]=1;
	l=0;r=1;q[0].x=qix;q[0].y=qiy;                                 //用循环队列
	while(l!=r){
		x=q[l].x;y=q[l].y;l=(l+1)%mo;flag[x][y]=0;
		for(i=0;i<4;i++){
			xx=x+dx[i];yy=y+dy[i];
			if(f[xx][yy]==0||f[xx][yy]==-1){                         //是空地或终点
				if(dist[x][y]+1>=dist[zhongx][zhongy])continue;     //由于是求两点间的最短距离，如果当前搜索的点的距离已经超过
				if(dist[x][y]+1<dist[xx][yy]){                 //到目标的最短距离，以后就没必要去更新它了，优化spfa
					dist[xx][yy]=dist[x][y]+1;
					pre[xx][yy].x=x;pre[xx][yy].y=y;                            //保存路径
					if(flag[xx][yy]==0)flag[xx][yy]=1,q[r].x=xx,q[r].y=yy,r=(r+1)%mo;
				}
			}
		}
	}
	xxx=zhongx;yyy=zhongy;                                                       //倒退求出到终点的路径，为了让程序实现自动走
	for(;;){
		top++;stack1[top].x=xxx;stack1[top].y=yyy;                                //用个stack1数组保存倒退的路径
		xx=pre[xxx][yyy].x;yy=pre[xxx][yyy].y;
		xxx=xx;yyy=yy;
		if(xxx==qix&&yyy==qiy)break;
	}
	for(i=1;i<=top/2;i++)temp=stack1[i],stack1[i]=stack1[top-i+1],stack1[top-i+1]=temp;  //把倒退的路径变成顺序的路径
}
void spfa3(int qix,int qiy,int pd){       //求当前点到其它所有点的最短路,pd是用来判断是普通魔龙还是高级魔龙 
	int mo,l,r,x,y,xx,yy,i,j;
	mo=N*M;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)dist[i][j]=100000;
	dist[qix][qiy]=0;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)flag[i][j]=0;
	flag[qix][qiy]=1;
	l=0;r=1;q[0].x=qix;q[0].y=qiy;                              //用循环队列
	while(l!=r){
		x=q[l].x;y=q[l].y;l=(l+1)%mo;flag[x][y]=0;
		for(i=0;i<4;i++){
			xx=x+dx[i];yy=y+dy[i];
			if((xx<=1)||(xx>=N)||(yy<=1)||(yy>=M))continue; 						//不可以超过边界 
			if((f[xx][yy]==0)||(f[xx][yy]==3)||(f[xx][yy]==4)||(f[xx][yy]==5)||((f[xx][yy]==1)&&(pd==5))){ //如果是高级龙可以无视障碍 
				if(dist[x][y]+1<dist[xx][yy]){
					dist[xx][yy]=dist[x][y]+1;
					if(flag[xx][yy]==0)flag[xx][yy]=1,q[r].x=xx,q[r].y=yy,r=(r+1)%mo;
				}
			}
		}
	}
}
void gouzao(){                    //构造一个新迷宫的函数
	int i,j,xx,yy,sum,xxx,yyy,xxxx,yyyy,js2;
	yes=0;
 	for(i=1;i<=N;i++)for(j=1;j<=M;j++)f[i][j]=1;    //先把图变成全障碍
	for(;;){                                        //不断随机路径，直到随机出一条到地图最右下角的路
	    js=0;
        dfs(2,2);									//不断搜索直到找到一条能从(2,2)到(N-1,M-1)的路 
        if(yes)break;
	}
	for(i=1;i<=N*M;i++){                            //随机出一些新的死路，用来增加迷宫的难度
		xx=rand()%(N-2)+2;							//死路是从障碍开始沿伸出去的 
		yy=rand()%(M-2)+2;
		if(f[xx][yy]==1){
			sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];//确保挖了以后不会连通迷宫的其它路径，使得难度变简单 
			if(sum==3){
				yes=0;js=0;cd=(N+M)/6+rand()%20;       //随机死路需要的长度
				dfs2(xx,yy,1);						//用dfs搜索出一条比较长的死胡同 
			}
		}
	}
	for(i=2;i<=N-1;i++)                                 //按顺序搜出尽量长的死路
		for(j=2;j<=M-1;j++){							//上面的一次dfs2是随机构造的，这里再一次填充 												//构造，从地图左上到右下，这样的好处是因为玩家从左上出发， 
			xx=i;yy=j;									//这样可以尽可能大增加走迷宫难度 
			if(f[xx][yy]==1){
				sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];
				if(sum==3){
					yes=0;js=0;cd=rand()%10;
					dfs2(xx,yy,1);
				}
			}
		}
	for(i=1;i<=N*M;i++){                             //随机填充剩余空间，把剩下的空间先随机填充一遍  			
		xx=rand()%(N-2)+2;
		yy=rand()%(M-2)+2;
		if(f[xx][yy]==1){
			sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];
			if(sum==3)dfs3(xx,yy);
		}
	}
	for(i=2;i<=N-1;i++)                                  //按顺序填充剩余空间，图已填满
		for(j=2;j<=M-1;j++){							//把剩下的空间完全填充一遍，使得整个迷宫比较满 
			xx=i;
			yy=j;
			if(f[xx][yy]==1){
				sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];
				if(sum==3)dfs3(xx,yy);
			}
		}
	setpos(N+1,0);                                        //用spfa算法找出从起点到终点的最短路
	spfa(2,2,N-1,M-1);dist1=dist[N-1][M-1];
	memset(fff,0,sizeof(fff));
	for(;;){
	    js2=0;
		for(i=2;i<=N-1;i++)                                    //先前构的图是张树形图，要加入环的情况
			for(j=2;j<=M-1;j++){                                //枚举能去掉的障碍
				xx=i;
				yy=j;
				if((f[xx][yy]==1)&&(fff[xx][yy]==0)){
					sum=f[xx-1][yy]+f[xx][yy-1]+f[xx][yy+1]+f[xx+1][yy];
					if(sum==2){
						f[xx][yy]=0;
						spfa(2,2,N-1,M-1);                   //首先要保证去掉这个方块，要使图的最短路长度不变，不然出现捷径难度就非常低了 
						f[xx][yy]=1;                         //还原方块
						if(dist[N-1][M-1]==dist1){           //然后求出方块连通的两个空格在之前的最短路
							if(f[xx-1][yy]==0)xxx=xx-1,yyy=yy;
								else if(f[xx][yy-1]==0)xxx=xx,yyy=yy-1;				//求出连通它的两个坐标点
									else if(f[xx][yy+1]==0)xxx=xx,yyy=yy+1;
										else xxx=xx+1,yyy=yy;	
							if((f[xx][yy-1]==0)&&((xx!=xxx)||(yy-1!=yyy)))xxxx=xx,yyyy=yy-1;
								else if((f[xx][yy+1]==0)&&((xx!=xxx)||(yy+1!=yyy)))xxxx=xx,yyyy=yy+1;
									else xxxx=xx+1,yyyy=yy;
							spfa(xxx,yyy,xxxx,yyyy);         //算法还是spfa
							if(dist[xxxx][yyyy]>30)js2++,a[js2].x=xx,a[js2].y=yy,a[js2].z=dist[xxxx][yyyy];//只需要考虑足够长的两点
								else fff[xx][yy]=1;                     //为了程序的速度，那些两点之间最短距离本身就很近
						}                                               //将方块去掉以后最短距离一定不会变长，这类点用个
						else fff[xx][yy]=1;                             //fff函数记录下次搜索到直接跳过，因为小环是干扰性不够的 
					}
				}
			}
		if(js2==0)break;                                                         //不断循环，直到找不到这样的点
		sort(a+1,a+js2+1,sortcmp);                                             //将满足条件的点搜索出来，排序，优先搜索两
		xx=a[1].x;yy=a[1].y;f[xx][yy]=0;                                       //方块最短距离大的点
	}
}
void begin(){
	int i,j,xx,yy;
	wangmusic=0;												//龙王第一次出场音乐用这个标记 
	shenmusic=0;												//神龙的出场音乐标记控制 
	ls=2;														//出龙王限制，每次加1，击败两条龙后出现龙王，之后刷龙神 
	yourbs=0;guais=0;js=0;										//保存玩家的步数   怪的数量    怪走路刷新
	guaiiq=5; 													//怪的默认智商
	mltime=0;                                                   //魔龙刷新
	mls=0;                                                      //魔龙数量
	killlong=0;                                                 //消灭的龙数
	zuobi=0;									              //默认不作弊
	qp=0;														//清屏技能触发
	lengque=1;												//技能冷却
	sg=0;                                                   //刷怪
	kill=0;													//杀史莱姆统计
	zjhp=100;                                               //当前hp
	manhp=100;                                          //hp上限
	level=1;                                                   //当前等级
	gongji=30;                                          //当前攻击
	jy=0;                                               //当前经验
	huixue=0;											//回hp计时
	wang=0;                                             //是否存在龙王
	killwang=0;											//杀龙王数 
	wangtime=0;											//龙王时间 
	memset(hp,0,sizeof(hp));							//用来保存地图上所有怪的血 
	starttime=clock();                                 //游戏开始时间
	system("cls");                                                         //开始界面
	setpos(10,40);
	printf("玩高难度级别请右键边框属性布局中将缓冲区屏幕大小和窗口宽度调至170");		//提示 
	setpos(12,40);
	//printf("作弊码为wohenlihai");								//你懂的 
	setpos(15,40);
	printf("游戏目标为到右下角找到星星");					//白雪公主，你懂的 
	setpos(18,40);
	printf("基本操作:上 w  下 s  左 a  右 d");					//这个不用多说了 
	setpos(20,40);
	printf("请输入难度0-9(按住shift选0-9为无怪模式)");							//不用多说+1 
	noguai=0;
	//mciSendString("close mymusic", NULL, 0, NULL);								//关闭之前的音乐 
	//mciSendString("open music\\梦之安魂曲.mp3 alias mymusic", NULL, 0, NULL);	// 打开新音乐
	//mciSendString("setaudio mymusic volume to 600",NULL,0,NULL);		//设置音量大小
	//mciSendString("play mymusic repeat", NULL, 0, NULL);				//循环播放
	for(;;){
		ch=getch();                                          //读入难度
		if(ch==')')ch='0',noguai=1;							//下面是两种不同类型 
		if(ch=='!')ch='1',noguai=1;							//纯数字是有怪的类似，按住shift后输入的就变成 
		if(ch=='@')ch='2',noguai=1;							//了相应上排字符 
		if(ch=='#')ch='3',noguai=1;							//用noguai作为标记来确定当前类型 
		if(ch=='$')ch='4',noguai=1;
		if(ch=='%')ch='5',noguai=1;
		if(ch=='^')ch='6',noguai=1;
		if(ch=='&')ch='7',noguai=1;
		if(ch=='*')ch='8',noguai=1;
		if(ch=='(')ch='9',noguai=1;
		nandu=ch-'0';										//通过字符ASCII的减法来相应计算当前难度 
		if(ch>='0'&&ch<='9'){
			N=(int)((double)(ch-'0'+1)*3.8);                            //根据难度构造迷宫的相应大小
			M=(ch-'0'+1)*8;
			break;
		}
	}
	gouzao();                                                              //用f数组构造迷宫
	system("cls");                                                         //清屏
	setpos(0,0);														//光标到最左上角 
	color(8);														//调成灰色 
	for(i=1;i<=N;i++){                                                     //输出迷宫
		for(j=1;j<=M;j++)
		if(f[i][j]==1)printf("囧");                                        //1表示当前块是障碍块，可以把囧换成其它汉字 
		else if(f[i][j]==0)printf("  ");                                //0表示当前块是空地
		putchar('\n');
	}
	color(7);setpos(N+2,0);printf("等级 %d 血 %d/100 攻 %d",level,zjhp,gongji);	//输出玩家现在的情况 
	color(7);setpos(N,4);printf("重来一局 n  自动走 p  加怪 g  提高怪物智商 t  降低怪物智商 y  攻击 j  输入作弊码 ~");
	nowx=2;nowy=2;                                    				//起点，也就是开始位置 
	zhongx=N-1;zhongy=M-1;                                      //终点，也就是目标位置 
	f[zhongx][zhongy]=-1;										//数组中的-1表示终点 
	setpos(zhongx-1,(zhongy-1)*2);color(6);printf("★");color(7);
	draw(nowx,nowy);
	for(i=1;i<=(ch-'0');i++)addguai();									//根据游戏难度生成一定数量的史莱姆
	if((ch-'0')>5)addlong();											//难度6为生成一条魔龙 
	if((ch-'0')>6)addlong();											//难度7为生成一条魔龙 
	if((ch-'0')>7)addlong();											//难度8为生成一条魔龙 
	if((ch-'0')>8)addlong();											//难度9为生成一条魔龙  
}
void draw(int x,int y){                                                 //画上现在的人物点 
	f[x][y]=2;x=x-1;y=(y-1)*2;		
	setpos(x,y);color(6);printf("♀");color(7);								//人物为深黄色 
}
void redraw(int x,int y){f[x][y]=0;x=x-1;y=(y-1)*2;setpos(x,y);printf("  ");}    //擦除原有点
void drawguai(int x,int y){									//添加怪物
	f[x][y]=3;
	x=x-1;y=(y-1)*2;
	setpos(x,y);color(2);printf("◎");color(7);					//绿色的屎莱姆 
}
void reguai(int x,int y){										//擦除怪物，变成空格 
	f[x][y]=0;
	x=x-1;y=(y-1)*2;
	setpos(x,y);printf("  ");
}
void drawlong(int x,int y){										//画龙
    f[x][y]=4;												//f数组中4为普通龙 
    x=x-1;y=(y-1)*2;
    setpos(x,y);color(12);printf("龙");color(7);			//颜色color(12)为红色,color(7)为切换成默认灰色 
}
void drawwang(int x,int y){										//画高级龙的位置 
    f[x][y]=5;													//5为高级龙 
    x=x-1;y=(y-1)*2;
    setpos(x,y);color(5);
	if(killwang==0)printf("王");								//第一次为龙王 
	else if(killwang>=1)printf("神");							//击败过龙王后出神龙，其实这么写主要是比较偷懒 
	color(7);
}
void relong(int x,int y){f[x][y]=0;x=x-1;y=(y-1)*2;setpos(x,y);printf("  ");}		//擦除龙
void rewang(int x,int y){f[x][y]=0;x=x-1;y=(y-1)*2;setpos(x,y);printf("  ");}		//擦除高级龙（包括龙王和神龙） 
int judge(int x,int y){return(f[x][y]==0||f[x][y]==-1);}//判断是空地或终点	
void run();
void printprincess(){											//输出人物形象 
	char ch=92;
	system("cls");
	setpos(10,0);printf("                                                成功找到星星");
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
void win(){                                                              //输出胜利后的界面
	endtime=clock();                                                   //求当前时间
	dtime=(double)(endtime-starttime)/CLOCKS_PER_SEC;                  //输出两段时间之间的时间差
	printprincess();
	system("cls");														//清屏
	setpos(13,60);printf("迷宫最少步数：%d",dist1);						//直接看文字 
	setpos(14,60);printf("你的步数:%d",yourbs);							//直接看文字 
	setpos(15,60);printf("总用时:%.3lf s",dtime);						//直接看文字 
	setpos(16,60);printf("你的难度是：%d",nandu);						//直接看文字 
	setpos(17,60);printf("生存的史莱姆数量：%d 生存的魔龙数量：%d",guais,mls);
	yuce=dist1/4;                                                  //预测时间为总步数除预测每秒走的步数
	bs=dtime/yuce;                                                 //根据玩家的时间算出玩家的等级
	setpos(18,60);printf("你的技术：");				//直接看文字，下面的等级是按从高到低随便一堆人，可以随便改，还是谦虚点好 
	if(bs<=1)printf("You are superman!");			//当前用时/预测用时，很明显，这个值越小，说明你越厉害					
	else if(bs<=2)printf("你很厉害");				//数字越大说明玩家走的越慢 
	else if(bs<=3)printf("你很棒");
	else if(bs<=4)printf("You are good");
	else if(bs<=5)printf("请挑战更高级别");
	else if(bs<=6)printf("你很勇敢");
	else if(bs<=7)printf("你很乐观");
	else if(bs<=8)printf("你很坚强");
	else if(bs<=9)printf("继续努力，加油");
	else printf("耶");
	setpos(19,60);printf("共击败%d只史莱姆",kill);						//直接看文字 
	setpos(20,60);printf("共击败%d只魔龙",killlong);					//直接看文字 
    if(guais==0)setpos(21,60),printf("击败所有史莱姆，获得称号 prince");//直接看文字 
	if(killlong>=2)setpos(22,60),printf("击败多只魔龙，获得称号 KING");				//直接看文字 
    if(zuobi==1)setpos(23,60),printf("银河爆碎，获得称号 观察者");					//直接看文字 
    if(qp==1)setpos(24,60),printf("时之咆哮，获得称号 归零者");					//直接看文字 
	if(killwang>=1)setpos(25,60),printf("击败龙王，获得称号 warrior");				//直接看文字 
	if(killwang>=2)setpos(26,60),printf("击败神龙，获得称号 The Incredible Hulk");	//直接看文字 
	setpos(30,50);printf("重来一局 n ");						//直接看文字 
	for(;;)                                                  //不断循环，直到玩家键盘有读入
		if(kbhit()){										//直到键盘有输入 
			char ch=getch();
		 	if(ch=='n'||ch=='N'){begin();return;}                          //输入n为再来一局
		}
}
void AI(){							//关于自动导航功能，这个功能原来是测纯迷宫时用的，但是后来越加越多，最后这个游戏已经和 									//迷宫没什么关系了，不过这个功能也给加着，在有怪的情况下由于会出现堵路情况，这个功能就封死了 
	int i,limit,js;					//要开启的话，先用作弊码开启银河爆碎打出咆哮清屏，然后再按p，可以自动走路 
	if(guais>0||mls>0||wang>0){						//在有怪的情况下自动走没用 
		setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");//清掉这一行 
		setpos(N+1,0);ts=0;printf("因为有怪物的存在，暂时无法自动走，请先使用银河爆碎清");
		return;
	}
	top=0;
	spfa2(nowx,nowy,zhongx,zhongy); //用spfa求出当前点到终点的最短路
	setpos(N,0);for(i=1;i<=160;i++)printf(" ");
    setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");                                       //同时记录路径
	setpos(N,M/2);printf("暂停 b   加速 u  减速 i");     //最下边为功能提示，可调节自动走的速度 
	limit=8;                                                            //控速变量
	for(i=1;i<=top;i++){//用队列存下了每一步，top为步数，这个是用上面的spfa2求出的最短路 
		js=0;
		for(;;){
			if(kbhit()){					//如果玩家有输入的话 
				ch=getch();
				if(ch=='b'||ch=='B')break;                         //可以走到一半的时候暂停，然后又可以玩家走 
				if(ch=='u'||ch=='U'){limit/=2;if(limit==0)limit=1;}     //加速
				if(ch=='i'||ch=='I'){limit*=2;if(limit>32768)limit=32768;}        //减速
			}
			Sleep(16);                                            //程序暂停的次数用来限制速度
			js++;
			if(js>=limit)break;
		}
		if(ch=='b'||ch=='B'){
			setpos(N,0);for(i=1;i<=160;i++)printf(" ");
			setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
			setpos(N,M/2);printf("重来一局 n  自动行走 p  加怪 g  提高怪物智商 t  降低怪物智商 y  攻击 j  输入作弊码 ~");
			setpos(nowx-1,nowy*2);
			break;
		}
		redraw(nowx,nowy);                      //自动走
		nowx=stack1[i].x;nowy=stack1[i].y;
		draw(nowx,nowy);yourbs++;
		if(nowx==zhongx&&nowy==zhongy)win();           //如果到终点输出胜利
	}
}
void addguai(){							//用随机函数添加怪物
    int js=0,x,y,i;
	if(noguai==1)return;
    for(;;){
        js++;
        x=rand()%(N-2)+2;y=rand()%(M-2)+2;       //随机
        if((f[x][y]==0)&&(abs(nowx-x)+abs(nowy-y)>15))break;     //如果是空地并且距离较远就满足
        if(js>100){
			setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");          //随机多次都无法随机出来就是没有满足点
            setpos(N+1,0);ts=0;printf("无法在有效区域内添加史莱姆");
            return;
        }
    }
    guais++;drawguai(x,y); 									//加上这个位置的怪
	hp[x][y]=rand()%80+20;									//随机出怪的血
}
void addwang(){									//增加高级龙 ，过程同addlong 
    int js=0,x,y,i;
	if(noguai==1)return;
    for(;;){
        js++;
        x=rand()%(N-2)+2;y=rand()%(M-2)+2;
        if((f[x][y]==0)&&(abs(nowx-x)+abs(nowy-y)>15))break;			//首先是空地，然后必须与玩家保持一定距离，不然出龙太不对了 
        if(js>100){													//枚举了100次还是没有找到合适的空位
            setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
            setpos(N+1,0);ts=0;
			if(killwang==0)printf("无法在有效区域内添加龙王");		//先确保在有效范围内可以加，不能出现龙王 
			else if(killwang>=1)printf("神龙无法降临"); 			//不能出现龙神		
            return;
        }
    }
    wang++;drawwang(x,y);											//增加一条龙王或龙神 
    if(killwang==0)hp[x][y]=1000+rand()%1000;						//龙王血 
    else if(killwang>=1)hp[x][y]=gongji*30+rand()%1000;					//神龙血，神龙的实力随着玩家level的提升也 
    setpos(N+1,0);for(i=1;i<=160;i++)printf(" "); 						//会慢慢变强，所以神龙血比较厚 
    setpos(N+1,0);ts=0;
	if(killwang==0){
		printf("多次击败魔龙，龙王出现，龙王会吸引龙群"),Sleep(1500); 		//这里的吸引只增加出普通魔龙的机率	
		if(wangmusic==0){
    		wangmusic=1;
			//mciSendString("close mymusic", NULL, 0, NULL);							//关闭之前的音乐 
			//mciSendString("open music\\暴龙-王.mp3 alias mymusic", NULL, 0, NULL);	// 打开音乐（龙王出场音乐） 
			//mciSendString("play mymusic repeat", NULL, 0, NULL);				//循环播放
		}
	} 
	else if(killwang>=1){
		if(shenmusic<=2){
    		shenmusic++;
			//mciSendString("close mymusic", NULL, 0, NULL);							//关闭之前的音乐 
			//mciSendString("open music\\暴龙-神.mp3 alias mymusic", NULL, 0, NULL);	// 打开音乐（龙神出场音乐） 
			//mciSendString("play mymusic repeat", NULL, 0, NULL);				//循环播放
		}
		else if(shenmusic<=6){
			shenmusic++;
			//mciSendString("close mymusic", NULL, 0, NULL);								//关闭之前的音乐 
			//mciSendString("open music\\暴龙-伏龙坛.mp3 alias mymusic", NULL, 0, NULL);	// 打开音乐（龙神变强了） 
			//mciSendString("play mymusic repeat", NULL, 0, NULL);				//循环播放
		}
		else if(shenmusic<=10){
			shenmusic=16;
			//mciSendString("close mymusic", NULL, 0, NULL);							//关闭之前的音乐 
			//mciSendString("open music\\battle.mp3 alias mymusic", NULL, 0, NULL);	// 打开音乐（非常强的敌人出场音乐）
			//mciSendString("play mymusic repeat", NULL, 0, NULL);				//循环播放，这就是最后的音乐了 
    	}
		printf("神龙降临，神龙会吸引龙群"),Sleep(1500/(level/10+1)); 				////这里的吸引只增加出龙的机率
	}
}
void addlong(){											//加魔龙,同addwang 
    int js=0,x,y,i;
	if(noguai==1)return;
    for(;;){
        js++;
        x=rand()%(N-2)+2;y=rand()%(M-2)+2;
        if((f[x][y]==0)&&(abs(nowx-x)+abs(nowy-y)>15))break;		//在当前玩家较远的位置生成魔龙 
        if(js>100){													//如果随机生成100次以上还没有找到合法位置 
            setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");				//就表示地图过于拥护，没有位置了 
            setpos(N+1,0);ts=0;printf("无法在有效区域内添加魔龙");		//确保有区域 
            return;
        }
    }
    mls++;drawlong(x,y);
    setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
    setpos(N+1,0);color(12);printf("地图上诞生一只魔龙");color(7);				//加龙，颜色为红色 
    hp[x][y]=600+rand()%100;								//普通魔龙血量为600-699，后期其实和史莱姆差不多了 
}
void loss(){												//被怪打到HP为0 
	Sleep(3000);
	system("cls");									//清屏 
	setpos(10,0);
	printf("    L         OOOOOO     SSSSS      EEEEE   \n");					//这个不用解释了 
	printf("    L         O    O     S          E       \n");
	printf("    L         O    O     SSSSS      EEEEE   \n");
	printf("    L         O    O         S      E       \n");
	printf("    LLLLLL    OOOOOO     SSSSS      EEEEE   \n");
	setpos(20,20);printf("You are a loser");					//上面图形的注释 
	setpos(21,20);printf("重来一局 n ");					//游戏重来的提示 
	for(;;)                                               //不断循环，直到玩家键盘有读入
		if(kbhit()){
			char ch=getch();
		 	if(ch=='n'||ch=='N'){begin();return;}                     //n为再来一局
		}
}
void shua(){											//用来刷新史莱姆的走路
	int i,j,w,k,xx,yy,sj,z;
	arr1 a[5],temp;
	memset(flag1,0,sizeof(flag1));						//为了避免重复走同一只，用数组来判断
	spfa3(nowx,nowy,3);									//求出所有点到玩家的最近距离
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
		if((f[i][j]==3)&&(flag1[i][j]==0)){					//是史莱姆并且没有被枚举到
			w=0;
			for(k=0;k<4;k++){								//四个方向选出能走的
				xx=i+dx[k];yy=j+dy[k];
				if((f[xx][yy]==0)||(f[xx][yy]==2))w++,a[w].x=xx,a[w].y=yy,a[w].z=dist[xx][yy];
			}
			if(w){												//如果存在能走的路
				sort(a+1,a+w+1,sortcmp2);					//求出离玩家最近的
				xx=a[1].x;yy=a[1].y;
				if(w>1){                                   //根据怪的智商来选，如果可选路多于一条
					sj=rand()%10+1;                          //随机1-10中的一个数
					if(sj<=guaiiq)xx=a[1].x,yy=a[1].y;        //如果随机数不比当前智商高就选最短路
					if(sj>guaiiq)xx=a[2].x,yy=a[2].y;			//否则选择次短路
				}
				if((xx==nowx)&&(yy==nowy)){						//如果到达的点是玩家的位置，则造成伤害 
				    z=rand()%20+1;zjhp-=z;xx=i;yy=j;if(zjhp<0)zjhp=0;//伤害为1到20，少得可怜 
				    setpos(N+1,0);for(k=1;k<=160;k++)printf(" ");
				    setpos(N+1,0);printf("史莱姆对你造成%d点伤害",z);ts=0;//说明对玩家造成的伤害 
				    setpos(N+2,0);for(k=1;k<=160;k++)printf(" ");
                    setpos(N+2,0);printf("等级 %d 血 %d/%d 攻 %d",level,zjhp,manhp,gongji);//玩家当前的面板 
				    if(zjhp<=0){loss();return;}
				    continue;							//如果受到伤害了，就不用移动史莱姆位置了，直接continue 
                }
                reguai(i,j);drawguai(xx,yy);				//更新怪物最新位置 
				hp[xx][yy]=hp[i][j];hp[i][j]=0;
				flag1[xx][yy]=1;					//选为已经走过
			}
		}
}
void shua3(){										//用来刷新龙的走路 
    int i,j,w,k,xx,yy,sj,z;
    arr1 a[5];
    memset(flag1,0,sizeof(flag1));
    spfa3(nowx,nowy,4);								//先求距离玩家的最短路，过程同史莱姆 
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
        if((f[i][j]==4)&&(flag1[i][j]==0)){
            w=0;
            if((rand()%10)==0){mljn(i,j);continue;}				//十分之一触发技能 
            for(k=0;k<4;k++){									//枚举四个方向 
                xx=i+dx[k];yy=j+dy[k];
                if((f[xx][yy]==0)||(f[xx][yy]==2))w++,a[w].x=xx,a[w].y=yy,a[w].z=dist[xx][yy];//保存下魔龙能走的位置 
            }
			if(w){												//如果存在能走的路
				sort(a+1,a+w+1,sortcmp2);					//求出离玩家最近的
				xx=a[1].x;yy=a[1].y;
				if((xx==nowx)&&(yy==nowy)){				//如果走到了玩家的位置 
				    z=rand()%100+80;zjhp-=z;xx=i;yy=j;if(zjhp<0)zjhp=0;//造成伤害，伤害为80-179 
				    setpos(N+1,0);for(k=1;k<=160;k++)printf(" ");
				    setpos(N+1,0);printf("魔龙对你造成%d点伤害",z);ts=0;
				    setpos(N+2,0);for(k=1;k<=160;k++)printf(" ");
                    setpos(N+2,0);printf("等级 %d 血 %d/%d 攻 %d",level,zjhp,manhp,gongji);
				    if(zjhp<=0){loss();return;}					//血为0就输了 
				    continue;
                }
                relong(i,j);drawlong(xx,yy);						//移动龙 
				hp[xx][yy]=hp[i][j];hp[i][j]=0;
				flag1[xx][yy]=1;					//选为已经走过
			}
        }
}
void shua4(){									//用来刷新高级龙的走路，攻击，召唤魔龙的情况 
    int i,j,w,k,xx,yy,sj,z;
    arr1 a[5];
    memset(flag1,0,sizeof(flag1));
    spfa3(nowx,nowy,5);
    if(rand()%10==0)addlong();					//每过一定时间刷新魔龙，相当于召唤了龙群 
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
        if((f[i][j]==5)&&(flag1[i][j]==0)){				//如果是高级龙并且没有走过 
            w=0;
            if((rand()%5)==0){mljn(i,j);continue;}			//五分之一龙王（龙神）触发技能 
            for(k=0;k<4;k++){
                xx=i+dx[k];yy=j+dy[k];
                if(xx<=1||xx>=N||yy<=1||yy>=M)continue;
                if((f[xx][yy]==0)||(f[xx][yy]==2)||f[xx][yy]==1)w++,a[w].x=xx,a[w].y=yy,a[w].z=dist[xx][yy];
            }
			if(w){												//如果存在能走的路
				sort(a+1,a+w+1,sortcmp2);					//求出离玩家最近的
				xx=a[1].x;yy=a[1].y;
				if((xx==nowx)&&(yy==nowy)){
				    z=rand()%(manhp/7)+100;zjhp-=z;xx=i;yy=j;if(zjhp<0)zjhp=0;		//按玩家的百分比扣血 
				    setpos(N+1,0);for(k=1;k<=160;k++)printf(" ");
				    setpos(N+1,0);printf("龙王对你造成%d点伤害",z);ts=0;
				    setpos(N+2,0);for(k=1;k<=160;k++)printf(" ");
                    setpos(N+2,0);printf("等级 %d 血 %d/%d 攻 %d",level,zjhp,manhp,gongji);
				    if(zjhp<=0){loss();return;}
				    continue;
                }
                rewang(i,j);drawwang(xx,yy);		//移动高级龙 
				hp[xx][yy]=hp[i][j];hp[i][j]=0;		//怪物原来位置的hp清0,新的地点生成相应hp 
				flag1[xx][yy]=1;					//选为已经走过
			}
        }
}
void mljn(int longx,int longy){								//所有龙的技能 
	int fw=3,i,j,x,y,z,px=0;							//地震范围=3,px默认为0为地震 
	setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
	memset(ff,0,sizeof(ff));						
	color(12);if(rand()%4==0)px=1;				//龙吟情况
	setpos(N+1,0);
	if(px==1)fw=8,printf("魔龙发动龙吟");		//范围为8
		else if(px==0)printf("魔龙发动地震");				//范围为3 
	color(7);
	for(i=-fw;i<=fw;i++)						//枚举周围范围，类似银河爆碎 
		for(j=-fw;j<=fw;j++){
			if(abs(i)+abs(j)>fw)continue;
			x=longx+i;y=longy+j;
			if((x>=1)&&(x<=N)&&(y>=1)&&(y<=M)){
				if(f[x][y]==0){
					setpos(x-1,(y-1)*2);
					if(px==1)color(7);else color(12);//龙吟显示为灰色，地震为红色 
					printf("#");ff[x][y]=1;			//输出#号表示攻击范围 
				}
				if(f[x][y]==2){
					if(px)z=30;else z=rand()%50+10;					//龙吟固定伤害30，地震为10到59随机一个数 
					color(7);
					setpos(N+1,10);printf("对你造成%d点伤害",z);
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
    setpos(N+2,0);printf("等级 %d 血 %d/%d 攻 %d",level,zjhp,manhp,gongji);
}
void fazhao(){
	int i,j,x,y,fw,szpx=0;
	setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
	memset(ff,0,sizeof(ff));
	setpos(N+1,0);
	fw=rand()%6+2;									//随机出范围，2-8的周边 
	color(14);
	if(rand()%100<5)fw=120,printf("银河爆碎 - 时之咆哮 造成无限大伤害"),qp=1,szpx=1;//全屏伤害，百分之五机率打出来 
	else printf("银河爆碎");						//否则就是范围小一些的攻击空间 
	color(7);
	for(i=-fw;i<=fw;i++)
		for(j=-fw;j<=fw;j++){
			if(abs(i)+abs(j)>fw)continue;
			x=nowx+i;y=nowy+j;
			if((x>=1)&&(x<=N)&&(y>=1)&&(y<=M)){				//判断是在地图中
				if(f[x][y]==3)reguai(x,y),hp[x][y]=0,guais--,kill++;				//是怪就清
				if(f[x][y]==4)relong(x,y),hp[x][y]=0,mls--,killlong++;				//秒杀一切 
				if(f[x][y]==5)rewang(x,y),hp[x][y]=0,wang--,killwang++;				//龙王龙神同样秒 
				if((f[x][y]==0)||(f[x][y]==3)||(f[x][y]==4)||f[x][y]==5){		//是怪或空地就显示银河爆碎效果 
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
void fazhao2(){										//零枭首，平A，就是普通攻击 
	int x,y,i,j,z,sum=0,bj=0;
	memset(jineng,0,sizeof(jineng));
	setpos(N+1,0);for(i=1;i<=160;i++)printf(" ");
	setpos(N+1,0);color(3);printf("零枭首");ts=0;color(7);
	if(rand()%10==0)color(12),bj=1,printf("  爆击"),color(7);				//爆击的情况
	x=nowx;y=nowy;
	while(f[x-1][y]==0||f[x-1][y]==3||f[x-1][y]==4||f[x-1][y]==5)x--,jineng[x][y]=1;	//枚举四个方向
	x=nowx;y=nowy;
	while(f[x][y-1]==0||f[x][y-1]==3||f[x][y-1]==4||f[x][y-1]==5)y--,jineng[x][y]=1;
	x=nowx;y=nowy;
	while(f[x][y+1]==0||f[x][y+1]==3||f[x][y+1]==4||f[x][y+1]==5)y++,jineng[x][y]=1;
	x=nowx;y=nowy;
	while(f[x+1][y]==0||f[x+1][y]==3||f[x+1][y]==4||f[x+1][y]==5)x++,jineng[x][y]=1;
	z=rand()%10+gongji;if(bj)z=rand()%100+gongji*2;
	for(i=1;i<=N;i++)											//杀怪加画面
		for(j=1;j<=M;j++)
		if(jineng[i][j]==1){
			if(f[i][j]==3){										//是史莱姆的情况
				sum+=z;hp[i][j]-=z;
				if(hp[i][j]<=0)hp[i][j]=0,reguai(i,j),guais--,kill++,jy+=1;//经验加1 
			}
			if(f[i][j]==4){									  //是魔龙的情况
			    sum+=z;hp[i][j]-=z;
			    if(hp[i][j]<=0)hp[i][j]=0,relong(i,j),mls--,killlong++,jy+=15;  //魔龙20点经验
			}
			if(f[i][j]==5){
				sum+=z;hp[i][j]-=z;
				if(hp[i][j]<=0)hp[i][j]=0,rewang(i,j),wang--,killwang++,jy+=max(40,level*2);//超级单位经验加40起步，或者等级数*2 
			}
			if(f[i][j]==0){
				setpos(i-1,(j-1)*2);
				if(bj)color(12);else color(3);
				if(j==nowy)printf("|");
				if(i==nowx)printf("-");
			}
		}
	if(bj)color(12);else color(3);
	setpos(N+1,15);printf("共造成%d点伤害",sum);
	if(jy>=level){
        ts=0;color(6);printf("  升级");color(7);								//升级的情况 ，加点随机
	    while(jy>=level)jy-=level,level++,gongji+=rand()%5+7,manhp+=rand()%10+20,zjhp+=manhp/6;//消耗经验，等级提升 
	    if(zjhp>manhp)zjhp=manhp;									//升级最大hp上升，同时回血六分之一
	    setpos(N+2,0);for(i=1;i<=160;i++)printf(" ");
        setpos(N+2,0);printf("等级 %d 血 %d/%d 攻 %d",level,zjhp,manhp,gongji);
	}
	color(7);jngx=0;lengque=0;									//技能冷却
}
void shua2(){
	for(int i=1;i<=N;i++)										//零枭首冷却
		for(int j=1;j<=M;j++)
			if(jineng[i][j]==1){
				jineng[i][j]=0;
				if(f[i][j]==0)setpos(i-1,(j-1)*2),printf("  ");
			}
	lengque=1;												//冷却完成
}
void huihp(){												//用来给主角加血 
    zjhp+=level;if(zjhp>manhp)zjhp=manhp;					//按主角的等级数加血，后一句为了防止爆血 
    setpos(N+2,0);for(int i=1;i<=160;i++)printf(" ");
    setpos(N+2,0);printf("等级 %d 血 %d/%d 攻 %d",level,zjhp,manhp,gongji);			//同时刷新现在血的情况 
}
void work(){
	Sleep(10);js++;ts++;jngx++;sg++;huixue++;mltime++;wangtime++;		//用来控制画面更新
	if((wang==0)&&(killlong>=ls)&&(killlong>0)){
		ls+=1;
		for(int i=1;i<=level/10+1;i++)addwang();
	}
	if(wang&&(wangtime>=max(40-level/2,7)))shua4(),wangtime=0;//超级单位走路时间10-(40-level),最终7单位时间走一格(玩家66级时) 
	if(js>=50)shua(),js=0;									//史莱姆刷新为500毫秒 
	if(ts>=200){							//用来控制提示栏消失时间，持续2秒
		setpos(N+1,1);for(int i=1;i<=160;i++)printf(" ");
		ts=0;
	}
	if(jngx>=25)shua2(),jngx=0;//技能更新
	if(sg>=300){						//每过3秒刷一只史莱姆 
        setpos(N+1,0);for(int i=1;i<=160;i++)printf(" ");
        setpos(N+1,0);color(2);printf("地图上诞生一只新的史莱姆");ts=0;color(7);
        addguai();sg=0;
    }
    if(huixue>150)huihp(),huixue=0;					//每过1.5秒恢复一下血 
    if(mltime>=100){								//普通魔龙移动为1秒走一格 
		shua3();
        if(rand()%100==0)addlong();
        mltime=0;
    }
}
void zb(){                        //开启作弊模式
	char ch1[11];
	setpos(N,1);
	for(int i=1;i<=10;i++)ch1[i]=getch();		//读入10个字符，必须全部输对
		if(ch1[1]=='w'&&ch1[2]=='o')				//作弊码为wohenlihai 
			if(ch1[3]=='h'&&ch1[4]=='e'&&ch1[5]=='n')
				if(ch1[6]=='l'&&ch1[7]=='i'&&ch1[8]=='h')
					if(ch1[9]=='a'&&ch1[10]=='i'){
						//mciSendString("close mymusic", NULL, 0, NULL);
						//mciSendString("open music\\战斗.mp3 alias mymusic", NULL, 0, NULL);	// 打开音乐
						//mciSendString("play mymusic repeat", NULL, 0, NULL);				//循环播放
						zuobi=1;							//开启作弊
						setpos(N+1,1);for(int i=1;i<=160;i++)printf(" ");
						setpos(N+1,1);printf("你学会了银河爆碎,注意银河爆碎杀敌不获得经验 k");ts=0;	//显示已经开启，按键为k
					}
}
void printfiq(){											//输出怪物智商 
	setpos(N+1,1);for(int i=1;i<=160;i++)printf(" ");
	setpos(N+1,1);printf("怪的当前智商为%d",guaiiq*15);
	ts=0;
}
void jnlq(){												//技能尚未冷却 
	setpos(N+1,1);for(int i=1;i<=160;i++)printf(" ");
	setpos(N+1,1);printf("技能尚未冷却");ts=0; 				//技能冷却
}
void run(){												//用来读取玩家的输入，并判断 
	for(;;){
		work();
    	if(kbhit()){						//监听键盘输入 
			ch=getch();
			if(ch=='a'||ch=='A')                        //左
				if(judge(nowx,nowy-1))redraw(nowx,nowy),nowy--,draw(nowx,nowy),yourbs++;
			if(ch=='d'||ch=='D')                         //右
				if(judge(nowx,nowy+1))redraw(nowx,nowy),nowy++,draw(nowx,nowy),yourbs++;
			if(ch=='w'||ch=='W')                         //上
				if(judge(nowx-1,nowy))redraw(nowx,nowy),nowx--,draw(nowx,nowy),yourbs++;
			if(ch=='s'||ch=='S')                         //下
				if(judge(nowx+1,nowy))redraw(nowx,nowy),nowx++,draw(nowx,nowy),yourbs++;
			if(nowx==zhongx&&nowy==zhongy)win();        //到终点胜利
			if(ch=='n'||ch=='N')begin();               //重来一局
			if(ch=='p'||ch=='P')AI();                 //自动走
			if(ch=='g'||ch=='G')addguai();
			if((ch=='k'||ch=='K')&&(zuobi==1))fazhao();
			if((ch=='t'||ch=='T')){guaiiq++;if(guaiiq>10)guaiiq=10;printfiq();}   //调高怪的智商
			if((ch=='y'||ch=='Y')){guaiiq--;if(guaiiq<1)guaiiq=1;printfiq();}     //降低怪的智商
			if(ch=='j'||ch=='J'){							//技能
				if(lengque==1)fazhao2();						//如果能发
				else jnlq();									//否则提示
			}
			if(ch=='~')zb();					//开启作弊码模式 
		}
	}
}
int main(){
	srand(time(NULL));                             //开启随机参数 
    begin();										//创造地图 
    run();											//玩家输入 
    return 0;
}
