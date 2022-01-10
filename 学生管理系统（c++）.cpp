#include <iostream>
#include <queue>
#include <string>
#define N 1000
using namespace std;

class Student{
	private :
		string name;
		int num;
		int score;
	public :
		Student(string name,int num,int score):name(name),num(num),score(score){}
		
		void display(){
			cout<<"学号："<<num<<"  姓名："<<name<<"  成绩："<<score<<endl;
		}
		
		int getNum(){
			return this->num;
		}
		
		int getScore(){
			return this->score;
		}
		
		string getName(){
			return this->name;
		}
};

void welcome_teacher()
{
	printf("1、录入学生信息\n");
	printf("2、查看学生信息\n");
	printf("3、删除学生信息\n");
	printf("4、统计学生个数\n");
	printf("5、通过学号查找学生信息（折半查找非递归）\n");
	printf("6、通过姓名查找学生信息\n");
	printf("7、直接插入排序（按姓名排序）\n");
	printf("8、折半插入排序（按学号排序）\n");
	printf("9、快速排序（按学号排序）\n");
	printf("按任意键退出系统！\n");
}

//录入学生信息 
void input_information(int n,queue<Student> &s){
	int num,score;
	string name;
	for (int i=0;i<n;i++){
		cout<<"请输入学号：";
		cin>>num;
		cout<<"请输入姓名：";
		cin>>name;
		cout<<"请输入成绩：";
		cin>>score;
		Student stu(name,num,score);
		s.push(stu);
	}
}

//查看学生信息
void display(queue<Student> s){
	if (s.empty()){
		cout<<"没有学生信息！"<<endl;
		return ;
	}
	while (!s.empty()){
		s.front().display();
		s.pop();
	}
} 

//删除学生信息 
void deleted(queue<Student> &s,queue<Student> &s1){
	if (s.empty()){
		cout<<"暂无学生！"<<endl;
		return; 
	}
	int count1 = s.size();
	cout<<"请输入想要删除的学号：";
	int num;
	cin>>num;
	while (!s.empty()){
		s1.push(s.front());
		s.pop();
	}
	while (!s1.empty()){
		if (s1.front().getNum() == num){
			
		}else{
			s.push(s1.front());
		}
		s1.pop();
	}
	int count2 = s.size();
	if (count1==count2){
		cout<<"删除失败！"<<endl;
	}else{
		cout<<"删除成功！"<<endl;
	}
}

//统计学生个数
int count(queue<Student> s){
	return s.size();
} 

//通过学号查找(折半查找)
void find_num(queue<Student> s){
	int count = s.size();
	int num[count],score[count];
	string name[count];
	int k=0;
	while (!s.empty()){
		num[k] = s.front().getNum();
		score[k] = s.front().getScore();
		name[k++] = s.front().getName();
		s.pop();
	}
	int n;
	cout<<"请输入学号：";
	cin>>n;
	int i=0,j=count-1;		//i为low的下标	 j为high的下标 
	int low = num[i];
	int high = num[j];
	int mid=0;		//中间学号 
	while (i<=j){
		mid = (low+high)/2;
		if (n==mid){
			cout<<"学号："<<num[(i+j)/2]<<"  姓名："<<name[(i+j)/2]<<"  成绩："<<score[(i+j)/2]<<endl;
			return ;
		}else if (mid>n){
			high = num[--j];
		}else{
			low = num[++i];
		}
	}
	cout<<"无此学号！"<<endl;
}

//查找对应姓名的下标 
void find_name(queue<Student> s){
	cout<<"请输入姓名：";
	string name;
	cin>>name;
	while (!s.empty()){
		Student stu = s.front();
		if (name == stu.getName()){
			stu.display();
			return ;
		}
		s.pop();
	}
	cout<<"无此学生！"<<endl;
}

//直接插入排序（按姓名排序） 
void InsertSort(queue<Student> &s){
	if (s.empty()){
		cout<<"没有学生信息！"<<endl;
		return ;
	}
	int k=1;
	int total = s.size();
	string name[total+1];
	int score[total+1],num[total+1];
	//遍历队列 
	while (!s.empty()){
		name[k] = s.front().getName();
		score[k] = s.front().getScore();
		num[k++] = s.front().getNum();
		s.pop();
	}
	int j,i;
	for (i=2;i<=total;i++){
		name[0] = name[i];
		score[0] = score[i];
		num[0] = num[i];
		for (j=i-1;name[0]<name[j];j--){
			name[j+1] = name[j];
			score[j+1] = score[j];
			num[j+1] = num[j];
		}
		name[j+1] = name[0];
		score[j+1] = score[0];
		num[j+1] = num[0];
	}
	for (int n=1;n<=total;n++){
		Student stu(name[n],num[n],score[n]);
		s.push(stu);
	}
	cout<<"排序成功！"<<endl;
}

