class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        if(a==""){
            ret = b;

        }   
        else if(b==""){
            ret = a;
        }
        else{
            int n=a.size(), m=b.size();
            if(a[n-1]=='1' && b[m-1]=='1'){
                string temp = addBinary(a.substr(0,n-1), "1");
                string temp2 = addBinary(b.substr(0,m-1), temp);
                ret = temp2+"0";
            }
            else{
                string temp = addBinary(a.substr(0,n-1), b.substr(0,m-1));
                if(a[n-1]=='0' && b[m-1]=='0'){     
                    ret = temp+"0";
                }
                else{
                    ret = temp+"1";
                }
            }
        }

        // cout<<a<<" "<<b<<" "<<ret<<endl;
        return ret;
    }
};