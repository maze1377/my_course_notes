#include<stdio.h>
#include<math.h>

int main(){
    int delivery[100][2];
    int restaurant[100][2];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&restaurant[i][0]);
        scanf("%d",&restaurant[i][1]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&delivery[i][0]);
        scanf("%d",&delivery[i][1]);
    }
    double distance[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int deltaX=delivery[i][0]-restaurant[j][0];
            int deltaY=delivery[i][1]-restaurant[j][1];
            if(deltaX<0) deltaX*=-1; // or you could use math.abs()
            if(deltaY<0) deltaY*=-1; // or you could use math.abs()
            distance[i][j] = sqrt(deltaX*deltaX+deltaY*deltaY);
        }
    }
    double ans=0;
    for(int i=0;i<n;i++){
        double currentMinDistance=-1; // not min distance yet => should replace with first distance
        int currentMinDelivery=-1;
        int currentMinRestaurant=-1;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(distance[j][k]==-1) continue; // we used this Delivery or Restaurant
                if(currentMinDistance==-1 || distance[j][k]<currentMinDistance){
                    currentMinDistance=distance[j][k];
                    currentMinDelivery=j;
                    currentMinRestaurant=k;
                }
            }
        }
        ans += currentMinDistance; // select currentMinDelivery and currentMinRestaurant
        for (int j=0;j<n;j++){
            distance[currentMinDelivery][j]=-1; // remove currentMinDelivery
            distance[j][currentMinRestaurant]=-1; // remove currentMinRestaurant
        }
    }
    printf("%lf\n",ans);
}