//折半插入排序（按学号排序）
void BInsertSort(queue<Student> &s){
	if (s.empty()){
		cout<<"没有学生信息！"<<endl;
		return ;
	}
	int k=1;
	int total = s.size();
	string name[total+1];
	int score[total+1],num[total+1];
	//遍历队列 
	while (!s.empty()){
		name[k] = s.front().getName();
		score[k] = s.front().getScore();
		num[k++] = s.front().getNum();
		s.pop();
	}
	int i,j,mid,low,high;
	for (i=2;i<=total;i++){
		name[0] = name[i];
		score[0] = score[i];
		num[0] = num[i];
		low=1;high=i-1;
		while (low<=high){
			mid = (low+high)/2;
			if (num[0]<num[mid]){
				high = mid-1;
			}else{
				low = mid+1;
			}
		}
		for (j=i-1;j>=high+1;j--){
			name[j+1] = name[j];
			score[j+1] = score[j];
			num[j+1] = num[j];
		}
		name[high+1] = name[0];
		score[high+1] = score[0];
		num[high+1] = num[0];
	}
	for (int n=1;n<=total;n++){
		Student stu(name[n],num[n],score[n]);
		s.push(stu);
	}
	cout<<"排序成功！"<<endl;
} 

//快速排序 
int partition(string name[],int num[],int score[],int lift,int right){
	name[0] = name[lift];
	num[0] = num[lift];
	score[0] = score[lift];
	int pivot = num[lift];
	while (lift<right){
		while (lift<right && num[right]>=pivot){
			right--;
		}
		name[lift] = name[right];
		num[lift] = num[right];
		score[lift] = score[right];
		while (lift<right && num[lift]<=pivot){
			lift++;
		}
		num[right] = num[lift];
		name[right] = name[lift];
		score[right] = score[lift];
	}
	num[lift] = num[0];
	name[lift] = name[0];
	score[lift] = score[0];
	return lift;
}

void sort(string name[],int num[],int score[],int lift,int right){
	int pivot;
	if (lift<right){
		pivot = partition(name,num,score,lift,right);
		sort(name,num,score,lift,pivot-1);
		sort(name,num,score,pivot+1,right);
	}
}

void Numsort(queue<Student> &s){
	if (s.empty()){
		cout<<"没有学生信息！"<<endl;
		return ;
	}
	int k=1;
	int total = s.size();
	string name[total+1];
	int score[total+1],num[total+1];
	//遍历队列 
	while (!s.empty()){
		name[k] = s.front().getName();
		score[k] = s.front().getScore();
		num[k++] = s.front().getNum();
		s.pop();
	}
	sort(name,num,score,1,total);
	for (int n=1;n<=total;n++){
		Student stu(name[n],num[n],score[n]);
		s.push(stu);
	}
	cout<<"排序成功！"<<endl;
}

int main()
{
	queue<Student> s,s1;
	int n=0,choice,flag = 1;
	while (1){
		if (flag==1){
			system("cls");
			welcome_teacher();
			cout<<"请选择：";
			cin>>choice;
			switch (choice){
				case 1:		//录入 
					cout<<"请输入学生数量：";
					cin>>n;
					input_information(n,s);
					system("pause");
					break;
				case 2:		//查看 
					display(s);
					system("pause");
					break;
				case 3:		//删除 
					deleted(s,s1);
					system("pause");
					break;
				case 4:		//统计个数
					 cout<<"学生个数为："<<count(s)<<endl;
					 system("pause");
					 break;
				case 5:		//通过学号查找
					find_num(s);
					system("pause");
					break;
				case 6:		//通过姓名查找
					find_name(s);
					system("pause");
					break; 
				case 7:		//直接插入排序（按姓名排序）
					InsertSort(s);
					system("pause");
					break;
				case 8:		//折半插入排序（按学号排序）
					BInsertSort(s);
					system("pause");
					break;
				case 9:		//快速排序
					Numsort(s);
					system("pause");
					break; 
				default :		//退出系统
					cout<<"感谢使用学生管理系统！再见！"<<endl;
					flag = 0;
					break;
			}
		}else{
			break;
		}
	}
}
