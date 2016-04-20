#2016 Bartlomiej Najdecki
#Part of codeforces local runtime enviroment
#!/bin/bash
RED='\033[1;31m'
GREEN='\033[0;32m'
NC='\033[0m'
END=100
make $1
make dst
for f in $(seq 1 $END)
do
   if [ -e "./test/$1$f.in" ] ; then 
      printf "Checking ./test/$1$f file.."
      time ./$1 < ./test/$1$f.in > tmpX
      ./dst < tmpX > tmp
      ./dst < ./test/$1$f.out > tmp2
      DIFF=$(diff tmp2 tmp)
      if [ "$DIFF" ] ; then
         echo -e "${RED}[Wrong Answer]${NC}.\nShould be:"
         cat ./test/$1$f.out
         cat tmp2
         echo "Your program result:"
         cat tmpX
         cat tmp
      else
         echo -e "${GREEN}[ACCEPTED]${NC}"
      fi
   else
      echo "Couldn't find ./test/$1$f.in."
      break
   fi
done
