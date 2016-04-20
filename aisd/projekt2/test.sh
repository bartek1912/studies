#!/bin/bash
RED='\033[1;31m'
GREEN='\033[0;32m'
NC='\033[0m'
END=100
make $1
for f in $(seq 1 $END)
do
   if [ -e "./test/$1$f.in" ] ; then 
      printf "Checking ./test/$1$f file.."
      ./$1 < ./test/$1$f.in > tmp
      DIFF=$(diff ./test/$1$f.out tmp)
      if [ "$DIFF" ] ; then
         echo -e "${RED}[Wrong Answer]${NC}.\nShould be:"
         cat ./test/$1$f.out
         echo "Your program result:"
         cat tmp
         break
      else
         echo -e "${GREEN}[ACCEPT]${NC}"
      fi
   else
      echo "Couldn't find ./test/$1$f.in."
      break
   fi
done
