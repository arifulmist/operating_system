#!/bin/bash
echo "enter the process number: "
read n
declare -a pid at bt rt ct tat wt srt exc
for((i=1;i<=n;i++))
do 
 pid[i]=$i
 read at[i]
 read bt[i]
 rt[i]=${bt[i]}
 exc[i]=0
done
 cc=0
 time=0
 while((cc<n))
  do
  mn=1000
  ind=-1
  for((i=1;i<=n;i++))
   do 
     if((at[i]<=time && rt[i]>0 && rt[i]<mn))
      then 
       mn=${rt[i]}
       ind=$i
     fi
   done
       if((ind==-1))
          then 
            ((time++))
           
         else
            if((exc[ind]==0))#recorde first one
              then
               srt[ind]=$time
               exc[ind]=1
            fi
              ((rt[ind]--))#qs time 1
              ((time++))
             if((rt[ind]==0))# kaj ses
               then
                 ct[ind]=$time
                 ((cc++))
             fi
                 
         fi
done

 #print all
 echo -e "\nPID\tAT\tBT\tCT\tTAT\tWT\tRT"
for (( i=1; i<=n; i++ ))
do
      tat[i]=$((ct[i]-at[i]))
     wt[i]=$((tat[i]-bt[i]))
     rt[i]=$((srt[i]-at[i]))
    echo -e "P${pid[i]}\t${at[i]}\t${bt[i]}\t${ct[i]}\t${tat[i]}\t${wt[i]}\t${rt[i]}"
done
                 