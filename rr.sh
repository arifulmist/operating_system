#!/bin/bash

echo "Enter the number of processes:"
read n
declare -a pid at bt rt ct tat wt srt exc
for ((i=1; i<=n; i++)); do
    pid[i]=$i
    read at[i]
    read bt[i]
    rt[i]=${bt[i]}
    exc[i]=0
    srt[i]=0
done

read -p "Enter quantum time: " q

cc=0
time=0
qq=()  

while(( cc < n ))
do
    for((i=1; i<=n; i++))
    do
        found=0
        for j in "${qq[@]}"
        do
            if [[ "$j" -eq "${pid[i]}" ]]
            then
                found=1
                break
            fi
done
        if(( at[i] <= time && rt[i] > 0 && found == 0 ))
        then
            qq+=("${pid[i]}")
        fi
    done
    if(( ${#qq[@]} == 0 ))
    then
        ((time++))
        continue
    fi

    ind=${qq[0]}          
    qq=("${qq[@]:1}")
    if (( exc[ind] == 0 ))
    then
        srt[ind]=$time
        exc[ind]=1
    fi
    if (( rt[ind] <= q ))
    then
        time=$((time + rt[ind]))
        rt[ind]=0
        ct[ind]=$time
        ((cc++))
    else
        time=$((time + q))
        rt[ind]=$((rt[ind] - q))
    fi
    for ((i=1; i<=n; i++))
   do
        found=0
        for j in "${qq[@]}"
        do
            if [[ "$j" -eq "${pid[i]}" ]]
            then
                found=1
                break
            fi
            done
        if (( at[i] > srt[ind] && at[i] <= time && rt[i] > 0 && found == 0 ))
        then
            qq+=("${pid[i]}")
        fi
    done
    if (( rt[ind] > 0 ))
    then
        qq+=("$ind")
    fi
done


echo -e "\nPID\tAT\tBT\tCT\tTAT\tWT\tRT"
for ((i=1; i<=n; i++))
do
    tat[i]=$(( ct[i] - at[i] ))
    wt[i]=$(( tat[i] - bt[i] ))
    rt[i]=$(( srt[i] - at[i] ))
    echo -e "P${pid[i]}\t${at[i]}\t${bt[i]}\t${ct[i]}\t${tat[i]}\t${wt[i]}\t${rt[i]}"
done
