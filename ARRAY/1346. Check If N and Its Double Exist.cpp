class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {

        // for(int i=0;i<arr.size();i++){
        //     for(int j=0;j<arr.size();j++){
        //         if(i!=j and arr[i]==2*arr[j]) return true;
        //     }
        // }
        // return false;

        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
        {
            if (m.find(arr[i] * 2) != m.end())
            {
                return true;
            }
            else if (arr[i] % 2 == 0 and m.find(arr[i] / 2) != m.end())
                return true;
            m[arr[i]] = i;
        }
        return false;
    }
};