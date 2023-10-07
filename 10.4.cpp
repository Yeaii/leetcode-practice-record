#include <bits/stdc++.h>
using namespace std;
//合并两个有序数组
class Solution1{
public:
    void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
    //m,n分别为数组nums1,nums2的长度
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];//先将nums2的元素追加在nums1之后
        }  
        sort(nums1.begin(),nums1.end());//对nums1快速排序  
    }
};//时间复杂度：O((m+n)log(m+n))。
  //空间复杂度: O(log(m+n))

class Solution2{
public:
     void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
        int p1=0,p2=0;//定义两个指针
        int sorted[m+n];
        int cur;
        while(p1<m||p2<n){
            if(p1==m){
                cur=nums2[p2++];
            }else if(p2==n){
                cur=nums1[p1++];
            }else if(nums1[p1]<nums2[p2]){
                cur=nums1[p1++];
            }else{
                cur=nums2[p2++];
            }
            sorted[p1+p2-1]=cur;
        }
        for(int i=0;i!=m+n;++i){
            nums1[i]=sorted[i];
        }
     }
};
//将两个数组看作队列，每次从两个数组头部取出比较小的数字放到结果中
//时间复杂度：O(m+n)
//空间复杂度：O(m+n)


//逆向双指针
class Solution3 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};
//时间复杂度：O(m+n)。 
//空间复杂度：O(1)。 

