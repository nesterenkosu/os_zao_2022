#!/bin/tcsh

echo "Please enter filename"

set file_name = $<

while(`ls | grep $file_name | wc -l` < 1)
    sleep 1
end

echo "УРА! Файл $file_name наконец-то появился"

