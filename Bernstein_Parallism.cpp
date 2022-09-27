#include<bits/stdc++.h>

using namespace std;

int depen[7][15],len2[15];

int main(){

    int i,j,k,l,n,r,t;

    cout<<"Program Nmber: ";
    cin>>n;
    string out[n];
    int len[n];
    string in[n][10],str,depen_flow[n][15],depen_anti[n][15],depen_output[n][15];

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

        t=0;

        for(j=i+1;j<n;j++){
            int cnt=1;
            if(out[i]==out[j]){
                cnt=0;
                depen_output[i+1][t]="Output Dependency";
            }

            for(k=0;k<len[i];k++){
                if(in[i][k]==out[j]){
                    cnt=0;
                    depen_anti[i+1][t]="Anti Dependency";
                }
            }
            for(r=0;r<len[j];r++){
                if(in[j][r]==out[i]){
                        cnt=0;
                        depen_flow[i+1][t]="Flow Dependency";
                }
            }


            if(cnt==1){
                cout<<"P"<<i+1<<"||"<<"P"<<j+1<<endl;
            }
            else
            {
                 depen[i+1][t]=j+1;
                 t++;
                 len2[i+1]=t;

            }

        }

    }
    cout << "Dependency Graph" << endl;

    for(int i=1;i<=n;i++)
    {
        //cout << "P" << i << "-->";

        for(int j=0;j<len2[i];j++)
        {

            if(depen_flow[i][j]=="Flow Dependency")
            {

                cout << "P" << depen[i][j] <<  " " << depen_flow[i][j] << " on P" << i << endl;

            }
            if(depen_anti[i][j]=="Anti Dependency")
            {

                cout << "P" << depen[i][j] <<  " " << depen_anti[i][j] << " on P" << i << endl;

            }
            if(depen_output[i][j]=="Output Dependency")
            {

                cout << "P" << depen[i][j] <<  " " << depen_output[i][j] << " on P" << i << endl;

            }




        }
        cout << endl;


    }



    return 0;
    /*P1:C=D*E
      P2:M=G+C
      P3:A=B+C
      P4:C=L+M
      P5:F=G/E */

}

