#!/bin/tcsh

set dir_name = $<

echo "Количество файлов в каталоге:"

ls $dir_name | wc -w
