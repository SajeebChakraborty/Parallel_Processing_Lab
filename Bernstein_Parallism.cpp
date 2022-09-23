#include<bits/stdc++.h>

using namespace std;


int main(){

    int i,j,k,l,n,r;

    cout<<"Program Nmber: ";
    cin>>n;
    string out[n];
    int len[n];
    string in[n][10],str;

    for(i=0;i<n;i++){
        cout<<"Program order: ";
        cin>>str;
        l=str.size();
        out[i]=str[3];
        k=0;
        for(j=5;j<l;j=j+2){
           in[i][k]=str[j];
           k++;
        }
        len[i]=k;
    }

    for(i=0;i<n;i++){

        for(j=i+1;j<n;j++){
            int cnt=1;
            if(out[i]==out[j]){
                cnt=0;
            }
            if(cnt==1){
                for(k=0;k<len[i];k++){
                    if(in[i][k]==out[j]){
                        cnt=0;
                    }
                }
                for(r=0;r<len[j];r++){
                    if(in[j][r]==out[i]){
                        cnt=0;
                    }
                }

            }
            if(cnt==1){
                cout<<"P"<<i+1<<"||"<<"P"<<j+1<<endl;
            }

        }

    }



    return 0;
    /*P1:C=D*E
      P2:M=G+C
      P3:A=B+C
      P4:C=L+M
      P5:F=G/E */

}

