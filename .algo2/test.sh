#!/bin/bash
#
PREFIX=".algo2"

if [ -f "banner.txt" ] ; then
    cat $PREFIX/banner.txt
    echo ""
fi

echo "Compilación y pruebas"
echo "=====================\n"

gcc tp0.c -o tp0
./tp0

RETVAL=$?
if [ $RETVAL -ne 0 ]; then
    echo ""
    echo -e "\033[1;31m¡ERROR CORRIENDO TU ENTREGA! Revisa el código, no se obtuvo el resultado esperado.\033[0m"
    echo ""
    exit 1
fi

echo ""
echo "Parece que tu TP está ok."
echo ""

cat $PREFIX/success.txt
