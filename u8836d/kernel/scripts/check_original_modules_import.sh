#!/bin/bash

source ./environment.sh

ORIGINAL_MODULES_PATH=../prepared/original_modules/used/
BUILT_MODULES_PATH=../prepared/built_modules/
BUILT_KERNEL=../huawei/kernel/vmlinux
IMPFILE=../prepared/_import.txt
EXPFILE=../prepared/_export.txt
UNRFILE=../prepared/_unresolved.txt

NEWLINE=`echo -ne '\n'`
SPACE=" "

# Arguments: 
# $1 - list of modules
# $2 - reference to return value
# Return value: list of import objects
getImport()
{
    local LOCAL_IMPORT=''
    for MODULE in $1
    do
        LOCAL_IMPORT=${LOCAL_IMPORT}${SPACE}`readelf -Ws ${MODULE} | grep GLOBAL | grep UND | awk '{print$8}'`
    done

    eval "$2=\"\$$2"${SPACE}"${LOCAL_IMPORT}\""
}

# Arguments: 
# $1 - list of modules
# $2 - reference to return value
# Return value: list of export objects
getExport()
{
    local LOCAL_EXPORT=''
    for MODULE in $1
    do
        LOCAL_EXPORT=${LOCAL_EXPORT}${SPACE}`readelf -Ws ${MODULE}  | grep GLOBAL | grep -v UND | awk '{print$8}'`
        LOCAL_EXPORT=${LOCAL_EXPORT}${SPACE}`readelf -Ws ${MODULE}  | grep WEAK | awk '{print$8}'`
#        LOCAL_EXPORT=${LOCAL_EXPORT}${SPACE}`readelf -Ws ${MODULE}  | grep -v UND | awk '{print$8}'`
    done

    eval "$2=\"\$$2"${SPACE}"${LOCAL_EXPORT}\""
}


# dump info from original modules
IMPORT=''
EXPORT=''
MODULES=`ls ${ORIGINAL_MODULES_PATH}*.ko`
getImport "$MODULES" IMPORT
getExport "$MODULES" EXPORT

# dump info from kernel

getImport "$BUILT_KERNEL" IMPORT
getExport "$BUILT_KERNEL" EXPORT

# dump info from built modules

MODULES=`ls ${BUILT_MODULES_PATH}*.ko`
getImport "$MODULES" IMPORT
getExport "$MODULES" EXPORT

echo $IMPORT | tr ' ' '\n' | sort -bu > $IMPFILE
echo $EXPORT | tr ' ' '\n' | sort -bu > $EXPFILE

# find difference between import and export

grep -v -F -x -f $EXPFILE $IMPFILE > $UNRFILE

UNRSIZE=`du -b $UNRFILE | awk '{print$1}'`

if [ $UNRSIZE -gt 0 ]; then
    UNR_FOUND=TRUE
else
    UNR_FOUND=FALSE
fi

echo 
echo Is Unresolved Externals Found?.....................$UNR_FOUND
echo 
echo If the only unresolved is arMsgMapTable then it is a bug in proprietary wlan.ko module.
echo Do not worry about arMsgMapTable.
echo 

