#!/bin/tcsh

set dir_name = $<



set file_count = `ls $dir_name | wc -w`

echo "Количество файлов в каталоге: $file_count"
