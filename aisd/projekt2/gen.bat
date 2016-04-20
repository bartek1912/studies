#!/bin/bash
if [ "$1" == "" ]
then
  echo "Nie wprowadzono ścieżki!"
  echo "parametry: <ścieżka> enviroment/graph"
  echo "Aby w pełni wykorzystać możliwości skryptu, uruchamiaj . gen.bat zamiast ./gen.bat"
elif [ "$2" == "enviroment" ]
then
   echo "Rozpoczynam przygotowywanie środowiska"
   if [[ ! -d "$1" ]]
   then
      echo "tworzenie katalogu $1/"
      mkdir "$1"
   fi 
   for f in "a.cpp" "b.cpp" "c.cpp" "d.cpp" "e.cpp"; do
      echo "Zapisywanie do $1/$f"
      cp template.cpp "$1/$f"
   done
   echo "Kopiowanie szablonow"
   cp -i graph_template.cpp "$1/graph_template.cpp"
   cp -i template.cpp "$1/template.cpp"
   echo "Kopiowanie Makefile... $1/Makefile"
   cp -i Makefile "$1/Makefile"
   echo "Kopiowanie test.sh... $1/test.sh"
   cp -i test.sh "$1/test.sh"
   echo "Tworzenie folderu testow $1/test/"
   mkdir "$1/test"
   echo "Samoreplikacja"
   cp -i gen.bat "$1/gen.bat"
   echo "Przenoszenie do folderu"
   cd "$1"
   echo "Zakończono"
elif [ "$2" == "graph" ]
then
   echo "Generowanie grafu do sciezki $1"
   cp -i graph_template.cpp "$1"
   echo "Zakończono"
else
   echo "nie wprowadzono akcji"
fi

