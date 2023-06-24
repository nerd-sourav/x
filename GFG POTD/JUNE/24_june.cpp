int count = 0;
        for(int i = 0; i < n; i++){
            int ok = 1;
            for(int j = 0; j < k; j++){
                if(arr[i][j] != str[j])
                    ok = 0;
            }
            
            count += ok;
        }
        
        return count;
