
// we used here linked list data structure 
// and maintained map of pointers 
// also has a set<int> thart will tell us if there are already values 
// why we chose list over vector, because erase via address value in vector causes re alloaction in memoery may cause error.
// where we know in Linked lIst which is non contiguous data structure 
// will act differently and efficiently 


#include <bits/stdc++.h>
class DataStream {
public:
    
    typedef list<int>::iterator iter;
    list<int> vec;
    set<int> s;
    map<int,iter> m;

    DataStream(){
        vec.clear();
        s.clear();
        m.clear();
      
    }
    
    void add(int value) {

        if (s.count(value)) return;

        if (m.count(value)) {
            // cout<<*m[value]<<endl;
            vec.erase(m[value]);
            s.insert(value);
        } else {
            vec.push_back(value);
           auto it = prev(vec.end());
           m[value]=it;
        }
    }

  
    int firstUnique() {
      return (vec.size()?vec.front():-1);
    }
};