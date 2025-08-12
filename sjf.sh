#!/bin/bash

echo "Enter the process number"
read n
declare -a pid at bt ct tat wt rt vis srt

for((i=1;i<=n;i++))
do
   pid[i]=$i
   read at[i]
   read bt[i]
   vis[i]=0
done
   
   time=0
   cc=0;
   while((cc<n))
   do 
   mn=1000
   ind=-1
   for((i=1;i<=n;i++))
   do 
   if(( vis[i]==0 && at[i]<=time))
   then 
   if (( bt[i] < mn || (bt[i] == mn && at[i] < at[ind]) ))
   then
      mn=${bt[i]}
      ind=$i
     fi
   fi
   done
   if((ind==-1))
   then 
   ((time++))
   else
     srt[ind]=$time
     time=$((time+bt[ind]))
     ct[ind]=$time
     tat[ind]=$((ct[ind]-at[ind]))
     wt[ind]=$((tat[ind]-bt[ind]))
     rt[ind]=$((srt[ind]-at[ind]))
     vis[ind]=1
     ((cc++))
     fi
   done
 #print all
 echo -e "\nPID\tAT\tBT\tCT\tTAT\tWT\tRT"
for (( i=1; i<=n; i++ ))
do
    echo -e "P${pid[i]}\t${at[i]}\t${bt[i]}\t${ct[i]}\t${tat[i]}\t${wt[i]}\t${rt[i]}"
done
   