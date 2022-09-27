#include<bits/stdc++.h>
using namespace std;

int reservation_table[10][10];

int main(){

    int i,j,k,l,n,m;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>m>>n;

    int store[n+1]={0};

    for(i=1;i<=m;i++){

        for(j=1;j<=n;j++){

            cin>>reservation_table[i][j];

        }

    }
    for(i=1;i<=m;i++){

        for(j=1;j<=n;j++){

            if(reservation_table[i][j]==1 && j!=1){

                for(k=j;k>=1;k--){

                    int s ;
                    s = reservation_table[i][j]-reservation_table[i][k];
                    if(s==0){

                        l = j-k;
                        store[l] = 1;

                    }

                }

            }

        }

    }
    int max_forbidden_lattency=0;

    cout<<"Output of Forbidden latency: ";

    for(i=1;i<=n;i++){

        if(store[i]==1){

            cout<<i<<" ";
            max_forbidden_lattency=i;

        }
    }
    cout<<endl;

    cout<<"Output of Permissible latency: ";

    for(i=1;i<=n;i++){

        if(store[i]==0)
            cout<<i<<" ";

    }

    cout<<endl;

    cout<<"Output of Collision Vector: ";

    for(i=max_forbidden_lattency;i>=1;i--){
        cout<<store[i] << " ";
    }

    cout<<endl;

    //collision point

    int latency;

    latency=2;

    for(int i=1;i<=m;i++)
    {

        for(int j=1;j<=n;j++)
        {

            if(reservation_table[i][j]==1)
            {

                if(reservation_table[i][j+latency]==1)
                {

                     cout << "Collision point : " << i << "," << j << endl;

                }




            }




        }



    }


/*1 0 0 0 0 1
0 1 0 1 0 0
0 0 1 0 0 0
0 0 0 1 1 0*/
}
