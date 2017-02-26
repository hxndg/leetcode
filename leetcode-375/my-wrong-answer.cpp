
      
/*
        vector<int> result;
        vector<int> geuseTimes;
        result.push_back(0);
        geuseTimes.push_back(0);
        for(int i = 1; i<n; i++){
            int minValue = INT_MAX;
            int geuse = INT_MAX;
            for( int j = 0; j<=i ;j++){
                int sumLeft = j + 1 + ((j == 0)?0:result[j-1]);
                int geuseLeft = 1 + ((j == 0)?0:geuseTimes[j-1]);
                int sumRight = j + 1 + ((j == i)?0:result[i-j-1] + (j+1)*geuseTimes[i-j-1]);
                int geuseRight = 1 + ((j == i)?0:geuseTimes[i-j-1]);
                int sum = max(sumRight,sumLeft);
                int tmp = 0;
                if(sumRight > sumLeft){
                    sum = sumRight;
                    tmp = geuseRight;
                }
                if(sumLeft > sumRight){
                    sum = sumLeft;
                    tmp = geuseLeft;
                }
                if(sumLeft == sumRight){
                    sum = sumLeft;
                    tmp = max(geuseLeft,geuseRight);
                }
                if(minValue == tmp){
                    geuse = min(geuse,tmp);
                }
                else{
                    minValue = min(minValue,sum);
                    if(minValue == sum){
                        geuse = tmp;
                    }
                }
            }
            result.push_back(minValue);
            geuseTimes.push_back(geuse);
        }
        return result[n-1];
      */
