#include<bits/stdc++.h>
#define BASE 256ULL
#define mod 100000ULL
using namespace std;

typedef struct submit
{
    char uId[10];
    char ProId[10];
    char TimePoint[10];
    char Status[10];
    int point;

}submit;

int uid_mana[1000000]={0};
int proId_mana[1000000]={0};
long long total_point[1000000]={0};
int time_mana[60][60][24]={0};
int total_error = 0;
int total_submit = 0;
int point_mana[100000][100] = {0};
int error_submit[1000000] = {0};
int second_convert[86400]={0};
int mark[100010] = {0};
map<string,long long>mp;
int hashFnc(char s[])
{
    unsigned long long n;
    unsigned long long Hash = 0, power = 1;
    int l = strlen(s);
    for(int j= l -1;j>=0;j--)
    {
        Hash = (Hash + ((unsigned long long)s[j]*power) % mod ) % mod;
        power = (power*BASE)%mod;
    }
    return int(Hash);
}

int main(){
    char uId[10],ProId[10],time[10],status[10];
    int point;
    int number = 1;
    while(1)
    {
        scanf("%s",uId);
        if(uId[0] == '#') break;
        if(mp[uId] == 0)
        mp[uId] = number++;
        long long id1 = mp[uId];
        uid_mana[id1]++;
        total_submit++;
        scanf("%s %s %s %i",ProId,time,status,&point);
        int proid = (int)(ProId[1]-48)*10+(int)(ProId[2]-48);
        int hour = (int)(time[0]-48)*10+(int)(time[1]-48);
        int minute = (int)(time[3]-48)*10+(int)(time[4]-48);
        int second = (int)(time[6]-48)*10+(int)(time[7]-48);
        time_mana[hour][minute][second]++;
        second_convert[hour*3600+minute*60+second]++;
        if(strcmp(status,"ERR") == 0)
        {
            total_error++;
            error_submit[id1]++;
        }
        if(point_mana[id1][proid] < point)
        {
            total_point[id1] += (- point_mana[id1][proid]+point);
            point_mana[id1][proid] = point;

        }

    }
    for(int i = 1 ; i<=86400;i++)
    {
        second_convert[i] += second_convert[i-1];
    }

    char c[20];
    while(1)
    {
        scanf("%s",c);
        if(strcmp(c,"#")==0) break;
        else if(strcmp(c,"?total_number_submissions") == 0)
        {
            printf("%i\n",total_submit);
        }
        else if(strcmp(c,"?number_error_submision") == 0)
        {
            printf("%i\n",total_error);

        }
        else if(strcmp(c,"?number_error_submission_of_user") == 0)
        {
            char a[10]; scanf("%s",a);
            int id_convert = mp[a];
            printf("%i\n",error_submit[id_convert]);

        }
        else if(strcmp(c,"?total_point_of_user") == 0)
        {
            char a[10]; scanf("%s",&a);
            int id_convert = mp[a];
            printf("%i\n",total_point[id_convert]);

        }
        else if(strcmp(c,"?number_submission_period") == 0)
        {
            char time1[10];
            char time2[10];
            scanf("%s %s",time1,time2);
            int hour1 = (int)(time1[0]-48)*10+(int)(time1[1]-48);
            int minute1 = (int)(time1[3]-48)*10+(int)(time1[4]-48);
            int second1 = (int)(time1[6]-48)*10+(int)(time1[7]-48);
            int hour2 = (int)(time2[0]-48)*10+(int)(time2[1]-48);
            int minute2 = (int)(time2[3]-48)*10+(int)(time2[4]-48);
            int second2 = (int)(time2[6]-48)*10+(int)(time2[7]-48);
            printf("%i\n",abs(second_convert[hour2*3600+minute2*60+second2] - second_convert[hour1*3600+minute1*60+second1]));
        }
    }
    return 0;
//U001 P01 10:30:20 ERR 0
//U001 P01 10:35:20 OK 10
//U001 P02 10:40:20 ERR 0
//U001 P02 10:55:20 OK 7
//U002 P01 10:40:20 ERR 0
//U001 P01 11:35:20 OK 8
//U002 P02 10:40:20 OK 10
//#
//?total_number_submissions
//?number_error_submision
//?number_error_submission_of_user U002
//?total_point_of_user U001
//?number_submission_period 10:00:00 11:30:45
//#
}