#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<functional>
#include<map>
#include<Unordered_map>
#include<set>
#include<unordered_set>
using namespace std;

bool compartor(pair<int,int> p8,pair<int,int> p9){
        bool check=false;
        if(p8.second!=p9.second){
            if(p8.second<p9.second){
             check=true;
        }
        else{
             check=false;
        }
        }
        else{
            if(p8.first<p9.first){
                check=true;
            }
            else{
                check=false;
            }
        }
        
        return check;
    }


int main(){
    // Sequence Containers or Sequential Containers
    // Vectors
    cout<<"Sequence Containers or Sequential Containers"<<endl;
    cout<<endl;
    cout<<"Vector:"<<endl;
    cout<<endl;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.emplace_back(5);
    vec.pop_back();
    for(int val:vec){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"Vector capacity: "<<vec.capacity()<<endl;
    cout<<"Vector Size: "<<vec.size()<<endl;
    cout<<"Value at index 2: "<<vec.at(2)<<endl;
    cout<<"Value at index 2: "<<vec[2]<<endl;
    cout<<"First Value of Vector: "<<vec.front()<<endl;
    cout<<"Last Value of Vector: "<<vec.back()<<endl;

    vector<int> A={6,7,8,9,10};
    vector<int> B(4,9);
    vector<int> C(A);

    for(int i:A){
        cout<<i<<" ";
    }
    cout<<endl;

    for(int j:B){
        cout<<j<<" ";
    }
    cout<<endl;

    for(int k:C){
        cout<<k<<" ";
    }
    cout<<endl;

    vector<int> vec1={11,12,13,14,15,16,17};
    vec1.erase(vec1.begin());
    // vec1.erase(vec1.begin()+2);
    // vec1.erase(vec1.begin()+1,vec1.begin()+3);
    vec1.insert(vec1.begin()+4,200);
    vec1.clear();
    cout<<"Vector is empty: "<<vec1.empty()<<endl;
    cout<<"Vector capacity: "<<vec1.capacity()<<endl;
    cout<<"Vector Size: "<<vec1.size()<<endl;
    for(int value:vec1){
        cout<<value<<" ";
    }
    cout<<endl;

    // Iterators
    cout<<"Iterators:"<<endl;
    cout<<endl;
    vector<int> vec2={1,9,7,5,3};
    cout<<"Begin Value: "<<*(vec2.begin())<<endl;
    cout<<"Ending Value: "<<*(vec2.end())<<endl;

    vector<int> :: iterator it;
    for(it=vec2.begin();it!=vec2.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    vector<int> :: reverse_iterator itr;
    for(itr=vec2.rbegin();itr!=vec2.rend();itr++){
        cout<<*(itr)<<" ";
    }
    cout<<endl;

    for(vector<int> :: iterator it=vec2.begin();it!=vec2.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    for(vector<int> :: reverse_iterator itr=vec2.rbegin();itr!=vec2.rend();itr++){
        cout<<*(itr)<<" ";
    }
    cout<<endl;

    for(auto it=vec2.begin();it!=vec2.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

     for(auto itr=vec2.rbegin();itr!=vec2.rend();itr++){
        cout<<*(itr)<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"List:"<<endl;
    cout<<endl;
    

    // List
    list<int> l;
    list<int> l1={8,7,9,5,3};
    list<int> l2(6,7);
    list<int> l3(l1);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(4);
    l.push_front(5);

    l.pop_back();
    l.pop_front();

    for(int value:l){
        cout<<value<<" ";
    }
    cout<<endl;

    for(int val:l1){
        cout<<val<<" ";
    }
    cout<<endl;

    for(int value1:l2){
        cout<<value1<<" ";
    }
    cout<<endl;
    cout<<endl;

    // cout<<l[2]<<endl; this line generate error because it is not possible in list
    //  container because data stored in the list is in doubly linked list
    //  which means we can't acces any random index value or index.

    // All functions that are used in vectors are also applicable in List 
    // Like emplace_front , emplace_back , insert, erase, clear,begin, 
    // rbegin, rsend ,front, back


    // Deque
    // There is a difference between the deque and dequeue. 
    // deque is double ended Queue But the Dequeue is to 
    // pop_front and pop_back means in simple to delete any number
    //  from the any container. Container like list, deque, map,vector etc 

    cout<<"Deque:"<<endl;
    cout<<endl;
    deque<int> d;
    deque<int> d1={8,7,9,5,3};
    deque<int> d2(6,7);
    deque<int> d3(d1);
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(4);
    d.push_front(5);

    d.pop_back();
    d.pop_front();

    for(int value:d){
        cout<<value<<" ";
    }
    cout<<endl;

    for(int val:d1){
        cout<<val<<" ";
    }
    cout<<endl;

    for(int value1:d2){
        cout<<value1<<" ";
    }
    cout<<endl;

    cout<<d[2]<<endl;
    cout<<endl; //  this is possible in deque but not in the list 
    // i try this in list above to proof this
    //  because it is not possible in list container because data stored in the list
    //  is in dynamically arrays which means 
    // we  acces any random index value or index.

    // All functions that are used in vectors are also applicable in Deque
    // Like emplace_front , emplace_back , insert, erase, clear,begin, 
    // rbegin, rsend ,front, back

    cout<<"Pair:"<<endl;
    cout<<endl;

    // Pair
    pair<int,int> p={1,2};
    pair<string,float> p1={"Scarface",2.3f};
    pair<int,pair<int,char>> p2={1,{3,'w'}};
    // We also add pair in vectors 
    vector<pair<int,int>> v={{1,1},{2,2},{3,3}};
    vector<pair<int,string>> vect={{1,"Mirza"},{2,"Awais"},{3,"Raza"}};

    // This is the difference between the push back and the emplace back 
    v.push_back({4,4}); //Assumes object already created. It just insert it.

    // v.pushback(4,4); here i can't used {} braces due to this i got error.
    //  why because push back doesn't create or change it into order pair. 
    // it just insert anything like if we give pair{4,4} inside push back 
    // but here without {} it can't identify it is pair or something 
    // that's way it cause error. 
    // On the other hand if we give this in emplace back this pair 4,4 without {} 
    // or other datatype, We can't need to specify means no need to use {}
    //  it automatically identify this and then create or change this into pair

    vect.emplace_back(4,"Baig"); //make the object and then insert 

    cout<<p.first<<" "<<p.second<<" "<<endl;
    cout<<p1.first<<" "<<p1.second<<" "<<endl;
    cout<<p.first<<" "<<p2.second.first<<" "<<p2.second.second<<" "<<endl;

    for(pair<int,string> a: vect){
        cout<<a.first<<" "<<a.second<<" "<<endl;
    }

    for(auto a: v){
        cout<<a.first<<" "<<a.second<<" "<<endl;
    }

    // Non Sequential Container:

    cout<<"Non-Sequence Containers or Sequential Containers"<<endl;
    cout<<endl;
    // Stack
    // The main thing important is that stack based on LIFO.
    //  LIFO stand for Last In First Out means the thing we add first come out from the stack at last.
    // And the thing or data store at last come out first. 
    // If we delete something from the stack it delete the top data
    //  in below case in which i add 1,2,3,4,5 the top thing is 5 due to LIFO.
    //  and when we delete firstly 5 delete and then 4
    //  and then 3 and move on to 1 at last.


    stack<int> s;
    stack<int> s1; 
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);

     cout<<"Top number or data on the stack:"<<" "<<s.top()<<endl;

     cout<<"Size of s Before Swapping: "<<s.size()<<endl;
     cout<<"Size of s1 Before Swapping: "<<s1.size()<<endl;

    // We store these values 1,2,3,4,5 but the output we get is 5,4,3,2,1
    // This is all due to LIFO. The last digit means 5 come first and 1 at last

    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // cout<<endl;

    // while(!s1.empty()){
    //     cout<<s1.top()<<" ";
    //     s1.pop();
    // }

    cout<<endl;
    // We got Empty yes because in loop we pop means delete all the elements 
    // After printing one by one.
    cout<<"Stack is empty or not(1 for yes or 0 for No): "<<s.empty()<<endl;

    // There are also  emplace,empty,size and swap functions for stack

    // Before swapping the size of s is 5 and the size of s1 is 4 
    // After swapping the size of s is 4 and the size of s1 is 5
    // Now all the elements swap of s and s1;

    
    s1.swap(s);

    cout<<"Size of s After Swapping: "<<s.size()<<endl;
    cout<<"Size of s1 After Swapping: "<<s1.size()<<endl;
    // There loops are just for checking the swapping the elements is done or not.

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }

    
    // Queue
    queue<int> q;
    // It is opposite of Stack means Stack work or based on LIFO 
    // but the Queue based or work on FIFO means First In First Out
    // So all the details i discussed in the Stack are opposite in queue
    //  so read the stack and then you understand how queue works
    // e.g if i pop or delete a number from the stack then the last or top element 
    // on the stack delete and then so on to first one. One by One. 
    // But in case of queue if i pop an element then the first one element deleted
    //  due to FIFO. Not the last or top one. In this way it is opposite 

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // The values print in 1,2,3,4,5 due to FIFO in Queue
    // But in Stack it print like 5,4,3,2,1 due to LIFO

    // There are also  emplace,empty,size and swap functions for Queue
    cout<<"Front or first element of Queue"<<q.front()<<endl;
    cout<<"Size of Queue:"<<q.size()<<endl;
    cout<<"Empty or not(1 or 0): "<<q.empty()<<endl;

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;

    // Priority Queue For this we need #include<queue> import from STL 
    // In priority Queue the data stored in priority vise
    //  means the priority based on CBT(Complete Base Tree). 
    // The overall structure is based on tree.
    // Tree means there are child and parent relations.
    //  in which data is stored in MaxHeap and in MinHeap. 
    // MaxHeap means there is maximum value at the top and 
    // teh MinHeap means minimum value at the top.
    // In default the data  stored in MaxHeap form or use MaxHeap. 
    // Which means according to my example i push data or elements 
    // in the priority queue like 1,20,5,9,7 but actually the data stored is like
    //  and the data print is like 20,9,7,5,1 means in greater sorting order.
    // Because MaxHeap store the maxmium value at the top.
    //  Its opposite is MinHeap means it store data in minimum sorting order.
    // Because MinHeap store minimum value at the top. The data stored and print like 
    // 1,5,7,9,20


    
    priority_queue<int> pq;
    // This is the syntax for MaxHeap.

    pq.push(1);
    pq.push(20);
    pq.push(5);
    pq.push(9);
    pq.push(7);


    priority_queue<int, vector<int>, greater<int>> pq1;
    // This is the syntax for MinHeap.
    

    pq1.push(1);
    pq1.push(20);
    pq1.push(5);
    pq1.push(9);
    pq1.push(7);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<endl;

    // There are also emplace,empty,size and swap functions for Priority Queue

    map<string,int> m;

    // The follwing lines  m["TV"]=100; is the syntax for adding key and value in map.
    // It also use insert and emplace functions. It behave like a pair.
    //  Because we give two things in map . 
    // First key which is unique in simple map not in multiple map.
    // and second is key. Which may or may not be same.
    // Also it stores and print data in sorting form. 
    // like in my example i give key string and value in int,
    // when i print firstly camera and its values print then the other 
    // because 'c' comes first in alphabets or in ASCII values.
    // This rule apply on all the elements that are inserted or emplaced or added.

    m["Tv"]=100;
    m["laptop"]=50;
    m["Remote"]=70;
    m["Controller"]=30;
    m["Camera"]=120; 

    // The reason why i used {} braces in insert function but not in emplace
    // It is the difference that i explained in pairs topic.

    // There are also functions of size find, erase etc.

    m.insert({"CPU",88});
    m.erase("CPU");
    m.emplace("Graphic Card",44);

    cout<<"Count:"<<m.count("Remote")<<endl; 
    //This line gives key count not the value so the key count is 1.Because 1 key of named Remote stored in map.

    cout<<"Count:"<<m["Remote"]<<endl; 
    // This line gives count of value which is 70. 
    // there is syntax difference of how to print count of key and count of value.

    for(auto p:m){ //Here auto p tells that it is pair and auto keyword automatically
        //  tell the compiler that it is pair.
        // If we don't use auto we write the long syntax which is lengthy. 
        // Soi prefer this.
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;

    if(m.find("Graphic Card") != m.end()){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }


    // Types of Maps
    // MultiMap

    multimap<string,int> multi;

    // m["Tv"]=100;
    // m["laptop"]=50;
    // m["Remote"]=70;
    // m["Controller"]=30;
    // m["Camera"]=120; Not allowed to use square bracket.
    //  We only use emplace or insert for adding data

    multi.emplace("tv",50);
    multi.emplace("tv",50);
    multi.emplace("tv",50);
    multi.emplace("tv",50);
    multi.emplace("tv",50);
    // In this way i create multiple or duplicate keys of named tv. 
    // It is only possible in multimap not in simple map.

    // multi.erase("tv");
    // This line delete all the keys named tv.

    multi.erase(multi.find("tv"));
    // This line only delete one tv named key.
    // Because iterator gives the single address where tv stored 
    // so tv stored in five place
    //  in this way only one tv is removed and we get output of 4 tv keys and values.

    for(auto p1:multi){
        cout<<p1.first<<" "<<p1.second<<endl;
    }
    cout<<endl;

    // Unordered Map
    // We need import for simple map and unordered map but not for multimap

    // There is difference between the simple map , multimap and unordered map. 
    // In simple and unordered map square braces [] allowed to insert data
    //  and in both of that maps repetation is not allowed. 
    // There is  a big difference b/w simple and multimap.
    //  In simple map data stored in sorted form but in unordered map 
    // the name is unorderd so data stored in unsorted form.
    // In multimap repetation is allowed but square braces [] are not allowed.
    // WE only enter data through insert and emplace. 
    // this syntax multimap[key]=value not allowed in multimap.
    // repetation means we store same keys in map.
    // Key is unique in simple map and unordered map but the value is not unique 
    // it may or may not be repeated.
    // Key  and value in multimap  are both repeated.

    unordered_map<string,int> unorder;
    unorder["laptop"]=50;
    unorder["laptop"]=50;
    unorder["laptop"]=50;
    unorder["laptop"]=50;
    unorder["laptop"]=50;
    
    // I write the above laptop key for five times. In simple and unordered map 
    // it is not allowed in such a way 
    // that we can write for multiple times of same key but it print only one time.
    //  run and check that one .But in multimap it print for five times 
    // this is how it is allowed in multimap.

    unorder["Bag"]=70;
    unorder["Keyboard"]=120;
    unorder["Mouse"]=50;
    unorder["Earphone"]=90;

    for(auto p2:unorder){
        cout<<p2.first<<" "<<p2.second<<endl;
    }
    cout<<endl;

    // There are also functions like size, insert, emplace, empty, count ,erase etc.
    // Unordered is the most used map from two of them.

    // Set
    set<int> se;
    // We added data in set through insert and emplace functions
    // The main thing we already know is that data stored in set 
    // is distinct or well defined means there is no repetation.
    // if we write data in repetation form it print or store data once.
    // Run the code and check.
    se.insert(1);
    se.insert(2);
    se.insert(3);
    se.insert(4);
    se.insert(5);

    // Here i write data in repetation but the data show
    //  in ouput or stored is non-repeative. 

    se.insert(1);
    se.insert(1);
    se.insert(1);
    se.insert(1);
    se.insert(1);

    // Here what is auto i completely described it above.

    for(auto p3: se){
        cout<<p3<<" ";
    }
    cout<<endl;

    // let's discuss upper and lower bound in set
    // Upper bound must print data greater to the given value.
    // Lower bound print data equal or greater to the given value.
    // It print equal if the value is available otherwise greater.
    // In both bounds greater means not the greatest among all of them.
    // greater means one step higher. e.g: the set is {1,2,3,4,5}
    // If i give se.upperbound(2). it print 3 because it must give greater than value.
    // If i give se.Lowerbound(3). it print 2 if it is available in the set 
    // otherwise 4 because it  give greater than value. due to not presence of 3.
    // In this way greater is not mean the greater value is 5. 
    // greater means one step higher.

    cout<<"Upper_Bound:"<<*(se.upper_bound(2))<<endl;
    cout<<"Lower_Bound:"<<*(se.lower_bound(4))<<endl;

    // There are also functions of erase,size,find,empty,count etc.

    // Types of Sets
    // Multiset(No import needed)
    // In multiset repetation is printed and in sorted form.

    multiset<int> mul;
    mul.insert(1);
    mul.insert(1);
    mul.insert(1);
    mul.insert(1);
    mul.insert(1);
    
    mul.insert(2);
    mul.insert(3);
    mul.insert(4);

    for(auto p4:mul){
        cout<<p4<<" ";
    }
    cout<<endl;
    
    

    // unorderedset(import needed).
    //  Like simple set repetation is not printed or allowed but in random order.
    // One thing important is that we can't calculate lower and upper bound 
    // in the unorderd set.Because they are only calculated 
    // when the data in properly sorted. 
    // Due to random form of data in unordered set.
    //  Both of the bounds are not possible.

    unordered_set<int> unset;
    unset.insert(1);
    unset.insert(2);
    unset.insert(3);
    unset.insert(4);

    unset.insert(4);
    unset.insert(4);
    unset.insert(4);
    unset.insert(4);

    for(auto p5:unset){
        cout<<p5<<" ";
    }
    cout<<endl;

    // The difference between the simple , multi and unordered set is same like maps.
    // I explain it completely a very few things are changed. 

    // Algorithms

    // Sorting algorithm
    // These are automatically sorted in asending order by sort function.
    int arr[5]={1,6,3,2,5};

    // The general form is sort(arr,arr+n); In given array 'n' is 5;
    sort(arr,arr+5);// Here pointer "arr", "arr+n" is used

    for(int arra:arr){
        cout<<arra<<" ";
    }
    cout<<endl;

    vector<int> v1={3,6,7,1,2};

    sort(v1.begin(),v1.end()); //Here iterator "begin" and "end" is used

    for(int k:v1){
        cout<<k<<" ";
    }

    cout<<endl;


    //For descending sorting we must pass a compartor or functor
    // In this example of descending sorting compartor or functor is greater.
    int arr1[5]={1,6,3,2,5};

    // The general form is sort(arr,arr+n); In given array 'n' is 5;
    sort(arr1,arr1+5,greater<int>());// Here pointer "arr", "arr+n" is used

    for(int arra:arr1){
        cout<<arra<<" ";
    }
    cout<<endl;

    vector<int> v12={3,6,7,1,2};

    //sort(v12.begin(),v12.end(),greater()); //Here iterator "begin" and "end" is used

    for(int k:v12){
        cout<<k<<" ";
    }

    cout<<endl;


    // sorting vectors in form of pairs
    // This is vector with pairs sorting.
    // In this default sorting the pairs sorted according to first value of each pair.
    // run and check the output

    vector<pair<int,int>> v2={{1,2},{3,1},{7,7},{2,5}};

    sort(v2.begin(),v2.end());

    for(auto value2:v2){
        cout<<value2.first<<" "<<value2.second<<endl;
    }
    cout<<endl;

    // For specific sorting means pairs are sorted
    //  depending upon our first value of pair and the second value of pair.
    // we firstly make our custom compartor and then use it for sorting.
    // I create custom comparator on the top of the file before main()

    vector<pair<int,int>> v3={{1,8},{3,1},{7,2},{2,1},{8,1}};

    sort(v3.begin(),v3.end(),compartor);

    for(auto value2:v3){
        cout<<value2.first<<" "<<value2.second<<endl;
    }
    cout<<endl;

    // Reverse
    vector<int> rev={1,2,3,4,5};
    vector<int> rev1={1,2,3,4,5};
    // This is for overall reverse
    cout<<"Overall or Normal reverse:"<<endl;
    reverse(rev.begin(),rev.end());
    for(int value3:rev){
        cout<<value3<<" ";
    }
    cout<<endl;

    // In order to reverse specific elements 
    reverse(rev1.begin()+1,rev1.begin()+3); //Why begin()+3 
    // because the ending is not included means here for terminate condition
    //  4 is not included. only 2,3 are revered. 
    // This is for ending condtion not the first. In reverse(rev.begin+1,rev.begin+3).
    //  rev.begin+1 is first and rev.begin+3 is terminate condition
    // This line reverse only 2,3 because we only specify them
    cout<<"Specific Reverse:"<<endl;
    for(int value4:rev1){
        cout<<value4<<" ";
    }
    cout<<endl;

    // Permutation
    // We use vectors or string etc.
    // previous Permutation:
    string str="abc";
    string str1="xyz";
    prev_permutation(str1.begin(),str1.end());
    cout<<"Previous_Permutation:"<<str1<<endl;
    // Next Permutation:
    next_permutation(str.begin(),str.end());
    cout<<"Next_Permutation:"<<str<<endl;

    // There also functions of min , max and swap

    int a=10;
    int b=50;
    cout<<"Minimum :"<<min(a,b)<<endl;
    cout<<"Maximum:"<<max(a,b)<<endl;
    swap(a,b);
    cout<<"a:"<<a<<" "<<"b:"<<b<<endl;

    // Min element and Max element functions
    // These functions are specially for vectors
    vector<int> v5={1,8,3,5,9};
    cout<<"Minimum element :"<<*(min_element(v5.begin(),v5.end()))<<endl;
    cout<<"Maximum element:"<<*(max_element(v5.begin(),v5.end()))<<endl;

    // Binary Search
    vector<int> bin={1,2,5,7,3};
    cout<<binary_search(bin.begin(),bin.end(),5)<<endl;
    // In this function we pass two iterators and the value or key i want to search
    // The function provide in boolean form means 0 or 1. 0 for false or 1 for true.

    // Set count bits functions
    // Set count bits functions are used to count the amount of 1 in the given number.
    // e.g; a= 15 it convert into binary form and count how much 1 it contain and then
    // provide us output
    // frequency means amount.
    int a11=15;
    long int b22=20;
    long long int c33=60;
    cout<<"frequency of 1 in a:"<<__builtin_popcount(a11)<<endl;
    // For simple we can't add any l because it is int not any type of long
    cout<<"frequency of 1 in b:"<<__builtin_popcountl(b22)<<endl;
    // Here i add small 'l' for long int 
    cout<<"frequency of 1 in c:"<<__builtin_popcountll(c33)<<endl;
    // Here i add small 'l' for two times for  long long  int 

    return 0;
}
