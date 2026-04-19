class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int dim = 0, dimsearch=true;

        while(dimsearch){
            dimsearch=false;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==dim){
                        dimsearch=true;
                        break;
                    }
                }
                if(dimsearch){
                    break;
                }
            }
            if(dimsearch){
                dim++;
            }
        }
        // cout<<dim<<endl;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++){
                        if(matrix[k][j]!=0){
                            matrix[k][j]=dim;
                        }
                    }
                    for(int k=0;k<m;k++){
                        if(matrix[i][k]!=0){
                            matrix[i][k]=dim;
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==dim){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
