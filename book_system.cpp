#include<iostream>
using namespace std;

class Book{
  public:
  int id;string title;bool issued;
  Book(){
    issued=false;
  }
  void input(){cout<<"BookID:";cin>>id;cout<<"Title:";cin>>title;}
  void display(){cout<<"ID:"<<id<<" "<<title<<" ";if(issued)cout<<"Issued\n";else cout<<"Avail\n";}
};

class User{
  public:
  int id;string name;Book* b;
  User(){ 
    b=NULL;}
  void input(){cout<<"UserID:";cin>>id;cout<<"Name:";cin>>name;}
  void borrow(Book* bk){
    if(b||bk->issued){
      cout<<"cant issue\n";return;}
    b=bk; 
    bk->issued=true;
}
  void ret(){if(b){b->issued=false;b=NULL;}}
};

int main(){
  Book* books[10];User* users[10];
  int bc=0,uc=0,ch;

while(1){
  cout<<"\n1.AddBook\n2.AddUser\n3.Issue\n4.Return\n5.ShowBooks\n6.Exit\n";
  cin>>ch;

  if(ch==1){
    books[bc]=new Book();
    books[bc++]->input();
  }

  else if(ch==2){
    users[uc]=new User();
    users[uc++]->input();}

else if(ch==3){
  int uid,bid;cout<<"uid:";cin>>uid;cout<<"bid:";cin>>bid;
  for(int i=0;i<uc;i++)
  if(users[i]->id==uid)
  for(int j=0;j<bc;j++)
  if(books[j]->id==bid)
  users[i]->borrow(books[j]);
}

else if(ch==4){
  int uid;cout<<"uid:";cin>>uid;
  for(int i=0;i<uc;i++)
  if(users[i]->id==uid)
  users[i]->ret();
}

else if(ch==5){
  for(int i=0;i<bc;i++)
  books[i]->display();
}

  else if(ch==6)break;
}
}
