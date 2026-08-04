#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size();          //This solution is AI generated, so next time, try doing it urself
    int n = nums2.size();          //TheWizardKingg

    int low = 0;
    int high = m;

    while (low <= high) {

        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {

            if ((m + n) % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            return max(left1, left2);
        }

        else if (left1 > right2) {
            high = cut1 - 1;
        }

        else {
            low = cut1 + 1;
        }
    }

    return 0;
}

int main(){
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}
