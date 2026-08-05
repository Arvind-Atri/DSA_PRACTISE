#include<iostream>
#include<unordered_map>
using namespace std;








int main(){

unordered_map<string,int>m;


pair<string,int>p=make_pair("Arvind",1);
m.insert(p);

pair<string,int>p1("Arvinda",2);
m.insert(p1);


m["sharma"]=3;

cout<<m["arvind"]<<endl;
cout<<m.at("sharma")<<endl;

cout<<m["1"]<<endl;  //create entry with zero 
cout<<m.at("1")<<endl;



cout<<m.count("arvind")<<endl; //returns if element  present or not?

cout<<m.size()<<endl; //return size(no of elements)
m.erase("arvind"); //remove an entry

cout<<m.size()<<endl; //return size(no of elements)

for(auto i:m){
    cout<<i.first<<"->"<<i.second<<endl;
}

// iterator
unordered_map<string,int>::iterator it=m.begin();
while(it!=m.end()){
    cout<<it->first<<"->"<<it->second<<endl;
    it++;
}

}