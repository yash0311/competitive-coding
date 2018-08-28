// multiset approach

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        if(nums.size()==0) return res;
        
        multiset<int> s;
        for(int i=0;i<k;i++){
            s.insert(nums[i]);
        }
        auto it=s.begin(),it_max=s.begin();
        it_max=max_element(s.begin(),s.end());
        
        res.push_back((*it_max));
        
        for(int i=0;i<nums.size()-k;i++){
            int mx=0;
            s.insert(nums[k+i]);
            
            auto itr = s.find(nums[i]);
            s.erase(itr);
            
            mx=*max_element(s.begin(),s.end());
            res.push_back(mx);
        }
        return res;
    }
};

// dequeue approach

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // dequeue method
        
        vector<int> res;
        if(nums.size()==0) return res;
        
        deque<int> d(k);
        
        for(int i=0;i<k;i++){
            while((!d.empty()) && nums[i]>=nums[d.back()]) d.pop_back();
            d.push_back(i);
        }
        
        for(int i=k;i<nums.size();i++){
            res.push_back(nums[d.front()]);
            
            while((!d.empty()) && d.front()<=i-k) d.pop_front();
            while((!d.empty()) && nums[i]>=nums[d.back()]) d.pop_back();
            
            d.push_back(i);
        }
       res.push_back(nums[d.front()]);
        
        return res;
    }
};
