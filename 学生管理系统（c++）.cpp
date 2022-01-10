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
			cout<<"ѧ�ţ�"<<num<<"  ������"<<name<<"  �ɼ���"<<score<<endl;
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
	printf("1��¼��ѧ����Ϣ\n");
	printf("2���鿴ѧ����Ϣ\n");
	printf("3��ɾ��ѧ����Ϣ\n");
	printf("4��ͳ��ѧ������\n");
	printf("5��ͨ��ѧ�Ų���ѧ����Ϣ���۰���ҷǵݹ飩\n");
	printf("6��ͨ����������ѧ����Ϣ\n");
	printf("7��ֱ�Ӳ������򣨰���������\n");
	printf("8���۰�������򣨰�ѧ������\n");
	printf("9���������򣨰�ѧ������\n");
	printf("��������˳�ϵͳ��\n");
}

//¼��ѧ����Ϣ 
void input_information(int n,queue<Student> &s){
	int num,score;
	string name;
	for (int i=0;i<n;i++){
		cout<<"������ѧ�ţ�";
		cin>>num;
		cout<<"������������";
		cin>>name;
		cout<<"������ɼ���";
		cin>>score;
		Student stu(name,num,score);
		s.push(stu);
	}
}

//�鿴ѧ����Ϣ
void display(queue<Student> s){
	if (s.empty()){
		cout<<"û��ѧ����Ϣ��"<<endl;
		return ;
	}
	while (!s.empty()){
		s.front().display();
		s.pop();
	}
} 

//ɾ��ѧ����Ϣ 
void deleted(queue<Student> &s,queue<Student> &s1){
	if (s.empty()){
		cout<<"����ѧ����"<<endl;
		return; 
	}
	int count1 = s.size();
	cout<<"��������Ҫɾ����ѧ�ţ�";
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
		cout<<"ɾ��ʧ�ܣ�"<<endl;
	}else{
		cout<<"ɾ���ɹ���"<<endl;
	}
}

//ͳ��ѧ������
int count(queue<Student> s){
	return s.size();
} 

//ͨ��ѧ�Ų���(�۰����)
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
	cout<<"������ѧ�ţ�";
	cin>>n;
	int i=0,j=count-1;		//iΪlow���±�	 jΪhigh���±� 
	int low = num[i];
	int high = num[j];
	int mid=0;		//�м�ѧ�� 
	while (i<=j){
		mid = (low+high)/2;
		if (n==mid){
			cout<<"ѧ�ţ�"<<num[(i+j)/2]<<"  ������"<<name[(i+j)/2]<<"  �ɼ���"<<score[(i+j)/2]<<endl;
			return ;
		}else if (mid>n){
			high = num[--j];
		}else{
			low = num[++i];
		}
	}
	cout<<"�޴�ѧ�ţ�"<<endl;
}

//���Ҷ�Ӧ�������±� 
void find_name(queue<Student> s){
	cout<<"������������";
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
	cout<<"�޴�ѧ����"<<endl;
}

//ֱ�Ӳ������򣨰��������� 
void InsertSort(queue<Student> &s){
	if (s.empty()){
		cout<<"û��ѧ����Ϣ��"<<endl;
		return ;
	}
	int k=1;
	int total = s.size();
	string name[total+1];
	int score[total+1],num[total+1];
	//�������� 
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
	cout<<"����ɹ���"<<endl;
}

//�۰�������򣨰�ѧ������
void BInsertSort(queue<Student> &s){
	if (s.empty()){
		cout<<"û��ѧ����Ϣ��"<<endl;
		return ;
	}
	int k=1;
	int total = s.size();
	string name[total+1];
	int score[total+1],num[total+1];
	//�������� 
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
	cout<<"����ɹ���"<<endl;
} 

//�������� 
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
		cout<<"û��ѧ����Ϣ��"<<endl;
		return ;
	}
	int k=1;
	int total = s.size();
	string name[total+1];
	int score[total+1],num[total+1];
	//�������� 
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
	cout<<"����ɹ���"<<endl;
}

int main()
{
	queue<Student> s,s1;
	int n=0,choice,flag = 1;
	while (1){
		if (flag==1){
			system("cls");
			welcome_teacher();
			cout<<"��ѡ��";
			cin>>choice;
			switch (choice){
				case 1:		//¼�� 
					cout<<"������ѧ��������";
					cin>>n;
					input_information(n,s);
					system("pause");
					break;
				case 2:		//�鿴 
					display(s);
					system("pause");
					break;
				case 3:		//ɾ�� 
					deleted(s,s1);
					system("pause");
					break;
				case 4:		//ͳ�Ƹ���
					 cout<<"ѧ������Ϊ��"<<count(s)<<endl;
					 system("pause");
					 break;
				case 5:		//ͨ��ѧ�Ų���
					find_num(s);
					system("pause");
					break;
				case 6:		//ͨ����������
					find_name(s);
					system("pause");
					break; 
				case 7:		//ֱ�Ӳ������򣨰���������
					InsertSort(s);
					system("pause");
					break;
				case 8:		//�۰�������򣨰�ѧ������
					BInsertSort(s);
					system("pause");
					break;
				case 9:		//��������
					Numsort(s);
					system("pause");
					break; 
				default :		//�˳�ϵͳ
					cout<<"��лʹ��ѧ������ϵͳ���ټ���"<<endl;
					flag = 0;
					break;
			}
		}else{
			break;
		}
	}
}
