class Solution {
public:
    int takeCharacters(string s, int k) {
        
        //Storing frequencies of characters
        int count_a = 0;
        int count_b = 0;
        int count_c = 0;

        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                count_a++;
            }
            else if(s[i] == 'b'){
                count_b++;
            }
            else{
                count_c++;
            }
        }

        //No possible way
        if(count_a < k || count_b < k || count_c < k){
            return -1;
        }

        int i = 0;
        int j = 0;

        int maxWindowToDeleted = -1;

        while(j < n){

            if(s[j] == 'a'){
                count_a--;
            }
            else if(s[j] == 'b'){
                count_b--;
            }
            else{
                count_c--;
            }

            //Shrinking window 
            while(i <= j && (count_a < k || count_b < k || count_c < k)){
                if(s[i] == 'a'){
                    count_a++;
                }
                else if(s[i] == 'b'){
                    count_b++;
                }
                else{
                    count_c++;
                }
                i++;
            }

            //Calculate result
            maxWindowToDeleted = max(maxWindowToDeleted, j - i + 1);
            j++;

        }

        //Return ans
        return n - maxWindowToDeleted;
    }
};