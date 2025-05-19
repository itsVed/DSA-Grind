class Solution {
public:
    string triangleType(vector<int>& arr) {
        string s ="none";
        
        if(arr[0] + arr[1] > arr[2] && arr[1] + arr[2] > arr[0] && arr[2] + arr[0] > arr[1] && arr[0]){
        
            if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[0]){
                s = "equilateral";
            }
            else if(arr[0] != arr[1] && arr[1] != arr[2] && arr[2] != arr[0]){
                s = "scalene";
            }
            else if(arr[0] == arr[1] || arr[1] == arr[2] || arr[2] == arr[0]){
                s = "isosceles";
            }
        }
        
        return s; 
    }
};