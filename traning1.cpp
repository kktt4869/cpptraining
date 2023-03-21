//#include<iostream>
//using namespace std;
//
//int main(){
//	int *A;
//	int n;
//	cin>>n;
//	A=new int[n*n];
//	memset(A,0x00,sizeof(int)*n*n);
//	
//	int iRow,iCol;
//	enum DIRECTION {DOWN = 0,LEFT,UP,RIGHT};
//	DIRECTION dir=DOWN;
//	iRow = 0;iCol = 0;
//	for(int k=1;k<=n*n;++k){
//		A[iRow*n+iCol] = k;
//		
//		switch(dir){
//			case DOWN:
//				if(iRow<n-1&&A[(iRow+1)*n+iCol]==0){
//					++iRow;
//				}else{
//					dir = RIGHT;
//					++iCol;
//				}
//				break;
//			case LEFT:
//				if(iCol>0&&A[iRow*n+iCol-1]==0){
//					--iCol;
//				}else{
//					dir = DOWN;
//					++iRow;
//				}
//				break;
//			case UP:
//				if(iRow>0&&A[(iRow-1)*n+iCol]==0)
//					--iRow;
//				else{
//					dir=LEFT;
//					--iCol;
//				}
//				break;
//			case RIGHT:
//				if(iCol<n-1&&A[iRow*n+iCol+1]==0)
//					++iCol;
//				else{
//					dir=UP;
//					--iRow;
//				}
//				break;
//		}
//	}
//	
//	for(iRow = 0; iRow<n; ++iRow){
//		for(iCol=0;iCol<n;++iCol){
//			cout.width(4);
//			cout<<A[iRow*n+iCol];
//		}
//		cout<<endl;
//	}
//	delete []A;
//}

//单链表的构造、插入、删除
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void Insert(Node *la,int x);
void Destory(Node *la);
void Print(Node *la);
void MergeList(Node* La,Node* Lb);
//void MergeList(Node* La,Node* Lb);

int main(){
	//头节点
	Node *la= new Node;
	la->next = NULL;
	
	Node *lb= new Node;
	lb->next = NULL;
	
	int n;	
	cin >>n;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x>0)
			Insert(la,x);
		else if(x<0)
			Insert(lb,x);
	}
	
	
	Print(la);
	Print(lb);
	
	MergeList(la,lb);
	Print(la); //打印合并后的链表
	
	Destory(la);
	Destory(lb);
	
	return 0;
}

void Insert(Node *la,int x){
	Node *q=new Node;
	q->data =x;
	
	Node *p=la;
	while(p->next&&x>p->next->data)
		p=p->next;
	q->next=p->next;
	p->next=q;
}

void Destory(Node *la){
	while(la){
		Node *q=la->next;
		delete la;
		la=q;
	}
}

void Print(Node *la){
	la=la->next;
	if(la){
		cout<<la->data;
		la=la->next;
	}
	while(la){
		cout<<"->"<<la->data;
		la=la->next;
	}
	cout<<endl;
}

void MergeList(Node* La,Node* Lb){
    Node *s=La,*pa=La->next,*pb=Lb->next;//s指向表尾结点,初始指向表头空结点。
    La->next=NULL;  //将结果链表初始化为空。新链表直接用La的空间，不占用其他空间。
//    s->next=La;
    
	while(pa&&pb){
   		if(pa->data<=pb->data){
           s->next=pa; //将s指向pa
           s=pa; //更新表尾结点    
           pa=s->next;//更新pa
       }
       else{
           s->next=pb; //将s指向pb
           s=pb;
           pb=s->next;
       }
   }
    if(pa)
        pb=pa;
    while(pb){
        s->next=pb; //将s指向pb
        s=pb;
        pb=s->next;
    }
    s->next = NULL;
}